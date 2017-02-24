// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.System.Threading.3.h"
#include "internal/Windows.System.Threading.Core.3.h"
#include "Windows.System.Threading.h"

WINRT_EXPORT namespace winrt {

namespace Windows::System::Threading::Core {

template <typename L> SignalHandler::SignalHandler(L lambda) :
    SignalHandler(impl::make_delegate<impl_SignalHandler<L>, SignalHandler>(std::forward<L>(lambda)))
{}

template <typename F> SignalHandler::SignalHandler(F * function) :
    SignalHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> SignalHandler::SignalHandler(O * object, M method) :
    SignalHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void SignalHandler::operator()(const Windows::System::Threading::Core::SignalNotifier & signalNotifier, bool timedOut) const
{
    check_hresult((*(abi<SignalHandler> **)this)->abi_Invoke(get_abi(signalNotifier), timedOut));
}

}

namespace impl {

template <typename D>
struct produce<D, Windows::System::Threading::Core::IPreallocatedWorkItem> : produce_base<D, Windows::System::Threading::Core::IPreallocatedWorkItem>
{
    HRESULT __stdcall abi_RunAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RunAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::Threading::Core::IPreallocatedWorkItemFactory> : produce_base<D, Windows::System::Threading::Core::IPreallocatedWorkItemFactory>
{
    HRESULT __stdcall abi_CreateWorkItem(impl::abi_arg_in<Windows::System::Threading::WorkItemHandler> handler, impl::abi_arg_out<Windows::System::Threading::Core::IPreallocatedWorkItem> workItem) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *workItem = detach_abi(this->shim().CreateWorkItem(*reinterpret_cast<const Windows::System::Threading::WorkItemHandler *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            *workItem = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWorkItemWithPriority(impl::abi_arg_in<Windows::System::Threading::WorkItemHandler> handler, Windows::System::Threading::WorkItemPriority priority, impl::abi_arg_out<Windows::System::Threading::Core::IPreallocatedWorkItem> WorkItem) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *WorkItem = detach_abi(this->shim().CreateWorkItemWithPriority(*reinterpret_cast<const Windows::System::Threading::WorkItemHandler *>(&handler), priority));
            return S_OK;
        }
        catch (...)
        {
            *WorkItem = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWorkItemWithPriorityAndOptions(impl::abi_arg_in<Windows::System::Threading::WorkItemHandler> handler, Windows::System::Threading::WorkItemPriority priority, Windows::System::Threading::WorkItemOptions options, impl::abi_arg_out<Windows::System::Threading::Core::IPreallocatedWorkItem> WorkItem) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *WorkItem = detach_abi(this->shim().CreateWorkItemWithPriorityAndOptions(*reinterpret_cast<const Windows::System::Threading::WorkItemHandler *>(&handler), priority, options));
            return S_OK;
        }
        catch (...)
        {
            *WorkItem = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::Threading::Core::ISignalNotifier> : produce_base<D, Windows::System::Threading::Core::ISignalNotifier>
{
    HRESULT __stdcall abi_Enable() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Enable();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Terminate() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Terminate();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::Threading::Core::ISignalNotifierStatics> : produce_base<D, Windows::System::Threading::Core::ISignalNotifierStatics>
{
    HRESULT __stdcall abi_AttachToEvent(impl::abi_arg_in<hstring> name, impl::abi_arg_in<Windows::System::Threading::Core::SignalHandler> handler, impl::abi_arg_out<Windows::System::Threading::Core::ISignalNotifier> signalNotifier) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *signalNotifier = detach_abi(this->shim().AttachToEvent(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::System::Threading::Core::SignalHandler *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            *signalNotifier = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AttachToEventWithTimeout(impl::abi_arg_in<hstring> name, impl::abi_arg_in<Windows::System::Threading::Core::SignalHandler> handler, impl::abi_arg_in<Windows::Foundation::TimeSpan> timeout, impl::abi_arg_out<Windows::System::Threading::Core::ISignalNotifier> signalNotifier) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *signalNotifier = detach_abi(this->shim().AttachToEvent(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::System::Threading::Core::SignalHandler *>(&handler), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&timeout)));
            return S_OK;
        }
        catch (...)
        {
            *signalNotifier = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AttachToSemaphore(impl::abi_arg_in<hstring> name, impl::abi_arg_in<Windows::System::Threading::Core::SignalHandler> handler, impl::abi_arg_out<Windows::System::Threading::Core::ISignalNotifier> signalNotifier) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *signalNotifier = detach_abi(this->shim().AttachToSemaphore(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::System::Threading::Core::SignalHandler *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            *signalNotifier = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AttachToSemaphoreWithTimeout(impl::abi_arg_in<hstring> name, impl::abi_arg_in<Windows::System::Threading::Core::SignalHandler> handler, impl::abi_arg_in<Windows::Foundation::TimeSpan> timeout, impl::abi_arg_out<Windows::System::Threading::Core::ISignalNotifier> signalNotifier) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *signalNotifier = detach_abi(this->shim().AttachToSemaphore(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::System::Threading::Core::SignalHandler *>(&handler), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&timeout)));
            return S_OK;
        }
        catch (...)
        {
            *signalNotifier = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::System::Threading::Core {

template <typename D> Windows::System::Threading::Core::SignalNotifier impl_ISignalNotifierStatics<D>::AttachToEvent(hstring_view name, const Windows::System::Threading::Core::SignalHandler & handler) const
{
    Windows::System::Threading::Core::SignalNotifier signalNotifier { nullptr };
    check_hresult(WINRT_SHIM(ISignalNotifierStatics)->abi_AttachToEvent(get_abi(name), get_abi(handler), put_abi(signalNotifier)));
    return signalNotifier;
}

template <typename D> Windows::System::Threading::Core::SignalNotifier impl_ISignalNotifierStatics<D>::AttachToEvent(hstring_view name, const Windows::System::Threading::Core::SignalHandler & handler, const Windows::Foundation::TimeSpan & timeout) const
{
    Windows::System::Threading::Core::SignalNotifier signalNotifier { nullptr };
    check_hresult(WINRT_SHIM(ISignalNotifierStatics)->abi_AttachToEventWithTimeout(get_abi(name), get_abi(handler), get_abi(timeout), put_abi(signalNotifier)));
    return signalNotifier;
}

template <typename D> Windows::System::Threading::Core::SignalNotifier impl_ISignalNotifierStatics<D>::AttachToSemaphore(hstring_view name, const Windows::System::Threading::Core::SignalHandler & handler) const
{
    Windows::System::Threading::Core::SignalNotifier signalNotifier { nullptr };
    check_hresult(WINRT_SHIM(ISignalNotifierStatics)->abi_AttachToSemaphore(get_abi(name), get_abi(handler), put_abi(signalNotifier)));
    return signalNotifier;
}

template <typename D> Windows::System::Threading::Core::SignalNotifier impl_ISignalNotifierStatics<D>::AttachToSemaphore(hstring_view name, const Windows::System::Threading::Core::SignalHandler & handler, const Windows::Foundation::TimeSpan & timeout) const
{
    Windows::System::Threading::Core::SignalNotifier signalNotifier { nullptr };
    check_hresult(WINRT_SHIM(ISignalNotifierStatics)->abi_AttachToSemaphoreWithTimeout(get_abi(name), get_abi(handler), get_abi(timeout), put_abi(signalNotifier)));
    return signalNotifier;
}

template <typename D> Windows::System::Threading::Core::PreallocatedWorkItem impl_IPreallocatedWorkItemFactory<D>::CreateWorkItem(const Windows::System::Threading::WorkItemHandler & handler) const
{
    Windows::System::Threading::Core::PreallocatedWorkItem workItem { nullptr };
    check_hresult(WINRT_SHIM(IPreallocatedWorkItemFactory)->abi_CreateWorkItem(get_abi(handler), put_abi(workItem)));
    return workItem;
}

template <typename D> Windows::System::Threading::Core::PreallocatedWorkItem impl_IPreallocatedWorkItemFactory<D>::CreateWorkItemWithPriority(const Windows::System::Threading::WorkItemHandler & handler, Windows::System::Threading::WorkItemPriority priority) const
{
    Windows::System::Threading::Core::PreallocatedWorkItem WorkItem { nullptr };
    check_hresult(WINRT_SHIM(IPreallocatedWorkItemFactory)->abi_CreateWorkItemWithPriority(get_abi(handler), priority, put_abi(WorkItem)));
    return WorkItem;
}

template <typename D> Windows::System::Threading::Core::PreallocatedWorkItem impl_IPreallocatedWorkItemFactory<D>::CreateWorkItemWithPriorityAndOptions(const Windows::System::Threading::WorkItemHandler & handler, Windows::System::Threading::WorkItemPriority priority, Windows::System::Threading::WorkItemOptions options) const
{
    Windows::System::Threading::Core::PreallocatedWorkItem WorkItem { nullptr };
    check_hresult(WINRT_SHIM(IPreallocatedWorkItemFactory)->abi_CreateWorkItemWithPriorityAndOptions(get_abi(handler), priority, options, put_abi(WorkItem)));
    return WorkItem;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPreallocatedWorkItem<D>::RunAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IPreallocatedWorkItem)->abi_RunAsync(put_abi(operation)));
    return operation;
}

template <typename D> void impl_ISignalNotifier<D>::Enable() const
{
    check_hresult(WINRT_SHIM(ISignalNotifier)->abi_Enable());
}

template <typename D> void impl_ISignalNotifier<D>::Terminate() const
{
    check_hresult(WINRT_SHIM(ISignalNotifier)->abi_Terminate());
}

inline PreallocatedWorkItem::PreallocatedWorkItem(const Windows::System::Threading::WorkItemHandler & handler) :
    PreallocatedWorkItem(get_activation_factory<PreallocatedWorkItem, IPreallocatedWorkItemFactory>().CreateWorkItem(handler))
{}

inline PreallocatedWorkItem::PreallocatedWorkItem(const Windows::System::Threading::WorkItemHandler & handler, Windows::System::Threading::WorkItemPriority priority) :
    PreallocatedWorkItem(get_activation_factory<PreallocatedWorkItem, IPreallocatedWorkItemFactory>().CreateWorkItemWithPriority(handler, priority))
{}

inline PreallocatedWorkItem::PreallocatedWorkItem(const Windows::System::Threading::WorkItemHandler & handler, Windows::System::Threading::WorkItemPriority priority, Windows::System::Threading::WorkItemOptions options) :
    PreallocatedWorkItem(get_activation_factory<PreallocatedWorkItem, IPreallocatedWorkItemFactory>().CreateWorkItemWithPriorityAndOptions(handler, priority, options))
{}

inline Windows::System::Threading::Core::SignalNotifier SignalNotifier::AttachToEvent(hstring_view name, const Windows::System::Threading::Core::SignalHandler & handler)
{
    return get_activation_factory<SignalNotifier, ISignalNotifierStatics>().AttachToEvent(name, handler);
}

inline Windows::System::Threading::Core::SignalNotifier SignalNotifier::AttachToEvent(hstring_view name, const Windows::System::Threading::Core::SignalHandler & handler, const Windows::Foundation::TimeSpan & timeout)
{
    return get_activation_factory<SignalNotifier, ISignalNotifierStatics>().AttachToEvent(name, handler, timeout);
}

inline Windows::System::Threading::Core::SignalNotifier SignalNotifier::AttachToSemaphore(hstring_view name, const Windows::System::Threading::Core::SignalHandler & handler)
{
    return get_activation_factory<SignalNotifier, ISignalNotifierStatics>().AttachToSemaphore(name, handler);
}

inline Windows::System::Threading::Core::SignalNotifier SignalNotifier::AttachToSemaphore(hstring_view name, const Windows::System::Threading::Core::SignalHandler & handler, const Windows::Foundation::TimeSpan & timeout)
{
    return get_activation_factory<SignalNotifier, ISignalNotifierStatics>().AttachToSemaphore(name, handler, timeout);
}

}

}
#pragma warning(pop)
