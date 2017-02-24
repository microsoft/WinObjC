// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.System.Threading.3.h"
#include "Windows.System.h"

WINRT_EXPORT namespace winrt {

namespace Windows::System::Threading {

template <typename L> TimerDestroyedHandler::TimerDestroyedHandler(L lambda) :
    TimerDestroyedHandler(impl::make_delegate<impl_TimerDestroyedHandler<L>, TimerDestroyedHandler>(std::forward<L>(lambda)))
{}

template <typename F> TimerDestroyedHandler::TimerDestroyedHandler(F * function) :
    TimerDestroyedHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> TimerDestroyedHandler::TimerDestroyedHandler(O * object, M method) :
    TimerDestroyedHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void TimerDestroyedHandler::operator()(const Windows::System::Threading::ThreadPoolTimer & timer) const
{
    check_hresult((*(abi<TimerDestroyedHandler> **)this)->abi_Invoke(get_abi(timer)));
}

template <typename L> TimerElapsedHandler::TimerElapsedHandler(L lambda) :
    TimerElapsedHandler(impl::make_delegate<impl_TimerElapsedHandler<L>, TimerElapsedHandler>(std::forward<L>(lambda)))
{}

template <typename F> TimerElapsedHandler::TimerElapsedHandler(F * function) :
    TimerElapsedHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> TimerElapsedHandler::TimerElapsedHandler(O * object, M method) :
    TimerElapsedHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void TimerElapsedHandler::operator()(const Windows::System::Threading::ThreadPoolTimer & timer) const
{
    check_hresult((*(abi<TimerElapsedHandler> **)this)->abi_Invoke(get_abi(timer)));
}

template <typename L> WorkItemHandler::WorkItemHandler(L lambda) :
    WorkItemHandler(impl::make_delegate<impl_WorkItemHandler<L>, WorkItemHandler>(std::forward<L>(lambda)))
{}

template <typename F> WorkItemHandler::WorkItemHandler(F * function) :
    WorkItemHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> WorkItemHandler::WorkItemHandler(O * object, M method) :
    WorkItemHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void WorkItemHandler::operator()(const Windows::Foundation::IAsyncAction & operation) const
{
    check_hresult((*(abi<WorkItemHandler> **)this)->abi_Invoke(get_abi(operation)));
}

}

namespace impl {

template <typename D>
struct produce<D, Windows::System::Threading::IThreadPoolStatics> : produce_base<D, Windows::System::Threading::IThreadPoolStatics>
{
    HRESULT __stdcall abi_RunAsync(impl::abi_arg_in<Windows::System::Threading::WorkItemHandler> handler, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RunAsync(*reinterpret_cast<const Windows::System::Threading::WorkItemHandler *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RunWithPriorityAsync(impl::abi_arg_in<Windows::System::Threading::WorkItemHandler> handler, Windows::System::Threading::WorkItemPriority priority, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RunAsync(*reinterpret_cast<const Windows::System::Threading::WorkItemHandler *>(&handler), priority));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RunWithPriorityAndOptionsAsync(impl::abi_arg_in<Windows::System::Threading::WorkItemHandler> handler, Windows::System::Threading::WorkItemPriority priority, Windows::System::Threading::WorkItemOptions options, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RunAsync(*reinterpret_cast<const Windows::System::Threading::WorkItemHandler *>(&handler), priority, options));
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
struct produce<D, Windows::System::Threading::IThreadPoolTimer> : produce_base<D, Windows::System::Threading::IThreadPoolTimer>
{
    HRESULT __stdcall get_Period(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Period());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Delay(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Delay());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Cancel() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Cancel();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::Threading::IThreadPoolTimerStatics> : produce_base<D, Windows::System::Threading::IThreadPoolTimerStatics>
{
    HRESULT __stdcall abi_CreatePeriodicTimer(impl::abi_arg_in<Windows::System::Threading::TimerElapsedHandler> handler, impl::abi_arg_in<Windows::Foundation::TimeSpan> period, impl::abi_arg_out<Windows::System::Threading::IThreadPoolTimer> timer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *timer = detach_abi(this->shim().CreatePeriodicTimer(*reinterpret_cast<const Windows::System::Threading::TimerElapsedHandler *>(&handler), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&period)));
            return S_OK;
        }
        catch (...)
        {
            *timer = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateTimer(impl::abi_arg_in<Windows::System::Threading::TimerElapsedHandler> handler, impl::abi_arg_in<Windows::Foundation::TimeSpan> delay, impl::abi_arg_out<Windows::System::Threading::IThreadPoolTimer> timer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *timer = detach_abi(this->shim().CreateTimer(*reinterpret_cast<const Windows::System::Threading::TimerElapsedHandler *>(&handler), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&delay)));
            return S_OK;
        }
        catch (...)
        {
            *timer = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreatePeriodicTimerWithCompletion(impl::abi_arg_in<Windows::System::Threading::TimerElapsedHandler> handler, impl::abi_arg_in<Windows::Foundation::TimeSpan> period, impl::abi_arg_in<Windows::System::Threading::TimerDestroyedHandler> destroyed, impl::abi_arg_out<Windows::System::Threading::IThreadPoolTimer> timer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *timer = detach_abi(this->shim().CreatePeriodicTimer(*reinterpret_cast<const Windows::System::Threading::TimerElapsedHandler *>(&handler), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&period), *reinterpret_cast<const Windows::System::Threading::TimerDestroyedHandler *>(&destroyed)));
            return S_OK;
        }
        catch (...)
        {
            *timer = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateTimerWithCompletion(impl::abi_arg_in<Windows::System::Threading::TimerElapsedHandler> handler, impl::abi_arg_in<Windows::Foundation::TimeSpan> delay, impl::abi_arg_in<Windows::System::Threading::TimerDestroyedHandler> destroyed, impl::abi_arg_out<Windows::System::Threading::IThreadPoolTimer> timer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *timer = detach_abi(this->shim().CreateTimer(*reinterpret_cast<const Windows::System::Threading::TimerElapsedHandler *>(&handler), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&delay), *reinterpret_cast<const Windows::System::Threading::TimerDestroyedHandler *>(&destroyed)));
            return S_OK;
        }
        catch (...)
        {
            *timer = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::System::Threading {

template <typename D> Windows::Foundation::IAsyncAction impl_IThreadPoolStatics<D>::RunAsync(const Windows::System::Threading::WorkItemHandler & handler) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IThreadPoolStatics)->abi_RunAsync(get_abi(handler), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IThreadPoolStatics<D>::RunAsync(const Windows::System::Threading::WorkItemHandler & handler, Windows::System::Threading::WorkItemPriority priority) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IThreadPoolStatics)->abi_RunWithPriorityAsync(get_abi(handler), priority, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IThreadPoolStatics<D>::RunAsync(const Windows::System::Threading::WorkItemHandler & handler, Windows::System::Threading::WorkItemPriority priority, Windows::System::Threading::WorkItemOptions options) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IThreadPoolStatics)->abi_RunWithPriorityAndOptionsAsync(get_abi(handler), priority, options, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::TimeSpan impl_IThreadPoolTimer<D>::Period() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IThreadPoolTimer)->get_Period(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IThreadPoolTimer<D>::Delay() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IThreadPoolTimer)->get_Delay(put_abi(value)));
    return value;
}

template <typename D> void impl_IThreadPoolTimer<D>::Cancel() const
{
    check_hresult(WINRT_SHIM(IThreadPoolTimer)->abi_Cancel());
}

template <typename D> Windows::System::Threading::ThreadPoolTimer impl_IThreadPoolTimerStatics<D>::CreatePeriodicTimer(const Windows::System::Threading::TimerElapsedHandler & handler, const Windows::Foundation::TimeSpan & period) const
{
    Windows::System::Threading::ThreadPoolTimer timer { nullptr };
    check_hresult(WINRT_SHIM(IThreadPoolTimerStatics)->abi_CreatePeriodicTimer(get_abi(handler), get_abi(period), put_abi(timer)));
    return timer;
}

template <typename D> Windows::System::Threading::ThreadPoolTimer impl_IThreadPoolTimerStatics<D>::CreateTimer(const Windows::System::Threading::TimerElapsedHandler & handler, const Windows::Foundation::TimeSpan & delay) const
{
    Windows::System::Threading::ThreadPoolTimer timer { nullptr };
    check_hresult(WINRT_SHIM(IThreadPoolTimerStatics)->abi_CreateTimer(get_abi(handler), get_abi(delay), put_abi(timer)));
    return timer;
}

template <typename D> Windows::System::Threading::ThreadPoolTimer impl_IThreadPoolTimerStatics<D>::CreatePeriodicTimer(const Windows::System::Threading::TimerElapsedHandler & handler, const Windows::Foundation::TimeSpan & period, const Windows::System::Threading::TimerDestroyedHandler & destroyed) const
{
    Windows::System::Threading::ThreadPoolTimer timer { nullptr };
    check_hresult(WINRT_SHIM(IThreadPoolTimerStatics)->abi_CreatePeriodicTimerWithCompletion(get_abi(handler), get_abi(period), get_abi(destroyed), put_abi(timer)));
    return timer;
}

template <typename D> Windows::System::Threading::ThreadPoolTimer impl_IThreadPoolTimerStatics<D>::CreateTimer(const Windows::System::Threading::TimerElapsedHandler & handler, const Windows::Foundation::TimeSpan & delay, const Windows::System::Threading::TimerDestroyedHandler & destroyed) const
{
    Windows::System::Threading::ThreadPoolTimer timer { nullptr };
    check_hresult(WINRT_SHIM(IThreadPoolTimerStatics)->abi_CreateTimerWithCompletion(get_abi(handler), get_abi(delay), get_abi(destroyed), put_abi(timer)));
    return timer;
}

inline Windows::Foundation::IAsyncAction ThreadPool::RunAsync(const Windows::System::Threading::WorkItemHandler & handler)
{
    return get_activation_factory<ThreadPool, IThreadPoolStatics>().RunAsync(handler);
}

inline Windows::Foundation::IAsyncAction ThreadPool::RunAsync(const Windows::System::Threading::WorkItemHandler & handler, Windows::System::Threading::WorkItemPriority priority)
{
    return get_activation_factory<ThreadPool, IThreadPoolStatics>().RunAsync(handler, priority);
}

inline Windows::Foundation::IAsyncAction ThreadPool::RunAsync(const Windows::System::Threading::WorkItemHandler & handler, Windows::System::Threading::WorkItemPriority priority, Windows::System::Threading::WorkItemOptions options)
{
    return get_activation_factory<ThreadPool, IThreadPoolStatics>().RunAsync(handler, priority, options);
}

inline Windows::System::Threading::ThreadPoolTimer ThreadPoolTimer::CreatePeriodicTimer(const Windows::System::Threading::TimerElapsedHandler & handler, const Windows::Foundation::TimeSpan & period)
{
    return get_activation_factory<ThreadPoolTimer, IThreadPoolTimerStatics>().CreatePeriodicTimer(handler, period);
}

inline Windows::System::Threading::ThreadPoolTimer ThreadPoolTimer::CreateTimer(const Windows::System::Threading::TimerElapsedHandler & handler, const Windows::Foundation::TimeSpan & delay)
{
    return get_activation_factory<ThreadPoolTimer, IThreadPoolTimerStatics>().CreateTimer(handler, delay);
}

inline Windows::System::Threading::ThreadPoolTimer ThreadPoolTimer::CreatePeriodicTimer(const Windows::System::Threading::TimerElapsedHandler & handler, const Windows::Foundation::TimeSpan & period, const Windows::System::Threading::TimerDestroyedHandler & destroyed)
{
    return get_activation_factory<ThreadPoolTimer, IThreadPoolTimerStatics>().CreatePeriodicTimer(handler, period, destroyed);
}

inline Windows::System::Threading::ThreadPoolTimer ThreadPoolTimer::CreateTimer(const Windows::System::Threading::TimerElapsedHandler & handler, const Windows::Foundation::TimeSpan & delay, const Windows::System::Threading::TimerDestroyedHandler & destroyed)
{
    return get_activation_factory<ThreadPoolTimer, IThreadPoolTimerStatics>().CreateTimer(handler, delay, destroyed);
}

}

}
#pragma warning(pop)
