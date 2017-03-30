// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Embedded.DeviceLockdown.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_9520e64b_15b2_52a6_98ed_3191fa6cf68a
#define WINRT_GENERIC_9520e64b_15b2_52a6_98ed_3191fa6cf68a
template <> struct __declspec(uuid("9520e64b-15b2-52a6-98ed-3191fa6cf68a")) __declspec(novtable) IVectorView<GUID> : impl_IVectorView<GUID> {};
#endif

#ifndef WINRT_GENERIC_d3d64048_82b3_53c7_9285_b0be18368482
#define WINRT_GENERIC_d3d64048_82b3_53c7_9285_b0be18368482
template <> struct __declspec(uuid("d3d64048-82b3-53c7-9285-b0be18368482")) __declspec(novtable) IIterator<GUID> : impl_IIterator<GUID> {};
#endif

#ifndef WINRT_GENERIC_f4ca3045_5dd7_54be_982e_d88d8ca0876e
#define WINRT_GENERIC_f4ca3045_5dd7_54be_982e_d88d8ca0876e
template <> struct __declspec(uuid("f4ca3045-5dd7-54be-982e-d88d8ca0876e")) __declspec(novtable) IIterable<GUID> : impl_IIterable<GUID> {};
#endif


}

namespace Windows::Embedded::DeviceLockdown {

struct IDeviceLockdownProfileInformation :
    Windows::Foundation::IInspectable,
    impl::consume<IDeviceLockdownProfileInformation>
{
    IDeviceLockdownProfileInformation(std::nullptr_t = nullptr) noexcept {}
};

struct IDeviceLockdownProfileStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IDeviceLockdownProfileStatics>
{
    IDeviceLockdownProfileStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
