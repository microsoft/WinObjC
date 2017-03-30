// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Globalization::DateTimeFormatting {

struct IDateTimeFormatter;
struct IDateTimeFormatter2;
struct IDateTimeFormatterFactory;
struct IDateTimeFormatterStatics;
struct DateTimeFormatter;

}

namespace Windows::Globalization::DateTimeFormatting {

struct IDateTimeFormatter;
struct IDateTimeFormatter2;
struct IDateTimeFormatterFactory;
struct IDateTimeFormatterStatics;
struct DateTimeFormatter;

}

namespace Windows::Globalization::DateTimeFormatting {

template <typename T> struct impl_IDateTimeFormatter;
template <typename T> struct impl_IDateTimeFormatter2;
template <typename T> struct impl_IDateTimeFormatterFactory;
template <typename T> struct impl_IDateTimeFormatterStatics;

}

namespace Windows::Globalization::DateTimeFormatting {

enum class DayFormat
{
    None = 0,
    Default = 1,
};

enum class DayOfWeekFormat
{
    None = 0,
    Default = 1,
    Abbreviated = 2,
    Full = 3,
};

enum class HourFormat
{
    None = 0,
    Default = 1,
};

enum class MinuteFormat
{
    None = 0,
    Default = 1,
};

enum class MonthFormat
{
    None = 0,
    Default = 1,
    Abbreviated = 2,
    Full = 3,
    Numeric = 4,
};

enum class SecondFormat
{
    None = 0,
    Default = 1,
};

enum class YearFormat
{
    None = 0,
    Default = 1,
    Abbreviated = 2,
    Full = 3,
};

}

}
