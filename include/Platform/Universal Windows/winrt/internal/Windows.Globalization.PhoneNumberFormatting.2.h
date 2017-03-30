// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Globalization.PhoneNumberFormatting.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Globalization::PhoneNumberFormatting {

struct IPhoneNumberFormatter :
    Windows::Foundation::IInspectable,
    impl::consume<IPhoneNumberFormatter>
{
    IPhoneNumberFormatter(std::nullptr_t = nullptr) noexcept {}
};

struct IPhoneNumberFormatterStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IPhoneNumberFormatterStatics>
{
    IPhoneNumberFormatterStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IPhoneNumberInfo :
    Windows::Foundation::IInspectable,
    impl::consume<IPhoneNumberInfo>
{
    IPhoneNumberInfo(std::nullptr_t = nullptr) noexcept {}
};

struct IPhoneNumberInfoFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IPhoneNumberInfoFactory>
{
    IPhoneNumberInfoFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IPhoneNumberInfoStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IPhoneNumberInfoStatics>
{
    IPhoneNumberInfoStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
