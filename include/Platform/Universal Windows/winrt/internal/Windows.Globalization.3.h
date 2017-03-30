// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Globalization.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Globalization {

struct ApplicationLanguages
{
    ApplicationLanguages() = delete;
    static hstring PrimaryLanguageOverride();
    static void PrimaryLanguageOverride(hstring_view value);
    static Windows::Foundation::Collections::IVectorView<hstring> Languages();
    static Windows::Foundation::Collections::IVectorView<hstring> ManifestLanguages();
};

struct WINRT_EBO Calendar :
    Windows::Globalization::ICalendar,
    impl::require<Calendar, Windows::Globalization::ITimeZoneOnCalendar>
{
    Calendar(std::nullptr_t) noexcept {}
    Calendar();
    Calendar(iterable<hstring> languages, hstring_view calendar, hstring_view clock, hstring_view timeZoneId);
    Calendar(iterable<hstring> languages);
    Calendar(iterable<hstring> languages, hstring_view calendar, hstring_view clock);
};

struct CalendarIdentifiers
{
    CalendarIdentifiers() = delete;
    static hstring Gregorian();
    static hstring Hebrew();
    static hstring Hijri();
    static hstring Japanese();
    static hstring Julian();
    static hstring Korean();
    static hstring Taiwan();
    static hstring Thai();
    static hstring UmAlQura();
    static hstring Persian();
    static hstring ChineseLunar();
    static hstring JapaneseLunar();
    static hstring KoreanLunar();
    static hstring TaiwanLunar();
    static hstring VietnameseLunar();
};

struct ClockIdentifiers
{
    ClockIdentifiers() = delete;
    static hstring TwelveHour();
    static hstring TwentyFourHour();
};

struct CurrencyIdentifiers
{
    CurrencyIdentifiers() = delete;
    static hstring AED();
    static hstring AFN();
    static hstring ALL();
    static hstring AMD();
    static hstring ANG();
    static hstring AOA();
    static hstring ARS();
    static hstring AUD();
    static hstring AWG();
    static hstring AZN();
    static hstring BAM();
    static hstring BBD();
    static hstring BDT();
    static hstring BGN();
    static hstring BHD();
    static hstring BIF();
    static hstring BMD();
    static hstring BND();
    static hstring BOB();
    static hstring BRL();
    static hstring BSD();
    static hstring BTN();
    static hstring BWP();
    static hstring BYR();
    static hstring BZD();
    static hstring CAD();
    static hstring CDF();
    static hstring CHF();
    static hstring CLP();
    static hstring CNY();
    static hstring COP();
    static hstring CRC();
    static hstring CUP();
    static hstring CVE();
    static hstring CZK();
    static hstring DJF();
    static hstring DKK();
    static hstring DOP();
    static hstring DZD();
    static hstring EGP();
    static hstring ERN();
    static hstring ETB();
    static hstring EUR();
    static hstring FJD();
    static hstring FKP();
    static hstring GBP();
    static hstring GEL();
    static hstring GHS();
    static hstring GIP();
    static hstring GMD();
    static hstring GNF();
    static hstring GTQ();
    static hstring GYD();
    static hstring HKD();
    static hstring HNL();
    static hstring HRK();
    static hstring HTG();
    static hstring HUF();
    static hstring IDR();
    static hstring ILS();
    static hstring INR();
    static hstring IQD();
    static hstring IRR();
    static hstring ISK();
    static hstring JMD();
    static hstring JOD();
    static hstring JPY();
    static hstring KES();
    static hstring KGS();
    static hstring KHR();
    static hstring KMF();
    static hstring KPW();
    static hstring KRW();
    static hstring KWD();
    static hstring KYD();
    static hstring KZT();
    static hstring LAK();
    static hstring LBP();
    static hstring LKR();
    static hstring LRD();
    static hstring LSL();
    static hstring LTL();
    static hstring LVL();
    static hstring LYD();
    static hstring MAD();
    static hstring MDL();
    static hstring MGA();
    static hstring MKD();
    static hstring MMK();
    static hstring MNT();
    static hstring MOP();
    static hstring MRO();
    static hstring MUR();
    static hstring MVR();
    static hstring MWK();
    static hstring MXN();
    static hstring MYR();
    static hstring MZN();
    static hstring NAD();
    static hstring NGN();
    static hstring NIO();
    static hstring NOK();
    static hstring NPR();
    static hstring NZD();
    static hstring OMR();
    static hstring PAB();
    static hstring PEN();
    static hstring PGK();
    static hstring PHP();
    static hstring PKR();
    static hstring PLN();
    static hstring PYG();
    static hstring QAR();
    static hstring RON();
    static hstring RSD();
    static hstring RUB();
    static hstring RWF();
    static hstring SAR();
    static hstring SBD();
    static hstring SCR();
    static hstring SDG();
    static hstring SEK();
    static hstring SGD();
    static hstring SHP();
    static hstring SLL();
    static hstring SOS();
    static hstring SRD();
    static hstring STD();
    static hstring SYP();
    static hstring SZL();
    static hstring THB();
    static hstring TJS();
    static hstring TMT();
    static hstring TND();
    static hstring TOP();
    static hstring TRY();
    static hstring TTD();
    static hstring TWD();
    static hstring TZS();
    static hstring UAH();
    static hstring UGX();
    static hstring USD();
    static hstring UYU();
    static hstring UZS();
    static hstring VEF();
    static hstring VND();
    static hstring VUV();
    static hstring WST();
    static hstring XAF();
    static hstring XCD();
    static hstring XOF();
    static hstring XPF();
    static hstring XXX();
    static hstring YER();
    static hstring ZAR();
    static hstring ZMW();
    static hstring ZWL();
};

struct WINRT_EBO GeographicRegion :
    Windows::Globalization::IGeographicRegion
{
    GeographicRegion(std::nullptr_t) noexcept {}
    GeographicRegion();
    GeographicRegion(hstring_view geographicRegionCode);
    static bool IsSupported(hstring_view geographicRegionCode);
};

struct WINRT_EBO JapanesePhoneme :
    Windows::Globalization::IJapanesePhoneme
{
    JapanesePhoneme(std::nullptr_t) noexcept {}
};

struct JapanesePhoneticAnalyzer
{
    JapanesePhoneticAnalyzer() = delete;
    static Windows::Foundation::Collections::IVectorView<Windows::Globalization::JapanesePhoneme> GetWords(hstring_view input);
    static Windows::Foundation::Collections::IVectorView<Windows::Globalization::JapanesePhoneme> GetWords(hstring_view input, bool monoRuby);
};

struct WINRT_EBO Language :
    Windows::Globalization::ILanguage,
    impl::require<Language, Windows::Globalization::ILanguageExtensionSubtags>
{
    Language(std::nullptr_t) noexcept {}
    Language(hstring_view languageTag);
    static bool IsWellFormed(hstring_view languageTag);
    static hstring CurrentInputMethodLanguageTag();
    static bool TrySetInputMethodLanguageTag(hstring_view languageTag);
};

struct NumeralSystemIdentifiers
{
    NumeralSystemIdentifiers() = delete;
    static hstring Arab();
    static hstring ArabExt();
    static hstring Bali();
    static hstring Beng();
    static hstring Cham();
    static hstring Deva();
    static hstring FullWide();
    static hstring Gujr();
    static hstring Guru();
    static hstring HaniDec();
    static hstring Java();
    static hstring Kali();
    static hstring Khmr();
    static hstring Knda();
    static hstring Lana();
    static hstring LanaTham();
    static hstring Laoo();
    static hstring Latn();
    static hstring Lepc();
    static hstring Limb();
    static hstring Mlym();
    static hstring Mong();
    static hstring Mtei();
    static hstring Mymr();
    static hstring MymrShan();
    static hstring Nkoo();
    static hstring Olck();
    static hstring Orya();
    static hstring Saur();
    static hstring Sund();
    static hstring Talu();
    static hstring TamlDec();
    static hstring Telu();
    static hstring Thai();
    static hstring Tibt();
    static hstring Vaii();
    static hstring Brah();
    static hstring Osma();
    static hstring MathBold();
    static hstring MathDbl();
    static hstring MathSans();
    static hstring MathSanb();
    static hstring MathMono();
    static hstring ZmthBold();
    static hstring ZmthDbl();
    static hstring ZmthSans();
    static hstring ZmthSanb();
    static hstring ZmthMono();
};

}

}
