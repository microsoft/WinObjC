// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Globalization.3.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Globalization::IApplicationLanguagesStatics> : produce_base<D, Windows::Globalization::IApplicationLanguagesStatics>
{
    HRESULT __stdcall get_PrimaryLanguageOverride(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PrimaryLanguageOverride());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PrimaryLanguageOverride(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PrimaryLanguageOverride(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall get_ManifestLanguages(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ManifestLanguages());
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
struct produce<D, Windows::Globalization::ICalendar> : produce_base<D, Windows::Globalization::ICalendar>
{
    HRESULT __stdcall abi_Clone(impl::abi_arg_out<Windows::Globalization::ICalendar> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Clone());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetToMin() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetToMin();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetToMax() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetToMax();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall abi_GetCalendarSystem(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetCalendarSystem());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ChangeCalendarSystem(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ChangeCalendarSystem(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetClock(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetClock());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ChangeClock(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ChangeClock(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDateTime(impl::abi_arg_out<Windows::Foundation::DateTime> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDateTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetDateTime(impl::abi_arg_in<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetDateTime(*reinterpret_cast<const Windows::Foundation::DateTime *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetToNow() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetToNow();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FirstEra(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FirstEra());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LastEra(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LastEra());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NumberOfEras(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NumberOfEras());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Era(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Era());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Era(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Era(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddEras(int32_t eras) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddEras(eras);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_EraAsFullString(impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().EraAsString());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_EraAsString(int32_t idealLength, impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().EraAsString(idealLength));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FirstYearInThisEra(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FirstYearInThisEra());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LastYearInThisEra(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LastYearInThisEra());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NumberOfYearsInThisEra(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NumberOfYearsInThisEra());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Year(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Year());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Year(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Year(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddYears(int32_t years) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddYears(years);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_YearAsString(impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().YearAsString());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_YearAsTruncatedString(int32_t remainingDigits, impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().YearAsTruncatedString(remainingDigits));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_YearAsPaddedString(int32_t minDigits, impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().YearAsPaddedString(minDigits));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FirstMonthInThisYear(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FirstMonthInThisYear());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LastMonthInThisYear(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LastMonthInThisYear());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NumberOfMonthsInThisYear(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NumberOfMonthsInThisYear());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Month(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Month());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Month(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Month(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddMonths(int32_t months) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddMonths(months);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MonthAsFullString(impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MonthAsString());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MonthAsString(int32_t idealLength, impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MonthAsString(idealLength));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MonthAsFullSoloString(impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MonthAsSoloString());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MonthAsSoloString(int32_t idealLength, impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MonthAsSoloString(idealLength));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MonthAsNumericString(impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MonthAsNumericString());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MonthAsPaddedNumericString(int32_t minDigits, impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MonthAsPaddedNumericString(minDigits));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddWeeks(int32_t weeks) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddWeeks(weeks);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FirstDayInThisMonth(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FirstDayInThisMonth());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LastDayInThisMonth(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LastDayInThisMonth());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NumberOfDaysInThisMonth(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NumberOfDaysInThisMonth());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Day(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Day());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Day(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Day(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddDays(int32_t days) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddDays(days);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DayAsString(impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().DayAsString());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DayAsPaddedString(int32_t minDigits, impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().DayAsPaddedString(minDigits));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DayOfWeek(Windows::Globalization::DayOfWeek * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DayOfWeek());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DayOfWeekAsFullString(impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().DayOfWeekAsString());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DayOfWeekAsString(int32_t idealLength, impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().DayOfWeekAsString(idealLength));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DayOfWeekAsFullSoloString(impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().DayOfWeekAsSoloString());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DayOfWeekAsSoloString(int32_t idealLength, impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().DayOfWeekAsSoloString(idealLength));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FirstPeriodInThisDay(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FirstPeriodInThisDay());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LastPeriodInThisDay(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LastPeriodInThisDay());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NumberOfPeriodsInThisDay(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NumberOfPeriodsInThisDay());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Period(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Period());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Period(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Period(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddPeriods(int32_t periods) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddPeriods(periods);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PeriodAsFullString(impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().PeriodAsString());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PeriodAsString(int32_t idealLength, impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().PeriodAsString(idealLength));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FirstHourInThisPeriod(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FirstHourInThisPeriod());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LastHourInThisPeriod(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LastHourInThisPeriod());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NumberOfHoursInThisPeriod(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NumberOfHoursInThisPeriod());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Hour(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Hour());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Hour(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Hour(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddHours(int32_t hours) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddHours(hours);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_HourAsString(impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().HourAsString());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_HourAsPaddedString(int32_t minDigits, impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().HourAsPaddedString(minDigits));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Minute(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Minute());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Minute(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Minute(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddMinutes(int32_t minutes) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddMinutes(minutes);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MinuteAsString(impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MinuteAsString());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MinuteAsPaddedString(int32_t minDigits, impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MinuteAsPaddedString(minDigits));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Second(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Second());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Second(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Second(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddSeconds(int32_t seconds) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddSeconds(seconds);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SecondAsString(impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().SecondAsString());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SecondAsPaddedString(int32_t minDigits, impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().SecondAsPaddedString(minDigits));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Nanosecond(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Nanosecond());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Nanosecond(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Nanosecond(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddNanoseconds(int32_t nanoseconds) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddNanoseconds(nanoseconds);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_NanosecondAsString(impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().NanosecondAsString());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_NanosecondAsPaddedString(int32_t minDigits, impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().NanosecondAsPaddedString(minDigits));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Compare(impl::abi_arg_in<Windows::Globalization::ICalendar> other, int32_t * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Compare(*reinterpret_cast<const Windows::Globalization::Calendar *>(&other)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CompareDateTime(impl::abi_arg_in<Windows::Foundation::DateTime> other, int32_t * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CompareDateTime(*reinterpret_cast<const Windows::Foundation::DateTime *>(&other)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CopyTo(impl::abi_arg_in<Windows::Globalization::ICalendar> other) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CopyTo(*reinterpret_cast<const Windows::Globalization::Calendar *>(&other));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FirstMinuteInThisHour(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FirstMinuteInThisHour());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LastMinuteInThisHour(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LastMinuteInThisHour());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NumberOfMinutesInThisHour(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NumberOfMinutesInThisHour());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FirstSecondInThisMinute(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FirstSecondInThisMinute());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LastSecondInThisMinute(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LastSecondInThisMinute());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NumberOfSecondsInThisMinute(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NumberOfSecondsInThisMinute());
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

    HRESULT __stdcall get_IsDaylightSavingTime(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDaylightSavingTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Globalization::ICalendarFactory> : produce_base<D, Windows::Globalization::ICalendarFactory>
{
    HRESULT __stdcall abi_CreateCalendarDefaultCalendarAndClock(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> languages, impl::abi_arg_out<Windows::Globalization::ICalendar> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateCalendarDefaultCalendarAndClock(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&languages)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateCalendar(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> languages, impl::abi_arg_in<hstring> calendar, impl::abi_arg_in<hstring> clock, impl::abi_arg_out<Windows::Globalization::ICalendar> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateCalendar(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&languages), *reinterpret_cast<const hstring *>(&calendar), *reinterpret_cast<const hstring *>(&clock)));
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
struct produce<D, Windows::Globalization::ICalendarFactory2> : produce_base<D, Windows::Globalization::ICalendarFactory2>
{
    HRESULT __stdcall abi_CreateCalendarWithTimeZone(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> languages, impl::abi_arg_in<hstring> calendar, impl::abi_arg_in<hstring> clock, impl::abi_arg_in<hstring> timeZoneId, impl::abi_arg_out<Windows::Globalization::ICalendar> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateCalendarWithTimeZone(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&languages), *reinterpret_cast<const hstring *>(&calendar), *reinterpret_cast<const hstring *>(&clock), *reinterpret_cast<const hstring *>(&timeZoneId)));
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
struct produce<D, Windows::Globalization::ICalendarIdentifiersStatics> : produce_base<D, Windows::Globalization::ICalendarIdentifiersStatics>
{
    HRESULT __stdcall get_Gregorian(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Gregorian());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Hebrew(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Hebrew());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Hijri(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Hijri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Japanese(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Japanese());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Julian(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Julian());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Korean(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Korean());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Taiwan(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Taiwan());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Thai(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Thai());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UmAlQura(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UmAlQura());
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
struct produce<D, Windows::Globalization::ICalendarIdentifiersStatics2> : produce_base<D, Windows::Globalization::ICalendarIdentifiersStatics2>
{
    HRESULT __stdcall get_Persian(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Persian());
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
struct produce<D, Windows::Globalization::ICalendarIdentifiersStatics3> : produce_base<D, Windows::Globalization::ICalendarIdentifiersStatics3>
{
    HRESULT __stdcall get_ChineseLunar(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ChineseLunar());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_JapaneseLunar(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().JapaneseLunar());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KoreanLunar(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KoreanLunar());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TaiwanLunar(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TaiwanLunar());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VietnameseLunar(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VietnameseLunar());
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
struct produce<D, Windows::Globalization::IClockIdentifiersStatics> : produce_base<D, Windows::Globalization::IClockIdentifiersStatics>
{
    HRESULT __stdcall get_TwelveHour(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TwelveHour());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TwentyFourHour(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TwentyFourHour());
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
struct produce<D, Windows::Globalization::ICurrencyIdentifiersStatics> : produce_base<D, Windows::Globalization::ICurrencyIdentifiersStatics>
{
    HRESULT __stdcall get_AED(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AED());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AFN(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AFN());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ALL(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ALL());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AMD(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AMD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ANG(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ANG());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AOA(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AOA());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ARS(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ARS());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AUD(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AUD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AWG(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AWG());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AZN(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AZN());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BAM(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BAM());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BBD(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BBD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BDT(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BDT());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BGN(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BGN());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BHD(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BHD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BIF(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BIF());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BMD(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BMD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BND(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BND());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BOB(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BOB());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BRL(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BRL());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BSD(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BSD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BTN(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BTN());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BWP(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BWP());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BYR(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BYR());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BZD(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BZD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CAD(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CAD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CDF(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CDF());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CHF(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CHF());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CLP(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CLP());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CNY(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CNY());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_COP(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().COP());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CRC(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CRC());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CUP(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CUP());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CVE(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CVE());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CZK(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CZK());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DJF(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DJF());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DKK(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DKK());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DOP(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DOP());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DZD(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DZD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EGP(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EGP());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ERN(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ERN());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ETB(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ETB());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EUR(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EUR());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FJD(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FJD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FKP(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FKP());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GBP(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GBP());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GEL(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GEL());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GHS(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GHS());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GIP(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GIP());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GMD(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GMD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GNF(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GNF());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GTQ(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GTQ());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GYD(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GYD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HKD(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HKD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HNL(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HNL());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HRK(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HRK());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HTG(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HTG());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HUF(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HUF());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IDR(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IDR());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ILS(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ILS());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_INR(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().INR());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IQD(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IQD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IRR(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IRR());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ISK(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ISK());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_JMD(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().JMD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_JOD(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().JOD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_JPY(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().JPY());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KES(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KES());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KGS(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KGS());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KHR(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KHR());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KMF(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KMF());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KPW(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KPW());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KRW(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KRW());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KWD(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KWD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KYD(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KYD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KZT(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KZT());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LAK(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LAK());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LBP(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LBP());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LKR(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LKR());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LRD(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LRD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LSL(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LSL());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LTL(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LTL());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LVL(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LVL());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LYD(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LYD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MAD(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MAD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MDL(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MDL());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MGA(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MGA());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MKD(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MKD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MMK(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MMK());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MNT(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MNT());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MOP(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MOP());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MRO(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MRO());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MUR(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MUR());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MVR(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MVR());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MWK(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MWK());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MXN(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MXN());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MYR(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MYR());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MZN(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MZN());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NAD(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NAD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NGN(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NGN());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NIO(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NIO());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NOK(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NOK());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NPR(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NPR());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NZD(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NZD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OMR(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OMR());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PAB(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PAB());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PEN(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PEN());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PGK(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PGK());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PHP(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PHP());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PKR(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PKR());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PLN(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PLN());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PYG(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PYG());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_QAR(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().QAR());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RON(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RON());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RSD(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RSD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RUB(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RUB());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RWF(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RWF());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SAR(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SAR());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SBD(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SBD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SCR(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SCR());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SDG(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SDG());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SEK(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SEK());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SGD(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SGD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SHP(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SHP());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SLL(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SLL());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SOS(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SOS());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SRD(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SRD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_STD(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().STD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SYP(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SYP());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SZL(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SZL());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_THB(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().THB());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TJS(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TJS());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TMT(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TMT());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TND(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TND());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TOP(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TOP());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TRY(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TRY());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TTD(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TTD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TWD(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TWD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TZS(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TZS());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UAH(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UAH());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UGX(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UGX());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_USD(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().USD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UYU(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UYU());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UZS(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UZS());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VEF(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VEF());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VND(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VND());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VUV(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VUV());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WST(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WST());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_XAF(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().XAF());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_XCD(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().XCD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_XOF(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().XOF());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_XPF(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().XPF());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_XXX(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().XXX());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_YER(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().YER());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ZAR(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ZAR());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ZMW(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ZMW());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ZWL(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ZWL());
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
struct produce<D, Windows::Globalization::IGeographicRegion> : produce_base<D, Windows::Globalization::IGeographicRegion>
{
    HRESULT __stdcall get_Code(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Code());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CodeTwoLetter(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CodeTwoLetter());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CodeThreeLetter(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CodeThreeLetter());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CodeThreeDigit(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CodeThreeDigit());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NativeName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NativeName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CurrenciesInUse(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CurrenciesInUse());
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
struct produce<D, Windows::Globalization::IGeographicRegionFactory> : produce_base<D, Windows::Globalization::IGeographicRegionFactory>
{
    HRESULT __stdcall abi_CreateGeographicRegion(impl::abi_arg_in<hstring> geographicRegionCode, impl::abi_arg_out<Windows::Globalization::IGeographicRegion> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateGeographicRegion(*reinterpret_cast<const hstring *>(&geographicRegionCode)));
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
struct produce<D, Windows::Globalization::IGeographicRegionStatics> : produce_base<D, Windows::Globalization::IGeographicRegionStatics>
{
    HRESULT __stdcall abi_IsSupported(impl::abi_arg_in<hstring> geographicRegionCode, bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsSupported(*reinterpret_cast<const hstring *>(&geographicRegionCode)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Globalization::IJapanesePhoneme> : produce_base<D, Windows::Globalization::IJapanesePhoneme>
{
    HRESULT __stdcall get_DisplayText(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayText());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_YomiText(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().YomiText());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsPhraseStart(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsPhraseStart());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Globalization::IJapanesePhoneticAnalyzerStatics> : produce_base<D, Windows::Globalization::IJapanesePhoneticAnalyzerStatics>
{
    HRESULT __stdcall abi_GetWords(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Globalization::JapanesePhoneme>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetWords(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetWordsWithMonoRubyOption(impl::abi_arg_in<hstring> input, bool monoRuby, impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Globalization::JapanesePhoneme>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetWords(*reinterpret_cast<const hstring *>(&input), monoRuby));
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
struct produce<D, Windows::Globalization::ILanguage> : produce_base<D, Windows::Globalization::ILanguage>
{
    HRESULT __stdcall get_LanguageTag(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LanguageTag());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NativeName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NativeName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Script(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Script());
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
struct produce<D, Windows::Globalization::ILanguageExtensionSubtags> : produce_base<D, Windows::Globalization::ILanguageExtensionSubtags>
{
    HRESULT __stdcall abi_GetExtensionSubtags(impl::abi_arg_in<hstring> singleton, impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetExtensionSubtags(*reinterpret_cast<const hstring *>(&singleton)));
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
struct produce<D, Windows::Globalization::ILanguageFactory> : produce_base<D, Windows::Globalization::ILanguageFactory>
{
    HRESULT __stdcall abi_CreateLanguage(impl::abi_arg_in<hstring> languageTag, impl::abi_arg_out<Windows::Globalization::ILanguage> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateLanguage(*reinterpret_cast<const hstring *>(&languageTag)));
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
struct produce<D, Windows::Globalization::ILanguageStatics> : produce_base<D, Windows::Globalization::ILanguageStatics>
{
    HRESULT __stdcall abi_IsWellFormed(impl::abi_arg_in<hstring> languageTag, bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsWellFormed(*reinterpret_cast<const hstring *>(&languageTag)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CurrentInputMethodLanguageTag(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CurrentInputMethodLanguageTag());
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
struct produce<D, Windows::Globalization::ILanguageStatics2> : produce_base<D, Windows::Globalization::ILanguageStatics2>
{
    HRESULT __stdcall abi_TrySetInputMethodLanguageTag(impl::abi_arg_in<hstring> languageTag, bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TrySetInputMethodLanguageTag(*reinterpret_cast<const hstring *>(&languageTag)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Globalization::INumeralSystemIdentifiersStatics> : produce_base<D, Windows::Globalization::INumeralSystemIdentifiersStatics>
{
    HRESULT __stdcall get_Arab(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Arab());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ArabExt(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ArabExt());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Bali(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Bali());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Beng(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Beng());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Cham(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Cham());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Deva(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Deva());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FullWide(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FullWide());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Gujr(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Gujr());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Guru(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Guru());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HaniDec(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HaniDec());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Java(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Java());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Kali(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Kali());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Khmr(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Khmr());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Knda(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Knda());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Lana(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Lana());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LanaTham(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LanaTham());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Laoo(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Laoo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Latn(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Latn());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Lepc(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Lepc());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Limb(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Limb());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Mlym(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Mlym());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Mong(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Mong());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Mtei(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Mtei());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Mymr(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Mymr());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MymrShan(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MymrShan());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Nkoo(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Nkoo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Olck(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Olck());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Orya(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Orya());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Saur(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Saur());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Sund(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Sund());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Talu(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Talu());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TamlDec(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TamlDec());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Telu(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Telu());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Thai(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Thai());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Tibt(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Tibt());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Vaii(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Vaii());
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
struct produce<D, Windows::Globalization::INumeralSystemIdentifiersStatics2> : produce_base<D, Windows::Globalization::INumeralSystemIdentifiersStatics2>
{
    HRESULT __stdcall get_Brah(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Brah());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Osma(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Osma());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MathBold(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MathBold());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MathDbl(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MathDbl());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MathSans(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MathSans());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MathSanb(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MathSanb());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MathMono(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MathMono());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ZmthBold(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ZmthBold());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ZmthDbl(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ZmthDbl());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ZmthSans(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ZmthSans());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ZmthSanb(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ZmthSanb());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ZmthMono(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ZmthMono());
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
struct produce<D, Windows::Globalization::ITimeZoneOnCalendar> : produce_base<D, Windows::Globalization::ITimeZoneOnCalendar>
{
    HRESULT __stdcall abi_GetTimeZone(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetTimeZone());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ChangeTimeZone(impl::abi_arg_in<hstring> timeZoneId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ChangeTimeZone(*reinterpret_cast<const hstring *>(&timeZoneId));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TimeZoneAsFullString(impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TimeZoneAsString());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TimeZoneAsString(int32_t idealLength, impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TimeZoneAsString(idealLength));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Globalization {

template <typename D> hstring impl_ICalendarIdentifiersStatics<D>::Gregorian() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICalendarIdentifiersStatics)->get_Gregorian(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICalendarIdentifiersStatics<D>::Hebrew() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICalendarIdentifiersStatics)->get_Hebrew(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICalendarIdentifiersStatics<D>::Hijri() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICalendarIdentifiersStatics)->get_Hijri(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICalendarIdentifiersStatics<D>::Japanese() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICalendarIdentifiersStatics)->get_Japanese(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICalendarIdentifiersStatics<D>::Julian() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICalendarIdentifiersStatics)->get_Julian(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICalendarIdentifiersStatics<D>::Korean() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICalendarIdentifiersStatics)->get_Korean(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICalendarIdentifiersStatics<D>::Taiwan() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICalendarIdentifiersStatics)->get_Taiwan(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICalendarIdentifiersStatics<D>::Thai() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICalendarIdentifiersStatics)->get_Thai(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICalendarIdentifiersStatics<D>::UmAlQura() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICalendarIdentifiersStatics)->get_UmAlQura(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICalendarIdentifiersStatics2<D>::Persian() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICalendarIdentifiersStatics2)->get_Persian(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICalendarIdentifiersStatics3<D>::ChineseLunar() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICalendarIdentifiersStatics3)->get_ChineseLunar(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICalendarIdentifiersStatics3<D>::JapaneseLunar() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICalendarIdentifiersStatics3)->get_JapaneseLunar(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICalendarIdentifiersStatics3<D>::KoreanLunar() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICalendarIdentifiersStatics3)->get_KoreanLunar(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICalendarIdentifiersStatics3<D>::TaiwanLunar() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICalendarIdentifiersStatics3)->get_TaiwanLunar(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICalendarIdentifiersStatics3<D>::VietnameseLunar() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICalendarIdentifiersStatics3)->get_VietnameseLunar(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IClockIdentifiersStatics<D>::TwelveHour() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IClockIdentifiersStatics)->get_TwelveHour(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IClockIdentifiersStatics<D>::TwentyFourHour() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IClockIdentifiersStatics)->get_TwentyFourHour(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Arab() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics)->get_Arab(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::ArabExt() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics)->get_ArabExt(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Bali() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics)->get_Bali(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Beng() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics)->get_Beng(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Cham() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics)->get_Cham(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Deva() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics)->get_Deva(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::FullWide() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics)->get_FullWide(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Gujr() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics)->get_Gujr(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Guru() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics)->get_Guru(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::HaniDec() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics)->get_HaniDec(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Java() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics)->get_Java(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Kali() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics)->get_Kali(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Khmr() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics)->get_Khmr(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Knda() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics)->get_Knda(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Lana() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics)->get_Lana(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::LanaTham() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics)->get_LanaTham(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Laoo() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics)->get_Laoo(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Latn() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics)->get_Latn(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Lepc() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics)->get_Lepc(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Limb() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics)->get_Limb(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Mlym() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics)->get_Mlym(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Mong() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics)->get_Mong(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Mtei() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics)->get_Mtei(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Mymr() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics)->get_Mymr(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::MymrShan() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics)->get_MymrShan(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Nkoo() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics)->get_Nkoo(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Olck() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics)->get_Olck(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Orya() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics)->get_Orya(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Saur() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics)->get_Saur(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Sund() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics)->get_Sund(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Talu() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics)->get_Talu(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::TamlDec() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics)->get_TamlDec(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Telu() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics)->get_Telu(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Thai() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics)->get_Thai(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Tibt() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics)->get_Tibt(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Vaii() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics)->get_Vaii(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics2<D>::Brah() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics2)->get_Brah(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics2<D>::Osma() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics2)->get_Osma(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics2<D>::MathBold() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics2)->get_MathBold(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics2<D>::MathDbl() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics2)->get_MathDbl(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics2<D>::MathSans() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics2)->get_MathSans(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics2<D>::MathSanb() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics2)->get_MathSanb(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics2<D>::MathMono() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics2)->get_MathMono(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics2<D>::ZmthBold() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics2)->get_ZmthBold(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics2<D>::ZmthDbl() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics2)->get_ZmthDbl(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics2<D>::ZmthSans() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics2)->get_ZmthSans(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics2<D>::ZmthSanb() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics2)->get_ZmthSanb(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics2<D>::ZmthMono() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemIdentifiersStatics2)->get_ZmthMono(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::AED() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_AED(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::AFN() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_AFN(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::ALL() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_ALL(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::AMD() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_AMD(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::ANG() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_ANG(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::AOA() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_AOA(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::ARS() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_ARS(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::AUD() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_AUD(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::AWG() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_AWG(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::AZN() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_AZN(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::BAM() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_BAM(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::BBD() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_BBD(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::BDT() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_BDT(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::BGN() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_BGN(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::BHD() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_BHD(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::BIF() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_BIF(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::BMD() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_BMD(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::BND() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_BND(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::BOB() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_BOB(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::BRL() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_BRL(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::BSD() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_BSD(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::BTN() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_BTN(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::BWP() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_BWP(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::BYR() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_BYR(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::BZD() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_BZD(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::CAD() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_CAD(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::CDF() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_CDF(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::CHF() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_CHF(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::CLP() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_CLP(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::CNY() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_CNY(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::COP() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_COP(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::CRC() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_CRC(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::CUP() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_CUP(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::CVE() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_CVE(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::CZK() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_CZK(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::DJF() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_DJF(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::DKK() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_DKK(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::DOP() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_DOP(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::DZD() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_DZD(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::EGP() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_EGP(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::ERN() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_ERN(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::ETB() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_ETB(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::EUR() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_EUR(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::FJD() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_FJD(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::FKP() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_FKP(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::GBP() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_GBP(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::GEL() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_GEL(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::GHS() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_GHS(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::GIP() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_GIP(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::GMD() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_GMD(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::GNF() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_GNF(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::GTQ() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_GTQ(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::GYD() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_GYD(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::HKD() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_HKD(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::HNL() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_HNL(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::HRK() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_HRK(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::HTG() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_HTG(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::HUF() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_HUF(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::IDR() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_IDR(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::ILS() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_ILS(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::INR() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_INR(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::IQD() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_IQD(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::IRR() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_IRR(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::ISK() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_ISK(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::JMD() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_JMD(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::JOD() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_JOD(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::JPY() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_JPY(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::KES() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_KES(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::KGS() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_KGS(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::KHR() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_KHR(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::KMF() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_KMF(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::KPW() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_KPW(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::KRW() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_KRW(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::KWD() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_KWD(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::KYD() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_KYD(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::KZT() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_KZT(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::LAK() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_LAK(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::LBP() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_LBP(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::LKR() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_LKR(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::LRD() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_LRD(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::LSL() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_LSL(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::LTL() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_LTL(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::LVL() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_LVL(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::LYD() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_LYD(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::MAD() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_MAD(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::MDL() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_MDL(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::MGA() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_MGA(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::MKD() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_MKD(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::MMK() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_MMK(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::MNT() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_MNT(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::MOP() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_MOP(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::MRO() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_MRO(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::MUR() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_MUR(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::MVR() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_MVR(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::MWK() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_MWK(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::MXN() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_MXN(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::MYR() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_MYR(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::MZN() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_MZN(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::NAD() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_NAD(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::NGN() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_NGN(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::NIO() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_NIO(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::NOK() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_NOK(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::NPR() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_NPR(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::NZD() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_NZD(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::OMR() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_OMR(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::PAB() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_PAB(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::PEN() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_PEN(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::PGK() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_PGK(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::PHP() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_PHP(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::PKR() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_PKR(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::PLN() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_PLN(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::PYG() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_PYG(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::QAR() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_QAR(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::RON() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_RON(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::RSD() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_RSD(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::RUB() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_RUB(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::RWF() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_RWF(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::SAR() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_SAR(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::SBD() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_SBD(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::SCR() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_SCR(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::SDG() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_SDG(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::SEK() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_SEK(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::SGD() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_SGD(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::SHP() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_SHP(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::SLL() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_SLL(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::SOS() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_SOS(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::SRD() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_SRD(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::STD() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_STD(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::SYP() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_SYP(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::SZL() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_SZL(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::THB() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_THB(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::TJS() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_TJS(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::TMT() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_TMT(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::TND() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_TND(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::TOP() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_TOP(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::TRY() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_TRY(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::TTD() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_TTD(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::TWD() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_TWD(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::TZS() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_TZS(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::UAH() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_UAH(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::UGX() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_UGX(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::USD() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_USD(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::UYU() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_UYU(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::UZS() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_UZS(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::VEF() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_VEF(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::VND() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_VND(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::VUV() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_VUV(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::WST() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_WST(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::XAF() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_XAF(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::XCD() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_XCD(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::XOF() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_XOF(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::XPF() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_XPF(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::XXX() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_XXX(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::YER() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_YER(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::ZAR() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_ZAR(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::ZMW() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_ZMW(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::ZWL() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyIdentifiersStatics)->get_ZWL(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IGeographicRegion<D>::Code() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IGeographicRegion)->get_Code(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IGeographicRegion<D>::CodeTwoLetter() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IGeographicRegion)->get_CodeTwoLetter(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IGeographicRegion<D>::CodeThreeLetter() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IGeographicRegion)->get_CodeThreeLetter(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IGeographicRegion<D>::CodeThreeDigit() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IGeographicRegion)->get_CodeThreeDigit(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IGeographicRegion<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IGeographicRegion)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IGeographicRegion<D>::NativeName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IGeographicRegion)->get_NativeName(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IGeographicRegion<D>::CurrenciesInUse() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(IGeographicRegion)->get_CurrenciesInUse(put_abi(value)));
    return value;
}

template <typename D> Windows::Globalization::GeographicRegion impl_IGeographicRegionFactory<D>::CreateGeographicRegion(hstring_view geographicRegionCode) const
{
    Windows::Globalization::GeographicRegion result { nullptr };
    check_hresult(WINRT_SHIM(IGeographicRegionFactory)->abi_CreateGeographicRegion(get_abi(geographicRegionCode), put_abi(result)));
    return result;
}

template <typename D> bool impl_IGeographicRegionStatics<D>::IsSupported(hstring_view geographicRegionCode) const
{
    bool result {};
    check_hresult(WINRT_SHIM(IGeographicRegionStatics)->abi_IsSupported(get_abi(geographicRegionCode), &result));
    return result;
}

template <typename D> hstring impl_ILanguage<D>::LanguageTag() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ILanguage)->get_LanguageTag(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ILanguage<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ILanguage)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ILanguage<D>::NativeName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ILanguage)->get_NativeName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ILanguage<D>::Script() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ILanguage)->get_Script(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_ILanguageExtensionSubtags<D>::GetExtensionSubtags(hstring_view singleton) const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(ILanguageExtensionSubtags)->abi_GetExtensionSubtags(get_abi(singleton), put_abi(value)));
    return value;
}

template <typename D> Windows::Globalization::Language impl_ILanguageFactory<D>::CreateLanguage(hstring_view languageTag) const
{
    Windows::Globalization::Language result { nullptr };
    check_hresult(WINRT_SHIM(ILanguageFactory)->abi_CreateLanguage(get_abi(languageTag), put_abi(result)));
    return result;
}

template <typename D> bool impl_ILanguageStatics<D>::IsWellFormed(hstring_view languageTag) const
{
    bool result {};
    check_hresult(WINRT_SHIM(ILanguageStatics)->abi_IsWellFormed(get_abi(languageTag), &result));
    return result;
}

template <typename D> hstring impl_ILanguageStatics<D>::CurrentInputMethodLanguageTag() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ILanguageStatics)->get_CurrentInputMethodLanguageTag(put_abi(value)));
    return value;
}

template <typename D> bool impl_ILanguageStatics2<D>::TrySetInputMethodLanguageTag(hstring_view languageTag) const
{
    bool result {};
    check_hresult(WINRT_SHIM(ILanguageStatics2)->abi_TrySetInputMethodLanguageTag(get_abi(languageTag), &result));
    return result;
}

template <typename D> Windows::Globalization::Calendar impl_ICalendar<D>::Clone() const
{
    Windows::Globalization::Calendar value { nullptr };
    check_hresult(WINRT_SHIM(ICalendar)->abi_Clone(put_abi(value)));
    return value;
}

template <typename D> void impl_ICalendar<D>::SetToMin() const
{
    check_hresult(WINRT_SHIM(ICalendar)->abi_SetToMin());
}

template <typename D> void impl_ICalendar<D>::SetToMax() const
{
    check_hresult(WINRT_SHIM(ICalendar)->abi_SetToMax());
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_ICalendar<D>::Languages() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(ICalendar)->get_Languages(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICalendar<D>::NumeralSystem() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICalendar)->get_NumeralSystem(put_abi(value)));
    return value;
}

template <typename D> void impl_ICalendar<D>::NumeralSystem(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ICalendar)->put_NumeralSystem(get_abi(value)));
}

template <typename D> hstring impl_ICalendar<D>::GetCalendarSystem() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICalendar)->abi_GetCalendarSystem(put_abi(value)));
    return value;
}

template <typename D> void impl_ICalendar<D>::ChangeCalendarSystem(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ICalendar)->abi_ChangeCalendarSystem(get_abi(value)));
}

template <typename D> hstring impl_ICalendar<D>::GetClock() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICalendar)->abi_GetClock(put_abi(value)));
    return value;
}

template <typename D> void impl_ICalendar<D>::ChangeClock(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ICalendar)->abi_ChangeClock(get_abi(value)));
}

template <typename D> Windows::Foundation::DateTime impl_ICalendar<D>::GetDateTime() const
{
    Windows::Foundation::DateTime result {};
    check_hresult(WINRT_SHIM(ICalendar)->abi_GetDateTime(put_abi(result)));
    return result;
}

template <typename D> void impl_ICalendar<D>::SetDateTime(const Windows::Foundation::DateTime & value) const
{
    check_hresult(WINRT_SHIM(ICalendar)->abi_SetDateTime(get_abi(value)));
}

template <typename D> void impl_ICalendar<D>::SetToNow() const
{
    check_hresult(WINRT_SHIM(ICalendar)->abi_SetToNow());
}

template <typename D> int32_t impl_ICalendar<D>::FirstEra() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ICalendar)->get_FirstEra(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::LastEra() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ICalendar)->get_LastEra(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::NumberOfEras() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ICalendar)->get_NumberOfEras(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::Era() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ICalendar)->get_Era(&value));
    return value;
}

template <typename D> void impl_ICalendar<D>::Era(int32_t value) const
{
    check_hresult(WINRT_SHIM(ICalendar)->put_Era(value));
}

template <typename D> void impl_ICalendar<D>::AddEras(int32_t eras) const
{
    check_hresult(WINRT_SHIM(ICalendar)->abi_AddEras(eras));
}

template <typename D> hstring impl_ICalendar<D>::EraAsString() const
{
    hstring result;
    check_hresult(WINRT_SHIM(ICalendar)->abi_EraAsFullString(put_abi(result)));
    return result;
}

template <typename D> hstring impl_ICalendar<D>::EraAsString(int32_t idealLength) const
{
    hstring result;
    check_hresult(WINRT_SHIM(ICalendar)->abi_EraAsString(idealLength, put_abi(result)));
    return result;
}

template <typename D> int32_t impl_ICalendar<D>::FirstYearInThisEra() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ICalendar)->get_FirstYearInThisEra(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::LastYearInThisEra() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ICalendar)->get_LastYearInThisEra(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::NumberOfYearsInThisEra() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ICalendar)->get_NumberOfYearsInThisEra(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::Year() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ICalendar)->get_Year(&value));
    return value;
}

template <typename D> void impl_ICalendar<D>::Year(int32_t value) const
{
    check_hresult(WINRT_SHIM(ICalendar)->put_Year(value));
}

template <typename D> void impl_ICalendar<D>::AddYears(int32_t years) const
{
    check_hresult(WINRT_SHIM(ICalendar)->abi_AddYears(years));
}

template <typename D> hstring impl_ICalendar<D>::YearAsString() const
{
    hstring result;
    check_hresult(WINRT_SHIM(ICalendar)->abi_YearAsString(put_abi(result)));
    return result;
}

template <typename D> hstring impl_ICalendar<D>::YearAsTruncatedString(int32_t remainingDigits) const
{
    hstring result;
    check_hresult(WINRT_SHIM(ICalendar)->abi_YearAsTruncatedString(remainingDigits, put_abi(result)));
    return result;
}

template <typename D> hstring impl_ICalendar<D>::YearAsPaddedString(int32_t minDigits) const
{
    hstring result;
    check_hresult(WINRT_SHIM(ICalendar)->abi_YearAsPaddedString(minDigits, put_abi(result)));
    return result;
}

template <typename D> int32_t impl_ICalendar<D>::FirstMonthInThisYear() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ICalendar)->get_FirstMonthInThisYear(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::LastMonthInThisYear() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ICalendar)->get_LastMonthInThisYear(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::NumberOfMonthsInThisYear() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ICalendar)->get_NumberOfMonthsInThisYear(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::Month() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ICalendar)->get_Month(&value));
    return value;
}

template <typename D> void impl_ICalendar<D>::Month(int32_t value) const
{
    check_hresult(WINRT_SHIM(ICalendar)->put_Month(value));
}

template <typename D> void impl_ICalendar<D>::AddMonths(int32_t months) const
{
    check_hresult(WINRT_SHIM(ICalendar)->abi_AddMonths(months));
}

template <typename D> hstring impl_ICalendar<D>::MonthAsString() const
{
    hstring result;
    check_hresult(WINRT_SHIM(ICalendar)->abi_MonthAsFullString(put_abi(result)));
    return result;
}

template <typename D> hstring impl_ICalendar<D>::MonthAsString(int32_t idealLength) const
{
    hstring result;
    check_hresult(WINRT_SHIM(ICalendar)->abi_MonthAsString(idealLength, put_abi(result)));
    return result;
}

template <typename D> hstring impl_ICalendar<D>::MonthAsSoloString() const
{
    hstring result;
    check_hresult(WINRT_SHIM(ICalendar)->abi_MonthAsFullSoloString(put_abi(result)));
    return result;
}

template <typename D> hstring impl_ICalendar<D>::MonthAsSoloString(int32_t idealLength) const
{
    hstring result;
    check_hresult(WINRT_SHIM(ICalendar)->abi_MonthAsSoloString(idealLength, put_abi(result)));
    return result;
}

template <typename D> hstring impl_ICalendar<D>::MonthAsNumericString() const
{
    hstring result;
    check_hresult(WINRT_SHIM(ICalendar)->abi_MonthAsNumericString(put_abi(result)));
    return result;
}

template <typename D> hstring impl_ICalendar<D>::MonthAsPaddedNumericString(int32_t minDigits) const
{
    hstring result;
    check_hresult(WINRT_SHIM(ICalendar)->abi_MonthAsPaddedNumericString(minDigits, put_abi(result)));
    return result;
}

template <typename D> void impl_ICalendar<D>::AddWeeks(int32_t weeks) const
{
    check_hresult(WINRT_SHIM(ICalendar)->abi_AddWeeks(weeks));
}

template <typename D> int32_t impl_ICalendar<D>::FirstDayInThisMonth() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ICalendar)->get_FirstDayInThisMonth(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::LastDayInThisMonth() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ICalendar)->get_LastDayInThisMonth(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::NumberOfDaysInThisMonth() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ICalendar)->get_NumberOfDaysInThisMonth(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::Day() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ICalendar)->get_Day(&value));
    return value;
}

template <typename D> void impl_ICalendar<D>::Day(int32_t value) const
{
    check_hresult(WINRT_SHIM(ICalendar)->put_Day(value));
}

template <typename D> void impl_ICalendar<D>::AddDays(int32_t days) const
{
    check_hresult(WINRT_SHIM(ICalendar)->abi_AddDays(days));
}

template <typename D> hstring impl_ICalendar<D>::DayAsString() const
{
    hstring result;
    check_hresult(WINRT_SHIM(ICalendar)->abi_DayAsString(put_abi(result)));
    return result;
}

template <typename D> hstring impl_ICalendar<D>::DayAsPaddedString(int32_t minDigits) const
{
    hstring result;
    check_hresult(WINRT_SHIM(ICalendar)->abi_DayAsPaddedString(minDigits, put_abi(result)));
    return result;
}

template <typename D> Windows::Globalization::DayOfWeek impl_ICalendar<D>::DayOfWeek() const
{
    Windows::Globalization::DayOfWeek value {};
    check_hresult(WINRT_SHIM(ICalendar)->get_DayOfWeek(&value));
    return value;
}

template <typename D> hstring impl_ICalendar<D>::DayOfWeekAsString() const
{
    hstring result;
    check_hresult(WINRT_SHIM(ICalendar)->abi_DayOfWeekAsFullString(put_abi(result)));
    return result;
}

template <typename D> hstring impl_ICalendar<D>::DayOfWeekAsString(int32_t idealLength) const
{
    hstring result;
    check_hresult(WINRT_SHIM(ICalendar)->abi_DayOfWeekAsString(idealLength, put_abi(result)));
    return result;
}

template <typename D> hstring impl_ICalendar<D>::DayOfWeekAsSoloString() const
{
    hstring result;
    check_hresult(WINRT_SHIM(ICalendar)->abi_DayOfWeekAsFullSoloString(put_abi(result)));
    return result;
}

template <typename D> hstring impl_ICalendar<D>::DayOfWeekAsSoloString(int32_t idealLength) const
{
    hstring result;
    check_hresult(WINRT_SHIM(ICalendar)->abi_DayOfWeekAsSoloString(idealLength, put_abi(result)));
    return result;
}

template <typename D> int32_t impl_ICalendar<D>::FirstPeriodInThisDay() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ICalendar)->get_FirstPeriodInThisDay(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::LastPeriodInThisDay() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ICalendar)->get_LastPeriodInThisDay(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::NumberOfPeriodsInThisDay() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ICalendar)->get_NumberOfPeriodsInThisDay(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::Period() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ICalendar)->get_Period(&value));
    return value;
}

template <typename D> void impl_ICalendar<D>::Period(int32_t value) const
{
    check_hresult(WINRT_SHIM(ICalendar)->put_Period(value));
}

template <typename D> void impl_ICalendar<D>::AddPeriods(int32_t periods) const
{
    check_hresult(WINRT_SHIM(ICalendar)->abi_AddPeriods(periods));
}

template <typename D> hstring impl_ICalendar<D>::PeriodAsString() const
{
    hstring result;
    check_hresult(WINRT_SHIM(ICalendar)->abi_PeriodAsFullString(put_abi(result)));
    return result;
}

template <typename D> hstring impl_ICalendar<D>::PeriodAsString(int32_t idealLength) const
{
    hstring result;
    check_hresult(WINRT_SHIM(ICalendar)->abi_PeriodAsString(idealLength, put_abi(result)));
    return result;
}

template <typename D> int32_t impl_ICalendar<D>::FirstHourInThisPeriod() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ICalendar)->get_FirstHourInThisPeriod(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::LastHourInThisPeriod() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ICalendar)->get_LastHourInThisPeriod(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::NumberOfHoursInThisPeriod() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ICalendar)->get_NumberOfHoursInThisPeriod(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::Hour() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ICalendar)->get_Hour(&value));
    return value;
}

template <typename D> void impl_ICalendar<D>::Hour(int32_t value) const
{
    check_hresult(WINRT_SHIM(ICalendar)->put_Hour(value));
}

template <typename D> void impl_ICalendar<D>::AddHours(int32_t hours) const
{
    check_hresult(WINRT_SHIM(ICalendar)->abi_AddHours(hours));
}

template <typename D> hstring impl_ICalendar<D>::HourAsString() const
{
    hstring result;
    check_hresult(WINRT_SHIM(ICalendar)->abi_HourAsString(put_abi(result)));
    return result;
}

template <typename D> hstring impl_ICalendar<D>::HourAsPaddedString(int32_t minDigits) const
{
    hstring result;
    check_hresult(WINRT_SHIM(ICalendar)->abi_HourAsPaddedString(minDigits, put_abi(result)));
    return result;
}

template <typename D> int32_t impl_ICalendar<D>::Minute() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ICalendar)->get_Minute(&value));
    return value;
}

template <typename D> void impl_ICalendar<D>::Minute(int32_t value) const
{
    check_hresult(WINRT_SHIM(ICalendar)->put_Minute(value));
}

template <typename D> void impl_ICalendar<D>::AddMinutes(int32_t minutes) const
{
    check_hresult(WINRT_SHIM(ICalendar)->abi_AddMinutes(minutes));
}

template <typename D> hstring impl_ICalendar<D>::MinuteAsString() const
{
    hstring result;
    check_hresult(WINRT_SHIM(ICalendar)->abi_MinuteAsString(put_abi(result)));
    return result;
}

template <typename D> hstring impl_ICalendar<D>::MinuteAsPaddedString(int32_t minDigits) const
{
    hstring result;
    check_hresult(WINRT_SHIM(ICalendar)->abi_MinuteAsPaddedString(minDigits, put_abi(result)));
    return result;
}

template <typename D> int32_t impl_ICalendar<D>::Second() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ICalendar)->get_Second(&value));
    return value;
}

template <typename D> void impl_ICalendar<D>::Second(int32_t value) const
{
    check_hresult(WINRT_SHIM(ICalendar)->put_Second(value));
}

template <typename D> void impl_ICalendar<D>::AddSeconds(int32_t seconds) const
{
    check_hresult(WINRT_SHIM(ICalendar)->abi_AddSeconds(seconds));
}

template <typename D> hstring impl_ICalendar<D>::SecondAsString() const
{
    hstring result;
    check_hresult(WINRT_SHIM(ICalendar)->abi_SecondAsString(put_abi(result)));
    return result;
}

template <typename D> hstring impl_ICalendar<D>::SecondAsPaddedString(int32_t minDigits) const
{
    hstring result;
    check_hresult(WINRT_SHIM(ICalendar)->abi_SecondAsPaddedString(minDigits, put_abi(result)));
    return result;
}

template <typename D> int32_t impl_ICalendar<D>::Nanosecond() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ICalendar)->get_Nanosecond(&value));
    return value;
}

template <typename D> void impl_ICalendar<D>::Nanosecond(int32_t value) const
{
    check_hresult(WINRT_SHIM(ICalendar)->put_Nanosecond(value));
}

template <typename D> void impl_ICalendar<D>::AddNanoseconds(int32_t nanoseconds) const
{
    check_hresult(WINRT_SHIM(ICalendar)->abi_AddNanoseconds(nanoseconds));
}

template <typename D> hstring impl_ICalendar<D>::NanosecondAsString() const
{
    hstring result;
    check_hresult(WINRT_SHIM(ICalendar)->abi_NanosecondAsString(put_abi(result)));
    return result;
}

template <typename D> hstring impl_ICalendar<D>::NanosecondAsPaddedString(int32_t minDigits) const
{
    hstring result;
    check_hresult(WINRT_SHIM(ICalendar)->abi_NanosecondAsPaddedString(minDigits, put_abi(result)));
    return result;
}

template <typename D> int32_t impl_ICalendar<D>::Compare(const Windows::Globalization::Calendar & other) const
{
    int32_t result {};
    check_hresult(WINRT_SHIM(ICalendar)->abi_Compare(get_abi(other), &result));
    return result;
}

template <typename D> int32_t impl_ICalendar<D>::CompareDateTime(const Windows::Foundation::DateTime & other) const
{
    int32_t result {};
    check_hresult(WINRT_SHIM(ICalendar)->abi_CompareDateTime(get_abi(other), &result));
    return result;
}

template <typename D> void impl_ICalendar<D>::CopyTo(const Windows::Globalization::Calendar & other) const
{
    check_hresult(WINRT_SHIM(ICalendar)->abi_CopyTo(get_abi(other)));
}

template <typename D> int32_t impl_ICalendar<D>::FirstMinuteInThisHour() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ICalendar)->get_FirstMinuteInThisHour(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::LastMinuteInThisHour() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ICalendar)->get_LastMinuteInThisHour(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::NumberOfMinutesInThisHour() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ICalendar)->get_NumberOfMinutesInThisHour(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::FirstSecondInThisMinute() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ICalendar)->get_FirstSecondInThisMinute(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::LastSecondInThisMinute() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ICalendar)->get_LastSecondInThisMinute(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::NumberOfSecondsInThisMinute() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ICalendar)->get_NumberOfSecondsInThisMinute(&value));
    return value;
}

template <typename D> hstring impl_ICalendar<D>::ResolvedLanguage() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICalendar)->get_ResolvedLanguage(put_abi(value)));
    return value;
}

template <typename D> bool impl_ICalendar<D>::IsDaylightSavingTime() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICalendar)->get_IsDaylightSavingTime(&value));
    return value;
}

template <typename D> Windows::Globalization::Calendar impl_ICalendarFactory2<D>::CreateCalendarWithTimeZone(iterable<hstring> languages, hstring_view calendar, hstring_view clock, hstring_view timeZoneId) const
{
    Windows::Globalization::Calendar result { nullptr };
    check_hresult(WINRT_SHIM(ICalendarFactory2)->abi_CreateCalendarWithTimeZone(get_abi(languages), get_abi(calendar), get_abi(clock), get_abi(timeZoneId), put_abi(result)));
    return result;
}

template <typename D> hstring impl_ITimeZoneOnCalendar<D>::GetTimeZone() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ITimeZoneOnCalendar)->abi_GetTimeZone(put_abi(value)));
    return value;
}

template <typename D> void impl_ITimeZoneOnCalendar<D>::ChangeTimeZone(hstring_view timeZoneId) const
{
    check_hresult(WINRT_SHIM(ITimeZoneOnCalendar)->abi_ChangeTimeZone(get_abi(timeZoneId)));
}

template <typename D> hstring impl_ITimeZoneOnCalendar<D>::TimeZoneAsString() const
{
    hstring result;
    check_hresult(WINRT_SHIM(ITimeZoneOnCalendar)->abi_TimeZoneAsFullString(put_abi(result)));
    return result;
}

template <typename D> hstring impl_ITimeZoneOnCalendar<D>::TimeZoneAsString(int32_t idealLength) const
{
    hstring result;
    check_hresult(WINRT_SHIM(ITimeZoneOnCalendar)->abi_TimeZoneAsString(idealLength, put_abi(result)));
    return result;
}

template <typename D> Windows::Globalization::Calendar impl_ICalendarFactory<D>::CreateCalendarDefaultCalendarAndClock(iterable<hstring> languages) const
{
    Windows::Globalization::Calendar result { nullptr };
    check_hresult(WINRT_SHIM(ICalendarFactory)->abi_CreateCalendarDefaultCalendarAndClock(get_abi(languages), put_abi(result)));
    return result;
}

template <typename D> Windows::Globalization::Calendar impl_ICalendarFactory<D>::CreateCalendar(iterable<hstring> languages, hstring_view calendar, hstring_view clock) const
{
    Windows::Globalization::Calendar result { nullptr };
    check_hresult(WINRT_SHIM(ICalendarFactory)->abi_CreateCalendar(get_abi(languages), get_abi(calendar), get_abi(clock), put_abi(result)));
    return result;
}

template <typename D> hstring impl_IApplicationLanguagesStatics<D>::PrimaryLanguageOverride() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IApplicationLanguagesStatics)->get_PrimaryLanguageOverride(put_abi(value)));
    return value;
}

template <typename D> void impl_IApplicationLanguagesStatics<D>::PrimaryLanguageOverride(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IApplicationLanguagesStatics)->put_PrimaryLanguageOverride(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IApplicationLanguagesStatics<D>::Languages() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(IApplicationLanguagesStatics)->get_Languages(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IApplicationLanguagesStatics<D>::ManifestLanguages() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(IApplicationLanguagesStatics)->get_ManifestLanguages(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Globalization::JapanesePhoneme> impl_IJapanesePhoneticAnalyzerStatics<D>::GetWords(hstring_view input) const
{
    Windows::Foundation::Collections::IVectorView<Windows::Globalization::JapanesePhoneme> result;
    check_hresult(WINRT_SHIM(IJapanesePhoneticAnalyzerStatics)->abi_GetWords(get_abi(input), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Globalization::JapanesePhoneme> impl_IJapanesePhoneticAnalyzerStatics<D>::GetWords(hstring_view input, bool monoRuby) const
{
    Windows::Foundation::Collections::IVectorView<Windows::Globalization::JapanesePhoneme> result;
    check_hresult(WINRT_SHIM(IJapanesePhoneticAnalyzerStatics)->abi_GetWordsWithMonoRubyOption(get_abi(input), monoRuby, put_abi(result)));
    return result;
}

template <typename D> hstring impl_IJapanesePhoneme<D>::DisplayText() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IJapanesePhoneme)->get_DisplayText(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IJapanesePhoneme<D>::YomiText() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IJapanesePhoneme)->get_YomiText(put_abi(value)));
    return value;
}

template <typename D> bool impl_IJapanesePhoneme<D>::IsPhraseStart() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IJapanesePhoneme)->get_IsPhraseStart(&value));
    return value;
}

inline hstring ApplicationLanguages::PrimaryLanguageOverride()
{
    return get_activation_factory<ApplicationLanguages, IApplicationLanguagesStatics>().PrimaryLanguageOverride();
}

inline void ApplicationLanguages::PrimaryLanguageOverride(hstring_view value)
{
    get_activation_factory<ApplicationLanguages, IApplicationLanguagesStatics>().PrimaryLanguageOverride(value);
}

inline Windows::Foundation::Collections::IVectorView<hstring> ApplicationLanguages::Languages()
{
    return get_activation_factory<ApplicationLanguages, IApplicationLanguagesStatics>().Languages();
}

inline Windows::Foundation::Collections::IVectorView<hstring> ApplicationLanguages::ManifestLanguages()
{
    return get_activation_factory<ApplicationLanguages, IApplicationLanguagesStatics>().ManifestLanguages();
}

inline Calendar::Calendar() :
    Calendar(activate_instance<Calendar>())
{}

inline Calendar::Calendar(iterable<hstring> languages, hstring_view calendar, hstring_view clock, hstring_view timeZoneId) :
    Calendar(get_activation_factory<Calendar, ICalendarFactory2>().CreateCalendarWithTimeZone(languages, calendar, clock, timeZoneId))
{}

inline Calendar::Calendar(iterable<hstring> languages) :
    Calendar(get_activation_factory<Calendar, ICalendarFactory>().CreateCalendarDefaultCalendarAndClock(languages))
{}

inline Calendar::Calendar(iterable<hstring> languages, hstring_view calendar, hstring_view clock) :
    Calendar(get_activation_factory<Calendar, ICalendarFactory>().CreateCalendar(languages, calendar, clock))
{}

inline hstring CalendarIdentifiers::Gregorian()
{
    return get_activation_factory<CalendarIdentifiers, ICalendarIdentifiersStatics>().Gregorian();
}

inline hstring CalendarIdentifiers::Hebrew()
{
    return get_activation_factory<CalendarIdentifiers, ICalendarIdentifiersStatics>().Hebrew();
}

inline hstring CalendarIdentifiers::Hijri()
{
    return get_activation_factory<CalendarIdentifiers, ICalendarIdentifiersStatics>().Hijri();
}

inline hstring CalendarIdentifiers::Japanese()
{
    return get_activation_factory<CalendarIdentifiers, ICalendarIdentifiersStatics>().Japanese();
}

inline hstring CalendarIdentifiers::Julian()
{
    return get_activation_factory<CalendarIdentifiers, ICalendarIdentifiersStatics>().Julian();
}

inline hstring CalendarIdentifiers::Korean()
{
    return get_activation_factory<CalendarIdentifiers, ICalendarIdentifiersStatics>().Korean();
}

inline hstring CalendarIdentifiers::Taiwan()
{
    return get_activation_factory<CalendarIdentifiers, ICalendarIdentifiersStatics>().Taiwan();
}

inline hstring CalendarIdentifiers::Thai()
{
    return get_activation_factory<CalendarIdentifiers, ICalendarIdentifiersStatics>().Thai();
}

inline hstring CalendarIdentifiers::UmAlQura()
{
    return get_activation_factory<CalendarIdentifiers, ICalendarIdentifiersStatics>().UmAlQura();
}

inline hstring CalendarIdentifiers::Persian()
{
    return get_activation_factory<CalendarIdentifiers, ICalendarIdentifiersStatics2>().Persian();
}

inline hstring CalendarIdentifiers::ChineseLunar()
{
    return get_activation_factory<CalendarIdentifiers, ICalendarIdentifiersStatics3>().ChineseLunar();
}

inline hstring CalendarIdentifiers::JapaneseLunar()
{
    return get_activation_factory<CalendarIdentifiers, ICalendarIdentifiersStatics3>().JapaneseLunar();
}

inline hstring CalendarIdentifiers::KoreanLunar()
{
    return get_activation_factory<CalendarIdentifiers, ICalendarIdentifiersStatics3>().KoreanLunar();
}

inline hstring CalendarIdentifiers::TaiwanLunar()
{
    return get_activation_factory<CalendarIdentifiers, ICalendarIdentifiersStatics3>().TaiwanLunar();
}

inline hstring CalendarIdentifiers::VietnameseLunar()
{
    return get_activation_factory<CalendarIdentifiers, ICalendarIdentifiersStatics3>().VietnameseLunar();
}

inline hstring ClockIdentifiers::TwelveHour()
{
    return get_activation_factory<ClockIdentifiers, IClockIdentifiersStatics>().TwelveHour();
}

inline hstring ClockIdentifiers::TwentyFourHour()
{
    return get_activation_factory<ClockIdentifiers, IClockIdentifiersStatics>().TwentyFourHour();
}

inline hstring CurrencyIdentifiers::AED()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().AED();
}

inline hstring CurrencyIdentifiers::AFN()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().AFN();
}

inline hstring CurrencyIdentifiers::ALL()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().ALL();
}

inline hstring CurrencyIdentifiers::AMD()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().AMD();
}

inline hstring CurrencyIdentifiers::ANG()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().ANG();
}

inline hstring CurrencyIdentifiers::AOA()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().AOA();
}

inline hstring CurrencyIdentifiers::ARS()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().ARS();
}

inline hstring CurrencyIdentifiers::AUD()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().AUD();
}

inline hstring CurrencyIdentifiers::AWG()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().AWG();
}

inline hstring CurrencyIdentifiers::AZN()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().AZN();
}

inline hstring CurrencyIdentifiers::BAM()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().BAM();
}

inline hstring CurrencyIdentifiers::BBD()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().BBD();
}

inline hstring CurrencyIdentifiers::BDT()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().BDT();
}

inline hstring CurrencyIdentifiers::BGN()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().BGN();
}

inline hstring CurrencyIdentifiers::BHD()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().BHD();
}

inline hstring CurrencyIdentifiers::BIF()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().BIF();
}

inline hstring CurrencyIdentifiers::BMD()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().BMD();
}

inline hstring CurrencyIdentifiers::BND()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().BND();
}

inline hstring CurrencyIdentifiers::BOB()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().BOB();
}

inline hstring CurrencyIdentifiers::BRL()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().BRL();
}

inline hstring CurrencyIdentifiers::BSD()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().BSD();
}

inline hstring CurrencyIdentifiers::BTN()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().BTN();
}

inline hstring CurrencyIdentifiers::BWP()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().BWP();
}

inline hstring CurrencyIdentifiers::BYR()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().BYR();
}

inline hstring CurrencyIdentifiers::BZD()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().BZD();
}

inline hstring CurrencyIdentifiers::CAD()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().CAD();
}

inline hstring CurrencyIdentifiers::CDF()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().CDF();
}

inline hstring CurrencyIdentifiers::CHF()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().CHF();
}

inline hstring CurrencyIdentifiers::CLP()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().CLP();
}

inline hstring CurrencyIdentifiers::CNY()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().CNY();
}

inline hstring CurrencyIdentifiers::COP()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().COP();
}

inline hstring CurrencyIdentifiers::CRC()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().CRC();
}

inline hstring CurrencyIdentifiers::CUP()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().CUP();
}

inline hstring CurrencyIdentifiers::CVE()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().CVE();
}

inline hstring CurrencyIdentifiers::CZK()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().CZK();
}

inline hstring CurrencyIdentifiers::DJF()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().DJF();
}

inline hstring CurrencyIdentifiers::DKK()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().DKK();
}

inline hstring CurrencyIdentifiers::DOP()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().DOP();
}

inline hstring CurrencyIdentifiers::DZD()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().DZD();
}

inline hstring CurrencyIdentifiers::EGP()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().EGP();
}

inline hstring CurrencyIdentifiers::ERN()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().ERN();
}

inline hstring CurrencyIdentifiers::ETB()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().ETB();
}

inline hstring CurrencyIdentifiers::EUR()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().EUR();
}

inline hstring CurrencyIdentifiers::FJD()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().FJD();
}

inline hstring CurrencyIdentifiers::FKP()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().FKP();
}

inline hstring CurrencyIdentifiers::GBP()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().GBP();
}

inline hstring CurrencyIdentifiers::GEL()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().GEL();
}

inline hstring CurrencyIdentifiers::GHS()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().GHS();
}

inline hstring CurrencyIdentifiers::GIP()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().GIP();
}

inline hstring CurrencyIdentifiers::GMD()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().GMD();
}

inline hstring CurrencyIdentifiers::GNF()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().GNF();
}

inline hstring CurrencyIdentifiers::GTQ()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().GTQ();
}

inline hstring CurrencyIdentifiers::GYD()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().GYD();
}

inline hstring CurrencyIdentifiers::HKD()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().HKD();
}

inline hstring CurrencyIdentifiers::HNL()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().HNL();
}

inline hstring CurrencyIdentifiers::HRK()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().HRK();
}

inline hstring CurrencyIdentifiers::HTG()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().HTG();
}

inline hstring CurrencyIdentifiers::HUF()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().HUF();
}

inline hstring CurrencyIdentifiers::IDR()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().IDR();
}

inline hstring CurrencyIdentifiers::ILS()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().ILS();
}

inline hstring CurrencyIdentifiers::INR()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().INR();
}

inline hstring CurrencyIdentifiers::IQD()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().IQD();
}

inline hstring CurrencyIdentifiers::IRR()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().IRR();
}

inline hstring CurrencyIdentifiers::ISK()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().ISK();
}

inline hstring CurrencyIdentifiers::JMD()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().JMD();
}

inline hstring CurrencyIdentifiers::JOD()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().JOD();
}

inline hstring CurrencyIdentifiers::JPY()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().JPY();
}

inline hstring CurrencyIdentifiers::KES()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().KES();
}

inline hstring CurrencyIdentifiers::KGS()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().KGS();
}

inline hstring CurrencyIdentifiers::KHR()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().KHR();
}

inline hstring CurrencyIdentifiers::KMF()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().KMF();
}

inline hstring CurrencyIdentifiers::KPW()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().KPW();
}

inline hstring CurrencyIdentifiers::KRW()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().KRW();
}

inline hstring CurrencyIdentifiers::KWD()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().KWD();
}

inline hstring CurrencyIdentifiers::KYD()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().KYD();
}

inline hstring CurrencyIdentifiers::KZT()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().KZT();
}

inline hstring CurrencyIdentifiers::LAK()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().LAK();
}

inline hstring CurrencyIdentifiers::LBP()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().LBP();
}

inline hstring CurrencyIdentifiers::LKR()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().LKR();
}

inline hstring CurrencyIdentifiers::LRD()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().LRD();
}

inline hstring CurrencyIdentifiers::LSL()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().LSL();
}

inline hstring CurrencyIdentifiers::LTL()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().LTL();
}

inline hstring CurrencyIdentifiers::LVL()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().LVL();
}

inline hstring CurrencyIdentifiers::LYD()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().LYD();
}

inline hstring CurrencyIdentifiers::MAD()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().MAD();
}

inline hstring CurrencyIdentifiers::MDL()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().MDL();
}

inline hstring CurrencyIdentifiers::MGA()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().MGA();
}

inline hstring CurrencyIdentifiers::MKD()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().MKD();
}

inline hstring CurrencyIdentifiers::MMK()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().MMK();
}

inline hstring CurrencyIdentifiers::MNT()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().MNT();
}

inline hstring CurrencyIdentifiers::MOP()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().MOP();
}

inline hstring CurrencyIdentifiers::MRO()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().MRO();
}

inline hstring CurrencyIdentifiers::MUR()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().MUR();
}

inline hstring CurrencyIdentifiers::MVR()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().MVR();
}

inline hstring CurrencyIdentifiers::MWK()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().MWK();
}

inline hstring CurrencyIdentifiers::MXN()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().MXN();
}

inline hstring CurrencyIdentifiers::MYR()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().MYR();
}

inline hstring CurrencyIdentifiers::MZN()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().MZN();
}

inline hstring CurrencyIdentifiers::NAD()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().NAD();
}

inline hstring CurrencyIdentifiers::NGN()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().NGN();
}

inline hstring CurrencyIdentifiers::NIO()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().NIO();
}

inline hstring CurrencyIdentifiers::NOK()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().NOK();
}

inline hstring CurrencyIdentifiers::NPR()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().NPR();
}

inline hstring CurrencyIdentifiers::NZD()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().NZD();
}

inline hstring CurrencyIdentifiers::OMR()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().OMR();
}

inline hstring CurrencyIdentifiers::PAB()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().PAB();
}

inline hstring CurrencyIdentifiers::PEN()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().PEN();
}

inline hstring CurrencyIdentifiers::PGK()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().PGK();
}

inline hstring CurrencyIdentifiers::PHP()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().PHP();
}

inline hstring CurrencyIdentifiers::PKR()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().PKR();
}

inline hstring CurrencyIdentifiers::PLN()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().PLN();
}

inline hstring CurrencyIdentifiers::PYG()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().PYG();
}

inline hstring CurrencyIdentifiers::QAR()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().QAR();
}

inline hstring CurrencyIdentifiers::RON()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().RON();
}

inline hstring CurrencyIdentifiers::RSD()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().RSD();
}

inline hstring CurrencyIdentifiers::RUB()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().RUB();
}

inline hstring CurrencyIdentifiers::RWF()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().RWF();
}

inline hstring CurrencyIdentifiers::SAR()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().SAR();
}

inline hstring CurrencyIdentifiers::SBD()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().SBD();
}

inline hstring CurrencyIdentifiers::SCR()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().SCR();
}

inline hstring CurrencyIdentifiers::SDG()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().SDG();
}

inline hstring CurrencyIdentifiers::SEK()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().SEK();
}

inline hstring CurrencyIdentifiers::SGD()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().SGD();
}

inline hstring CurrencyIdentifiers::SHP()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().SHP();
}

inline hstring CurrencyIdentifiers::SLL()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().SLL();
}

inline hstring CurrencyIdentifiers::SOS()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().SOS();
}

inline hstring CurrencyIdentifiers::SRD()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().SRD();
}

inline hstring CurrencyIdentifiers::STD()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().STD();
}

inline hstring CurrencyIdentifiers::SYP()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().SYP();
}

inline hstring CurrencyIdentifiers::SZL()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().SZL();
}

inline hstring CurrencyIdentifiers::THB()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().THB();
}

inline hstring CurrencyIdentifiers::TJS()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().TJS();
}

inline hstring CurrencyIdentifiers::TMT()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().TMT();
}

inline hstring CurrencyIdentifiers::TND()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().TND();
}

inline hstring CurrencyIdentifiers::TOP()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().TOP();
}

inline hstring CurrencyIdentifiers::TRY()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().TRY();
}

inline hstring CurrencyIdentifiers::TTD()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().TTD();
}

inline hstring CurrencyIdentifiers::TWD()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().TWD();
}

inline hstring CurrencyIdentifiers::TZS()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().TZS();
}

inline hstring CurrencyIdentifiers::UAH()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().UAH();
}

inline hstring CurrencyIdentifiers::UGX()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().UGX();
}

inline hstring CurrencyIdentifiers::USD()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().USD();
}

inline hstring CurrencyIdentifiers::UYU()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().UYU();
}

inline hstring CurrencyIdentifiers::UZS()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().UZS();
}

inline hstring CurrencyIdentifiers::VEF()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().VEF();
}

inline hstring CurrencyIdentifiers::VND()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().VND();
}

inline hstring CurrencyIdentifiers::VUV()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().VUV();
}

inline hstring CurrencyIdentifiers::WST()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().WST();
}

inline hstring CurrencyIdentifiers::XAF()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().XAF();
}

inline hstring CurrencyIdentifiers::XCD()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().XCD();
}

inline hstring CurrencyIdentifiers::XOF()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().XOF();
}

inline hstring CurrencyIdentifiers::XPF()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().XPF();
}

inline hstring CurrencyIdentifiers::XXX()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().XXX();
}

inline hstring CurrencyIdentifiers::YER()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().YER();
}

inline hstring CurrencyIdentifiers::ZAR()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().ZAR();
}

inline hstring CurrencyIdentifiers::ZMW()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().ZMW();
}

inline hstring CurrencyIdentifiers::ZWL()
{
    return get_activation_factory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().ZWL();
}

inline GeographicRegion::GeographicRegion() :
    GeographicRegion(activate_instance<GeographicRegion>())
{}

inline GeographicRegion::GeographicRegion(hstring_view geographicRegionCode) :
    GeographicRegion(get_activation_factory<GeographicRegion, IGeographicRegionFactory>().CreateGeographicRegion(geographicRegionCode))
{}

inline bool GeographicRegion::IsSupported(hstring_view geographicRegionCode)
{
    return get_activation_factory<GeographicRegion, IGeographicRegionStatics>().IsSupported(geographicRegionCode);
}

inline Windows::Foundation::Collections::IVectorView<Windows::Globalization::JapanesePhoneme> JapanesePhoneticAnalyzer::GetWords(hstring_view input)
{
    return get_activation_factory<JapanesePhoneticAnalyzer, IJapanesePhoneticAnalyzerStatics>().GetWords(input);
}

inline Windows::Foundation::Collections::IVectorView<Windows::Globalization::JapanesePhoneme> JapanesePhoneticAnalyzer::GetWords(hstring_view input, bool monoRuby)
{
    return get_activation_factory<JapanesePhoneticAnalyzer, IJapanesePhoneticAnalyzerStatics>().GetWords(input, monoRuby);
}

inline Language::Language(hstring_view languageTag) :
    Language(get_activation_factory<Language, ILanguageFactory>().CreateLanguage(languageTag))
{}

inline bool Language::IsWellFormed(hstring_view languageTag)
{
    return get_activation_factory<Language, ILanguageStatics>().IsWellFormed(languageTag);
}

inline hstring Language::CurrentInputMethodLanguageTag()
{
    return get_activation_factory<Language, ILanguageStatics>().CurrentInputMethodLanguageTag();
}

inline bool Language::TrySetInputMethodLanguageTag(hstring_view languageTag)
{
    return get_activation_factory<Language, ILanguageStatics2>().TrySetInputMethodLanguageTag(languageTag);
}

inline hstring NumeralSystemIdentifiers::Arab()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Arab();
}

inline hstring NumeralSystemIdentifiers::ArabExt()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().ArabExt();
}

inline hstring NumeralSystemIdentifiers::Bali()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Bali();
}

inline hstring NumeralSystemIdentifiers::Beng()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Beng();
}

inline hstring NumeralSystemIdentifiers::Cham()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Cham();
}

inline hstring NumeralSystemIdentifiers::Deva()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Deva();
}

inline hstring NumeralSystemIdentifiers::FullWide()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().FullWide();
}

inline hstring NumeralSystemIdentifiers::Gujr()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Gujr();
}

inline hstring NumeralSystemIdentifiers::Guru()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Guru();
}

inline hstring NumeralSystemIdentifiers::HaniDec()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().HaniDec();
}

inline hstring NumeralSystemIdentifiers::Java()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Java();
}

inline hstring NumeralSystemIdentifiers::Kali()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Kali();
}

inline hstring NumeralSystemIdentifiers::Khmr()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Khmr();
}

inline hstring NumeralSystemIdentifiers::Knda()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Knda();
}

inline hstring NumeralSystemIdentifiers::Lana()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Lana();
}

inline hstring NumeralSystemIdentifiers::LanaTham()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().LanaTham();
}

inline hstring NumeralSystemIdentifiers::Laoo()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Laoo();
}

inline hstring NumeralSystemIdentifiers::Latn()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Latn();
}

inline hstring NumeralSystemIdentifiers::Lepc()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Lepc();
}

inline hstring NumeralSystemIdentifiers::Limb()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Limb();
}

inline hstring NumeralSystemIdentifiers::Mlym()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Mlym();
}

inline hstring NumeralSystemIdentifiers::Mong()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Mong();
}

inline hstring NumeralSystemIdentifiers::Mtei()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Mtei();
}

inline hstring NumeralSystemIdentifiers::Mymr()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Mymr();
}

inline hstring NumeralSystemIdentifiers::MymrShan()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().MymrShan();
}

inline hstring NumeralSystemIdentifiers::Nkoo()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Nkoo();
}

inline hstring NumeralSystemIdentifiers::Olck()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Olck();
}

inline hstring NumeralSystemIdentifiers::Orya()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Orya();
}

inline hstring NumeralSystemIdentifiers::Saur()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Saur();
}

inline hstring NumeralSystemIdentifiers::Sund()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Sund();
}

inline hstring NumeralSystemIdentifiers::Talu()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Talu();
}

inline hstring NumeralSystemIdentifiers::TamlDec()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().TamlDec();
}

inline hstring NumeralSystemIdentifiers::Telu()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Telu();
}

inline hstring NumeralSystemIdentifiers::Thai()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Thai();
}

inline hstring NumeralSystemIdentifiers::Tibt()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Tibt();
}

inline hstring NumeralSystemIdentifiers::Vaii()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Vaii();
}

inline hstring NumeralSystemIdentifiers::Brah()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics2>().Brah();
}

inline hstring NumeralSystemIdentifiers::Osma()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics2>().Osma();
}

inline hstring NumeralSystemIdentifiers::MathBold()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics2>().MathBold();
}

inline hstring NumeralSystemIdentifiers::MathDbl()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics2>().MathDbl();
}

inline hstring NumeralSystemIdentifiers::MathSans()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics2>().MathSans();
}

inline hstring NumeralSystemIdentifiers::MathSanb()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics2>().MathSanb();
}

inline hstring NumeralSystemIdentifiers::MathMono()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics2>().MathMono();
}

inline hstring NumeralSystemIdentifiers::ZmthBold()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics2>().ZmthBold();
}

inline hstring NumeralSystemIdentifiers::ZmthDbl()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics2>().ZmthDbl();
}

inline hstring NumeralSystemIdentifiers::ZmthSans()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics2>().ZmthSans();
}

inline hstring NumeralSystemIdentifiers::ZmthSanb()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics2>().ZmthSanb();
}

inline hstring NumeralSystemIdentifiers::ZmthMono()
{
    return get_activation_factory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics2>().ZmthMono();
}

}

}
#pragma warning(pop)
