// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Globalization.NumberFormatting.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Globalization::NumberFormatting {

struct __declspec(uuid("11730ca5-4b00-41b2-b332-73b12a497d54")) __declspec(novtable) ICurrencyFormatter : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Currency(hstring * value) = 0;
    virtual HRESULT __stdcall put_Currency(hstring value) = 0;
};

struct __declspec(uuid("072c2f1d-e7ba-4197-920e-247c92f7dea6")) __declspec(novtable) ICurrencyFormatter2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Mode(winrt::Windows::Globalization::NumberFormatting::CurrencyFormatterMode * value) = 0;
    virtual HRESULT __stdcall put_Mode(winrt::Windows::Globalization::NumberFormatting::CurrencyFormatterMode value) = 0;
    virtual HRESULT __stdcall abi_ApplyRoundingForCurrency(winrt::Windows::Globalization::NumberFormatting::RoundingAlgorithm roundingAlgorithm) = 0;
};

struct __declspec(uuid("86c7537e-b938-4aa2-84b0-2c33dc5b1450")) __declspec(novtable) ICurrencyFormatterFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateCurrencyFormatterCode(hstring currencyCode, Windows::Globalization::NumberFormatting::ICurrencyFormatter ** result) = 0;
    virtual HRESULT __stdcall abi_CreateCurrencyFormatterCodeContext(hstring currencyCode, Windows::Foundation::Collections::IIterable<hstring> * languages, hstring geographicRegion, Windows::Globalization::NumberFormatting::ICurrencyFormatter ** result) = 0;
};

struct __declspec(uuid("0d018c9a-e393-46b8-b830-7a69c8f89fbb")) __declspec(novtable) IDecimalFormatterFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateDecimalFormatter(Windows::Foundation::Collections::IIterable<hstring> * languages, hstring geographicRegion, Windows::Globalization::NumberFormatting::INumberFormatter ** result) = 0;
};

struct __declspec(uuid("70a64ff8-66ab-4155-9da1-739e46764543")) __declspec(novtable) IIncrementNumberRounder : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RoundingAlgorithm(winrt::Windows::Globalization::NumberFormatting::RoundingAlgorithm * value) = 0;
    virtual HRESULT __stdcall put_RoundingAlgorithm(winrt::Windows::Globalization::NumberFormatting::RoundingAlgorithm value) = 0;
    virtual HRESULT __stdcall get_Increment(double * value) = 0;
    virtual HRESULT __stdcall put_Increment(double value) = 0;
};

struct __declspec(uuid("a5007c49-7676-4db7-8631-1b6ff265caa9")) __declspec(novtable) INumberFormatter : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FormatInt(int64_t value, hstring * result) = 0;
    virtual HRESULT __stdcall abi_FormatUInt(uint64_t value, hstring * result) = 0;
    virtual HRESULT __stdcall abi_FormatDouble(double value, hstring * result) = 0;
};

struct __declspec(uuid("d4a8c1f0-80d0-4b0d-a89e-882c1e8f8310")) __declspec(novtable) INumberFormatter2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FormatInt(int64_t value, hstring * result) = 0;
    virtual HRESULT __stdcall abi_FormatUInt(uint64_t value, hstring * result) = 0;
    virtual HRESULT __stdcall abi_FormatDouble(double value, hstring * result) = 0;
};

struct __declspec(uuid("80332d21-aee1-4a39-baa2-07ed8c96daf6")) __declspec(novtable) INumberFormatterOptions : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Languages(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_GeographicRegion(hstring * value) = 0;
    virtual HRESULT __stdcall get_IntegerDigits(int32_t * value) = 0;
    virtual HRESULT __stdcall put_IntegerDigits(int32_t value) = 0;
    virtual HRESULT __stdcall get_FractionDigits(int32_t * value) = 0;
    virtual HRESULT __stdcall put_FractionDigits(int32_t value) = 0;
    virtual HRESULT __stdcall get_IsGrouped(bool * value) = 0;
    virtual HRESULT __stdcall put_IsGrouped(bool value) = 0;
    virtual HRESULT __stdcall get_IsDecimalPointAlwaysDisplayed(bool * value) = 0;
    virtual HRESULT __stdcall put_IsDecimalPointAlwaysDisplayed(bool value) = 0;
    virtual HRESULT __stdcall get_NumeralSystem(hstring * value) = 0;
    virtual HRESULT __stdcall put_NumeralSystem(hstring value) = 0;
    virtual HRESULT __stdcall get_ResolvedLanguage(hstring * value) = 0;
    virtual HRESULT __stdcall get_ResolvedGeographicRegion(hstring * value) = 0;
};

struct __declspec(uuid("e6659412-4a13-4a53-83a1-392fbe4cff9f")) __declspec(novtable) INumberParser : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ParseInt(hstring text, Windows::Foundation::IReference<int64_t> ** result) = 0;
    virtual HRESULT __stdcall abi_ParseUInt(hstring text, Windows::Foundation::IReference<uint64_t> ** result) = 0;
    virtual HRESULT __stdcall abi_ParseDouble(hstring text, Windows::Foundation::IReference<double> ** result) = 0;
};

struct __declspec(uuid("5473c375-38ed-4631-b80c-ef34fc48b7f5")) __declspec(novtable) INumberRounder : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RoundInt32(int32_t value, int32_t * result) = 0;
    virtual HRESULT __stdcall abi_RoundUInt32(uint32_t value, uint32_t * result) = 0;
    virtual HRESULT __stdcall abi_RoundInt64(int64_t value, int64_t * result) = 0;
    virtual HRESULT __stdcall abi_RoundUInt64(uint64_t value, uint64_t * result) = 0;
    virtual HRESULT __stdcall abi_RoundSingle(float value, float * result) = 0;
    virtual HRESULT __stdcall abi_RoundDouble(double value, double * result) = 0;
};

struct __declspec(uuid("3b088433-646f-4efe-8d48-66eb2e49e736")) __declspec(novtable) INumberRounderOption : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_NumberRounder(Windows::Globalization::NumberFormatting::INumberRounder ** value) = 0;
    virtual HRESULT __stdcall put_NumberRounder(Windows::Globalization::NumberFormatting::INumberRounder * value) = 0;
};

struct __declspec(uuid("28f5bc2c-8c23-4234-ad2e-fa5a3a426e9b")) __declspec(novtable) INumeralSystemTranslator : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Languages(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_ResolvedLanguage(hstring * value) = 0;
    virtual HRESULT __stdcall get_NumeralSystem(hstring * value) = 0;
    virtual HRESULT __stdcall put_NumeralSystem(hstring value) = 0;
    virtual HRESULT __stdcall abi_TranslateNumerals(hstring value, hstring * result) = 0;
};

struct __declspec(uuid("9630c8da-36ef-4d88-a85c-6f0d98d620a6")) __declspec(novtable) INumeralSystemTranslatorFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Foundation::Collections::IIterable<hstring> * languages, Windows::Globalization::NumberFormatting::INumeralSystemTranslator ** result) = 0;
};

struct __declspec(uuid("b7828aef-fed4-4018-a6e2-e09961e03765")) __declspec(novtable) IPercentFormatterFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreatePercentFormatter(Windows::Foundation::Collections::IIterable<hstring> * languages, hstring geographicRegion, Windows::Globalization::NumberFormatting::INumberFormatter ** result) = 0;
};

struct __declspec(uuid("2b37b4ac-e638-4ed5-a998-62f6b06a49ae")) __declspec(novtable) IPermilleFormatterFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreatePermilleFormatter(Windows::Foundation::Collections::IIterable<hstring> * languages, hstring geographicRegion, Windows::Globalization::NumberFormatting::INumberFormatter ** result) = 0;
};

struct __declspec(uuid("fd1cdd31-0a3c-49c4-a642-96a1564f4f30")) __declspec(novtable) ISignedZeroOption : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsZeroSigned(bool * value) = 0;
    virtual HRESULT __stdcall put_IsZeroSigned(bool value) = 0;
};

struct __declspec(uuid("f5941bca-6646-4913-8c76-1b191ff94dfd")) __declspec(novtable) ISignificantDigitsNumberRounder : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RoundingAlgorithm(winrt::Windows::Globalization::NumberFormatting::RoundingAlgorithm * value) = 0;
    virtual HRESULT __stdcall put_RoundingAlgorithm(winrt::Windows::Globalization::NumberFormatting::RoundingAlgorithm value) = 0;
    virtual HRESULT __stdcall get_SignificantDigits(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_SignificantDigits(uint32_t value) = 0;
};

struct __declspec(uuid("1d4dfcdd-2d43-4ee8-bbf1-c1b26a711a58")) __declspec(novtable) ISignificantDigitsOption : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SignificantDigits(int32_t * value) = 0;
    virtual HRESULT __stdcall put_SignificantDigits(int32_t value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Globalization::NumberFormatting::CurrencyFormatter> { using default_interface = Windows::Globalization::NumberFormatting::ICurrencyFormatter; };
template <> struct traits<Windows::Globalization::NumberFormatting::DecimalFormatter> { using default_interface = Windows::Globalization::NumberFormatting::INumberFormatter; };
template <> struct traits<Windows::Globalization::NumberFormatting::IncrementNumberRounder> { using default_interface = Windows::Globalization::NumberFormatting::INumberRounder; };
template <> struct traits<Windows::Globalization::NumberFormatting::NumeralSystemTranslator> { using default_interface = Windows::Globalization::NumberFormatting::INumeralSystemTranslator; };
template <> struct traits<Windows::Globalization::NumberFormatting::PercentFormatter> { using default_interface = Windows::Globalization::NumberFormatting::INumberFormatter; };
template <> struct traits<Windows::Globalization::NumberFormatting::PermilleFormatter> { using default_interface = Windows::Globalization::NumberFormatting::INumberFormatter; };
template <> struct traits<Windows::Globalization::NumberFormatting::SignificantDigitsNumberRounder> { using default_interface = Windows::Globalization::NumberFormatting::INumberRounder; };

}

namespace Windows::Globalization::NumberFormatting {

template <typename D>
struct WINRT_EBO impl_ICurrencyFormatter
{
    hstring Currency() const;
    [[deprecated("Currency may be read-only for releases after Windows 8.1. Instead, use a new CurrencyFormatter.")]] void Currency(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_ICurrencyFormatter2
{
    Windows::Globalization::NumberFormatting::CurrencyFormatterMode Mode() const;
    void Mode(Windows::Globalization::NumberFormatting::CurrencyFormatterMode value) const;
    void ApplyRoundingForCurrency(Windows::Globalization::NumberFormatting::RoundingAlgorithm roundingAlgorithm) const;
};

template <typename D>
struct WINRT_EBO impl_ICurrencyFormatterFactory
{
    Windows::Globalization::NumberFormatting::CurrencyFormatter CreateCurrencyFormatterCode(hstring_view currencyCode) const;
    Windows::Globalization::NumberFormatting::CurrencyFormatter CreateCurrencyFormatterCodeContext(hstring_view currencyCode, iterable<hstring> languages, hstring_view geographicRegion) const;
};

template <typename D>
struct WINRT_EBO impl_IDecimalFormatterFactory
{
    Windows::Globalization::NumberFormatting::DecimalFormatter CreateDecimalFormatter(iterable<hstring> languages, hstring_view geographicRegion) const;
};

template <typename D>
struct WINRT_EBO impl_IIncrementNumberRounder
{
    Windows::Globalization::NumberFormatting::RoundingAlgorithm RoundingAlgorithm() const;
    void RoundingAlgorithm(Windows::Globalization::NumberFormatting::RoundingAlgorithm value) const;
    double Increment() const;
    void Increment(double value) const;
};

template <typename D>
struct WINRT_EBO impl_INumberFormatter
{
    hstring Format(int64_t value) const;
    hstring Format(uint64_t value) const;
    hstring Format(double value) const;
};

template <typename D>
struct WINRT_EBO impl_INumberFormatter2
{
    hstring FormatInt(int64_t value) const;
    hstring FormatUInt(uint64_t value) const;
    hstring FormatDouble(double value) const;
};

template <typename D>
struct WINRT_EBO impl_INumberFormatterOptions
{
    Windows::Foundation::Collections::IVectorView<hstring> Languages() const;
    hstring GeographicRegion() const;
    int32_t IntegerDigits() const;
    void IntegerDigits(int32_t value) const;
    int32_t FractionDigits() const;
    void FractionDigits(int32_t value) const;
    bool IsGrouped() const;
    void IsGrouped(bool value) const;
    bool IsDecimalPointAlwaysDisplayed() const;
    void IsDecimalPointAlwaysDisplayed(bool value) const;
    hstring NumeralSystem() const;
    void NumeralSystem(hstring_view value) const;
    hstring ResolvedLanguage() const;
    hstring ResolvedGeographicRegion() const;
};

template <typename D>
struct WINRT_EBO impl_INumberParser
{
    Windows::Foundation::IReference<int64_t> ParseInt(hstring_view text) const;
    Windows::Foundation::IReference<uint64_t> ParseUInt(hstring_view text) const;
    Windows::Foundation::IReference<double> ParseDouble(hstring_view text) const;
};

template <typename D>
struct WINRT_EBO impl_INumberRounder
{
    int32_t RoundInt32(int32_t value) const;
    uint32_t RoundUInt32(uint32_t value) const;
    int64_t RoundInt64(int64_t value) const;
    uint64_t RoundUInt64(uint64_t value) const;
    float RoundSingle(float value) const;
    double RoundDouble(double value) const;
};

template <typename D>
struct WINRT_EBO impl_INumberRounderOption
{
    Windows::Globalization::NumberFormatting::INumberRounder NumberRounder() const;
    void NumberRounder(const Windows::Globalization::NumberFormatting::INumberRounder & value) const;
};

template <typename D>
struct WINRT_EBO impl_INumeralSystemTranslator
{
    Windows::Foundation::Collections::IVectorView<hstring> Languages() const;
    hstring ResolvedLanguage() const;
    hstring NumeralSystem() const;
    void NumeralSystem(hstring_view value) const;
    hstring TranslateNumerals(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_INumeralSystemTranslatorFactory
{
    Windows::Globalization::NumberFormatting::NumeralSystemTranslator Create(iterable<hstring> languages) const;
};

template <typename D>
struct WINRT_EBO impl_IPercentFormatterFactory
{
    Windows::Globalization::NumberFormatting::PercentFormatter CreatePercentFormatter(iterable<hstring> languages, hstring_view geographicRegion) const;
};

template <typename D>
struct WINRT_EBO impl_IPermilleFormatterFactory
{
    Windows::Globalization::NumberFormatting::PermilleFormatter CreatePermilleFormatter(iterable<hstring> languages, hstring_view geographicRegion) const;
};

template <typename D>
struct WINRT_EBO impl_ISignedZeroOption
{
    bool IsZeroSigned() const;
    void IsZeroSigned(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_ISignificantDigitsNumberRounder
{
    Windows::Globalization::NumberFormatting::RoundingAlgorithm RoundingAlgorithm() const;
    void RoundingAlgorithm(Windows::Globalization::NumberFormatting::RoundingAlgorithm value) const;
    uint32_t SignificantDigits() const;
    void SignificantDigits(uint32_t value) const;
};

template <typename D>
struct WINRT_EBO impl_ISignificantDigitsOption
{
    int32_t SignificantDigits() const;
    void SignificantDigits(int32_t value) const;
};

}

namespace impl {

template <> struct traits<Windows::Globalization::NumberFormatting::ICurrencyFormatter>
{
    using abi = ABI::Windows::Globalization::NumberFormatting::ICurrencyFormatter;
    template <typename D> using consume = Windows::Globalization::NumberFormatting::impl_ICurrencyFormatter<D>;
};

template <> struct traits<Windows::Globalization::NumberFormatting::ICurrencyFormatter2>
{
    using abi = ABI::Windows::Globalization::NumberFormatting::ICurrencyFormatter2;
    template <typename D> using consume = Windows::Globalization::NumberFormatting::impl_ICurrencyFormatter2<D>;
};

template <> struct traits<Windows::Globalization::NumberFormatting::ICurrencyFormatterFactory>
{
    using abi = ABI::Windows::Globalization::NumberFormatting::ICurrencyFormatterFactory;
    template <typename D> using consume = Windows::Globalization::NumberFormatting::impl_ICurrencyFormatterFactory<D>;
};

template <> struct traits<Windows::Globalization::NumberFormatting::IDecimalFormatterFactory>
{
    using abi = ABI::Windows::Globalization::NumberFormatting::IDecimalFormatterFactory;
    template <typename D> using consume = Windows::Globalization::NumberFormatting::impl_IDecimalFormatterFactory<D>;
};

template <> struct traits<Windows::Globalization::NumberFormatting::IIncrementNumberRounder>
{
    using abi = ABI::Windows::Globalization::NumberFormatting::IIncrementNumberRounder;
    template <typename D> using consume = Windows::Globalization::NumberFormatting::impl_IIncrementNumberRounder<D>;
};

template <> struct traits<Windows::Globalization::NumberFormatting::INumberFormatter>
{
    using abi = ABI::Windows::Globalization::NumberFormatting::INumberFormatter;
    template <typename D> using consume = Windows::Globalization::NumberFormatting::impl_INumberFormatter<D>;
};

template <> struct traits<Windows::Globalization::NumberFormatting::INumberFormatter2>
{
    using abi = ABI::Windows::Globalization::NumberFormatting::INumberFormatter2;
    template <typename D> using consume = Windows::Globalization::NumberFormatting::impl_INumberFormatter2<D>;
};

template <> struct traits<Windows::Globalization::NumberFormatting::INumberFormatterOptions>
{
    using abi = ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions;
    template <typename D> using consume = Windows::Globalization::NumberFormatting::impl_INumberFormatterOptions<D>;
};

template <> struct traits<Windows::Globalization::NumberFormatting::INumberParser>
{
    using abi = ABI::Windows::Globalization::NumberFormatting::INumberParser;
    template <typename D> using consume = Windows::Globalization::NumberFormatting::impl_INumberParser<D>;
};

template <> struct traits<Windows::Globalization::NumberFormatting::INumberRounder>
{
    using abi = ABI::Windows::Globalization::NumberFormatting::INumberRounder;
    template <typename D> using consume = Windows::Globalization::NumberFormatting::impl_INumberRounder<D>;
};

template <> struct traits<Windows::Globalization::NumberFormatting::INumberRounderOption>
{
    using abi = ABI::Windows::Globalization::NumberFormatting::INumberRounderOption;
    template <typename D> using consume = Windows::Globalization::NumberFormatting::impl_INumberRounderOption<D>;
};

template <> struct traits<Windows::Globalization::NumberFormatting::INumeralSystemTranslator>
{
    using abi = ABI::Windows::Globalization::NumberFormatting::INumeralSystemTranslator;
    template <typename D> using consume = Windows::Globalization::NumberFormatting::impl_INumeralSystemTranslator<D>;
};

template <> struct traits<Windows::Globalization::NumberFormatting::INumeralSystemTranslatorFactory>
{
    using abi = ABI::Windows::Globalization::NumberFormatting::INumeralSystemTranslatorFactory;
    template <typename D> using consume = Windows::Globalization::NumberFormatting::impl_INumeralSystemTranslatorFactory<D>;
};

template <> struct traits<Windows::Globalization::NumberFormatting::IPercentFormatterFactory>
{
    using abi = ABI::Windows::Globalization::NumberFormatting::IPercentFormatterFactory;
    template <typename D> using consume = Windows::Globalization::NumberFormatting::impl_IPercentFormatterFactory<D>;
};

template <> struct traits<Windows::Globalization::NumberFormatting::IPermilleFormatterFactory>
{
    using abi = ABI::Windows::Globalization::NumberFormatting::IPermilleFormatterFactory;
    template <typename D> using consume = Windows::Globalization::NumberFormatting::impl_IPermilleFormatterFactory<D>;
};

template <> struct traits<Windows::Globalization::NumberFormatting::ISignedZeroOption>
{
    using abi = ABI::Windows::Globalization::NumberFormatting::ISignedZeroOption;
    template <typename D> using consume = Windows::Globalization::NumberFormatting::impl_ISignedZeroOption<D>;
};

template <> struct traits<Windows::Globalization::NumberFormatting::ISignificantDigitsNumberRounder>
{
    using abi = ABI::Windows::Globalization::NumberFormatting::ISignificantDigitsNumberRounder;
    template <typename D> using consume = Windows::Globalization::NumberFormatting::impl_ISignificantDigitsNumberRounder<D>;
};

template <> struct traits<Windows::Globalization::NumberFormatting::ISignificantDigitsOption>
{
    using abi = ABI::Windows::Globalization::NumberFormatting::ISignificantDigitsOption;
    template <typename D> using consume = Windows::Globalization::NumberFormatting::impl_ISignificantDigitsOption<D>;
};

template <> struct traits<Windows::Globalization::NumberFormatting::CurrencyFormatter>
{
    using abi = ABI::Windows::Globalization::NumberFormatting::CurrencyFormatter;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Globalization.NumberFormatting.CurrencyFormatter"; }
};

template <> struct traits<Windows::Globalization::NumberFormatting::DecimalFormatter>
{
    using abi = ABI::Windows::Globalization::NumberFormatting::DecimalFormatter;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Globalization.NumberFormatting.DecimalFormatter"; }
};

template <> struct traits<Windows::Globalization::NumberFormatting::IncrementNumberRounder>
{
    using abi = ABI::Windows::Globalization::NumberFormatting::IncrementNumberRounder;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Globalization.NumberFormatting.IncrementNumberRounder"; }
};

template <> struct traits<Windows::Globalization::NumberFormatting::NumeralSystemTranslator>
{
    using abi = ABI::Windows::Globalization::NumberFormatting::NumeralSystemTranslator;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Globalization.NumberFormatting.NumeralSystemTranslator"; }
};

template <> struct traits<Windows::Globalization::NumberFormatting::PercentFormatter>
{
    using abi = ABI::Windows::Globalization::NumberFormatting::PercentFormatter;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Globalization.NumberFormatting.PercentFormatter"; }
};

template <> struct traits<Windows::Globalization::NumberFormatting::PermilleFormatter>
{
    using abi = ABI::Windows::Globalization::NumberFormatting::PermilleFormatter;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Globalization.NumberFormatting.PermilleFormatter"; }
};

template <> struct traits<Windows::Globalization::NumberFormatting::SignificantDigitsNumberRounder>
{
    using abi = ABI::Windows::Globalization::NumberFormatting::SignificantDigitsNumberRounder;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Globalization.NumberFormatting.SignificantDigitsNumberRounder"; }
};

}

}
