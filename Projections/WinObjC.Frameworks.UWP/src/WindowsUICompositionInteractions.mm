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

// WindowsUICompositionInteractions.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.Composition.Interactions.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUICompositionInteractions.h"
#include "WindowsUICompositionInteractions_priv.h"

@implementation WUCIICompositionInteractionSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::Interactions::ICompositionInteractionSource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WUCIIInteractionTrackerOwner

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerOwner> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)customAnimationStateEntered:(WUCIInteractionTracker*)sender args:(WUCIInteractionTrackerCustomAnimationStateEnteredArgs*)args {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerOwner>(self);
    THROW_NS_IF_FAILED(_comInst->CustomAnimationStateEntered(
        _getRtInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(sender).Get(),
        _getRtInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerCustomAnimationStateEnteredArgs>(args).Get()));
}

- (void)idleStateEntered:(WUCIInteractionTracker*)sender args:(WUCIInteractionTrackerIdleStateEnteredArgs*)args {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerOwner>(self);
    THROW_NS_IF_FAILED(_comInst->IdleStateEntered(
        _getRtInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(sender).Get(),
        _getRtInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerIdleStateEnteredArgs>(args).Get()));
}

- (void)inertiaStateEntered:(WUCIInteractionTracker*)sender args:(WUCIInteractionTrackerInertiaStateEnteredArgs*)args {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerOwner>(self);
    THROW_NS_IF_FAILED(_comInst->InertiaStateEntered(
        _getRtInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(sender).Get(),
        _getRtInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaStateEnteredArgs>(args).Get()));
}

- (void)interactingStateEntered:(WUCIInteractionTracker*)sender args:(WUCIInteractionTrackerInteractingStateEnteredArgs*)args {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerOwner>(self);
    THROW_NS_IF_FAILED(_comInst->InteractingStateEntered(
        _getRtInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(sender).Get(),
        _getRtInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInteractingStateEnteredArgs>(args).Get()));
}

- (void)requestIgnored:(WUCIInteractionTracker*)sender args:(WUCIInteractionTrackerRequestIgnoredArgs*)args {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerOwner>(self);
    THROW_NS_IF_FAILED(_comInst->RequestIgnored(
        _getRtInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(sender).Get(),
        _getRtInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerRequestIgnoredArgs>(args).Get()));
}

- (void)valuesChanged:(WUCIInteractionTracker*)sender args:(WUCIInteractionTrackerValuesChangedArgs*)args {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerOwner>(self);
    THROW_NS_IF_FAILED(_comInst->ValuesChanged(
        _getRtInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(sender).Get(),
        _getRtInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerValuesChangedArgs>(args).Get()));
}

@end

@implementation WUCIInteractionTrackerCustomAnimationStateEnteredArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerCustomAnimationStateEnteredArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (int)requestId {
    int unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerCustomAnimationStateEnteredArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequestId(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WUCIInteractionTrackerIdleStateEnteredArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerIdleStateEnteredArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (int)requestId {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerIdleStateEnteredArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequestId(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WUCIInteractionTrackerInertiaStateEnteredArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaStateEnteredArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (id /* WFNVector3* */)modifiedRestingPosition {
    ComPtr<IReference<ABI::Windows::Foundation::Numerics::Vector3>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaStateEnteredArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ModifiedRestingPosition(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFNVector3, ABI::Windows::Foundation::Numerics::Vector3>::convert(unmarshalledReturn.Get());
}

- (id /* float */)modifiedRestingScale {
    ComPtr<IReference<float>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaStateEnteredArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ModifiedRestingScale(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<float, float>::convert(unmarshalledReturn.Get());
}

- (WFNVector3*)naturalRestingPosition {
    ABI::Windows::Foundation::Numerics::Vector3 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaStateEnteredArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_NaturalRestingPosition(&unmarshalledReturn));
    return WFNVector3_create(unmarshalledReturn);
}

- (float)naturalRestingScale {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaStateEnteredArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_NaturalRestingScale(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFNVector3*)positionVelocityInPixelsPerSecond {
    ABI::Windows::Foundation::Numerics::Vector3 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaStateEnteredArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PositionVelocityInPixelsPerSecond(&unmarshalledReturn));
    return WFNVector3_create(unmarshalledReturn);
}

- (int)requestId {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaStateEnteredArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequestId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)scaleVelocityInPercentPerSecond {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaStateEnteredArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ScaleVelocityInPercentPerSecond(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WUCIInteractionTrackerInteractingStateEnteredArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInteractingStateEnteredArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (int)requestId {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInteractingStateEnteredArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequestId(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WUCIInteractionTrackerRequestIgnoredArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerRequestIgnoredArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (int)requestId {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerRequestIgnoredArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequestId(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WUCIInteractionTrackerValuesChangedArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerValuesChangedArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFNVector3*)position {
    ABI::Windows::Foundation::Numerics::Vector3 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerValuesChangedArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WFNVector3_create(unmarshalledReturn);
}

- (int)requestId {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerValuesChangedArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequestId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)scale {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerValuesChangedArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Scale(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WUCIInteractionTracker

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::Interactions::IInteractionTracker> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerStatics> WUCIIInteractionTrackerStatics_inst() {
    ComPtr<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Composition.Interactions.InteractionTracker").Get(), &inst));
    return inst;
}

+ (WUCIInteractionTracker*)create:(WUCCompositor*)compositor {
    ComPtr<ABI::Windows::UI::Composition::Interactions::IInteractionTracker> unmarshalledReturn;
    auto _comInst = WUCIIInteractionTrackerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create(_getRtInterface<ABI::Windows::UI::Composition::ICompositor>(compositor).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCIInteractionTracker>(unmarshalledReturn.Get());
}

+ (WUCIInteractionTracker*)createWithOwner:(WUCCompositor*)compositor owner:(RTObject<WUCIIInteractionTrackerOwner>*)owner {
    ComPtr<ABI::Windows::UI::Composition::Interactions::IInteractionTracker> unmarshalledReturn;
    auto _comInst = WUCIIInteractionTrackerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateWithOwner(_getRtInterface<ABI::Windows::UI::Composition::ICompositor>(compositor).Get(),
                                  _getRtInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerOwner>(owner).Get(),
                                  unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCIInteractionTracker>(unmarshalledReturn.Get());
}

- (WUCICompositionInteractionSourceCollection*)interactionSources {
    ComPtr<ABI::Windows::UI::Composition::Interactions::ICompositionInteractionSourceCollection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(self);
    THROW_NS_IF_FAILED(_comInst->get_InteractionSources(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCICompositionInteractionSourceCollection>(unmarshalledReturn.Get());
}

- (BOOL)isPositionRoundingSuggested {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPositionRoundingSuggested(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WFNVector3*)maxPosition {
    ABI::Windows::Foundation::Numerics::Vector3 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxPosition(&unmarshalledReturn));
    return WFNVector3_create(unmarshalledReturn);
}

- (void)setMaxPosition:(WFNVector3*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxPosition(*[value internalStruct]));
}

- (float)maxScale {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxScale(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setMaxScale:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxScale(value));
}

- (WFNVector3*)minPosition {
    ABI::Windows::Foundation::Numerics::Vector3 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinPosition(&unmarshalledReturn));
    return WFNVector3_create(unmarshalledReturn);
}

- (void)setMinPosition:(WFNVector3*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(self);
    THROW_NS_IF_FAILED(_comInst->put_MinPosition(*[value internalStruct]));
}

- (float)minScale {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinScale(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setMinScale:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(self);
    THROW_NS_IF_FAILED(_comInst->put_MinScale(value));
}

- (WFNVector3*)naturalRestingPosition {
    ABI::Windows::Foundation::Numerics::Vector3 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(self);
    THROW_NS_IF_FAILED(_comInst->get_NaturalRestingPosition(&unmarshalledReturn));
    return WFNVector3_create(unmarshalledReturn);
}

- (float)naturalRestingScale {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(self);
    THROW_NS_IF_FAILED(_comInst->get_NaturalRestingScale(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (RTObject<WUCIIInteractionTrackerOwner>*)owner {
    ComPtr<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerOwner> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(self);
    THROW_NS_IF_FAILED(_comInst->get_Owner(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCIIInteractionTrackerOwner>(unmarshalledReturn.Get());
}

- (WFNVector3*)position {
    ABI::Windows::Foundation::Numerics::Vector3 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WFNVector3_create(unmarshalledReturn);
}

- (id /* WFNVector3* */)positionInertiaDecayRate {
    ComPtr<IReference<ABI::Windows::Foundation::Numerics::Vector3>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(self);
    THROW_NS_IF_FAILED(_comInst->get_PositionInertiaDecayRate(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFNVector3, ABI::Windows::Foundation::Numerics::Vector3>::convert(unmarshalledReturn.Get());
}

- (void)setPositionInertiaDecayRate:(id /* WFNVector3* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(self);
    THROW_NS_IF_FAILED(_comInst->put_PositionInertiaDecayRate(BuildNullable<ABI::Windows::Foundation::Numerics::Vector3>(value)));
}

- (WFNVector3*)positionVelocityInPixelsPerSecond {
    ABI::Windows::Foundation::Numerics::Vector3 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(self);
    THROW_NS_IF_FAILED(_comInst->get_PositionVelocityInPixelsPerSecond(&unmarshalledReturn));
    return WFNVector3_create(unmarshalledReturn);
}

- (float)scale {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(self);
    THROW_NS_IF_FAILED(_comInst->get_Scale(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (id /* float */)scaleInertiaDecayRate {
    ComPtr<IReference<float>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(self);
    THROW_NS_IF_FAILED(_comInst->get_ScaleInertiaDecayRate(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<float, float>::convert(unmarshalledReturn.Get());
}

- (void)setScaleInertiaDecayRate:(id /* float */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(self);
    THROW_NS_IF_FAILED(_comInst->put_ScaleInertiaDecayRate(BuildNullable<float>(value)));
}

- (float)scaleVelocityInPercentPerSecond {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(self);
    THROW_NS_IF_FAILED(_comInst->get_ScaleVelocityInPercentPerSecond(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)adjustPositionXIfGreaterThanThreshold:(float)adjustment positionThreshold:(float)positionThreshold {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(self);
    THROW_NS_IF_FAILED(_comInst->AdjustPositionXIfGreaterThanThreshold(adjustment, positionThreshold));
}

- (void)adjustPositionYIfGreaterThanThreshold:(float)adjustment positionThreshold:(float)positionThreshold {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(self);
    THROW_NS_IF_FAILED(_comInst->AdjustPositionYIfGreaterThanThreshold(adjustment, positionThreshold));
}

- (void)configurePositionXInertiaModifiers:(id<NSFastEnumeration> /* WUCIInteractionTrackerInertiaModifier* */)modifiers {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(self);
    THROW_NS_IF_FAILED(_comInst->ConfigurePositionXInertiaModifiers(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Foundation::Internal::AggregateType<
            ABI::Windows::UI::Composition::Interactions::InteractionTrackerInertiaModifier*,
            ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaModifier*>>::type>*>(
            ConvertToIterable<WUCIInteractionTrackerInertiaModifier,
                              ABI::Windows::Foundation::Internal::AggregateType<
                                  ABI::Windows::UI::Composition::Interactions::InteractionTrackerInertiaModifier*,
                                  ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaModifier*>>(modifiers)
                .Get())));
}

- (void)configurePositionYInertiaModifiers:(id<NSFastEnumeration> /* WUCIInteractionTrackerInertiaModifier* */)modifiers {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(self);
    THROW_NS_IF_FAILED(_comInst->ConfigurePositionYInertiaModifiers(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Foundation::Internal::AggregateType<
            ABI::Windows::UI::Composition::Interactions::InteractionTrackerInertiaModifier*,
            ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaModifier*>>::type>*>(
            ConvertToIterable<WUCIInteractionTrackerInertiaModifier,
                              ABI::Windows::Foundation::Internal::AggregateType<
                                  ABI::Windows::UI::Composition::Interactions::InteractionTrackerInertiaModifier*,
                                  ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaModifier*>>(modifiers)
                .Get())));
}

- (void)configureScaleInertiaModifiers:(id<NSFastEnumeration> /* WUCIInteractionTrackerInertiaModifier* */)modifiers {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(self);
    THROW_NS_IF_FAILED(_comInst->ConfigureScaleInertiaModifiers(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Foundation::Internal::AggregateType<
            ABI::Windows::UI::Composition::Interactions::InteractionTrackerInertiaModifier*,
            ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaModifier*>>::type>*>(
            ConvertToIterable<WUCIInteractionTrackerInertiaModifier,
                              ABI::Windows::Foundation::Internal::AggregateType<
                                  ABI::Windows::UI::Composition::Interactions::InteractionTrackerInertiaModifier*,
                                  ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaModifier*>>(modifiers)
                .Get())));
}

- (int)tryUpdatePosition:(WFNVector3*)value {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(self);
    THROW_NS_IF_FAILED(_comInst->TryUpdatePosition(*[value internalStruct], &unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)tryUpdatePositionBy:(WFNVector3*)amount {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(self);
    THROW_NS_IF_FAILED(_comInst->TryUpdatePositionBy(*[amount internalStruct], &unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)tryUpdatePositionWithAnimation:(WUCCompositionAnimation*)animation {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(self);
    THROW_NS_IF_FAILED(
        _comInst->TryUpdatePositionWithAnimation(_getRtInterface<ABI::Windows::UI::Composition::ICompositionAnimation>(animation).Get(),
                                                 &unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)tryUpdatePositionWithAdditionalVelocity:(WFNVector3*)velocityInPixelsPerSecond {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(self);
    THROW_NS_IF_FAILED(_comInst->TryUpdatePositionWithAdditionalVelocity(*[velocityInPixelsPerSecond internalStruct], &unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)tryUpdateScale:(float)value centerPoint:(WFNVector3*)centerPoint {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(self);
    THROW_NS_IF_FAILED(_comInst->TryUpdateScale(value, *[centerPoint internalStruct], &unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)tryUpdateScaleWithAnimation:(WUCCompositionAnimation*)animation centerPoint:(WFNVector3*)centerPoint {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(self);
    THROW_NS_IF_FAILED(
        _comInst->TryUpdateScaleWithAnimation(_getRtInterface<ABI::Windows::UI::Composition::ICompositionAnimation>(animation).Get(),
                                              *[centerPoint internalStruct],
                                              &unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)tryUpdateScaleWithAdditionalVelocity:(float)velocityInPercentPerSecond centerPoint:(WFNVector3*)centerPoint {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTracker>(self);
    THROW_NS_IF_FAILED(
        _comInst->TryUpdateScaleWithAdditionalVelocity(velocityInPercentPerSecond, *[centerPoint internalStruct], &unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WUCICompositionInteractionSourceCollection

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::Interactions::ICompositionInteractionSourceCollection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (int)count {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::ICompositionInteractionSourceCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_Count(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)add:(RTObject<WUCIICompositionInteractionSource>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::ICompositionInteractionSourceCollection>(self);
    THROW_NS_IF_FAILED(
        _comInst->Add(_getRtInterface<ABI::Windows::UI::Composition::Interactions::ICompositionInteractionSource>(value).Get()));
}

- (void)remove:(RTObject<WUCIICompositionInteractionSource>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::ICompositionInteractionSourceCollection>(self);
    THROW_NS_IF_FAILED(
        _comInst->Remove(_getRtInterface<ABI::Windows::UI::Composition::Interactions::ICompositionInteractionSource>(value).Get()));
}

- (void)removeAll {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::ICompositionInteractionSourceCollection>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveAll());
}

@end

@implementation WUCIInteractionTrackerInertiaModifier

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaModifier> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WUCIInteractionTrackerInertiaRestingValue

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaRestingValue> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaRestingValueStatics>
WUCIIInteractionTrackerInertiaRestingValueStatics_inst() {
    ComPtr<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaRestingValueStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Composition.Interactions.InteractionTrackerInertiaRestingValue").Get(), &inst));
    return inst;
}

+ (WUCIInteractionTrackerInertiaRestingValue*)create:(WUCCompositor*)compositor {
    ComPtr<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaRestingValue> unmarshalledReturn;
    auto _comInst = WUCIIInteractionTrackerInertiaRestingValueStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create(_getRtInterface<ABI::Windows::UI::Composition::ICompositor>(compositor).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCIInteractionTrackerInertiaRestingValue>(unmarshalledReturn.Get());
}

- (WUCExpressionAnimation*)condition {
    ComPtr<ABI::Windows::UI::Composition::IExpressionAnimation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaRestingValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Condition(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCExpressionAnimation>(unmarshalledReturn.Get());
}

- (void)setCondition:(WUCExpressionAnimation*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaRestingValue>(self);
    THROW_NS_IF_FAILED(_comInst->put_Condition(_getRtInterface<ABI::Windows::UI::Composition::IExpressionAnimation>(value).Get()));
}

- (WUCExpressionAnimation*)restingValue {
    ComPtr<ABI::Windows::UI::Composition::IExpressionAnimation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaRestingValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_RestingValue(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCExpressionAnimation>(unmarshalledReturn.Get());
}

- (void)setRestingValue:(WUCExpressionAnimation*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaRestingValue>(self);
    THROW_NS_IF_FAILED(_comInst->put_RestingValue(_getRtInterface<ABI::Windows::UI::Composition::IExpressionAnimation>(value).Get()));
}

@end

@implementation WUCIInteractionTrackerInertiaMotion

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaMotion> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaMotionStatics>
WUCIIInteractionTrackerInertiaMotionStatics_inst() {
    ComPtr<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaMotionStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Composition.Interactions.InteractionTrackerInertiaMotion").Get(), &inst));
    return inst;
}

+ (WUCIInteractionTrackerInertiaMotion*)create:(WUCCompositor*)compositor {
    ComPtr<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaMotion> unmarshalledReturn;
    auto _comInst = WUCIIInteractionTrackerInertiaMotionStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create(_getRtInterface<ABI::Windows::UI::Composition::ICompositor>(compositor).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCIInteractionTrackerInertiaMotion>(unmarshalledReturn.Get());
}

- (WUCExpressionAnimation*)condition {
    ComPtr<ABI::Windows::UI::Composition::IExpressionAnimation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaMotion>(self);
    THROW_NS_IF_FAILED(_comInst->get_Condition(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCExpressionAnimation>(unmarshalledReturn.Get());
}

- (void)setCondition:(WUCExpressionAnimation*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaMotion>(self);
    THROW_NS_IF_FAILED(_comInst->put_Condition(_getRtInterface<ABI::Windows::UI::Composition::IExpressionAnimation>(value).Get()));
}

- (WUCExpressionAnimation*)motion {
    ComPtr<ABI::Windows::UI::Composition::IExpressionAnimation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaMotion>(self);
    THROW_NS_IF_FAILED(_comInst->get_Motion(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCExpressionAnimation>(unmarshalledReturn.Get());
}

- (void)setMotion:(WUCExpressionAnimation*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaMotion>(self);
    THROW_NS_IF_FAILED(_comInst->put_Motion(_getRtInterface<ABI::Windows::UI::Composition::IExpressionAnimation>(value).Get()));
}

@end

@implementation WUCIVisualInteractionSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::Interactions::IVisualInteractionSource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Composition::Interactions::IVisualInteractionSourceStatics> WUCIIVisualInteractionSourceStatics_inst() {
    ComPtr<ABI::Windows::UI::Composition::Interactions::IVisualInteractionSourceStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Composition.Interactions.VisualInteractionSource").Get(), &inst));
    return inst;
}

+ (WUCIVisualInteractionSource*)create:(WUCVisual*)source {
    ComPtr<ABI::Windows::UI::Composition::Interactions::IVisualInteractionSource> unmarshalledReturn;
    auto _comInst = WUCIIVisualInteractionSourceStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create(_getRtInterface<ABI::Windows::UI::Composition::IVisual>(source).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCIVisualInteractionSource>(unmarshalledReturn.Get());
}

- (BOOL)isPositionXRailsEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IVisualInteractionSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPositionXRailsEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsPositionXRailsEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IVisualInteractionSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsPositionXRailsEnabled((boolean)value));
}

- (BOOL)isPositionYRailsEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IVisualInteractionSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPositionYRailsEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsPositionYRailsEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IVisualInteractionSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsPositionYRailsEnabled((boolean)value));
}

- (WUCIVisualInteractionSourceRedirectionMode)manipulationRedirectionMode {
    ABI::Windows::UI::Composition::Interactions::VisualInteractionSourceRedirectionMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IVisualInteractionSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_ManipulationRedirectionMode(&unmarshalledReturn));
    return (WUCIVisualInteractionSourceRedirectionMode)unmarshalledReturn;
}

- (void)setManipulationRedirectionMode:(WUCIVisualInteractionSourceRedirectionMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IVisualInteractionSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_ManipulationRedirectionMode(
        (ABI::Windows::UI::Composition::Interactions::VisualInteractionSourceRedirectionMode)value));
}

- (WUCIInteractionChainingMode)positionXChainingMode {
    ABI::Windows::UI::Composition::Interactions::InteractionChainingMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IVisualInteractionSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_PositionXChainingMode(&unmarshalledReturn));
    return (WUCIInteractionChainingMode)unmarshalledReturn;
}

- (void)setPositionXChainingMode:(WUCIInteractionChainingMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IVisualInteractionSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_PositionXChainingMode((ABI::Windows::UI::Composition::Interactions::InteractionChainingMode)value));
}

- (WUCIInteractionSourceMode)positionXSourceMode {
    ABI::Windows::UI::Composition::Interactions::InteractionSourceMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IVisualInteractionSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_PositionXSourceMode(&unmarshalledReturn));
    return (WUCIInteractionSourceMode)unmarshalledReturn;
}

- (void)setPositionXSourceMode:(WUCIInteractionSourceMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IVisualInteractionSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_PositionXSourceMode((ABI::Windows::UI::Composition::Interactions::InteractionSourceMode)value));
}

- (WUCIInteractionChainingMode)positionYChainingMode {
    ABI::Windows::UI::Composition::Interactions::InteractionChainingMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IVisualInteractionSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_PositionYChainingMode(&unmarshalledReturn));
    return (WUCIInteractionChainingMode)unmarshalledReturn;
}

- (void)setPositionYChainingMode:(WUCIInteractionChainingMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IVisualInteractionSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_PositionYChainingMode((ABI::Windows::UI::Composition::Interactions::InteractionChainingMode)value));
}

- (WUCIInteractionSourceMode)positionYSourceMode {
    ABI::Windows::UI::Composition::Interactions::InteractionSourceMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IVisualInteractionSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_PositionYSourceMode(&unmarshalledReturn));
    return (WUCIInteractionSourceMode)unmarshalledReturn;
}

- (void)setPositionYSourceMode:(WUCIInteractionSourceMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IVisualInteractionSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_PositionYSourceMode((ABI::Windows::UI::Composition::Interactions::InteractionSourceMode)value));
}

- (WUCIInteractionChainingMode)scaleChainingMode {
    ABI::Windows::UI::Composition::Interactions::InteractionChainingMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IVisualInteractionSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_ScaleChainingMode(&unmarshalledReturn));
    return (WUCIInteractionChainingMode)unmarshalledReturn;
}

- (void)setScaleChainingMode:(WUCIInteractionChainingMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IVisualInteractionSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_ScaleChainingMode((ABI::Windows::UI::Composition::Interactions::InteractionChainingMode)value));
}

- (WUCIInteractionSourceMode)scaleSourceMode {
    ABI::Windows::UI::Composition::Interactions::InteractionSourceMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IVisualInteractionSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_ScaleSourceMode(&unmarshalledReturn));
    return (WUCIInteractionSourceMode)unmarshalledReturn;
}

- (void)setScaleSourceMode:(WUCIInteractionSourceMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IVisualInteractionSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_ScaleSourceMode((ABI::Windows::UI::Composition::Interactions::InteractionSourceMode)value));
}

- (WUCVisual*)source {
    ComPtr<ABI::Windows::UI::Composition::IVisual> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IVisualInteractionSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_Source(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCVisual>(unmarshalledReturn.Get());
}

- (void)tryRedirectForManipulation:(WUIPointerPoint*)pointerPoint {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Interactions::IVisualInteractionSource>(self);
    THROW_NS_IF_FAILED(_comInst->TryRedirectForManipulation(_getRtInterface<ABI::Windows::UI::Input::IPointerPoint>(pointerPoint).Get()));
}

@end

id RTProxiedIterableNSArray_WUCIInteractionTrackerInertiaModifier_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<
        IterableArrayAdapterObj<IIterable<ABI::Windows::UI::Composition::Interactions::InteractionTrackerInertiaModifier*>,
                                RTIterableObj<ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaModifier*,
                                              IIterable<ABI::Windows::UI::Composition::Interactions::InteractionTrackerInertiaModifier*>,
                                              WUCIInteractionTrackerInertiaModifier,
                                              ABI::Windows::UI::Composition::Interactions::InteractionTrackerInertiaModifier*,
                                              dummyObjCCreator,
                                              dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
