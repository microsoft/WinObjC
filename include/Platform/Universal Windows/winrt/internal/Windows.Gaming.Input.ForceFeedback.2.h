// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Gaming.Input.ForceFeedback.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_cdb5efb3_5788_509d_9be1_71ccb8a3362a
#define WINRT_GENERIC_cdb5efb3_5788_509d_9be1_71ccb8a3362a
template <> struct __declspec(uuid("cdb5efb3-5788-509d-9be1-71ccb8a3362a")) __declspec(novtable) IAsyncOperation<bool> : impl_IAsyncOperation<bool> {};
#endif

#ifndef WINRT_GENERIC_21f834fc_e845_5ab9_bf85_9534e2397798
#define WINRT_GENERIC_21f834fc_e845_5ab9_bf85_9534e2397798
template <> struct __declspec(uuid("21f834fc-e845-5ab9-bf85-9534e2397798")) __declspec(novtable) IAsyncOperation<winrt::Windows::Gaming::Input::ForceFeedback::ForceFeedbackLoadEffectResult> : impl_IAsyncOperation<winrt::Windows::Gaming::Input::ForceFeedback::ForceFeedbackLoadEffectResult> {};
#endif

#ifndef WINRT_GENERIC_c1d3d1a2_ae17_5a5f_b5a2_bdcc8844889a
#define WINRT_GENERIC_c1d3d1a2_ae17_5a5f_b5a2_bdcc8844889a
template <> struct __declspec(uuid("c1d3d1a2-ae17-5a5f-b5a2-bdcc8844889a")) __declspec(novtable) AsyncOperationCompletedHandler<bool> : impl_AsyncOperationCompletedHandler<bool> {};
#endif

#ifndef WINRT_GENERIC_f8220a41_f738_51e8_89ba_76bbd66158cb
#define WINRT_GENERIC_f8220a41_f738_51e8_89ba_76bbd66158cb
template <> struct __declspec(uuid("f8220a41-f738-51e8-89ba-76bbd66158cb")) __declspec(novtable) AsyncOperationCompletedHandler<winrt::Windows::Gaming::Input::ForceFeedback::ForceFeedbackLoadEffectResult> : impl_AsyncOperationCompletedHandler<winrt::Windows::Gaming::Input::ForceFeedback::ForceFeedbackLoadEffectResult> {};
#endif


}

namespace Windows::Gaming::Input::ForceFeedback {

struct IConditionForceEffect :
    Windows::Foundation::IInspectable,
    impl::consume<IConditionForceEffect>,
    impl::require<IConditionForceEffect, Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect>
{
    IConditionForceEffect(std::nullptr_t = nullptr) noexcept {}
};

struct IConditionForceEffectFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IConditionForceEffectFactory>
{
    IConditionForceEffectFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IConstantForceEffect :
    Windows::Foundation::IInspectable,
    impl::consume<IConstantForceEffect>,
    impl::require<IConstantForceEffect, Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect>
{
    IConstantForceEffect(std::nullptr_t = nullptr) noexcept {}
};

struct IForceFeedbackEffect :
    Windows::Foundation::IInspectable,
    impl::consume<IForceFeedbackEffect>
{
    IForceFeedbackEffect(std::nullptr_t = nullptr) noexcept {}
};

struct IForceFeedbackMotor :
    Windows::Foundation::IInspectable,
    impl::consume<IForceFeedbackMotor>
{
    IForceFeedbackMotor(std::nullptr_t = nullptr) noexcept {}
};

struct IPeriodicForceEffect :
    Windows::Foundation::IInspectable,
    impl::consume<IPeriodicForceEffect>,
    impl::require<IPeriodicForceEffect, Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect>
{
    IPeriodicForceEffect(std::nullptr_t = nullptr) noexcept {}
};

struct IPeriodicForceEffectFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IPeriodicForceEffectFactory>
{
    IPeriodicForceEffectFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IRampForceEffect :
    Windows::Foundation::IInspectable,
    impl::consume<IRampForceEffect>,
    impl::require<IRampForceEffect, Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect>
{
    IRampForceEffect(std::nullptr_t = nullptr) noexcept {}
};

}

}
