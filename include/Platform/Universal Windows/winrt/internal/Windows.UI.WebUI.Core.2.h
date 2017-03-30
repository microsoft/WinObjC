// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.WebUI.Core.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_c587d918_89aa_55ca_95b0_c14a07a53217
#define WINRT_GENERIC_c587d918_89aa_55ca_95b0_c14a07a53217
template <> struct __declspec(uuid("c587d918-89aa-55ca-95b0-c14a07a53217")) __declspec(novtable) TypedEventHandler<Windows::UI::WebUI::Core::WebUICommandBarIconButton, Windows::UI::WebUI::Core::WebUICommandBarItemInvokedEventArgs> : impl_TypedEventHandler<Windows::UI::WebUI::Core::WebUICommandBarIconButton, Windows::UI::WebUI::Core::WebUICommandBarItemInvokedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_10f0434f_880e_504a_9ce1_24b14149213b
#define WINRT_GENERIC_10f0434f_880e_504a_9ce1_24b14149213b
template <> struct __declspec(uuid("10f0434f-880e-504a-9ce1-24b14149213b")) __declspec(novtable) TypedEventHandler<Windows::UI::WebUI::Core::WebUICommandBarConfirmationButton, Windows::UI::WebUI::Core::WebUICommandBarItemInvokedEventArgs> : impl_TypedEventHandler<Windows::UI::WebUI::Core::WebUICommandBarConfirmationButton, Windows::UI::WebUI::Core::WebUICommandBarItemInvokedEventArgs> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_b35feb4b_1833_59f8_b146_4627813af189
#define WINRT_GENERIC_b35feb4b_1833_59f8_b146_4627813af189
template <> struct __declspec(uuid("b35feb4b-1833-59f8-b146-4627813af189")) __declspec(novtable) IObservableVector<Windows::UI::WebUI::Core::IWebUICommandBarElement> : impl_IObservableVector<Windows::UI::WebUI::Core::IWebUICommandBarElement> {};
#endif

#ifndef WINRT_GENERIC_42997479_cbf2_5a79_9560_dd7e7c413af4
#define WINRT_GENERIC_42997479_cbf2_5a79_9560_dd7e7c413af4
template <> struct __declspec(uuid("42997479-cbf2-5a79-9560-dd7e7c413af4")) __declspec(novtable) VectorChangedEventHandler<Windows::UI::WebUI::Core::IWebUICommandBarElement> : impl_VectorChangedEventHandler<Windows::UI::WebUI::Core::IWebUICommandBarElement> {};
#endif

#ifndef WINRT_GENERIC_b6224973_c1a6_5601_b000_b5e078746bc5
#define WINRT_GENERIC_b6224973_c1a6_5601_b000_b5e078746bc5
template <> struct __declspec(uuid("b6224973-c1a6-5601-b000-b5e078746bc5")) __declspec(novtable) IIterator<Windows::UI::WebUI::Core::IWebUICommandBarElement> : impl_IIterator<Windows::UI::WebUI::Core::IWebUICommandBarElement> {};
#endif

#ifndef WINRT_GENERIC_3cb21e0d_b293_5112_bccc_6e92b6321d2f
#define WINRT_GENERIC_3cb21e0d_b293_5112_bccc_6e92b6321d2f
template <> struct __declspec(uuid("3cb21e0d-b293-5112-bccc-6e92b6321d2f")) __declspec(novtable) IIterable<Windows::UI::WebUI::Core::IWebUICommandBarElement> : impl_IIterable<Windows::UI::WebUI::Core::IWebUICommandBarElement> {};
#endif

#ifndef WINRT_GENERIC_ba62c01a_2cb5_5916_a2c5_d2289e16b2b2
#define WINRT_GENERIC_ba62c01a_2cb5_5916_a2c5_d2289e16b2b2
template <> struct __declspec(uuid("ba62c01a-2cb5-5916-a2c5-d2289e16b2b2")) __declspec(novtable) IVectorView<Windows::UI::WebUI::Core::IWebUICommandBarElement> : impl_IVectorView<Windows::UI::WebUI::Core::IWebUICommandBarElement> {};
#endif

#ifndef WINRT_GENERIC_4a89cee1_56c5_5e02_ba8f_52b436b71377
#define WINRT_GENERIC_4a89cee1_56c5_5e02_ba8f_52b436b71377
template <> struct __declspec(uuid("4a89cee1-56c5-5e02-ba8f-52b436b71377")) __declspec(novtable) IVector<Windows::UI::WebUI::Core::IWebUICommandBarElement> : impl_IVector<Windows::UI::WebUI::Core::IWebUICommandBarElement> {};
#endif


}

namespace Windows::UI::WebUI::Core {

struct MenuClosedEventHandler : Windows::Foundation::IUnknown
{
    MenuClosedEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> MenuClosedEventHandler(L lambda);
    template <typename F> MenuClosedEventHandler (F * function);
    template <typename O, typename M> MenuClosedEventHandler(O * object, M method);
    void operator()() const;
};

struct MenuOpenedEventHandler : Windows::Foundation::IUnknown
{
    MenuOpenedEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> MenuOpenedEventHandler(L lambda);
    template <typename F> MenuOpenedEventHandler (F * function);
    template <typename O, typename M> MenuOpenedEventHandler(O * object, M method);
    void operator()() const;
};

struct SizeChangedEventHandler : Windows::Foundation::IUnknown
{
    SizeChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> SizeChangedEventHandler(L lambda);
    template <typename F> SizeChangedEventHandler (F * function);
    template <typename O, typename M> SizeChangedEventHandler(O * object, M method);
    void operator()(const Windows::UI::WebUI::Core::WebUICommandBarSizeChangedEventArgs & eventArgs) const;
};

struct IWebUICommandBar :
    Windows::Foundation::IInspectable,
    impl::consume<IWebUICommandBar>
{
    IWebUICommandBar(std::nullptr_t = nullptr) noexcept {}
};

struct IWebUICommandBarBitmapIcon :
    Windows::Foundation::IInspectable,
    impl::consume<IWebUICommandBarBitmapIcon>,
    impl::require<IWebUICommandBarBitmapIcon, Windows::UI::WebUI::Core::IWebUICommandBarIcon>
{
    IWebUICommandBarBitmapIcon(std::nullptr_t = nullptr) noexcept {}
};

struct IWebUICommandBarBitmapIconFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IWebUICommandBarBitmapIconFactory>
{
    IWebUICommandBarBitmapIconFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IWebUICommandBarConfirmationButton :
    Windows::Foundation::IInspectable,
    impl::consume<IWebUICommandBarConfirmationButton>,
    impl::require<IWebUICommandBarConfirmationButton, Windows::UI::WebUI::Core::IWebUICommandBarElement>
{
    IWebUICommandBarConfirmationButton(std::nullptr_t = nullptr) noexcept {}
};

struct IWebUICommandBarElement :
    Windows::Foundation::IInspectable,
    impl::consume<IWebUICommandBarElement>
{
    IWebUICommandBarElement(std::nullptr_t = nullptr) noexcept {}
};

struct IWebUICommandBarIcon :
    Windows::Foundation::IInspectable,
    impl::consume<IWebUICommandBarIcon>
{
    IWebUICommandBarIcon(std::nullptr_t = nullptr) noexcept {}
};

struct IWebUICommandBarIconButton :
    Windows::Foundation::IInspectable,
    impl::consume<IWebUICommandBarIconButton>,
    impl::require<IWebUICommandBarIconButton, Windows::UI::WebUI::Core::IWebUICommandBarElement>
{
    IWebUICommandBarIconButton(std::nullptr_t = nullptr) noexcept {}
};

struct IWebUICommandBarItemInvokedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IWebUICommandBarItemInvokedEventArgs>
{
    IWebUICommandBarItemInvokedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IWebUICommandBarSizeChangedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IWebUICommandBarSizeChangedEventArgs>
{
    IWebUICommandBarSizeChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IWebUICommandBarStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IWebUICommandBarStatics>
{
    IWebUICommandBarStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IWebUICommandBarSymbolIcon :
    Windows::Foundation::IInspectable,
    impl::consume<IWebUICommandBarSymbolIcon>,
    impl::require<IWebUICommandBarSymbolIcon, Windows::UI::WebUI::Core::IWebUICommandBarIcon>
{
    IWebUICommandBarSymbolIcon(std::nullptr_t = nullptr) noexcept {}
};

struct IWebUICommandBarSymbolIconFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IWebUICommandBarSymbolIconFactory>
{
    IWebUICommandBarSymbolIconFactory(std::nullptr_t = nullptr) noexcept {}
};

}

}
