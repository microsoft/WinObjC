// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Graphics.Printing.OptionDetails.1.h"
#include "Windows.Graphics.Printing.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_a6487363_b074_5c60_ab16_866dce4ee54d
#define WINRT_GENERIC_a6487363_b074_5c60_ab16_866dce4ee54d
template <> struct __declspec(uuid("a6487363-b074-5c60-ab16-866dce4ee54d")) __declspec(novtable) IVectorView<Windows::Foundation::IInspectable> : impl_IVectorView<Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_79e5168f_702a_5030_bd44_ef23d8887aed
#define WINRT_GENERIC_79e5168f_702a_5030_bd44_ef23d8887aed
template <> struct __declspec(uuid("79e5168f-702a-5030-bd44-ef23d8887aed")) __declspec(novtable) IMapView<hstring, Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails> : impl_IMapView<hstring, Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_1b1f456b_8821_592e_b4a7_9b4c3712518e
#define WINRT_GENERIC_1b1f456b_8821_592e_b4a7_9b4c3712518e
template <> struct __declspec(uuid("1b1f456b-8821-592e-b4a7-9b4c3712518e")) __declspec(novtable) TypedEventHandler<Windows::Graphics::Printing::OptionDetails::PrintTaskOptionDetails, Windows::Graphics::Printing::OptionDetails::PrintTaskOptionChangedEventArgs> : impl_TypedEventHandler<Windows::Graphics::Printing::OptionDetails::PrintTaskOptionDetails, Windows::Graphics::Printing::OptionDetails::PrintTaskOptionChangedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_5c88455c_5b59_557c_8064_5e4f3d59a8ec
#define WINRT_GENERIC_5c88455c_5b59_557c_8064_5e4f3d59a8ec
template <> struct __declspec(uuid("5c88455c-5b59-557c-8064-5e4f3d59a8ec")) __declspec(novtable) TypedEventHandler<Windows::Graphics::Printing::OptionDetails::PrintTaskOptionDetails, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::Graphics::Printing::OptionDetails::PrintTaskOptionDetails, Windows::Foundation::IInspectable> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_092b849b_60b1_52be_a44a_6fe8e933cbe4
#define WINRT_GENERIC_092b849b_60b1_52be_a44a_6fe8e933cbe4
template <> struct __declspec(uuid("092b849b-60b1-52be-a44a-6fe8e933cbe4")) __declspec(novtable) IIterable<Windows::Foundation::IInspectable> : impl_IIterable<Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_44a94f2d_04f8_5091_b336_be7892dd10be
#define WINRT_GENERIC_44a94f2d_04f8_5091_b336_be7892dd10be
template <> struct __declspec(uuid("44a94f2d-04f8-5091-b336-be7892dd10be")) __declspec(novtable) IIterator<Windows::Foundation::IInspectable> : impl_IIterator<Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_f5d9c723_a4b1_5fc8_9f78_0b95b716720b
#define WINRT_GENERIC_f5d9c723_a4b1_5fc8_9f78_0b95b716720b
template <> struct __declspec(uuid("f5d9c723-a4b1-5fc8-9f78-0b95b716720b")) __declspec(novtable) IKeyValuePair<hstring, Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails> : impl_IKeyValuePair<hstring, Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails> {};
#endif

#ifndef WINRT_GENERIC_7bef6011_58a1_5523_8e2a_309f8cb1bd39
#define WINRT_GENERIC_7bef6011_58a1_5523_8e2a_309f8cb1bd39
template <> struct __declspec(uuid("7bef6011-58a1-5523-8e2a-309f8cb1bd39")) __declspec(novtable) IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>> : impl_IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>> {};
#endif

#ifndef WINRT_GENERIC_6770cf39_094f_59c5_8a5d_e3b5dc64db0f
#define WINRT_GENERIC_6770cf39_094f_59c5_8a5d_e3b5dc64db0f
template <> struct __declspec(uuid("6770cf39-094f-59c5-8a5d-e3b5dc64db0f")) __declspec(novtable) IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>> : impl_IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>> {};
#endif


}

namespace Windows::Graphics::Printing::OptionDetails {

struct IPrintCustomItemDetails :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintCustomItemDetails>
{
    IPrintCustomItemDetails(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintCustomItemListOptionDetails :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintCustomItemListOptionDetails>,
    impl::require<IPrintCustomItemListOptionDetails, Windows::Graphics::Printing::OptionDetails::IPrintCustomOptionDetails, Windows::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails, Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>
{
    IPrintCustomItemListOptionDetails(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintCustomOptionDetails :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintCustomOptionDetails>,
    impl::require<IPrintCustomOptionDetails, Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>
{
    IPrintCustomOptionDetails(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintCustomTextOptionDetails :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintCustomTextOptionDetails>,
    impl::require<IPrintCustomTextOptionDetails, Windows::Graphics::Printing::OptionDetails::IPrintCustomOptionDetails, Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>
{
    IPrintCustomTextOptionDetails(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintItemListOptionDetails :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintItemListOptionDetails>,
    impl::require<IPrintItemListOptionDetails, Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>
{
    IPrintItemListOptionDetails(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintNumberOptionDetails :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintNumberOptionDetails>,
    impl::require<IPrintNumberOptionDetails, Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>
{
    IPrintNumberOptionDetails(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintOptionDetails :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintOptionDetails>
{
    IPrintOptionDetails(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintTaskOptionChangedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintTaskOptionChangedEventArgs>
{
    IPrintTaskOptionChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintTaskOptionDetails :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintTaskOptionDetails>
{
    IPrintTaskOptionDetails(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintTaskOptionDetailsStatic :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintTaskOptionDetailsStatic>
{
    IPrintTaskOptionDetailsStatic(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintTextOptionDetails :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintTextOptionDetails>,
    impl::require<IPrintTextOptionDetails, Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>
{
    IPrintTextOptionDetails(std::nullptr_t = nullptr) noexcept {}
};

}

}
