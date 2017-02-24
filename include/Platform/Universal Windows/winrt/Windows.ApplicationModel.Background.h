// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.System.3.h"
#include "internal/Windows.Devices.Sms.3.h"
#include "internal/Windows.Storage.3.h"
#include "internal/Windows.Storage.Provider.3.h"
#include "internal/Windows.Devices.Bluetooth.Background.3.h"
#include "internal/Windows.Networking.Sockets.3.h"
#include "internal/Windows.Networking.3.h"
#include "internal/Windows.Devices.Bluetooth.GenericAttributeProfile.3.h"
#include "internal/Windows.Devices.Bluetooth.3.h"
#include "internal/Windows.Devices.Bluetooth.Advertisement.3.h"
#include "internal/Windows.Devices.Sensors.3.h"
#include "internal/Windows.UI.Notifications.3.h"
#include "internal/Windows.ApplicationModel.Calls.Background.3.h"
#include "internal/Windows.Devices.SmartCards.3.h"
#include "internal/Windows.ApplicationModel.Background.3.h"
#include "Windows.ApplicationModel.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::Background {

template <typename L> BackgroundTaskCanceledEventHandler::BackgroundTaskCanceledEventHandler(L lambda) :
    BackgroundTaskCanceledEventHandler(impl::make_delegate<impl_BackgroundTaskCanceledEventHandler<L>, BackgroundTaskCanceledEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> BackgroundTaskCanceledEventHandler::BackgroundTaskCanceledEventHandler(F * function) :
    BackgroundTaskCanceledEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> BackgroundTaskCanceledEventHandler::BackgroundTaskCanceledEventHandler(O * object, M method) :
    BackgroundTaskCanceledEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void BackgroundTaskCanceledEventHandler::operator()(const Windows::ApplicationModel::Background::IBackgroundTaskInstance & sender, Windows::ApplicationModel::Background::BackgroundTaskCancellationReason reason) const
{
    check_hresult((*(abi<BackgroundTaskCanceledEventHandler> **)this)->abi_Invoke(get_abi(sender), reason));
}

template <typename L> BackgroundTaskCompletedEventHandler::BackgroundTaskCompletedEventHandler(L lambda) :
    BackgroundTaskCompletedEventHandler(impl::make_delegate<impl_BackgroundTaskCompletedEventHandler<L>, BackgroundTaskCompletedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> BackgroundTaskCompletedEventHandler::BackgroundTaskCompletedEventHandler(F * function) :
    BackgroundTaskCompletedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> BackgroundTaskCompletedEventHandler::BackgroundTaskCompletedEventHandler(O * object, M method) :
    BackgroundTaskCompletedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void BackgroundTaskCompletedEventHandler::operator()(const Windows::ApplicationModel::Background::BackgroundTaskRegistration & sender, const Windows::ApplicationModel::Background::BackgroundTaskCompletedEventArgs & args) const
{
    check_hresult((*(abi<BackgroundTaskCompletedEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(args)));
}

template <typename L> BackgroundTaskProgressEventHandler::BackgroundTaskProgressEventHandler(L lambda) :
    BackgroundTaskProgressEventHandler(impl::make_delegate<impl_BackgroundTaskProgressEventHandler<L>, BackgroundTaskProgressEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> BackgroundTaskProgressEventHandler::BackgroundTaskProgressEventHandler(F * function) :
    BackgroundTaskProgressEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> BackgroundTaskProgressEventHandler::BackgroundTaskProgressEventHandler(O * object, M method) :
    BackgroundTaskProgressEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void BackgroundTaskProgressEventHandler::operator()(const Windows::ApplicationModel::Background::BackgroundTaskRegistration & sender, const Windows::ApplicationModel::Background::BackgroundTaskProgressEventArgs & args) const
{
    check_hresult((*(abi<BackgroundTaskProgressEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(args)));
}

}

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IActivitySensorTrigger> : produce_base<D, Windows::ApplicationModel::Background::IActivitySensorTrigger>
{
    HRESULT __stdcall get_SubscribedActivities(impl::abi_arg_out<Windows::Foundation::Collections::IVector<winrt::Windows::Devices::Sensors::ActivityType>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SubscribedActivities());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ReportInterval(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReportInterval());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedActivities(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::Sensors::ActivityType>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportedActivities());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinimumReportInterval(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinimumReportInterval());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IActivitySensorTriggerFactory> : produce_base<D, Windows::ApplicationModel::Background::IActivitySensorTriggerFactory>
{
    HRESULT __stdcall abi_Create(uint32_t reportIntervalInMilliseconds, impl::abi_arg_out<Windows::ApplicationModel::Background::IActivitySensorTrigger> activityTrigger) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *activityTrigger = detach_abi(this->shim().Create(reportIntervalInMilliseconds));
            return S_OK;
        }
        catch (...)
        {
            *activityTrigger = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IAlarmApplicationManagerStatics> : produce_base<D, Windows::ApplicationModel::Background::IAlarmApplicationManagerStatics>
{
    HRESULT __stdcall abi_RequestAccessAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::AlarmAccessStatus>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RequestAccessAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAccessStatus(Windows::ApplicationModel::Background::AlarmAccessStatus * status) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *status = detach_abi(this->shim().GetAccessStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IApplicationTrigger> : produce_base<D, Windows::ApplicationModel::Background::IApplicationTrigger>
{
    HRESULT __stdcall abi_RequestAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::ApplicationTriggerResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestAsyncWithArguments(impl::abi_arg_in<Windows::Foundation::Collections::IPropertySet> arguments, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::ApplicationTriggerResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestAsync(*reinterpret_cast<const Windows::Foundation::Collections::ValueSet *>(&arguments)));
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
struct produce<D, Windows::ApplicationModel::Background::IApplicationTriggerDetails> : produce_base<D, Windows::ApplicationModel::Background::IApplicationTriggerDetails>
{
    HRESULT __stdcall get_Arguments(impl::abi_arg_out<Windows::Foundation::Collections::IPropertySet> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Arguments());
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
struct produce<D, Windows::ApplicationModel::Background::IAppointmentStoreNotificationTrigger> : produce_base<D, Windows::ApplicationModel::Background::IAppointmentStoreNotificationTrigger>
{};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IBackgroundCondition> : produce_base<D, Windows::ApplicationModel::Background::IBackgroundCondition>
{};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IBackgroundExecutionManagerStatics> : produce_base<D, Windows::ApplicationModel::Background::IBackgroundExecutionManagerStatics>
{
    HRESULT __stdcall abi_RequestAccessAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::BackgroundAccessStatus>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RequestAccessAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestAccessForApplicationAsync(impl::abi_arg_in<hstring> applicationId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::BackgroundAccessStatus>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RequestAccessAsync(*reinterpret_cast<const hstring *>(&applicationId)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveAccess() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveAccess();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveAccessForApplication(impl::abi_arg_in<hstring> applicationId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveAccess(*reinterpret_cast<const hstring *>(&applicationId));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAccessStatus(Windows::ApplicationModel::Background::BackgroundAccessStatus * status) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *status = detach_abi(this->shim().GetAccessStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAccessStatusForApplication(impl::abi_arg_in<hstring> applicationId, Windows::ApplicationModel::Background::BackgroundAccessStatus * status) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *status = detach_abi(this->shim().GetAccessStatus(*reinterpret_cast<const hstring *>(&applicationId)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IBackgroundTask> : produce_base<D, Windows::ApplicationModel::Background::IBackgroundTask>
{
    HRESULT __stdcall abi_Run(impl::abi_arg_in<Windows::ApplicationModel::Background::IBackgroundTaskInstance> taskInstance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Run(*reinterpret_cast<const Windows::ApplicationModel::Background::IBackgroundTaskInstance *>(&taskInstance));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IBackgroundTaskBuilder> : produce_base<D, Windows::ApplicationModel::Background::IBackgroundTaskBuilder>
{
    HRESULT __stdcall put_TaskEntryPoint(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TaskEntryPoint(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TaskEntryPoint(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TaskEntryPoint());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetTrigger(impl::abi_arg_in<Windows::ApplicationModel::Background::IBackgroundTrigger> trigger) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetTrigger(*reinterpret_cast<const Windows::ApplicationModel::Background::IBackgroundTrigger *>(&trigger));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddCondition(impl::abi_arg_in<Windows::ApplicationModel::Background::IBackgroundCondition> condition) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddCondition(*reinterpret_cast<const Windows::ApplicationModel::Background::IBackgroundCondition *>(&condition));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Name(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Name(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall abi_Register(impl::abi_arg_out<Windows::ApplicationModel::Background::IBackgroundTaskRegistration> task) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *task = detach_abi(this->shim().Register());
            return S_OK;
        }
        catch (...)
        {
            *task = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IBackgroundTaskBuilder2> : produce_base<D, Windows::ApplicationModel::Background::IBackgroundTaskBuilder2>
{
    HRESULT __stdcall put_CancelOnConditionLoss(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CancelOnConditionLoss(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CancelOnConditionLoss(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CancelOnConditionLoss());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IBackgroundTaskBuilder3> : produce_base<D, Windows::ApplicationModel::Background::IBackgroundTaskBuilder3>
{
    HRESULT __stdcall put_IsNetworkRequested(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsNetworkRequested(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsNetworkRequested(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsNetworkRequested());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IBackgroundTaskCompletedEventArgs> : produce_base<D, Windows::ApplicationModel::Background::IBackgroundTaskCompletedEventArgs>
{
    HRESULT __stdcall get_InstanceId(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InstanceId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CheckResult() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CheckResult();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IBackgroundTaskDeferral> : produce_base<D, Windows::ApplicationModel::Background::IBackgroundTaskDeferral>
{
    HRESULT __stdcall abi_Complete() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Complete();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IBackgroundTaskInstance> : produce_base<D, Windows::ApplicationModel::Background::IBackgroundTaskInstance>
{
    HRESULT __stdcall get_InstanceId(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InstanceId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Task(impl::abi_arg_out<Windows::ApplicationModel::Background::IBackgroundTaskRegistration> task) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *task = detach_abi(this->shim().Task());
            return S_OK;
        }
        catch (...)
        {
            *task = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Progress(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Progress());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Progress(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Progress(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TriggerDetails(impl::abi_arg_out<Windows::Foundation::IInspectable> triggerDetails) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *triggerDetails = detach_abi(this->shim().TriggerDetails());
            return S_OK;
        }
        catch (...)
        {
            *triggerDetails = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Canceled(impl::abi_arg_in<Windows::ApplicationModel::Background::BackgroundTaskCanceledEventHandler> cancelHandler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().Canceled(*reinterpret_cast<const Windows::ApplicationModel::Background::BackgroundTaskCanceledEventHandler *>(&cancelHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Canceled(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Canceled(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SuspendedCount(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SuspendedCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::ApplicationModel::Background::IBackgroundTaskDeferral> deferral) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deferral = detach_abi(this->shim().GetDeferral());
            return S_OK;
        }
        catch (...)
        {
            *deferral = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IBackgroundTaskInstance2> : produce_base<D, Windows::ApplicationModel::Background::IBackgroundTaskInstance2>
{
    HRESULT __stdcall abi_GetThrottleCount(Windows::ApplicationModel::Background::BackgroundTaskThrottleCounter counter, uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetThrottleCount(counter));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IBackgroundTaskInstance4> : produce_base<D, Windows::ApplicationModel::Background::IBackgroundTaskInstance4>
{
    HRESULT __stdcall get_User(impl::abi_arg_out<Windows::System::IUser> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().User());
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
struct produce<D, Windows::ApplicationModel::Background::IBackgroundTaskProgressEventArgs> : produce_base<D, Windows::ApplicationModel::Background::IBackgroundTaskProgressEventArgs>
{
    HRESULT __stdcall get_InstanceId(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InstanceId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Progress(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Progress());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IBackgroundTaskRegistration> : produce_base<D, Windows::ApplicationModel::Background::IBackgroundTaskRegistration>
{
    HRESULT __stdcall get_TaskId(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TaskId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall add_Progress(impl::abi_arg_in<Windows::ApplicationModel::Background::BackgroundTaskProgressEventHandler> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().Progress(*reinterpret_cast<const Windows::ApplicationModel::Background::BackgroundTaskProgressEventHandler *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Progress(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Progress(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Completed(impl::abi_arg_in<Windows::ApplicationModel::Background::BackgroundTaskCompletedEventHandler> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().Completed(*reinterpret_cast<const Windows::ApplicationModel::Background::BackgroundTaskCompletedEventHandler *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Completed(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Completed(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Unregister(bool cancelTask) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Unregister(cancelTask);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IBackgroundTaskRegistration2> : produce_base<D, Windows::ApplicationModel::Background::IBackgroundTaskRegistration2>
{
    HRESULT __stdcall get_Trigger(impl::abi_arg_out<Windows::ApplicationModel::Background::IBackgroundTrigger> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Trigger());
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
struct produce<D, Windows::ApplicationModel::Background::IBackgroundTaskRegistrationStatics> : produce_base<D, Windows::ApplicationModel::Background::IBackgroundTaskRegistrationStatics>
{
    HRESULT __stdcall get_AllTasks(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<GUID, Windows::ApplicationModel::Background::IBackgroundTaskRegistration>> tasks) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *tasks = detach_abi(this->shim().AllTasks());
            return S_OK;
        }
        catch (...)
        {
            *tasks = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IBackgroundTrigger> : produce_base<D, Windows::ApplicationModel::Background::IBackgroundTrigger>
{};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IBackgroundWorkCostStatics> : produce_base<D, Windows::ApplicationModel::Background::IBackgroundWorkCostStatics>
{
    HRESULT __stdcall get_CurrentBackgroundWorkCost(Windows::ApplicationModel::Background::BackgroundWorkCostValue * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CurrentBackgroundWorkCost());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IBluetoothLEAdvertisementPublisherTrigger> : produce_base<D, Windows::ApplicationModel::Background::IBluetoothLEAdvertisementPublisherTrigger>
{
    HRESULT __stdcall get_Advertisement(impl::abi_arg_out<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Advertisement());
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
struct produce<D, Windows::ApplicationModel::Background::IBluetoothLEAdvertisementWatcherTrigger> : produce_base<D, Windows::ApplicationModel::Background::IBluetoothLEAdvertisementWatcherTrigger>
{
    HRESULT __stdcall get_MinSamplingInterval(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinSamplingInterval());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxSamplingInterval(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxSamplingInterval());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinOutOfRangeTimeout(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinOutOfRangeTimeout());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxOutOfRangeTimeout(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxOutOfRangeTimeout());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SignalStrengthFilter(impl::abi_arg_out<Windows::Devices::Bluetooth::IBluetoothSignalStrengthFilter> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SignalStrengthFilter());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SignalStrengthFilter(impl::abi_arg_in<Windows::Devices::Bluetooth::IBluetoothSignalStrengthFilter> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SignalStrengthFilter(*reinterpret_cast<const Windows::Devices::Bluetooth::BluetoothSignalStrengthFilter *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AdvertisementFilter(impl::abi_arg_out<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementFilter> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AdvertisementFilter());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AdvertisementFilter(impl::abi_arg_in<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementFilter> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AdvertisementFilter(*reinterpret_cast<const Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFilter *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::ICachedFileUpdaterTrigger> : produce_base<D, Windows::ApplicationModel::Background::ICachedFileUpdaterTrigger>
{};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::ICachedFileUpdaterTriggerDetails> : produce_base<D, Windows::ApplicationModel::Background::ICachedFileUpdaterTriggerDetails>
{
    HRESULT __stdcall get_UpdateTarget(Windows::Storage::Provider::CachedFileTarget * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UpdateTarget());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UpdateRequest(impl::abi_arg_out<Windows::Storage::Provider::IFileUpdateRequest> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UpdateRequest());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanRequestUserInput(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanRequestUserInput());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IChatMessageNotificationTrigger> : produce_base<D, Windows::ApplicationModel::Background::IChatMessageNotificationTrigger>
{};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IChatMessageReceivedNotificationTrigger> : produce_base<D, Windows::ApplicationModel::Background::IChatMessageReceivedNotificationTrigger>
{};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::ICommunicationBlockingAppSetAsActiveTrigger> : produce_base<D, Windows::ApplicationModel::Background::ICommunicationBlockingAppSetAsActiveTrigger>
{};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IContactStoreNotificationTrigger> : produce_base<D, Windows::ApplicationModel::Background::IContactStoreNotificationTrigger>
{};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IContentPrefetchTrigger> : produce_base<D, Windows::ApplicationModel::Background::IContentPrefetchTrigger>
{
    HRESULT __stdcall get_WaitInterval(impl::abi_arg_out<Windows::Foundation::TimeSpan> waitInterval) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *waitInterval = detach_abi(this->shim().WaitInterval());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IContentPrefetchTriggerFactory> : produce_base<D, Windows::ApplicationModel::Background::IContentPrefetchTriggerFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Foundation::TimeSpan> waitInterval, impl::abi_arg_out<Windows::ApplicationModel::Background::IContentPrefetchTrigger> trigger) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *trigger = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&waitInterval)));
            return S_OK;
        }
        catch (...)
        {
            *trigger = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IDeviceConnectionChangeTrigger> : produce_base<D, Windows::ApplicationModel::Background::IDeviceConnectionChangeTrigger>
{
    HRESULT __stdcall get_DeviceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanMaintainConnection(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanMaintainConnection());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaintainConnection(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaintainConnection());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaintainConnection(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaintainConnection(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IDeviceConnectionChangeTriggerStatics> : produce_base<D, Windows::ApplicationModel::Background::IDeviceConnectionChangeTriggerStatics>
{
    HRESULT __stdcall abi_FromIdAsync(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Background::DeviceConnectionChangeTrigger>> deviceChangeTrigger) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deviceChangeTrigger = detach_abi(this->shim().FromIdAsync(*reinterpret_cast<const hstring *>(&deviceId)));
            return S_OK;
        }
        catch (...)
        {
            *deviceChangeTrigger = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IDeviceManufacturerNotificationTrigger> : produce_base<D, Windows::ApplicationModel::Background::IDeviceManufacturerNotificationTrigger>
{
    HRESULT __stdcall get_TriggerQualifier(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TriggerQualifier());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OneShot(bool * oneShot) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *oneShot = detach_abi(this->shim().OneShot());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IDeviceManufacturerNotificationTriggerFactory> : produce_base<D, Windows::ApplicationModel::Background::IDeviceManufacturerNotificationTriggerFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> triggerQualifier, bool oneShot, impl::abi_arg_out<Windows::ApplicationModel::Background::IDeviceManufacturerNotificationTrigger> trigger) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *trigger = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&triggerQualifier), oneShot));
            return S_OK;
        }
        catch (...)
        {
            *trigger = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IDeviceServicingTrigger> : produce_base<D, Windows::ApplicationModel::Background::IDeviceServicingTrigger>
{
    HRESULT __stdcall abi_RequestAsyncSimple(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_in<Windows::Foundation::TimeSpan> expectedDuration, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::DeviceTriggerResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestAsync(*reinterpret_cast<const hstring *>(&deviceId), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&expectedDuration)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestAsyncWithArguments(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_in<Windows::Foundation::TimeSpan> expectedDuration, impl::abi_arg_in<hstring> arguments, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::DeviceTriggerResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestAsync(*reinterpret_cast<const hstring *>(&deviceId), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&expectedDuration), *reinterpret_cast<const hstring *>(&arguments)));
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
struct produce<D, Windows::ApplicationModel::Background::IDeviceUseTrigger> : produce_base<D, Windows::ApplicationModel::Background::IDeviceUseTrigger>
{
    HRESULT __stdcall abi_RequestAsyncSimple(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::DeviceTriggerResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestAsync(*reinterpret_cast<const hstring *>(&deviceId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestAsyncWithArguments(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_in<hstring> arguments, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::DeviceTriggerResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestAsync(*reinterpret_cast<const hstring *>(&deviceId), *reinterpret_cast<const hstring *>(&arguments)));
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
struct produce<D, Windows::ApplicationModel::Background::IDeviceWatcherTrigger> : produce_base<D, Windows::ApplicationModel::Background::IDeviceWatcherTrigger>
{};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IEmailStoreNotificationTrigger> : produce_base<D, Windows::ApplicationModel::Background::IEmailStoreNotificationTrigger>
{};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IGattCharacteristicNotificationTrigger> : produce_base<D, Windows::ApplicationModel::Background::IGattCharacteristicNotificationTrigger>
{
    HRESULT __stdcall get_Characteristic(impl::abi_arg_out<Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristic> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Characteristic());
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
struct produce<D, Windows::ApplicationModel::Background::IGattCharacteristicNotificationTriggerFactory> : produce_base<D, Windows::ApplicationModel::Background::IGattCharacteristicNotificationTriggerFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristic> characteristic, impl::abi_arg_out<Windows::ApplicationModel::Background::IGattCharacteristicNotificationTrigger> gattCharacteristicNotificationTrigger) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *gattCharacteristicNotificationTrigger = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic *>(&characteristic)));
            return S_OK;
        }
        catch (...)
        {
            *gattCharacteristicNotificationTrigger = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::ILocationTrigger> : produce_base<D, Windows::ApplicationModel::Background::ILocationTrigger>
{
    HRESULT __stdcall get_TriggerType(Windows::ApplicationModel::Background::LocationTriggerType * triggerType) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *triggerType = detach_abi(this->shim().TriggerType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::ILocationTriggerFactory> : produce_base<D, Windows::ApplicationModel::Background::ILocationTriggerFactory>
{
    HRESULT __stdcall abi_Create(Windows::ApplicationModel::Background::LocationTriggerType triggerType, impl::abi_arg_out<Windows::ApplicationModel::Background::ILocationTrigger> locationTrigger) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *locationTrigger = detach_abi(this->shim().Create(triggerType));
            return S_OK;
        }
        catch (...)
        {
            *locationTrigger = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IMaintenanceTrigger> : produce_base<D, Windows::ApplicationModel::Background::IMaintenanceTrigger>
{
    HRESULT __stdcall get_FreshnessTime(uint32_t * freshnessTime) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *freshnessTime = detach_abi(this->shim().FreshnessTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OneShot(bool * oneShot) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *oneShot = detach_abi(this->shim().OneShot());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IMaintenanceTriggerFactory> : produce_base<D, Windows::ApplicationModel::Background::IMaintenanceTriggerFactory>
{
    HRESULT __stdcall abi_Create(uint32_t freshnessTime, bool oneShot, impl::abi_arg_out<Windows::ApplicationModel::Background::IMaintenanceTrigger> trigger) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *trigger = detach_abi(this->shim().Create(freshnessTime, oneShot));
            return S_OK;
        }
        catch (...)
        {
            *trigger = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IMediaProcessingTrigger> : produce_base<D, Windows::ApplicationModel::Background::IMediaProcessingTrigger>
{
    HRESULT __stdcall abi_RequestAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::MediaProcessingTriggerResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestAsyncWithArguments(impl::abi_arg_in<Windows::Foundation::Collections::IPropertySet> arguments, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::MediaProcessingTriggerResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestAsync(*reinterpret_cast<const Windows::Foundation::Collections::ValueSet *>(&arguments)));
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
struct produce<D, Windows::ApplicationModel::Background::INetworkOperatorHotspotAuthenticationTrigger> : produce_base<D, Windows::ApplicationModel::Background::INetworkOperatorHotspotAuthenticationTrigger>
{};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::INetworkOperatorNotificationTrigger> : produce_base<D, Windows::ApplicationModel::Background::INetworkOperatorNotificationTrigger>
{
    HRESULT __stdcall get_NetworkAccountId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NetworkAccountId());
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
struct produce<D, Windows::ApplicationModel::Background::INetworkOperatorNotificationTriggerFactory> : produce_base<D, Windows::ApplicationModel::Background::INetworkOperatorNotificationTriggerFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> networkAccountId, impl::abi_arg_out<Windows::ApplicationModel::Background::INetworkOperatorNotificationTrigger> trigger) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *trigger = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&networkAccountId)));
            return S_OK;
        }
        catch (...)
        {
            *trigger = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IPhoneTrigger> : produce_base<D, Windows::ApplicationModel::Background::IPhoneTrigger>
{
    HRESULT __stdcall get_OneShot(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OneShot());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TriggerType(Windows::ApplicationModel::Calls::Background::PhoneTriggerType * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TriggerType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IPhoneTriggerFactory> : produce_base<D, Windows::ApplicationModel::Background::IPhoneTriggerFactory>
{
    HRESULT __stdcall abi_Create(Windows::ApplicationModel::Calls::Background::PhoneTriggerType type, bool oneShot, impl::abi_arg_out<Windows::ApplicationModel::Background::IPhoneTrigger> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(type, oneShot));
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
struct produce<D, Windows::ApplicationModel::Background::IPushNotificationTriggerFactory> : produce_base<D, Windows::ApplicationModel::Background::IPushNotificationTriggerFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> applicationId, impl::abi_arg_out<Windows::ApplicationModel::Background::IBackgroundTrigger> trigger) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *trigger = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&applicationId)));
            return S_OK;
        }
        catch (...)
        {
            *trigger = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IRcsEndUserMessageAvailableTrigger> : produce_base<D, Windows::ApplicationModel::Background::IRcsEndUserMessageAvailableTrigger>
{};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IRfcommConnectionTrigger> : produce_base<D, Windows::ApplicationModel::Background::IRfcommConnectionTrigger>
{
    HRESULT __stdcall get_InboundConnection(impl::abi_arg_out<Windows::Devices::Bluetooth::Background::IRfcommInboundConnectionInformation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InboundConnection());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OutboundConnection(impl::abi_arg_out<Windows::Devices::Bluetooth::Background::IRfcommOutboundConnectionInformation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OutboundConnection());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AllowMultipleConnections(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllowMultipleConnections());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AllowMultipleConnections(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowMultipleConnections(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProtectionLevel(Windows::Networking::Sockets::SocketProtectionLevel * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProtectionLevel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ProtectionLevel(Windows::Networking::Sockets::SocketProtectionLevel value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProtectionLevel(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RemoteHostName(impl::abi_arg_out<Windows::Networking::IHostName> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RemoteHostName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RemoteHostName(impl::abi_arg_in<Windows::Networking::IHostName> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoteHostName(*reinterpret_cast<const Windows::Networking::HostName *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::ISecondaryAuthenticationFactorAuthenticationTrigger> : produce_base<D, Windows::ApplicationModel::Background::ISecondaryAuthenticationFactorAuthenticationTrigger>
{};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::ISensorDataThresholdTrigger> : produce_base<D, Windows::ApplicationModel::Background::ISensorDataThresholdTrigger>
{};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::ISensorDataThresholdTriggerFactory> : produce_base<D, Windows::ApplicationModel::Background::ISensorDataThresholdTriggerFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Devices::Sensors::ISensorDataThreshold> threshold, impl::abi_arg_out<Windows::ApplicationModel::Background::ISensorDataThresholdTrigger> trigger) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *trigger = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Devices::Sensors::ISensorDataThreshold *>(&threshold)));
            return S_OK;
        }
        catch (...)
        {
            *trigger = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::ISmartCardTrigger> : produce_base<D, Windows::ApplicationModel::Background::ISmartCardTrigger>
{
    HRESULT __stdcall get_TriggerType(Windows::Devices::SmartCards::SmartCardTriggerType * triggerType) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *triggerType = detach_abi(this->shim().TriggerType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::ISmartCardTriggerFactory> : produce_base<D, Windows::ApplicationModel::Background::ISmartCardTriggerFactory>
{
    HRESULT __stdcall abi_Create(Windows::Devices::SmartCards::SmartCardTriggerType triggerType, impl::abi_arg_out<Windows::ApplicationModel::Background::ISmartCardTrigger> trigger) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *trigger = detach_abi(this->shim().Create(triggerType));
            return S_OK;
        }
        catch (...)
        {
            *trigger = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::ISmsMessageReceivedTriggerFactory> : produce_base<D, Windows::ApplicationModel::Background::ISmsMessageReceivedTriggerFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Devices::Sms::ISmsFilterRules> filterRules, impl::abi_arg_out<Windows::ApplicationModel::Background::IBackgroundTrigger> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Devices::Sms::SmsFilterRules *>(&filterRules)));
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
struct produce<D, Windows::ApplicationModel::Background::ISocketActivityTrigger> : produce_base<D, Windows::ApplicationModel::Background::ISocketActivityTrigger>
{
    HRESULT __stdcall get_IsWakeFromLowPowerSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsWakeFromLowPowerSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IStorageLibraryContentChangedTrigger> : produce_base<D, Windows::ApplicationModel::Background::IStorageLibraryContentChangedTrigger>
{};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IStorageLibraryContentChangedTriggerStatics> : produce_base<D, Windows::ApplicationModel::Background::IStorageLibraryContentChangedTriggerStatics>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Storage::IStorageLibrary> storageLibrary, impl::abi_arg_out<Windows::ApplicationModel::Background::IStorageLibraryContentChangedTrigger> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Storage::StorageLibrary *>(&storageLibrary)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromLibraries(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Storage::StorageLibrary>> storageLibraries, impl::abi_arg_out<Windows::ApplicationModel::Background::IStorageLibraryContentChangedTrigger> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateFromLibraries(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Storage::StorageLibrary> *>(&storageLibraries)));
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
struct produce<D, Windows::ApplicationModel::Background::ISystemCondition> : produce_base<D, Windows::ApplicationModel::Background::ISystemCondition>
{
    HRESULT __stdcall get_ConditionType(Windows::ApplicationModel::Background::SystemConditionType * conditionType) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *conditionType = detach_abi(this->shim().ConditionType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::ISystemConditionFactory> : produce_base<D, Windows::ApplicationModel::Background::ISystemConditionFactory>
{
    HRESULT __stdcall abi_Create(Windows::ApplicationModel::Background::SystemConditionType conditionType, impl::abi_arg_out<Windows::ApplicationModel::Background::ISystemCondition> condition) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *condition = detach_abi(this->shim().Create(conditionType));
            return S_OK;
        }
        catch (...)
        {
            *condition = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::ISystemTrigger> : produce_base<D, Windows::ApplicationModel::Background::ISystemTrigger>
{
    HRESULT __stdcall get_OneShot(bool * oneShot) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *oneShot = detach_abi(this->shim().OneShot());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TriggerType(Windows::ApplicationModel::Background::SystemTriggerType * triggerType) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *triggerType = detach_abi(this->shim().TriggerType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::ISystemTriggerFactory> : produce_base<D, Windows::ApplicationModel::Background::ISystemTriggerFactory>
{
    HRESULT __stdcall abi_Create(Windows::ApplicationModel::Background::SystemTriggerType triggerType, bool oneShot, impl::abi_arg_out<Windows::ApplicationModel::Background::ISystemTrigger> trigger) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *trigger = detach_abi(this->shim().Create(triggerType, oneShot));
            return S_OK;
        }
        catch (...)
        {
            *trigger = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::ITimeTrigger> : produce_base<D, Windows::ApplicationModel::Background::ITimeTrigger>
{
    HRESULT __stdcall get_FreshnessTime(uint32_t * freshnessTime) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *freshnessTime = detach_abi(this->shim().FreshnessTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OneShot(bool * oneShot) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *oneShot = detach_abi(this->shim().OneShot());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::ITimeTriggerFactory> : produce_base<D, Windows::ApplicationModel::Background::ITimeTriggerFactory>
{
    HRESULT __stdcall abi_Create(uint32_t freshnessTime, bool oneShot, impl::abi_arg_out<Windows::ApplicationModel::Background::ITimeTrigger> trigger) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *trigger = detach_abi(this->shim().Create(freshnessTime, oneShot));
            return S_OK;
        }
        catch (...)
        {
            *trigger = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IToastNotificationActionTriggerFactory> : produce_base<D, Windows::ApplicationModel::Background::IToastNotificationActionTriggerFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> applicationId, impl::abi_arg_out<Windows::ApplicationModel::Background::IBackgroundTrigger> trigger) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *trigger = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&applicationId)));
            return S_OK;
        }
        catch (...)
        {
            *trigger = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IToastNotificationHistoryChangedTriggerFactory> : produce_base<D, Windows::ApplicationModel::Background::IToastNotificationHistoryChangedTriggerFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> applicationId, impl::abi_arg_out<Windows::ApplicationModel::Background::IBackgroundTrigger> trigger) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *trigger = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&applicationId)));
            return S_OK;
        }
        catch (...)
        {
            *trigger = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Background::IUserNotificationChangedTriggerFactory> : produce_base<D, Windows::ApplicationModel::Background::IUserNotificationChangedTriggerFactory>
{
    HRESULT __stdcall abi_Create(Windows::UI::Notifications::NotificationKinds notificationKinds, impl::abi_arg_out<Windows::ApplicationModel::Background::IBackgroundTrigger> trigger) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *trigger = detach_abi(this->shim().Create(notificationKinds));
            return S_OK;
        }
        catch (...)
        {
            *trigger = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::ApplicationModel::Background {

template <typename D> Windows::Foundation::Collections::ValueSet impl_IApplicationTriggerDetails<D>::Arguments() const
{
    Windows::Foundation::Collections::ValueSet value { nullptr };
    check_hresult(WINRT_SHIM(IApplicationTriggerDetails)->get_Arguments(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::BackgroundAccessStatus> impl_IBackgroundExecutionManagerStatics<D>::RequestAccessAsync() const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::BackgroundAccessStatus> operation;
    check_hresult(WINRT_SHIM(IBackgroundExecutionManagerStatics)->abi_RequestAccessAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::BackgroundAccessStatus> impl_IBackgroundExecutionManagerStatics<D>::RequestAccessAsync(hstring_view applicationId) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::BackgroundAccessStatus> operation;
    check_hresult(WINRT_SHIM(IBackgroundExecutionManagerStatics)->abi_RequestAccessForApplicationAsync(get_abi(applicationId), put_abi(operation)));
    return operation;
}

template <typename D> void impl_IBackgroundExecutionManagerStatics<D>::RemoveAccess() const
{
    check_hresult(WINRT_SHIM(IBackgroundExecutionManagerStatics)->abi_RemoveAccess());
}

template <typename D> void impl_IBackgroundExecutionManagerStatics<D>::RemoveAccess(hstring_view applicationId) const
{
    check_hresult(WINRT_SHIM(IBackgroundExecutionManagerStatics)->abi_RemoveAccessForApplication(get_abi(applicationId)));
}

template <typename D> Windows::ApplicationModel::Background::BackgroundAccessStatus impl_IBackgroundExecutionManagerStatics<D>::GetAccessStatus() const
{
    Windows::ApplicationModel::Background::BackgroundAccessStatus status {};
    check_hresult(WINRT_SHIM(IBackgroundExecutionManagerStatics)->abi_GetAccessStatus(&status));
    return status;
}

template <typename D> Windows::ApplicationModel::Background::BackgroundAccessStatus impl_IBackgroundExecutionManagerStatics<D>::GetAccessStatus(hstring_view applicationId) const
{
    Windows::ApplicationModel::Background::BackgroundAccessStatus status {};
    check_hresult(WINRT_SHIM(IBackgroundExecutionManagerStatics)->abi_GetAccessStatusForApplication(get_abi(applicationId), &status));
    return status;
}

template <typename D> GUID impl_IBackgroundTaskInstance<D>::InstanceId() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(IBackgroundTaskInstance)->get_InstanceId(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Background::BackgroundTaskRegistration impl_IBackgroundTaskInstance<D>::Task() const
{
    Windows::ApplicationModel::Background::BackgroundTaskRegistration task { nullptr };
    check_hresult(WINRT_SHIM(IBackgroundTaskInstance)->get_Task(put_abi(task)));
    return task;
}

template <typename D> uint32_t impl_IBackgroundTaskInstance<D>::Progress() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBackgroundTaskInstance)->get_Progress(&value));
    return value;
}

template <typename D> void impl_IBackgroundTaskInstance<D>::Progress(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IBackgroundTaskInstance)->put_Progress(value));
}

template <typename D> Windows::Foundation::IInspectable impl_IBackgroundTaskInstance<D>::TriggerDetails() const
{
    Windows::Foundation::IInspectable triggerDetails;
    check_hresult(WINRT_SHIM(IBackgroundTaskInstance)->get_TriggerDetails(put_abi(triggerDetails)));
    return triggerDetails;
}

template <typename D> event_token impl_IBackgroundTaskInstance<D>::Canceled(const Windows::ApplicationModel::Background::BackgroundTaskCanceledEventHandler & cancelHandler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IBackgroundTaskInstance)->add_Canceled(get_abi(cancelHandler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IBackgroundTaskInstance> impl_IBackgroundTaskInstance<D>::Canceled(auto_revoke_t, const Windows::ApplicationModel::Background::BackgroundTaskCanceledEventHandler & cancelHandler) const
{
    return impl::make_event_revoker<D, IBackgroundTaskInstance>(this, &ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance::remove_Canceled, Canceled(cancelHandler));
}

template <typename D> void impl_IBackgroundTaskInstance<D>::Canceled(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IBackgroundTaskInstance)->remove_Canceled(cookie));
}

template <typename D> uint32_t impl_IBackgroundTaskInstance<D>::SuspendedCount() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBackgroundTaskInstance)->get_SuspendedCount(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Background::BackgroundTaskDeferral impl_IBackgroundTaskInstance<D>::GetDeferral() const
{
    Windows::ApplicationModel::Background::BackgroundTaskDeferral deferral { nullptr };
    check_hresult(WINRT_SHIM(IBackgroundTaskInstance)->abi_GetDeferral(put_abi(deferral)));
    return deferral;
}

template <typename D> Windows::ApplicationModel::Background::BackgroundWorkCostValue impl_IBackgroundWorkCostStatics<D>::CurrentBackgroundWorkCost() const
{
    Windows::ApplicationModel::Background::BackgroundWorkCostValue value {};
    check_hresult(WINRT_SHIM(IBackgroundWorkCostStatics)->get_CurrentBackgroundWorkCost(&value));
    return value;
}

template <typename D> void impl_IBackgroundTaskDeferral<D>::Complete() const
{
    check_hresult(WINRT_SHIM(IBackgroundTaskDeferral)->abi_Complete());
}

template <typename D> uint32_t impl_IBackgroundTaskInstance2<D>::GetThrottleCount(Windows::ApplicationModel::Background::BackgroundTaskThrottleCounter counter) const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBackgroundTaskInstance2)->abi_GetThrottleCount(counter, &value));
    return value;
}

template <typename D> Windows::System::User impl_IBackgroundTaskInstance4<D>::User() const
{
    Windows::System::User value { nullptr };
    check_hresult(WINRT_SHIM(IBackgroundTaskInstance4)->get_User(put_abi(value)));
    return value;
}

template <typename D> void impl_IBackgroundTask<D>::Run(const Windows::ApplicationModel::Background::IBackgroundTaskInstance & taskInstance) const
{
    check_hresult(WINRT_SHIM(IBackgroundTask)->abi_Run(get_abi(taskInstance)));
}

template <typename D> GUID impl_IBackgroundTaskRegistration<D>::TaskId() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(IBackgroundTaskRegistration)->get_TaskId(&value));
    return value;
}

template <typename D> hstring impl_IBackgroundTaskRegistration<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IBackgroundTaskRegistration)->get_Name(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IBackgroundTaskRegistration<D>::Progress(const Windows::ApplicationModel::Background::BackgroundTaskProgressEventHandler & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IBackgroundTaskRegistration)->add_Progress(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IBackgroundTaskRegistration> impl_IBackgroundTaskRegistration<D>::Progress(auto_revoke_t, const Windows::ApplicationModel::Background::BackgroundTaskProgressEventHandler & handler) const
{
    return impl::make_event_revoker<D, IBackgroundTaskRegistration>(this, &ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration::remove_Progress, Progress(handler));
}

template <typename D> void impl_IBackgroundTaskRegistration<D>::Progress(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IBackgroundTaskRegistration)->remove_Progress(cookie));
}

template <typename D> event_token impl_IBackgroundTaskRegistration<D>::Completed(const Windows::ApplicationModel::Background::BackgroundTaskCompletedEventHandler & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IBackgroundTaskRegistration)->add_Completed(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IBackgroundTaskRegistration> impl_IBackgroundTaskRegistration<D>::Completed(auto_revoke_t, const Windows::ApplicationModel::Background::BackgroundTaskCompletedEventHandler & handler) const
{
    return impl::make_event_revoker<D, IBackgroundTaskRegistration>(this, &ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration::remove_Completed, Completed(handler));
}

template <typename D> void impl_IBackgroundTaskRegistration<D>::Completed(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IBackgroundTaskRegistration)->remove_Completed(cookie));
}

template <typename D> void impl_IBackgroundTaskRegistration<D>::Unregister(bool cancelTask) const
{
    check_hresult(WINRT_SHIM(IBackgroundTaskRegistration)->abi_Unregister(cancelTask));
}

template <typename D> Windows::ApplicationModel::Background::IBackgroundTrigger impl_IBackgroundTaskRegistration2<D>::Trigger() const
{
    Windows::ApplicationModel::Background::IBackgroundTrigger value;
    check_hresult(WINRT_SHIM(IBackgroundTaskRegistration2)->get_Trigger(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::ApplicationTriggerResult> impl_IApplicationTrigger<D>::RequestAsync() const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::ApplicationTriggerResult> result;
    check_hresult(WINRT_SHIM(IApplicationTrigger)->abi_RequestAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::ApplicationTriggerResult> impl_IApplicationTrigger<D>::RequestAsync(const Windows::Foundation::Collections::ValueSet & arguments) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::ApplicationTriggerResult> result;
    check_hresult(WINRT_SHIM(IApplicationTrigger)->abi_RequestAsyncWithArguments(get_abi(arguments), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::MediaProcessingTriggerResult> impl_IMediaProcessingTrigger<D>::RequestAsync() const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::MediaProcessingTriggerResult> result;
    check_hresult(WINRT_SHIM(IMediaProcessingTrigger)->abi_RequestAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::MediaProcessingTriggerResult> impl_IMediaProcessingTrigger<D>::RequestAsync(const Windows::Foundation::Collections::ValueSet & arguments) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::MediaProcessingTriggerResult> result;
    check_hresult(WINRT_SHIM(IMediaProcessingTrigger)->abi_RequestAsyncWithArguments(get_abi(arguments), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Collections::IMapView<GUID, Windows::ApplicationModel::Background::IBackgroundTaskRegistration> impl_IBackgroundTaskRegistrationStatics<D>::AllTasks() const
{
    Windows::Foundation::Collections::IMapView<GUID, Windows::ApplicationModel::Background::IBackgroundTaskRegistration> tasks;
    check_hresult(WINRT_SHIM(IBackgroundTaskRegistrationStatics)->get_AllTasks(put_abi(tasks)));
    return tasks;
}

template <typename D> void impl_IBackgroundTaskBuilder<D>::TaskEntryPoint(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IBackgroundTaskBuilder)->put_TaskEntryPoint(get_abi(value)));
}

template <typename D> hstring impl_IBackgroundTaskBuilder<D>::TaskEntryPoint() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IBackgroundTaskBuilder)->get_TaskEntryPoint(put_abi(value)));
    return value;
}

template <typename D> void impl_IBackgroundTaskBuilder<D>::SetTrigger(const Windows::ApplicationModel::Background::IBackgroundTrigger & trigger) const
{
    check_hresult(WINRT_SHIM(IBackgroundTaskBuilder)->abi_SetTrigger(get_abi(trigger)));
}

template <typename D> void impl_IBackgroundTaskBuilder<D>::AddCondition(const Windows::ApplicationModel::Background::IBackgroundCondition & condition) const
{
    check_hresult(WINRT_SHIM(IBackgroundTaskBuilder)->abi_AddCondition(get_abi(condition)));
}

template <typename D> void impl_IBackgroundTaskBuilder<D>::Name(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IBackgroundTaskBuilder)->put_Name(get_abi(value)));
}

template <typename D> hstring impl_IBackgroundTaskBuilder<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IBackgroundTaskBuilder)->get_Name(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Background::BackgroundTaskRegistration impl_IBackgroundTaskBuilder<D>::Register() const
{
    Windows::ApplicationModel::Background::BackgroundTaskRegistration task { nullptr };
    check_hresult(WINRT_SHIM(IBackgroundTaskBuilder)->abi_Register(put_abi(task)));
    return task;
}

template <typename D> void impl_IBackgroundTaskBuilder2<D>::CancelOnConditionLoss(bool value) const
{
    check_hresult(WINRT_SHIM(IBackgroundTaskBuilder2)->put_CancelOnConditionLoss(value));
}

template <typename D> bool impl_IBackgroundTaskBuilder2<D>::CancelOnConditionLoss() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IBackgroundTaskBuilder2)->get_CancelOnConditionLoss(&value));
    return value;
}

template <typename D> void impl_IBackgroundTaskBuilder3<D>::IsNetworkRequested(bool value) const
{
    check_hresult(WINRT_SHIM(IBackgroundTaskBuilder3)->put_IsNetworkRequested(value));
}

template <typename D> bool impl_IBackgroundTaskBuilder3<D>::IsNetworkRequested() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IBackgroundTaskBuilder3)->get_IsNetworkRequested(&value));
    return value;
}

template <typename D> GUID impl_IBackgroundTaskCompletedEventArgs<D>::InstanceId() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(IBackgroundTaskCompletedEventArgs)->get_InstanceId(&value));
    return value;
}

template <typename D> void impl_IBackgroundTaskCompletedEventArgs<D>::CheckResult() const
{
    check_hresult(WINRT_SHIM(IBackgroundTaskCompletedEventArgs)->abi_CheckResult());
}

template <typename D> GUID impl_IBackgroundTaskProgressEventArgs<D>::InstanceId() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(IBackgroundTaskProgressEventArgs)->get_InstanceId(&value));
    return value;
}

template <typename D> uint32_t impl_IBackgroundTaskProgressEventArgs<D>::Progress() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBackgroundTaskProgressEventArgs)->get_Progress(&value));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IContentPrefetchTrigger<D>::WaitInterval() const
{
    Windows::Foundation::TimeSpan waitInterval {};
    check_hresult(WINRT_SHIM(IContentPrefetchTrigger)->get_WaitInterval(put_abi(waitInterval)));
    return waitInterval;
}

template <typename D> Windows::ApplicationModel::Background::ContentPrefetchTrigger impl_IContentPrefetchTriggerFactory<D>::Create(const Windows::Foundation::TimeSpan & waitInterval) const
{
    Windows::ApplicationModel::Background::ContentPrefetchTrigger trigger { nullptr };
    check_hresult(WINRT_SHIM(IContentPrefetchTriggerFactory)->abi_Create(get_abi(waitInterval), put_abi(trigger)));
    return trigger;
}

template <typename D> Windows::ApplicationModel::Background::SmsMessageReceivedTrigger impl_ISmsMessageReceivedTriggerFactory<D>::Create(const Windows::Devices::Sms::SmsFilterRules & filterRules) const
{
    Windows::ApplicationModel::Background::SmsMessageReceivedTrigger value { nullptr };
    check_hresult(WINRT_SHIM(ISmsMessageReceivedTriggerFactory)->abi_Create(get_abi(filterRules), put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Background::StorageLibraryContentChangedTrigger impl_IStorageLibraryContentChangedTriggerStatics<D>::Create(const Windows::Storage::StorageLibrary & storageLibrary) const
{
    Windows::ApplicationModel::Background::StorageLibraryContentChangedTrigger result { nullptr };
    check_hresult(WINRT_SHIM(IStorageLibraryContentChangedTriggerStatics)->abi_Create(get_abi(storageLibrary), put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Background::StorageLibraryContentChangedTrigger impl_IStorageLibraryContentChangedTriggerStatics<D>::CreateFromLibraries(iterable<Windows::Storage::StorageLibrary> storageLibraries) const
{
    Windows::ApplicationModel::Background::StorageLibraryContentChangedTrigger result { nullptr };
    check_hresult(WINRT_SHIM(IStorageLibraryContentChangedTriggerStatics)->abi_CreateFromLibraries(get_abi(storageLibraries), put_abi(result)));
    return result;
}

template <typename D> bool impl_ISystemTrigger<D>::OneShot() const
{
    bool oneShot {};
    check_hresult(WINRT_SHIM(ISystemTrigger)->get_OneShot(&oneShot));
    return oneShot;
}

template <typename D> Windows::ApplicationModel::Background::SystemTriggerType impl_ISystemTrigger<D>::TriggerType() const
{
    Windows::ApplicationModel::Background::SystemTriggerType triggerType {};
    check_hresult(WINRT_SHIM(ISystemTrigger)->get_TriggerType(&triggerType));
    return triggerType;
}

template <typename D> Windows::ApplicationModel::Background::SystemTrigger impl_ISystemTriggerFactory<D>::Create(Windows::ApplicationModel::Background::SystemTriggerType triggerType, bool oneShot) const
{
    Windows::ApplicationModel::Background::SystemTrigger trigger { nullptr };
    check_hresult(WINRT_SHIM(ISystemTriggerFactory)->abi_Create(triggerType, oneShot, put_abi(trigger)));
    return trigger;
}

template <typename D> Windows::ApplicationModel::Background::SystemConditionType impl_ISystemCondition<D>::ConditionType() const
{
    Windows::ApplicationModel::Background::SystemConditionType conditionType {};
    check_hresult(WINRT_SHIM(ISystemCondition)->get_ConditionType(&conditionType));
    return conditionType;
}

template <typename D> Windows::ApplicationModel::Background::SystemCondition impl_ISystemConditionFactory<D>::Create(Windows::ApplicationModel::Background::SystemConditionType conditionType) const
{
    Windows::ApplicationModel::Background::SystemCondition condition { nullptr };
    check_hresult(WINRT_SHIM(ISystemConditionFactory)->abi_Create(conditionType, put_abi(condition)));
    return condition;
}

template <typename D> hstring impl_INetworkOperatorNotificationTrigger<D>::NetworkAccountId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INetworkOperatorNotificationTrigger)->get_NetworkAccountId(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Background::NetworkOperatorNotificationTrigger impl_INetworkOperatorNotificationTriggerFactory<D>::Create(hstring_view networkAccountId) const
{
    Windows::ApplicationModel::Background::NetworkOperatorNotificationTrigger trigger { nullptr };
    check_hresult(WINRT_SHIM(INetworkOperatorNotificationTriggerFactory)->abi_Create(get_abi(networkAccountId), put_abi(trigger)));
    return trigger;
}

template <typename D> hstring impl_IDeviceManufacturerNotificationTrigger<D>::TriggerQualifier() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDeviceManufacturerNotificationTrigger)->get_TriggerQualifier(put_abi(value)));
    return value;
}

template <typename D> bool impl_IDeviceManufacturerNotificationTrigger<D>::OneShot() const
{
    bool oneShot {};
    check_hresult(WINRT_SHIM(IDeviceManufacturerNotificationTrigger)->get_OneShot(&oneShot));
    return oneShot;
}

template <typename D> Windows::ApplicationModel::Background::DeviceManufacturerNotificationTrigger impl_IDeviceManufacturerNotificationTriggerFactory<D>::Create(hstring_view triggerQualifier, bool oneShot) const
{
    Windows::ApplicationModel::Background::DeviceManufacturerNotificationTrigger trigger { nullptr };
    check_hresult(WINRT_SHIM(IDeviceManufacturerNotificationTriggerFactory)->abi_Create(get_abi(triggerQualifier), oneShot, put_abi(trigger)));
    return trigger;
}

template <typename D> Windows::Storage::Provider::CachedFileTarget impl_ICachedFileUpdaterTriggerDetails<D>::UpdateTarget() const
{
    Windows::Storage::Provider::CachedFileTarget value {};
    check_hresult(WINRT_SHIM(ICachedFileUpdaterTriggerDetails)->get_UpdateTarget(&value));
    return value;
}

template <typename D> Windows::Storage::Provider::FileUpdateRequest impl_ICachedFileUpdaterTriggerDetails<D>::UpdateRequest() const
{
    Windows::Storage::Provider::FileUpdateRequest value { nullptr };
    check_hresult(WINRT_SHIM(ICachedFileUpdaterTriggerDetails)->get_UpdateRequest(put_abi(value)));
    return value;
}

template <typename D> bool impl_ICachedFileUpdaterTriggerDetails<D>::CanRequestUserInput() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICachedFileUpdaterTriggerDetails)->get_CanRequestUserInput(&value));
    return value;
}

template <typename D> uint32_t impl_ITimeTrigger<D>::FreshnessTime() const
{
    uint32_t freshnessTime {};
    check_hresult(WINRT_SHIM(ITimeTrigger)->get_FreshnessTime(&freshnessTime));
    return freshnessTime;
}

template <typename D> bool impl_ITimeTrigger<D>::OneShot() const
{
    bool oneShot {};
    check_hresult(WINRT_SHIM(ITimeTrigger)->get_OneShot(&oneShot));
    return oneShot;
}

template <typename D> Windows::ApplicationModel::Background::TimeTrigger impl_ITimeTriggerFactory<D>::Create(uint32_t freshnessTime, bool oneShot) const
{
    Windows::ApplicationModel::Background::TimeTrigger trigger { nullptr };
    check_hresult(WINRT_SHIM(ITimeTriggerFactory)->abi_Create(freshnessTime, oneShot, put_abi(trigger)));
    return trigger;
}

template <typename D> uint32_t impl_IMaintenanceTrigger<D>::FreshnessTime() const
{
    uint32_t freshnessTime {};
    check_hresult(WINRT_SHIM(IMaintenanceTrigger)->get_FreshnessTime(&freshnessTime));
    return freshnessTime;
}

template <typename D> bool impl_IMaintenanceTrigger<D>::OneShot() const
{
    bool oneShot {};
    check_hresult(WINRT_SHIM(IMaintenanceTrigger)->get_OneShot(&oneShot));
    return oneShot;
}

template <typename D> Windows::ApplicationModel::Background::MaintenanceTrigger impl_IMaintenanceTriggerFactory<D>::Create(uint32_t freshnessTime, bool oneShot) const
{
    Windows::ApplicationModel::Background::MaintenanceTrigger trigger { nullptr };
    check_hresult(WINRT_SHIM(IMaintenanceTriggerFactory)->abi_Create(freshnessTime, oneShot, put_abi(trigger)));
    return trigger;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::DeviceTriggerResult> impl_IDeviceUseTrigger<D>::RequestAsync(hstring_view deviceId) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::DeviceTriggerResult> result;
    check_hresult(WINRT_SHIM(IDeviceUseTrigger)->abi_RequestAsyncSimple(get_abi(deviceId), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::DeviceTriggerResult> impl_IDeviceUseTrigger<D>::RequestAsync(hstring_view deviceId, hstring_view arguments) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::DeviceTriggerResult> result;
    check_hresult(WINRT_SHIM(IDeviceUseTrigger)->abi_RequestAsyncWithArguments(get_abi(deviceId), get_abi(arguments), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::DeviceTriggerResult> impl_IDeviceServicingTrigger<D>::RequestAsync(hstring_view deviceId, const Windows::Foundation::TimeSpan & expectedDuration) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::DeviceTriggerResult> result;
    check_hresult(WINRT_SHIM(IDeviceServicingTrigger)->abi_RequestAsyncSimple(get_abi(deviceId), get_abi(expectedDuration), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::DeviceTriggerResult> impl_IDeviceServicingTrigger<D>::RequestAsync(hstring_view deviceId, const Windows::Foundation::TimeSpan & expectedDuration, hstring_view arguments) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::DeviceTriggerResult> result;
    check_hresult(WINRT_SHIM(IDeviceServicingTrigger)->abi_RequestAsyncWithArguments(get_abi(deviceId), get_abi(expectedDuration), get_abi(arguments), put_abi(result)));
    return result;
}

template <typename D> Windows::Devices::Bluetooth::Background::RfcommInboundConnectionInformation impl_IRfcommConnectionTrigger<D>::InboundConnection() const
{
    Windows::Devices::Bluetooth::Background::RfcommInboundConnectionInformation value { nullptr };
    check_hresult(WINRT_SHIM(IRfcommConnectionTrigger)->get_InboundConnection(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Bluetooth::Background::RfcommOutboundConnectionInformation impl_IRfcommConnectionTrigger<D>::OutboundConnection() const
{
    Windows::Devices::Bluetooth::Background::RfcommOutboundConnectionInformation value { nullptr };
    check_hresult(WINRT_SHIM(IRfcommConnectionTrigger)->get_OutboundConnection(put_abi(value)));
    return value;
}

template <typename D> bool impl_IRfcommConnectionTrigger<D>::AllowMultipleConnections() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IRfcommConnectionTrigger)->get_AllowMultipleConnections(&value));
    return value;
}

template <typename D> void impl_IRfcommConnectionTrigger<D>::AllowMultipleConnections(bool value) const
{
    check_hresult(WINRT_SHIM(IRfcommConnectionTrigger)->put_AllowMultipleConnections(value));
}

template <typename D> Windows::Networking::Sockets::SocketProtectionLevel impl_IRfcommConnectionTrigger<D>::ProtectionLevel() const
{
    Windows::Networking::Sockets::SocketProtectionLevel value {};
    check_hresult(WINRT_SHIM(IRfcommConnectionTrigger)->get_ProtectionLevel(&value));
    return value;
}

template <typename D> void impl_IRfcommConnectionTrigger<D>::ProtectionLevel(Windows::Networking::Sockets::SocketProtectionLevel value) const
{
    check_hresult(WINRT_SHIM(IRfcommConnectionTrigger)->put_ProtectionLevel(value));
}

template <typename D> Windows::Networking::HostName impl_IRfcommConnectionTrigger<D>::RemoteHostName() const
{
    Windows::Networking::HostName value { nullptr };
    check_hresult(WINRT_SHIM(IRfcommConnectionTrigger)->get_RemoteHostName(put_abi(value)));
    return value;
}

template <typename D> void impl_IRfcommConnectionTrigger<D>::RemoteHostName(const Windows::Networking::HostName & value) const
{
    check_hresult(WINRT_SHIM(IRfcommConnectionTrigger)->put_RemoteHostName(get_abi(value)));
}

template <typename D> hstring impl_IDeviceConnectionChangeTrigger<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDeviceConnectionChangeTrigger)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> bool impl_IDeviceConnectionChangeTrigger<D>::CanMaintainConnection() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDeviceConnectionChangeTrigger)->get_CanMaintainConnection(&value));
    return value;
}

template <typename D> bool impl_IDeviceConnectionChangeTrigger<D>::MaintainConnection() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDeviceConnectionChangeTrigger)->get_MaintainConnection(&value));
    return value;
}

template <typename D> void impl_IDeviceConnectionChangeTrigger<D>::MaintainConnection(bool value) const
{
    check_hresult(WINRT_SHIM(IDeviceConnectionChangeTrigger)->put_MaintainConnection(value));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Background::DeviceConnectionChangeTrigger> impl_IDeviceConnectionChangeTriggerStatics<D>::FromIdAsync(hstring_view deviceId) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Background::DeviceConnectionChangeTrigger> deviceChangeTrigger;
    check_hresult(WINRT_SHIM(IDeviceConnectionChangeTriggerStatics)->abi_FromIdAsync(get_abi(deviceId), put_abi(deviceChangeTrigger)));
    return deviceChangeTrigger;
}

template <typename D> Windows::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic impl_IGattCharacteristicNotificationTrigger<D>::Characteristic() const
{
    Windows::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic value { nullptr };
    check_hresult(WINRT_SHIM(IGattCharacteristicNotificationTrigger)->get_Characteristic(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Background::GattCharacteristicNotificationTrigger impl_IGattCharacteristicNotificationTriggerFactory<D>::Create(const Windows::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic & characteristic) const
{
    Windows::ApplicationModel::Background::GattCharacteristicNotificationTrigger gattCharacteristicNotificationTrigger { nullptr };
    check_hresult(WINRT_SHIM(IGattCharacteristicNotificationTriggerFactory)->abi_Create(get_abi(characteristic), put_abi(gattCharacteristicNotificationTrigger)));
    return gattCharacteristicNotificationTrigger;
}

template <typename D> Windows::Foundation::TimeSpan impl_IBluetoothLEAdvertisementWatcherTrigger<D>::MinSamplingInterval() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAdvertisementWatcherTrigger)->get_MinSamplingInterval(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IBluetoothLEAdvertisementWatcherTrigger<D>::MaxSamplingInterval() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAdvertisementWatcherTrigger)->get_MaxSamplingInterval(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IBluetoothLEAdvertisementWatcherTrigger<D>::MinOutOfRangeTimeout() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAdvertisementWatcherTrigger)->get_MinOutOfRangeTimeout(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IBluetoothLEAdvertisementWatcherTrigger<D>::MaxOutOfRangeTimeout() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAdvertisementWatcherTrigger)->get_MaxOutOfRangeTimeout(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Bluetooth::BluetoothSignalStrengthFilter impl_IBluetoothLEAdvertisementWatcherTrigger<D>::SignalStrengthFilter() const
{
    Windows::Devices::Bluetooth::BluetoothSignalStrengthFilter value { nullptr };
    check_hresult(WINRT_SHIM(IBluetoothLEAdvertisementWatcherTrigger)->get_SignalStrengthFilter(put_abi(value)));
    return value;
}

template <typename D> void impl_IBluetoothLEAdvertisementWatcherTrigger<D>::SignalStrengthFilter(const Windows::Devices::Bluetooth::BluetoothSignalStrengthFilter & value) const
{
    check_hresult(WINRT_SHIM(IBluetoothLEAdvertisementWatcherTrigger)->put_SignalStrengthFilter(get_abi(value)));
}

template <typename D> Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFilter impl_IBluetoothLEAdvertisementWatcherTrigger<D>::AdvertisementFilter() const
{
    Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFilter value { nullptr };
    check_hresult(WINRT_SHIM(IBluetoothLEAdvertisementWatcherTrigger)->get_AdvertisementFilter(put_abi(value)));
    return value;
}

template <typename D> void impl_IBluetoothLEAdvertisementWatcherTrigger<D>::AdvertisementFilter(const Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFilter & value) const
{
    check_hresult(WINRT_SHIM(IBluetoothLEAdvertisementWatcherTrigger)->put_AdvertisementFilter(get_abi(value)));
}

template <typename D> Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisement impl_IBluetoothLEAdvertisementPublisherTrigger<D>::Advertisement() const
{
    Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisement value { nullptr };
    check_hresult(WINRT_SHIM(IBluetoothLEAdvertisementPublisherTrigger)->get_Advertisement(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Background::LocationTriggerType impl_ILocationTrigger<D>::TriggerType() const
{
    Windows::ApplicationModel::Background::LocationTriggerType triggerType {};
    check_hresult(WINRT_SHIM(ILocationTrigger)->get_TriggerType(&triggerType));
    return triggerType;
}

template <typename D> Windows::ApplicationModel::Background::LocationTrigger impl_ILocationTriggerFactory<D>::Create(Windows::ApplicationModel::Background::LocationTriggerType triggerType) const
{
    Windows::ApplicationModel::Background::LocationTrigger locationTrigger { nullptr };
    check_hresult(WINRT_SHIM(ILocationTriggerFactory)->abi_Create(triggerType, put_abi(locationTrigger)));
    return locationTrigger;
}

template <typename D> Windows::Foundation::Collections::IVector<winrt::Windows::Devices::Sensors::ActivityType> impl_IActivitySensorTrigger<D>::SubscribedActivities() const
{
    Windows::Foundation::Collections::IVector<winrt::Windows::Devices::Sensors::ActivityType> value;
    check_hresult(WINRT_SHIM(IActivitySensorTrigger)->get_SubscribedActivities(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IActivitySensorTrigger<D>::ReportInterval() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IActivitySensorTrigger)->get_ReportInterval(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::Sensors::ActivityType> impl_IActivitySensorTrigger<D>::SupportedActivities() const
{
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::Sensors::ActivityType> value;
    check_hresult(WINRT_SHIM(IActivitySensorTrigger)->get_SupportedActivities(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IActivitySensorTrigger<D>::MinimumReportInterval() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IActivitySensorTrigger)->get_MinimumReportInterval(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Background::ActivitySensorTrigger impl_IActivitySensorTriggerFactory<D>::Create(uint32_t reportIntervalInMilliseconds) const
{
    Windows::ApplicationModel::Background::ActivitySensorTrigger activityTrigger { nullptr };
    check_hresult(WINRT_SHIM(IActivitySensorTriggerFactory)->abi_Create(reportIntervalInMilliseconds, put_abi(activityTrigger)));
    return activityTrigger;
}

template <typename D> Windows::ApplicationModel::Background::SensorDataThresholdTrigger impl_ISensorDataThresholdTriggerFactory<D>::Create(const Windows::Devices::Sensors::ISensorDataThreshold & threshold) const
{
    Windows::ApplicationModel::Background::SensorDataThresholdTrigger trigger { nullptr };
    check_hresult(WINRT_SHIM(ISensorDataThresholdTriggerFactory)->abi_Create(get_abi(threshold), put_abi(trigger)));
    return trigger;
}

template <typename D> bool impl_ISocketActivityTrigger<D>::IsWakeFromLowPowerSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISocketActivityTrigger)->get_IsWakeFromLowPowerSupported(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Background::PushNotificationTrigger impl_IPushNotificationTriggerFactory<D>::Create(hstring_view applicationId) const
{
    Windows::ApplicationModel::Background::PushNotificationTrigger trigger { nullptr };
    check_hresult(WINRT_SHIM(IPushNotificationTriggerFactory)->abi_Create(get_abi(applicationId), put_abi(trigger)));
    return trigger;
}

template <typename D> Windows::ApplicationModel::Background::ToastNotificationHistoryChangedTrigger impl_IToastNotificationHistoryChangedTriggerFactory<D>::Create(hstring_view applicationId) const
{
    Windows::ApplicationModel::Background::ToastNotificationHistoryChangedTrigger trigger { nullptr };
    check_hresult(WINRT_SHIM(IToastNotificationHistoryChangedTriggerFactory)->abi_Create(get_abi(applicationId), put_abi(trigger)));
    return trigger;
}

template <typename D> Windows::ApplicationModel::Background::ToastNotificationActionTrigger impl_IToastNotificationActionTriggerFactory<D>::Create(hstring_view applicationId) const
{
    Windows::ApplicationModel::Background::ToastNotificationActionTrigger trigger { nullptr };
    check_hresult(WINRT_SHIM(IToastNotificationActionTriggerFactory)->abi_Create(get_abi(applicationId), put_abi(trigger)));
    return trigger;
}

template <typename D> Windows::ApplicationModel::Background::UserNotificationChangedTrigger impl_IUserNotificationChangedTriggerFactory<D>::Create(Windows::UI::Notifications::NotificationKinds notificationKinds) const
{
    Windows::ApplicationModel::Background::UserNotificationChangedTrigger trigger { nullptr };
    check_hresult(WINRT_SHIM(IUserNotificationChangedTriggerFactory)->abi_Create(notificationKinds, put_abi(trigger)));
    return trigger;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::AlarmAccessStatus> impl_IAlarmApplicationManagerStatics<D>::RequestAccessAsync() const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::AlarmAccessStatus> operation;
    check_hresult(WINRT_SHIM(IAlarmApplicationManagerStatics)->abi_RequestAccessAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::ApplicationModel::Background::AlarmAccessStatus impl_IAlarmApplicationManagerStatics<D>::GetAccessStatus() const
{
    Windows::ApplicationModel::Background::AlarmAccessStatus status {};
    check_hresult(WINRT_SHIM(IAlarmApplicationManagerStatics)->abi_GetAccessStatus(&status));
    return status;
}

template <typename D> bool impl_IPhoneTrigger<D>::OneShot() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPhoneTrigger)->get_OneShot(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Calls::Background::PhoneTriggerType impl_IPhoneTrigger<D>::TriggerType() const
{
    Windows::ApplicationModel::Calls::Background::PhoneTriggerType result {};
    check_hresult(WINRT_SHIM(IPhoneTrigger)->get_TriggerType(&result));
    return result;
}

template <typename D> Windows::ApplicationModel::Background::PhoneTrigger impl_IPhoneTriggerFactory<D>::Create(Windows::ApplicationModel::Calls::Background::PhoneTriggerType type, bool oneShot) const
{
    Windows::ApplicationModel::Background::PhoneTrigger result { nullptr };
    check_hresult(WINRT_SHIM(IPhoneTriggerFactory)->abi_Create(type, oneShot, put_abi(result)));
    return result;
}

template <typename D> Windows::Devices::SmartCards::SmartCardTriggerType impl_ISmartCardTrigger<D>::TriggerType() const
{
    Windows::Devices::SmartCards::SmartCardTriggerType triggerType {};
    check_hresult(WINRT_SHIM(ISmartCardTrigger)->get_TriggerType(&triggerType));
    return triggerType;
}

template <typename D> Windows::ApplicationModel::Background::SmartCardTrigger impl_ISmartCardTriggerFactory<D>::Create(Windows::Devices::SmartCards::SmartCardTriggerType triggerType) const
{
    Windows::ApplicationModel::Background::SmartCardTrigger trigger { nullptr };
    check_hresult(WINRT_SHIM(ISmartCardTriggerFactory)->abi_Create(triggerType, put_abi(trigger)));
    return trigger;
}

inline ActivitySensorTrigger::ActivitySensorTrigger(uint32_t reportIntervalInMilliseconds) :
    ActivitySensorTrigger(get_activation_factory<ActivitySensorTrigger, IActivitySensorTriggerFactory>().Create(reportIntervalInMilliseconds))
{}

inline Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::AlarmAccessStatus> AlarmApplicationManager::RequestAccessAsync()
{
    return get_activation_factory<AlarmApplicationManager, IAlarmApplicationManagerStatics>().RequestAccessAsync();
}

inline Windows::ApplicationModel::Background::AlarmAccessStatus AlarmApplicationManager::GetAccessStatus()
{
    return get_activation_factory<AlarmApplicationManager, IAlarmApplicationManagerStatics>().GetAccessStatus();
}

inline ApplicationTrigger::ApplicationTrigger() :
    ApplicationTrigger(activate_instance<ApplicationTrigger>())
{}

inline AppointmentStoreNotificationTrigger::AppointmentStoreNotificationTrigger() :
    AppointmentStoreNotificationTrigger(activate_instance<AppointmentStoreNotificationTrigger>())
{}

inline Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::BackgroundAccessStatus> BackgroundExecutionManager::RequestAccessAsync()
{
    return get_activation_factory<BackgroundExecutionManager, IBackgroundExecutionManagerStatics>().RequestAccessAsync();
}

inline Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::BackgroundAccessStatus> BackgroundExecutionManager::RequestAccessAsync(hstring_view applicationId)
{
    return get_activation_factory<BackgroundExecutionManager, IBackgroundExecutionManagerStatics>().RequestAccessAsync(applicationId);
}

inline void BackgroundExecutionManager::RemoveAccess()
{
    get_activation_factory<BackgroundExecutionManager, IBackgroundExecutionManagerStatics>().RemoveAccess();
}

inline void BackgroundExecutionManager::RemoveAccess(hstring_view applicationId)
{
    get_activation_factory<BackgroundExecutionManager, IBackgroundExecutionManagerStatics>().RemoveAccess(applicationId);
}

inline Windows::ApplicationModel::Background::BackgroundAccessStatus BackgroundExecutionManager::GetAccessStatus()
{
    return get_activation_factory<BackgroundExecutionManager, IBackgroundExecutionManagerStatics>().GetAccessStatus();
}

inline Windows::ApplicationModel::Background::BackgroundAccessStatus BackgroundExecutionManager::GetAccessStatus(hstring_view applicationId)
{
    return get_activation_factory<BackgroundExecutionManager, IBackgroundExecutionManagerStatics>().GetAccessStatus(applicationId);
}

inline BackgroundTaskBuilder::BackgroundTaskBuilder() :
    BackgroundTaskBuilder(activate_instance<BackgroundTaskBuilder>())
{}

inline Windows::Foundation::Collections::IMapView<GUID, Windows::ApplicationModel::Background::IBackgroundTaskRegistration> BackgroundTaskRegistration::AllTasks()
{
    return get_activation_factory<BackgroundTaskRegistration, IBackgroundTaskRegistrationStatics>().AllTasks();
}

inline Windows::ApplicationModel::Background::BackgroundWorkCostValue BackgroundWorkCost::CurrentBackgroundWorkCost()
{
    return get_activation_factory<BackgroundWorkCost, IBackgroundWorkCostStatics>().CurrentBackgroundWorkCost();
}

inline BluetoothLEAdvertisementPublisherTrigger::BluetoothLEAdvertisementPublisherTrigger() :
    BluetoothLEAdvertisementPublisherTrigger(activate_instance<BluetoothLEAdvertisementPublisherTrigger>())
{}

inline BluetoothLEAdvertisementWatcherTrigger::BluetoothLEAdvertisementWatcherTrigger() :
    BluetoothLEAdvertisementWatcherTrigger(activate_instance<BluetoothLEAdvertisementWatcherTrigger>())
{}

inline CachedFileUpdaterTrigger::CachedFileUpdaterTrigger() :
    CachedFileUpdaterTrigger(activate_instance<CachedFileUpdaterTrigger>())
{}

inline ChatMessageNotificationTrigger::ChatMessageNotificationTrigger() :
    ChatMessageNotificationTrigger(activate_instance<ChatMessageNotificationTrigger>())
{}

inline ChatMessageReceivedNotificationTrigger::ChatMessageReceivedNotificationTrigger() :
    ChatMessageReceivedNotificationTrigger(activate_instance<ChatMessageReceivedNotificationTrigger>())
{}

inline CommunicationBlockingAppSetAsActiveTrigger::CommunicationBlockingAppSetAsActiveTrigger() :
    CommunicationBlockingAppSetAsActiveTrigger(activate_instance<CommunicationBlockingAppSetAsActiveTrigger>())
{}

inline ContactStoreNotificationTrigger::ContactStoreNotificationTrigger() :
    ContactStoreNotificationTrigger(activate_instance<ContactStoreNotificationTrigger>())
{}

inline ContentPrefetchTrigger::ContentPrefetchTrigger() :
    ContentPrefetchTrigger(activate_instance<ContentPrefetchTrigger>())
{}

inline ContentPrefetchTrigger::ContentPrefetchTrigger(const Windows::Foundation::TimeSpan & waitInterval) :
    ContentPrefetchTrigger(get_activation_factory<ContentPrefetchTrigger, IContentPrefetchTriggerFactory>().Create(waitInterval))
{}

inline Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Background::DeviceConnectionChangeTrigger> DeviceConnectionChangeTrigger::FromIdAsync(hstring_view deviceId)
{
    return get_activation_factory<DeviceConnectionChangeTrigger, IDeviceConnectionChangeTriggerStatics>().FromIdAsync(deviceId);
}

inline DeviceManufacturerNotificationTrigger::DeviceManufacturerNotificationTrigger(hstring_view triggerQualifier, bool oneShot) :
    DeviceManufacturerNotificationTrigger(get_activation_factory<DeviceManufacturerNotificationTrigger, IDeviceManufacturerNotificationTriggerFactory>().Create(triggerQualifier, oneShot))
{}

inline DeviceServicingTrigger::DeviceServicingTrigger() :
    DeviceServicingTrigger(activate_instance<DeviceServicingTrigger>())
{}

inline DeviceUseTrigger::DeviceUseTrigger() :
    DeviceUseTrigger(activate_instance<DeviceUseTrigger>())
{}

inline EmailStoreNotificationTrigger::EmailStoreNotificationTrigger() :
    EmailStoreNotificationTrigger(activate_instance<EmailStoreNotificationTrigger>())
{}

inline GattCharacteristicNotificationTrigger::GattCharacteristicNotificationTrigger(const Windows::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic & characteristic) :
    GattCharacteristicNotificationTrigger(get_activation_factory<GattCharacteristicNotificationTrigger, IGattCharacteristicNotificationTriggerFactory>().Create(characteristic))
{}

inline LocationTrigger::LocationTrigger(Windows::ApplicationModel::Background::LocationTriggerType triggerType) :
    LocationTrigger(get_activation_factory<LocationTrigger, ILocationTriggerFactory>().Create(triggerType))
{}

inline MaintenanceTrigger::MaintenanceTrigger(uint32_t freshnessTime, bool oneShot) :
    MaintenanceTrigger(get_activation_factory<MaintenanceTrigger, IMaintenanceTriggerFactory>().Create(freshnessTime, oneShot))
{}

inline MediaProcessingTrigger::MediaProcessingTrigger() :
    MediaProcessingTrigger(activate_instance<MediaProcessingTrigger>())
{}

inline MobileBroadbandDeviceServiceNotificationTrigger::MobileBroadbandDeviceServiceNotificationTrigger() :
    MobileBroadbandDeviceServiceNotificationTrigger(activate_instance<MobileBroadbandDeviceServiceNotificationTrigger>())
{}

inline MobileBroadbandPinLockStateChangeTrigger::MobileBroadbandPinLockStateChangeTrigger() :
    MobileBroadbandPinLockStateChangeTrigger(activate_instance<MobileBroadbandPinLockStateChangeTrigger>())
{}

inline MobileBroadbandRadioStateChangeTrigger::MobileBroadbandRadioStateChangeTrigger() :
    MobileBroadbandRadioStateChangeTrigger(activate_instance<MobileBroadbandRadioStateChangeTrigger>())
{}

inline MobileBroadbandRegistrationStateChangeTrigger::MobileBroadbandRegistrationStateChangeTrigger() :
    MobileBroadbandRegistrationStateChangeTrigger(activate_instance<MobileBroadbandRegistrationStateChangeTrigger>())
{}

inline NetworkOperatorHotspotAuthenticationTrigger::NetworkOperatorHotspotAuthenticationTrigger() :
    NetworkOperatorHotspotAuthenticationTrigger(activate_instance<NetworkOperatorHotspotAuthenticationTrigger>())
{}

inline NetworkOperatorNotificationTrigger::NetworkOperatorNotificationTrigger(hstring_view networkAccountId) :
    NetworkOperatorNotificationTrigger(get_activation_factory<NetworkOperatorNotificationTrigger, INetworkOperatorNotificationTriggerFactory>().Create(networkAccountId))
{}

inline PhoneTrigger::PhoneTrigger(Windows::ApplicationModel::Calls::Background::PhoneTriggerType type, bool oneShot) :
    PhoneTrigger(get_activation_factory<PhoneTrigger, IPhoneTriggerFactory>().Create(type, oneShot))
{}

inline PushNotificationTrigger::PushNotificationTrigger() :
    PushNotificationTrigger(activate_instance<PushNotificationTrigger>())
{}

inline PushNotificationTrigger::PushNotificationTrigger(hstring_view applicationId) :
    PushNotificationTrigger(get_activation_factory<PushNotificationTrigger, IPushNotificationTriggerFactory>().Create(applicationId))
{}

inline RcsEndUserMessageAvailableTrigger::RcsEndUserMessageAvailableTrigger() :
    RcsEndUserMessageAvailableTrigger(activate_instance<RcsEndUserMessageAvailableTrigger>())
{}

inline RfcommConnectionTrigger::RfcommConnectionTrigger() :
    RfcommConnectionTrigger(activate_instance<RfcommConnectionTrigger>())
{}

inline SecondaryAuthenticationFactorAuthenticationTrigger::SecondaryAuthenticationFactorAuthenticationTrigger() :
    SecondaryAuthenticationFactorAuthenticationTrigger(activate_instance<SecondaryAuthenticationFactorAuthenticationTrigger>())
{}

inline SensorDataThresholdTrigger::SensorDataThresholdTrigger(const Windows::Devices::Sensors::ISensorDataThreshold & threshold) :
    SensorDataThresholdTrigger(get_activation_factory<SensorDataThresholdTrigger, ISensorDataThresholdTriggerFactory>().Create(threshold))
{}

inline SmartCardTrigger::SmartCardTrigger(Windows::Devices::SmartCards::SmartCardTriggerType triggerType) :
    SmartCardTrigger(get_activation_factory<SmartCardTrigger, ISmartCardTriggerFactory>().Create(triggerType))
{}

inline SmsMessageReceivedTrigger::SmsMessageReceivedTrigger(const Windows::Devices::Sms::SmsFilterRules & filterRules) :
    SmsMessageReceivedTrigger(get_activation_factory<SmsMessageReceivedTrigger, ISmsMessageReceivedTriggerFactory>().Create(filterRules))
{}

inline SocketActivityTrigger::SocketActivityTrigger() :
    SocketActivityTrigger(activate_instance<SocketActivityTrigger>())
{}

inline Windows::ApplicationModel::Background::StorageLibraryContentChangedTrigger StorageLibraryContentChangedTrigger::Create(const Windows::Storage::StorageLibrary & storageLibrary)
{
    return get_activation_factory<StorageLibraryContentChangedTrigger, IStorageLibraryContentChangedTriggerStatics>().Create(storageLibrary);
}

inline Windows::ApplicationModel::Background::StorageLibraryContentChangedTrigger StorageLibraryContentChangedTrigger::CreateFromLibraries(iterable<Windows::Storage::StorageLibrary> storageLibraries)
{
    return get_activation_factory<StorageLibraryContentChangedTrigger, IStorageLibraryContentChangedTriggerStatics>().CreateFromLibraries(storageLibraries);
}

inline SystemCondition::SystemCondition(Windows::ApplicationModel::Background::SystemConditionType conditionType) :
    SystemCondition(get_activation_factory<SystemCondition, ISystemConditionFactory>().Create(conditionType))
{}

inline SystemTrigger::SystemTrigger(Windows::ApplicationModel::Background::SystemTriggerType triggerType, bool oneShot) :
    SystemTrigger(get_activation_factory<SystemTrigger, ISystemTriggerFactory>().Create(triggerType, oneShot))
{}

inline TimeTrigger::TimeTrigger(uint32_t freshnessTime, bool oneShot) :
    TimeTrigger(get_activation_factory<TimeTrigger, ITimeTriggerFactory>().Create(freshnessTime, oneShot))
{}

inline ToastNotificationActionTrigger::ToastNotificationActionTrigger() :
    ToastNotificationActionTrigger(activate_instance<ToastNotificationActionTrigger>())
{}

inline ToastNotificationActionTrigger::ToastNotificationActionTrigger(hstring_view applicationId) :
    ToastNotificationActionTrigger(get_activation_factory<ToastNotificationActionTrigger, IToastNotificationActionTriggerFactory>().Create(applicationId))
{}

inline ToastNotificationHistoryChangedTrigger::ToastNotificationHistoryChangedTrigger() :
    ToastNotificationHistoryChangedTrigger(activate_instance<ToastNotificationHistoryChangedTrigger>())
{}

inline ToastNotificationHistoryChangedTrigger::ToastNotificationHistoryChangedTrigger(hstring_view applicationId) :
    ToastNotificationHistoryChangedTrigger(get_activation_factory<ToastNotificationHistoryChangedTrigger, IToastNotificationHistoryChangedTriggerFactory>().Create(applicationId))
{}

inline UserNotificationChangedTrigger::UserNotificationChangedTrigger(Windows::UI::Notifications::NotificationKinds notificationKinds) :
    UserNotificationChangedTrigger(get_activation_factory<UserNotificationChangedTrigger, IUserNotificationChangedTriggerFactory>().Create(notificationKinds))
{}

}

}
#pragma warning(pop)
