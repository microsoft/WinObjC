// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Popups.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_105139a1_dcb8_5f65_97ef_cb1bf0b75f9d
#define WINRT_GENERIC_105139a1_dcb8_5f65_97ef_cb1bf0b75f9d
template <> struct __declspec(uuid("105139a1-dcb8-5f65-97ef-cb1bf0b75f9d")) __declspec(novtable) IVector<Windows::UI::Popups::IUICommand> : impl_IVector<Windows::UI::Popups::IUICommand> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_b8770535_6a4b_52b1_b578_f3cdc5007a1f
#define WINRT_GENERIC_b8770535_6a4b_52b1_b578_f3cdc5007a1f
template <> struct __declspec(uuid("b8770535-6a4b-52b1-b578-f3cdc5007a1f")) __declspec(novtable) IAsyncOperation<Windows::UI::Popups::IUICommand> : impl_IAsyncOperation<Windows::UI::Popups::IUICommand> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_f45db3d3_7299_57ce_a73e_297cf0af3083
#define WINRT_GENERIC_f45db3d3_7299_57ce_a73e_297cf0af3083
template <> struct __declspec(uuid("f45db3d3-7299-57ce-a73e-297cf0af3083")) __declspec(novtable) IIterator<Windows::UI::Popups::IUICommand> : impl_IIterator<Windows::UI::Popups::IUICommand> {};
#endif

#ifndef WINRT_GENERIC_e63de42b_53c3_5e07_90d3_98172d545412
#define WINRT_GENERIC_e63de42b_53c3_5e07_90d3_98172d545412
template <> struct __declspec(uuid("e63de42b-53c3-5e07-90d3-98172d545412")) __declspec(novtable) IIterable<Windows::UI::Popups::IUICommand> : impl_IIterable<Windows::UI::Popups::IUICommand> {};
#endif

#ifndef WINRT_GENERIC_ed1165e6_f377_5b00_8172_93c1bd04deb4
#define WINRT_GENERIC_ed1165e6_f377_5b00_8172_93c1bd04deb4
template <> struct __declspec(uuid("ed1165e6-f377-5b00-8172-93c1bd04deb4")) __declspec(novtable) IVectorView<Windows::UI::Popups::IUICommand> : impl_IVectorView<Windows::UI::Popups::IUICommand> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_dd33fd5b_a24d_5a44_91fe_dd6441770103
#define WINRT_GENERIC_dd33fd5b_a24d_5a44_91fe_dd6441770103
template <> struct __declspec(uuid("dd33fd5b-a24d-5a44-91fe-dd6441770103")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::UI::Popups::IUICommand> : impl_AsyncOperationCompletedHandler<Windows::UI::Popups::IUICommand> {};
#endif


}

namespace Windows::UI::Popups {

struct UICommandInvokedHandler : Windows::Foundation::IUnknown
{
    UICommandInvokedHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> UICommandInvokedHandler(L lambda);
    template <typename F> UICommandInvokedHandler (F * function);
    template <typename O, typename M> UICommandInvokedHandler(O * object, M method);
    void operator()(const Windows::UI::Popups::IUICommand & command) const;
};

struct IMessageDialog :
    Windows::Foundation::IInspectable,
    impl::consume<IMessageDialog>
{
    IMessageDialog(std::nullptr_t = nullptr) noexcept {}
};

struct IMessageDialogFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IMessageDialogFactory>
{
    IMessageDialogFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IPopupMenu :
    Windows::Foundation::IInspectable,
    impl::consume<IPopupMenu>
{
    IPopupMenu(std::nullptr_t = nullptr) noexcept {}
};

struct IUICommand :
    Windows::Foundation::IInspectable,
    impl::consume<IUICommand>
{
    IUICommand(std::nullptr_t = nullptr) noexcept {}
};

struct IUICommandFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IUICommandFactory>
{
    IUICommandFactory(std::nullptr_t = nullptr) noexcept {}
};

}

}
