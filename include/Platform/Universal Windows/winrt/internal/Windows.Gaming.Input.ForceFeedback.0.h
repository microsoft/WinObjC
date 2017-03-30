// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Gaming::Input::ForceFeedback {

struct IConditionForceEffect;
struct IConditionForceEffectFactory;
struct IConstantForceEffect;
struct IForceFeedbackEffect;
struct IForceFeedbackMotor;
struct IPeriodicForceEffect;
struct IPeriodicForceEffectFactory;
struct IRampForceEffect;
struct ConditionForceEffect;
struct ConstantForceEffect;
struct ForceFeedbackMotor;
struct PeriodicForceEffect;
struct RampForceEffect;

}

namespace Windows::Gaming::Input::ForceFeedback {

struct IConditionForceEffect;
struct IConditionForceEffectFactory;
struct IConstantForceEffect;
struct IForceFeedbackEffect;
struct IForceFeedbackMotor;
struct IPeriodicForceEffect;
struct IPeriodicForceEffectFactory;
struct IRampForceEffect;
struct ConditionForceEffect;
struct ConstantForceEffect;
struct ForceFeedbackMotor;
struct PeriodicForceEffect;
struct RampForceEffect;

}

namespace Windows::Gaming::Input::ForceFeedback {

template <typename T> struct impl_IConditionForceEffect;
template <typename T> struct impl_IConditionForceEffectFactory;
template <typename T> struct impl_IConstantForceEffect;
template <typename T> struct impl_IForceFeedbackEffect;
template <typename T> struct impl_IForceFeedbackMotor;
template <typename T> struct impl_IPeriodicForceEffect;
template <typename T> struct impl_IPeriodicForceEffectFactory;
template <typename T> struct impl_IRampForceEffect;

}

namespace Windows::Gaming::Input::ForceFeedback {

enum class ConditionForceEffectKind
{
    Spring = 0,
    Damper = 1,
    Inertia = 2,
    Friction = 3,
};

enum class ForceFeedbackEffectAxes : unsigned
{
    None = 0x0,
    X = 0x1,
    Y = 0x2,
    Z = 0x4,
};

DEFINE_ENUM_FLAG_OPERATORS(ForceFeedbackEffectAxes)

enum class ForceFeedbackEffectState
{
    Stopped = 0,
    Running = 1,
    Paused = 2,
    Faulted = 3,
};

enum class ForceFeedbackLoadEffectResult
{
    Succeeded = 0,
    EffectStorageFull = 1,
    EffectNotSupported = 2,
};

enum class PeriodicForceEffectKind
{
    SquareWave = 0,
    SineWave = 1,
    TriangleWave = 2,
    SawtoothWaveUp = 3,
    SawtoothWaveDown = 4,
};

}

}
