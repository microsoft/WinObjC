// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Globalization.DateTimeFormatting.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Globalization::DateTimeFormatting {

struct WINRT_EBO DateTimeFormatter :
    Windows::Globalization::DateTimeFormatting::IDateTimeFormatter,
    impl::require<DateTimeFormatter, Windows::Globalization::DateTimeFormatting::IDateTimeFormatter2>
{
    DateTimeFormatter(std::nullptr_t) noexcept {}
    DateTimeFormatter(hstring_view formatTemplate);
    DateTimeFormatter(hstring_view formatTemplate, iterable<hstring> languages);
    DateTimeFormatter(hstring_view formatTemplate, iterable<hstring> languages, hstring_view geographicRegion, hstring_view calendar, hstring_view clock);
    DateTimeFormatter(Windows::Globalization::DateTimeFormatting::YearFormat yearFormat, Windows::Globalization::DateTimeFormatting::MonthFormat monthFormat, Windows::Globalization::DateTimeFormatting::DayFormat dayFormat, Windows::Globalization::DateTimeFormatting::DayOfWeekFormat dayOfWeekFormat);
    DateTimeFormatter(Windows::Globalization::DateTimeFormatting::HourFormat hourFormat, Windows::Globalization::DateTimeFormatting::MinuteFormat minuteFormat, Windows::Globalization::DateTimeFormatting::SecondFormat secondFormat);
    DateTimeFormatter(Windows::Globalization::DateTimeFormatting::YearFormat yearFormat, Windows::Globalization::DateTimeFormatting::MonthFormat monthFormat, Windows::Globalization::DateTimeFormatting::DayFormat dayFormat, Windows::Globalization::DateTimeFormatting::DayOfWeekFormat dayOfWeekFormat, Windows::Globalization::DateTimeFormatting::HourFormat hourFormat, Windows::Globalization::DateTimeFormatting::MinuteFormat minuteFormat, Windows::Globalization::DateTimeFormatting::SecondFormat secondFormat, iterable<hstring> languages);
    DateTimeFormatter(Windows::Globalization::DateTimeFormatting::YearFormat yearFormat, Windows::Globalization::DateTimeFormatting::MonthFormat monthFormat, Windows::Globalization::DateTimeFormatting::DayFormat dayFormat, Windows::Globalization::DateTimeFormatting::DayOfWeekFormat dayOfWeekFormat, Windows::Globalization::DateTimeFormatting::HourFormat hourFormat, Windows::Globalization::DateTimeFormatting::MinuteFormat minuteFormat, Windows::Globalization::DateTimeFormatting::SecondFormat secondFormat, iterable<hstring> languages, hstring_view geographicRegion, hstring_view calendar, hstring_view clock);
    using impl_IDateTimeFormatter::Format;
    using impl_IDateTimeFormatter2::Format;
    static Windows::Globalization::DateTimeFormatting::DateTimeFormatter LongDate();
    static Windows::Globalization::DateTimeFormatting::DateTimeFormatter LongTime();
    static Windows::Globalization::DateTimeFormatting::DateTimeFormatter ShortDate();
    static Windows::Globalization::DateTimeFormatting::DateTimeFormatter ShortTime();
};

}

}
