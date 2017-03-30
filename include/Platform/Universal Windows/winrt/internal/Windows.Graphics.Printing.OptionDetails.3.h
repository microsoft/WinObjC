// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Graphics.Printing.OptionDetails.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Graphics::Printing::OptionDetails {

struct WINRT_EBO PrintBindingOptionDetails :
    Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails,
    impl::require<PrintBindingOptionDetails, Windows::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails>
{
    PrintBindingOptionDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PrintBorderingOptionDetails :
    Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails,
    impl::require<PrintBorderingOptionDetails, Windows::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails>
{
    PrintBorderingOptionDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PrintCollationOptionDetails :
    Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails,
    impl::require<PrintCollationOptionDetails, Windows::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails>
{
    PrintCollationOptionDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PrintColorModeOptionDetails :
    Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails,
    impl::require<PrintColorModeOptionDetails, Windows::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails>
{
    PrintColorModeOptionDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PrintCopiesOptionDetails :
    Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails,
    impl::require<PrintCopiesOptionDetails, Windows::Graphics::Printing::OptionDetails::IPrintNumberOptionDetails>
{
    PrintCopiesOptionDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PrintCustomItemDetails :
    Windows::Graphics::Printing::OptionDetails::IPrintCustomItemDetails
{
    PrintCustomItemDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PrintCustomItemListOptionDetails :
    Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails,
    impl::require<PrintCustomItemListOptionDetails, Windows::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails, Windows::Graphics::Printing::OptionDetails::IPrintCustomOptionDetails, Windows::Graphics::Printing::OptionDetails::IPrintCustomItemListOptionDetails>
{
    PrintCustomItemListOptionDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PrintCustomTextOptionDetails :
    Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails,
    impl::require<PrintCustomTextOptionDetails, Windows::Graphics::Printing::OptionDetails::IPrintCustomOptionDetails, Windows::Graphics::Printing::OptionDetails::IPrintCustomTextOptionDetails>
{
    PrintCustomTextOptionDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PrintDuplexOptionDetails :
    Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails,
    impl::require<PrintDuplexOptionDetails, Windows::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails>
{
    PrintDuplexOptionDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PrintHolePunchOptionDetails :
    Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails,
    impl::require<PrintHolePunchOptionDetails, Windows::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails>
{
    PrintHolePunchOptionDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PrintMediaSizeOptionDetails :
    Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails,
    impl::require<PrintMediaSizeOptionDetails, Windows::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails>
{
    PrintMediaSizeOptionDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PrintMediaTypeOptionDetails :
    Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails,
    impl::require<PrintMediaTypeOptionDetails, Windows::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails>
{
    PrintMediaTypeOptionDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PrintOrientationOptionDetails :
    Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails,
    impl::require<PrintOrientationOptionDetails, Windows::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails>
{
    PrintOrientationOptionDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PrintQualityOptionDetails :
    Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails,
    impl::require<PrintQualityOptionDetails, Windows::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails>
{
    PrintQualityOptionDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PrintStapleOptionDetails :
    Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails,
    impl::require<PrintStapleOptionDetails, Windows::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails>
{
    PrintStapleOptionDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PrintTaskOptionChangedEventArgs :
    Windows::Graphics::Printing::OptionDetails::IPrintTaskOptionChangedEventArgs
{
    PrintTaskOptionChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PrintTaskOptionDetails :
    Windows::Graphics::Printing::OptionDetails::IPrintTaskOptionDetails,
    impl::require<PrintTaskOptionDetails, Windows::Graphics::Printing::IPrintTaskOptionsCoreUIConfiguration, Windows::Graphics::Printing::IPrintTaskOptionsCore>
{
    PrintTaskOptionDetails(std::nullptr_t) noexcept {}
    static Windows::Graphics::Printing::OptionDetails::PrintTaskOptionDetails GetFromPrintTaskOptions(const Windows::Graphics::Printing::PrintTaskOptions & printTaskOptions);
};

}

}
