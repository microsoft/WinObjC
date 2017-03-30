// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Pwm.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_07cb8bac_3bac_5ea0_919a_9eaf620270ae
#define WINRT_GENERIC_07cb8bac_3bac_5ea0_919a_9eaf620270ae
template <> struct __declspec(uuid("07cb8bac-3bac-5ea0-919a-9eaf620270ae")) __declspec(novtable) IVectorView<Windows::Devices::Pwm::PwmController> : impl_IVectorView<Windows::Devices::Pwm::PwmController> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_0a288d41_1f20_5d16_85dd_52855b11569a
#define WINRT_GENERIC_0a288d41_1f20_5d16_85dd_52855b11569a
template <> struct __declspec(uuid("0a288d41-1f20-5d16-85dd-52855b11569a")) __declspec(novtable) IAsyncOperation<Windows::Devices::Pwm::PwmController> : impl_IAsyncOperation<Windows::Devices::Pwm::PwmController> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_599330bd_b0ca_533e_938f_5dd4242bf513
#define WINRT_GENERIC_599330bd_b0ca_533e_938f_5dd4242bf513
template <> struct __declspec(uuid("599330bd-b0ca-533e-938f-5dd4242bf513")) __declspec(novtable) IIterator<Windows::Devices::Pwm::PwmController> : impl_IIterator<Windows::Devices::Pwm::PwmController> {};
#endif

#ifndef WINRT_GENERIC_1403a6ab_73cb_5805_9bbc_a0dd39d476b0
#define WINRT_GENERIC_1403a6ab_73cb_5805_9bbc_a0dd39d476b0
template <> struct __declspec(uuid("1403a6ab-73cb-5805-9bbc-a0dd39d476b0")) __declspec(novtable) IIterable<Windows::Devices::Pwm::PwmController> : impl_IIterable<Windows::Devices::Pwm::PwmController> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_5fc68e9f_ffff_5d53_ba21_9c33ef56b240
#define WINRT_GENERIC_5fc68e9f_ffff_5d53_ba21_9c33ef56b240
template <> struct __declspec(uuid("5fc68e9f-ffff-5d53-ba21-9c33ef56b240")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::Pwm::PwmController> : impl_AsyncOperationCompletedHandler<Windows::Devices::Pwm::PwmController> {};
#endif

#ifndef WINRT_GENERIC_e4151e8d_4688_5023_9f5d_008bbd904891
#define WINRT_GENERIC_e4151e8d_4688_5023_9f5d_008bbd904891
template <> struct __declspec(uuid("e4151e8d-4688-5023-9f5d-008bbd904891")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Pwm::PwmController>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Pwm::PwmController>> {};
#endif

#ifndef WINRT_GENERIC_e72bd078_ce02_55ac_a7b9_abd01248d888
#define WINRT_GENERIC_e72bd078_ce02_55ac_a7b9_abd01248d888
template <> struct __declspec(uuid("e72bd078-ce02-55ac-a7b9-abd01248d888")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Devices::Pwm::PwmController>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Devices::Pwm::PwmController>> {};
#endif


}

namespace Windows::Devices::Pwm {

struct IPwmController :
    Windows::Foundation::IInspectable,
    impl::consume<IPwmController>
{
    IPwmController(std::nullptr_t = nullptr) noexcept {}
};

struct IPwmControllerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IPwmControllerStatics>
{
    IPwmControllerStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IPwmControllerStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IPwmControllerStatics2>
{
    IPwmControllerStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct IPwmPin :
    Windows::Foundation::IInspectable,
    impl::consume<IPwmPin>,
    impl::require<IPwmPin, Windows::Foundation::IClosable>
{
    IPwmPin(std::nullptr_t = nullptr) noexcept {}
};

}

}
