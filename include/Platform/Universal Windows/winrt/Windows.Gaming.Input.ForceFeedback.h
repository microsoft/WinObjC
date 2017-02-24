// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Gaming.Input.ForceFeedback.3.h"
#include "Windows.Gaming.Input.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Gaming::Input::ForceFeedback::IConditionForceEffect> : produce_base<D, Windows::Gaming::Input::ForceFeedback::IConditionForceEffect>
{
    HRESULT __stdcall get_Kind(Windows::Gaming::Input::ForceFeedback::ConditionForceEffectKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Kind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetParameters(impl::abi_arg_in<Windows::Foundation::Numerics::float3> direction, float positiveCoefficient, float negativeCoefficient, float maxPositiveMagnitude, float maxNegativeMagnitude, float deadZone, float bias) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetParameters(*reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&direction), positiveCoefficient, negativeCoefficient, maxPositiveMagnitude, maxNegativeMagnitude, deadZone, bias);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Gaming::Input::ForceFeedback::IConditionForceEffectFactory> : produce_base<D, Windows::Gaming::Input::ForceFeedback::IConditionForceEffectFactory>
{
    HRESULT __stdcall abi_CreateInstance(Windows::Gaming::Input::ForceFeedback::ConditionForceEffectKind effectKind, impl::abi_arg_out<Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateInstance(effectKind));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Gaming::Input::ForceFeedback::IConstantForceEffect> : produce_base<D, Windows::Gaming::Input::ForceFeedback::IConstantForceEffect>
{
    HRESULT __stdcall abi_SetParameters(impl::abi_arg_in<Windows::Foundation::Numerics::float3> vector, impl::abi_arg_in<Windows::Foundation::TimeSpan> duration) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetParameters(*reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&vector), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&duration));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetParametersWithEnvelope(impl::abi_arg_in<Windows::Foundation::Numerics::float3> vector, float attackGain, float sustainGain, float releaseGain, impl::abi_arg_in<Windows::Foundation::TimeSpan> startDelay, impl::abi_arg_in<Windows::Foundation::TimeSpan> attackDuration, impl::abi_arg_in<Windows::Foundation::TimeSpan> sustainDuration, impl::abi_arg_in<Windows::Foundation::TimeSpan> releaseDuration, uint32_t repeatCount) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetParametersWithEnvelope(*reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&vector), attackGain, sustainGain, releaseGain, *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&startDelay), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&attackDuration), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&sustainDuration), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&releaseDuration), repeatCount);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect> : produce_base<D, Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect>
{
    HRESULT __stdcall get_Gain(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Gain());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Gain(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Gain(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_State(Windows::Gaming::Input::ForceFeedback::ForceFeedbackEffectState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().State());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Start() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Stop() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stop();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Gaming::Input::ForceFeedback::IForceFeedbackMotor> : produce_base<D, Windows::Gaming::Input::ForceFeedback::IForceFeedbackMotor>
{
    HRESULT __stdcall get_AreEffectsPaused(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AreEffectsPaused());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MasterGain(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MasterGain());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MasterGain(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MasterGain(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedAxes(Windows::Gaming::Input::ForceFeedback::ForceFeedbackEffectAxes * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportedAxes());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LoadEffectAsync(impl::abi_arg_in<Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect> effect, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Gaming::Input::ForceFeedback::ForceFeedbackLoadEffectResult>> asyncOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOperation = detach_abi(this->shim().LoadEffectAsync(*reinterpret_cast<const Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect *>(&effect)));
            return S_OK;
        }
        catch (...)
        {
            *asyncOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PauseAllEffects() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PauseAllEffects();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ResumeAllEffects() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ResumeAllEffects();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StopAllEffects() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StopAllEffects();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryDisableAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> asyncOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOperation = detach_abi(this->shim().TryDisableAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryEnableAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> asyncOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOperation = detach_abi(this->shim().TryEnableAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryResetAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> asyncOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOperation = detach_abi(this->shim().TryResetAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryUnloadEffectAsync(impl::abi_arg_in<Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect> effect, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> asyncOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOperation = detach_abi(this->shim().TryUnloadEffectAsync(*reinterpret_cast<const Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect *>(&effect)));
            return S_OK;
        }
        catch (...)
        {
            *asyncOperation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Gaming::Input::ForceFeedback::IPeriodicForceEffect> : produce_base<D, Windows::Gaming::Input::ForceFeedback::IPeriodicForceEffect>
{
    HRESULT __stdcall get_Kind(Windows::Gaming::Input::ForceFeedback::PeriodicForceEffectKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Kind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetParameters(impl::abi_arg_in<Windows::Foundation::Numerics::float3> vector, float frequency, float phase, float bias, impl::abi_arg_in<Windows::Foundation::TimeSpan> duration) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetParameters(*reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&vector), frequency, phase, bias, *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&duration));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetParametersWithEnvelope(impl::abi_arg_in<Windows::Foundation::Numerics::float3> vector, float frequency, float phase, float bias, float attackGain, float sustainGain, float releaseGain, impl::abi_arg_in<Windows::Foundation::TimeSpan> startDelay, impl::abi_arg_in<Windows::Foundation::TimeSpan> attackDuration, impl::abi_arg_in<Windows::Foundation::TimeSpan> sustainDuration, impl::abi_arg_in<Windows::Foundation::TimeSpan> releaseDuration, uint32_t repeatCount) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetParametersWithEnvelope(*reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&vector), frequency, phase, bias, attackGain, sustainGain, releaseGain, *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&startDelay), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&attackDuration), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&sustainDuration), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&releaseDuration), repeatCount);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Gaming::Input::ForceFeedback::IPeriodicForceEffectFactory> : produce_base<D, Windows::Gaming::Input::ForceFeedback::IPeriodicForceEffectFactory>
{
    HRESULT __stdcall abi_CreateInstance(Windows::Gaming::Input::ForceFeedback::PeriodicForceEffectKind effectKind, impl::abi_arg_out<Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateInstance(effectKind));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Gaming::Input::ForceFeedback::IRampForceEffect> : produce_base<D, Windows::Gaming::Input::ForceFeedback::IRampForceEffect>
{
    HRESULT __stdcall abi_SetParameters(impl::abi_arg_in<Windows::Foundation::Numerics::float3> startVector, impl::abi_arg_in<Windows::Foundation::Numerics::float3> endVector, impl::abi_arg_in<Windows::Foundation::TimeSpan> duration) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetParameters(*reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&startVector), *reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&endVector), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&duration));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetParametersWithEnvelope(impl::abi_arg_in<Windows::Foundation::Numerics::float3> startVector, impl::abi_arg_in<Windows::Foundation::Numerics::float3> endVector, float attackGain, float sustainGain, float releaseGain, impl::abi_arg_in<Windows::Foundation::TimeSpan> startDelay, impl::abi_arg_in<Windows::Foundation::TimeSpan> attackDuration, impl::abi_arg_in<Windows::Foundation::TimeSpan> sustainDuration, impl::abi_arg_in<Windows::Foundation::TimeSpan> releaseDuration, uint32_t repeatCount) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetParametersWithEnvelope(*reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&startVector), *reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&endVector), attackGain, sustainGain, releaseGain, *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&startDelay), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&attackDuration), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&sustainDuration), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&releaseDuration), repeatCount);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Gaming::Input::ForceFeedback {

template <typename D> double impl_IForceFeedbackEffect<D>::Gain() const
{
    double value {};
    check_hresult(WINRT_SHIM(IForceFeedbackEffect)->get_Gain(&value));
    return value;
}

template <typename D> void impl_IForceFeedbackEffect<D>::Gain(double value) const
{
    check_hresult(WINRT_SHIM(IForceFeedbackEffect)->put_Gain(value));
}

template <typename D> Windows::Gaming::Input::ForceFeedback::ForceFeedbackEffectState impl_IForceFeedbackEffect<D>::State() const
{
    Windows::Gaming::Input::ForceFeedback::ForceFeedbackEffectState value {};
    check_hresult(WINRT_SHIM(IForceFeedbackEffect)->get_State(&value));
    return value;
}

template <typename D> void impl_IForceFeedbackEffect<D>::Start() const
{
    check_hresult(WINRT_SHIM(IForceFeedbackEffect)->abi_Start());
}

template <typename D> void impl_IForceFeedbackEffect<D>::Stop() const
{
    check_hresult(WINRT_SHIM(IForceFeedbackEffect)->abi_Stop());
}

template <typename D> Windows::Gaming::Input::ForceFeedback::ConditionForceEffectKind impl_IConditionForceEffect<D>::Kind() const
{
    Windows::Gaming::Input::ForceFeedback::ConditionForceEffectKind value {};
    check_hresult(WINRT_SHIM(IConditionForceEffect)->get_Kind(&value));
    return value;
}

template <typename D> void impl_IConditionForceEffect<D>::SetParameters(const Windows::Foundation::Numerics::float3 & direction, float positiveCoefficient, float negativeCoefficient, float maxPositiveMagnitude, float maxNegativeMagnitude, float deadZone, float bias) const
{
    check_hresult(WINRT_SHIM(IConditionForceEffect)->abi_SetParameters(get_abi(direction), positiveCoefficient, negativeCoefficient, maxPositiveMagnitude, maxNegativeMagnitude, deadZone, bias));
}

template <typename D> Windows::Gaming::Input::ForceFeedback::ConditionForceEffect impl_IConditionForceEffectFactory<D>::CreateInstance(Windows::Gaming::Input::ForceFeedback::ConditionForceEffectKind effectKind) const
{
    Windows::Gaming::Input::ForceFeedback::ConditionForceEffect value { nullptr };
    check_hresult(WINRT_SHIM(IConditionForceEffectFactory)->abi_CreateInstance(effectKind, put_abi(value)));
    return value;
}

template <typename D> void impl_IConstantForceEffect<D>::SetParameters(const Windows::Foundation::Numerics::float3 & vector, const Windows::Foundation::TimeSpan & duration) const
{
    check_hresult(WINRT_SHIM(IConstantForceEffect)->abi_SetParameters(get_abi(vector), get_abi(duration)));
}

template <typename D> void impl_IConstantForceEffect<D>::SetParametersWithEnvelope(const Windows::Foundation::Numerics::float3 & vector, float attackGain, float sustainGain, float releaseGain, const Windows::Foundation::TimeSpan & startDelay, const Windows::Foundation::TimeSpan & attackDuration, const Windows::Foundation::TimeSpan & sustainDuration, const Windows::Foundation::TimeSpan & releaseDuration, uint32_t repeatCount) const
{
    check_hresult(WINRT_SHIM(IConstantForceEffect)->abi_SetParametersWithEnvelope(get_abi(vector), attackGain, sustainGain, releaseGain, get_abi(startDelay), get_abi(attackDuration), get_abi(sustainDuration), get_abi(releaseDuration), repeatCount));
}

template <typename D> Windows::Gaming::Input::ForceFeedback::PeriodicForceEffectKind impl_IPeriodicForceEffect<D>::Kind() const
{
    Windows::Gaming::Input::ForceFeedback::PeriodicForceEffectKind value {};
    check_hresult(WINRT_SHIM(IPeriodicForceEffect)->get_Kind(&value));
    return value;
}

template <typename D> void impl_IPeriodicForceEffect<D>::SetParameters(const Windows::Foundation::Numerics::float3 & vector, float frequency, float phase, float bias, const Windows::Foundation::TimeSpan & duration) const
{
    check_hresult(WINRT_SHIM(IPeriodicForceEffect)->abi_SetParameters(get_abi(vector), frequency, phase, bias, get_abi(duration)));
}

template <typename D> void impl_IPeriodicForceEffect<D>::SetParametersWithEnvelope(const Windows::Foundation::Numerics::float3 & vector, float frequency, float phase, float bias, float attackGain, float sustainGain, float releaseGain, const Windows::Foundation::TimeSpan & startDelay, const Windows::Foundation::TimeSpan & attackDuration, const Windows::Foundation::TimeSpan & sustainDuration, const Windows::Foundation::TimeSpan & releaseDuration, uint32_t repeatCount) const
{
    check_hresult(WINRT_SHIM(IPeriodicForceEffect)->abi_SetParametersWithEnvelope(get_abi(vector), frequency, phase, bias, attackGain, sustainGain, releaseGain, get_abi(startDelay), get_abi(attackDuration), get_abi(sustainDuration), get_abi(releaseDuration), repeatCount));
}

template <typename D> Windows::Gaming::Input::ForceFeedback::PeriodicForceEffect impl_IPeriodicForceEffectFactory<D>::CreateInstance(Windows::Gaming::Input::ForceFeedback::PeriodicForceEffectKind effectKind) const
{
    Windows::Gaming::Input::ForceFeedback::PeriodicForceEffect value { nullptr };
    check_hresult(WINRT_SHIM(IPeriodicForceEffectFactory)->abi_CreateInstance(effectKind, put_abi(value)));
    return value;
}

template <typename D> void impl_IRampForceEffect<D>::SetParameters(const Windows::Foundation::Numerics::float3 & startVector, const Windows::Foundation::Numerics::float3 & endVector, const Windows::Foundation::TimeSpan & duration) const
{
    check_hresult(WINRT_SHIM(IRampForceEffect)->abi_SetParameters(get_abi(startVector), get_abi(endVector), get_abi(duration)));
}

template <typename D> void impl_IRampForceEffect<D>::SetParametersWithEnvelope(const Windows::Foundation::Numerics::float3 & startVector, const Windows::Foundation::Numerics::float3 & endVector, float attackGain, float sustainGain, float releaseGain, const Windows::Foundation::TimeSpan & startDelay, const Windows::Foundation::TimeSpan & attackDuration, const Windows::Foundation::TimeSpan & sustainDuration, const Windows::Foundation::TimeSpan & releaseDuration, uint32_t repeatCount) const
{
    check_hresult(WINRT_SHIM(IRampForceEffect)->abi_SetParametersWithEnvelope(get_abi(startVector), get_abi(endVector), attackGain, sustainGain, releaseGain, get_abi(startDelay), get_abi(attackDuration), get_abi(sustainDuration), get_abi(releaseDuration), repeatCount));
}

template <typename D> bool impl_IForceFeedbackMotor<D>::AreEffectsPaused() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IForceFeedbackMotor)->get_AreEffectsPaused(&value));
    return value;
}

template <typename D> double impl_IForceFeedbackMotor<D>::MasterGain() const
{
    double value {};
    check_hresult(WINRT_SHIM(IForceFeedbackMotor)->get_MasterGain(&value));
    return value;
}

template <typename D> void impl_IForceFeedbackMotor<D>::MasterGain(double value) const
{
    check_hresult(WINRT_SHIM(IForceFeedbackMotor)->put_MasterGain(value));
}

template <typename D> bool impl_IForceFeedbackMotor<D>::IsEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IForceFeedbackMotor)->get_IsEnabled(&value));
    return value;
}

template <typename D> Windows::Gaming::Input::ForceFeedback::ForceFeedbackEffectAxes impl_IForceFeedbackMotor<D>::SupportedAxes() const
{
    Windows::Gaming::Input::ForceFeedback::ForceFeedbackEffectAxes value {};
    check_hresult(WINRT_SHIM(IForceFeedbackMotor)->get_SupportedAxes(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Gaming::Input::ForceFeedback::ForceFeedbackLoadEffectResult> impl_IForceFeedbackMotor<D>::LoadEffectAsync(const Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect & effect) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Gaming::Input::ForceFeedback::ForceFeedbackLoadEffectResult> asyncOperation;
    check_hresult(WINRT_SHIM(IForceFeedbackMotor)->abi_LoadEffectAsync(get_abi(effect), put_abi(asyncOperation)));
    return asyncOperation;
}

template <typename D> void impl_IForceFeedbackMotor<D>::PauseAllEffects() const
{
    check_hresult(WINRT_SHIM(IForceFeedbackMotor)->abi_PauseAllEffects());
}

template <typename D> void impl_IForceFeedbackMotor<D>::ResumeAllEffects() const
{
    check_hresult(WINRT_SHIM(IForceFeedbackMotor)->abi_ResumeAllEffects());
}

template <typename D> void impl_IForceFeedbackMotor<D>::StopAllEffects() const
{
    check_hresult(WINRT_SHIM(IForceFeedbackMotor)->abi_StopAllEffects());
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IForceFeedbackMotor<D>::TryDisableAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> asyncOperation;
    check_hresult(WINRT_SHIM(IForceFeedbackMotor)->abi_TryDisableAsync(put_abi(asyncOperation)));
    return asyncOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IForceFeedbackMotor<D>::TryEnableAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> asyncOperation;
    check_hresult(WINRT_SHIM(IForceFeedbackMotor)->abi_TryEnableAsync(put_abi(asyncOperation)));
    return asyncOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IForceFeedbackMotor<D>::TryResetAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> asyncOperation;
    check_hresult(WINRT_SHIM(IForceFeedbackMotor)->abi_TryResetAsync(put_abi(asyncOperation)));
    return asyncOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IForceFeedbackMotor<D>::TryUnloadEffectAsync(const Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect & effect) const
{
    Windows::Foundation::IAsyncOperation<bool> asyncOperation;
    check_hresult(WINRT_SHIM(IForceFeedbackMotor)->abi_TryUnloadEffectAsync(get_abi(effect), put_abi(asyncOperation)));
    return asyncOperation;
}

inline ConditionForceEffect::ConditionForceEffect(Windows::Gaming::Input::ForceFeedback::ConditionForceEffectKind effectKind) :
    ConditionForceEffect(get_activation_factory<ConditionForceEffect, IConditionForceEffectFactory>().CreateInstance(effectKind))
{}

inline ConstantForceEffect::ConstantForceEffect() :
    ConstantForceEffect(activate_instance<ConstantForceEffect>())
{}

inline PeriodicForceEffect::PeriodicForceEffect(Windows::Gaming::Input::ForceFeedback::PeriodicForceEffectKind effectKind) :
    PeriodicForceEffect(get_activation_factory<PeriodicForceEffect, IPeriodicForceEffectFactory>().CreateInstance(effectKind))
{}

inline RampForceEffect::RampForceEffect() :
    RampForceEffect(activate_instance<RampForceEffect>())
{}

}

}
#pragma warning(pop)
