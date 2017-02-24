// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "base.h"
#include <ctxtcall.h>
#include <ppltasks.h>

namespace winrt::ppl
{
    struct adapter
    {
        adapter() noexcept = default;

        adapter(Windows::Foundation::IUnknown const & object) : m_object(object)
        {
            m_object = object;
            m_agile = !!object.try_as<IAgileObject>();

            if (!m_agile)
            {
                check_hresult(::CoGetObjectContext(__uuidof(m_context), reinterpret_cast<void **>(put_abi(m_context))));
            }
        };

        template<typename T>
        operator T() const
        {
            if (m_agile)
            {
                return m_object.as<T>();
            }

            struct user_data
            {
                IUnknown * object;
                IStream * stream;
            };

            user_data data{ winrt::get_abi(m_object) };
            ComCallData param{ 0, 0, &data };

            check_hresult(m_context->ContextCallback([](ComCallData * param)
            {
                user_data & data = *static_cast<user_data *>(param->pUserDefined);

                return CoMarshalInterThreadInterfaceInStream(__uuidof(abi_default_interface<T>),
                    data.object,
                    &data.stream);
            }, &param, __uuidof(IContextCallback), 5, nullptr));

            T result = nullptr;

            check_hresult(CoGetInterfaceAndReleaseStream(data.stream,
                __uuidof(abi_default_interface<T>),
                reinterpret_cast<void **>(put_abi(result))));

            return result;
        }

    private:
        Windows::Foundation::IUnknown m_object;
        bool m_agile = false;
        com_ptr<IContextCallback> m_context;
    };

    inline auto create_task(Windows::Foundation::IAsyncAction const & async)
    {
        concurrency::task_completion_event<void> event;

        async.Completed([event](auto && ...)
        {
            event.set();
        });

        return concurrency::task<void>(event).then([=]
        {
            async.GetResults();
        });
    }

    template <typename TProgress>
    auto create_task(Windows::Foundation::IAsyncActionWithProgress<TProgress> const & async)
    {
        concurrency::task_completion_event<void> event;

        async.Completed([event](auto && ...)
        {
            event.set();
        });

        return concurrency::task<void>(event).then([=]
        {
            async.GetResults();
        });
    }

    template <typename TResult>
    auto create_task(Windows::Foundation::IAsyncOperation<TResult> const & async)
    {
        using adapted_result = std::conditional_t<impl::is_base_of_v<Windows::Foundation::IUnknown, TResult>, adapter, TResult>;

        concurrency::task_completion_event<void> event;

        async.Completed([event](auto && ...)
        {
            event.set();
        });

        return concurrency::task<void>(event).then([=]
        {
            return concurrency::create_task([=]() -> adapted_result { return async.GetResults(); });
        });
    }

    template <typename TResult, typename TProgress>
    auto create_task(Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress> const & async)
    {
        using adapted_result = std::conditional_t<impl::is_base_of_v<Windows::Foundation::IUnknown, TResult>, adapter, TResult>;
        concurrency::task_completion_event<void> event;

        async.Completed([event](auto && ...)
        {
            event.set();
        });

        return concurrency::task<void>(event).then([=]
        {
            return concurrency::create_task([=]() -> adapted_result { return async.GetResults(); });
        });
    }
}
