// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.UI.Composition.Interactions.0.h"
#include "Windows.UI.Composition.0.h"
#include "Windows.UI.Input.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Composition::Interactions {

struct __declspec(uuid("043b2431-06e3-495a-ba54-409f0017fac0")) __declspec(novtable) ICompositionInteractionSource : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("1b468e4b-a5bf-47d8-a547-3894155a158c")) __declspec(novtable) ICompositionInteractionSourceCollection : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Count(int32_t * value) = 0;
    virtual HRESULT __stdcall abi_Add(Windows::UI::Composition::Interactions::ICompositionInteractionSource * value) = 0;
    virtual HRESULT __stdcall abi_Remove(Windows::UI::Composition::Interactions::ICompositionInteractionSource * value) = 0;
    virtual HRESULT __stdcall abi_RemoveAll() = 0;
};

struct __declspec(uuid("2a8e8cb1-1000-4416-8363-cc27fb877308")) __declspec(novtable) IInteractionTracker : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_InteractionSources(Windows::UI::Composition::Interactions::ICompositionInteractionSourceCollection ** value) = 0;
    virtual HRESULT __stdcall get_IsPositionRoundingSuggested(bool * value) = 0;
    virtual HRESULT __stdcall get_MaxPosition(Windows::Foundation::Numerics::float3 * value) = 0;
    virtual HRESULT __stdcall put_MaxPosition(Windows::Foundation::Numerics::float3 value) = 0;
    virtual HRESULT __stdcall get_MaxScale(float * value) = 0;
    virtual HRESULT __stdcall put_MaxScale(float value) = 0;
    virtual HRESULT __stdcall get_MinPosition(Windows::Foundation::Numerics::float3 * value) = 0;
    virtual HRESULT __stdcall put_MinPosition(Windows::Foundation::Numerics::float3 value) = 0;
    virtual HRESULT __stdcall get_MinScale(float * value) = 0;
    virtual HRESULT __stdcall put_MinScale(float value) = 0;
    virtual HRESULT __stdcall get_NaturalRestingPosition(Windows::Foundation::Numerics::float3 * value) = 0;
    virtual HRESULT __stdcall get_NaturalRestingScale(float * value) = 0;
    virtual HRESULT __stdcall get_Owner(Windows::UI::Composition::Interactions::IInteractionTrackerOwner ** value) = 0;
    virtual HRESULT __stdcall get_Position(Windows::Foundation::Numerics::float3 * value) = 0;
    virtual HRESULT __stdcall get_PositionInertiaDecayRate(Windows::Foundation::IReference<Windows::Foundation::Numerics::float3> ** value) = 0;
    virtual HRESULT __stdcall put_PositionInertiaDecayRate(Windows::Foundation::IReference<Windows::Foundation::Numerics::float3> * value) = 0;
    virtual HRESULT __stdcall get_PositionVelocityInPixelsPerSecond(Windows::Foundation::Numerics::float3 * value) = 0;
    virtual HRESULT __stdcall get_Scale(float * value) = 0;
    virtual HRESULT __stdcall get_ScaleInertiaDecayRate(Windows::Foundation::IReference<float> ** value) = 0;
    virtual HRESULT __stdcall put_ScaleInertiaDecayRate(Windows::Foundation::IReference<float> * value) = 0;
    virtual HRESULT __stdcall get_ScaleVelocityInPercentPerSecond(float * value) = 0;
    virtual HRESULT __stdcall abi_AdjustPositionXIfGreaterThanThreshold(float adjustment, float positionThreshold) = 0;
    virtual HRESULT __stdcall abi_AdjustPositionYIfGreaterThanThreshold(float adjustment, float positionThreshold) = 0;
    virtual HRESULT __stdcall abi_ConfigurePositionXInertiaModifiers(Windows::Foundation::Collections::IIterable<Windows::UI::Composition::Interactions::InteractionTrackerInertiaModifier> * modifiers) = 0;
    virtual HRESULT __stdcall abi_ConfigurePositionYInertiaModifiers(Windows::Foundation::Collections::IIterable<Windows::UI::Composition::Interactions::InteractionTrackerInertiaModifier> * modifiers) = 0;
    virtual HRESULT __stdcall abi_ConfigureScaleInertiaModifiers(Windows::Foundation::Collections::IIterable<Windows::UI::Composition::Interactions::InteractionTrackerInertiaModifier> * modifiers) = 0;
    virtual HRESULT __stdcall abi_TryUpdatePosition(Windows::Foundation::Numerics::float3 value, int32_t * requestId) = 0;
    virtual HRESULT __stdcall abi_TryUpdatePositionBy(Windows::Foundation::Numerics::float3 amount, int32_t * requestId) = 0;
    virtual HRESULT __stdcall abi_TryUpdatePositionWithAnimation(Windows::UI::Composition::ICompositionAnimation * animation, int32_t * requestId) = 0;
    virtual HRESULT __stdcall abi_TryUpdatePositionWithAdditionalVelocity(Windows::Foundation::Numerics::float3 velocityInPixelsPerSecond, int32_t * requestId) = 0;
    virtual HRESULT __stdcall abi_TryUpdateScale(float value, Windows::Foundation::Numerics::float3 centerPoint, int32_t * requestId) = 0;
    virtual HRESULT __stdcall abi_TryUpdateScaleWithAnimation(Windows::UI::Composition::ICompositionAnimation * animation, Windows::Foundation::Numerics::float3 centerPoint, int32_t * requestId) = 0;
    virtual HRESULT __stdcall abi_TryUpdateScaleWithAdditionalVelocity(float velocityInPercentPerSecond, Windows::Foundation::Numerics::float3 centerPoint, int32_t * requestId) = 0;
};

struct __declspec(uuid("8d1c8cf1-d7b0-434c-a5d2-2d7611864834")) __declspec(novtable) IInteractionTrackerCustomAnimationStateEnteredArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RequestId(int32_t * value) = 0;
};

struct __declspec(uuid("50012faa-1510-4142-a1a5-019b09f8857b")) __declspec(novtable) IInteractionTrackerIdleStateEnteredArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RequestId(int32_t * value) = 0;
};

struct __declspec(uuid("a0e2c920-26b4-4da2-8b61-5e683979bbe2")) __declspec(novtable) IInteractionTrackerInertiaModifier : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("993818fe-c94e-4b86-87f3-922665ba46b9")) __declspec(novtable) IInteractionTrackerInertiaModifierFactory : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("04922fdc-f154-4cb8-bf33-cc1ba611e6db")) __declspec(novtable) IInteractionTrackerInertiaMotion : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Condition(Windows::UI::Composition::IExpressionAnimation ** value) = 0;
    virtual HRESULT __stdcall put_Condition(Windows::UI::Composition::IExpressionAnimation * value) = 0;
    virtual HRESULT __stdcall get_Motion(Windows::UI::Composition::IExpressionAnimation ** value) = 0;
    virtual HRESULT __stdcall put_Motion(Windows::UI::Composition::IExpressionAnimation * value) = 0;
};

struct __declspec(uuid("8cc83dd6-ba7b-431a-844b-6eac9130f99a")) __declspec(novtable) IInteractionTrackerInertiaMotionStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::UI::Composition::ICompositor * compositor, Windows::UI::Composition::Interactions::IInteractionTrackerInertiaMotion ** result) = 0;
};

struct __declspec(uuid("86f7ec09-5096-4170-9cc8-df2fe101bb93")) __declspec(novtable) IInteractionTrackerInertiaRestingValue : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Condition(Windows::UI::Composition::IExpressionAnimation ** value) = 0;
    virtual HRESULT __stdcall put_Condition(Windows::UI::Composition::IExpressionAnimation * value) = 0;
    virtual HRESULT __stdcall get_RestingValue(Windows::UI::Composition::IExpressionAnimation ** value) = 0;
    virtual HRESULT __stdcall put_RestingValue(Windows::UI::Composition::IExpressionAnimation * value) = 0;
};

struct __declspec(uuid("18ed4699-0745-4096-bcab-3a4e99569bcf")) __declspec(novtable) IInteractionTrackerInertiaRestingValueStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::UI::Composition::ICompositor * compositor, Windows::UI::Composition::Interactions::IInteractionTrackerInertiaRestingValue ** result) = 0;
};

struct __declspec(uuid("87108cf2-e7ff-4f7d-9ffd-d72f1e409b63")) __declspec(novtable) IInteractionTrackerInertiaStateEnteredArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ModifiedRestingPosition(Windows::Foundation::IReference<Windows::Foundation::Numerics::float3> ** value) = 0;
    virtual HRESULT __stdcall get_ModifiedRestingScale(Windows::Foundation::IReference<float> ** value) = 0;
    virtual HRESULT __stdcall get_NaturalRestingPosition(Windows::Foundation::Numerics::float3 * value) = 0;
    virtual HRESULT __stdcall get_NaturalRestingScale(float * value) = 0;
    virtual HRESULT __stdcall get_PositionVelocityInPixelsPerSecond(Windows::Foundation::Numerics::float3 * value) = 0;
    virtual HRESULT __stdcall get_RequestId(int32_t * value) = 0;
    virtual HRESULT __stdcall get_ScaleVelocityInPercentPerSecond(float * value) = 0;
};

struct __declspec(uuid("a7263939-a17b-4011-99fd-b5c24f143748")) __declspec(novtable) IInteractionTrackerInteractingStateEnteredArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RequestId(int32_t * value) = 0;
};

struct __declspec(uuid("db2e8af3-4deb-4e53-b29c-b06c9f96d651")) __declspec(novtable) IInteractionTrackerOwner : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CustomAnimationStateEntered(Windows::UI::Composition::Interactions::IInteractionTracker * sender, Windows::UI::Composition::Interactions::IInteractionTrackerCustomAnimationStateEnteredArgs * args) = 0;
    virtual HRESULT __stdcall abi_IdleStateEntered(Windows::UI::Composition::Interactions::IInteractionTracker * sender, Windows::UI::Composition::Interactions::IInteractionTrackerIdleStateEnteredArgs * args) = 0;
    virtual HRESULT __stdcall abi_InertiaStateEntered(Windows::UI::Composition::Interactions::IInteractionTracker * sender, Windows::UI::Composition::Interactions::IInteractionTrackerInertiaStateEnteredArgs * args) = 0;
    virtual HRESULT __stdcall abi_InteractingStateEntered(Windows::UI::Composition::Interactions::IInteractionTracker * sender, Windows::UI::Composition::Interactions::IInteractionTrackerInteractingStateEnteredArgs * args) = 0;
    virtual HRESULT __stdcall abi_RequestIgnored(Windows::UI::Composition::Interactions::IInteractionTracker * sender, Windows::UI::Composition::Interactions::IInteractionTrackerRequestIgnoredArgs * args) = 0;
    virtual HRESULT __stdcall abi_ValuesChanged(Windows::UI::Composition::Interactions::IInteractionTracker * sender, Windows::UI::Composition::Interactions::IInteractionTrackerValuesChangedArgs * args) = 0;
};

struct __declspec(uuid("80dd82f1-ce25-488f-91dd-cb6455ccff2e")) __declspec(novtable) IInteractionTrackerRequestIgnoredArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RequestId(int32_t * value) = 0;
};

struct __declspec(uuid("bba5d7b7-6590-4498-8d6c-eb62b514c92a")) __declspec(novtable) IInteractionTrackerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::UI::Composition::ICompositor * compositor, Windows::UI::Composition::Interactions::IInteractionTracker ** result) = 0;
    virtual HRESULT __stdcall abi_CreateWithOwner(Windows::UI::Composition::ICompositor * compositor, Windows::UI::Composition::Interactions::IInteractionTrackerOwner * owner, Windows::UI::Composition::Interactions::IInteractionTracker ** result) = 0;
};

struct __declspec(uuid("cf1578ef-d3df-4501-b9e6-f02fb22f73d0")) __declspec(novtable) IInteractionTrackerValuesChangedArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Position(Windows::Foundation::Numerics::float3 * value) = 0;
    virtual HRESULT __stdcall get_RequestId(int32_t * value) = 0;
    virtual HRESULT __stdcall get_Scale(float * value) = 0;
};

struct __declspec(uuid("ca0e8a86-d8d6-4111-b088-70347bd2b0ed")) __declspec(novtable) IVisualInteractionSource : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsPositionXRailsEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsPositionXRailsEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsPositionYRailsEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsPositionYRailsEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_ManipulationRedirectionMode(winrt::Windows::UI::Composition::Interactions::VisualInteractionSourceRedirectionMode * value) = 0;
    virtual HRESULT __stdcall put_ManipulationRedirectionMode(winrt::Windows::UI::Composition::Interactions::VisualInteractionSourceRedirectionMode value) = 0;
    virtual HRESULT __stdcall get_PositionXChainingMode(winrt::Windows::UI::Composition::Interactions::InteractionChainingMode * value) = 0;
    virtual HRESULT __stdcall put_PositionXChainingMode(winrt::Windows::UI::Composition::Interactions::InteractionChainingMode value) = 0;
    virtual HRESULT __stdcall get_PositionXSourceMode(winrt::Windows::UI::Composition::Interactions::InteractionSourceMode * value) = 0;
    virtual HRESULT __stdcall put_PositionXSourceMode(winrt::Windows::UI::Composition::Interactions::InteractionSourceMode value) = 0;
    virtual HRESULT __stdcall get_PositionYChainingMode(winrt::Windows::UI::Composition::Interactions::InteractionChainingMode * value) = 0;
    virtual HRESULT __stdcall put_PositionYChainingMode(winrt::Windows::UI::Composition::Interactions::InteractionChainingMode value) = 0;
    virtual HRESULT __stdcall get_PositionYSourceMode(winrt::Windows::UI::Composition::Interactions::InteractionSourceMode * value) = 0;
    virtual HRESULT __stdcall put_PositionYSourceMode(winrt::Windows::UI::Composition::Interactions::InteractionSourceMode value) = 0;
    virtual HRESULT __stdcall get_ScaleChainingMode(winrt::Windows::UI::Composition::Interactions::InteractionChainingMode * value) = 0;
    virtual HRESULT __stdcall put_ScaleChainingMode(winrt::Windows::UI::Composition::Interactions::InteractionChainingMode value) = 0;
    virtual HRESULT __stdcall get_ScaleSourceMode(winrt::Windows::UI::Composition::Interactions::InteractionSourceMode * value) = 0;
    virtual HRESULT __stdcall put_ScaleSourceMode(winrt::Windows::UI::Composition::Interactions::InteractionSourceMode value) = 0;
    virtual HRESULT __stdcall get_Source(Windows::UI::Composition::IVisual ** value) = 0;
    virtual HRESULT __stdcall abi_TryRedirectForManipulation(Windows::UI::Input::IPointerPoint * pointerPoint) = 0;
};

struct __declspec(uuid("369965e1-8645-4f75-ba00-6479cd10c8e6")) __declspec(novtable) IVisualInteractionSourceStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::UI::Composition::IVisual * source, Windows::UI::Composition::Interactions::IVisualInteractionSource ** result) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::UI::Composition::Interactions::CompositionInteractionSourceCollection> { using default_interface = Windows::UI::Composition::Interactions::ICompositionInteractionSourceCollection; };
template <> struct traits<Windows::UI::Composition::Interactions::InteractionTracker> { using default_interface = Windows::UI::Composition::Interactions::IInteractionTracker; };
template <> struct traits<Windows::UI::Composition::Interactions::InteractionTrackerCustomAnimationStateEnteredArgs> { using default_interface = Windows::UI::Composition::Interactions::IInteractionTrackerCustomAnimationStateEnteredArgs; };
template <> struct traits<Windows::UI::Composition::Interactions::InteractionTrackerIdleStateEnteredArgs> { using default_interface = Windows::UI::Composition::Interactions::IInteractionTrackerIdleStateEnteredArgs; };
template <> struct traits<Windows::UI::Composition::Interactions::InteractionTrackerInertiaModifier> { using default_interface = Windows::UI::Composition::Interactions::IInteractionTrackerInertiaModifier; };
template <> struct traits<Windows::UI::Composition::Interactions::InteractionTrackerInertiaMotion> { using default_interface = Windows::UI::Composition::Interactions::IInteractionTrackerInertiaMotion; };
template <> struct traits<Windows::UI::Composition::Interactions::InteractionTrackerInertiaRestingValue> { using default_interface = Windows::UI::Composition::Interactions::IInteractionTrackerInertiaRestingValue; };
template <> struct traits<Windows::UI::Composition::Interactions::InteractionTrackerInertiaStateEnteredArgs> { using default_interface = Windows::UI::Composition::Interactions::IInteractionTrackerInertiaStateEnteredArgs; };
template <> struct traits<Windows::UI::Composition::Interactions::InteractionTrackerInteractingStateEnteredArgs> { using default_interface = Windows::UI::Composition::Interactions::IInteractionTrackerInteractingStateEnteredArgs; };
template <> struct traits<Windows::UI::Composition::Interactions::InteractionTrackerRequestIgnoredArgs> { using default_interface = Windows::UI::Composition::Interactions::IInteractionTrackerRequestIgnoredArgs; };
template <> struct traits<Windows::UI::Composition::Interactions::InteractionTrackerValuesChangedArgs> { using default_interface = Windows::UI::Composition::Interactions::IInteractionTrackerValuesChangedArgs; };
template <> struct traits<Windows::UI::Composition::Interactions::VisualInteractionSource> { using default_interface = Windows::UI::Composition::Interactions::IVisualInteractionSource; };

}

namespace Windows::UI::Composition::Interactions {

template <typename D>
struct WINRT_EBO impl_ICompositionInteractionSource
{
};

template <typename D>
struct WINRT_EBO impl_ICompositionInteractionSourceCollection
{
    int32_t Count() const;
    void Add(const Windows::UI::Composition::Interactions::ICompositionInteractionSource & value) const;
    void Remove(const Windows::UI::Composition::Interactions::ICompositionInteractionSource & value) const;
    void RemoveAll() const;
};

template <typename D>
struct WINRT_EBO impl_IInteractionTracker
{
    Windows::UI::Composition::Interactions::CompositionInteractionSourceCollection InteractionSources() const;
    bool IsPositionRoundingSuggested() const;
    Windows::Foundation::Numerics::float3 MaxPosition() const;
    void MaxPosition(const Windows::Foundation::Numerics::float3 & value) const;
    float MaxScale() const;
    void MaxScale(float value) const;
    Windows::Foundation::Numerics::float3 MinPosition() const;
    void MinPosition(const Windows::Foundation::Numerics::float3 & value) const;
    float MinScale() const;
    void MinScale(float value) const;
    Windows::Foundation::Numerics::float3 NaturalRestingPosition() const;
    float NaturalRestingScale() const;
    Windows::UI::Composition::Interactions::IInteractionTrackerOwner Owner() const;
    Windows::Foundation::Numerics::float3 Position() const;
    Windows::Foundation::IReference<Windows::Foundation::Numerics::float3> PositionInertiaDecayRate() const;
    void PositionInertiaDecayRate(const optional<Windows::Foundation::Numerics::float3> & value) const;
    Windows::Foundation::Numerics::float3 PositionVelocityInPixelsPerSecond() const;
    float Scale() const;
    Windows::Foundation::IReference<float> ScaleInertiaDecayRate() const;
    void ScaleInertiaDecayRate(const optional<float> & value) const;
    float ScaleVelocityInPercentPerSecond() const;
    void AdjustPositionXIfGreaterThanThreshold(float adjustment, float positionThreshold) const;
    void AdjustPositionYIfGreaterThanThreshold(float adjustment, float positionThreshold) const;
    void ConfigurePositionXInertiaModifiers(iterable<Windows::UI::Composition::Interactions::InteractionTrackerInertiaModifier> modifiers) const;
    void ConfigurePositionYInertiaModifiers(iterable<Windows::UI::Composition::Interactions::InteractionTrackerInertiaModifier> modifiers) const;
    void ConfigureScaleInertiaModifiers(iterable<Windows::UI::Composition::Interactions::InteractionTrackerInertiaModifier> modifiers) const;
    int32_t TryUpdatePosition(const Windows::Foundation::Numerics::float3 & value) const;
    int32_t TryUpdatePositionBy(const Windows::Foundation::Numerics::float3 & amount) const;
    int32_t TryUpdatePositionWithAnimation(const Windows::UI::Composition::CompositionAnimation & animation) const;
    int32_t TryUpdatePositionWithAdditionalVelocity(const Windows::Foundation::Numerics::float3 & velocityInPixelsPerSecond) const;
    int32_t TryUpdateScale(float value, const Windows::Foundation::Numerics::float3 & centerPoint) const;
    int32_t TryUpdateScaleWithAnimation(const Windows::UI::Composition::CompositionAnimation & animation, const Windows::Foundation::Numerics::float3 & centerPoint) const;
    int32_t TryUpdateScaleWithAdditionalVelocity(float velocityInPercentPerSecond, const Windows::Foundation::Numerics::float3 & centerPoint) const;
};

template <typename D>
struct WINRT_EBO impl_IInteractionTrackerCustomAnimationStateEnteredArgs
{
    int32_t RequestId() const;
};

template <typename D>
struct WINRT_EBO impl_IInteractionTrackerIdleStateEnteredArgs
{
    int32_t RequestId() const;
};

template <typename D>
struct WINRT_EBO impl_IInteractionTrackerInertiaModifier
{
};

template <typename D>
struct WINRT_EBO impl_IInteractionTrackerInertiaModifierFactory
{
};

template <typename D>
struct WINRT_EBO impl_IInteractionTrackerInertiaMotion
{
    Windows::UI::Composition::ExpressionAnimation Condition() const;
    void Condition(const Windows::UI::Composition::ExpressionAnimation & value) const;
    Windows::UI::Composition::ExpressionAnimation Motion() const;
    void Motion(const Windows::UI::Composition::ExpressionAnimation & value) const;
};

template <typename D>
struct WINRT_EBO impl_IInteractionTrackerInertiaMotionStatics
{
    Windows::UI::Composition::Interactions::InteractionTrackerInertiaMotion Create(const Windows::UI::Composition::Compositor & compositor) const;
};

template <typename D>
struct WINRT_EBO impl_IInteractionTrackerInertiaRestingValue
{
    Windows::UI::Composition::ExpressionAnimation Condition() const;
    void Condition(const Windows::UI::Composition::ExpressionAnimation & value) const;
    Windows::UI::Composition::ExpressionAnimation RestingValue() const;
    void RestingValue(const Windows::UI::Composition::ExpressionAnimation & value) const;
};

template <typename D>
struct WINRT_EBO impl_IInteractionTrackerInertiaRestingValueStatics
{
    Windows::UI::Composition::Interactions::InteractionTrackerInertiaRestingValue Create(const Windows::UI::Composition::Compositor & compositor) const;
};

template <typename D>
struct WINRT_EBO impl_IInteractionTrackerInertiaStateEnteredArgs
{
    Windows::Foundation::IReference<Windows::Foundation::Numerics::float3> ModifiedRestingPosition() const;
    Windows::Foundation::IReference<float> ModifiedRestingScale() const;
    Windows::Foundation::Numerics::float3 NaturalRestingPosition() const;
    float NaturalRestingScale() const;
    Windows::Foundation::Numerics::float3 PositionVelocityInPixelsPerSecond() const;
    int32_t RequestId() const;
    float ScaleVelocityInPercentPerSecond() const;
};

template <typename D>
struct WINRT_EBO impl_IInteractionTrackerInteractingStateEnteredArgs
{
    int32_t RequestId() const;
};

template <typename D>
struct WINRT_EBO impl_IInteractionTrackerOwner
{
    void CustomAnimationStateEntered(const Windows::UI::Composition::Interactions::InteractionTracker & sender, const Windows::UI::Composition::Interactions::InteractionTrackerCustomAnimationStateEnteredArgs & args) const;
    void IdleStateEntered(const Windows::UI::Composition::Interactions::InteractionTracker & sender, const Windows::UI::Composition::Interactions::InteractionTrackerIdleStateEnteredArgs & args) const;
    void InertiaStateEntered(const Windows::UI::Composition::Interactions::InteractionTracker & sender, const Windows::UI::Composition::Interactions::InteractionTrackerInertiaStateEnteredArgs & args) const;
    void InteractingStateEntered(const Windows::UI::Composition::Interactions::InteractionTracker & sender, const Windows::UI::Composition::Interactions::InteractionTrackerInteractingStateEnteredArgs & args) const;
    void RequestIgnored(const Windows::UI::Composition::Interactions::InteractionTracker & sender, const Windows::UI::Composition::Interactions::InteractionTrackerRequestIgnoredArgs & args) const;
    void ValuesChanged(const Windows::UI::Composition::Interactions::InteractionTracker & sender, const Windows::UI::Composition::Interactions::InteractionTrackerValuesChangedArgs & args) const;
};

template <typename D>
struct WINRT_EBO impl_IInteractionTrackerRequestIgnoredArgs
{
    int32_t RequestId() const;
};

template <typename D>
struct WINRT_EBO impl_IInteractionTrackerStatics
{
    Windows::UI::Composition::Interactions::InteractionTracker Create(const Windows::UI::Composition::Compositor & compositor) const;
    Windows::UI::Composition::Interactions::InteractionTracker CreateWithOwner(const Windows::UI::Composition::Compositor & compositor, const Windows::UI::Composition::Interactions::IInteractionTrackerOwner & owner) const;
};

template <typename D>
struct WINRT_EBO impl_IInteractionTrackerValuesChangedArgs
{
    Windows::Foundation::Numerics::float3 Position() const;
    int32_t RequestId() const;
    float Scale() const;
};

template <typename D>
struct WINRT_EBO impl_IVisualInteractionSource
{
    bool IsPositionXRailsEnabled() const;
    void IsPositionXRailsEnabled(bool value) const;
    bool IsPositionYRailsEnabled() const;
    void IsPositionYRailsEnabled(bool value) const;
    Windows::UI::Composition::Interactions::VisualInteractionSourceRedirectionMode ManipulationRedirectionMode() const;
    void ManipulationRedirectionMode(Windows::UI::Composition::Interactions::VisualInteractionSourceRedirectionMode value) const;
    Windows::UI::Composition::Interactions::InteractionChainingMode PositionXChainingMode() const;
    void PositionXChainingMode(Windows::UI::Composition::Interactions::InteractionChainingMode value) const;
    Windows::UI::Composition::Interactions::InteractionSourceMode PositionXSourceMode() const;
    void PositionXSourceMode(Windows::UI::Composition::Interactions::InteractionSourceMode value) const;
    Windows::UI::Composition::Interactions::InteractionChainingMode PositionYChainingMode() const;
    void PositionYChainingMode(Windows::UI::Composition::Interactions::InteractionChainingMode value) const;
    Windows::UI::Composition::Interactions::InteractionSourceMode PositionYSourceMode() const;
    void PositionYSourceMode(Windows::UI::Composition::Interactions::InteractionSourceMode value) const;
    Windows::UI::Composition::Interactions::InteractionChainingMode ScaleChainingMode() const;
    void ScaleChainingMode(Windows::UI::Composition::Interactions::InteractionChainingMode value) const;
    Windows::UI::Composition::Interactions::InteractionSourceMode ScaleSourceMode() const;
    void ScaleSourceMode(Windows::UI::Composition::Interactions::InteractionSourceMode value) const;
    Windows::UI::Composition::Visual Source() const;
    void TryRedirectForManipulation(const Windows::UI::Input::PointerPoint & pointerPoint) const;
};

template <typename D>
struct WINRT_EBO impl_IVisualInteractionSourceStatics
{
    Windows::UI::Composition::Interactions::VisualInteractionSource Create(const Windows::UI::Composition::Visual & source) const;
};

}

namespace impl {

template <> struct traits<Windows::UI::Composition::Interactions::ICompositionInteractionSource>
{
    using abi = ABI::Windows::UI::Composition::Interactions::ICompositionInteractionSource;
    template <typename D> using consume = Windows::UI::Composition::Interactions::impl_ICompositionInteractionSource<D>;
};

template <> struct traits<Windows::UI::Composition::Interactions::ICompositionInteractionSourceCollection>
{
    using abi = ABI::Windows::UI::Composition::Interactions::ICompositionInteractionSourceCollection;
    template <typename D> using consume = Windows::UI::Composition::Interactions::impl_ICompositionInteractionSourceCollection<D>;
};

template <> struct traits<Windows::UI::Composition::Interactions::IInteractionTracker>
{
    using abi = ABI::Windows::UI::Composition::Interactions::IInteractionTracker;
    template <typename D> using consume = Windows::UI::Composition::Interactions::impl_IInteractionTracker<D>;
};

template <> struct traits<Windows::UI::Composition::Interactions::IInteractionTrackerCustomAnimationStateEnteredArgs>
{
    using abi = ABI::Windows::UI::Composition::Interactions::IInteractionTrackerCustomAnimationStateEnteredArgs;
    template <typename D> using consume = Windows::UI::Composition::Interactions::impl_IInteractionTrackerCustomAnimationStateEnteredArgs<D>;
};

template <> struct traits<Windows::UI::Composition::Interactions::IInteractionTrackerIdleStateEnteredArgs>
{
    using abi = ABI::Windows::UI::Composition::Interactions::IInteractionTrackerIdleStateEnteredArgs;
    template <typename D> using consume = Windows::UI::Composition::Interactions::impl_IInteractionTrackerIdleStateEnteredArgs<D>;
};

template <> struct traits<Windows::UI::Composition::Interactions::IInteractionTrackerInertiaModifier>
{
    using abi = ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaModifier;
    template <typename D> using consume = Windows::UI::Composition::Interactions::impl_IInteractionTrackerInertiaModifier<D>;
};

template <> struct traits<Windows::UI::Composition::Interactions::IInteractionTrackerInertiaModifierFactory>
{
    using abi = ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaModifierFactory;
    template <typename D> using consume = Windows::UI::Composition::Interactions::impl_IInteractionTrackerInertiaModifierFactory<D>;
};

template <> struct traits<Windows::UI::Composition::Interactions::IInteractionTrackerInertiaMotion>
{
    using abi = ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaMotion;
    template <typename D> using consume = Windows::UI::Composition::Interactions::impl_IInteractionTrackerInertiaMotion<D>;
};

template <> struct traits<Windows::UI::Composition::Interactions::IInteractionTrackerInertiaMotionStatics>
{
    using abi = ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaMotionStatics;
    template <typename D> using consume = Windows::UI::Composition::Interactions::impl_IInteractionTrackerInertiaMotionStatics<D>;
};

template <> struct traits<Windows::UI::Composition::Interactions::IInteractionTrackerInertiaRestingValue>
{
    using abi = ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaRestingValue;
    template <typename D> using consume = Windows::UI::Composition::Interactions::impl_IInteractionTrackerInertiaRestingValue<D>;
};

template <> struct traits<Windows::UI::Composition::Interactions::IInteractionTrackerInertiaRestingValueStatics>
{
    using abi = ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaRestingValueStatics;
    template <typename D> using consume = Windows::UI::Composition::Interactions::impl_IInteractionTrackerInertiaRestingValueStatics<D>;
};

template <> struct traits<Windows::UI::Composition::Interactions::IInteractionTrackerInertiaStateEnteredArgs>
{
    using abi = ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInertiaStateEnteredArgs;
    template <typename D> using consume = Windows::UI::Composition::Interactions::impl_IInteractionTrackerInertiaStateEnteredArgs<D>;
};

template <> struct traits<Windows::UI::Composition::Interactions::IInteractionTrackerInteractingStateEnteredArgs>
{
    using abi = ABI::Windows::UI::Composition::Interactions::IInteractionTrackerInteractingStateEnteredArgs;
    template <typename D> using consume = Windows::UI::Composition::Interactions::impl_IInteractionTrackerInteractingStateEnteredArgs<D>;
};

template <> struct traits<Windows::UI::Composition::Interactions::IInteractionTrackerOwner>
{
    using abi = ABI::Windows::UI::Composition::Interactions::IInteractionTrackerOwner;
    template <typename D> using consume = Windows::UI::Composition::Interactions::impl_IInteractionTrackerOwner<D>;
};

template <> struct traits<Windows::UI::Composition::Interactions::IInteractionTrackerRequestIgnoredArgs>
{
    using abi = ABI::Windows::UI::Composition::Interactions::IInteractionTrackerRequestIgnoredArgs;
    template <typename D> using consume = Windows::UI::Composition::Interactions::impl_IInteractionTrackerRequestIgnoredArgs<D>;
};

template <> struct traits<Windows::UI::Composition::Interactions::IInteractionTrackerStatics>
{
    using abi = ABI::Windows::UI::Composition::Interactions::IInteractionTrackerStatics;
    template <typename D> using consume = Windows::UI::Composition::Interactions::impl_IInteractionTrackerStatics<D>;
};

template <> struct traits<Windows::UI::Composition::Interactions::IInteractionTrackerValuesChangedArgs>
{
    using abi = ABI::Windows::UI::Composition::Interactions::IInteractionTrackerValuesChangedArgs;
    template <typename D> using consume = Windows::UI::Composition::Interactions::impl_IInteractionTrackerValuesChangedArgs<D>;
};

template <> struct traits<Windows::UI::Composition::Interactions::IVisualInteractionSource>
{
    using abi = ABI::Windows::UI::Composition::Interactions::IVisualInteractionSource;
    template <typename D> using consume = Windows::UI::Composition::Interactions::impl_IVisualInteractionSource<D>;
};

template <> struct traits<Windows::UI::Composition::Interactions::IVisualInteractionSourceStatics>
{
    using abi = ABI::Windows::UI::Composition::Interactions::IVisualInteractionSourceStatics;
    template <typename D> using consume = Windows::UI::Composition::Interactions::impl_IVisualInteractionSourceStatics<D>;
};

template <> struct traits<Windows::UI::Composition::Interactions::CompositionInteractionSourceCollection>
{
    using abi = ABI::Windows::UI::Composition::Interactions::CompositionInteractionSourceCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Composition.Interactions.CompositionInteractionSourceCollection"; }
};

template <> struct traits<Windows::UI::Composition::Interactions::InteractionTracker>
{
    using abi = ABI::Windows::UI::Composition::Interactions::InteractionTracker;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Composition.Interactions.InteractionTracker"; }
};

template <> struct traits<Windows::UI::Composition::Interactions::InteractionTrackerCustomAnimationStateEnteredArgs>
{
    using abi = ABI::Windows::UI::Composition::Interactions::InteractionTrackerCustomAnimationStateEnteredArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Composition.Interactions.InteractionTrackerCustomAnimationStateEnteredArgs"; }
};

template <> struct traits<Windows::UI::Composition::Interactions::InteractionTrackerIdleStateEnteredArgs>
{
    using abi = ABI::Windows::UI::Composition::Interactions::InteractionTrackerIdleStateEnteredArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Composition.Interactions.InteractionTrackerIdleStateEnteredArgs"; }
};

template <> struct traits<Windows::UI::Composition::Interactions::InteractionTrackerInertiaModifier>
{
    using abi = ABI::Windows::UI::Composition::Interactions::InteractionTrackerInertiaModifier;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Composition.Interactions.InteractionTrackerInertiaModifier"; }
};

template <> struct traits<Windows::UI::Composition::Interactions::InteractionTrackerInertiaMotion>
{
    using abi = ABI::Windows::UI::Composition::Interactions::InteractionTrackerInertiaMotion;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Composition.Interactions.InteractionTrackerInertiaMotion"; }
};

template <> struct traits<Windows::UI::Composition::Interactions::InteractionTrackerInertiaRestingValue>
{
    using abi = ABI::Windows::UI::Composition::Interactions::InteractionTrackerInertiaRestingValue;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Composition.Interactions.InteractionTrackerInertiaRestingValue"; }
};

template <> struct traits<Windows::UI::Composition::Interactions::InteractionTrackerInertiaStateEnteredArgs>
{
    using abi = ABI::Windows::UI::Composition::Interactions::InteractionTrackerInertiaStateEnteredArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Composition.Interactions.InteractionTrackerInertiaStateEnteredArgs"; }
};

template <> struct traits<Windows::UI::Composition::Interactions::InteractionTrackerInteractingStateEnteredArgs>
{
    using abi = ABI::Windows::UI::Composition::Interactions::InteractionTrackerInteractingStateEnteredArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Composition.Interactions.InteractionTrackerInteractingStateEnteredArgs"; }
};

template <> struct traits<Windows::UI::Composition::Interactions::InteractionTrackerRequestIgnoredArgs>
{
    using abi = ABI::Windows::UI::Composition::Interactions::InteractionTrackerRequestIgnoredArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Composition.Interactions.InteractionTrackerRequestIgnoredArgs"; }
};

template <> struct traits<Windows::UI::Composition::Interactions::InteractionTrackerValuesChangedArgs>
{
    using abi = ABI::Windows::UI::Composition::Interactions::InteractionTrackerValuesChangedArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Composition.Interactions.InteractionTrackerValuesChangedArgs"; }
};

template <> struct traits<Windows::UI::Composition::Interactions::VisualInteractionSource>
{
    using abi = ABI::Windows::UI::Composition::Interactions::VisualInteractionSource;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Composition.Interactions.VisualInteractionSource"; }
};

}

}
