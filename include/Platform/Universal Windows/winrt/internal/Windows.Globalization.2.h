// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Globalization.1.h"

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

#ifndef WINRT_GENERIC_4cdc5bd0_d4aa_5b60_bf25_7144905050f9
#define WINRT_GENERIC_4cdc5bd0_d4aa_5b60_bf25_7144905050f9
template <> struct __declspec(uuid("4cdc5bd0-d4aa-5b60-bf25-7144905050f9")) __declspec(novtable) IVectorView<Windows::Globalization::JapanesePhoneme> : impl_IVectorView<Windows::Globalization::JapanesePhoneme> {};
#endif

#ifndef WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
#define WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
template <> struct __declspec(uuid("8c304ebb-6615-50a4-8829-879ecd443236")) __declspec(novtable) IIterator<hstring> : impl_IIterator<hstring> {};
#endif

#ifndef WINRT_GENERIC_f15ca7e7_69a8_564d_9c20_4da75a773432
#define WINRT_GENERIC_f15ca7e7_69a8_564d_9c20_4da75a773432
template <> struct __declspec(uuid("f15ca7e7-69a8-564d-9c20-4da75a773432")) __declspec(novtable) IIterator<Windows::Globalization::JapanesePhoneme> : impl_IIterator<Windows::Globalization::JapanesePhoneme> {};
#endif

#ifndef WINRT_GENERIC_1aad17cb_1829_5236_8aef_0b75f8dfd7a6
#define WINRT_GENERIC_1aad17cb_1829_5236_8aef_0b75f8dfd7a6
template <> struct __declspec(uuid("1aad17cb-1829-5236-8aef-0b75f8dfd7a6")) __declspec(novtable) IIterable<Windows::Globalization::JapanesePhoneme> : impl_IIterable<Windows::Globalization::JapanesePhoneme> {};
#endif


}

namespace Windows::Globalization {

struct IApplicationLanguagesStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IApplicationLanguagesStatics>
{
    IApplicationLanguagesStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ICalendar :
    Windows::Foundation::IInspectable,
    impl::consume<ICalendar>
{
    ICalendar(std::nullptr_t = nullptr) noexcept {}
};

struct ICalendarFactory :
    Windows::Foundation::IInspectable,
    impl::consume<ICalendarFactory>
{
    ICalendarFactory(std::nullptr_t = nullptr) noexcept {}
};

struct ICalendarFactory2 :
    Windows::Foundation::IInspectable,
    impl::consume<ICalendarFactory2>
{
    ICalendarFactory2(std::nullptr_t = nullptr) noexcept {}
};

struct ICalendarIdentifiersStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ICalendarIdentifiersStatics>
{
    ICalendarIdentifiersStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ICalendarIdentifiersStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<ICalendarIdentifiersStatics2>
{
    ICalendarIdentifiersStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct ICalendarIdentifiersStatics3 :
    Windows::Foundation::IInspectable,
    impl::consume<ICalendarIdentifiersStatics3>
{
    ICalendarIdentifiersStatics3(std::nullptr_t = nullptr) noexcept {}
};

struct IClockIdentifiersStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IClockIdentifiersStatics>
{
    IClockIdentifiersStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ICurrencyIdentifiersStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ICurrencyIdentifiersStatics>
{
    ICurrencyIdentifiersStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IGeographicRegion :
    Windows::Foundation::IInspectable,
    impl::consume<IGeographicRegion>
{
    IGeographicRegion(std::nullptr_t = nullptr) noexcept {}
};

struct IGeographicRegionFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IGeographicRegionFactory>
{
    IGeographicRegionFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IGeographicRegionStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IGeographicRegionStatics>
{
    IGeographicRegionStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IJapanesePhoneme :
    Windows::Foundation::IInspectable,
    impl::consume<IJapanesePhoneme>
{
    IJapanesePhoneme(std::nullptr_t = nullptr) noexcept {}
};

struct IJapanesePhoneticAnalyzerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IJapanesePhoneticAnalyzerStatics>
{
    IJapanesePhoneticAnalyzerStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ILanguage :
    Windows::Foundation::IInspectable,
    impl::consume<ILanguage>
{
    ILanguage(std::nullptr_t = nullptr) noexcept {}
};

struct ILanguageExtensionSubtags :
    Windows::Foundation::IInspectable,
    impl::consume<ILanguageExtensionSubtags>
{
    ILanguageExtensionSubtags(std::nullptr_t = nullptr) noexcept {}
};

struct ILanguageFactory :
    Windows::Foundation::IInspectable,
    impl::consume<ILanguageFactory>
{
    ILanguageFactory(std::nullptr_t = nullptr) noexcept {}
};

struct ILanguageStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ILanguageStatics>
{
    ILanguageStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ILanguageStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<ILanguageStatics2>
{
    ILanguageStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct INumeralSystemIdentifiersStatics :
    Windows::Foundation::IInspectable,
    impl::consume<INumeralSystemIdentifiersStatics>
{
    INumeralSystemIdentifiersStatics(std::nullptr_t = nullptr) noexcept {}
};

struct INumeralSystemIdentifiersStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<INumeralSystemIdentifiersStatics2>
{
    INumeralSystemIdentifiersStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct ITimeZoneOnCalendar :
    Windows::Foundation::IInspectable,
    impl::consume<ITimeZoneOnCalendar>
{
    ITimeZoneOnCalendar(std::nullptr_t = nullptr) noexcept {}
};

}

}
