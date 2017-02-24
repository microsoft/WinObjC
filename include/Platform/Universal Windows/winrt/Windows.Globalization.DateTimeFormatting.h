// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Globalization.DateTimeFormatting.3.h"
#include "Windows.Globalization.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Globalization::DateTimeFormatting::IDateTimeFormatter> : produce_base<D, Windows::Globalization::DateTimeFormatting::IDateTimeFormatter>
{
    HRESULT __stdcall get_Languages(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Languages());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GeographicRegion(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GeographicRegion());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Calendar(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Calendar());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Clock(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Clock());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NumeralSystem(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NumeralSystem());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_NumeralSystem(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NumeralSystem(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Patterns(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Patterns());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Template(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Template());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Format(impl::abi_arg_in<Windows::Foundation::DateTime> value, impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Format(*reinterpret_cast<const Windows::Foundation::DateTime *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IncludeYear(Windows::Globalization::DateTimeFormatting::YearFormat * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IncludeYear());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IncludeMonth(Windows::Globalization::DateTimeFormatting::MonthFormat * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IncludeMonth());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IncludeDayOfWeek(Windows::Globalization::DateTimeFormatting::DayOfWeekFormat * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IncludeDayOfWeek());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IncludeDay(Windows::Globalization::DateTimeFormatting::DayFormat * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IncludeDay());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IncludeHour(Windows::Globalization::DateTimeFormatting::HourFormat * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IncludeHour());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IncludeMinute(Windows::Globalization::DateTimeFormatting::MinuteFormat * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IncludeMinute());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IncludeSecond(Windows::Globalization::DateTimeFormatting::SecondFormat * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IncludeSecond());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ResolvedLanguage(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ResolvedLanguage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ResolvedGeographicRegion(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ResolvedGeographicRegion());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Globalization::DateTimeFormatting::IDateTimeFormatter2> : produce_base<D, Windows::Globalization::DateTimeFormatting::IDateTimeFormatter2>
{
    HRESULT __stdcall abi_FormatUsingTimeZone(impl::abi_arg_in<Windows::Foundation::DateTime> datetime, impl::abi_arg_in<hstring> timeZoneId, impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Format(*reinterpret_cast<const Windows::Foundation::DateTime *>(&datetime), *reinterpret_cast<const hstring *>(&timeZoneId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Globalization::DateTimeFormatting::IDateTimeFormatterFactory> : produce_base<D, Windows::Globalization::DateTimeFormatting::IDateTimeFormatterFactory>
{
    HRESULT __stdcall abi_CreateDateTimeFormatter(impl::abi_arg_in<hstring> formatTemplate, impl::abi_arg_out<Windows::Globalization::DateTimeFormatting::IDateTimeFormatter> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateDateTimeFormatter(*reinterpret_cast<const hstring *>(&formatTemplate)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateDateTimeFormatterLanguages(impl::abi_arg_in<hstring> formatTemplate, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> languages, impl::abi_arg_out<Windows::Globalization::DateTimeFormatting::IDateTimeFormatter> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateDateTimeFormatterLanguages(*reinterpret_cast<const hstring *>(&formatTemplate), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&languages)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateDateTimeFormatterContext(impl::abi_arg_in<hstring> formatTemplate, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> languages, impl::abi_arg_in<hstring> geographicRegion, impl::abi_arg_in<hstring> calendar, impl::abi_arg_in<hstring> clock, impl::abi_arg_out<Windows::Globalization::DateTimeFormatting::IDateTimeFormatter> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateDateTimeFormatterContext(*reinterpret_cast<const hstring *>(&formatTemplate), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&languages), *reinterpret_cast<const hstring *>(&geographicRegion), *reinterpret_cast<const hstring *>(&calendar), *reinterpret_cast<const hstring *>(&clock)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateDateTimeFormatterDate(Windows::Globalization::DateTimeFormatting::YearFormat yearFormat, Windows::Globalization::DateTimeFormatting::MonthFormat monthFormat, Windows::Globalization::DateTimeFormatting::DayFormat dayFormat, Windows::Globalization::DateTimeFormatting::DayOfWeekFormat dayOfWeekFormat, impl::abi_arg_out<Windows::Globalization::DateTimeFormatting::IDateTimeFormatter> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateDateTimeFormatterDate(yearFormat, monthFormat, dayFormat, dayOfWeekFormat));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateDateTimeFormatterTime(Windows::Globalization::DateTimeFormatting::HourFormat hourFormat, Windows::Globalization::DateTimeFormatting::MinuteFormat minuteFormat, Windows::Globalization::DateTimeFormatting::SecondFormat secondFormat, impl::abi_arg_out<Windows::Globalization::DateTimeFormatting::IDateTimeFormatter> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateDateTimeFormatterTime(hourFormat, minuteFormat, secondFormat));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateDateTimeFormatterDateTimeLanguages(Windows::Globalization::DateTimeFormatting::YearFormat yearFormat, Windows::Globalization::DateTimeFormatting::MonthFormat monthFormat, Windows::Globalization::DateTimeFormatting::DayFormat dayFormat, Windows::Globalization::DateTimeFormatting::DayOfWeekFormat dayOfWeekFormat, Windows::Globalization::DateTimeFormatting::HourFormat hourFormat, Windows::Globalization::DateTimeFormatting::MinuteFormat minuteFormat, Windows::Globalization::DateTimeFormatting::SecondFormat secondFormat, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> languages, impl::abi_arg_out<Windows::Globalization::DateTimeFormatting::IDateTimeFormatter> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateDateTimeFormatterDateTimeLanguages(yearFormat, monthFormat, dayFormat, dayOfWeekFormat, hourFormat, minuteFormat, secondFormat, *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&languages)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateDateTimeFormatterDateTimeContext(Windows::Globalization::DateTimeFormatting::YearFormat yearFormat, Windows::Globalization::DateTimeFormatting::MonthFormat monthFormat, Windows::Globalization::DateTimeFormatting::DayFormat dayFormat, Windows::Globalization::DateTimeFormatting::DayOfWeekFormat dayOfWeekFormat, Windows::Globalization::DateTimeFormatting::HourFormat hourFormat, Windows::Globalization::DateTimeFormatting::MinuteFormat minuteFormat, Windows::Globalization::DateTimeFormatting::SecondFormat secondFormat, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> languages, impl::abi_arg_in<hstring> geographicRegion, impl::abi_arg_in<hstring> calendar, impl::abi_arg_in<hstring> clock, impl::abi_arg_out<Windows::Globalization::DateTimeFormatting::IDateTimeFormatter> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateDateTimeFormatterDateTimeContext(yearFormat, monthFormat, dayFormat, dayOfWeekFormat, hourFormat, minuteFormat, secondFormat, *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&languages), *reinterpret_cast<const hstring *>(&geographicRegion), *reinterpret_cast<const hstring *>(&calendar), *reinterpret_cast<const hstring *>(&clock)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Globalization::DateTimeFormatting::IDateTimeFormatterStatics> : produce_base<D, Windows::Globalization::DateTimeFormatting::IDateTimeFormatterStatics>
{
    HRESULT __stdcall get_LongDate(impl::abi_arg_out<Windows::Globalization::DateTimeFormatting::IDateTimeFormatter> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LongDate());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LongTime(impl::abi_arg_out<Windows::Globalization::DateTimeFormatting::IDateTimeFormatter> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LongTime());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ShortDate(impl::abi_arg_out<Windows::Globalization::DateTimeFormatting::IDateTimeFormatter> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ShortDate());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ShortTime(impl::abi_arg_out<Windows::Globalization::DateTimeFormatting::IDateTimeFormatter> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ShortTime());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Globalization::DateTimeFormatting {

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IDateTimeFormatter<D>::Languages() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(IDateTimeFormatter)->get_Languages(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IDateTimeFormatter<D>::GeographicRegion() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDateTimeFormatter)->get_GeographicRegion(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IDateTimeFormatter<D>::Calendar() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDateTimeFormatter)->get_Calendar(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IDateTimeFormatter<D>::Clock() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDateTimeFormatter)->get_Clock(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IDateTimeFormatter<D>::NumeralSystem() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDateTimeFormatter)->get_NumeralSystem(put_abi(value)));
    return value;
}

template <typename D> void impl_IDateTimeFormatter<D>::NumeralSystem(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IDateTimeFormatter)->put_NumeralSystem(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IDateTimeFormatter<D>::Patterns() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(IDateTimeFormatter)->get_Patterns(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IDateTimeFormatter<D>::Template() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDateTimeFormatter)->get_Template(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IDateTimeFormatter<D>::Format(const Windows::Foundation::DateTime & value) const
{
    hstring result;
    check_hresult(WINRT_SHIM(IDateTimeFormatter)->abi_Format(get_abi(value), put_abi(result)));
    return result;
}

template <typename D> Windows::Globalization::DateTimeFormatting::YearFormat impl_IDateTimeFormatter<D>::IncludeYear() const
{
    Windows::Globalization::DateTimeFormatting::YearFormat value {};
    check_hresult(WINRT_SHIM(IDateTimeFormatter)->get_IncludeYear(&value));
    return value;
}

template <typename D> Windows::Globalization::DateTimeFormatting::MonthFormat impl_IDateTimeFormatter<D>::IncludeMonth() const
{
    Windows::Globalization::DateTimeFormatting::MonthFormat value {};
    check_hresult(WINRT_SHIM(IDateTimeFormatter)->get_IncludeMonth(&value));
    return value;
}

template <typename D> Windows::Globalization::DateTimeFormatting::DayOfWeekFormat impl_IDateTimeFormatter<D>::IncludeDayOfWeek() const
{
    Windows::Globalization::DateTimeFormatting::DayOfWeekFormat value {};
    check_hresult(WINRT_SHIM(IDateTimeFormatter)->get_IncludeDayOfWeek(&value));
    return value;
}

template <typename D> Windows::Globalization::DateTimeFormatting::DayFormat impl_IDateTimeFormatter<D>::IncludeDay() const
{
    Windows::Globalization::DateTimeFormatting::DayFormat value {};
    check_hresult(WINRT_SHIM(IDateTimeFormatter)->get_IncludeDay(&value));
    return value;
}

template <typename D> Windows::Globalization::DateTimeFormatting::HourFormat impl_IDateTimeFormatter<D>::IncludeHour() const
{
    Windows::Globalization::DateTimeFormatting::HourFormat value {};
    check_hresult(WINRT_SHIM(IDateTimeFormatter)->get_IncludeHour(&value));
    return value;
}

template <typename D> Windows::Globalization::DateTimeFormatting::MinuteFormat impl_IDateTimeFormatter<D>::IncludeMinute() const
{
    Windows::Globalization::DateTimeFormatting::MinuteFormat value {};
    check_hresult(WINRT_SHIM(IDateTimeFormatter)->get_IncludeMinute(&value));
    return value;
}

template <typename D> Windows::Globalization::DateTimeFormatting::SecondFormat impl_IDateTimeFormatter<D>::IncludeSecond() const
{
    Windows::Globalization::DateTimeFormatting::SecondFormat value {};
    check_hresult(WINRT_SHIM(IDateTimeFormatter)->get_IncludeSecond(&value));
    return value;
}

template <typename D> hstring impl_IDateTimeFormatter<D>::ResolvedLanguage() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDateTimeFormatter)->get_ResolvedLanguage(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IDateTimeFormatter<D>::ResolvedGeographicRegion() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDateTimeFormatter)->get_ResolvedGeographicRegion(put_abi(value)));
    return value;
}

template <typename D> Windows::Globalization::DateTimeFormatting::DateTimeFormatter impl_IDateTimeFormatterFactory<D>::CreateDateTimeFormatter(hstring_view formatTemplate) const
{
    Windows::Globalization::DateTimeFormatting::DateTimeFormatter result { nullptr };
    check_hresult(WINRT_SHIM(IDateTimeFormatterFactory)->abi_CreateDateTimeFormatter(get_abi(formatTemplate), put_abi(result)));
    return result;
}

template <typename D> Windows::Globalization::DateTimeFormatting::DateTimeFormatter impl_IDateTimeFormatterFactory<D>::CreateDateTimeFormatterLanguages(hstring_view formatTemplate, iterable<hstring> languages) const
{
    Windows::Globalization::DateTimeFormatting::DateTimeFormatter result { nullptr };
    check_hresult(WINRT_SHIM(IDateTimeFormatterFactory)->abi_CreateDateTimeFormatterLanguages(get_abi(formatTemplate), get_abi(languages), put_abi(result)));
    return result;
}

template <typename D> Windows::Globalization::DateTimeFormatting::DateTimeFormatter impl_IDateTimeFormatterFactory<D>::CreateDateTimeFormatterContext(hstring_view formatTemplate, iterable<hstring> languages, hstring_view geographicRegion, hstring_view calendar, hstring_view clock) const
{
    Windows::Globalization::DateTimeFormatting::DateTimeFormatter result { nullptr };
    check_hresult(WINRT_SHIM(IDateTimeFormatterFactory)->abi_CreateDateTimeFormatterContext(get_abi(formatTemplate), get_abi(languages), get_abi(geographicRegion), get_abi(calendar), get_abi(clock), put_abi(result)));
    return result;
}

template <typename D> Windows::Globalization::DateTimeFormatting::DateTimeFormatter impl_IDateTimeFormatterFactory<D>::CreateDateTimeFormatterDate(Windows::Globalization::DateTimeFormatting::YearFormat yearFormat, Windows::Globalization::DateTimeFormatting::MonthFormat monthFormat, Windows::Globalization::DateTimeFormatting::DayFormat dayFormat, Windows::Globalization::DateTimeFormatting::DayOfWeekFormat dayOfWeekFormat) const
{
    Windows::Globalization::DateTimeFormatting::DateTimeFormatter result { nullptr };
    check_hresult(WINRT_SHIM(IDateTimeFormatterFactory)->abi_CreateDateTimeFormatterDate(yearFormat, monthFormat, dayFormat, dayOfWeekFormat, put_abi(result)));
    return result;
}

template <typename D> Windows::Globalization::DateTimeFormatting::DateTimeFormatter impl_IDateTimeFormatterFactory<D>::CreateDateTimeFormatterTime(Windows::Globalization::DateTimeFormatting::HourFormat hourFormat, Windows::Globalization::DateTimeFormatting::MinuteFormat minuteFormat, Windows::Globalization::DateTimeFormatting::SecondFormat secondFormat) const
{
    Windows::Globalization::DateTimeFormatting::DateTimeFormatter result { nullptr };
    check_hresult(WINRT_SHIM(IDateTimeFormatterFactory)->abi_CreateDateTimeFormatterTime(hourFormat, minuteFormat, secondFormat, put_abi(result)));
    return result;
}

template <typename D> Windows::Globalization::DateTimeFormatting::DateTimeFormatter impl_IDateTimeFormatterFactory<D>::CreateDateTimeFormatterDateTimeLanguages(Windows::Globalization::DateTimeFormatting::YearFormat yearFormat, Windows::Globalization::DateTimeFormatting::MonthFormat monthFormat, Windows::Globalization::DateTimeFormatting::DayFormat dayFormat, Windows::Globalization::DateTimeFormatting::DayOfWeekFormat dayOfWeekFormat, Windows::Globalization::DateTimeFormatting::HourFormat hourFormat, Windows::Globalization::DateTimeFormatting::MinuteFormat minuteFormat, Windows::Globalization::DateTimeFormatting::SecondFormat secondFormat, iterable<hstring> languages) const
{
    Windows::Globalization::DateTimeFormatting::DateTimeFormatter result { nullptr };
    check_hresult(WINRT_SHIM(IDateTimeFormatterFactory)->abi_CreateDateTimeFormatterDateTimeLanguages(yearFormat, monthFormat, dayFormat, dayOfWeekFormat, hourFormat, minuteFormat, secondFormat, get_abi(languages), put_abi(result)));
    return result;
}

template <typename D> Windows::Globalization::DateTimeFormatting::DateTimeFormatter impl_IDateTimeFormatterFactory<D>::CreateDateTimeFormatterDateTimeContext(Windows::Globalization::DateTimeFormatting::YearFormat yearFormat, Windows::Globalization::DateTimeFormatting::MonthFormat monthFormat, Windows::Globalization::DateTimeFormatting::DayFormat dayFormat, Windows::Globalization::DateTimeFormatting::DayOfWeekFormat dayOfWeekFormat, Windows::Globalization::DateTimeFormatting::HourFormat hourFormat, Windows::Globalization::DateTimeFormatting::MinuteFormat minuteFormat, Windows::Globalization::DateTimeFormatting::SecondFormat secondFormat, iterable<hstring> languages, hstring_view geographicRegion, hstring_view calendar, hstring_view clock) const
{
    Windows::Globalization::DateTimeFormatting::DateTimeFormatter result { nullptr };
    check_hresult(WINRT_SHIM(IDateTimeFormatterFactory)->abi_CreateDateTimeFormatterDateTimeContext(yearFormat, monthFormat, dayFormat, dayOfWeekFormat, hourFormat, minuteFormat, secondFormat, get_abi(languages), get_abi(geographicRegion), get_abi(calendar), get_abi(clock), put_abi(result)));
    return result;
}

template <typename D> Windows::Globalization::DateTimeFormatting::DateTimeFormatter impl_IDateTimeFormatterStatics<D>::LongDate() const
{
    Windows::Globalization::DateTimeFormatting::DateTimeFormatter value { nullptr };
    check_hresult(WINRT_SHIM(IDateTimeFormatterStatics)->get_LongDate(put_abi(value)));
    return value;
}

template <typename D> Windows::Globalization::DateTimeFormatting::DateTimeFormatter impl_IDateTimeFormatterStatics<D>::LongTime() const
{
    Windows::Globalization::DateTimeFormatting::DateTimeFormatter value { nullptr };
    check_hresult(WINRT_SHIM(IDateTimeFormatterStatics)->get_LongTime(put_abi(value)));
    return value;
}

template <typename D> Windows::Globalization::DateTimeFormatting::DateTimeFormatter impl_IDateTimeFormatterStatics<D>::ShortDate() const
{
    Windows::Globalization::DateTimeFormatting::DateTimeFormatter value { nullptr };
    check_hresult(WINRT_SHIM(IDateTimeFormatterStatics)->get_ShortDate(put_abi(value)));
    return value;
}

template <typename D> Windows::Globalization::DateTimeFormatting::DateTimeFormatter impl_IDateTimeFormatterStatics<D>::ShortTime() const
{
    Windows::Globalization::DateTimeFormatting::DateTimeFormatter value { nullptr };
    check_hresult(WINRT_SHIM(IDateTimeFormatterStatics)->get_ShortTime(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IDateTimeFormatter2<D>::Format(const Windows::Foundation::DateTime & datetime, hstring_view timeZoneId) const
{
    hstring result;
    check_hresult(WINRT_SHIM(IDateTimeFormatter2)->abi_FormatUsingTimeZone(get_abi(datetime), get_abi(timeZoneId), put_abi(result)));
    return result;
}

inline DateTimeFormatter::DateTimeFormatter(hstring_view formatTemplate) :
    DateTimeFormatter(get_activation_factory<DateTimeFormatter, IDateTimeFormatterFactory>().CreateDateTimeFormatter(formatTemplate))
{}

inline DateTimeFormatter::DateTimeFormatter(hstring_view formatTemplate, iterable<hstring> languages) :
    DateTimeFormatter(get_activation_factory<DateTimeFormatter, IDateTimeFormatterFactory>().CreateDateTimeFormatterLanguages(formatTemplate, languages))
{}

inline DateTimeFormatter::DateTimeFormatter(hstring_view formatTemplate, iterable<hstring> languages, hstring_view geographicRegion, hstring_view calendar, hstring_view clock) :
    DateTimeFormatter(get_activation_factory<DateTimeFormatter, IDateTimeFormatterFactory>().CreateDateTimeFormatterContext(formatTemplate, languages, geographicRegion, calendar, clock))
{}

inline DateTimeFormatter::DateTimeFormatter(Windows::Globalization::DateTimeFormatting::YearFormat yearFormat, Windows::Globalization::DateTimeFormatting::MonthFormat monthFormat, Windows::Globalization::DateTimeFormatting::DayFormat dayFormat, Windows::Globalization::DateTimeFormatting::DayOfWeekFormat dayOfWeekFormat) :
    DateTimeFormatter(get_activation_factory<DateTimeFormatter, IDateTimeFormatterFactory>().CreateDateTimeFormatterDate(yearFormat, monthFormat, dayFormat, dayOfWeekFormat))
{}

inline DateTimeFormatter::DateTimeFormatter(Windows::Globalization::DateTimeFormatting::HourFormat hourFormat, Windows::Globalization::DateTimeFormatting::MinuteFormat minuteFormat, Windows::Globalization::DateTimeFormatting::SecondFormat secondFormat) :
    DateTimeFormatter(get_activation_factory<DateTimeFormatter, IDateTimeFormatterFactory>().CreateDateTimeFormatterTime(hourFormat, minuteFormat, secondFormat))
{}

inline DateTimeFormatter::DateTimeFormatter(Windows::Globalization::DateTimeFormatting::YearFormat yearFormat, Windows::Globalization::DateTimeFormatting::MonthFormat monthFormat, Windows::Globalization::DateTimeFormatting::DayFormat dayFormat, Windows::Globalization::DateTimeFormatting::DayOfWeekFormat dayOfWeekFormat, Windows::Globalization::DateTimeFormatting::HourFormat hourFormat, Windows::Globalization::DateTimeFormatting::MinuteFormat minuteFormat, Windows::Globalization::DateTimeFormatting::SecondFormat secondFormat, iterable<hstring> languages) :
    DateTimeFormatter(get_activation_factory<DateTimeFormatter, IDateTimeFormatterFactory>().CreateDateTimeFormatterDateTimeLanguages(yearFormat, monthFormat, dayFormat, dayOfWeekFormat, hourFormat, minuteFormat, secondFormat, languages))
{}

inline DateTimeFormatter::DateTimeFormatter(Windows::Globalization::DateTimeFormatting::YearFormat yearFormat, Windows::Globalization::DateTimeFormatting::MonthFormat monthFormat, Windows::Globalization::DateTimeFormatting::DayFormat dayFormat, Windows::Globalization::DateTimeFormatting::DayOfWeekFormat dayOfWeekFormat, Windows::Globalization::DateTimeFormatting::HourFormat hourFormat, Windows::Globalization::DateTimeFormatting::MinuteFormat minuteFormat, Windows::Globalization::DateTimeFormatting::SecondFormat secondFormat, iterable<hstring> languages, hstring_view geographicRegion, hstring_view calendar, hstring_view clock) :
    DateTimeFormatter(get_activation_factory<DateTimeFormatter, IDateTimeFormatterFactory>().CreateDateTimeFormatterDateTimeContext(yearFormat, monthFormat, dayFormat, dayOfWeekFormat, hourFormat, minuteFormat, secondFormat, languages, geographicRegion, calendar, clock))
{}

inline Windows::Globalization::DateTimeFormatting::DateTimeFormatter DateTimeFormatter::LongDate()
{
    return get_activation_factory<DateTimeFormatter, IDateTimeFormatterStatics>().LongDate();
}

inline Windows::Globalization::DateTimeFormatting::DateTimeFormatter DateTimeFormatter::LongTime()
{
    return get_activation_factory<DateTimeFormatter, IDateTimeFormatterStatics>().LongTime();
}

inline Windows::Globalization::DateTimeFormatting::DateTimeFormatter DateTimeFormatter::ShortDate()
{
    return get_activation_factory<DateTimeFormatter, IDateTimeFormatterStatics>().ShortDate();
}

inline Windows::Globalization::DateTimeFormatting::DateTimeFormatter DateTimeFormatter::ShortTime()
{
    return get_activation_factory<DateTimeFormatter, IDateTimeFormatterStatics>().ShortTime();
}

}

}
#pragma warning(pop)
