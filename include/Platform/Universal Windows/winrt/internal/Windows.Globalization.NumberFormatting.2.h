// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Globalization.NumberFormatting.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
#define WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
template <> struct __declspec(uuid("2f13c006-a03a-5f69-b090-75a43e33423e")) __declspec(novtable) IVectorView<hstring> : impl_IVectorView<hstring> {};
#endif

#ifndef WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
#define WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
template <> struct __declspec(uuid("e2fcc7c1-3bfc-5a0b-b2b0-72e769d1cb7e")) __declspec(novtable) IIterable<hstring> : impl_IIterable<hstring> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_2f2d6c29_5473_5f3e_92e7_96572bb990e2
#define WINRT_GENERIC_2f2d6c29_5473_5f3e_92e7_96572bb990e2
template <> struct __declspec(uuid("2f2d6c29-5473-5f3e-92e7-96572bb990e2")) __declspec(novtable) IReference<double> : impl_IReference<double> {};
#endif

#ifndef WINRT_GENERIC_4dda9e24_e69f_5c6a_a0a6_93427365af2a
#define WINRT_GENERIC_4dda9e24_e69f_5c6a_a0a6_93427365af2a
template <> struct __declspec(uuid("4dda9e24-e69f-5c6a-a0a6-93427365af2a")) __declspec(novtable) IReference<int64_t> : impl_IReference<int64_t> {};
#endif

#ifndef WINRT_GENERIC_6755e376_53bb_568b_a11d_17239868309e
#define WINRT_GENERIC_6755e376_53bb_568b_a11d_17239868309e
template <> struct __declspec(uuid("6755e376-53bb-568b-a11d-17239868309e")) __declspec(novtable) IReference<uint64_t> : impl_IReference<uint64_t> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
#define WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
template <> struct __declspec(uuid("8c304ebb-6615-50a4-8829-879ecd443236")) __declspec(novtable) IIterator<hstring> : impl_IIterator<hstring> {};
#endif


}

namespace Windows::Globalization::NumberFormatting {

struct ICurrencyFormatter :
    Windows::Foundation::IInspectable,
    impl::consume<ICurrencyFormatter>,
    impl::require<ICurrencyFormatter, Windows::Globalization::NumberFormatting::INumberFormatter, Windows::Globalization::NumberFormatting::INumberFormatter2, Windows::Globalization::NumberFormatting::INumberFormatterOptions, Windows::Globalization::NumberFormatting::INumberParser>
{
    ICurrencyFormatter(std::nullptr_t = nullptr) noexcept {}
};

struct ICurrencyFormatter2 :
    Windows::Foundation::IInspectable,
    impl::consume<ICurrencyFormatter2>
{
    ICurrencyFormatter2(std::nullptr_t = nullptr) noexcept {}
};

struct ICurrencyFormatterFactory :
    Windows::Foundation::IInspectable,
    impl::consume<ICurrencyFormatterFactory>
{
    ICurrencyFormatterFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IDecimalFormatterFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IDecimalFormatterFactory>
{
    IDecimalFormatterFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IIncrementNumberRounder :
    Windows::Foundation::IInspectable,
    impl::consume<IIncrementNumberRounder>
{
    IIncrementNumberRounder(std::nullptr_t = nullptr) noexcept {}
};

struct INumberFormatter :
    Windows::Foundation::IInspectable,
    impl::consume<INumberFormatter>
{
    INumberFormatter(std::nullptr_t = nullptr) noexcept {}
};

struct INumberFormatter2 :
    Windows::Foundation::IInspectable,
    impl::consume<INumberFormatter2>
{
    INumberFormatter2(std::nullptr_t = nullptr) noexcept {}
};

struct INumberFormatterOptions :
    Windows::Foundation::IInspectable,
    impl::consume<INumberFormatterOptions>
{
    INumberFormatterOptions(std::nullptr_t = nullptr) noexcept {}
};

struct INumberParser :
    Windows::Foundation::IInspectable,
    impl::consume<INumberParser>
{
    INumberParser(std::nullptr_t = nullptr) noexcept {}
};

struct INumberRounder :
    Windows::Foundation::IInspectable,
    impl::consume<INumberRounder>
{
    INumberRounder(std::nullptr_t = nullptr) noexcept {}
};

struct INumberRounderOption :
    Windows::Foundation::IInspectable,
    impl::consume<INumberRounderOption>
{
    INumberRounderOption(std::nullptr_t = nullptr) noexcept {}
};

struct INumeralSystemTranslator :
    Windows::Foundation::IInspectable,
    impl::consume<INumeralSystemTranslator>
{
    INumeralSystemTranslator(std::nullptr_t = nullptr) noexcept {}
};

struct INumeralSystemTranslatorFactory :
    Windows::Foundation::IInspectable,
    impl::consume<INumeralSystemTranslatorFactory>
{
    INumeralSystemTranslatorFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IPercentFormatterFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IPercentFormatterFactory>
{
    IPercentFormatterFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IPermilleFormatterFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IPermilleFormatterFactory>
{
    IPermilleFormatterFactory(std::nullptr_t = nullptr) noexcept {}
};

struct ISignedZeroOption :
    Windows::Foundation::IInspectable,
    impl::consume<ISignedZeroOption>
{
    ISignedZeroOption(std::nullptr_t = nullptr) noexcept {}
};

struct ISignificantDigitsNumberRounder :
    Windows::Foundation::IInspectable,
    impl::consume<ISignificantDigitsNumberRounder>
{
    ISignificantDigitsNumberRounder(std::nullptr_t = nullptr) noexcept {}
};

struct ISignificantDigitsOption :
    Windows::Foundation::IInspectable,
    impl::consume<ISignificantDigitsOption>
{
    ISignificantDigitsOption(std::nullptr_t = nullptr) noexcept {}
};

}

}
