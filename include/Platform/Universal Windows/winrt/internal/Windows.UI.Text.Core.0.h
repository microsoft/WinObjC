// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Text::Core {

struct CoreTextRange;

}

namespace Windows::UI::Text::Core {

using CoreTextRange = ABI::Windows::UI::Text::Core::CoreTextRange;

}

namespace ABI::Windows::UI::Text::Core {

struct ICoreTextCompositionCompletedEventArgs;
struct ICoreTextCompositionSegment;
struct ICoreTextCompositionStartedEventArgs;
struct ICoreTextEditContext;
struct ICoreTextEditContext2;
struct ICoreTextFormatUpdatingEventArgs;
struct ICoreTextLayoutBounds;
struct ICoreTextLayoutRequest;
struct ICoreTextLayoutRequestedEventArgs;
struct ICoreTextSelectionRequest;
struct ICoreTextSelectionRequestedEventArgs;
struct ICoreTextSelectionUpdatingEventArgs;
struct ICoreTextServicesManager;
struct ICoreTextServicesManagerStatics;
struct ICoreTextServicesStatics;
struct ICoreTextTextRequest;
struct ICoreTextTextRequestedEventArgs;
struct ICoreTextTextUpdatingEventArgs;
struct CoreTextCompositionCompletedEventArgs;
struct CoreTextCompositionSegment;
struct CoreTextCompositionStartedEventArgs;
struct CoreTextEditContext;
struct CoreTextFormatUpdatingEventArgs;
struct CoreTextLayoutBounds;
struct CoreTextLayoutRequest;
struct CoreTextLayoutRequestedEventArgs;
struct CoreTextSelectionRequest;
struct CoreTextSelectionRequestedEventArgs;
struct CoreTextSelectionUpdatingEventArgs;
struct CoreTextServicesManager;
struct CoreTextTextRequest;
struct CoreTextTextRequestedEventArgs;
struct CoreTextTextUpdatingEventArgs;

}

namespace Windows::UI::Text::Core {

struct ICoreTextCompositionCompletedEventArgs;
struct ICoreTextCompositionSegment;
struct ICoreTextCompositionStartedEventArgs;
struct ICoreTextEditContext;
struct ICoreTextEditContext2;
struct ICoreTextFormatUpdatingEventArgs;
struct ICoreTextLayoutBounds;
struct ICoreTextLayoutRequest;
struct ICoreTextLayoutRequestedEventArgs;
struct ICoreTextSelectionRequest;
struct ICoreTextSelectionRequestedEventArgs;
struct ICoreTextSelectionUpdatingEventArgs;
struct ICoreTextServicesManager;
struct ICoreTextServicesManagerStatics;
struct ICoreTextServicesStatics;
struct ICoreTextTextRequest;
struct ICoreTextTextRequestedEventArgs;
struct ICoreTextTextUpdatingEventArgs;
struct CoreTextCompositionCompletedEventArgs;
struct CoreTextCompositionSegment;
struct CoreTextCompositionStartedEventArgs;
struct CoreTextEditContext;
struct CoreTextFormatUpdatingEventArgs;
struct CoreTextLayoutBounds;
struct CoreTextLayoutRequest;
struct CoreTextLayoutRequestedEventArgs;
struct CoreTextSelectionRequest;
struct CoreTextSelectionRequestedEventArgs;
struct CoreTextSelectionUpdatingEventArgs;
struct CoreTextServicesConstants;
struct CoreTextServicesManager;
struct CoreTextTextRequest;
struct CoreTextTextRequestedEventArgs;
struct CoreTextTextUpdatingEventArgs;

}

namespace Windows::UI::Text::Core {

template <typename T> struct impl_ICoreTextCompositionCompletedEventArgs;
template <typename T> struct impl_ICoreTextCompositionSegment;
template <typename T> struct impl_ICoreTextCompositionStartedEventArgs;
template <typename T> struct impl_ICoreTextEditContext;
template <typename T> struct impl_ICoreTextEditContext2;
template <typename T> struct impl_ICoreTextFormatUpdatingEventArgs;
template <typename T> struct impl_ICoreTextLayoutBounds;
template <typename T> struct impl_ICoreTextLayoutRequest;
template <typename T> struct impl_ICoreTextLayoutRequestedEventArgs;
template <typename T> struct impl_ICoreTextSelectionRequest;
template <typename T> struct impl_ICoreTextSelectionRequestedEventArgs;
template <typename T> struct impl_ICoreTextSelectionUpdatingEventArgs;
template <typename T> struct impl_ICoreTextServicesManager;
template <typename T> struct impl_ICoreTextServicesManagerStatics;
template <typename T> struct impl_ICoreTextServicesStatics;
template <typename T> struct impl_ICoreTextTextRequest;
template <typename T> struct impl_ICoreTextTextRequestedEventArgs;
template <typename T> struct impl_ICoreTextTextUpdatingEventArgs;

}

namespace Windows::UI::Text::Core {

enum class CoreTextFormatUpdatingReason
{
    None = 0,
    CompositionUnconverted = 1,
    CompositionConverted = 2,
    CompositionTargetUnconverted = 3,
    CompositionTargetConverted = 4,
};

enum class CoreTextFormatUpdatingResult
{
    Succeeded = 0,
    Failed = 1,
};

enum class CoreTextInputPaneDisplayPolicy
{
    Automatic = 0,
    Manual = 1,
};

enum class CoreTextInputScope
{
    Default = 0,
    Url = 1,
    FilePath = 2,
    FileName = 3,
    EmailUserName = 4,
    EmailAddress = 5,
    UserName = 6,
    PersonalFullName = 7,
    PersonalNamePrefix = 8,
    PersonalGivenName = 9,
    PersonalMiddleName = 10,
    PersonalSurname = 11,
    PersonalNameSuffix = 12,
    Address = 13,
    AddressPostalCode = 14,
    AddressStreet = 15,
    AddressStateOrProvince = 16,
    AddressCity = 17,
    AddressCountryName = 18,
    AddressCountryShortName = 19,
    CurrencyAmountAndSymbol = 20,
    CurrencyAmount = 21,
    Date = 22,
    DateMonth = 23,
    DateDay = 24,
    DateYear = 25,
    DateMonthName = 26,
    DateDayName = 27,
    Number = 29,
    SingleCharacter = 30,
    Password = 31,
    TelephoneNumber = 32,
    TelephoneCountryCode = 33,
    TelephoneAreaCode = 34,
    TelephoneLocalNumber = 35,
    Time = 36,
    TimeHour = 37,
    TimeMinuteOrSecond = 38,
    NumberFullWidth = 39,
    AlphanumericHalfWidth = 40,
    AlphanumericFullWidth = 41,
    CurrencyChinese = 42,
    Bopomofo = 43,
    Hiragana = 44,
    KatakanaHalfWidth = 45,
    KatakanaFullWidth = 46,
    Hanja = 47,
    HangulHalfWidth = 48,
    HangulFullWidth = 49,
    Search = 50,
    Formula = 51,
    SearchIncremental = 52,
    ChineseHalfWidth = 53,
    ChineseFullWidth = 54,
    NativeScript = 55,
    Text = 57,
    Chat = 58,
    NameOrPhoneNumber = 59,
    EmailUserNameOrAddress = 60,
    Private = 61,
    Maps = 62,
    PasswordNumeric = 63,
    FormulaNumber = 67,
    ChatWithoutEmoji = 68,
};

enum class CoreTextSelectionUpdatingResult
{
    Succeeded = 0,
    Failed = 1,
};

enum class CoreTextTextUpdatingResult
{
    Succeeded = 0,
    Failed = 1,
};

}

}
