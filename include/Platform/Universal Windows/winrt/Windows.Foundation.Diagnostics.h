// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Storage.3.h"
#include "internal/Windows.Foundation.Diagnostics.3.h"
#include "Windows.Foundation.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Foundation::Diagnostics::IAsyncCausalityTracerStatics> : produce_base<D, Windows::Foundation::Diagnostics::IAsyncCausalityTracerStatics>
{
    HRESULT __stdcall abi_TraceOperationCreation(Windows::Foundation::Diagnostics::CausalityTraceLevel traceLevel, Windows::Foundation::Diagnostics::CausalitySource source, GUID platformId, uint64_t operationId, impl::abi_arg_in<hstring> operationName, uint64_t relatedContext) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TraceOperationCreation(traceLevel, source, platformId, operationId, *reinterpret_cast<const hstring *>(&operationName), relatedContext);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TraceOperationCompletion(Windows::Foundation::Diagnostics::CausalityTraceLevel traceLevel, Windows::Foundation::Diagnostics::CausalitySource source, GUID platformId, uint64_t operationId, Windows::Foundation::AsyncStatus status) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TraceOperationCompletion(traceLevel, source, platformId, operationId, status);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TraceOperationRelation(Windows::Foundation::Diagnostics::CausalityTraceLevel traceLevel, Windows::Foundation::Diagnostics::CausalitySource source, GUID platformId, uint64_t operationId, Windows::Foundation::Diagnostics::CausalityRelation relation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TraceOperationRelation(traceLevel, source, platformId, operationId, relation);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TraceSynchronousWorkStart(Windows::Foundation::Diagnostics::CausalityTraceLevel traceLevel, Windows::Foundation::Diagnostics::CausalitySource source, GUID platformId, uint64_t operationId, Windows::Foundation::Diagnostics::CausalitySynchronousWork work) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TraceSynchronousWorkStart(traceLevel, source, platformId, operationId, work);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TraceSynchronousWorkCompletion(Windows::Foundation::Diagnostics::CausalityTraceLevel traceLevel, Windows::Foundation::Diagnostics::CausalitySource source, Windows::Foundation::Diagnostics::CausalitySynchronousWork work) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TraceSynchronousWorkCompletion(traceLevel, source, work);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_TracingStatusChanged(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Foundation::Diagnostics::TracingStatusChangedEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().TracingStatusChanged(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Foundation::Diagnostics::TracingStatusChangedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_TracingStatusChanged(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TracingStatusChanged(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::Diagnostics::IErrorDetails> : produce_base<D, Windows::Foundation::Diagnostics::IErrorDetails>
{
    HRESULT __stdcall get_Description(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Description());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LongDescription(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LongDescription());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HelpUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HelpUri());
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
struct produce<D, Windows::Foundation::Diagnostics::IErrorDetailsStatics> : produce_base<D, Windows::Foundation::Diagnostics::IErrorDetailsStatics>
{
    HRESULT __stdcall abi_CreateFromHResultAsync(int32_t errorCode, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Diagnostics::ErrorDetails>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreateFromHResultAsync(errorCode));
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
struct produce<D, Windows::Foundation::Diagnostics::IErrorReportingSettings> : produce_base<D, Windows::Foundation::Diagnostics::IErrorReportingSettings>
{
    HRESULT __stdcall abi_SetErrorOptions(Windows::Foundation::Diagnostics::ErrorOptions value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetErrorOptions(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetErrorOptions(Windows::Foundation::Diagnostics::ErrorOptions * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetErrorOptions());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::Diagnostics::IFileLoggingSession> : produce_base<D, Windows::Foundation::Diagnostics::IFileLoggingSession>
{
    HRESULT __stdcall get_Name(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Name());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddLoggingChannel(impl::abi_arg_in<Windows::Foundation::Diagnostics::ILoggingChannel> loggingChannel) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddLoggingChannel(*reinterpret_cast<const Windows::Foundation::Diagnostics::ILoggingChannel *>(&loggingChannel));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddLoggingChannelWithLevel(impl::abi_arg_in<Windows::Foundation::Diagnostics::ILoggingChannel> loggingChannel, Windows::Foundation::Diagnostics::LoggingLevel maxLevel) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddLoggingChannel(*reinterpret_cast<const Windows::Foundation::Diagnostics::ILoggingChannel *>(&loggingChannel), maxLevel);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveLoggingChannel(impl::abi_arg_in<Windows::Foundation::Diagnostics::ILoggingChannel> loggingChannel) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveLoggingChannel(*reinterpret_cast<const Windows::Foundation::Diagnostics::ILoggingChannel *>(&loggingChannel));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CloseAndSaveToFileAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CloseAndSaveToFileAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_LogFileGenerated(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Foundation::Diagnostics::IFileLoggingSession, Windows::Foundation::Diagnostics::LogFileGeneratedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().LogFileGenerated(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Foundation::Diagnostics::IFileLoggingSession, Windows::Foundation::Diagnostics::LogFileGeneratedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_LogFileGenerated(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LogFileGenerated(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::Diagnostics::IFileLoggingSessionFactory> : produce_base<D, Windows::Foundation::Diagnostics::IFileLoggingSessionFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::Foundation::Diagnostics::IFileLoggingSession> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::Diagnostics::ILogFileGeneratedEventArgs> : produce_base<D, Windows::Foundation::Diagnostics::ILogFileGeneratedEventArgs>
{
    HRESULT __stdcall get_File(impl::abi_arg_out<Windows::Storage::IStorageFile> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().File());
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
struct produce<D, Windows::Foundation::Diagnostics::ILoggingActivity> : produce_base<D, Windows::Foundation::Diagnostics::ILoggingActivity>
{
    HRESULT __stdcall get_Name(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Name());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Id(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Id());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::Diagnostics::ILoggingActivity2> : produce_base<D, Windows::Foundation::Diagnostics::ILoggingActivity2>
{
    HRESULT __stdcall get_Channel(impl::abi_arg_out<Windows::Foundation::Diagnostics::ILoggingChannel> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Channel());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StopActivity(impl::abi_arg_in<hstring> stopEventName) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StopActivity(*reinterpret_cast<const hstring *>(&stopEventName));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StopActivityWithFields(impl::abi_arg_in<hstring> stopEventName, impl::abi_arg_in<Windows::Foundation::Diagnostics::ILoggingFields> fields) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StopActivity(*reinterpret_cast<const hstring *>(&stopEventName), *reinterpret_cast<const Windows::Foundation::Diagnostics::LoggingFields *>(&fields));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StopActivityWithFieldsAndOptions(impl::abi_arg_in<hstring> stopEventName, impl::abi_arg_in<Windows::Foundation::Diagnostics::ILoggingFields> fields, impl::abi_arg_in<Windows::Foundation::Diagnostics::ILoggingOptions> options) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StopActivity(*reinterpret_cast<const hstring *>(&stopEventName), *reinterpret_cast<const Windows::Foundation::Diagnostics::LoggingFields *>(&fields), *reinterpret_cast<const Windows::Foundation::Diagnostics::LoggingOptions *>(&options));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::Diagnostics::ILoggingActivityFactory> : produce_base<D, Windows::Foundation::Diagnostics::ILoggingActivityFactory>
{
    HRESULT __stdcall abi_CreateLoggingActivity(impl::abi_arg_in<hstring> activityName, impl::abi_arg_in<Windows::Foundation::Diagnostics::ILoggingChannel> loggingChannel, impl::abi_arg_out<Windows::Foundation::Diagnostics::ILoggingActivity> loggingActivity) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *loggingActivity = detach_abi(this->shim().CreateLoggingActivity(*reinterpret_cast<const hstring *>(&activityName), *reinterpret_cast<const Windows::Foundation::Diagnostics::ILoggingChannel *>(&loggingChannel)));
            return S_OK;
        }
        catch (...)
        {
            *loggingActivity = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateLoggingActivityWithLevel(impl::abi_arg_in<hstring> activityName, impl::abi_arg_in<Windows::Foundation::Diagnostics::ILoggingChannel> loggingChannel, Windows::Foundation::Diagnostics::LoggingLevel level, impl::abi_arg_out<Windows::Foundation::Diagnostics::ILoggingActivity> loggingActivity) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *loggingActivity = detach_abi(this->shim().CreateLoggingActivityWithLevel(*reinterpret_cast<const hstring *>(&activityName), *reinterpret_cast<const Windows::Foundation::Diagnostics::ILoggingChannel *>(&loggingChannel), level));
            return S_OK;
        }
        catch (...)
        {
            *loggingActivity = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::Diagnostics::ILoggingChannel> : produce_base<D, Windows::Foundation::Diagnostics::ILoggingChannel>
{
    HRESULT __stdcall get_Name(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Name());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Enabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Enabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Level(Windows::Foundation::Diagnostics::LoggingLevel * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Level());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LogMessage(impl::abi_arg_in<hstring> eventString) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LogMessage(*reinterpret_cast<const hstring *>(&eventString));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LogMessageWithLevel(impl::abi_arg_in<hstring> eventString, Windows::Foundation::Diagnostics::LoggingLevel level) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LogMessage(*reinterpret_cast<const hstring *>(&eventString), level);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LogValuePair(impl::abi_arg_in<hstring> value1, int32_t value2) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LogValuePair(*reinterpret_cast<const hstring *>(&value1), value2);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LogValuePairWithLevel(impl::abi_arg_in<hstring> value1, int32_t value2, Windows::Foundation::Diagnostics::LoggingLevel level) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LogValuePair(*reinterpret_cast<const hstring *>(&value1), value2, level);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_LoggingEnabled(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Foundation::Diagnostics::ILoggingChannel, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().LoggingEnabled(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Foundation::Diagnostics::ILoggingChannel, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_LoggingEnabled(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LoggingEnabled(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::Diagnostics::ILoggingChannel2> : produce_base<D, Windows::Foundation::Diagnostics::ILoggingChannel2>
{
    HRESULT __stdcall get_Id(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Id());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::Diagnostics::ILoggingChannelFactory> : produce_base<D, Windows::Foundation::Diagnostics::ILoggingChannelFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::Foundation::Diagnostics::ILoggingChannel> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::Diagnostics::ILoggingChannelFactory2> : produce_base<D, Windows::Foundation::Diagnostics::ILoggingChannelFactory2>
{
    HRESULT __stdcall abi_CreateWithOptions(impl::abi_arg_in<hstring> name, impl::abi_arg_in<Windows::Foundation::Diagnostics::ILoggingChannelOptions> options, impl::abi_arg_out<Windows::Foundation::Diagnostics::ILoggingChannel> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateWithOptions(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Foundation::Diagnostics::LoggingChannelOptions *>(&options)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithOptionsAndId(impl::abi_arg_in<hstring> name, impl::abi_arg_in<Windows::Foundation::Diagnostics::ILoggingChannelOptions> options, GUID id, impl::abi_arg_out<Windows::Foundation::Diagnostics::ILoggingChannel> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateWithOptionsAndId(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Foundation::Diagnostics::LoggingChannelOptions *>(&options), id));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::Diagnostics::ILoggingChannelOptions> : produce_base<D, Windows::Foundation::Diagnostics::ILoggingChannelOptions>
{
    HRESULT __stdcall get_Group(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Group());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Group(GUID value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Group(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::Diagnostics::ILoggingChannelOptionsFactory> : produce_base<D, Windows::Foundation::Diagnostics::ILoggingChannelOptionsFactory>
{
    HRESULT __stdcall abi_Create(GUID group, impl::abi_arg_out<Windows::Foundation::Diagnostics::ILoggingChannelOptions> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(group));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::Diagnostics::ILoggingFields> : produce_base<D, Windows::Foundation::Diagnostics::ILoggingFields>
{
    HRESULT __stdcall abi_Clear() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Clear();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_BeginStruct(impl::abi_arg_in<hstring> name) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BeginStruct(*reinterpret_cast<const hstring *>(&name));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_BeginStructWithTags(impl::abi_arg_in<hstring> name, int32_t tags) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BeginStruct(*reinterpret_cast<const hstring *>(&name), tags);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_EndStruct() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EndStruct();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddEmpty(impl::abi_arg_in<hstring> name) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddEmpty(*reinterpret_cast<const hstring *>(&name));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddEmptyWithFormat(impl::abi_arg_in<hstring> name, Windows::Foundation::Diagnostics::LoggingFieldFormat format) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddEmpty(*reinterpret_cast<const hstring *>(&name), format);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddEmptyWithFormatAndTags(impl::abi_arg_in<hstring> name, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddEmpty(*reinterpret_cast<const hstring *>(&name), format, tags);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddUInt8(impl::abi_arg_in<hstring> name, uint8_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddUInt8(*reinterpret_cast<const hstring *>(&name), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddUInt8WithFormat(impl::abi_arg_in<hstring> name, uint8_t value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddUInt8(*reinterpret_cast<const hstring *>(&name), value, format);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddUInt8WithFormatAndTags(impl::abi_arg_in<hstring> name, uint8_t value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddUInt8(*reinterpret_cast<const hstring *>(&name), value, format, tags);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddUInt8Array(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<uint8_t> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddUInt8Array(*reinterpret_cast<const hstring *>(&name), array_view<const uint8_t>(value, value + __valueSize));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddUInt8ArrayWithFormat(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<uint8_t> * value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddUInt8Array(*reinterpret_cast<const hstring *>(&name), array_view<const uint8_t>(value, value + __valueSize), format);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddUInt8ArrayWithFormatAndTags(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<uint8_t> * value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddUInt8Array(*reinterpret_cast<const hstring *>(&name), array_view<const uint8_t>(value, value + __valueSize), format, tags);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddInt16(impl::abi_arg_in<hstring> name, int16_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddInt16(*reinterpret_cast<const hstring *>(&name), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddInt16WithFormat(impl::abi_arg_in<hstring> name, int16_t value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddInt16(*reinterpret_cast<const hstring *>(&name), value, format);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddInt16WithFormatAndTags(impl::abi_arg_in<hstring> name, int16_t value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddInt16(*reinterpret_cast<const hstring *>(&name), value, format, tags);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddInt16Array(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<int16_t> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddInt16Array(*reinterpret_cast<const hstring *>(&name), array_view<const int16_t>(value, value + __valueSize));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddInt16ArrayWithFormat(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<int16_t> * value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddInt16Array(*reinterpret_cast<const hstring *>(&name), array_view<const int16_t>(value, value + __valueSize), format);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddInt16ArrayWithFormatAndTags(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<int16_t> * value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddInt16Array(*reinterpret_cast<const hstring *>(&name), array_view<const int16_t>(value, value + __valueSize), format, tags);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddUInt16(impl::abi_arg_in<hstring> name, uint16_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddUInt16(*reinterpret_cast<const hstring *>(&name), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddUInt16WithFormat(impl::abi_arg_in<hstring> name, uint16_t value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddUInt16(*reinterpret_cast<const hstring *>(&name), value, format);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddUInt16WithFormatAndTags(impl::abi_arg_in<hstring> name, uint16_t value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddUInt16(*reinterpret_cast<const hstring *>(&name), value, format, tags);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddUInt16Array(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<uint16_t> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddUInt16Array(*reinterpret_cast<const hstring *>(&name), array_view<const uint16_t>(value, value + __valueSize));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddUInt16ArrayWithFormat(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<uint16_t> * value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddUInt16Array(*reinterpret_cast<const hstring *>(&name), array_view<const uint16_t>(value, value + __valueSize), format);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddUInt16ArrayWithFormatAndTags(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<uint16_t> * value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddUInt16Array(*reinterpret_cast<const hstring *>(&name), array_view<const uint16_t>(value, value + __valueSize), format, tags);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddInt32(impl::abi_arg_in<hstring> name, int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddInt32(*reinterpret_cast<const hstring *>(&name), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddInt32WithFormat(impl::abi_arg_in<hstring> name, int32_t value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddInt32(*reinterpret_cast<const hstring *>(&name), value, format);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddInt32WithFormatAndTags(impl::abi_arg_in<hstring> name, int32_t value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddInt32(*reinterpret_cast<const hstring *>(&name), value, format, tags);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddInt32Array(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<int32_t> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddInt32Array(*reinterpret_cast<const hstring *>(&name), array_view<const int32_t>(value, value + __valueSize));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddInt32ArrayWithFormat(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<int32_t> * value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddInt32Array(*reinterpret_cast<const hstring *>(&name), array_view<const int32_t>(value, value + __valueSize), format);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddInt32ArrayWithFormatAndTags(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<int32_t> * value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddInt32Array(*reinterpret_cast<const hstring *>(&name), array_view<const int32_t>(value, value + __valueSize), format, tags);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddUInt32(impl::abi_arg_in<hstring> name, uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddUInt32(*reinterpret_cast<const hstring *>(&name), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddUInt32WithFormat(impl::abi_arg_in<hstring> name, uint32_t value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddUInt32(*reinterpret_cast<const hstring *>(&name), value, format);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddUInt32WithFormatAndTags(impl::abi_arg_in<hstring> name, uint32_t value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddUInt32(*reinterpret_cast<const hstring *>(&name), value, format, tags);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddUInt32Array(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<uint32_t> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddUInt32Array(*reinterpret_cast<const hstring *>(&name), array_view<const uint32_t>(value, value + __valueSize));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddUInt32ArrayWithFormat(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<uint32_t> * value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddUInt32Array(*reinterpret_cast<const hstring *>(&name), array_view<const uint32_t>(value, value + __valueSize), format);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddUInt32ArrayWithFormatAndTags(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<uint32_t> * value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddUInt32Array(*reinterpret_cast<const hstring *>(&name), array_view<const uint32_t>(value, value + __valueSize), format, tags);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddInt64(impl::abi_arg_in<hstring> name, int64_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddInt64(*reinterpret_cast<const hstring *>(&name), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddInt64WithFormat(impl::abi_arg_in<hstring> name, int64_t value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddInt64(*reinterpret_cast<const hstring *>(&name), value, format);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddInt64WithFormatAndTags(impl::abi_arg_in<hstring> name, int64_t value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddInt64(*reinterpret_cast<const hstring *>(&name), value, format, tags);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddInt64Array(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<int64_t> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddInt64Array(*reinterpret_cast<const hstring *>(&name), array_view<const int64_t>(value, value + __valueSize));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddInt64ArrayWithFormat(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<int64_t> * value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddInt64Array(*reinterpret_cast<const hstring *>(&name), array_view<const int64_t>(value, value + __valueSize), format);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddInt64ArrayWithFormatAndTags(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<int64_t> * value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddInt64Array(*reinterpret_cast<const hstring *>(&name), array_view<const int64_t>(value, value + __valueSize), format, tags);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddUInt64(impl::abi_arg_in<hstring> name, uint64_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddUInt64(*reinterpret_cast<const hstring *>(&name), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddUInt64WithFormat(impl::abi_arg_in<hstring> name, uint64_t value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddUInt64(*reinterpret_cast<const hstring *>(&name), value, format);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddUInt64WithFormatAndTags(impl::abi_arg_in<hstring> name, uint64_t value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddUInt64(*reinterpret_cast<const hstring *>(&name), value, format, tags);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddUInt64Array(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<uint64_t> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddUInt64Array(*reinterpret_cast<const hstring *>(&name), array_view<const uint64_t>(value, value + __valueSize));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddUInt64ArrayWithFormat(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<uint64_t> * value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddUInt64Array(*reinterpret_cast<const hstring *>(&name), array_view<const uint64_t>(value, value + __valueSize), format);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddUInt64ArrayWithFormatAndTags(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<uint64_t> * value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddUInt64Array(*reinterpret_cast<const hstring *>(&name), array_view<const uint64_t>(value, value + __valueSize), format, tags);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddSingle(impl::abi_arg_in<hstring> name, float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddSingle(*reinterpret_cast<const hstring *>(&name), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddSingleWithFormat(impl::abi_arg_in<hstring> name, float value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddSingle(*reinterpret_cast<const hstring *>(&name), value, format);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddSingleWithFormatAndTags(impl::abi_arg_in<hstring> name, float value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddSingle(*reinterpret_cast<const hstring *>(&name), value, format, tags);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddSingleArray(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<float> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddSingleArray(*reinterpret_cast<const hstring *>(&name), array_view<const float>(value, value + __valueSize));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddSingleArrayWithFormat(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<float> * value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddSingleArray(*reinterpret_cast<const hstring *>(&name), array_view<const float>(value, value + __valueSize), format);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddSingleArrayWithFormatAndTags(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<float> * value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddSingleArray(*reinterpret_cast<const hstring *>(&name), array_view<const float>(value, value + __valueSize), format, tags);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddDouble(impl::abi_arg_in<hstring> name, double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddDouble(*reinterpret_cast<const hstring *>(&name), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddDoubleWithFormat(impl::abi_arg_in<hstring> name, double value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddDouble(*reinterpret_cast<const hstring *>(&name), value, format);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddDoubleWithFormatAndTags(impl::abi_arg_in<hstring> name, double value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddDouble(*reinterpret_cast<const hstring *>(&name), value, format, tags);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddDoubleArray(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<double> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddDoubleArray(*reinterpret_cast<const hstring *>(&name), array_view<const double>(value, value + __valueSize));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddDoubleArrayWithFormat(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<double> * value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddDoubleArray(*reinterpret_cast<const hstring *>(&name), array_view<const double>(value, value + __valueSize), format);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddDoubleArrayWithFormatAndTags(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<double> * value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddDoubleArray(*reinterpret_cast<const hstring *>(&name), array_view<const double>(value, value + __valueSize), format, tags);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddChar16(impl::abi_arg_in<hstring> name, wchar_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddChar16(*reinterpret_cast<const hstring *>(&name), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddChar16WithFormat(impl::abi_arg_in<hstring> name, wchar_t value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddChar16(*reinterpret_cast<const hstring *>(&name), value, format);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddChar16WithFormatAndTags(impl::abi_arg_in<hstring> name, wchar_t value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddChar16(*reinterpret_cast<const hstring *>(&name), value, format, tags);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddChar16Array(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<wchar_t> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddChar16Array(*reinterpret_cast<const hstring *>(&name), array_view<const wchar_t>(value, value + __valueSize));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddChar16ArrayWithFormat(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<wchar_t> * value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddChar16Array(*reinterpret_cast<const hstring *>(&name), array_view<const wchar_t>(value, value + __valueSize), format);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddChar16ArrayWithFormatAndTags(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<wchar_t> * value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddChar16Array(*reinterpret_cast<const hstring *>(&name), array_view<const wchar_t>(value, value + __valueSize), format, tags);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddBoolean(impl::abi_arg_in<hstring> name, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddBoolean(*reinterpret_cast<const hstring *>(&name), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddBooleanWithFormat(impl::abi_arg_in<hstring> name, bool value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddBoolean(*reinterpret_cast<const hstring *>(&name), value, format);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddBooleanWithFormatAndTags(impl::abi_arg_in<hstring> name, bool value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddBoolean(*reinterpret_cast<const hstring *>(&name), value, format, tags);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddBooleanArray(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<bool> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddBooleanArray(*reinterpret_cast<const hstring *>(&name), array_view<const bool>(value, value + __valueSize));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddBooleanArrayWithFormat(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<bool> * value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddBooleanArray(*reinterpret_cast<const hstring *>(&name), array_view<const bool>(value, value + __valueSize), format);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddBooleanArrayWithFormatAndTags(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<bool> * value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddBooleanArray(*reinterpret_cast<const hstring *>(&name), array_view<const bool>(value, value + __valueSize), format, tags);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddString(impl::abi_arg_in<hstring> name, impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddString(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddStringWithFormat(impl::abi_arg_in<hstring> name, impl::abi_arg_in<hstring> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddString(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const hstring *>(&value), format);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddStringWithFormatAndTags(impl::abi_arg_in<hstring> name, impl::abi_arg_in<hstring> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddString(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const hstring *>(&value), format, tags);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddStringArray(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<hstring> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddStringArray(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddStringArrayWithFormat(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<hstring> * value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddStringArray(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const hstring *>(&value), format);
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddStringArrayWithFormatAndTags(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<hstring> * value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddStringArray(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const hstring *>(&value), format, tags);
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddGuid(impl::abi_arg_in<hstring> name, GUID value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddGuid(*reinterpret_cast<const hstring *>(&name), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddGuidWithFormat(impl::abi_arg_in<hstring> name, GUID value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddGuid(*reinterpret_cast<const hstring *>(&name), value, format);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddGuidWithFormatAndTags(impl::abi_arg_in<hstring> name, GUID value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddGuid(*reinterpret_cast<const hstring *>(&name), value, format, tags);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddGuidArray(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<GUID> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddGuidArray(*reinterpret_cast<const hstring *>(&name), array_view<const GUID>(value, value + __valueSize));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddGuidArrayWithFormat(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<GUID> * value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddGuidArray(*reinterpret_cast<const hstring *>(&name), array_view<const GUID>(value, value + __valueSize), format);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddGuidArrayWithFormatAndTags(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<GUID> * value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddGuidArray(*reinterpret_cast<const hstring *>(&name), array_view<const GUID>(value, value + __valueSize), format, tags);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddDateTime(impl::abi_arg_in<hstring> name, impl::abi_arg_in<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddDateTime(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Foundation::DateTime *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddDateTimeWithFormat(impl::abi_arg_in<hstring> name, impl::abi_arg_in<Windows::Foundation::DateTime> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddDateTime(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Foundation::DateTime *>(&value), format);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddDateTimeWithFormatAndTags(impl::abi_arg_in<hstring> name, impl::abi_arg_in<Windows::Foundation::DateTime> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddDateTime(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Foundation::DateTime *>(&value), format, tags);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddDateTimeArray(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<Windows::Foundation::DateTime> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddDateTimeArray(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Foundation::DateTime *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddDateTimeArrayWithFormat(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<Windows::Foundation::DateTime> * value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddDateTimeArray(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Foundation::DateTime *>(&value), format);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddDateTimeArrayWithFormatAndTags(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<Windows::Foundation::DateTime> * value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddDateTimeArray(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Foundation::DateTime *>(&value), format, tags);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddTimeSpan(impl::abi_arg_in<hstring> name, impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddTimeSpan(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddTimeSpanWithFormat(impl::abi_arg_in<hstring> name, impl::abi_arg_in<Windows::Foundation::TimeSpan> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddTimeSpan(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value), format);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddTimeSpanWithFormatAndTags(impl::abi_arg_in<hstring> name, impl::abi_arg_in<Windows::Foundation::TimeSpan> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddTimeSpan(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value), format, tags);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddTimeSpanArray(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<Windows::Foundation::TimeSpan> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddTimeSpanArray(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddTimeSpanArrayWithFormat(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<Windows::Foundation::TimeSpan> * value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddTimeSpanArray(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value), format);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddTimeSpanArrayWithFormatAndTags(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<Windows::Foundation::TimeSpan> * value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddTimeSpanArray(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value), format, tags);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddPoint(impl::abi_arg_in<hstring> name, impl::abi_arg_in<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddPoint(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Foundation::Point *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddPointWithFormat(impl::abi_arg_in<hstring> name, impl::abi_arg_in<Windows::Foundation::Point> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddPoint(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Foundation::Point *>(&value), format);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddPointWithFormatAndTags(impl::abi_arg_in<hstring> name, impl::abi_arg_in<Windows::Foundation::Point> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddPoint(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Foundation::Point *>(&value), format, tags);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddPointArray(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<Windows::Foundation::Point> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddPointArray(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Foundation::Point *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddPointArrayWithFormat(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<Windows::Foundation::Point> * value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddPointArray(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Foundation::Point *>(&value), format);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddPointArrayWithFormatAndTags(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<Windows::Foundation::Point> * value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddPointArray(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Foundation::Point *>(&value), format, tags);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddSize(impl::abi_arg_in<hstring> name, impl::abi_arg_in<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddSize(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Foundation::Size *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddSizeWithFormat(impl::abi_arg_in<hstring> name, impl::abi_arg_in<Windows::Foundation::Size> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddSize(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Foundation::Size *>(&value), format);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddSizeWithFormatAndTags(impl::abi_arg_in<hstring> name, impl::abi_arg_in<Windows::Foundation::Size> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddSize(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Foundation::Size *>(&value), format, tags);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddSizeArray(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<Windows::Foundation::Size> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddSizeArray(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Foundation::Size *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddSizeArrayWithFormat(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<Windows::Foundation::Size> * value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddSizeArray(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Foundation::Size *>(&value), format);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddSizeArrayWithFormatAndTags(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<Windows::Foundation::Size> * value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddSizeArray(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Foundation::Size *>(&value), format, tags);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddRect(impl::abi_arg_in<hstring> name, impl::abi_arg_in<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddRect(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Foundation::Rect *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddRectWithFormat(impl::abi_arg_in<hstring> name, impl::abi_arg_in<Windows::Foundation::Rect> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddRect(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Foundation::Rect *>(&value), format);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddRectWithFormatAndTags(impl::abi_arg_in<hstring> name, impl::abi_arg_in<Windows::Foundation::Rect> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddRect(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Foundation::Rect *>(&value), format, tags);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddRectArray(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<Windows::Foundation::Rect> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddRectArray(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Foundation::Rect *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddRectArrayWithFormat(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<Windows::Foundation::Rect> * value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddRectArray(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Foundation::Rect *>(&value), format);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddRectArrayWithFormatAndTags(impl::abi_arg_in<hstring> name, uint32_t __valueSize, impl::abi_arg_in<Windows::Foundation::Rect> * value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddRectArray(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Foundation::Rect *>(&value), format, tags);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::Diagnostics::ILoggingOptions> : produce_base<D, Windows::Foundation::Diagnostics::ILoggingOptions>
{
    HRESULT __stdcall get_Keywords(int64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Keywords());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Keywords(int64_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Keywords(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Tags(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Tags());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Tags(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Tags(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Task(int16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Task());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Task(int16_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Task(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Opcode(Windows::Foundation::Diagnostics::LoggingOpcode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Opcode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Opcode(Windows::Foundation::Diagnostics::LoggingOpcode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Opcode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ActivityId(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ActivityId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ActivityId(GUID value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ActivityId(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RelatedActivityId(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RelatedActivityId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RelatedActivityId(GUID value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RelatedActivityId(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::Diagnostics::ILoggingOptionsFactory> : produce_base<D, Windows::Foundation::Diagnostics::ILoggingOptionsFactory>
{
    HRESULT __stdcall abi_CreateWithKeywords(int64_t keywords, impl::abi_arg_out<Windows::Foundation::Diagnostics::ILoggingOptions> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateWithKeywords(keywords));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::Diagnostics::ILoggingSession> : produce_base<D, Windows::Foundation::Diagnostics::ILoggingSession>
{
    HRESULT __stdcall get_Name(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Name());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SaveToFileAsync(impl::abi_arg_in<Windows::Storage::IStorageFolder> folder, impl::abi_arg_in<hstring> fileName, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().SaveToFileAsync(*reinterpret_cast<const Windows::Storage::IStorageFolder *>(&folder), *reinterpret_cast<const hstring *>(&fileName)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddLoggingChannel(impl::abi_arg_in<Windows::Foundation::Diagnostics::ILoggingChannel> loggingChannel) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddLoggingChannel(*reinterpret_cast<const Windows::Foundation::Diagnostics::ILoggingChannel *>(&loggingChannel));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddLoggingChannelWithLevel(impl::abi_arg_in<Windows::Foundation::Diagnostics::ILoggingChannel> loggingChannel, Windows::Foundation::Diagnostics::LoggingLevel maxLevel) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddLoggingChannel(*reinterpret_cast<const Windows::Foundation::Diagnostics::ILoggingChannel *>(&loggingChannel), maxLevel);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveLoggingChannel(impl::abi_arg_in<Windows::Foundation::Diagnostics::ILoggingChannel> loggingChannel) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveLoggingChannel(*reinterpret_cast<const Windows::Foundation::Diagnostics::ILoggingChannel *>(&loggingChannel));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::Diagnostics::ILoggingSessionFactory> : produce_base<D, Windows::Foundation::Diagnostics::ILoggingSessionFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::Foundation::Diagnostics::ILoggingSession> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::Diagnostics::ILoggingTarget> : produce_base<D, Windows::Foundation::Diagnostics::ILoggingTarget>
{
    HRESULT __stdcall abi_IsEnabled(bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsEnabledWithLevel(Windows::Foundation::Diagnostics::LoggingLevel level, bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsEnabled(level));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsEnabledWithLevelAndKeywords(Windows::Foundation::Diagnostics::LoggingLevel level, int64_t keywords, bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsEnabled(level, keywords));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LogEvent(impl::abi_arg_in<hstring> eventName) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LogEvent(*reinterpret_cast<const hstring *>(&eventName));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LogEventWithFields(impl::abi_arg_in<hstring> eventName, impl::abi_arg_in<Windows::Foundation::Diagnostics::ILoggingFields> fields) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LogEvent(*reinterpret_cast<const hstring *>(&eventName), *reinterpret_cast<const Windows::Foundation::Diagnostics::LoggingFields *>(&fields));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LogEventWithFieldsAndLevel(impl::abi_arg_in<hstring> eventName, impl::abi_arg_in<Windows::Foundation::Diagnostics::ILoggingFields> fields, Windows::Foundation::Diagnostics::LoggingLevel level) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LogEvent(*reinterpret_cast<const hstring *>(&eventName), *reinterpret_cast<const Windows::Foundation::Diagnostics::LoggingFields *>(&fields), level);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LogEventWithFieldsAndOptions(impl::abi_arg_in<hstring> eventName, impl::abi_arg_in<Windows::Foundation::Diagnostics::ILoggingFields> fields, Windows::Foundation::Diagnostics::LoggingLevel level, impl::abi_arg_in<Windows::Foundation::Diagnostics::ILoggingOptions> options) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LogEvent(*reinterpret_cast<const hstring *>(&eventName), *reinterpret_cast<const Windows::Foundation::Diagnostics::LoggingFields *>(&fields), level, *reinterpret_cast<const Windows::Foundation::Diagnostics::LoggingOptions *>(&options));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartActivity(impl::abi_arg_in<hstring> startEventName, impl::abi_arg_out<Windows::Foundation::Diagnostics::ILoggingActivity> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().StartActivity(*reinterpret_cast<const hstring *>(&startEventName)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartActivityWithFields(impl::abi_arg_in<hstring> startEventName, impl::abi_arg_in<Windows::Foundation::Diagnostics::ILoggingFields> fields, impl::abi_arg_out<Windows::Foundation::Diagnostics::ILoggingActivity> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().StartActivity(*reinterpret_cast<const hstring *>(&startEventName), *reinterpret_cast<const Windows::Foundation::Diagnostics::LoggingFields *>(&fields)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartActivityWithFieldsAndLevel(impl::abi_arg_in<hstring> startEventName, impl::abi_arg_in<Windows::Foundation::Diagnostics::ILoggingFields> fields, Windows::Foundation::Diagnostics::LoggingLevel level, impl::abi_arg_out<Windows::Foundation::Diagnostics::ILoggingActivity> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().StartActivity(*reinterpret_cast<const hstring *>(&startEventName), *reinterpret_cast<const Windows::Foundation::Diagnostics::LoggingFields *>(&fields), level));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartActivityWithFieldsAndOptions(impl::abi_arg_in<hstring> startEventName, impl::abi_arg_in<Windows::Foundation::Diagnostics::ILoggingFields> fields, Windows::Foundation::Diagnostics::LoggingLevel level, impl::abi_arg_in<Windows::Foundation::Diagnostics::ILoggingOptions> options, impl::abi_arg_out<Windows::Foundation::Diagnostics::ILoggingActivity> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().StartActivity(*reinterpret_cast<const hstring *>(&startEventName), *reinterpret_cast<const Windows::Foundation::Diagnostics::LoggingFields *>(&fields), level, *reinterpret_cast<const Windows::Foundation::Diagnostics::LoggingOptions *>(&options)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::Diagnostics::ITracingStatusChangedEventArgs> : produce_base<D, Windows::Foundation::Diagnostics::ITracingStatusChangedEventArgs>
{
    HRESULT __stdcall get_Enabled(bool * enabled) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *enabled = detach_abi(this->shim().Enabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TraceLevel(Windows::Foundation::Diagnostics::CausalityTraceLevel * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TraceLevel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Foundation::Diagnostics {

template <typename D> bool impl_ITracingStatusChangedEventArgs<D>::Enabled() const
{
    bool enabled {};
    check_hresult(WINRT_SHIM(ITracingStatusChangedEventArgs)->get_Enabled(&enabled));
    return enabled;
}

template <typename D> Windows::Foundation::Diagnostics::CausalityTraceLevel impl_ITracingStatusChangedEventArgs<D>::TraceLevel() const
{
    Windows::Foundation::Diagnostics::CausalityTraceLevel value {};
    check_hresult(WINRT_SHIM(ITracingStatusChangedEventArgs)->get_TraceLevel(&value));
    return value;
}

template <typename D> void impl_IAsyncCausalityTracerStatics<D>::TraceOperationCreation(Windows::Foundation::Diagnostics::CausalityTraceLevel traceLevel, Windows::Foundation::Diagnostics::CausalitySource source, GUID platformId, uint64_t operationId, hstring_view operationName, uint64_t relatedContext) const
{
    check_hresult(WINRT_SHIM(IAsyncCausalityTracerStatics)->abi_TraceOperationCreation(traceLevel, source, platformId, operationId, get_abi(operationName), relatedContext));
}

template <typename D> void impl_IAsyncCausalityTracerStatics<D>::TraceOperationCompletion(Windows::Foundation::Diagnostics::CausalityTraceLevel traceLevel, Windows::Foundation::Diagnostics::CausalitySource source, GUID platformId, uint64_t operationId, Windows::Foundation::AsyncStatus status) const
{
    check_hresult(WINRT_SHIM(IAsyncCausalityTracerStatics)->abi_TraceOperationCompletion(traceLevel, source, platformId, operationId, status));
}

template <typename D> void impl_IAsyncCausalityTracerStatics<D>::TraceOperationRelation(Windows::Foundation::Diagnostics::CausalityTraceLevel traceLevel, Windows::Foundation::Diagnostics::CausalitySource source, GUID platformId, uint64_t operationId, Windows::Foundation::Diagnostics::CausalityRelation relation) const
{
    check_hresult(WINRT_SHIM(IAsyncCausalityTracerStatics)->abi_TraceOperationRelation(traceLevel, source, platformId, operationId, relation));
}

template <typename D> void impl_IAsyncCausalityTracerStatics<D>::TraceSynchronousWorkStart(Windows::Foundation::Diagnostics::CausalityTraceLevel traceLevel, Windows::Foundation::Diagnostics::CausalitySource source, GUID platformId, uint64_t operationId, Windows::Foundation::Diagnostics::CausalitySynchronousWork work) const
{
    check_hresult(WINRT_SHIM(IAsyncCausalityTracerStatics)->abi_TraceSynchronousWorkStart(traceLevel, source, platformId, operationId, work));
}

template <typename D> void impl_IAsyncCausalityTracerStatics<D>::TraceSynchronousWorkCompletion(Windows::Foundation::Diagnostics::CausalityTraceLevel traceLevel, Windows::Foundation::Diagnostics::CausalitySource source, Windows::Foundation::Diagnostics::CausalitySynchronousWork work) const
{
    check_hresult(WINRT_SHIM(IAsyncCausalityTracerStatics)->abi_TraceSynchronousWorkCompletion(traceLevel, source, work));
}

template <typename D> event_token impl_IAsyncCausalityTracerStatics<D>::TracingStatusChanged(const Windows::Foundation::EventHandler<Windows::Foundation::Diagnostics::TracingStatusChangedEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IAsyncCausalityTracerStatics)->add_TracingStatusChanged(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IAsyncCausalityTracerStatics> impl_IAsyncCausalityTracerStatics<D>::TracingStatusChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::Diagnostics::TracingStatusChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IAsyncCausalityTracerStatics>(this, &ABI::Windows::Foundation::Diagnostics::IAsyncCausalityTracerStatics::remove_TracingStatusChanged, TracingStatusChanged(handler));
}

template <typename D> void impl_IAsyncCausalityTracerStatics<D>::TracingStatusChanged(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IAsyncCausalityTracerStatics)->remove_TracingStatusChanged(cookie));
}

template <typename D> void impl_IErrorReportingSettings<D>::SetErrorOptions(Windows::Foundation::Diagnostics::ErrorOptions value) const
{
    check_hresult(WINRT_SHIM(IErrorReportingSettings)->abi_SetErrorOptions(value));
}

template <typename D> Windows::Foundation::Diagnostics::ErrorOptions impl_IErrorReportingSettings<D>::GetErrorOptions() const
{
    Windows::Foundation::Diagnostics::ErrorOptions value {};
    check_hresult(WINRT_SHIM(IErrorReportingSettings)->abi_GetErrorOptions(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Diagnostics::ErrorDetails> impl_IErrorDetailsStatics<D>::CreateFromHResultAsync(int32_t errorCode) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Diagnostics::ErrorDetails> operation;
    check_hresult(WINRT_SHIM(IErrorDetailsStatics)->abi_CreateFromHResultAsync(errorCode, put_abi(operation)));
    return operation;
}

template <typename D> hstring impl_IErrorDetails<D>::Description() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IErrorDetails)->get_Description(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IErrorDetails<D>::LongDescription() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IErrorDetails)->get_LongDescription(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_IErrorDetails<D>::HelpUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IErrorDetails)->get_HelpUri(put_abi(value)));
    return value;
}

template <typename D> int64_t impl_ILoggingOptions<D>::Keywords() const
{
    int64_t value {};
    check_hresult(WINRT_SHIM(ILoggingOptions)->get_Keywords(&value));
    return value;
}

template <typename D> void impl_ILoggingOptions<D>::Keywords(int64_t value) const
{
    check_hresult(WINRT_SHIM(ILoggingOptions)->put_Keywords(value));
}

template <typename D> int32_t impl_ILoggingOptions<D>::Tags() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ILoggingOptions)->get_Tags(&value));
    return value;
}

template <typename D> void impl_ILoggingOptions<D>::Tags(int32_t value) const
{
    check_hresult(WINRT_SHIM(ILoggingOptions)->put_Tags(value));
}

template <typename D> int16_t impl_ILoggingOptions<D>::Task() const
{
    int16_t value {};
    check_hresult(WINRT_SHIM(ILoggingOptions)->get_Task(&value));
    return value;
}

template <typename D> void impl_ILoggingOptions<D>::Task(int16_t value) const
{
    check_hresult(WINRT_SHIM(ILoggingOptions)->put_Task(value));
}

template <typename D> Windows::Foundation::Diagnostics::LoggingOpcode impl_ILoggingOptions<D>::Opcode() const
{
    Windows::Foundation::Diagnostics::LoggingOpcode value {};
    check_hresult(WINRT_SHIM(ILoggingOptions)->get_Opcode(&value));
    return value;
}

template <typename D> void impl_ILoggingOptions<D>::Opcode(Windows::Foundation::Diagnostics::LoggingOpcode value) const
{
    check_hresult(WINRT_SHIM(ILoggingOptions)->put_Opcode(value));
}

template <typename D> GUID impl_ILoggingOptions<D>::ActivityId() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(ILoggingOptions)->get_ActivityId(&value));
    return value;
}

template <typename D> void impl_ILoggingOptions<D>::ActivityId(GUID value) const
{
    check_hresult(WINRT_SHIM(ILoggingOptions)->put_ActivityId(value));
}

template <typename D> GUID impl_ILoggingOptions<D>::RelatedActivityId() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(ILoggingOptions)->get_RelatedActivityId(&value));
    return value;
}

template <typename D> void impl_ILoggingOptions<D>::RelatedActivityId(GUID value) const
{
    check_hresult(WINRT_SHIM(ILoggingOptions)->put_RelatedActivityId(value));
}

template <typename D> Windows::Foundation::Diagnostics::LoggingOptions impl_ILoggingOptionsFactory<D>::CreateWithKeywords(int64_t keywords) const
{
    Windows::Foundation::Diagnostics::LoggingOptions result { nullptr };
    check_hresult(WINRT_SHIM(ILoggingOptionsFactory)->abi_CreateWithKeywords(keywords, put_abi(result)));
    return result;
}

template <typename D> GUID impl_ILoggingChannelOptions<D>::Group() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(ILoggingChannelOptions)->get_Group(&value));
    return value;
}

template <typename D> void impl_ILoggingChannelOptions<D>::Group(GUID value) const
{
    check_hresult(WINRT_SHIM(ILoggingChannelOptions)->put_Group(value));
}

template <typename D> Windows::Foundation::Diagnostics::LoggingChannelOptions impl_ILoggingChannelOptionsFactory<D>::Create(GUID group) const
{
    Windows::Foundation::Diagnostics::LoggingChannelOptions result { nullptr };
    check_hresult(WINRT_SHIM(ILoggingChannelOptionsFactory)->abi_Create(group, put_abi(result)));
    return result;
}

template <typename D> void impl_ILoggingFields<D>::Clear() const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_Clear());
}

template <typename D> void impl_ILoggingFields<D>::BeginStruct(hstring_view name) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_BeginStruct(get_abi(name)));
}

template <typename D> void impl_ILoggingFields<D>::BeginStruct(hstring_view name, int32_t tags) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_BeginStructWithTags(get_abi(name), tags));
}

template <typename D> void impl_ILoggingFields<D>::EndStruct() const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_EndStruct());
}

template <typename D> void impl_ILoggingFields<D>::AddEmpty(hstring_view name) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddEmpty(get_abi(name)));
}

template <typename D> void impl_ILoggingFields<D>::AddEmpty(hstring_view name, Windows::Foundation::Diagnostics::LoggingFieldFormat format) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddEmptyWithFormat(get_abi(name), format));
}

template <typename D> void impl_ILoggingFields<D>::AddEmpty(hstring_view name, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddEmptyWithFormatAndTags(get_abi(name), format, tags));
}

template <typename D> void impl_ILoggingFields<D>::AddUInt8(hstring_view name, uint8_t value) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddUInt8(get_abi(name), value));
}

template <typename D> void impl_ILoggingFields<D>::AddUInt8(hstring_view name, uint8_t value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddUInt8WithFormat(get_abi(name), value, format));
}

template <typename D> void impl_ILoggingFields<D>::AddUInt8(hstring_view name, uint8_t value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddUInt8WithFormatAndTags(get_abi(name), value, format, tags));
}

template <typename D> void impl_ILoggingFields<D>::AddUInt8Array(hstring_view name, array_view<const uint8_t> value) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddUInt8Array(get_abi(name), value.size(), get_abi(value)));
}

template <typename D> void impl_ILoggingFields<D>::AddUInt8Array(hstring_view name, array_view<const uint8_t> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddUInt8ArrayWithFormat(get_abi(name), value.size(), get_abi(value), format));
}

template <typename D> void impl_ILoggingFields<D>::AddUInt8Array(hstring_view name, array_view<const uint8_t> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddUInt8ArrayWithFormatAndTags(get_abi(name), value.size(), get_abi(value), format, tags));
}

template <typename D> void impl_ILoggingFields<D>::AddInt16(hstring_view name, int16_t value) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddInt16(get_abi(name), value));
}

template <typename D> void impl_ILoggingFields<D>::AddInt16(hstring_view name, int16_t value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddInt16WithFormat(get_abi(name), value, format));
}

template <typename D> void impl_ILoggingFields<D>::AddInt16(hstring_view name, int16_t value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddInt16WithFormatAndTags(get_abi(name), value, format, tags));
}

template <typename D> void impl_ILoggingFields<D>::AddInt16Array(hstring_view name, array_view<const int16_t> value) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddInt16Array(get_abi(name), value.size(), get_abi(value)));
}

template <typename D> void impl_ILoggingFields<D>::AddInt16Array(hstring_view name, array_view<const int16_t> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddInt16ArrayWithFormat(get_abi(name), value.size(), get_abi(value), format));
}

template <typename D> void impl_ILoggingFields<D>::AddInt16Array(hstring_view name, array_view<const int16_t> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddInt16ArrayWithFormatAndTags(get_abi(name), value.size(), get_abi(value), format, tags));
}

template <typename D> void impl_ILoggingFields<D>::AddUInt16(hstring_view name, uint16_t value) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddUInt16(get_abi(name), value));
}

template <typename D> void impl_ILoggingFields<D>::AddUInt16(hstring_view name, uint16_t value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddUInt16WithFormat(get_abi(name), value, format));
}

template <typename D> void impl_ILoggingFields<D>::AddUInt16(hstring_view name, uint16_t value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddUInt16WithFormatAndTags(get_abi(name), value, format, tags));
}

template <typename D> void impl_ILoggingFields<D>::AddUInt16Array(hstring_view name, array_view<const uint16_t> value) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddUInt16Array(get_abi(name), value.size(), get_abi(value)));
}

template <typename D> void impl_ILoggingFields<D>::AddUInt16Array(hstring_view name, array_view<const uint16_t> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddUInt16ArrayWithFormat(get_abi(name), value.size(), get_abi(value), format));
}

template <typename D> void impl_ILoggingFields<D>::AddUInt16Array(hstring_view name, array_view<const uint16_t> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddUInt16ArrayWithFormatAndTags(get_abi(name), value.size(), get_abi(value), format, tags));
}

template <typename D> void impl_ILoggingFields<D>::AddInt32(hstring_view name, int32_t value) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddInt32(get_abi(name), value));
}

template <typename D> void impl_ILoggingFields<D>::AddInt32(hstring_view name, int32_t value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddInt32WithFormat(get_abi(name), value, format));
}

template <typename D> void impl_ILoggingFields<D>::AddInt32(hstring_view name, int32_t value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddInt32WithFormatAndTags(get_abi(name), value, format, tags));
}

template <typename D> void impl_ILoggingFields<D>::AddInt32Array(hstring_view name, array_view<const int32_t> value) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddInt32Array(get_abi(name), value.size(), get_abi(value)));
}

template <typename D> void impl_ILoggingFields<D>::AddInt32Array(hstring_view name, array_view<const int32_t> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddInt32ArrayWithFormat(get_abi(name), value.size(), get_abi(value), format));
}

template <typename D> void impl_ILoggingFields<D>::AddInt32Array(hstring_view name, array_view<const int32_t> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddInt32ArrayWithFormatAndTags(get_abi(name), value.size(), get_abi(value), format, tags));
}

template <typename D> void impl_ILoggingFields<D>::AddUInt32(hstring_view name, uint32_t value) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddUInt32(get_abi(name), value));
}

template <typename D> void impl_ILoggingFields<D>::AddUInt32(hstring_view name, uint32_t value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddUInt32WithFormat(get_abi(name), value, format));
}

template <typename D> void impl_ILoggingFields<D>::AddUInt32(hstring_view name, uint32_t value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddUInt32WithFormatAndTags(get_abi(name), value, format, tags));
}

template <typename D> void impl_ILoggingFields<D>::AddUInt32Array(hstring_view name, array_view<const uint32_t> value) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddUInt32Array(get_abi(name), value.size(), get_abi(value)));
}

template <typename D> void impl_ILoggingFields<D>::AddUInt32Array(hstring_view name, array_view<const uint32_t> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddUInt32ArrayWithFormat(get_abi(name), value.size(), get_abi(value), format));
}

template <typename D> void impl_ILoggingFields<D>::AddUInt32Array(hstring_view name, array_view<const uint32_t> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddUInt32ArrayWithFormatAndTags(get_abi(name), value.size(), get_abi(value), format, tags));
}

template <typename D> void impl_ILoggingFields<D>::AddInt64(hstring_view name, int64_t value) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddInt64(get_abi(name), value));
}

template <typename D> void impl_ILoggingFields<D>::AddInt64(hstring_view name, int64_t value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddInt64WithFormat(get_abi(name), value, format));
}

template <typename D> void impl_ILoggingFields<D>::AddInt64(hstring_view name, int64_t value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddInt64WithFormatAndTags(get_abi(name), value, format, tags));
}

template <typename D> void impl_ILoggingFields<D>::AddInt64Array(hstring_view name, array_view<const int64_t> value) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddInt64Array(get_abi(name), value.size(), get_abi(value)));
}

template <typename D> void impl_ILoggingFields<D>::AddInt64Array(hstring_view name, array_view<const int64_t> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddInt64ArrayWithFormat(get_abi(name), value.size(), get_abi(value), format));
}

template <typename D> void impl_ILoggingFields<D>::AddInt64Array(hstring_view name, array_view<const int64_t> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddInt64ArrayWithFormatAndTags(get_abi(name), value.size(), get_abi(value), format, tags));
}

template <typename D> void impl_ILoggingFields<D>::AddUInt64(hstring_view name, uint64_t value) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddUInt64(get_abi(name), value));
}

template <typename D> void impl_ILoggingFields<D>::AddUInt64(hstring_view name, uint64_t value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddUInt64WithFormat(get_abi(name), value, format));
}

template <typename D> void impl_ILoggingFields<D>::AddUInt64(hstring_view name, uint64_t value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddUInt64WithFormatAndTags(get_abi(name), value, format, tags));
}

template <typename D> void impl_ILoggingFields<D>::AddUInt64Array(hstring_view name, array_view<const uint64_t> value) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddUInt64Array(get_abi(name), value.size(), get_abi(value)));
}

template <typename D> void impl_ILoggingFields<D>::AddUInt64Array(hstring_view name, array_view<const uint64_t> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddUInt64ArrayWithFormat(get_abi(name), value.size(), get_abi(value), format));
}

template <typename D> void impl_ILoggingFields<D>::AddUInt64Array(hstring_view name, array_view<const uint64_t> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddUInt64ArrayWithFormatAndTags(get_abi(name), value.size(), get_abi(value), format, tags));
}

template <typename D> void impl_ILoggingFields<D>::AddSingle(hstring_view name, float value) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddSingle(get_abi(name), value));
}

template <typename D> void impl_ILoggingFields<D>::AddSingle(hstring_view name, float value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddSingleWithFormat(get_abi(name), value, format));
}

template <typename D> void impl_ILoggingFields<D>::AddSingle(hstring_view name, float value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddSingleWithFormatAndTags(get_abi(name), value, format, tags));
}

template <typename D> void impl_ILoggingFields<D>::AddSingleArray(hstring_view name, array_view<const float> value) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddSingleArray(get_abi(name), value.size(), get_abi(value)));
}

template <typename D> void impl_ILoggingFields<D>::AddSingleArray(hstring_view name, array_view<const float> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddSingleArrayWithFormat(get_abi(name), value.size(), get_abi(value), format));
}

template <typename D> void impl_ILoggingFields<D>::AddSingleArray(hstring_view name, array_view<const float> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddSingleArrayWithFormatAndTags(get_abi(name), value.size(), get_abi(value), format, tags));
}

template <typename D> void impl_ILoggingFields<D>::AddDouble(hstring_view name, double value) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddDouble(get_abi(name), value));
}

template <typename D> void impl_ILoggingFields<D>::AddDouble(hstring_view name, double value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddDoubleWithFormat(get_abi(name), value, format));
}

template <typename D> void impl_ILoggingFields<D>::AddDouble(hstring_view name, double value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddDoubleWithFormatAndTags(get_abi(name), value, format, tags));
}

template <typename D> void impl_ILoggingFields<D>::AddDoubleArray(hstring_view name, array_view<const double> value) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddDoubleArray(get_abi(name), value.size(), get_abi(value)));
}

template <typename D> void impl_ILoggingFields<D>::AddDoubleArray(hstring_view name, array_view<const double> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddDoubleArrayWithFormat(get_abi(name), value.size(), get_abi(value), format));
}

template <typename D> void impl_ILoggingFields<D>::AddDoubleArray(hstring_view name, array_view<const double> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddDoubleArrayWithFormatAndTags(get_abi(name), value.size(), get_abi(value), format, tags));
}

template <typename D> void impl_ILoggingFields<D>::AddChar16(hstring_view name, wchar_t value) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddChar16(get_abi(name), value));
}

template <typename D> void impl_ILoggingFields<D>::AddChar16(hstring_view name, wchar_t value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddChar16WithFormat(get_abi(name), value, format));
}

template <typename D> void impl_ILoggingFields<D>::AddChar16(hstring_view name, wchar_t value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddChar16WithFormatAndTags(get_abi(name), value, format, tags));
}

template <typename D> void impl_ILoggingFields<D>::AddChar16Array(hstring_view name, array_view<const wchar_t> value) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddChar16Array(get_abi(name), value.size(), get_abi(value)));
}

template <typename D> void impl_ILoggingFields<D>::AddChar16Array(hstring_view name, array_view<const wchar_t> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddChar16ArrayWithFormat(get_abi(name), value.size(), get_abi(value), format));
}

template <typename D> void impl_ILoggingFields<D>::AddChar16Array(hstring_view name, array_view<const wchar_t> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddChar16ArrayWithFormatAndTags(get_abi(name), value.size(), get_abi(value), format, tags));
}

template <typename D> void impl_ILoggingFields<D>::AddBoolean(hstring_view name, bool value) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddBoolean(get_abi(name), value));
}

template <typename D> void impl_ILoggingFields<D>::AddBoolean(hstring_view name, bool value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddBooleanWithFormat(get_abi(name), value, format));
}

template <typename D> void impl_ILoggingFields<D>::AddBoolean(hstring_view name, bool value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddBooleanWithFormatAndTags(get_abi(name), value, format, tags));
}

template <typename D> void impl_ILoggingFields<D>::AddBooleanArray(hstring_view name, array_view<const bool> value) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddBooleanArray(get_abi(name), value.size(), get_abi(value)));
}

template <typename D> void impl_ILoggingFields<D>::AddBooleanArray(hstring_view name, array_view<const bool> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddBooleanArrayWithFormat(get_abi(name), value.size(), get_abi(value), format));
}

template <typename D> void impl_ILoggingFields<D>::AddBooleanArray(hstring_view name, array_view<const bool> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddBooleanArrayWithFormatAndTags(get_abi(name), value.size(), get_abi(value), format, tags));
}

template <typename D> void impl_ILoggingFields<D>::AddString(hstring_view name, hstring_view value) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddString(get_abi(name), get_abi(value)));
}

template <typename D> void impl_ILoggingFields<D>::AddString(hstring_view name, hstring_view value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddStringWithFormat(get_abi(name), get_abi(value), format));
}

template <typename D> void impl_ILoggingFields<D>::AddString(hstring_view name, hstring_view value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddStringWithFormatAndTags(get_abi(name), get_abi(value), format, tags));
}

template <typename D> void impl_ILoggingFields<D>::AddStringArray(hstring_view name, array_view<const hstring> value) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddStringArray(get_abi(name), value.size(), get_abi(value)));
}

template <typename D> void impl_ILoggingFields<D>::AddStringArray(hstring_view name, array_view<const hstring> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddStringArrayWithFormat(get_abi(name), value.size(), get_abi(value), format));
}

template <typename D> void impl_ILoggingFields<D>::AddStringArray(hstring_view name, array_view<const hstring> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddStringArrayWithFormatAndTags(get_abi(name), value.size(), get_abi(value), format, tags));
}

template <typename D> void impl_ILoggingFields<D>::AddGuid(hstring_view name, GUID value) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddGuid(get_abi(name), value));
}

template <typename D> void impl_ILoggingFields<D>::AddGuid(hstring_view name, GUID value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddGuidWithFormat(get_abi(name), value, format));
}

template <typename D> void impl_ILoggingFields<D>::AddGuid(hstring_view name, GUID value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddGuidWithFormatAndTags(get_abi(name), value, format, tags));
}

template <typename D> void impl_ILoggingFields<D>::AddGuidArray(hstring_view name, array_view<const GUID> value) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddGuidArray(get_abi(name), value.size(), get_abi(value)));
}

template <typename D> void impl_ILoggingFields<D>::AddGuidArray(hstring_view name, array_view<const GUID> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddGuidArrayWithFormat(get_abi(name), value.size(), get_abi(value), format));
}

template <typename D> void impl_ILoggingFields<D>::AddGuidArray(hstring_view name, array_view<const GUID> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddGuidArrayWithFormatAndTags(get_abi(name), value.size(), get_abi(value), format, tags));
}

template <typename D> void impl_ILoggingFields<D>::AddDateTime(hstring_view name, const Windows::Foundation::DateTime & value) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddDateTime(get_abi(name), get_abi(value)));
}

template <typename D> void impl_ILoggingFields<D>::AddDateTime(hstring_view name, const Windows::Foundation::DateTime & value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddDateTimeWithFormat(get_abi(name), get_abi(value), format));
}

template <typename D> void impl_ILoggingFields<D>::AddDateTime(hstring_view name, const Windows::Foundation::DateTime & value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddDateTimeWithFormatAndTags(get_abi(name), get_abi(value), format, tags));
}

template <typename D> void impl_ILoggingFields<D>::AddDateTimeArray(hstring_view name, array_view<const Windows::Foundation::DateTime> value) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddDateTimeArray(get_abi(name), value.size(), get_abi(value)));
}

template <typename D> void impl_ILoggingFields<D>::AddDateTimeArray(hstring_view name, array_view<const Windows::Foundation::DateTime> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddDateTimeArrayWithFormat(get_abi(name), value.size(), get_abi(value), format));
}

template <typename D> void impl_ILoggingFields<D>::AddDateTimeArray(hstring_view name, array_view<const Windows::Foundation::DateTime> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddDateTimeArrayWithFormatAndTags(get_abi(name), value.size(), get_abi(value), format, tags));
}

template <typename D> void impl_ILoggingFields<D>::AddTimeSpan(hstring_view name, const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddTimeSpan(get_abi(name), get_abi(value)));
}

template <typename D> void impl_ILoggingFields<D>::AddTimeSpan(hstring_view name, const Windows::Foundation::TimeSpan & value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddTimeSpanWithFormat(get_abi(name), get_abi(value), format));
}

template <typename D> void impl_ILoggingFields<D>::AddTimeSpan(hstring_view name, const Windows::Foundation::TimeSpan & value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddTimeSpanWithFormatAndTags(get_abi(name), get_abi(value), format, tags));
}

template <typename D> void impl_ILoggingFields<D>::AddTimeSpanArray(hstring_view name, array_view<const Windows::Foundation::TimeSpan> value) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddTimeSpanArray(get_abi(name), value.size(), get_abi(value)));
}

template <typename D> void impl_ILoggingFields<D>::AddTimeSpanArray(hstring_view name, array_view<const Windows::Foundation::TimeSpan> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddTimeSpanArrayWithFormat(get_abi(name), value.size(), get_abi(value), format));
}

template <typename D> void impl_ILoggingFields<D>::AddTimeSpanArray(hstring_view name, array_view<const Windows::Foundation::TimeSpan> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddTimeSpanArrayWithFormatAndTags(get_abi(name), value.size(), get_abi(value), format, tags));
}

template <typename D> void impl_ILoggingFields<D>::AddPoint(hstring_view name, const Windows::Foundation::Point & value) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddPoint(get_abi(name), get_abi(value)));
}

template <typename D> void impl_ILoggingFields<D>::AddPoint(hstring_view name, const Windows::Foundation::Point & value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddPointWithFormat(get_abi(name), get_abi(value), format));
}

template <typename D> void impl_ILoggingFields<D>::AddPoint(hstring_view name, const Windows::Foundation::Point & value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddPointWithFormatAndTags(get_abi(name), get_abi(value), format, tags));
}

template <typename D> void impl_ILoggingFields<D>::AddPointArray(hstring_view name, array_view<const Windows::Foundation::Point> value) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddPointArray(get_abi(name), value.size(), get_abi(value)));
}

template <typename D> void impl_ILoggingFields<D>::AddPointArray(hstring_view name, array_view<const Windows::Foundation::Point> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddPointArrayWithFormat(get_abi(name), value.size(), get_abi(value), format));
}

template <typename D> void impl_ILoggingFields<D>::AddPointArray(hstring_view name, array_view<const Windows::Foundation::Point> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddPointArrayWithFormatAndTags(get_abi(name), value.size(), get_abi(value), format, tags));
}

template <typename D> void impl_ILoggingFields<D>::AddSize(hstring_view name, const Windows::Foundation::Size & value) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddSize(get_abi(name), get_abi(value)));
}

template <typename D> void impl_ILoggingFields<D>::AddSize(hstring_view name, const Windows::Foundation::Size & value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddSizeWithFormat(get_abi(name), get_abi(value), format));
}

template <typename D> void impl_ILoggingFields<D>::AddSize(hstring_view name, const Windows::Foundation::Size & value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddSizeWithFormatAndTags(get_abi(name), get_abi(value), format, tags));
}

template <typename D> void impl_ILoggingFields<D>::AddSizeArray(hstring_view name, array_view<const Windows::Foundation::Size> value) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddSizeArray(get_abi(name), value.size(), get_abi(value)));
}

template <typename D> void impl_ILoggingFields<D>::AddSizeArray(hstring_view name, array_view<const Windows::Foundation::Size> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddSizeArrayWithFormat(get_abi(name), value.size(), get_abi(value), format));
}

template <typename D> void impl_ILoggingFields<D>::AddSizeArray(hstring_view name, array_view<const Windows::Foundation::Size> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddSizeArrayWithFormatAndTags(get_abi(name), value.size(), get_abi(value), format, tags));
}

template <typename D> void impl_ILoggingFields<D>::AddRect(hstring_view name, const Windows::Foundation::Rect & value) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddRect(get_abi(name), get_abi(value)));
}

template <typename D> void impl_ILoggingFields<D>::AddRect(hstring_view name, const Windows::Foundation::Rect & value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddRectWithFormat(get_abi(name), get_abi(value), format));
}

template <typename D> void impl_ILoggingFields<D>::AddRect(hstring_view name, const Windows::Foundation::Rect & value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddRectWithFormatAndTags(get_abi(name), get_abi(value), format, tags));
}

template <typename D> void impl_ILoggingFields<D>::AddRectArray(hstring_view name, array_view<const Windows::Foundation::Rect> value) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddRectArray(get_abi(name), value.size(), get_abi(value)));
}

template <typename D> void impl_ILoggingFields<D>::AddRectArray(hstring_view name, array_view<const Windows::Foundation::Rect> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddRectArrayWithFormat(get_abi(name), value.size(), get_abi(value), format));
}

template <typename D> void impl_ILoggingFields<D>::AddRectArray(hstring_view name, array_view<const Windows::Foundation::Rect> value, Windows::Foundation::Diagnostics::LoggingFieldFormat format, int32_t tags) const
{
    check_hresult(WINRT_SHIM(ILoggingFields)->abi_AddRectArrayWithFormatAndTags(get_abi(name), value.size(), get_abi(value), format, tags));
}

template <typename D> bool impl_ILoggingTarget<D>::IsEnabled() const
{
    bool result {};
    check_hresult(WINRT_SHIM(ILoggingTarget)->abi_IsEnabled(&result));
    return result;
}

template <typename D> bool impl_ILoggingTarget<D>::IsEnabled(Windows::Foundation::Diagnostics::LoggingLevel level) const
{
    bool result {};
    check_hresult(WINRT_SHIM(ILoggingTarget)->abi_IsEnabledWithLevel(level, &result));
    return result;
}

template <typename D> bool impl_ILoggingTarget<D>::IsEnabled(Windows::Foundation::Diagnostics::LoggingLevel level, int64_t keywords) const
{
    bool result {};
    check_hresult(WINRT_SHIM(ILoggingTarget)->abi_IsEnabledWithLevelAndKeywords(level, keywords, &result));
    return result;
}

template <typename D> void impl_ILoggingTarget<D>::LogEvent(hstring_view eventName) const
{
    check_hresult(WINRT_SHIM(ILoggingTarget)->abi_LogEvent(get_abi(eventName)));
}

template <typename D> void impl_ILoggingTarget<D>::LogEvent(hstring_view eventName, const Windows::Foundation::Diagnostics::LoggingFields & fields) const
{
    check_hresult(WINRT_SHIM(ILoggingTarget)->abi_LogEventWithFields(get_abi(eventName), get_abi(fields)));
}

template <typename D> void impl_ILoggingTarget<D>::LogEvent(hstring_view eventName, const Windows::Foundation::Diagnostics::LoggingFields & fields, Windows::Foundation::Diagnostics::LoggingLevel level) const
{
    check_hresult(WINRT_SHIM(ILoggingTarget)->abi_LogEventWithFieldsAndLevel(get_abi(eventName), get_abi(fields), level));
}

template <typename D> void impl_ILoggingTarget<D>::LogEvent(hstring_view eventName, const Windows::Foundation::Diagnostics::LoggingFields & fields, Windows::Foundation::Diagnostics::LoggingLevel level, const Windows::Foundation::Diagnostics::LoggingOptions & options) const
{
    check_hresult(WINRT_SHIM(ILoggingTarget)->abi_LogEventWithFieldsAndOptions(get_abi(eventName), get_abi(fields), level, get_abi(options)));
}

template <typename D> Windows::Foundation::Diagnostics::LoggingActivity impl_ILoggingTarget<D>::StartActivity(hstring_view startEventName) const
{
    Windows::Foundation::Diagnostics::LoggingActivity result { nullptr };
    check_hresult(WINRT_SHIM(ILoggingTarget)->abi_StartActivity(get_abi(startEventName), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Diagnostics::LoggingActivity impl_ILoggingTarget<D>::StartActivity(hstring_view startEventName, const Windows::Foundation::Diagnostics::LoggingFields & fields) const
{
    Windows::Foundation::Diagnostics::LoggingActivity result { nullptr };
    check_hresult(WINRT_SHIM(ILoggingTarget)->abi_StartActivityWithFields(get_abi(startEventName), get_abi(fields), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Diagnostics::LoggingActivity impl_ILoggingTarget<D>::StartActivity(hstring_view startEventName, const Windows::Foundation::Diagnostics::LoggingFields & fields, Windows::Foundation::Diagnostics::LoggingLevel level) const
{
    Windows::Foundation::Diagnostics::LoggingActivity result { nullptr };
    check_hresult(WINRT_SHIM(ILoggingTarget)->abi_StartActivityWithFieldsAndLevel(get_abi(startEventName), get_abi(fields), level, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Diagnostics::LoggingActivity impl_ILoggingTarget<D>::StartActivity(hstring_view startEventName, const Windows::Foundation::Diagnostics::LoggingFields & fields, Windows::Foundation::Diagnostics::LoggingLevel level, const Windows::Foundation::Diagnostics::LoggingOptions & options) const
{
    Windows::Foundation::Diagnostics::LoggingActivity result { nullptr };
    check_hresult(WINRT_SHIM(ILoggingTarget)->abi_StartActivityWithFieldsAndOptions(get_abi(startEventName), get_abi(fields), level, get_abi(options), put_abi(result)));
    return result;
}

template <typename D> hstring impl_ILoggingChannel<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ILoggingChannel)->get_Name(put_abi(value)));
    return value;
}

template <typename D> bool impl_ILoggingChannel<D>::Enabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ILoggingChannel)->get_Enabled(&value));
    return value;
}

template <typename D> Windows::Foundation::Diagnostics::LoggingLevel impl_ILoggingChannel<D>::Level() const
{
    Windows::Foundation::Diagnostics::LoggingLevel value {};
    check_hresult(WINRT_SHIM(ILoggingChannel)->get_Level(&value));
    return value;
}

template <typename D> void impl_ILoggingChannel<D>::LogMessage(hstring_view eventString) const
{
    check_hresult(WINRT_SHIM(ILoggingChannel)->abi_LogMessage(get_abi(eventString)));
}

template <typename D> void impl_ILoggingChannel<D>::LogMessage(hstring_view eventString, Windows::Foundation::Diagnostics::LoggingLevel level) const
{
    check_hresult(WINRT_SHIM(ILoggingChannel)->abi_LogMessageWithLevel(get_abi(eventString), level));
}

template <typename D> void impl_ILoggingChannel<D>::LogValuePair(hstring_view value1, int32_t value2) const
{
    check_hresult(WINRT_SHIM(ILoggingChannel)->abi_LogValuePair(get_abi(value1), value2));
}

template <typename D> void impl_ILoggingChannel<D>::LogValuePair(hstring_view value1, int32_t value2, Windows::Foundation::Diagnostics::LoggingLevel level) const
{
    check_hresult(WINRT_SHIM(ILoggingChannel)->abi_LogValuePairWithLevel(get_abi(value1), value2, level));
}

template <typename D> event_token impl_ILoggingChannel<D>::LoggingEnabled(const Windows::Foundation::TypedEventHandler<Windows::Foundation::Diagnostics::ILoggingChannel, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ILoggingChannel)->add_LoggingEnabled(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ILoggingChannel> impl_ILoggingChannel<D>::LoggingEnabled(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Foundation::Diagnostics::ILoggingChannel, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, ILoggingChannel>(this, &ABI::Windows::Foundation::Diagnostics::ILoggingChannel::remove_LoggingEnabled, LoggingEnabled(handler));
}

template <typename D> void impl_ILoggingChannel<D>::LoggingEnabled(event_token token) const
{
    check_hresult(WINRT_SHIM(ILoggingChannel)->remove_LoggingEnabled(token));
}

template <typename D> GUID impl_ILoggingChannel2<D>::Id() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(ILoggingChannel2)->get_Id(&value));
    return value;
}

template <typename D> Windows::Foundation::Diagnostics::LoggingChannel impl_ILoggingChannelFactory<D>::Create(hstring_view name) const
{
    Windows::Foundation::Diagnostics::LoggingChannel result { nullptr };
    check_hresult(WINRT_SHIM(ILoggingChannelFactory)->abi_Create(get_abi(name), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Diagnostics::LoggingChannel impl_ILoggingChannelFactory2<D>::CreateWithOptions(hstring_view name, const Windows::Foundation::Diagnostics::LoggingChannelOptions & options) const
{
    Windows::Foundation::Diagnostics::LoggingChannel result { nullptr };
    check_hresult(WINRT_SHIM(ILoggingChannelFactory2)->abi_CreateWithOptions(get_abi(name), get_abi(options), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Diagnostics::LoggingChannel impl_ILoggingChannelFactory2<D>::CreateWithOptionsAndId(hstring_view name, const Windows::Foundation::Diagnostics::LoggingChannelOptions & options, GUID id) const
{
    Windows::Foundation::Diagnostics::LoggingChannel result { nullptr };
    check_hresult(WINRT_SHIM(ILoggingChannelFactory2)->abi_CreateWithOptionsAndId(get_abi(name), get_abi(options), id, put_abi(result)));
    return result;
}

template <typename D> hstring impl_ILoggingActivity<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ILoggingActivity)->get_Name(put_abi(value)));
    return value;
}

template <typename D> GUID impl_ILoggingActivity<D>::Id() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(ILoggingActivity)->get_Id(&value));
    return value;
}

template <typename D> Windows::Foundation::Diagnostics::LoggingChannel impl_ILoggingActivity2<D>::Channel() const
{
    Windows::Foundation::Diagnostics::LoggingChannel value { nullptr };
    check_hresult(WINRT_SHIM(ILoggingActivity2)->get_Channel(put_abi(value)));
    return value;
}

template <typename D> void impl_ILoggingActivity2<D>::StopActivity(hstring_view stopEventName) const
{
    check_hresult(WINRT_SHIM(ILoggingActivity2)->abi_StopActivity(get_abi(stopEventName)));
}

template <typename D> void impl_ILoggingActivity2<D>::StopActivity(hstring_view stopEventName, const Windows::Foundation::Diagnostics::LoggingFields & fields) const
{
    check_hresult(WINRT_SHIM(ILoggingActivity2)->abi_StopActivityWithFields(get_abi(stopEventName), get_abi(fields)));
}

template <typename D> void impl_ILoggingActivity2<D>::StopActivity(hstring_view stopEventName, const Windows::Foundation::Diagnostics::LoggingFields & fields, const Windows::Foundation::Diagnostics::LoggingOptions & options) const
{
    check_hresult(WINRT_SHIM(ILoggingActivity2)->abi_StopActivityWithFieldsAndOptions(get_abi(stopEventName), get_abi(fields), get_abi(options)));
}

template <typename D> Windows::Foundation::Diagnostics::LoggingActivity impl_ILoggingActivityFactory<D>::CreateLoggingActivity(hstring_view activityName, const Windows::Foundation::Diagnostics::ILoggingChannel & loggingChannel) const
{
    Windows::Foundation::Diagnostics::LoggingActivity loggingActivity { nullptr };
    check_hresult(WINRT_SHIM(ILoggingActivityFactory)->abi_CreateLoggingActivity(get_abi(activityName), get_abi(loggingChannel), put_abi(loggingActivity)));
    return loggingActivity;
}

template <typename D> Windows::Foundation::Diagnostics::LoggingActivity impl_ILoggingActivityFactory<D>::CreateLoggingActivityWithLevel(hstring_view activityName, const Windows::Foundation::Diagnostics::ILoggingChannel & loggingChannel, Windows::Foundation::Diagnostics::LoggingLevel level) const
{
    Windows::Foundation::Diagnostics::LoggingActivity loggingActivity { nullptr };
    check_hresult(WINRT_SHIM(ILoggingActivityFactory)->abi_CreateLoggingActivityWithLevel(get_abi(activityName), get_abi(loggingChannel), level, put_abi(loggingActivity)));
    return loggingActivity;
}

template <typename D> hstring impl_ILoggingSession<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ILoggingSession)->get_Name(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> impl_ILoggingSession<D>::SaveToFileAsync(const Windows::Storage::IStorageFolder & folder, hstring_view fileName) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> operation;
    check_hresult(WINRT_SHIM(ILoggingSession)->abi_SaveToFileAsync(get_abi(folder), get_abi(fileName), put_abi(operation)));
    return operation;
}

template <typename D> void impl_ILoggingSession<D>::AddLoggingChannel(const Windows::Foundation::Diagnostics::ILoggingChannel & loggingChannel) const
{
    check_hresult(WINRT_SHIM(ILoggingSession)->abi_AddLoggingChannel(get_abi(loggingChannel)));
}

template <typename D> void impl_ILoggingSession<D>::AddLoggingChannel(const Windows::Foundation::Diagnostics::ILoggingChannel & loggingChannel, Windows::Foundation::Diagnostics::LoggingLevel maxLevel) const
{
    check_hresult(WINRT_SHIM(ILoggingSession)->abi_AddLoggingChannelWithLevel(get_abi(loggingChannel), maxLevel));
}

template <typename D> void impl_ILoggingSession<D>::RemoveLoggingChannel(const Windows::Foundation::Diagnostics::ILoggingChannel & loggingChannel) const
{
    check_hresult(WINRT_SHIM(ILoggingSession)->abi_RemoveLoggingChannel(get_abi(loggingChannel)));
}

template <typename D> Windows::Foundation::Diagnostics::LoggingSession impl_ILoggingSessionFactory<D>::Create(hstring_view name) const
{
    Windows::Foundation::Diagnostics::LoggingSession result { nullptr };
    check_hresult(WINRT_SHIM(ILoggingSessionFactory)->abi_Create(get_abi(name), put_abi(result)));
    return result;
}

template <typename D> Windows::Storage::StorageFile impl_ILogFileGeneratedEventArgs<D>::File() const
{
    Windows::Storage::StorageFile value { nullptr };
    check_hresult(WINRT_SHIM(ILogFileGeneratedEventArgs)->get_File(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IFileLoggingSession<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IFileLoggingSession)->get_Name(put_abi(value)));
    return value;
}

template <typename D> void impl_IFileLoggingSession<D>::AddLoggingChannel(const Windows::Foundation::Diagnostics::ILoggingChannel & loggingChannel) const
{
    check_hresult(WINRT_SHIM(IFileLoggingSession)->abi_AddLoggingChannel(get_abi(loggingChannel)));
}

template <typename D> void impl_IFileLoggingSession<D>::AddLoggingChannel(const Windows::Foundation::Diagnostics::ILoggingChannel & loggingChannel, Windows::Foundation::Diagnostics::LoggingLevel maxLevel) const
{
    check_hresult(WINRT_SHIM(IFileLoggingSession)->abi_AddLoggingChannelWithLevel(get_abi(loggingChannel), maxLevel));
}

template <typename D> void impl_IFileLoggingSession<D>::RemoveLoggingChannel(const Windows::Foundation::Diagnostics::ILoggingChannel & loggingChannel) const
{
    check_hresult(WINRT_SHIM(IFileLoggingSession)->abi_RemoveLoggingChannel(get_abi(loggingChannel)));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> impl_IFileLoggingSession<D>::CloseAndSaveToFileAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> operation;
    check_hresult(WINRT_SHIM(IFileLoggingSession)->abi_CloseAndSaveToFileAsync(put_abi(operation)));
    return operation;
}

template <typename D> event_token impl_IFileLoggingSession<D>::LogFileGenerated(const Windows::Foundation::TypedEventHandler<Windows::Foundation::Diagnostics::IFileLoggingSession, Windows::Foundation::Diagnostics::LogFileGeneratedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IFileLoggingSession)->add_LogFileGenerated(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IFileLoggingSession> impl_IFileLoggingSession<D>::LogFileGenerated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Foundation::Diagnostics::IFileLoggingSession, Windows::Foundation::Diagnostics::LogFileGeneratedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IFileLoggingSession>(this, &ABI::Windows::Foundation::Diagnostics::IFileLoggingSession::remove_LogFileGenerated, LogFileGenerated(handler));
}

template <typename D> void impl_IFileLoggingSession<D>::LogFileGenerated(event_token token) const
{
    check_hresult(WINRT_SHIM(IFileLoggingSession)->remove_LogFileGenerated(token));
}

template <typename D> Windows::Foundation::Diagnostics::FileLoggingSession impl_IFileLoggingSessionFactory<D>::Create(hstring_view name) const
{
    Windows::Foundation::Diagnostics::FileLoggingSession result { nullptr };
    check_hresult(WINRT_SHIM(IFileLoggingSessionFactory)->abi_Create(get_abi(name), put_abi(result)));
    return result;
}

inline void AsyncCausalityTracer::TraceOperationCreation(Windows::Foundation::Diagnostics::CausalityTraceLevel traceLevel, Windows::Foundation::Diagnostics::CausalitySource source, GUID platformId, uint64_t operationId, hstring_view operationName, uint64_t relatedContext)
{
    get_activation_factory<AsyncCausalityTracer, IAsyncCausalityTracerStatics>().TraceOperationCreation(traceLevel, source, platformId, operationId, operationName, relatedContext);
}

inline void AsyncCausalityTracer::TraceOperationCompletion(Windows::Foundation::Diagnostics::CausalityTraceLevel traceLevel, Windows::Foundation::Diagnostics::CausalitySource source, GUID platformId, uint64_t operationId, Windows::Foundation::AsyncStatus status)
{
    get_activation_factory<AsyncCausalityTracer, IAsyncCausalityTracerStatics>().TraceOperationCompletion(traceLevel, source, platformId, operationId, status);
}

inline void AsyncCausalityTracer::TraceOperationRelation(Windows::Foundation::Diagnostics::CausalityTraceLevel traceLevel, Windows::Foundation::Diagnostics::CausalitySource source, GUID platformId, uint64_t operationId, Windows::Foundation::Diagnostics::CausalityRelation relation)
{
    get_activation_factory<AsyncCausalityTracer, IAsyncCausalityTracerStatics>().TraceOperationRelation(traceLevel, source, platformId, operationId, relation);
}

inline void AsyncCausalityTracer::TraceSynchronousWorkStart(Windows::Foundation::Diagnostics::CausalityTraceLevel traceLevel, Windows::Foundation::Diagnostics::CausalitySource source, GUID platformId, uint64_t operationId, Windows::Foundation::Diagnostics::CausalitySynchronousWork work)
{
    get_activation_factory<AsyncCausalityTracer, IAsyncCausalityTracerStatics>().TraceSynchronousWorkStart(traceLevel, source, platformId, operationId, work);
}

inline void AsyncCausalityTracer::TraceSynchronousWorkCompletion(Windows::Foundation::Diagnostics::CausalityTraceLevel traceLevel, Windows::Foundation::Diagnostics::CausalitySource source, Windows::Foundation::Diagnostics::CausalitySynchronousWork work)
{
    get_activation_factory<AsyncCausalityTracer, IAsyncCausalityTracerStatics>().TraceSynchronousWorkCompletion(traceLevel, source, work);
}

inline event_token AsyncCausalityTracer::TracingStatusChanged(const Windows::Foundation::EventHandler<Windows::Foundation::Diagnostics::TracingStatusChangedEventArgs> & handler)
{
    return get_activation_factory<AsyncCausalityTracer, IAsyncCausalityTracerStatics>().TracingStatusChanged(handler);
}

inline factory_event_revoker<IAsyncCausalityTracerStatics> AsyncCausalityTracer::TracingStatusChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::Diagnostics::TracingStatusChangedEventArgs> & handler)
{
    auto factory = get_activation_factory<AsyncCausalityTracer, IAsyncCausalityTracerStatics>();
    return { factory, &ABI::Windows::Foundation::Diagnostics::IAsyncCausalityTracerStatics::remove_TracingStatusChanged, factory.TracingStatusChanged(handler) };
}

inline void AsyncCausalityTracer::TracingStatusChanged(event_token cookie)
{
    get_activation_factory<AsyncCausalityTracer, IAsyncCausalityTracerStatics>().TracingStatusChanged(cookie);
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Diagnostics::ErrorDetails> ErrorDetails::CreateFromHResultAsync(int32_t errorCode)
{
    return get_activation_factory<ErrorDetails, IErrorDetailsStatics>().CreateFromHResultAsync(errorCode);
}

inline FileLoggingSession::FileLoggingSession(hstring_view name) :
    FileLoggingSession(get_activation_factory<FileLoggingSession, IFileLoggingSessionFactory>().Create(name))
{}

inline LoggingActivity::LoggingActivity(hstring_view activityName, const Windows::Foundation::Diagnostics::ILoggingChannel & loggingChannel) :
    LoggingActivity(get_activation_factory<LoggingActivity, ILoggingActivityFactory>().CreateLoggingActivity(activityName, loggingChannel))
{}

inline LoggingActivity::LoggingActivity(hstring_view activityName, const Windows::Foundation::Diagnostics::ILoggingChannel & loggingChannel, Windows::Foundation::Diagnostics::LoggingLevel level) :
    LoggingActivity(get_activation_factory<LoggingActivity, ILoggingActivityFactory>().CreateLoggingActivityWithLevel(activityName, loggingChannel, level))
{}

inline LoggingChannel::LoggingChannel(hstring_view name, const Windows::Foundation::Diagnostics::LoggingChannelOptions & options) :
    LoggingChannel(get_activation_factory<LoggingChannel, ILoggingChannelFactory2>().CreateWithOptions(name, options))
{}

inline LoggingChannel::LoggingChannel(hstring_view name, const Windows::Foundation::Diagnostics::LoggingChannelOptions & options, GUID id) :
    LoggingChannel(get_activation_factory<LoggingChannel, ILoggingChannelFactory2>().CreateWithOptionsAndId(name, options, id))
{}

inline LoggingChannel::LoggingChannel(hstring_view name) :
    LoggingChannel(get_activation_factory<LoggingChannel, ILoggingChannelFactory>().Create(name))
{}

inline LoggingChannelOptions::LoggingChannelOptions() :
    LoggingChannelOptions(activate_instance<LoggingChannelOptions>())
{}

inline LoggingChannelOptions::LoggingChannelOptions(GUID group) :
    LoggingChannelOptions(get_activation_factory<LoggingChannelOptions, ILoggingChannelOptionsFactory>().Create(group))
{}

inline LoggingFields::LoggingFields() :
    LoggingFields(activate_instance<LoggingFields>())
{}

inline LoggingOptions::LoggingOptions() :
    LoggingOptions(activate_instance<LoggingOptions>())
{}

inline LoggingOptions::LoggingOptions(int64_t keywords) :
    LoggingOptions(get_activation_factory<LoggingOptions, ILoggingOptionsFactory>().CreateWithKeywords(keywords))
{}

inline LoggingSession::LoggingSession(hstring_view name) :
    LoggingSession(get_activation_factory<LoggingSession, ILoggingSessionFactory>().Create(name))
{}

inline RuntimeBrokerErrorSettings::RuntimeBrokerErrorSettings() :
    RuntimeBrokerErrorSettings(activate_instance<RuntimeBrokerErrorSettings>())
{}

}

}
#pragma warning(pop)
