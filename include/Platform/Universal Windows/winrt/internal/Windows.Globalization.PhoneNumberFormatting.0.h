// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Globalization::PhoneNumberFormatting {

struct IPhoneNumberFormatter;
struct IPhoneNumberFormatterStatics;
struct IPhoneNumberInfo;
struct IPhoneNumberInfoFactory;
struct IPhoneNumberInfoStatics;
struct PhoneNumberFormatter;
struct PhoneNumberInfo;

}

namespace Windows::Globalization::PhoneNumberFormatting {

struct IPhoneNumberFormatter;
struct IPhoneNumberFormatterStatics;
struct IPhoneNumberInfo;
struct IPhoneNumberInfoFactory;
struct IPhoneNumberInfoStatics;
struct PhoneNumberFormatter;
struct PhoneNumberInfo;

}

namespace Windows::Globalization::PhoneNumberFormatting {

template <typename T> struct impl_IPhoneNumberFormatter;
template <typename T> struct impl_IPhoneNumberFormatterStatics;
template <typename T> struct impl_IPhoneNumberInfo;
template <typename T> struct impl_IPhoneNumberInfoFactory;
template <typename T> struct impl_IPhoneNumberInfoStatics;

}

namespace Windows::Globalization::PhoneNumberFormatting {

enum class PhoneNumberFormat
{
    E164 = 0,
    International = 1,
    National = 2,
    Rfc3966 = 3,
};

enum class PhoneNumberMatchResult
{
    NoMatch = 0,
    ShortNationalSignificantNumberMatch = 1,
    NationalSignificantNumberMatch = 2,
    ExactMatch = 3,
};

enum class PhoneNumberParseResult
{
    Valid = 0,
    NotANumber = 1,
    InvalidCountryCode = 2,
    TooShort = 3,
    TooLong = 4,
};

enum class PredictedPhoneNumberKind
{
    FixedLine = 0,
    Mobile = 1,
    FixedLineOrMobile = 2,
    TollFree = 3,
    PremiumRate = 4,
    SharedCost = 5,
    Voip = 6,
    PersonalNumber = 7,
    Pager = 8,
    UniversalAccountNumber = 9,
    Voicemail = 10,
    Unknown = 11,
};

}

}
