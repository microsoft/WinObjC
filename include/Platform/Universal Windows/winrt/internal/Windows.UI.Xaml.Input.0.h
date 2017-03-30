// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Xaml::Input {

struct DoubleTappedEventHandler;
struct HoldingEventHandler;
struct IAccessKeyDisplayDismissedEventArgs;
struct IAccessKeyDisplayRequestedEventArgs;
struct IAccessKeyInvokedEventArgs;
struct IAccessKeyManager;
struct IAccessKeyManagerStatics;
struct ICommand;
struct IContextRequestedEventArgs;
struct IDoubleTappedRoutedEventArgs;
struct IFocusManager;
struct IFocusManagerStatics;
struct IFocusManagerStatics2;
struct IFocusManagerStatics3;
struct IHoldingRoutedEventArgs;
struct IInertiaExpansionBehavior;
struct IInertiaRotationBehavior;
struct IInertiaTranslationBehavior;
struct IInputScope;
struct IInputScopeName;
struct IInputScopeNameFactory;
struct IKeyRoutedEventArgs;
struct IKeyRoutedEventArgs2;
struct IKeyRoutedEventArgs3;
struct IManipulationCompletedRoutedEventArgs;
struct IManipulationDeltaRoutedEventArgs;
struct IManipulationInertiaStartingRoutedEventArgs;
struct IManipulationPivot;
struct IManipulationPivotFactory;
struct IManipulationStartedRoutedEventArgs;
struct IManipulationStartedRoutedEventArgsFactory;
struct IManipulationStartingRoutedEventArgs;
struct IPointer;
struct IPointerRoutedEventArgs;
struct IRightTappedRoutedEventArgs;
struct ITappedRoutedEventArgs;
struct KeyEventHandler;
struct ManipulationCompletedEventHandler;
struct ManipulationDeltaEventHandler;
struct ManipulationInertiaStartingEventHandler;
struct ManipulationStartedEventHandler;
struct ManipulationStartingEventHandler;
struct PointerEventHandler;
struct RightTappedEventHandler;
struct TappedEventHandler;
struct AccessKeyDisplayDismissedEventArgs;
struct AccessKeyDisplayRequestedEventArgs;
struct AccessKeyInvokedEventArgs;
struct AccessKeyManager;
struct ContextRequestedEventArgs;
struct DoubleTappedRoutedEventArgs;
struct FocusManager;
struct HoldingRoutedEventArgs;
struct InertiaExpansionBehavior;
struct InertiaRotationBehavior;
struct InertiaTranslationBehavior;
struct InputScope;
struct InputScopeName;
struct KeyRoutedEventArgs;
struct ManipulationCompletedRoutedEventArgs;
struct ManipulationDeltaRoutedEventArgs;
struct ManipulationInertiaStartingRoutedEventArgs;
struct ManipulationPivot;
struct ManipulationStartedRoutedEventArgs;
struct ManipulationStartingRoutedEventArgs;
struct Pointer;
struct PointerRoutedEventArgs;
struct RightTappedRoutedEventArgs;
struct TappedRoutedEventArgs;

}

namespace Windows::UI::Xaml::Input {

struct DoubleTappedEventHandler;
struct HoldingEventHandler;
struct KeyEventHandler;
struct ManipulationCompletedEventHandler;
struct ManipulationDeltaEventHandler;
struct ManipulationInertiaStartingEventHandler;
struct ManipulationStartedEventHandler;
struct ManipulationStartingEventHandler;
struct PointerEventHandler;
struct RightTappedEventHandler;
struct TappedEventHandler;
struct IAccessKeyDisplayDismissedEventArgs;
struct IAccessKeyDisplayRequestedEventArgs;
struct IAccessKeyInvokedEventArgs;
struct IAccessKeyManager;
struct IAccessKeyManagerStatics;
struct ICommand;
struct IContextRequestedEventArgs;
struct IDoubleTappedRoutedEventArgs;
struct IFocusManager;
struct IFocusManagerStatics;
struct IFocusManagerStatics2;
struct IFocusManagerStatics3;
struct IHoldingRoutedEventArgs;
struct IInertiaExpansionBehavior;
struct IInertiaRotationBehavior;
struct IInertiaTranslationBehavior;
struct IInputScope;
struct IInputScopeName;
struct IInputScopeNameFactory;
struct IKeyRoutedEventArgs;
struct IKeyRoutedEventArgs2;
struct IKeyRoutedEventArgs3;
struct IManipulationCompletedRoutedEventArgs;
struct IManipulationDeltaRoutedEventArgs;
struct IManipulationInertiaStartingRoutedEventArgs;
struct IManipulationPivot;
struct IManipulationPivotFactory;
struct IManipulationStartedRoutedEventArgs;
struct IManipulationStartedRoutedEventArgsFactory;
struct IManipulationStartingRoutedEventArgs;
struct IPointer;
struct IPointerRoutedEventArgs;
struct IRightTappedRoutedEventArgs;
struct ITappedRoutedEventArgs;
struct AccessKeyDisplayDismissedEventArgs;
struct AccessKeyDisplayRequestedEventArgs;
struct AccessKeyInvokedEventArgs;
struct AccessKeyManager;
struct ContextRequestedEventArgs;
struct DoubleTappedRoutedEventArgs;
struct FocusManager;
struct HoldingRoutedEventArgs;
struct InertiaExpansionBehavior;
struct InertiaRotationBehavior;
struct InertiaTranslationBehavior;
struct InputScope;
struct InputScopeName;
struct KeyRoutedEventArgs;
struct ManipulationCompletedRoutedEventArgs;
struct ManipulationDeltaRoutedEventArgs;
struct ManipulationInertiaStartingRoutedEventArgs;
struct ManipulationPivot;
struct ManipulationStartedRoutedEventArgs;
struct ManipulationStartingRoutedEventArgs;
struct Pointer;
struct PointerRoutedEventArgs;
struct RightTappedRoutedEventArgs;
struct TappedRoutedEventArgs;

}

namespace Windows::UI::Xaml::Input {

template <typename T> struct impl_IAccessKeyDisplayDismissedEventArgs;
template <typename T> struct impl_IAccessKeyDisplayRequestedEventArgs;
template <typename T> struct impl_IAccessKeyInvokedEventArgs;
template <typename T> struct impl_IAccessKeyManager;
template <typename T> struct impl_IAccessKeyManagerStatics;
template <typename T> struct impl_ICommand;
template <typename T> struct impl_IContextRequestedEventArgs;
template <typename T> struct impl_IDoubleTappedRoutedEventArgs;
template <typename T> struct impl_IFocusManager;
template <typename T> struct impl_IFocusManagerStatics;
template <typename T> struct impl_IFocusManagerStatics2;
template <typename T> struct impl_IFocusManagerStatics3;
template <typename T> struct impl_IHoldingRoutedEventArgs;
template <typename T> struct impl_IInertiaExpansionBehavior;
template <typename T> struct impl_IInertiaRotationBehavior;
template <typename T> struct impl_IInertiaTranslationBehavior;
template <typename T> struct impl_IInputScope;
template <typename T> struct impl_IInputScopeName;
template <typename T> struct impl_IInputScopeNameFactory;
template <typename T> struct impl_IKeyRoutedEventArgs;
template <typename T> struct impl_IKeyRoutedEventArgs2;
template <typename T> struct impl_IKeyRoutedEventArgs3;
template <typename T> struct impl_IManipulationCompletedRoutedEventArgs;
template <typename T> struct impl_IManipulationDeltaRoutedEventArgs;
template <typename T> struct impl_IManipulationInertiaStartingRoutedEventArgs;
template <typename T> struct impl_IManipulationPivot;
template <typename T> struct impl_IManipulationPivotFactory;
template <typename T> struct impl_IManipulationStartedRoutedEventArgs;
template <typename T> struct impl_IManipulationStartedRoutedEventArgsFactory;
template <typename T> struct impl_IManipulationStartingRoutedEventArgs;
template <typename T> struct impl_IPointer;
template <typename T> struct impl_IPointerRoutedEventArgs;
template <typename T> struct impl_IRightTappedRoutedEventArgs;
template <typename T> struct impl_ITappedRoutedEventArgs;
template <typename T> struct impl_DoubleTappedEventHandler;
template <typename T> struct impl_HoldingEventHandler;
template <typename T> struct impl_KeyEventHandler;
template <typename T> struct impl_ManipulationCompletedEventHandler;
template <typename T> struct impl_ManipulationDeltaEventHandler;
template <typename T> struct impl_ManipulationInertiaStartingEventHandler;
template <typename T> struct impl_ManipulationStartedEventHandler;
template <typename T> struct impl_ManipulationStartingEventHandler;
template <typename T> struct impl_PointerEventHandler;
template <typename T> struct impl_RightTappedEventHandler;
template <typename T> struct impl_TappedEventHandler;

}

namespace Windows::UI::Xaml::Input {

enum class FocusNavigationDirection
{
    Next = 0,
    Previous = 1,
    Up = 2,
    Down = 3,
    Left = 4,
    Right = 5,
    None = 6,
};

enum class InputScopeNameValue
{
    Default = 0,
    Url = 1,
    EmailSmtpAddress = 5,
    PersonalFullName = 7,
    CurrencyAmountAndSymbol = 20,
    CurrencyAmount = 21,
    DateMonthNumber = 23,
    DateDayNumber = 24,
    DateYear = 25,
    Digits = 28,
    Number = 29,
    Password = 31,
    TelephoneNumber = 32,
    TelephoneCountryCode = 33,
    TelephoneAreaCode = 34,
    TelephoneLocalNumber = 35,
    TimeHour = 37,
    TimeMinutesOrSeconds = 38,
    NumberFullWidth = 39,
    AlphanumericHalfWidth = 40,
    AlphanumericFullWidth = 41,
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
    EmailNameOrAddress = 60,
    Maps = 62,
    NumericPassword = 63,
    NumericPin = 64,
    AlphanumericPin = 65,
    FormulaNumber = 67,
    ChatWithoutEmoji = 68,
};

enum class KeyboardNavigationMode
{
    Local = 0,
    Cycle = 1,
    Once = 2,
};

enum class ManipulationModes : unsigned
{
    None = 0x0,
    TranslateX = 0x1,
    TranslateY = 0x2,
    TranslateRailsX = 0x4,
    TranslateRailsY = 0x8,
    Rotate = 0x10,
    Scale = 0x20,
    TranslateInertia = 0x40,
    RotateInertia = 0x80,
    ScaleInertia = 0x100,
    All = 0xFFFF,
    System = 0x10000,
};

DEFINE_ENUM_FLAG_OPERATORS(ManipulationModes)

}

}
