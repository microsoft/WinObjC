// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Globalization.NumberFormatting.3.h"
#include "Windows.Globalization.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Globalization::NumberFormatting::ICurrencyFormatter> : produce_base<D, Windows::Globalization::NumberFormatting::ICurrencyFormatter>
{
    HRESULT __stdcall get_Currency(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Currency());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Currency(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Currency(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Globalization::NumberFormatting::ICurrencyFormatter2> : produce_base<D, Windows::Globalization::NumberFormatting::ICurrencyFormatter2>
{
    HRESULT __stdcall get_Mode(Windows::Globalization::NumberFormatting::CurrencyFormatterMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Mode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Mode(Windows::Globalization::NumberFormatting::CurrencyFormatterMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Mode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ApplyRoundingForCurrency(Windows::Globalization::NumberFormatting::RoundingAlgorithm roundingAlgorithm) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ApplyRoundingForCurrency(roundingAlgorithm);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Globalization::NumberFormatting::ICurrencyFormatterFactory> : produce_base<D, Windows::Globalization::NumberFormatting::ICurrencyFormatterFactory>
{
    HRESULT __stdcall abi_CreateCurrencyFormatterCode(impl::abi_arg_in<hstring> currencyCode, impl::abi_arg_out<Windows::Globalization::NumberFormatting::ICurrencyFormatter> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateCurrencyFormatterCode(*reinterpret_cast<const hstring *>(&currencyCode)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateCurrencyFormatterCodeContext(impl::abi_arg_in<hstring> currencyCode, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> languages, impl::abi_arg_in<hstring> geographicRegion, impl::abi_arg_out<Windows::Globalization::NumberFormatting::ICurrencyFormatter> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateCurrencyFormatterCodeContext(*reinterpret_cast<const hstring *>(&currencyCode), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&languages), *reinterpret_cast<const hstring *>(&geographicRegion)));
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
struct produce<D, Windows::Globalization::NumberFormatting::IDecimalFormatterFactory> : produce_base<D, Windows::Globalization::NumberFormatting::IDecimalFormatterFactory>
{
    HRESULT __stdcall abi_CreateDecimalFormatter(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> languages, impl::abi_arg_in<hstring> geographicRegion, impl::abi_arg_out<Windows::Globalization::NumberFormatting::INumberFormatter> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateDecimalFormatter(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&languages), *reinterpret_cast<const hstring *>(&geographicRegion)));
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
struct produce<D, Windows::Globalization::NumberFormatting::IIncrementNumberRounder> : produce_base<D, Windows::Globalization::NumberFormatting::IIncrementNumberRounder>
{
    HRESULT __stdcall get_RoundingAlgorithm(Windows::Globalization::NumberFormatting::RoundingAlgorithm * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RoundingAlgorithm());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RoundingAlgorithm(Windows::Globalization::NumberFormatting::RoundingAlgorithm value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RoundingAlgorithm(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Increment(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Increment());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Increment(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Increment(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Globalization::NumberFormatting::INumberFormatter> : produce_base<D, Windows::Globalization::NumberFormatting::INumberFormatter>
{
    HRESULT __stdcall abi_FormatInt(int64_t value, impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Format(value));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FormatUInt(uint64_t value, impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Format(value));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FormatDouble(double value, impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Format(value));
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
struct produce<D, Windows::Globalization::NumberFormatting::INumberFormatter2> : produce_base<D, Windows::Globalization::NumberFormatting::INumberFormatter2>
{
    HRESULT __stdcall abi_FormatInt(int64_t value, impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FormatInt(value));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FormatUInt(uint64_t value, impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FormatUInt(value));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FormatDouble(double value, impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FormatDouble(value));
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
struct produce<D, Windows::Globalization::NumberFormatting::INumberFormatterOptions> : produce_base<D, Windows::Globalization::NumberFormatting::INumberFormatterOptions>
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

    HRESULT __stdcall get_IntegerDigits(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IntegerDigits());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IntegerDigits(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IntegerDigits(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FractionDigits(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FractionDigits());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FractionDigits(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FractionDigits(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsGrouped(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsGrouped());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsGrouped(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsGrouped(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsDecimalPointAlwaysDisplayed(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDecimalPointAlwaysDisplayed());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsDecimalPointAlwaysDisplayed(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsDecimalPointAlwaysDisplayed(value);
            return S_OK;
        }
        catch (...)
        {
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
struct produce<D, Windows::Globalization::NumberFormatting::INumberParser> : produce_base<D, Windows::Globalization::NumberFormatting::INumberParser>
{
    HRESULT __stdcall abi_ParseInt(impl::abi_arg_in<hstring> text, impl::abi_arg_out<Windows::Foundation::IReference<int64_t>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ParseInt(*reinterpret_cast<const hstring *>(&text)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ParseUInt(impl::abi_arg_in<hstring> text, impl::abi_arg_out<Windows::Foundation::IReference<uint64_t>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ParseUInt(*reinterpret_cast<const hstring *>(&text)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ParseDouble(impl::abi_arg_in<hstring> text, impl::abi_arg_out<Windows::Foundation::IReference<double>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ParseDouble(*reinterpret_cast<const hstring *>(&text)));
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
struct produce<D, Windows::Globalization::NumberFormatting::INumberRounder> : produce_base<D, Windows::Globalization::NumberFormatting::INumberRounder>
{
    HRESULT __stdcall abi_RoundInt32(int32_t value, int32_t * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RoundInt32(value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RoundUInt32(uint32_t value, uint32_t * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RoundUInt32(value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RoundInt64(int64_t value, int64_t * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RoundInt64(value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RoundUInt64(uint64_t value, uint64_t * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RoundUInt64(value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RoundSingle(float value, float * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RoundSingle(value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RoundDouble(double value, double * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RoundDouble(value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Globalization::NumberFormatting::INumberRounderOption> : produce_base<D, Windows::Globalization::NumberFormatting::INumberRounderOption>
{
    HRESULT __stdcall get_NumberRounder(impl::abi_arg_out<Windows::Globalization::NumberFormatting::INumberRounder> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NumberRounder());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_NumberRounder(impl::abi_arg_in<Windows::Globalization::NumberFormatting::INumberRounder> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NumberRounder(*reinterpret_cast<const Windows::Globalization::NumberFormatting::INumberRounder *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Globalization::NumberFormatting::INumeralSystemTranslator> : produce_base<D, Windows::Globalization::NumberFormatting::INumeralSystemTranslator>
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

    HRESULT __stdcall abi_TranslateNumerals(impl::abi_arg_in<hstring> value, impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TranslateNumerals(*reinterpret_cast<const hstring *>(&value)));
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
struct produce<D, Windows::Globalization::NumberFormatting::INumeralSystemTranslatorFactory> : produce_base<D, Windows::Globalization::NumberFormatting::INumeralSystemTranslatorFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> languages, impl::abi_arg_out<Windows::Globalization::NumberFormatting::INumeralSystemTranslator> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&languages)));
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
struct produce<D, Windows::Globalization::NumberFormatting::IPercentFormatterFactory> : produce_base<D, Windows::Globalization::NumberFormatting::IPercentFormatterFactory>
{
    HRESULT __stdcall abi_CreatePercentFormatter(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> languages, impl::abi_arg_in<hstring> geographicRegion, impl::abi_arg_out<Windows::Globalization::NumberFormatting::INumberFormatter> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreatePercentFormatter(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&languages), *reinterpret_cast<const hstring *>(&geographicRegion)));
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
struct produce<D, Windows::Globalization::NumberFormatting::IPermilleFormatterFactory> : produce_base<D, Windows::Globalization::NumberFormatting::IPermilleFormatterFactory>
{
    HRESULT __stdcall abi_CreatePermilleFormatter(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> languages, impl::abi_arg_in<hstring> geographicRegion, impl::abi_arg_out<Windows::Globalization::NumberFormatting::INumberFormatter> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreatePermilleFormatter(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&languages), *reinterpret_cast<const hstring *>(&geographicRegion)));
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
struct produce<D, Windows::Globalization::NumberFormatting::ISignedZeroOption> : produce_base<D, Windows::Globalization::NumberFormatting::ISignedZeroOption>
{
    HRESULT __stdcall get_IsZeroSigned(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsZeroSigned());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsZeroSigned(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsZeroSigned(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Globalization::NumberFormatting::ISignificantDigitsNumberRounder> : produce_base<D, Windows::Globalization::NumberFormatting::ISignificantDigitsNumberRounder>
{
    HRESULT __stdcall get_RoundingAlgorithm(Windows::Globalization::NumberFormatting::RoundingAlgorithm * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RoundingAlgorithm());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RoundingAlgorithm(Windows::Globalization::NumberFormatting::RoundingAlgorithm value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RoundingAlgorithm(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SignificantDigits(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SignificantDigits());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SignificantDigits(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SignificantDigits(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Globalization::NumberFormatting::ISignificantDigitsOption> : produce_base<D, Windows::Globalization::NumberFormatting::ISignificantDigitsOption>
{
    HRESULT __stdcall get_SignificantDigits(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SignificantDigits());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SignificantDigits(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SignificantDigits(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Globalization::NumberFormatting {

template <typename D> int32_t impl_INumberRounder<D>::RoundInt32(int32_t value) const
{
    int32_t result {};
    check_hresult(WINRT_SHIM(INumberRounder)->abi_RoundInt32(value, &result));
    return result;
}

template <typename D> uint32_t impl_INumberRounder<D>::RoundUInt32(uint32_t value) const
{
    uint32_t result {};
    check_hresult(WINRT_SHIM(INumberRounder)->abi_RoundUInt32(value, &result));
    return result;
}

template <typename D> int64_t impl_INumberRounder<D>::RoundInt64(int64_t value) const
{
    int64_t result {};
    check_hresult(WINRT_SHIM(INumberRounder)->abi_RoundInt64(value, &result));
    return result;
}

template <typename D> uint64_t impl_INumberRounder<D>::RoundUInt64(uint64_t value) const
{
    uint64_t result {};
    check_hresult(WINRT_SHIM(INumberRounder)->abi_RoundUInt64(value, &result));
    return result;
}

template <typename D> float impl_INumberRounder<D>::RoundSingle(float value) const
{
    float result {};
    check_hresult(WINRT_SHIM(INumberRounder)->abi_RoundSingle(value, &result));
    return result;
}

template <typename D> double impl_INumberRounder<D>::RoundDouble(double value) const
{
    double result {};
    check_hresult(WINRT_SHIM(INumberRounder)->abi_RoundDouble(value, &result));
    return result;
}

template <typename D> Windows::Globalization::NumberFormatting::RoundingAlgorithm impl_ISignificantDigitsNumberRounder<D>::RoundingAlgorithm() const
{
    Windows::Globalization::NumberFormatting::RoundingAlgorithm value {};
    check_hresult(WINRT_SHIM(ISignificantDigitsNumberRounder)->get_RoundingAlgorithm(&value));
    return value;
}

template <typename D> void impl_ISignificantDigitsNumberRounder<D>::RoundingAlgorithm(Windows::Globalization::NumberFormatting::RoundingAlgorithm value) const
{
    check_hresult(WINRT_SHIM(ISignificantDigitsNumberRounder)->put_RoundingAlgorithm(value));
}

template <typename D> uint32_t impl_ISignificantDigitsNumberRounder<D>::SignificantDigits() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ISignificantDigitsNumberRounder)->get_SignificantDigits(&value));
    return value;
}

template <typename D> void impl_ISignificantDigitsNumberRounder<D>::SignificantDigits(uint32_t value) const
{
    check_hresult(WINRT_SHIM(ISignificantDigitsNumberRounder)->put_SignificantDigits(value));
}

template <typename D> Windows::Globalization::NumberFormatting::RoundingAlgorithm impl_IIncrementNumberRounder<D>::RoundingAlgorithm() const
{
    Windows::Globalization::NumberFormatting::RoundingAlgorithm value {};
    check_hresult(WINRT_SHIM(IIncrementNumberRounder)->get_RoundingAlgorithm(&value));
    return value;
}

template <typename D> void impl_IIncrementNumberRounder<D>::RoundingAlgorithm(Windows::Globalization::NumberFormatting::RoundingAlgorithm value) const
{
    check_hresult(WINRT_SHIM(IIncrementNumberRounder)->put_RoundingAlgorithm(value));
}

template <typename D> double impl_IIncrementNumberRounder<D>::Increment() const
{
    double value {};
    check_hresult(WINRT_SHIM(IIncrementNumberRounder)->get_Increment(&value));
    return value;
}

template <typename D> void impl_IIncrementNumberRounder<D>::Increment(double value) const
{
    check_hresult(WINRT_SHIM(IIncrementNumberRounder)->put_Increment(value));
}

template <typename D> hstring impl_INumberFormatter<D>::Format(int64_t value) const
{
    hstring result;
    check_hresult(WINRT_SHIM(INumberFormatter)->abi_FormatInt(value, put_abi(result)));
    return result;
}

template <typename D> hstring impl_INumberFormatter<D>::Format(uint64_t value) const
{
    hstring result;
    check_hresult(WINRT_SHIM(INumberFormatter)->abi_FormatUInt(value, put_abi(result)));
    return result;
}

template <typename D> hstring impl_INumberFormatter<D>::Format(double value) const
{
    hstring result;
    check_hresult(WINRT_SHIM(INumberFormatter)->abi_FormatDouble(value, put_abi(result)));
    return result;
}

template <typename D> hstring impl_INumberFormatter2<D>::FormatInt(int64_t value) const
{
    hstring result;
    check_hresult(WINRT_SHIM(INumberFormatter2)->abi_FormatInt(value, put_abi(result)));
    return result;
}

template <typename D> hstring impl_INumberFormatter2<D>::FormatUInt(uint64_t value) const
{
    hstring result;
    check_hresult(WINRT_SHIM(INumberFormatter2)->abi_FormatUInt(value, put_abi(result)));
    return result;
}

template <typename D> hstring impl_INumberFormatter2<D>::FormatDouble(double value) const
{
    hstring result;
    check_hresult(WINRT_SHIM(INumberFormatter2)->abi_FormatDouble(value, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IReference<int64_t> impl_INumberParser<D>::ParseInt(hstring_view text) const
{
    Windows::Foundation::IReference<int64_t> result;
    check_hresult(WINRT_SHIM(INumberParser)->abi_ParseInt(get_abi(text), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IReference<uint64_t> impl_INumberParser<D>::ParseUInt(hstring_view text) const
{
    Windows::Foundation::IReference<uint64_t> result;
    check_hresult(WINRT_SHIM(INumberParser)->abi_ParseUInt(get_abi(text), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IReference<double> impl_INumberParser<D>::ParseDouble(hstring_view text) const
{
    Windows::Foundation::IReference<double> result;
    check_hresult(WINRT_SHIM(INumberParser)->abi_ParseDouble(get_abi(text), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_INumberFormatterOptions<D>::Languages() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(INumberFormatterOptions)->get_Languages(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumberFormatterOptions<D>::GeographicRegion() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumberFormatterOptions)->get_GeographicRegion(put_abi(value)));
    return value;
}

template <typename D> int32_t impl_INumberFormatterOptions<D>::IntegerDigits() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(INumberFormatterOptions)->get_IntegerDigits(&value));
    return value;
}

template <typename D> void impl_INumberFormatterOptions<D>::IntegerDigits(int32_t value) const
{
    check_hresult(WINRT_SHIM(INumberFormatterOptions)->put_IntegerDigits(value));
}

template <typename D> int32_t impl_INumberFormatterOptions<D>::FractionDigits() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(INumberFormatterOptions)->get_FractionDigits(&value));
    return value;
}

template <typename D> void impl_INumberFormatterOptions<D>::FractionDigits(int32_t value) const
{
    check_hresult(WINRT_SHIM(INumberFormatterOptions)->put_FractionDigits(value));
}

template <typename D> bool impl_INumberFormatterOptions<D>::IsGrouped() const
{
    bool value {};
    check_hresult(WINRT_SHIM(INumberFormatterOptions)->get_IsGrouped(&value));
    return value;
}

template <typename D> void impl_INumberFormatterOptions<D>::IsGrouped(bool value) const
{
    check_hresult(WINRT_SHIM(INumberFormatterOptions)->put_IsGrouped(value));
}

template <typename D> bool impl_INumberFormatterOptions<D>::IsDecimalPointAlwaysDisplayed() const
{
    bool value {};
    check_hresult(WINRT_SHIM(INumberFormatterOptions)->get_IsDecimalPointAlwaysDisplayed(&value));
    return value;
}

template <typename D> void impl_INumberFormatterOptions<D>::IsDecimalPointAlwaysDisplayed(bool value) const
{
    check_hresult(WINRT_SHIM(INumberFormatterOptions)->put_IsDecimalPointAlwaysDisplayed(value));
}

template <typename D> hstring impl_INumberFormatterOptions<D>::NumeralSystem() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumberFormatterOptions)->get_NumeralSystem(put_abi(value)));
    return value;
}

template <typename D> void impl_INumberFormatterOptions<D>::NumeralSystem(hstring_view value) const
{
    check_hresult(WINRT_SHIM(INumberFormatterOptions)->put_NumeralSystem(get_abi(value)));
}

template <typename D> hstring impl_INumberFormatterOptions<D>::ResolvedLanguage() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumberFormatterOptions)->get_ResolvedLanguage(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumberFormatterOptions<D>::ResolvedGeographicRegion() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumberFormatterOptions)->get_ResolvedGeographicRegion(put_abi(value)));
    return value;
}

template <typename D> int32_t impl_ISignificantDigitsOption<D>::SignificantDigits() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ISignificantDigitsOption)->get_SignificantDigits(&value));
    return value;
}

template <typename D> void impl_ISignificantDigitsOption<D>::SignificantDigits(int32_t value) const
{
    check_hresult(WINRT_SHIM(ISignificantDigitsOption)->put_SignificantDigits(value));
}

template <typename D> Windows::Globalization::NumberFormatting::INumberRounder impl_INumberRounderOption<D>::NumberRounder() const
{
    Windows::Globalization::NumberFormatting::INumberRounder value;
    check_hresult(WINRT_SHIM(INumberRounderOption)->get_NumberRounder(put_abi(value)));
    return value;
}

template <typename D> void impl_INumberRounderOption<D>::NumberRounder(const Windows::Globalization::NumberFormatting::INumberRounder & value) const
{
    check_hresult(WINRT_SHIM(INumberRounderOption)->put_NumberRounder(get_abi(value)));
}

template <typename D> bool impl_ISignedZeroOption<D>::IsZeroSigned() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISignedZeroOption)->get_IsZeroSigned(&value));
    return value;
}

template <typename D> void impl_ISignedZeroOption<D>::IsZeroSigned(bool value) const
{
    check_hresult(WINRT_SHIM(ISignedZeroOption)->put_IsZeroSigned(value));
}

template <typename D> Windows::Globalization::NumberFormatting::DecimalFormatter impl_IDecimalFormatterFactory<D>::CreateDecimalFormatter(iterable<hstring> languages, hstring_view geographicRegion) const
{
    Windows::Globalization::NumberFormatting::DecimalFormatter result { nullptr };
    check_hresult(WINRT_SHIM(IDecimalFormatterFactory)->abi_CreateDecimalFormatter(get_abi(languages), get_abi(geographicRegion), put_abi(result)));
    return result;
}

template <typename D> Windows::Globalization::NumberFormatting::PercentFormatter impl_IPercentFormatterFactory<D>::CreatePercentFormatter(iterable<hstring> languages, hstring_view geographicRegion) const
{
    Windows::Globalization::NumberFormatting::PercentFormatter result { nullptr };
    check_hresult(WINRT_SHIM(IPercentFormatterFactory)->abi_CreatePercentFormatter(get_abi(languages), get_abi(geographicRegion), put_abi(result)));
    return result;
}

template <typename D> Windows::Globalization::NumberFormatting::PermilleFormatter impl_IPermilleFormatterFactory<D>::CreatePermilleFormatter(iterable<hstring> languages, hstring_view geographicRegion) const
{
    Windows::Globalization::NumberFormatting::PermilleFormatter result { nullptr };
    check_hresult(WINRT_SHIM(IPermilleFormatterFactory)->abi_CreatePermilleFormatter(get_abi(languages), get_abi(geographicRegion), put_abi(result)));
    return result;
}

template <typename D> Windows::Globalization::NumberFormatting::CurrencyFormatter impl_ICurrencyFormatterFactory<D>::CreateCurrencyFormatterCode(hstring_view currencyCode) const
{
    Windows::Globalization::NumberFormatting::CurrencyFormatter result { nullptr };
    check_hresult(WINRT_SHIM(ICurrencyFormatterFactory)->abi_CreateCurrencyFormatterCode(get_abi(currencyCode), put_abi(result)));
    return result;
}

template <typename D> Windows::Globalization::NumberFormatting::CurrencyFormatter impl_ICurrencyFormatterFactory<D>::CreateCurrencyFormatterCodeContext(hstring_view currencyCode, iterable<hstring> languages, hstring_view geographicRegion) const
{
    Windows::Globalization::NumberFormatting::CurrencyFormatter result { nullptr };
    check_hresult(WINRT_SHIM(ICurrencyFormatterFactory)->abi_CreateCurrencyFormatterCodeContext(get_abi(currencyCode), get_abi(languages), get_abi(geographicRegion), put_abi(result)));
    return result;
}

template <typename D> hstring impl_ICurrencyFormatter<D>::Currency() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICurrencyFormatter)->get_Currency(put_abi(value)));
    return value;
}

template <typename D> void impl_ICurrencyFormatter<D>::Currency(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ICurrencyFormatter)->put_Currency(get_abi(value)));
}

template <typename D> Windows::Globalization::NumberFormatting::CurrencyFormatterMode impl_ICurrencyFormatter2<D>::Mode() const
{
    Windows::Globalization::NumberFormatting::CurrencyFormatterMode value {};
    check_hresult(WINRT_SHIM(ICurrencyFormatter2)->get_Mode(&value));
    return value;
}

template <typename D> void impl_ICurrencyFormatter2<D>::Mode(Windows::Globalization::NumberFormatting::CurrencyFormatterMode value) const
{
    check_hresult(WINRT_SHIM(ICurrencyFormatter2)->put_Mode(value));
}

template <typename D> void impl_ICurrencyFormatter2<D>::ApplyRoundingForCurrency(Windows::Globalization::NumberFormatting::RoundingAlgorithm roundingAlgorithm) const
{
    check_hresult(WINRT_SHIM(ICurrencyFormatter2)->abi_ApplyRoundingForCurrency(roundingAlgorithm));
}

template <typename D> Windows::Globalization::NumberFormatting::NumeralSystemTranslator impl_INumeralSystemTranslatorFactory<D>::Create(iterable<hstring> languages) const
{
    Windows::Globalization::NumberFormatting::NumeralSystemTranslator result { nullptr };
    check_hresult(WINRT_SHIM(INumeralSystemTranslatorFactory)->abi_Create(get_abi(languages), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_INumeralSystemTranslator<D>::Languages() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(INumeralSystemTranslator)->get_Languages(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemTranslator<D>::ResolvedLanguage() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemTranslator)->get_ResolvedLanguage(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemTranslator<D>::NumeralSystem() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INumeralSystemTranslator)->get_NumeralSystem(put_abi(value)));
    return value;
}

template <typename D> void impl_INumeralSystemTranslator<D>::NumeralSystem(hstring_view value) const
{
    check_hresult(WINRT_SHIM(INumeralSystemTranslator)->put_NumeralSystem(get_abi(value)));
}

template <typename D> hstring impl_INumeralSystemTranslator<D>::TranslateNumerals(hstring_view value) const
{
    hstring result;
    check_hresult(WINRT_SHIM(INumeralSystemTranslator)->abi_TranslateNumerals(get_abi(value), put_abi(result)));
    return result;
}

inline CurrencyFormatter::CurrencyFormatter(hstring_view currencyCode) :
    CurrencyFormatter(get_activation_factory<CurrencyFormatter, ICurrencyFormatterFactory>().CreateCurrencyFormatterCode(currencyCode))
{}

inline CurrencyFormatter::CurrencyFormatter(hstring_view currencyCode, iterable<hstring> languages, hstring_view geographicRegion) :
    CurrencyFormatter(get_activation_factory<CurrencyFormatter, ICurrencyFormatterFactory>().CreateCurrencyFormatterCodeContext(currencyCode, languages, geographicRegion))
{}

inline DecimalFormatter::DecimalFormatter() :
    DecimalFormatter(activate_instance<DecimalFormatter>())
{}

inline DecimalFormatter::DecimalFormatter(iterable<hstring> languages, hstring_view geographicRegion) :
    DecimalFormatter(get_activation_factory<DecimalFormatter, IDecimalFormatterFactory>().CreateDecimalFormatter(languages, geographicRegion))
{}

inline IncrementNumberRounder::IncrementNumberRounder() :
    IncrementNumberRounder(activate_instance<IncrementNumberRounder>())
{}

inline NumeralSystemTranslator::NumeralSystemTranslator() :
    NumeralSystemTranslator(activate_instance<NumeralSystemTranslator>())
{}

inline NumeralSystemTranslator::NumeralSystemTranslator(iterable<hstring> languages) :
    NumeralSystemTranslator(get_activation_factory<NumeralSystemTranslator, INumeralSystemTranslatorFactory>().Create(languages))
{}

inline PercentFormatter::PercentFormatter() :
    PercentFormatter(activate_instance<PercentFormatter>())
{}

inline PercentFormatter::PercentFormatter(iterable<hstring> languages, hstring_view geographicRegion) :
    PercentFormatter(get_activation_factory<PercentFormatter, IPercentFormatterFactory>().CreatePercentFormatter(languages, geographicRegion))
{}

inline PermilleFormatter::PermilleFormatter() :
    PermilleFormatter(activate_instance<PermilleFormatter>())
{}

inline PermilleFormatter::PermilleFormatter(iterable<hstring> languages, hstring_view geographicRegion) :
    PermilleFormatter(get_activation_factory<PermilleFormatter, IPermilleFormatterFactory>().CreatePermilleFormatter(languages, geographicRegion))
{}

inline SignificantDigitsNumberRounder::SignificantDigitsNumberRounder() :
    SignificantDigitsNumberRounder(activate_instance<SignificantDigitsNumberRounder>())
{}

}

}
#pragma warning(pop)
