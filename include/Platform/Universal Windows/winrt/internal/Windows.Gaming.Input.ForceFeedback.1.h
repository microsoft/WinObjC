// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Gaming.Input.ForceFeedback.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Gaming::Input::ForceFeedback {

struct __declspec(uuid("32d1ea68-3695-4e69-85c0-cd1944189140")) __declspec(novtable) IConditionForceEffect : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Kind(winrt::Windows::Gaming::Input::ForceFeedback::ConditionForceEffectKind * value) = 0;
    virtual HRESULT __stdcall abi_SetParameters(Windows::Foundation::Numerics::float3 direction, float positiveCoefficient, float negativeCoefficient, float maxPositiveMagnitude, float maxNegativeMagnitude, float deadZone, float bias) = 0;
};

struct __declspec(uuid("91a99264-1810-4eb6-a773-bfd3b8cddbab")) __declspec(novtable) IConditionForceEffectFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(winrt::Windows::Gaming::Input::ForceFeedback::ConditionForceEffectKind effectKind, Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect ** value) = 0;
};

struct __declspec(uuid("9bfa0140-f3c7-415c-b068-0f068734bce0")) __declspec(novtable) IConstantForceEffect : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SetParameters(Windows::Foundation::Numerics::float3 vector, Windows::Foundation::TimeSpan duration) = 0;
    virtual HRESULT __stdcall abi_SetParametersWithEnvelope(Windows::Foundation::Numerics::float3 vector, float attackGain, float sustainGain, float releaseGain, Windows::Foundation::TimeSpan startDelay, Windows::Foundation::TimeSpan attackDuration, Windows::Foundation::TimeSpan sustainDuration, Windows::Foundation::TimeSpan releaseDuration, uint32_t repeatCount) = 0;
};

struct __declspec(uuid("a17fba0c-2ae4-48c2-8063-eabd0777cb89")) __declspec(novtable) IForceFeedbackEffect : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Gain(double * value) = 0;
    virtual HRESULT __stdcall put_Gain(double value) = 0;
    virtual HRESULT __stdcall get_State(winrt::Windows::Gaming::Input::ForceFeedback::ForceFeedbackEffectState * value) = 0;
    virtual HRESULT __stdcall abi_Start() = 0;
    virtual HRESULT __stdcall abi_Stop() = 0;
};

struct __declspec(uuid("8d3d417c-a5ea-4516-8026-2b00f74ef6e5")) __declspec(novtable) IForceFeedbackMotor : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AreEffectsPaused(bool * value) = 0;
    virtual HRESULT __stdcall get_MasterGain(double * value) = 0;
    virtual HRESULT __stdcall put_MasterGain(double value) = 0;
    virtual HRESULT __stdcall get_IsEnabled(bool * value) = 0;
    virtual HRESULT __stdcall get_SupportedAxes(winrt::Windows::Gaming::Input::ForceFeedback::ForceFeedbackEffectAxes * value) = 0;
    virtual HRESULT __stdcall abi_LoadEffectAsync(Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect * effect, Windows::Foundation::IAsyncOperation<winrt::Windows::Gaming::Input::ForceFeedback::ForceFeedbackLoadEffectResult> ** asyncOperation) = 0;
    virtual HRESULT __stdcall abi_PauseAllEffects() = 0;
    virtual HRESULT __stdcall abi_ResumeAllEffects() = 0;
    virtual HRESULT __stdcall abi_StopAllEffects() = 0;
    virtual HRESULT __stdcall abi_TryDisableAsync(Windows::Foundation::IAsyncOperation<bool> ** asyncOperation) = 0;
    virtual HRESULT __stdcall abi_TryEnableAsync(Windows::Foundation::IAsyncOperation<bool> ** asyncOperation) = 0;
    virtual HRESULT __stdcall abi_TryResetAsync(Windows::Foundation::IAsyncOperation<bool> ** asyncOperation) = 0;
    virtual HRESULT __stdcall abi_TryUnloadEffectAsync(Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect * effect, Windows::Foundation::IAsyncOperation<bool> ** asyncOperation) = 0;
};

struct __declspec(uuid("5c5138d7-fc75-4d52-9a0a-efe4cab5fe64")) __declspec(novtable) IPeriodicForceEffect : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Kind(winrt::Windows::Gaming::Input::ForceFeedback::PeriodicForceEffectKind * value) = 0;
    virtual HRESULT __stdcall abi_SetParameters(Windows::Foundation::Numerics::float3 vector, float frequency, float phase, float bias, Windows::Foundation::TimeSpan duration) = 0;
    virtual HRESULT __stdcall abi_SetParametersWithEnvelope(Windows::Foundation::Numerics::float3 vector, float frequency, float phase, float bias, float attackGain, float sustainGain, float releaseGain, Windows::Foundation::TimeSpan startDelay, Windows::Foundation::TimeSpan attackDuration, Windows::Foundation::TimeSpan sustainDuration, Windows::Foundation::TimeSpan releaseDuration, uint32_t repeatCount) = 0;
};

struct __declspec(uuid("6f62eb1a-9851-477b-b318-35ecaa15070f")) __declspec(novtable) IPeriodicForceEffectFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(winrt::Windows::Gaming::Input::ForceFeedback::PeriodicForceEffectKind effectKind, Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect ** value) = 0;
};

struct __declspec(uuid("f1f81259-1ca6-4080-b56d-b43f3354d052")) __declspec(novtable) IRampForceEffect : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SetParameters(Windows::Foundation::Numerics::float3 startVector, Windows::Foundation::Numerics::float3 endVector, Windows::Foundation::TimeSpan duration) = 0;
    virtual HRESULT __stdcall abi_SetParametersWithEnvelope(Windows::Foundation::Numerics::float3 startVector, Windows::Foundation::Numerics::float3 endVector, float attackGain, float sustainGain, float releaseGain, Windows::Foundation::TimeSpan startDelay, Windows::Foundation::TimeSpan attackDuration, Windows::Foundation::TimeSpan sustainDuration, Windows::Foundation::TimeSpan releaseDuration, uint32_t repeatCount) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Gaming::Input::ForceFeedback::ConditionForceEffect> { using default_interface = Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect; };
template <> struct traits<Windows::Gaming::Input::ForceFeedback::ConstantForceEffect> { using default_interface = Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect; };
template <> struct traits<Windows::Gaming::Input::ForceFeedback::ForceFeedbackMotor> { using default_interface = Windows::Gaming::Input::ForceFeedback::IForceFeedbackMotor; };
template <> struct traits<Windows::Gaming::Input::ForceFeedback::PeriodicForceEffect> { using default_interface = Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect; };
template <> struct traits<Windows::Gaming::Input::ForceFeedback::RampForceEffect> { using default_interface = Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect; };

}

namespace Windows::Gaming::Input::ForceFeedback {

template <typename D>
struct WINRT_EBO impl_IConditionForceEffect
{
    Windows::Gaming::Input::ForceFeedback::ConditionForceEffectKind Kind() const;
    void SetParameters(const Windows::Foundation::Numerics::float3 & direction, float positiveCoefficient, float negativeCoefficient, float maxPositiveMagnitude, float maxNegativeMagnitude, float deadZone, float bias) const;
};

template <typename D>
struct WINRT_EBO impl_IConditionForceEffectFactory
{
    Windows::Gaming::Input::ForceFeedback::ConditionForceEffect CreateInstance(Windows::Gaming::Input::ForceFeedback::ConditionForceEffectKind effectKind) const;
};

template <typename D>
struct WINRT_EBO impl_IConstantForceEffect
{
    void SetParameters(const Windows::Foundation::Numerics::float3 & vector, const Windows::Foundation::TimeSpan & duration) const;
    void SetParametersWithEnvelope(const Windows::Foundation::Numerics::float3 & vector, float attackGain, float sustainGain, float releaseGain, const Windows::Foundation::TimeSpan & startDelay, const Windows::Foundation::TimeSpan & attackDuration, const Windows::Foundation::TimeSpan & sustainDuration, const Windows::Foundation::TimeSpan & releaseDuration, uint32_t repeatCount) const;
};

template <typename D>
struct WINRT_EBO impl_IForceFeedbackEffect
{
    double Gain() const;
    void Gain(double value) const;
    Windows::Gaming::Input::ForceFeedback::ForceFeedbackEffectState State() const;
    void Start() const;
    void Stop() const;
};

template <typename D>
struct WINRT_EBO impl_IForceFeedbackMotor
{
    bool AreEffectsPaused() const;
    double MasterGain() const;
    void MasterGain(double value) const;
    bool IsEnabled() const;
    Windows::Gaming::Input::ForceFeedback::ForceFeedbackEffectAxes SupportedAxes() const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Gaming::Input::ForceFeedback::ForceFeedbackLoadEffectResult> LoadEffectAsync(const Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect & effect) const;
    void PauseAllEffects() const;
    void ResumeAllEffects() const;
    void StopAllEffects() const;
    Windows::Foundation::IAsyncOperation<bool> TryDisableAsync() const;
    Windows::Foundation::IAsyncOperation<bool> TryEnableAsync() const;
    Windows::Foundation::IAsyncOperation<bool> TryResetAsync() const;
    Windows::Foundation::IAsyncOperation<bool> TryUnloadEffectAsync(const Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect & effect) const;
};

template <typename D>
struct WINRT_EBO impl_IPeriodicForceEffect
{
    Windows::Gaming::Input::ForceFeedback::PeriodicForceEffectKind Kind() const;
    void SetParameters(const Windows::Foundation::Numerics::float3 & vector, float frequency, float phase, float bias, const Windows::Foundation::TimeSpan & duration) const;
    void SetParametersWithEnvelope(const Windows::Foundation::Numerics::float3 & vector, float frequency, float phase, float bias, float attackGain, float sustainGain, float releaseGain, const Windows::Foundation::TimeSpan & startDelay, const Windows::Foundation::TimeSpan & attackDuration, const Windows::Foundation::TimeSpan & sustainDuration, const Windows::Foundation::TimeSpan & releaseDuration, uint32_t repeatCount) const;
};

template <typename D>
struct WINRT_EBO impl_IPeriodicForceEffectFactory
{
    Windows::Gaming::Input::ForceFeedback::PeriodicForceEffect CreateInstance(Windows::Gaming::Input::ForceFeedback::PeriodicForceEffectKind effectKind) const;
};

template <typename D>
struct WINRT_EBO impl_IRampForceEffect
{
    void SetParameters(const Windows::Foundation::Numerics::float3 & startVector, const Windows::Foundation::Numerics::float3 & endVector, const Windows::Foundation::TimeSpan & duration) const;
    void SetParametersWithEnvelope(const Windows::Foundation::Numerics::float3 & startVector, const Windows::Foundation::Numerics::float3 & endVector, float attackGain, float sustainGain, float releaseGain, const Windows::Foundation::TimeSpan & startDelay, const Windows::Foundation::TimeSpan & attackDuration, const Windows::Foundation::TimeSpan & sustainDuration, const Windows::Foundation::TimeSpan & releaseDuration, uint32_t repeatCount) const;
};

}

namespace impl {

template <> struct traits<Windows::Gaming::Input::ForceFeedback::IConditionForceEffect>
{
    using abi = ABI::Windows::Gaming::Input::ForceFeedback::IConditionForceEffect;
    template <typename D> using consume = Windows::Gaming::Input::ForceFeedback::impl_IConditionForceEffect<D>;
};

template <> struct traits<Windows::Gaming::Input::ForceFeedback::IConditionForceEffectFactory>
{
    using abi = ABI::Windows::Gaming::Input::ForceFeedback::IConditionForceEffectFactory;
    template <typename D> using consume = Windows::Gaming::Input::ForceFeedback::impl_IConditionForceEffectFactory<D>;
};

template <> struct traits<Windows::Gaming::Input::ForceFeedback::IConstantForceEffect>
{
    using abi = ABI::Windows::Gaming::Input::ForceFeedback::IConstantForceEffect;
    template <typename D> using consume = Windows::Gaming::Input::ForceFeedback::impl_IConstantForceEffect<D>;
};

template <> struct traits<Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect>
{
    using abi = ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect;
    template <typename D> using consume = Windows::Gaming::Input::ForceFeedback::impl_IForceFeedbackEffect<D>;
};

template <> struct traits<Windows::Gaming::Input::ForceFeedback::IForceFeedbackMotor>
{
    using abi = ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackMotor;
    template <typename D> using consume = Windows::Gaming::Input::ForceFeedback::impl_IForceFeedbackMotor<D>;
};

template <> struct traits<Windows::Gaming::Input::ForceFeedback::IPeriodicForceEffect>
{
    using abi = ABI::Windows::Gaming::Input::ForceFeedback::IPeriodicForceEffect;
    template <typename D> using consume = Windows::Gaming::Input::ForceFeedback::impl_IPeriodicForceEffect<D>;
};

template <> struct traits<Windows::Gaming::Input::ForceFeedback::IPeriodicForceEffectFactory>
{
    using abi = ABI::Windows::Gaming::Input::ForceFeedback::IPeriodicForceEffectFactory;
    template <typename D> using consume = Windows::Gaming::Input::ForceFeedback::impl_IPeriodicForceEffectFactory<D>;
};

template <> struct traits<Windows::Gaming::Input::ForceFeedback::IRampForceEffect>
{
    using abi = ABI::Windows::Gaming::Input::ForceFeedback::IRampForceEffect;
    template <typename D> using consume = Windows::Gaming::Input::ForceFeedback::impl_IRampForceEffect<D>;
};

template <> struct traits<Windows::Gaming::Input::ForceFeedback::ConditionForceEffect>
{
    using abi = ABI::Windows::Gaming::Input::ForceFeedback::ConditionForceEffect;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Gaming.Input.ForceFeedback.ConditionForceEffect"; }
};

template <> struct traits<Windows::Gaming::Input::ForceFeedback::ConstantForceEffect>
{
    using abi = ABI::Windows::Gaming::Input::ForceFeedback::ConstantForceEffect;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Gaming.Input.ForceFeedback.ConstantForceEffect"; }
};

template <> struct traits<Windows::Gaming::Input::ForceFeedback::ForceFeedbackMotor>
{
    using abi = ABI::Windows::Gaming::Input::ForceFeedback::ForceFeedbackMotor;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Gaming.Input.ForceFeedback.ForceFeedbackMotor"; }
};

template <> struct traits<Windows::Gaming::Input::ForceFeedback::PeriodicForceEffect>
{
    using abi = ABI::Windows::Gaming::Input::ForceFeedback::PeriodicForceEffect;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Gaming.Input.ForceFeedback.PeriodicForceEffect"; }
};

template <> struct traits<Windows::Gaming::Input::ForceFeedback::RampForceEffect>
{
    using abi = ABI::Windows::Gaming::Input::ForceFeedback::RampForceEffect;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Gaming.Input.ForceFeedback.RampForceEffect"; }
};

}

}
