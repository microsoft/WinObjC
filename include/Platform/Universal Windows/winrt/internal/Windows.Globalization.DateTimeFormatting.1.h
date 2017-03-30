// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Globalization.DateTimeFormatting.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Globalization::DateTimeFormatting {

struct __declspec(uuid("95eeca10-73e0-4e4b-a183-3d6ad0ba35ec")) __declspec(novtable) IDateTimeFormatter : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Languages(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_GeographicRegion(hstring * value) = 0;
    virtual HRESULT __stdcall get_Calendar(hstring * value) = 0;
    virtual HRESULT __stdcall get_Clock(hstring * value) = 0;
    virtual HRESULT __stdcall get_NumeralSystem(hstring * value) = 0;
    virtual HRESULT __stdcall put_NumeralSystem(hstring value) = 0;
    virtual HRESULT __stdcall get_Patterns(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_Template(hstring * value) = 0;
    virtual HRESULT __stdcall abi_Format(Windows::Foundation::DateTime value, hstring * result) = 0;
    virtual HRESULT __stdcall get_IncludeYear(winrt::Windows::Globalization::DateTimeFormatting::YearFormat * value) = 0;
    virtual HRESULT __stdcall get_IncludeMonth(winrt::Windows::Globalization::DateTimeFormatting::MonthFormat * value) = 0;
    virtual HRESULT __stdcall get_IncludeDayOfWeek(winrt::Windows::Globalization::DateTimeFormatting::DayOfWeekFormat * value) = 0;
    virtual HRESULT __stdcall get_IncludeDay(winrt::Windows::Globalization::DateTimeFormatting::DayFormat * value) = 0;
    virtual HRESULT __stdcall get_IncludeHour(winrt::Windows::Globalization::DateTimeFormatting::HourFormat * value) = 0;
    virtual HRESULT __stdcall get_IncludeMinute(winrt::Windows::Globalization::DateTimeFormatting::MinuteFormat * value) = 0;
    virtual HRESULT __stdcall get_IncludeSecond(winrt::Windows::Globalization::DateTimeFormatting::SecondFormat * value) = 0;
    virtual HRESULT __stdcall get_ResolvedLanguage(hstring * value) = 0;
    virtual HRESULT __stdcall get_ResolvedGeographicRegion(hstring * value) = 0;
};

struct __declspec(uuid("27c91a86-bdaa-4fd0-9e36-671d5aa5ee03")) __declspec(novtable) IDateTimeFormatter2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FormatUsingTimeZone(Windows::Foundation::DateTime datetime, hstring timeZoneId, hstring * result) = 0;
};

struct __declspec(uuid("ec8d8a53-1a2e-412d-8815-3b745fb1a2a0")) __declspec(novtable) IDateTimeFormatterFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateDateTimeFormatter(hstring formatTemplate, Windows::Globalization::DateTimeFormatting::IDateTimeFormatter ** result) = 0;
    virtual HRESULT __stdcall abi_CreateDateTimeFormatterLanguages(hstring formatTemplate, Windows::Foundation::Collections::IIterable<hstring> * languages, Windows::Globalization::DateTimeFormatting::IDateTimeFormatter ** result) = 0;
    virtual HRESULT __stdcall abi_CreateDateTimeFormatterContext(hstring formatTemplate, Windows::Foundation::Collections::IIterable<hstring> * languages, hstring geographicRegion, hstring calendar, hstring clock, Windows::Globalization::DateTimeFormatting::IDateTimeFormatter ** result) = 0;
    virtual HRESULT __stdcall abi_CreateDateTimeFormatterDate(winrt::Windows::Globalization::DateTimeFormatting::YearFormat yearFormat, winrt::Windows::Globalization::DateTimeFormatting::MonthFormat monthFormat, winrt::Windows::Globalization::DateTimeFormatting::DayFormat dayFormat, winrt::Windows::Globalization::DateTimeFormatting::DayOfWeekFormat dayOfWeekFormat, Windows::Globalization::DateTimeFormatting::IDateTimeFormatter ** result) = 0;
    virtual HRESULT __stdcall abi_CreateDateTimeFormatterTime(winrt::Windows::Globalization::DateTimeFormatting::HourFormat hourFormat, winrt::Windows::Globalization::DateTimeFormatting::MinuteFormat minuteFormat, winrt::Windows::Globalization::DateTimeFormatting::SecondFormat secondFormat, Windows::Globalization::DateTimeFormatting::IDateTimeFormatter ** result) = 0;
    virtual HRESULT __stdcall abi_CreateDateTimeFormatterDateTimeLanguages(winrt::Windows::Globalization::DateTimeFormatting::YearFormat yearFormat, winrt::Windows::Globalization::DateTimeFormatting::MonthFormat monthFormat, winrt::Windows::Globalization::DateTimeFormatting::DayFormat dayFormat, winrt::Windows::Globalization::DateTimeFormatting::DayOfWeekFormat dayOfWeekFormat, winrt::Windows::Globalization::DateTimeFormatting::HourFormat hourFormat, winrt::Windows::Globalization::DateTimeFormatting::MinuteFormat minuteFormat, winrt::Windows::Globalization::DateTimeFormatting::SecondFormat secondFormat, Windows::Foundation::Collections::IIterable<hstring> * languages, Windows::Globalization::DateTimeFormatting::IDateTimeFormatter ** result) = 0;
    virtual HRESULT __stdcall abi_CreateDateTimeFormatterDateTimeContext(winrt::Windows::Globalization::DateTimeFormatting::YearFormat yearFormat, winrt::Windows::Globalization::DateTimeFormatting::MonthFormat monthFormat, winrt::Windows::Globalization::DateTimeFormatting::DayFormat dayFormat, winrt::Windows::Globalization::DateTimeFormatting::DayOfWeekFormat dayOfWeekFormat, winrt::Windows::Globalization::DateTimeFormatting::HourFormat hourFormat, winrt::Windows::Globalization::DateTimeFormatting::MinuteFormat minuteFormat, winrt::Windows::Globalization::DateTimeFormatting::SecondFormat secondFormat, Windows::Foundation::Collections::IIterable<hstring> * languages, hstring geographicRegion, hstring calendar, hstring clock, Windows::Globalization::DateTimeFormatting::IDateTimeFormatter ** result) = 0;
};

struct __declspec(uuid("bfcde7c0-df4c-4a2e-9012-f47daf3f1212")) __declspec(novtable) IDateTimeFormatterStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LongDate(Windows::Globalization::DateTimeFormatting::IDateTimeFormatter ** value) = 0;
    virtual HRESULT __stdcall get_LongTime(Windows::Globalization::DateTimeFormatting::IDateTimeFormatter ** value) = 0;
    virtual HRESULT __stdcall get_ShortDate(Windows::Globalization::DateTimeFormatting::IDateTimeFormatter ** value) = 0;
    virtual HRESULT __stdcall get_ShortTime(Windows::Globalization::DateTimeFormatting::IDateTimeFormatter ** value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Globalization::DateTimeFormatting::DateTimeFormatter> { using default_interface = Windows::Globalization::DateTimeFormatting::IDateTimeFormatter; };

}

namespace Windows::Globalization::DateTimeFormatting {

template <typename D>
struct WINRT_EBO impl_IDateTimeFormatter
{
    Windows::Foundation::Collections::IVectorView<hstring> Languages() const;
    hstring GeographicRegion() const;
    hstring Calendar() const;
    hstring Clock() const;
    hstring NumeralSystem() const;
    void NumeralSystem(hstring_view value) const;
    Windows::Foundation::Collections::IVectorView<hstring> Patterns() const;
    hstring Template() const;
    hstring Format(const Windows::Foundation::DateTime & value) const;
    Windows::Globalization::DateTimeFormatting::YearFormat IncludeYear() const;
    Windows::Globalization::DateTimeFormatting::MonthFormat IncludeMonth() const;
    Windows::Globalization::DateTimeFormatting::DayOfWeekFormat IncludeDayOfWeek() const;
    Windows::Globalization::DateTimeFormatting::DayFormat IncludeDay() const;
    Windows::Globalization::DateTimeFormatting::HourFormat IncludeHour() const;
    Windows::Globalization::DateTimeFormatting::MinuteFormat IncludeMinute() const;
    Windows::Globalization::DateTimeFormatting::SecondFormat IncludeSecond() const;
    hstring ResolvedLanguage() const;
    hstring ResolvedGeographicRegion() const;
};

template <typename D>
struct WINRT_EBO impl_IDateTimeFormatter2
{
    hstring Format(const Windows::Foundation::DateTime & datetime, hstring_view timeZoneId) const;
};

template <typename D>
struct WINRT_EBO impl_IDateTimeFormatterFactory
{
    Windows::Globalization::DateTimeFormatting::DateTimeFormatter CreateDateTimeFormatter(hstring_view formatTemplate) const;
    Windows::Globalization::DateTimeFormatting::DateTimeFormatter CreateDateTimeFormatterLanguages(hstring_view formatTemplate, iterable<hstring> languages) const;
    Windows::Globalization::DateTimeFormatting::DateTimeFormatter CreateDateTimeFormatterContext(hstring_view formatTemplate, iterable<hstring> languages, hstring_view geographicRegion, hstring_view calendar, hstring_view clock) const;
    Windows::Globalization::DateTimeFormatting::DateTimeFormatter CreateDateTimeFormatterDate(Windows::Globalization::DateTimeFormatting::YearFormat yearFormat, Windows::Globalization::DateTimeFormatting::MonthFormat monthFormat, Windows::Globalization::DateTimeFormatting::DayFormat dayFormat, Windows::Globalization::DateTimeFormatting::DayOfWeekFormat dayOfWeekFormat) const;
    Windows::Globalization::DateTimeFormatting::DateTimeFormatter CreateDateTimeFormatterTime(Windows::Globalization::DateTimeFormatting::HourFormat hourFormat, Windows::Globalization::DateTimeFormatting::MinuteFormat minuteFormat, Windows::Globalization::DateTimeFormatting::SecondFormat secondFormat) const;
    Windows::Globalization::DateTimeFormatting::DateTimeFormatter CreateDateTimeFormatterDateTimeLanguages(Windows::Globalization::DateTimeFormatting::YearFormat yearFormat, Windows::Globalization::DateTimeFormatting::MonthFormat monthFormat, Windows::Globalization::DateTimeFormatting::DayFormat dayFormat, Windows::Globalization::DateTimeFormatting::DayOfWeekFormat dayOfWeekFormat, Windows::Globalization::DateTimeFormatting::HourFormat hourFormat, Windows::Globalization::DateTimeFormatting::MinuteFormat minuteFormat, Windows::Globalization::DateTimeFormatting::SecondFormat secondFormat, iterable<hstring> languages) const;
    Windows::Globalization::DateTimeFormatting::DateTimeFormatter CreateDateTimeFormatterDateTimeContext(Windows::Globalization::DateTimeFormatting::YearFormat yearFormat, Windows::Globalization::DateTimeFormatting::MonthFormat monthFormat, Windows::Globalization::DateTimeFormatting::DayFormat dayFormat, Windows::Globalization::DateTimeFormatting::DayOfWeekFormat dayOfWeekFormat, Windows::Globalization::DateTimeFormatting::HourFormat hourFormat, Windows::Globalization::DateTimeFormatting::MinuteFormat minuteFormat, Windows::Globalization::DateTimeFormatting::SecondFormat secondFormat, iterable<hstring> languages, hstring_view geographicRegion, hstring_view calendar, hstring_view clock) const;
};

template <typename D>
struct WINRT_EBO impl_IDateTimeFormatterStatics
{
    Windows::Globalization::DateTimeFormatting::DateTimeFormatter LongDate() const;
    Windows::Globalization::DateTimeFormatting::DateTimeFormatter LongTime() const;
    Windows::Globalization::DateTimeFormatting::DateTimeFormatter ShortDate() const;
    Windows::Globalization::DateTimeFormatting::DateTimeFormatter ShortTime() const;
};

}

namespace impl {

template <> struct traits<Windows::Globalization::DateTimeFormatting::IDateTimeFormatter>
{
    using abi = ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatter;
    template <typename D> using consume = Windows::Globalization::DateTimeFormatting::impl_IDateTimeFormatter<D>;
};

template <> struct traits<Windows::Globalization::DateTimeFormatting::IDateTimeFormatter2>
{
    using abi = ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatter2;
    template <typename D> using consume = Windows::Globalization::DateTimeFormatting::impl_IDateTimeFormatter2<D>;
};

template <> struct traits<Windows::Globalization::DateTimeFormatting::IDateTimeFormatterFactory>
{
    using abi = ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatterFactory;
    template <typename D> using consume = Windows::Globalization::DateTimeFormatting::impl_IDateTimeFormatterFactory<D>;
};

template <> struct traits<Windows::Globalization::DateTimeFormatting::IDateTimeFormatterStatics>
{
    using abi = ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatterStatics;
    template <typename D> using consume = Windows::Globalization::DateTimeFormatting::impl_IDateTimeFormatterStatics<D>;
};

template <> struct traits<Windows::Globalization::DateTimeFormatting::DateTimeFormatter>
{
    using abi = ABI::Windows::Globalization::DateTimeFormatting::DateTimeFormatter;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Globalization.DateTimeFormatting.DateTimeFormatter"; }
};

}

}
