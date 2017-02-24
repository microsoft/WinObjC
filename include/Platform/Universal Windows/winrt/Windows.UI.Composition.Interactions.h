// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.UI.Composition.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.UI.Input.3.h"
#include "internal/Windows.UI.Composition.Interactions.3.h"
#include "Windows.UI.Composition.h"
#include "Windows.Foundation.h"
#include "Windows.Foundation.Collections.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::UI::Composition::Interactions::ICompositionInteractionSource> : produce_base<D, Windows::UI::Composition::Interactions::ICompositionInteractionSource>
{};

template <typename D>
struct produce<D, Windows::UI::Composition::Interactions::ICompositionInteractionSourceCollection> : produce_base<D, Windows::UI::Composition::Interactions::ICompositionInteractionSourceCollection>
{
    HRESULT __stdcall get_Count(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Count());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Add(impl::abi_arg_in<Windows::UI::Composition::Interactions::ICompositionInteractionSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Add(*reinterpret_cast<const Windows::UI::Composition::Interactions::ICompositionInteractionSource *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Remove(impl::abi_arg_in<Windows::UI::Composition::Interactions::ICompositionInteractionSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Remove(*reinterpret_cast<const Windows::UI::Composition::Interactions::ICompositionInteractionSource *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveAll() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveAll();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::Interactions::IInteractionTracker> : produce_base<D, Windows::UI::Composition::Interactions::IInteractionTracker>
{
    HRESULT __stdcall get_InteractionSources(impl::abi_arg_out<Windows::UI::Composition::Interactions::ICompositionInteractionSourceCollection> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InteractionSources());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsPositionRoundingSuggested(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsPositionRoundingSuggested());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxPosition(impl::abi_arg_out<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxPosition());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxPosition(impl::abi_arg_in<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxPosition(*reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxScale(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxScale());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxScale(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxScale(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinPosition(impl::abi_arg_out<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinPosition());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MinPosition(impl::abi_arg_in<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MinPosition(*reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinScale(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinScale());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MinScale(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MinScale(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NaturalRestingPosition(impl::abi_arg_out<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NaturalRestingPosition());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NaturalRestingScale(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NaturalRestingScale());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Owner(impl::abi_arg_out<Windows::UI::Composition::Interactions::IInteractionTrackerOwner> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Owner());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Position(impl::abi_arg_out<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Position());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PositionInertiaDecayRate(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::Numerics::float3>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PositionInertiaDecayRate());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PositionInertiaDecayRate(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::Numerics::float3>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PositionInertiaDecayRate(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::Numerics::float3> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PositionVelocityInPixelsPerSecond(impl::abi_arg_out<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PositionVelocityInPixelsPerSecond());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Scale(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Scale());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ScaleInertiaDecayRate(impl::abi_arg_out<Windows::Foundation::IReference<float>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ScaleInertiaDecayRate());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ScaleInertiaDecayRate(impl::abi_arg_in<Windows::Foundation::IReference<float>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ScaleInertiaDecayRate(*reinterpret_cast<const Windows::Foundation::IReference<float> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ScaleVelocityInPercentPerSecond(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ScaleVelocityInPercentPerSecond());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AdjustPositionXIfGreaterThanThreshold(float adjustment, float positionThreshold) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AdjustPositionXIfGreaterThanThreshold(adjustment, positionThreshold);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AdjustPositionYIfGreaterThanThreshold(float adjustment, float positionThreshold) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AdjustPositionYIfGreaterThanThreshold(adjustment, positionThreshold);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ConfigurePositionXInertiaModifiers(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::UI::Composition::Interactions::InteractionTrackerInertiaModifier>> modifiers) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ConfigurePositionXInertiaModifiers(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::UI::Composition::Interactions::InteractionTrackerInertiaModifier> *>(&modifiers));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ConfigurePositionYInertiaModifiers(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::UI::Composition::Interactions::InteractionTrackerInertiaModifier>> modifiers) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ConfigurePositionYInertiaModifiers(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::UI::Composition::Interactions::InteractionTrackerInertiaModifier> *>(&modifiers));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ConfigureScaleInertiaModifiers(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::UI::Composition::Interactions::InteractionTrackerInertiaModifier>> modifiers) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ConfigureScaleInertiaModifiers(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::UI::Composition::Interactions::InteractionTrackerInertiaModifier> *>(&modifiers));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryUpdatePosition(impl::abi_arg_in<Windows::Foundation::Numerics::float3> value, int32_t * requestId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *requestId = detach_abi(this->shim().TryUpdatePosition(*reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryUpdatePositionBy(impl::abi_arg_in<Windows::Foundation::Numerics::float3> amount, int32_t * requestId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *requestId = detach_abi(this->shim().TryUpdatePositionBy(*reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&amount)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryUpdatePositionWithAnimation(impl::abi_arg_in<Windows::UI::Composition::ICompositionAnimation> animation, int32_t * requestId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *requestId = detach_abi(this->shim().TryUpdatePositionWithAnimation(*reinterpret_cast<const Windows::UI::Composition::CompositionAnimation *>(&animation)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryUpdatePositionWithAdditionalVelocity(impl::abi_arg_in<Windows::Foundation::Numerics::float3> velocityInPixelsPerSecond, int32_t * requestId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *requestId = detach_abi(this->shim().TryUpdatePositionWithAdditionalVelocity(*reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&velocityInPixelsPerSecond)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryUpdateScale(float value, impl::abi_arg_in<Windows::Foundation::Numerics::float3> centerPoint, int32_t * requestId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *requestId = detach_abi(this->shim().TryUpdateScale(value, *reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&centerPoint)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryUpdateScaleWithAnimation(impl::abi_arg_in<Windows::UI::Composition::ICompositionAnimation> animation, impl::abi_arg_in<Windows::Foundation::Numerics::float3> centerPoint, int32_t * requestId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *requestId = detach_abi(this->shim().TryUpdateScaleWithAnimation(*reinterpret_cast<const Windows::UI::Composition::CompositionAnimation *>(&animation), *reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&centerPoint)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryUpdateScaleWithAdditionalVelocity(float velocityInPercentPerSecond, impl::abi_arg_in<Windows::Foundation::Numerics::float3> centerPoint, int32_t * requestId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *requestId = detach_abi(this->shim().TryUpdateScaleWithAdditionalVelocity(velocityInPercentPerSecond, *reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&centerPoint)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::Interactions::IInteractionTrackerCustomAnimationStateEnteredArgs> : produce_base<D, Windows::UI::Composition::Interactions::IInteractionTrackerCustomAnimationStateEnteredArgs>
{
    HRESULT __stdcall get_RequestId(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequestId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::Interactions::IInteractionTrackerIdleStateEnteredArgs> : produce_base<D, Windows::UI::Composition::Interactions::IInteractionTrackerIdleStateEnteredArgs>
{
    HRESULT __stdcall get_RequestId(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequestId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::Interactions::IInteractionTrackerInertiaModifier> : produce_base<D, Windows::UI::Composition::Interactions::IInteractionTrackerInertiaModifier>
{};

template <typename D>
struct produce<D, Windows::UI::Composition::Interactions::IInteractionTrackerInertiaModifierFactory> : produce_base<D, Windows::UI::Composition::Interactions::IInteractionTrackerInertiaModifierFactory>
{};

template <typename D>
struct produce<D, Windows::UI::Composition::Interactions::IInteractionTrackerInertiaMotion> : produce_base<D, Windows::UI::Composition::Interactions::IInteractionTrackerInertiaMotion>
{
    HRESULT __stdcall get_Condition(impl::abi_arg_out<Windows::UI::Composition::IExpressionAnimation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Condition());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Condition(impl::abi_arg_in<Windows::UI::Composition::IExpressionAnimation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Condition(*reinterpret_cast<const Windows::UI::Composition::ExpressionAnimation *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Motion(impl::abi_arg_out<Windows::UI::Composition::IExpressionAnimation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Motion());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Motion(impl::abi_arg_in<Windows::UI::Composition::IExpressionAnimation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Motion(*reinterpret_cast<const Windows::UI::Composition::ExpressionAnimation *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::Interactions::IInteractionTrackerInertiaMotionStatics> : produce_base<D, Windows::UI::Composition::Interactions::IInteractionTrackerInertiaMotionStatics>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::UI::Composition::ICompositor> compositor, impl::abi_arg_out<Windows::UI::Composition::Interactions::IInteractionTrackerInertiaMotion> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::UI::Composition::Compositor *>(&compositor)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::Interactions::IInteractionTrackerInertiaRestingValue> : produce_base<D, Windows::UI::Composition::Interactions::IInteractionTrackerInertiaRestingValue>
{
    HRESULT __stdcall get_Condition(impl::abi_arg_out<Windows::UI::Composition::IExpressionAnimation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Condition());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Condition(impl::abi_arg_in<Windows::UI::Composition::IExpressionAnimation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Condition(*reinterpret_cast<const Windows::UI::Composition::ExpressionAnimation *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RestingValue(impl::abi_arg_out<Windows::UI::Composition::IExpressionAnimation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RestingValue());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RestingValue(impl::abi_arg_in<Windows::UI::Composition::IExpressionAnimation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RestingValue(*reinterpret_cast<const Windows::UI::Composition::ExpressionAnimation *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::Interactions::IInteractionTrackerInertiaRestingValueStatics> : produce_base<D, Windows::UI::Composition::Interactions::IInteractionTrackerInertiaRestingValueStatics>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::UI::Composition::ICompositor> compositor, impl::abi_arg_out<Windows::UI::Composition::Interactions::IInteractionTrackerInertiaRestingValue> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::UI::Composition::Compositor *>(&compositor)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::Interactions::IInteractionTrackerInertiaStateEnteredArgs> : produce_base<D, Windows::UI::Composition::Interactions::IInteractionTrackerInertiaStateEnteredArgs>
{
    HRESULT __stdcall get_ModifiedRestingPosition(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::Numerics::float3>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ModifiedRestingPosition());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ModifiedRestingScale(impl::abi_arg_out<Windows::Foundation::IReference<float>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ModifiedRestingScale());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NaturalRestingPosition(impl::abi_arg_out<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NaturalRestingPosition());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NaturalRestingScale(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NaturalRestingScale());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PositionVelocityInPixelsPerSecond(impl::abi_arg_out<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PositionVelocityInPixelsPerSecond());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RequestId(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequestId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ScaleVelocityInPercentPerSecond(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ScaleVelocityInPercentPerSecond());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::Interactions::IInteractionTrackerInteractingStateEnteredArgs> : produce_base<D, Windows::UI::Composition::Interactions::IInteractionTrackerInteractingStateEnteredArgs>
{
    HRESULT __stdcall get_RequestId(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequestId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::Interactions::IInteractionTrackerOwner> : produce_base<D, Windows::UI::Composition::Interactions::IInteractionTrackerOwner>
{
    HRESULT __stdcall abi_CustomAnimationStateEntered(impl::abi_arg_in<Windows::UI::Composition::Interactions::IInteractionTracker> sender, impl::abi_arg_in<Windows::UI::Composition::Interactions::IInteractionTrackerCustomAnimationStateEnteredArgs> args) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CustomAnimationStateEntered(*reinterpret_cast<const Windows::UI::Composition::Interactions::InteractionTracker *>(&sender), *reinterpret_cast<const Windows::UI::Composition::Interactions::InteractionTrackerCustomAnimationStateEnteredArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IdleStateEntered(impl::abi_arg_in<Windows::UI::Composition::Interactions::IInteractionTracker> sender, impl::abi_arg_in<Windows::UI::Composition::Interactions::IInteractionTrackerIdleStateEnteredArgs> args) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IdleStateEntered(*reinterpret_cast<const Windows::UI::Composition::Interactions::InteractionTracker *>(&sender), *reinterpret_cast<const Windows::UI::Composition::Interactions::InteractionTrackerIdleStateEnteredArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_InertiaStateEntered(impl::abi_arg_in<Windows::UI::Composition::Interactions::IInteractionTracker> sender, impl::abi_arg_in<Windows::UI::Composition::Interactions::IInteractionTrackerInertiaStateEnteredArgs> args) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InertiaStateEntered(*reinterpret_cast<const Windows::UI::Composition::Interactions::InteractionTracker *>(&sender), *reinterpret_cast<const Windows::UI::Composition::Interactions::InteractionTrackerInertiaStateEnteredArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_InteractingStateEntered(impl::abi_arg_in<Windows::UI::Composition::Interactions::IInteractionTracker> sender, impl::abi_arg_in<Windows::UI::Composition::Interactions::IInteractionTrackerInteractingStateEnteredArgs> args) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InteractingStateEntered(*reinterpret_cast<const Windows::UI::Composition::Interactions::InteractionTracker *>(&sender), *reinterpret_cast<const Windows::UI::Composition::Interactions::InteractionTrackerInteractingStateEnteredArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestIgnored(impl::abi_arg_in<Windows::UI::Composition::Interactions::IInteractionTracker> sender, impl::abi_arg_in<Windows::UI::Composition::Interactions::IInteractionTrackerRequestIgnoredArgs> args) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequestIgnored(*reinterpret_cast<const Windows::UI::Composition::Interactions::InteractionTracker *>(&sender), *reinterpret_cast<const Windows::UI::Composition::Interactions::InteractionTrackerRequestIgnoredArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ValuesChanged(impl::abi_arg_in<Windows::UI::Composition::Interactions::IInteractionTracker> sender, impl::abi_arg_in<Windows::UI::Composition::Interactions::IInteractionTrackerValuesChangedArgs> args) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ValuesChanged(*reinterpret_cast<const Windows::UI::Composition::Interactions::InteractionTracker *>(&sender), *reinterpret_cast<const Windows::UI::Composition::Interactions::InteractionTrackerValuesChangedArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::Interactions::IInteractionTrackerRequestIgnoredArgs> : produce_base<D, Windows::UI::Composition::Interactions::IInteractionTrackerRequestIgnoredArgs>
{
    HRESULT __stdcall get_RequestId(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequestId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::Interactions::IInteractionTrackerStatics> : produce_base<D, Windows::UI::Composition::Interactions::IInteractionTrackerStatics>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::UI::Composition::ICompositor> compositor, impl::abi_arg_out<Windows::UI::Composition::Interactions::IInteractionTracker> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::UI::Composition::Compositor *>(&compositor)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithOwner(impl::abi_arg_in<Windows::UI::Composition::ICompositor> compositor, impl::abi_arg_in<Windows::UI::Composition::Interactions::IInteractionTrackerOwner> owner, impl::abi_arg_out<Windows::UI::Composition::Interactions::IInteractionTracker> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateWithOwner(*reinterpret_cast<const Windows::UI::Composition::Compositor *>(&compositor), *reinterpret_cast<const Windows::UI::Composition::Interactions::IInteractionTrackerOwner *>(&owner)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::Interactions::IInteractionTrackerValuesChangedArgs> : produce_base<D, Windows::UI::Composition::Interactions::IInteractionTrackerValuesChangedArgs>
{
    HRESULT __stdcall get_Position(impl::abi_arg_out<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Position());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RequestId(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequestId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Scale(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Scale());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::Interactions::IVisualInteractionSource> : produce_base<D, Windows::UI::Composition::Interactions::IVisualInteractionSource>
{
    HRESULT __stdcall get_IsPositionXRailsEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsPositionXRailsEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsPositionXRailsEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsPositionXRailsEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsPositionYRailsEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsPositionYRailsEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsPositionYRailsEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsPositionYRailsEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ManipulationRedirectionMode(Windows::UI::Composition::Interactions::VisualInteractionSourceRedirectionMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ManipulationRedirectionMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ManipulationRedirectionMode(Windows::UI::Composition::Interactions::VisualInteractionSourceRedirectionMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ManipulationRedirectionMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PositionXChainingMode(Windows::UI::Composition::Interactions::InteractionChainingMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PositionXChainingMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PositionXChainingMode(Windows::UI::Composition::Interactions::InteractionChainingMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PositionXChainingMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PositionXSourceMode(Windows::UI::Composition::Interactions::InteractionSourceMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PositionXSourceMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PositionXSourceMode(Windows::UI::Composition::Interactions::InteractionSourceMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PositionXSourceMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PositionYChainingMode(Windows::UI::Composition::Interactions::InteractionChainingMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PositionYChainingMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PositionYChainingMode(Windows::UI::Composition::Interactions::InteractionChainingMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PositionYChainingMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PositionYSourceMode(Windows::UI::Composition::Interactions::InteractionSourceMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PositionYSourceMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PositionYSourceMode(Windows::UI::Composition::Interactions::InteractionSourceMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PositionYSourceMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ScaleChainingMode(Windows::UI::Composition::Interactions::InteractionChainingMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ScaleChainingMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ScaleChainingMode(Windows::UI::Composition::Interactions::InteractionChainingMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ScaleChainingMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ScaleSourceMode(Windows::UI::Composition::Interactions::InteractionSourceMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ScaleSourceMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ScaleSourceMode(Windows::UI::Composition::Interactions::InteractionSourceMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ScaleSourceMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Source(impl::abi_arg_out<Windows::UI::Composition::IVisual> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Source());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryRedirectForManipulation(impl::abi_arg_in<Windows::UI::Input::IPointerPoint> pointerPoint) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TryRedirectForManipulation(*reinterpret_cast<const Windows::UI::Input::PointerPoint *>(&pointerPoint));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::Interactions::IVisualInteractionSourceStatics> : produce_base<D, Windows::UI::Composition::Interactions::IVisualInteractionSourceStatics>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::UI::Composition::IVisual> source, impl::abi_arg_out<Windows::UI::Composition::Interactions::IVisualInteractionSource> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::UI::Composition::Visual *>(&source)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::UI::Composition::Interactions {

template <typename D> int32_t impl_ICompositionInteractionSourceCollection<D>::Count() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ICompositionInteractionSourceCollection)->get_Count(&value));
    return value;
}

template <typename D> void impl_ICompositionInteractionSourceCollection<D>::Add(const Windows::UI::Composition::Interactions::ICompositionInteractionSource & value) const
{
    check_hresult(WINRT_SHIM(ICompositionInteractionSourceCollection)->abi_Add(get_abi(value)));
}

template <typename D> void impl_ICompositionInteractionSourceCollection<D>::Remove(const Windows::UI::Composition::Interactions::ICompositionInteractionSource & value) const
{
    check_hresult(WINRT_SHIM(ICompositionInteractionSourceCollection)->abi_Remove(get_abi(value)));
}

template <typename D> void impl_ICompositionInteractionSourceCollection<D>::RemoveAll() const
{
    check_hresult(WINRT_SHIM(ICompositionInteractionSourceCollection)->abi_RemoveAll());
}

template <typename D> Windows::UI::Composition::Interactions::InteractionTracker impl_IInteractionTrackerStatics<D>::Create(const Windows::UI::Composition::Compositor & compositor) const
{
    Windows::UI::Composition::Interactions::InteractionTracker result { nullptr };
    check_hresult(WINRT_SHIM(IInteractionTrackerStatics)->abi_Create(get_abi(compositor), put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::Interactions::InteractionTracker impl_IInteractionTrackerStatics<D>::CreateWithOwner(const Windows::UI::Composition::Compositor & compositor, const Windows::UI::Composition::Interactions::IInteractionTrackerOwner & owner) const
{
    Windows::UI::Composition::Interactions::InteractionTracker result { nullptr };
    check_hresult(WINRT_SHIM(IInteractionTrackerStatics)->abi_CreateWithOwner(get_abi(compositor), get_abi(owner), put_abi(result)));
    return result;
}

template <typename D> void impl_IInteractionTrackerOwner<D>::CustomAnimationStateEntered(const Windows::UI::Composition::Interactions::InteractionTracker & sender, const Windows::UI::Composition::Interactions::InteractionTrackerCustomAnimationStateEnteredArgs & args) const
{
    check_hresult(WINRT_SHIM(IInteractionTrackerOwner)->abi_CustomAnimationStateEntered(get_abi(sender), get_abi(args)));
}

template <typename D> void impl_IInteractionTrackerOwner<D>::IdleStateEntered(const Windows::UI::Composition::Interactions::InteractionTracker & sender, const Windows::UI::Composition::Interactions::InteractionTrackerIdleStateEnteredArgs & args) const
{
    check_hresult(WINRT_SHIM(IInteractionTrackerOwner)->abi_IdleStateEntered(get_abi(sender), get_abi(args)));
}

template <typename D> void impl_IInteractionTrackerOwner<D>::InertiaStateEntered(const Windows::UI::Composition::Interactions::InteractionTracker & sender, const Windows::UI::Composition::Interactions::InteractionTrackerInertiaStateEnteredArgs & args) const
{
    check_hresult(WINRT_SHIM(IInteractionTrackerOwner)->abi_InertiaStateEntered(get_abi(sender), get_abi(args)));
}

template <typename D> void impl_IInteractionTrackerOwner<D>::InteractingStateEntered(const Windows::UI::Composition::Interactions::InteractionTracker & sender, const Windows::UI::Composition::Interactions::InteractionTrackerInteractingStateEnteredArgs & args) const
{
    check_hresult(WINRT_SHIM(IInteractionTrackerOwner)->abi_InteractingStateEntered(get_abi(sender), get_abi(args)));
}

template <typename D> void impl_IInteractionTrackerOwner<D>::RequestIgnored(const Windows::UI::Composition::Interactions::InteractionTracker & sender, const Windows::UI::Composition::Interactions::InteractionTrackerRequestIgnoredArgs & args) const
{
    check_hresult(WINRT_SHIM(IInteractionTrackerOwner)->abi_RequestIgnored(get_abi(sender), get_abi(args)));
}

template <typename D> void impl_IInteractionTrackerOwner<D>::ValuesChanged(const Windows::UI::Composition::Interactions::InteractionTracker & sender, const Windows::UI::Composition::Interactions::InteractionTrackerValuesChangedArgs & args) const
{
    check_hresult(WINRT_SHIM(IInteractionTrackerOwner)->abi_ValuesChanged(get_abi(sender), get_abi(args)));
}

template <typename D> Windows::UI::Composition::Interactions::CompositionInteractionSourceCollection impl_IInteractionTracker<D>::InteractionSources() const
{
    Windows::UI::Composition::Interactions::CompositionInteractionSourceCollection value { nullptr };
    check_hresult(WINRT_SHIM(IInteractionTracker)->get_InteractionSources(put_abi(value)));
    return value;
}

template <typename D> bool impl_IInteractionTracker<D>::IsPositionRoundingSuggested() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IInteractionTracker)->get_IsPositionRoundingSuggested(&value));
    return value;
}

template <typename D> Windows::Foundation::Numerics::float3 impl_IInteractionTracker<D>::MaxPosition() const
{
    Windows::Foundation::Numerics::float3 value {};
    check_hresult(WINRT_SHIM(IInteractionTracker)->get_MaxPosition(put_abi(value)));
    return value;
}

template <typename D> void impl_IInteractionTracker<D>::MaxPosition(const Windows::Foundation::Numerics::float3 & value) const
{
    check_hresult(WINRT_SHIM(IInteractionTracker)->put_MaxPosition(get_abi(value)));
}

template <typename D> float impl_IInteractionTracker<D>::MaxScale() const
{
    float value {};
    check_hresult(WINRT_SHIM(IInteractionTracker)->get_MaxScale(&value));
    return value;
}

template <typename D> void impl_IInteractionTracker<D>::MaxScale(float value) const
{
    check_hresult(WINRT_SHIM(IInteractionTracker)->put_MaxScale(value));
}

template <typename D> Windows::Foundation::Numerics::float3 impl_IInteractionTracker<D>::MinPosition() const
{
    Windows::Foundation::Numerics::float3 value {};
    check_hresult(WINRT_SHIM(IInteractionTracker)->get_MinPosition(put_abi(value)));
    return value;
}

template <typename D> void impl_IInteractionTracker<D>::MinPosition(const Windows::Foundation::Numerics::float3 & value) const
{
    check_hresult(WINRT_SHIM(IInteractionTracker)->put_MinPosition(get_abi(value)));
}

template <typename D> float impl_IInteractionTracker<D>::MinScale() const
{
    float value {};
    check_hresult(WINRT_SHIM(IInteractionTracker)->get_MinScale(&value));
    return value;
}

template <typename D> void impl_IInteractionTracker<D>::MinScale(float value) const
{
    check_hresult(WINRT_SHIM(IInteractionTracker)->put_MinScale(value));
}

template <typename D> Windows::Foundation::Numerics::float3 impl_IInteractionTracker<D>::NaturalRestingPosition() const
{
    Windows::Foundation::Numerics::float3 value {};
    check_hresult(WINRT_SHIM(IInteractionTracker)->get_NaturalRestingPosition(put_abi(value)));
    return value;
}

template <typename D> float impl_IInteractionTracker<D>::NaturalRestingScale() const
{
    float value {};
    check_hresult(WINRT_SHIM(IInteractionTracker)->get_NaturalRestingScale(&value));
    return value;
}

template <typename D> Windows::UI::Composition::Interactions::IInteractionTrackerOwner impl_IInteractionTracker<D>::Owner() const
{
    Windows::UI::Composition::Interactions::IInteractionTrackerOwner value;
    check_hresult(WINRT_SHIM(IInteractionTracker)->get_Owner(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Numerics::float3 impl_IInteractionTracker<D>::Position() const
{
    Windows::Foundation::Numerics::float3 value {};
    check_hresult(WINRT_SHIM(IInteractionTracker)->get_Position(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::Numerics::float3> impl_IInteractionTracker<D>::PositionInertiaDecayRate() const
{
    Windows::Foundation::IReference<Windows::Foundation::Numerics::float3> value;
    check_hresult(WINRT_SHIM(IInteractionTracker)->get_PositionInertiaDecayRate(put_abi(value)));
    return value;
}

template <typename D> void impl_IInteractionTracker<D>::PositionInertiaDecayRate(const optional<Windows::Foundation::Numerics::float3> & value) const
{
    check_hresult(WINRT_SHIM(IInteractionTracker)->put_PositionInertiaDecayRate(get_abi(value)));
}

template <typename D> Windows::Foundation::Numerics::float3 impl_IInteractionTracker<D>::PositionVelocityInPixelsPerSecond() const
{
    Windows::Foundation::Numerics::float3 value {};
    check_hresult(WINRT_SHIM(IInteractionTracker)->get_PositionVelocityInPixelsPerSecond(put_abi(value)));
    return value;
}

template <typename D> float impl_IInteractionTracker<D>::Scale() const
{
    float value {};
    check_hresult(WINRT_SHIM(IInteractionTracker)->get_Scale(&value));
    return value;
}

template <typename D> Windows::Foundation::IReference<float> impl_IInteractionTracker<D>::ScaleInertiaDecayRate() const
{
    Windows::Foundation::IReference<float> value;
    check_hresult(WINRT_SHIM(IInteractionTracker)->get_ScaleInertiaDecayRate(put_abi(value)));
    return value;
}

template <typename D> void impl_IInteractionTracker<D>::ScaleInertiaDecayRate(const optional<float> & value) const
{
    check_hresult(WINRT_SHIM(IInteractionTracker)->put_ScaleInertiaDecayRate(get_abi(value)));
}

template <typename D> float impl_IInteractionTracker<D>::ScaleVelocityInPercentPerSecond() const
{
    float value {};
    check_hresult(WINRT_SHIM(IInteractionTracker)->get_ScaleVelocityInPercentPerSecond(&value));
    return value;
}

template <typename D> void impl_IInteractionTracker<D>::AdjustPositionXIfGreaterThanThreshold(float adjustment, float positionThreshold) const
{
    check_hresult(WINRT_SHIM(IInteractionTracker)->abi_AdjustPositionXIfGreaterThanThreshold(adjustment, positionThreshold));
}

template <typename D> void impl_IInteractionTracker<D>::AdjustPositionYIfGreaterThanThreshold(float adjustment, float positionThreshold) const
{
    check_hresult(WINRT_SHIM(IInteractionTracker)->abi_AdjustPositionYIfGreaterThanThreshold(adjustment, positionThreshold));
}

template <typename D> void impl_IInteractionTracker<D>::ConfigurePositionXInertiaModifiers(iterable<Windows::UI::Composition::Interactions::InteractionTrackerInertiaModifier> modifiers) const
{
    check_hresult(WINRT_SHIM(IInteractionTracker)->abi_ConfigurePositionXInertiaModifiers(get_abi(modifiers)));
}

template <typename D> void impl_IInteractionTracker<D>::ConfigurePositionYInertiaModifiers(iterable<Windows::UI::Composition::Interactions::InteractionTrackerInertiaModifier> modifiers) const
{
    check_hresult(WINRT_SHIM(IInteractionTracker)->abi_ConfigurePositionYInertiaModifiers(get_abi(modifiers)));
}

template <typename D> void impl_IInteractionTracker<D>::ConfigureScaleInertiaModifiers(iterable<Windows::UI::Composition::Interactions::InteractionTrackerInertiaModifier> modifiers) const
{
    check_hresult(WINRT_SHIM(IInteractionTracker)->abi_ConfigureScaleInertiaModifiers(get_abi(modifiers)));
}

template <typename D> int32_t impl_IInteractionTracker<D>::TryUpdatePosition(const Windows::Foundation::Numerics::float3 & value) const
{
    int32_t requestId {};
    check_hresult(WINRT_SHIM(IInteractionTracker)->abi_TryUpdatePosition(get_abi(value), &requestId));
    return requestId;
}

template <typename D> int32_t impl_IInteractionTracker<D>::TryUpdatePositionBy(const Windows::Foundation::Numerics::float3 & amount) const
{
    int32_t requestId {};
    check_hresult(WINRT_SHIM(IInteractionTracker)->abi_TryUpdatePositionBy(get_abi(amount), &requestId));
    return requestId;
}

template <typename D> int32_t impl_IInteractionTracker<D>::TryUpdatePositionWithAnimation(const Windows::UI::Composition::CompositionAnimation & animation) const
{
    int32_t requestId {};
    check_hresult(WINRT_SHIM(IInteractionTracker)->abi_TryUpdatePositionWithAnimation(get_abi(animation), &requestId));
    return requestId;
}

template <typename D> int32_t impl_IInteractionTracker<D>::TryUpdatePositionWithAdditionalVelocity(const Windows::Foundation::Numerics::float3 & velocityInPixelsPerSecond) const
{
    int32_t requestId {};
    check_hresult(WINRT_SHIM(IInteractionTracker)->abi_TryUpdatePositionWithAdditionalVelocity(get_abi(velocityInPixelsPerSecond), &requestId));
    return requestId;
}

template <typename D> int32_t impl_IInteractionTracker<D>::TryUpdateScale(float value, const Windows::Foundation::Numerics::float3 & centerPoint) const
{
    int32_t requestId {};
    check_hresult(WINRT_SHIM(IInteractionTracker)->abi_TryUpdateScale(value, get_abi(centerPoint), &requestId));
    return requestId;
}

template <typename D> int32_t impl_IInteractionTracker<D>::TryUpdateScaleWithAnimation(const Windows::UI::Composition::CompositionAnimation & animation, const Windows::Foundation::Numerics::float3 & centerPoint) const
{
    int32_t requestId {};
    check_hresult(WINRT_SHIM(IInteractionTracker)->abi_TryUpdateScaleWithAnimation(get_abi(animation), get_abi(centerPoint), &requestId));
    return requestId;
}

template <typename D> int32_t impl_IInteractionTracker<D>::TryUpdateScaleWithAdditionalVelocity(float velocityInPercentPerSecond, const Windows::Foundation::Numerics::float3 & centerPoint) const
{
    int32_t requestId {};
    check_hresult(WINRT_SHIM(IInteractionTracker)->abi_TryUpdateScaleWithAdditionalVelocity(velocityInPercentPerSecond, get_abi(centerPoint), &requestId));
    return requestId;
}

template <typename D> int32_t impl_IInteractionTrackerCustomAnimationStateEnteredArgs<D>::RequestId() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IInteractionTrackerCustomAnimationStateEnteredArgs)->get_RequestId(&value));
    return value;
}

template <typename D> int32_t impl_IInteractionTrackerIdleStateEnteredArgs<D>::RequestId() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IInteractionTrackerIdleStateEnteredArgs)->get_RequestId(&value));
    return value;
}

template <typename D> int32_t impl_IInteractionTrackerInteractingStateEnteredArgs<D>::RequestId() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IInteractionTrackerInteractingStateEnteredArgs)->get_RequestId(&value));
    return value;
}

template <typename D> Windows::UI::Composition::Interactions::InteractionTrackerInertiaRestingValue impl_IInteractionTrackerInertiaRestingValueStatics<D>::Create(const Windows::UI::Composition::Compositor & compositor) const
{
    Windows::UI::Composition::Interactions::InteractionTrackerInertiaRestingValue result { nullptr };
    check_hresult(WINRT_SHIM(IInteractionTrackerInertiaRestingValueStatics)->abi_Create(get_abi(compositor), put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::ExpressionAnimation impl_IInteractionTrackerInertiaRestingValue<D>::Condition() const
{
    Windows::UI::Composition::ExpressionAnimation value { nullptr };
    check_hresult(WINRT_SHIM(IInteractionTrackerInertiaRestingValue)->get_Condition(put_abi(value)));
    return value;
}

template <typename D> void impl_IInteractionTrackerInertiaRestingValue<D>::Condition(const Windows::UI::Composition::ExpressionAnimation & value) const
{
    check_hresult(WINRT_SHIM(IInteractionTrackerInertiaRestingValue)->put_Condition(get_abi(value)));
}

template <typename D> Windows::UI::Composition::ExpressionAnimation impl_IInteractionTrackerInertiaRestingValue<D>::RestingValue() const
{
    Windows::UI::Composition::ExpressionAnimation value { nullptr };
    check_hresult(WINRT_SHIM(IInteractionTrackerInertiaRestingValue)->get_RestingValue(put_abi(value)));
    return value;
}

template <typename D> void impl_IInteractionTrackerInertiaRestingValue<D>::RestingValue(const Windows::UI::Composition::ExpressionAnimation & value) const
{
    check_hresult(WINRT_SHIM(IInteractionTrackerInertiaRestingValue)->put_RestingValue(get_abi(value)));
}

template <typename D> Windows::UI::Composition::Interactions::InteractionTrackerInertiaMotion impl_IInteractionTrackerInertiaMotionStatics<D>::Create(const Windows::UI::Composition::Compositor & compositor) const
{
    Windows::UI::Composition::Interactions::InteractionTrackerInertiaMotion result { nullptr };
    check_hresult(WINRT_SHIM(IInteractionTrackerInertiaMotionStatics)->abi_Create(get_abi(compositor), put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::ExpressionAnimation impl_IInteractionTrackerInertiaMotion<D>::Condition() const
{
    Windows::UI::Composition::ExpressionAnimation value { nullptr };
    check_hresult(WINRT_SHIM(IInteractionTrackerInertiaMotion)->get_Condition(put_abi(value)));
    return value;
}

template <typename D> void impl_IInteractionTrackerInertiaMotion<D>::Condition(const Windows::UI::Composition::ExpressionAnimation & value) const
{
    check_hresult(WINRT_SHIM(IInteractionTrackerInertiaMotion)->put_Condition(get_abi(value)));
}

template <typename D> Windows::UI::Composition::ExpressionAnimation impl_IInteractionTrackerInertiaMotion<D>::Motion() const
{
    Windows::UI::Composition::ExpressionAnimation value { nullptr };
    check_hresult(WINRT_SHIM(IInteractionTrackerInertiaMotion)->get_Motion(put_abi(value)));
    return value;
}

template <typename D> void impl_IInteractionTrackerInertiaMotion<D>::Motion(const Windows::UI::Composition::ExpressionAnimation & value) const
{
    check_hresult(WINRT_SHIM(IInteractionTrackerInertiaMotion)->put_Motion(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::Numerics::float3> impl_IInteractionTrackerInertiaStateEnteredArgs<D>::ModifiedRestingPosition() const
{
    Windows::Foundation::IReference<Windows::Foundation::Numerics::float3> value;
    check_hresult(WINRT_SHIM(IInteractionTrackerInertiaStateEnteredArgs)->get_ModifiedRestingPosition(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<float> impl_IInteractionTrackerInertiaStateEnteredArgs<D>::ModifiedRestingScale() const
{
    Windows::Foundation::IReference<float> value;
    check_hresult(WINRT_SHIM(IInteractionTrackerInertiaStateEnteredArgs)->get_ModifiedRestingScale(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Numerics::float3 impl_IInteractionTrackerInertiaStateEnteredArgs<D>::NaturalRestingPosition() const
{
    Windows::Foundation::Numerics::float3 value {};
    check_hresult(WINRT_SHIM(IInteractionTrackerInertiaStateEnteredArgs)->get_NaturalRestingPosition(put_abi(value)));
    return value;
}

template <typename D> float impl_IInteractionTrackerInertiaStateEnteredArgs<D>::NaturalRestingScale() const
{
    float value {};
    check_hresult(WINRT_SHIM(IInteractionTrackerInertiaStateEnteredArgs)->get_NaturalRestingScale(&value));
    return value;
}

template <typename D> Windows::Foundation::Numerics::float3 impl_IInteractionTrackerInertiaStateEnteredArgs<D>::PositionVelocityInPixelsPerSecond() const
{
    Windows::Foundation::Numerics::float3 value {};
    check_hresult(WINRT_SHIM(IInteractionTrackerInertiaStateEnteredArgs)->get_PositionVelocityInPixelsPerSecond(put_abi(value)));
    return value;
}

template <typename D> int32_t impl_IInteractionTrackerInertiaStateEnteredArgs<D>::RequestId() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IInteractionTrackerInertiaStateEnteredArgs)->get_RequestId(&value));
    return value;
}

template <typename D> float impl_IInteractionTrackerInertiaStateEnteredArgs<D>::ScaleVelocityInPercentPerSecond() const
{
    float value {};
    check_hresult(WINRT_SHIM(IInteractionTrackerInertiaStateEnteredArgs)->get_ScaleVelocityInPercentPerSecond(&value));
    return value;
}

template <typename D> int32_t impl_IInteractionTrackerRequestIgnoredArgs<D>::RequestId() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IInteractionTrackerRequestIgnoredArgs)->get_RequestId(&value));
    return value;
}

template <typename D> Windows::Foundation::Numerics::float3 impl_IInteractionTrackerValuesChangedArgs<D>::Position() const
{
    Windows::Foundation::Numerics::float3 value {};
    check_hresult(WINRT_SHIM(IInteractionTrackerValuesChangedArgs)->get_Position(put_abi(value)));
    return value;
}

template <typename D> int32_t impl_IInteractionTrackerValuesChangedArgs<D>::RequestId() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IInteractionTrackerValuesChangedArgs)->get_RequestId(&value));
    return value;
}

template <typename D> float impl_IInteractionTrackerValuesChangedArgs<D>::Scale() const
{
    float value {};
    check_hresult(WINRT_SHIM(IInteractionTrackerValuesChangedArgs)->get_Scale(&value));
    return value;
}

template <typename D> Windows::UI::Composition::Interactions::VisualInteractionSource impl_IVisualInteractionSourceStatics<D>::Create(const Windows::UI::Composition::Visual & source) const
{
    Windows::UI::Composition::Interactions::VisualInteractionSource result { nullptr };
    check_hresult(WINRT_SHIM(IVisualInteractionSourceStatics)->abi_Create(get_abi(source), put_abi(result)));
    return result;
}

template <typename D> bool impl_IVisualInteractionSource<D>::IsPositionXRailsEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IVisualInteractionSource)->get_IsPositionXRailsEnabled(&value));
    return value;
}

template <typename D> void impl_IVisualInteractionSource<D>::IsPositionXRailsEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IVisualInteractionSource)->put_IsPositionXRailsEnabled(value));
}

template <typename D> bool impl_IVisualInteractionSource<D>::IsPositionYRailsEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IVisualInteractionSource)->get_IsPositionYRailsEnabled(&value));
    return value;
}

template <typename D> void impl_IVisualInteractionSource<D>::IsPositionYRailsEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IVisualInteractionSource)->put_IsPositionYRailsEnabled(value));
}

template <typename D> Windows::UI::Composition::Interactions::VisualInteractionSourceRedirectionMode impl_IVisualInteractionSource<D>::ManipulationRedirectionMode() const
{
    Windows::UI::Composition::Interactions::VisualInteractionSourceRedirectionMode value {};
    check_hresult(WINRT_SHIM(IVisualInteractionSource)->get_ManipulationRedirectionMode(&value));
    return value;
}

template <typename D> void impl_IVisualInteractionSource<D>::ManipulationRedirectionMode(Windows::UI::Composition::Interactions::VisualInteractionSourceRedirectionMode value) const
{
    check_hresult(WINRT_SHIM(IVisualInteractionSource)->put_ManipulationRedirectionMode(value));
}

template <typename D> Windows::UI::Composition::Interactions::InteractionChainingMode impl_IVisualInteractionSource<D>::PositionXChainingMode() const
{
    Windows::UI::Composition::Interactions::InteractionChainingMode value {};
    check_hresult(WINRT_SHIM(IVisualInteractionSource)->get_PositionXChainingMode(&value));
    return value;
}

template <typename D> void impl_IVisualInteractionSource<D>::PositionXChainingMode(Windows::UI::Composition::Interactions::InteractionChainingMode value) const
{
    check_hresult(WINRT_SHIM(IVisualInteractionSource)->put_PositionXChainingMode(value));
}

template <typename D> Windows::UI::Composition::Interactions::InteractionSourceMode impl_IVisualInteractionSource<D>::PositionXSourceMode() const
{
    Windows::UI::Composition::Interactions::InteractionSourceMode value {};
    check_hresult(WINRT_SHIM(IVisualInteractionSource)->get_PositionXSourceMode(&value));
    return value;
}

template <typename D> void impl_IVisualInteractionSource<D>::PositionXSourceMode(Windows::UI::Composition::Interactions::InteractionSourceMode value) const
{
    check_hresult(WINRT_SHIM(IVisualInteractionSource)->put_PositionXSourceMode(value));
}

template <typename D> Windows::UI::Composition::Interactions::InteractionChainingMode impl_IVisualInteractionSource<D>::PositionYChainingMode() const
{
    Windows::UI::Composition::Interactions::InteractionChainingMode value {};
    check_hresult(WINRT_SHIM(IVisualInteractionSource)->get_PositionYChainingMode(&value));
    return value;
}

template <typename D> void impl_IVisualInteractionSource<D>::PositionYChainingMode(Windows::UI::Composition::Interactions::InteractionChainingMode value) const
{
    check_hresult(WINRT_SHIM(IVisualInteractionSource)->put_PositionYChainingMode(value));
}

template <typename D> Windows::UI::Composition::Interactions::InteractionSourceMode impl_IVisualInteractionSource<D>::PositionYSourceMode() const
{
    Windows::UI::Composition::Interactions::InteractionSourceMode value {};
    check_hresult(WINRT_SHIM(IVisualInteractionSource)->get_PositionYSourceMode(&value));
    return value;
}

template <typename D> void impl_IVisualInteractionSource<D>::PositionYSourceMode(Windows::UI::Composition::Interactions::InteractionSourceMode value) const
{
    check_hresult(WINRT_SHIM(IVisualInteractionSource)->put_PositionYSourceMode(value));
}

template <typename D> Windows::UI::Composition::Interactions::InteractionChainingMode impl_IVisualInteractionSource<D>::ScaleChainingMode() const
{
    Windows::UI::Composition::Interactions::InteractionChainingMode value {};
    check_hresult(WINRT_SHIM(IVisualInteractionSource)->get_ScaleChainingMode(&value));
    return value;
}

template <typename D> void impl_IVisualInteractionSource<D>::ScaleChainingMode(Windows::UI::Composition::Interactions::InteractionChainingMode value) const
{
    check_hresult(WINRT_SHIM(IVisualInteractionSource)->put_ScaleChainingMode(value));
}

template <typename D> Windows::UI::Composition::Interactions::InteractionSourceMode impl_IVisualInteractionSource<D>::ScaleSourceMode() const
{
    Windows::UI::Composition::Interactions::InteractionSourceMode value {};
    check_hresult(WINRT_SHIM(IVisualInteractionSource)->get_ScaleSourceMode(&value));
    return value;
}

template <typename D> void impl_IVisualInteractionSource<D>::ScaleSourceMode(Windows::UI::Composition::Interactions::InteractionSourceMode value) const
{
    check_hresult(WINRT_SHIM(IVisualInteractionSource)->put_ScaleSourceMode(value));
}

template <typename D> Windows::UI::Composition::Visual impl_IVisualInteractionSource<D>::Source() const
{
    Windows::UI::Composition::Visual value { nullptr };
    check_hresult(WINRT_SHIM(IVisualInteractionSource)->get_Source(put_abi(value)));
    return value;
}

template <typename D> void impl_IVisualInteractionSource<D>::TryRedirectForManipulation(const Windows::UI::Input::PointerPoint & pointerPoint) const
{
    check_hresult(WINRT_SHIM(IVisualInteractionSource)->abi_TryRedirectForManipulation(get_abi(pointerPoint)));
}

inline Windows::UI::Composition::Interactions::InteractionTracker InteractionTracker::Create(const Windows::UI::Composition::Compositor & compositor)
{
    return get_activation_factory<InteractionTracker, IInteractionTrackerStatics>().Create(compositor);
}

inline Windows::UI::Composition::Interactions::InteractionTracker InteractionTracker::CreateWithOwner(const Windows::UI::Composition::Compositor & compositor, const Windows::UI::Composition::Interactions::IInteractionTrackerOwner & owner)
{
    return get_activation_factory<InteractionTracker, IInteractionTrackerStatics>().CreateWithOwner(compositor, owner);
}

inline Windows::UI::Composition::Interactions::InteractionTrackerInertiaMotion InteractionTrackerInertiaMotion::Create(const Windows::UI::Composition::Compositor & compositor)
{
    return get_activation_factory<InteractionTrackerInertiaMotion, IInteractionTrackerInertiaMotionStatics>().Create(compositor);
}

inline Windows::UI::Composition::Interactions::InteractionTrackerInertiaRestingValue InteractionTrackerInertiaRestingValue::Create(const Windows::UI::Composition::Compositor & compositor)
{
    return get_activation_factory<InteractionTrackerInertiaRestingValue, IInteractionTrackerInertiaRestingValueStatics>().Create(compositor);
}

inline Windows::UI::Composition::Interactions::VisualInteractionSource VisualInteractionSource::Create(const Windows::UI::Composition::Visual & source)
{
    return get_activation_factory<VisualInteractionSource, IVisualInteractionSourceStatics>().Create(source);
}

}

}
#pragma warning(pop)
