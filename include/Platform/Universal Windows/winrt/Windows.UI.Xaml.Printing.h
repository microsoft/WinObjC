// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Graphics.Printing.3.h"
#include "internal/Windows.UI.Xaml.3.h"
#include "internal/Windows.UI.Xaml.Printing.3.h"
#include "Windows.UI.Xaml.h"
#include "internal/Windows.UI.Xaml.Printing.5.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Printing {

template <typename L> AddPagesEventHandler::AddPagesEventHandler(L lambda) :
    AddPagesEventHandler(impl::make_delegate<impl_AddPagesEventHandler<L>, AddPagesEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> AddPagesEventHandler::AddPagesEventHandler(F * function) :
    AddPagesEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> AddPagesEventHandler::AddPagesEventHandler(O * object, M method) :
    AddPagesEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void AddPagesEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Printing::AddPagesEventArgs & e) const
{
    check_hresult((*(abi<AddPagesEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

template <typename L> GetPreviewPageEventHandler::GetPreviewPageEventHandler(L lambda) :
    GetPreviewPageEventHandler(impl::make_delegate<impl_GetPreviewPageEventHandler<L>, GetPreviewPageEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> GetPreviewPageEventHandler::GetPreviewPageEventHandler(F * function) :
    GetPreviewPageEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> GetPreviewPageEventHandler::GetPreviewPageEventHandler(O * object, M method) :
    GetPreviewPageEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void GetPreviewPageEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Printing::GetPreviewPageEventArgs & e) const
{
    check_hresult((*(abi<GetPreviewPageEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

template <typename L> PaginateEventHandler::PaginateEventHandler(L lambda) :
    PaginateEventHandler(impl::make_delegate<impl_PaginateEventHandler<L>, PaginateEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> PaginateEventHandler::PaginateEventHandler(F * function) :
    PaginateEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> PaginateEventHandler::PaginateEventHandler(O * object, M method) :
    PaginateEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void PaginateEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Printing::PaginateEventArgs & e) const
{
    check_hresult((*(abi<PaginateEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

}

namespace impl {

template <typename D>
struct produce<D, Windows::UI::Xaml::Printing::IAddPagesEventArgs> : produce_base<D, Windows::UI::Xaml::Printing::IAddPagesEventArgs>
{
    HRESULT __stdcall get_PrintTaskOptions(impl::abi_arg_out<Windows::Graphics::Printing::IPrintTaskOptionsCore> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PrintTaskOptions());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Printing::IGetPreviewPageEventArgs> : produce_base<D, Windows::UI::Xaml::Printing::IGetPreviewPageEventArgs>
{
    HRESULT __stdcall get_PageNumber(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PageNumber());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Printing::IPaginateEventArgs> : produce_base<D, Windows::UI::Xaml::Printing::IPaginateEventArgs>
{
    HRESULT __stdcall get_PrintTaskOptions(impl::abi_arg_out<Windows::Graphics::Printing::IPrintTaskOptionsCore> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PrintTaskOptions());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CurrentPreviewPageNumber(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CurrentPreviewPageNumber());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Printing::IPrintDocument> : produce_base<D, Windows::UI::Xaml::Printing::IPrintDocument>
{
    HRESULT __stdcall get_DocumentSource(impl::abi_arg_out<Windows::Graphics::Printing::IPrintDocumentSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DocumentSource());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Paginate(impl::abi_arg_in<Windows::UI::Xaml::Printing::PaginateEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Paginate(*reinterpret_cast<const Windows::UI::Xaml::Printing::PaginateEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Paginate(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Paginate(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_GetPreviewPage(impl::abi_arg_in<Windows::UI::Xaml::Printing::GetPreviewPageEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().GetPreviewPage(*reinterpret_cast<const Windows::UI::Xaml::Printing::GetPreviewPageEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_GetPreviewPage(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GetPreviewPage(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_AddPages(impl::abi_arg_in<Windows::UI::Xaml::Printing::AddPagesEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().AddPages(*reinterpret_cast<const Windows::UI::Xaml::Printing::AddPagesEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AddPages(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddPages(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddPage(impl::abi_arg_in<Windows::UI::Xaml::IUIElement> pageVisual) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddPage(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&pageVisual));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddPagesComplete() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddPagesComplete();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPreviewPageCount(int32_t count, Windows::UI::Xaml::Printing::PreviewPageCountType type) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPreviewPageCount(count, type);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPreviewPage(int32_t pageNumber, impl::abi_arg_in<Windows::UI::Xaml::IUIElement> pageVisual) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPreviewPage(pageNumber, *reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&pageVisual));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_InvalidatePreview() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InvalidatePreview();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Printing::IPrintDocumentFactory> : produce_base<D, Windows::UI::Xaml::Printing::IPrintDocumentFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Printing::IPrintDocument> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstance(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
            return S_OK;
        }
        catch (...)
        {
            *inner = nullptr;
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Printing::IPrintDocumentStatics> : produce_base<D, Windows::UI::Xaml::Printing::IPrintDocumentStatics>
{
    HRESULT __stdcall get_DocumentSourceProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DocumentSourceProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::UI::Xaml::Printing {

template <typename D> Windows::Graphics::Printing::PrintTaskOptions impl_IAddPagesEventArgs<D>::PrintTaskOptions() const
{
    Windows::Graphics::Printing::PrintTaskOptions value { nullptr };
    check_hresult(WINRT_SHIM(IAddPagesEventArgs)->get_PrintTaskOptions(put_abi(value)));
    return value;
}

template <typename D> int32_t impl_IGetPreviewPageEventArgs<D>::PageNumber() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IGetPreviewPageEventArgs)->get_PageNumber(&value));
    return value;
}

template <typename D> Windows::Graphics::Printing::PrintTaskOptions impl_IPaginateEventArgs<D>::PrintTaskOptions() const
{
    Windows::Graphics::Printing::PrintTaskOptions value { nullptr };
    check_hresult(WINRT_SHIM(IPaginateEventArgs)->get_PrintTaskOptions(put_abi(value)));
    return value;
}

template <typename D> int32_t impl_IPaginateEventArgs<D>::CurrentPreviewPageNumber() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IPaginateEventArgs)->get_CurrentPreviewPageNumber(&value));
    return value;
}

template <typename D> Windows::Graphics::Printing::IPrintDocumentSource impl_IPrintDocument<D>::DocumentSource() const
{
    Windows::Graphics::Printing::IPrintDocumentSource value;
    check_hresult(WINRT_SHIM(IPrintDocument)->get_DocumentSource(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IPrintDocument<D>::Paginate(const Windows::UI::Xaml::Printing::PaginateEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPrintDocument)->add_Paginate(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IPrintDocument> impl_IPrintDocument<D>::Paginate(auto_revoke_t, const Windows::UI::Xaml::Printing::PaginateEventHandler & value) const
{
    return impl::make_event_revoker<D, IPrintDocument>(this, &ABI::Windows::UI::Xaml::Printing::IPrintDocument::remove_Paginate, Paginate(value));
}

template <typename D> void impl_IPrintDocument<D>::Paginate(event_token token) const
{
    check_hresult(WINRT_SHIM(IPrintDocument)->remove_Paginate(token));
}

template <typename D> event_token impl_IPrintDocument<D>::GetPreviewPage(const Windows::UI::Xaml::Printing::GetPreviewPageEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPrintDocument)->add_GetPreviewPage(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IPrintDocument> impl_IPrintDocument<D>::GetPreviewPage(auto_revoke_t, const Windows::UI::Xaml::Printing::GetPreviewPageEventHandler & value) const
{
    return impl::make_event_revoker<D, IPrintDocument>(this, &ABI::Windows::UI::Xaml::Printing::IPrintDocument::remove_GetPreviewPage, GetPreviewPage(value));
}

template <typename D> void impl_IPrintDocument<D>::GetPreviewPage(event_token token) const
{
    check_hresult(WINRT_SHIM(IPrintDocument)->remove_GetPreviewPage(token));
}

template <typename D> event_token impl_IPrintDocument<D>::AddPages(const Windows::UI::Xaml::Printing::AddPagesEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPrintDocument)->add_AddPages(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IPrintDocument> impl_IPrintDocument<D>::AddPages(auto_revoke_t, const Windows::UI::Xaml::Printing::AddPagesEventHandler & value) const
{
    return impl::make_event_revoker<D, IPrintDocument>(this, &ABI::Windows::UI::Xaml::Printing::IPrintDocument::remove_AddPages, AddPages(value));
}

template <typename D> void impl_IPrintDocument<D>::AddPages(event_token token) const
{
    check_hresult(WINRT_SHIM(IPrintDocument)->remove_AddPages(token));
}

template <typename D> void impl_IPrintDocument<D>::AddPage(const Windows::UI::Xaml::UIElement & pageVisual) const
{
    check_hresult(WINRT_SHIM(IPrintDocument)->abi_AddPage(get_abi(pageVisual)));
}

template <typename D> void impl_IPrintDocument<D>::AddPagesComplete() const
{
    check_hresult(WINRT_SHIM(IPrintDocument)->abi_AddPagesComplete());
}

template <typename D> void impl_IPrintDocument<D>::SetPreviewPageCount(int32_t count, Windows::UI::Xaml::Printing::PreviewPageCountType type) const
{
    check_hresult(WINRT_SHIM(IPrintDocument)->abi_SetPreviewPageCount(count, type));
}

template <typename D> void impl_IPrintDocument<D>::SetPreviewPage(int32_t pageNumber, const Windows::UI::Xaml::UIElement & pageVisual) const
{
    check_hresult(WINRT_SHIM(IPrintDocument)->abi_SetPreviewPage(pageNumber, get_abi(pageVisual)));
}

template <typename D> void impl_IPrintDocument<D>::InvalidatePreview() const
{
    check_hresult(WINRT_SHIM(IPrintDocument)->abi_InvalidatePreview());
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPrintDocumentStatics<D>::DocumentSourceProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPrintDocumentStatics)->get_DocumentSourceProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Printing::PrintDocument impl_IPrintDocumentFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Printing::PrintDocument instance { nullptr };
    check_hresult(WINRT_SHIM(IPrintDocumentFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

inline AddPagesEventArgs::AddPagesEventArgs() :
    AddPagesEventArgs(activate_instance<AddPagesEventArgs>())
{}

inline GetPreviewPageEventArgs::GetPreviewPageEventArgs() :
    GetPreviewPageEventArgs(activate_instance<GetPreviewPageEventArgs>())
{}

inline PaginateEventArgs::PaginateEventArgs() :
    PaginateEventArgs(activate_instance<PaginateEventArgs>())
{}

inline PrintDocument::PrintDocument()
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<PrintDocument, IPrintDocumentFactory>().CreateInstance(outer, inner));
}

inline Windows::UI::Xaml::DependencyProperty PrintDocument::DocumentSourceProperty()
{
    return get_activation_factory<PrintDocument, IPrintDocumentStatics>().DocumentSourceProperty();
}

}

}
#pragma warning(pop)
