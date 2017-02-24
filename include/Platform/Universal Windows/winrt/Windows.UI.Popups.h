// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.UI.Popups.3.h"
#include "Windows.UI.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Popups {

template <typename L> UICommandInvokedHandler::UICommandInvokedHandler(L lambda) :
    UICommandInvokedHandler(impl::make_delegate<impl_UICommandInvokedHandler<L>, UICommandInvokedHandler>(std::forward<L>(lambda)))
{}

template <typename F> UICommandInvokedHandler::UICommandInvokedHandler(F * function) :
    UICommandInvokedHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> UICommandInvokedHandler::UICommandInvokedHandler(O * object, M method) :
    UICommandInvokedHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void UICommandInvokedHandler::operator()(const Windows::UI::Popups::IUICommand & command) const
{
    check_hresult((*(abi<UICommandInvokedHandler> **)this)->abi_Invoke(get_abi(command)));
}

}

namespace impl {

template <typename D>
struct produce<D, Windows::UI::Popups::IMessageDialog> : produce_base<D, Windows::UI::Popups::IMessageDialog>
{
    HRESULT __stdcall get_Title(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Title());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Title(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Title(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Commands(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Popups::IUICommand>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Commands());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DefaultCommandIndex(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DefaultCommandIndex());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DefaultCommandIndex(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DefaultCommandIndex(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CancelCommandIndex(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CancelCommandIndex());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CancelCommandIndex(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CancelCommandIndex(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Content(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Content());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Content(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Content(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::UI::Popups::IUICommand>> messageDialogAsyncOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *messageDialogAsyncOperation = detach_abi(this->shim().ShowAsync());
            return S_OK;
        }
        catch (...)
        {
            *messageDialogAsyncOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Options(Windows::UI::Popups::MessageDialogOptions * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Options());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Options(Windows::UI::Popups::MessageDialogOptions value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Options(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Popups::IMessageDialogFactory> : produce_base<D, Windows::UI::Popups::IMessageDialogFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> content, impl::abi_arg_out<Windows::UI::Popups::IMessageDialog> messageDialog) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *messageDialog = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&content)));
            return S_OK;
        }
        catch (...)
        {
            *messageDialog = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithTitle(impl::abi_arg_in<hstring> content, impl::abi_arg_in<hstring> title, impl::abi_arg_out<Windows::UI::Popups::IMessageDialog> messageDialog) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *messageDialog = detach_abi(this->shim().CreateWithTitle(*reinterpret_cast<const hstring *>(&content), *reinterpret_cast<const hstring *>(&title)));
            return S_OK;
        }
        catch (...)
        {
            *messageDialog = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Popups::IPopupMenu> : produce_base<D, Windows::UI::Popups::IPopupMenu>
{
    HRESULT __stdcall get_Commands(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Popups::IUICommand>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Commands());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowAsync(impl::abi_arg_in<Windows::Foundation::Point> invocationPoint, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::UI::Popups::IUICommand>> asyncOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOperation = detach_abi(this->shim().ShowAsync(*reinterpret_cast<const Windows::Foundation::Point *>(&invocationPoint)));
            return S_OK;
        }
        catch (...)
        {
            *asyncOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowAsyncWithRect(impl::abi_arg_in<Windows::Foundation::Rect> selection, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::UI::Popups::IUICommand>> asyncOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOperation = detach_abi(this->shim().ShowForSelectionAsync(*reinterpret_cast<const Windows::Foundation::Rect *>(&selection)));
            return S_OK;
        }
        catch (...)
        {
            *asyncOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowAsyncWithRectAndPlacement(impl::abi_arg_in<Windows::Foundation::Rect> selection, Windows::UI::Popups::Placement preferredPlacement, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::UI::Popups::IUICommand>> asyncOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOperation = detach_abi(this->shim().ShowForSelectionAsync(*reinterpret_cast<const Windows::Foundation::Rect *>(&selection), preferredPlacement));
            return S_OK;
        }
        catch (...)
        {
            *asyncOperation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Popups::IUICommand> : produce_base<D, Windows::UI::Popups::IUICommand>
{
    HRESULT __stdcall get_Label(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Label());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Label(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Label(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Invoked(impl::abi_arg_out<Windows::UI::Popups::UICommandInvokedHandler> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Invoked());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Invoked(impl::abi_arg_in<Windows::UI::Popups::UICommandInvokedHandler> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Invoked(*reinterpret_cast<const Windows::UI::Popups::UICommandInvokedHandler *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Id(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Id());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Id(impl::abi_arg_in<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Id(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Popups::IUICommandFactory> : produce_base<D, Windows::UI::Popups::IUICommandFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> label, impl::abi_arg_out<Windows::UI::Popups::IUICommand> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&label)));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithHandler(impl::abi_arg_in<hstring> label, impl::abi_arg_in<Windows::UI::Popups::UICommandInvokedHandler> action, impl::abi_arg_out<Windows::UI::Popups::IUICommand> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateWithHandler(*reinterpret_cast<const hstring *>(&label), *reinterpret_cast<const Windows::UI::Popups::UICommandInvokedHandler *>(&action)));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithHandlerAndId(impl::abi_arg_in<hstring> label, impl::abi_arg_in<Windows::UI::Popups::UICommandInvokedHandler> action, impl::abi_arg_in<Windows::Foundation::IInspectable> commandId, impl::abi_arg_out<Windows::UI::Popups::IUICommand> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateWithHandlerAndId(*reinterpret_cast<const hstring *>(&label), *reinterpret_cast<const Windows::UI::Popups::UICommandInvokedHandler *>(&action), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&commandId)));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::UI::Popups {

template <typename D> hstring impl_IMessageDialog<D>::Title() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMessageDialog)->get_Title(put_abi(value)));
    return value;
}

template <typename D> void impl_IMessageDialog<D>::Title(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IMessageDialog)->put_Title(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::UI::Popups::IUICommand> impl_IMessageDialog<D>::Commands() const
{
    Windows::Foundation::Collections::IVector<Windows::UI::Popups::IUICommand> value;
    check_hresult(WINRT_SHIM(IMessageDialog)->get_Commands(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IMessageDialog<D>::DefaultCommandIndex() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMessageDialog)->get_DefaultCommandIndex(&value));
    return value;
}

template <typename D> void impl_IMessageDialog<D>::DefaultCommandIndex(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IMessageDialog)->put_DefaultCommandIndex(value));
}

template <typename D> uint32_t impl_IMessageDialog<D>::CancelCommandIndex() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMessageDialog)->get_CancelCommandIndex(&value));
    return value;
}

template <typename D> void impl_IMessageDialog<D>::CancelCommandIndex(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IMessageDialog)->put_CancelCommandIndex(value));
}

template <typename D> hstring impl_IMessageDialog<D>::Content() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMessageDialog)->get_Content(put_abi(value)));
    return value;
}

template <typename D> void impl_IMessageDialog<D>::Content(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IMessageDialog)->put_Content(get_abi(value)));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::UI::Popups::IUICommand> impl_IMessageDialog<D>::ShowAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::UI::Popups::IUICommand> messageDialogAsyncOperation;
    check_hresult(WINRT_SHIM(IMessageDialog)->abi_ShowAsync(put_abi(messageDialogAsyncOperation)));
    return messageDialogAsyncOperation;
}

template <typename D> Windows::UI::Popups::MessageDialogOptions impl_IMessageDialog<D>::Options() const
{
    Windows::UI::Popups::MessageDialogOptions value {};
    check_hresult(WINRT_SHIM(IMessageDialog)->get_Options(&value));
    return value;
}

template <typename D> void impl_IMessageDialog<D>::Options(Windows::UI::Popups::MessageDialogOptions value) const
{
    check_hresult(WINRT_SHIM(IMessageDialog)->put_Options(value));
}

template <typename D> Windows::UI::Popups::MessageDialog impl_IMessageDialogFactory<D>::Create(hstring_view content) const
{
    Windows::UI::Popups::MessageDialog messageDialog { nullptr };
    check_hresult(WINRT_SHIM(IMessageDialogFactory)->abi_Create(get_abi(content), put_abi(messageDialog)));
    return messageDialog;
}

template <typename D> Windows::UI::Popups::MessageDialog impl_IMessageDialogFactory<D>::CreateWithTitle(hstring_view content, hstring_view title) const
{
    Windows::UI::Popups::MessageDialog messageDialog { nullptr };
    check_hresult(WINRT_SHIM(IMessageDialogFactory)->abi_CreateWithTitle(get_abi(content), get_abi(title), put_abi(messageDialog)));
    return messageDialog;
}

template <typename D> hstring impl_IUICommand<D>::Label() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUICommand)->get_Label(put_abi(value)));
    return value;
}

template <typename D> void impl_IUICommand<D>::Label(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IUICommand)->put_Label(get_abi(value)));
}

template <typename D> Windows::UI::Popups::UICommandInvokedHandler impl_IUICommand<D>::Invoked() const
{
    Windows::UI::Popups::UICommandInvokedHandler value {};
    check_hresult(WINRT_SHIM(IUICommand)->get_Invoked(put_abi(value)));
    return value;
}

template <typename D> void impl_IUICommand<D>::Invoked(const Windows::UI::Popups::UICommandInvokedHandler & value) const
{
    check_hresult(WINRT_SHIM(IUICommand)->put_Invoked(get_abi(value)));
}

template <typename D> Windows::Foundation::IInspectable impl_IUICommand<D>::Id() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IUICommand)->get_Id(put_abi(value)));
    return value;
}

template <typename D> void impl_IUICommand<D>::Id(const Windows::Foundation::IInspectable & value) const
{
    check_hresult(WINRT_SHIM(IUICommand)->put_Id(get_abi(value)));
}

template <typename D> Windows::UI::Popups::UICommand impl_IUICommandFactory<D>::Create(hstring_view label) const
{
    Windows::UI::Popups::UICommand instance { nullptr };
    check_hresult(WINRT_SHIM(IUICommandFactory)->abi_Create(get_abi(label), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Popups::UICommand impl_IUICommandFactory<D>::CreateWithHandler(hstring_view label, const Windows::UI::Popups::UICommandInvokedHandler & action) const
{
    Windows::UI::Popups::UICommand instance { nullptr };
    check_hresult(WINRT_SHIM(IUICommandFactory)->abi_CreateWithHandler(get_abi(label), get_abi(action), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Popups::UICommand impl_IUICommandFactory<D>::CreateWithHandlerAndId(hstring_view label, const Windows::UI::Popups::UICommandInvokedHandler & action, const Windows::Foundation::IInspectable & commandId) const
{
    Windows::UI::Popups::UICommand instance { nullptr };
    check_hresult(WINRT_SHIM(IUICommandFactory)->abi_CreateWithHandlerAndId(get_abi(label), get_abi(action), get_abi(commandId), put_abi(instance)));
    return instance;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::UI::Popups::IUICommand> impl_IPopupMenu<D>::Commands() const
{
    Windows::Foundation::Collections::IVector<Windows::UI::Popups::IUICommand> value;
    check_hresult(WINRT_SHIM(IPopupMenu)->get_Commands(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::UI::Popups::IUICommand> impl_IPopupMenu<D>::ShowAsync(const Windows::Foundation::Point & invocationPoint) const
{
    Windows::Foundation::IAsyncOperation<Windows::UI::Popups::IUICommand> asyncOperation;
    check_hresult(WINRT_SHIM(IPopupMenu)->abi_ShowAsync(get_abi(invocationPoint), put_abi(asyncOperation)));
    return asyncOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::UI::Popups::IUICommand> impl_IPopupMenu<D>::ShowForSelectionAsync(const Windows::Foundation::Rect & selection) const
{
    Windows::Foundation::IAsyncOperation<Windows::UI::Popups::IUICommand> asyncOperation;
    check_hresult(WINRT_SHIM(IPopupMenu)->abi_ShowAsyncWithRect(get_abi(selection), put_abi(asyncOperation)));
    return asyncOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::UI::Popups::IUICommand> impl_IPopupMenu<D>::ShowForSelectionAsync(const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement) const
{
    Windows::Foundation::IAsyncOperation<Windows::UI::Popups::IUICommand> asyncOperation;
    check_hresult(WINRT_SHIM(IPopupMenu)->abi_ShowAsyncWithRectAndPlacement(get_abi(selection), preferredPlacement, put_abi(asyncOperation)));
    return asyncOperation;
}

inline MessageDialog::MessageDialog(hstring_view content) :
    MessageDialog(get_activation_factory<MessageDialog, IMessageDialogFactory>().Create(content))
{}

inline MessageDialog::MessageDialog(hstring_view content, hstring_view title) :
    MessageDialog(get_activation_factory<MessageDialog, IMessageDialogFactory>().CreateWithTitle(content, title))
{}

inline PopupMenu::PopupMenu() :
    PopupMenu(activate_instance<PopupMenu>())
{}

inline UICommand::UICommand() :
    UICommand(activate_instance<UICommand>())
{}

inline UICommand::UICommand(hstring_view label) :
    UICommand(get_activation_factory<UICommand, IUICommandFactory>().Create(label))
{}

inline UICommand::UICommand(hstring_view label, const Windows::UI::Popups::UICommandInvokedHandler & action) :
    UICommand(get_activation_factory<UICommand, IUICommandFactory>().CreateWithHandler(label, action))
{}

inline UICommand::UICommand(hstring_view label, const Windows::UI::Popups::UICommandInvokedHandler & action, const Windows::Foundation::IInspectable & commandId) :
    UICommand(get_activation_factory<UICommand, IUICommandFactory>().CreateWithHandlerAndId(label, action, commandId))
{}

inline UICommandSeparator::UICommandSeparator() :
    UICommandSeparator(activate_instance<UICommandSeparator>())
{}

}

}
#pragma warning(pop)
