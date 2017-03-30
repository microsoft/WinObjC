// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Globalization.PhoneNumberFormatting.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Globalization::PhoneNumberFormatting {

struct WINRT_EBO PhoneNumberFormatter :
    Windows::Globalization::PhoneNumberFormatting::IPhoneNumberFormatter
{
    PhoneNumberFormatter(std::nullptr_t) noexcept {}
    PhoneNumberFormatter();
    static void TryCreate(hstring_view regionCode, Windows::Globalization::PhoneNumberFormatting::PhoneNumberFormatter & phoneNumber);
    static int32_t GetCountryCodeForRegion(hstring_view regionCode);
    static hstring GetNationalDirectDialingPrefixForRegion(hstring_view regionCode, bool stripNonDigit);
    static hstring WrapWithLeftToRightMarkers(hstring_view number);
};

struct WINRT_EBO PhoneNumberInfo :
    Windows::Globalization::PhoneNumberFormatting::IPhoneNumberInfo,
    impl::require<PhoneNumberInfo, Windows::Foundation::IStringable>
{
    PhoneNumberInfo(std::nullptr_t) noexcept {}
    PhoneNumberInfo(hstring_view number);
    static Windows::Globalization::PhoneNumberFormatting::PhoneNumberParseResult TryParse(hstring_view input, Windows::Globalization::PhoneNumberFormatting::PhoneNumberInfo & phoneNumber);
    static Windows::Globalization::PhoneNumberFormatting::PhoneNumberParseResult TryParse(hstring_view input, hstring_view regionCode, Windows::Globalization::PhoneNumberFormatting::PhoneNumberInfo & phoneNumber);
};

}

}
