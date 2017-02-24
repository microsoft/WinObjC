// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Devices.Sms.3.h"
#include "Windows.Devices.h"
#include "Windows.Foundation.Collections.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::Sms {

template <typename L> SmsDeviceStatusChangedEventHandler::SmsDeviceStatusChangedEventHandler(L lambda) :
    SmsDeviceStatusChangedEventHandler(impl::make_delegate<impl_SmsDeviceStatusChangedEventHandler<L>, SmsDeviceStatusChangedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> SmsDeviceStatusChangedEventHandler::SmsDeviceStatusChangedEventHandler(F * function) :
    SmsDeviceStatusChangedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> SmsDeviceStatusChangedEventHandler::SmsDeviceStatusChangedEventHandler(O * object, M method) :
    SmsDeviceStatusChangedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void SmsDeviceStatusChangedEventHandler::operator()(const Windows::Devices::Sms::SmsDevice & sender) const
{
    check_hresult((*(abi<SmsDeviceStatusChangedEventHandler> **)this)->abi_Invoke(get_abi(sender)));
}

template <typename L> SmsMessageReceivedEventHandler::SmsMessageReceivedEventHandler(L lambda) :
    SmsMessageReceivedEventHandler(impl::make_delegate<impl_SmsMessageReceivedEventHandler<L>, SmsMessageReceivedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> SmsMessageReceivedEventHandler::SmsMessageReceivedEventHandler(F * function) :
    SmsMessageReceivedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> SmsMessageReceivedEventHandler::SmsMessageReceivedEventHandler(O * object, M method) :
    SmsMessageReceivedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void SmsMessageReceivedEventHandler::operator()(const Windows::Devices::Sms::SmsDevice & sender, const Windows::Devices::Sms::SmsMessageReceivedEventArgs & e) const
{
    check_hresult((*(abi<SmsMessageReceivedEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

}

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::Sms::ISmsAppMessage> : produce_base<D, Windows::Devices::Sms::ISmsAppMessage>
{
    HRESULT __stdcall get_Timestamp(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Timestamp());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_To(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().To());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_To(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().To(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_From(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().From());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Body(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Body());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Body(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Body(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CallbackNumber(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CallbackNumber());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CallbackNumber(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CallbackNumber(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsDeliveryNotificationEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDeliveryNotificationEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsDeliveryNotificationEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsDeliveryNotificationEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RetryAttemptCount(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RetryAttemptCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RetryAttemptCount(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RetryAttemptCount(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Encoding(Windows::Devices::Sms::SmsEncoding * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Encoding());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Encoding(Windows::Devices::Sms::SmsEncoding value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Encoding(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PortNumber(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PortNumber());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PortNumber(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PortNumber(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TeleserviceId(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TeleserviceId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TeleserviceId(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TeleserviceId(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProtocolId(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProtocolId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ProtocolId(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProtocolId(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BinaryBody(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BinaryBody());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BinaryBody(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BinaryBody(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sms::ISmsBinaryMessage> : produce_base<D, Windows::Devices::Sms::ISmsBinaryMessage>
{
    HRESULT __stdcall get_Format(Windows::Devices::Sms::SmsDataFormat * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Format());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Format(Windows::Devices::Sms::SmsDataFormat value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Format(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetData(uint32_t * __valueSize, impl::abi_arg_out<uint8_t> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            std::tie(*__valueSize, *value) = detach_abi(this->shim().GetData());
            return S_OK;
        }
        catch (...)
        {
            *__valueSize = 0;
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetData(uint32_t __valueSize, impl::abi_arg_in<uint8_t> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetData(array_view<const uint8_t>(value, value + __valueSize));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sms::ISmsBroadcastMessage> : produce_base<D, Windows::Devices::Sms::ISmsBroadcastMessage>
{
    HRESULT __stdcall get_Timestamp(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Timestamp());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_To(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().To());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Body(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Body());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Channel(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Channel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GeographicalScope(Windows::Devices::Sms::SmsGeographicalScope * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GeographicalScope());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MessageCode(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MessageCode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UpdateNumber(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UpdateNumber());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BroadcastType(Windows::Devices::Sms::SmsBroadcastType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BroadcastType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsEmergencyAlert(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsEmergencyAlert());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsUserPopupRequested(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsUserPopupRequested());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sms::ISmsDevice> : produce_base<D, Windows::Devices::Sms::ISmsDevice>
{
    HRESULT __stdcall abi_SendMessageAsync(impl::abi_arg_in<Windows::Devices::Sms::ISmsMessage> message, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().SendMessageAsync(*reinterpret_cast<const Windows::Devices::Sms::ISmsMessage *>(&message)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CalculateLength(impl::abi_arg_in<Windows::Devices::Sms::ISmsTextMessage> message, impl::abi_arg_out<Windows::Devices::Sms::SmsEncodedLength> encodedLength) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *encodedLength = detach_abi(this->shim().CalculateLength(*reinterpret_cast<const Windows::Devices::Sms::SmsTextMessage *>(&message)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AccountPhoneNumber(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AccountPhoneNumber());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CellularClass(Windows::Devices::Sms::CellularClass * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CellularClass());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MessageStore(impl::abi_arg_out<Windows::Devices::Sms::ISmsDeviceMessageStore> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MessageStore());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeviceStatus(Windows::Devices::Sms::SmsDeviceStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_SmsMessageReceived(impl::abi_arg_in<Windows::Devices::Sms::SmsMessageReceivedEventHandler> eventHandler, event_token * eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_abi(this->shim().SmsMessageReceived(*reinterpret_cast<const Windows::Devices::Sms::SmsMessageReceivedEventHandler *>(&eventHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SmsMessageReceived(event_token eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SmsMessageReceived(eventCookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_SmsDeviceStatusChanged(impl::abi_arg_in<Windows::Devices::Sms::SmsDeviceStatusChangedEventHandler> eventHandler, event_token * eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_abi(this->shim().SmsDeviceStatusChanged(*reinterpret_cast<const Windows::Devices::Sms::SmsDeviceStatusChangedEventHandler *>(&eventHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SmsDeviceStatusChanged(event_token eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SmsDeviceStatusChanged(eventCookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sms::ISmsDevice2> : produce_base<D, Windows::Devices::Sms::ISmsDevice2>
{
    HRESULT __stdcall get_SmscAddress(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SmscAddress());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SmscAddress(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SmscAddress(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall get_ParentDeviceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ParentDeviceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AccountPhoneNumber(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AccountPhoneNumber());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CellularClass(Windows::Devices::Sms::CellularClass * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CellularClass());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeviceStatus(Windows::Devices::Sms::SmsDeviceStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CalculateLength(impl::abi_arg_in<Windows::Devices::Sms::ISmsMessageBase> message, impl::abi_arg_out<Windows::Devices::Sms::SmsEncodedLength> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CalculateLength(*reinterpret_cast<const Windows::Devices::Sms::ISmsMessageBase *>(&message)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SendMessageAndGetResultAsync(impl::abi_arg_in<Windows::Devices::Sms::ISmsMessageBase> message, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Sms::SmsSendMessageResult>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().SendMessageAndGetResultAsync(*reinterpret_cast<const Windows::Devices::Sms::ISmsMessageBase *>(&message)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_DeviceStatusChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Sms::SmsDevice2, Windows::Foundation::IInspectable>> eventHandler, event_token * eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_abi(this->shim().DeviceStatusChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Sms::SmsDevice2, Windows::Foundation::IInspectable> *>(&eventHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_DeviceStatusChanged(event_token eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DeviceStatusChanged(eventCookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sms::ISmsDevice2Statics> : produce_base<D, Windows::Devices::Sms::ISmsDevice2Statics>
{
    HRESULT __stdcall abi_GetDeviceSelector(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDeviceSelector());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromId(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_out<Windows::Devices::Sms::ISmsDevice2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FromId(*reinterpret_cast<const hstring *>(&deviceId)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDefault(impl::abi_arg_out<Windows::Devices::Sms::ISmsDevice2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDefault());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromParentId(impl::abi_arg_in<hstring> parentDeviceId, impl::abi_arg_out<Windows::Devices::Sms::ISmsDevice2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FromParentId(*reinterpret_cast<const hstring *>(&parentDeviceId)));
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
struct produce<D, Windows::Devices::Sms::ISmsDeviceMessageStore> : produce_base<D, Windows::Devices::Sms::ISmsDeviceMessageStore>
{
    HRESULT __stdcall abi_DeleteMessageAsync(uint32_t messageId, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().DeleteMessageAsync(messageId));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteMessagesAsync(Windows::Devices::Sms::SmsMessageFilter messageFilter, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().DeleteMessagesAsync(messageFilter));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetMessageAsync(uint32_t messageId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Sms::ISmsMessage>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().GetMessageAsync(messageId));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetMessagesAsync(Windows::Devices::Sms::SmsMessageFilter messageFilter, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sms::ISmsMessage>, int32_t>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().GetMessagesAsync(messageFilter));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxMessages(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxMessages());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sms::ISmsDeviceStatics> : produce_base<D, Windows::Devices::Sms::ISmsDeviceStatics>
{
    HRESULT __stdcall abi_GetDeviceSelector(impl::abi_arg_out<hstring> phstrDeviceClassSelector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *phstrDeviceClassSelector = detach_abi(this->shim().GetDeviceSelector());
            return S_OK;
        }
        catch (...)
        {
            *phstrDeviceClassSelector = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromIdAsync(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Sms::SmsDevice>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().FromIdAsync(*reinterpret_cast<const hstring *>(&deviceId)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDefaultAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Sms::SmsDevice>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().GetDefaultAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sms::ISmsDeviceStatics2> : produce_base<D, Windows::Devices::Sms::ISmsDeviceStatics2>
{
    HRESULT __stdcall abi_FromNetworkAccountIdAsync(impl::abi_arg_in<hstring> networkAccountId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Sms::SmsDevice>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().FromNetworkAccountIdAsync(*reinterpret_cast<const hstring *>(&networkAccountId)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sms::ISmsFilterRule> : produce_base<D, Windows::Devices::Sms::ISmsFilterRule>
{
    HRESULT __stdcall get_MessageType(Windows::Devices::Sms::SmsMessageType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MessageType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ImsiPrefixes(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ImsiPrefixes());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeviceIds(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceIds());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SenderNumbers(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SenderNumbers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TextMessagePrefixes(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TextMessagePrefixes());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PortNumbers(impl::abi_arg_out<Windows::Foundation::Collections::IVector<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PortNumbers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CellularClass(Windows::Devices::Sms::CellularClass * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CellularClass());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CellularClass(Windows::Devices::Sms::CellularClass value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CellularClass(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProtocolIds(impl::abi_arg_out<Windows::Foundation::Collections::IVector<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProtocolIds());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TeleserviceIds(impl::abi_arg_out<Windows::Foundation::Collections::IVector<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TeleserviceIds());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WapApplicationIds(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WapApplicationIds());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WapContentTypes(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WapContentTypes());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BroadcastTypes(impl::abi_arg_out<Windows::Foundation::Collections::IVector<winrt::Windows::Devices::Sms::SmsBroadcastType>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BroadcastTypes());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BroadcastChannels(impl::abi_arg_out<Windows::Foundation::Collections::IVector<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BroadcastChannels());
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
struct produce<D, Windows::Devices::Sms::ISmsFilterRuleFactory> : produce_base<D, Windows::Devices::Sms::ISmsFilterRuleFactory>
{
    HRESULT __stdcall abi_CreateFilterRule(Windows::Devices::Sms::SmsMessageType messageType, impl::abi_arg_out<Windows::Devices::Sms::ISmsFilterRule> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateFilterRule(messageType));
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
struct produce<D, Windows::Devices::Sms::ISmsFilterRules> : produce_base<D, Windows::Devices::Sms::ISmsFilterRules>
{
    HRESULT __stdcall get_ActionType(Windows::Devices::Sms::SmsFilterActionType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ActionType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Rules(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Devices::Sms::SmsFilterRule>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Rules());
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
struct produce<D, Windows::Devices::Sms::ISmsFilterRulesFactory> : produce_base<D, Windows::Devices::Sms::ISmsFilterRulesFactory>
{
    HRESULT __stdcall abi_CreateFilterRules(Windows::Devices::Sms::SmsFilterActionType actionType, impl::abi_arg_out<Windows::Devices::Sms::ISmsFilterRules> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateFilterRules(actionType));
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
struct produce<D, Windows::Devices::Sms::ISmsMessage> : produce_base<D, Windows::Devices::Sms::ISmsMessage>
{
    HRESULT __stdcall get_Id(uint32_t * value) noexcept override
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

    HRESULT __stdcall get_MessageClass(Windows::Devices::Sms::SmsMessageClass * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MessageClass());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sms::ISmsMessageBase> : produce_base<D, Windows::Devices::Sms::ISmsMessageBase>
{
    HRESULT __stdcall get_MessageType(Windows::Devices::Sms::SmsMessageType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MessageType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall get_CellularClass(Windows::Devices::Sms::CellularClass * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CellularClass());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MessageClass(Windows::Devices::Sms::SmsMessageClass * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MessageClass());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SimIccId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SimIccId());
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
struct produce<D, Windows::Devices::Sms::ISmsMessageReceivedEventArgs> : produce_base<D, Windows::Devices::Sms::ISmsMessageReceivedEventArgs>
{
    HRESULT __stdcall get_TextMessage(impl::abi_arg_out<Windows::Devices::Sms::ISmsTextMessage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TextMessage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BinaryMessage(impl::abi_arg_out<Windows::Devices::Sms::ISmsBinaryMessage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BinaryMessage());
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
struct produce<D, Windows::Devices::Sms::ISmsMessageReceivedTriggerDetails> : produce_base<D, Windows::Devices::Sms::ISmsMessageReceivedTriggerDetails>
{
    HRESULT __stdcall get_MessageType(Windows::Devices::Sms::SmsMessageType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MessageType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TextMessage(impl::abi_arg_out<Windows::Devices::Sms::ISmsTextMessage2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TextMessage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WapMessage(impl::abi_arg_out<Windows::Devices::Sms::ISmsWapMessage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WapMessage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AppMessage(impl::abi_arg_out<Windows::Devices::Sms::ISmsAppMessage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AppMessage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BroadcastMessage(impl::abi_arg_out<Windows::Devices::Sms::ISmsBroadcastMessage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BroadcastMessage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VoicemailMessage(impl::abi_arg_out<Windows::Devices::Sms::ISmsVoicemailMessage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VoicemailMessage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StatusMessage(impl::abi_arg_out<Windows::Devices::Sms::ISmsStatusMessage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StatusMessage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Drop() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Drop();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Accept() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Accept();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sms::ISmsMessageRegistration> : produce_base<D, Windows::Devices::Sms::ISmsMessageRegistration>
{
    HRESULT __stdcall get_Id(impl::abi_arg_out<hstring> value) noexcept override
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

    HRESULT __stdcall abi_Unregister() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Unregister();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_MessageReceived(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Sms::SmsMessageRegistration, Windows::Devices::Sms::SmsMessageReceivedTriggerDetails>> eventHandler, event_token * eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_abi(this->shim().MessageReceived(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Sms::SmsMessageRegistration, Windows::Devices::Sms::SmsMessageReceivedTriggerDetails> *>(&eventHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_MessageReceived(event_token eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MessageReceived(eventCookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sms::ISmsMessageRegistrationStatics> : produce_base<D, Windows::Devices::Sms::ISmsMessageRegistrationStatics>
{
    HRESULT __stdcall get_AllRegistrations(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sms::SmsMessageRegistration>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllRegistrations());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Register(impl::abi_arg_in<hstring> id, impl::abi_arg_in<Windows::Devices::Sms::ISmsFilterRules> filterRules, impl::abi_arg_out<Windows::Devices::Sms::ISmsMessageRegistration> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Register(*reinterpret_cast<const hstring *>(&id), *reinterpret_cast<const Windows::Devices::Sms::SmsFilterRules *>(&filterRules)));
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
struct produce<D, Windows::Devices::Sms::ISmsReceivedEventDetails> : produce_base<D, Windows::Devices::Sms::ISmsReceivedEventDetails>
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

    HRESULT __stdcall get_MessageIndex(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MessageIndex());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sms::ISmsReceivedEventDetails2> : produce_base<D, Windows::Devices::Sms::ISmsReceivedEventDetails2>
{
    HRESULT __stdcall get_MessageClass(Windows::Devices::Sms::SmsMessageClass * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MessageClass());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BinaryMessage(impl::abi_arg_out<Windows::Devices::Sms::ISmsBinaryMessage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BinaryMessage());
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
struct produce<D, Windows::Devices::Sms::ISmsSendMessageResult> : produce_base<D, Windows::Devices::Sms::ISmsSendMessageResult>
{
    HRESULT __stdcall get_IsSuccessful(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsSuccessful());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MessageReferenceNumbers(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MessageReferenceNumbers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CellularClass(Windows::Devices::Sms::CellularClass * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CellularClass());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ModemErrorCode(Windows::Devices::Sms::SmsModemErrorCode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ModemErrorCode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsErrorTransient(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsErrorTransient());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NetworkCauseCode(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NetworkCauseCode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TransportFailureCause(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TransportFailureCause());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sms::ISmsStatusMessage> : produce_base<D, Windows::Devices::Sms::ISmsStatusMessage>
{
    HRESULT __stdcall get_To(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().To());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_From(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().From());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Body(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Body());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Status(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MessageReferenceNumber(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MessageReferenceNumber());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServiceCenterTimestamp(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServiceCenterTimestamp());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DischargeTime(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DischargeTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sms::ISmsTextMessage> : produce_base<D, Windows::Devices::Sms::ISmsTextMessage>
{
    HRESULT __stdcall get_Timestamp(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Timestamp());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PartReferenceId(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PartReferenceId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PartNumber(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PartNumber());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PartCount(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PartCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_To(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().To());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_To(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().To(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_From(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().From());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_From(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().From(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Body(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Body());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Body(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Body(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Encoding(Windows::Devices::Sms::SmsEncoding * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Encoding());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Encoding(Windows::Devices::Sms::SmsEncoding value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Encoding(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ToBinaryMessages(Windows::Devices::Sms::SmsDataFormat format, impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sms::ISmsBinaryMessage>> messages) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *messages = detach_abi(this->shim().ToBinaryMessages(format));
            return S_OK;
        }
        catch (...)
        {
            *messages = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sms::ISmsTextMessage2> : produce_base<D, Windows::Devices::Sms::ISmsTextMessage2>
{
    HRESULT __stdcall get_Timestamp(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Timestamp());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_To(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().To());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_To(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().To(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_From(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().From());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Body(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Body());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Body(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Body(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Encoding(Windows::Devices::Sms::SmsEncoding * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Encoding());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Encoding(Windows::Devices::Sms::SmsEncoding value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Encoding(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CallbackNumber(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CallbackNumber());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CallbackNumber(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CallbackNumber(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsDeliveryNotificationEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDeliveryNotificationEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsDeliveryNotificationEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsDeliveryNotificationEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RetryAttemptCount(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RetryAttemptCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RetryAttemptCount(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RetryAttemptCount(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TeleserviceId(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TeleserviceId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProtocolId(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProtocolId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sms::ISmsTextMessageStatics> : produce_base<D, Windows::Devices::Sms::ISmsTextMessageStatics>
{
    HRESULT __stdcall abi_FromBinaryMessage(impl::abi_arg_in<Windows::Devices::Sms::ISmsBinaryMessage> binaryMessage, impl::abi_arg_out<Windows::Devices::Sms::ISmsTextMessage> textMessage) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *textMessage = detach_abi(this->shim().FromBinaryMessage(*reinterpret_cast<const Windows::Devices::Sms::SmsBinaryMessage *>(&binaryMessage)));
            return S_OK;
        }
        catch (...)
        {
            *textMessage = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromBinaryData(Windows::Devices::Sms::SmsDataFormat format, uint32_t __valueSize, impl::abi_arg_in<uint8_t> * value, impl::abi_arg_out<Windows::Devices::Sms::ISmsTextMessage> textMessage) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *textMessage = detach_abi(this->shim().FromBinaryData(format, array_view<const uint8_t>(value, value + __valueSize)));
            return S_OK;
        }
        catch (...)
        {
            *textMessage = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sms::ISmsVoicemailMessage> : produce_base<D, Windows::Devices::Sms::ISmsVoicemailMessage>
{
    HRESULT __stdcall get_Timestamp(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Timestamp());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_To(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().To());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Body(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Body());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MessageCount(impl::abi_arg_out<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MessageCount());
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
struct produce<D, Windows::Devices::Sms::ISmsWapMessage> : produce_base<D, Windows::Devices::Sms::ISmsWapMessage>
{
    HRESULT __stdcall get_Timestamp(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Timestamp());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_To(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().To());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_From(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().From());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ApplicationId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ApplicationId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContentType(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentType());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BinaryBody(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BinaryBody());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Headers(impl::abi_arg_out<Windows::Foundation::Collections::IMap<hstring, hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Headers());
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

namespace Windows::Devices::Sms {

template <typename D> Windows::Devices::Sms::SmsMessageType impl_ISmsMessageBase<D>::MessageType() const
{
    Windows::Devices::Sms::SmsMessageType value {};
    check_hresult(WINRT_SHIM(ISmsMessageBase)->get_MessageType(&value));
    return value;
}

template <typename D> hstring impl_ISmsMessageBase<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmsMessageBase)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sms::CellularClass impl_ISmsMessageBase<D>::CellularClass() const
{
    Windows::Devices::Sms::CellularClass value {};
    check_hresult(WINRT_SHIM(ISmsMessageBase)->get_CellularClass(&value));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsMessageClass impl_ISmsMessageBase<D>::MessageClass() const
{
    Windows::Devices::Sms::SmsMessageClass value {};
    check_hresult(WINRT_SHIM(ISmsMessageBase)->get_MessageClass(&value));
    return value;
}

template <typename D> hstring impl_ISmsMessageBase<D>::SimIccId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmsMessageBase)->get_SimIccId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_ISmsTextMessage2<D>::Timestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(ISmsTextMessage2)->get_Timestamp(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISmsTextMessage2<D>::To() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmsTextMessage2)->get_To(put_abi(value)));
    return value;
}

template <typename D> void impl_ISmsTextMessage2<D>::To(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISmsTextMessage2)->put_To(get_abi(value)));
}

template <typename D> hstring impl_ISmsTextMessage2<D>::From() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmsTextMessage2)->get_From(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISmsTextMessage2<D>::Body() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmsTextMessage2)->get_Body(put_abi(value)));
    return value;
}

template <typename D> void impl_ISmsTextMessage2<D>::Body(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISmsTextMessage2)->put_Body(get_abi(value)));
}

template <typename D> Windows::Devices::Sms::SmsEncoding impl_ISmsTextMessage2<D>::Encoding() const
{
    Windows::Devices::Sms::SmsEncoding value {};
    check_hresult(WINRT_SHIM(ISmsTextMessage2)->get_Encoding(&value));
    return value;
}

template <typename D> void impl_ISmsTextMessage2<D>::Encoding(Windows::Devices::Sms::SmsEncoding value) const
{
    check_hresult(WINRT_SHIM(ISmsTextMessage2)->put_Encoding(value));
}

template <typename D> hstring impl_ISmsTextMessage2<D>::CallbackNumber() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmsTextMessage2)->get_CallbackNumber(put_abi(value)));
    return value;
}

template <typename D> void impl_ISmsTextMessage2<D>::CallbackNumber(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISmsTextMessage2)->put_CallbackNumber(get_abi(value)));
}

template <typename D> bool impl_ISmsTextMessage2<D>::IsDeliveryNotificationEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISmsTextMessage2)->get_IsDeliveryNotificationEnabled(&value));
    return value;
}

template <typename D> void impl_ISmsTextMessage2<D>::IsDeliveryNotificationEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(ISmsTextMessage2)->put_IsDeliveryNotificationEnabled(value));
}

template <typename D> int32_t impl_ISmsTextMessage2<D>::RetryAttemptCount() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ISmsTextMessage2)->get_RetryAttemptCount(&value));
    return value;
}

template <typename D> void impl_ISmsTextMessage2<D>::RetryAttemptCount(int32_t value) const
{
    check_hresult(WINRT_SHIM(ISmsTextMessage2)->put_RetryAttemptCount(value));
}

template <typename D> int32_t impl_ISmsTextMessage2<D>::TeleserviceId() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ISmsTextMessage2)->get_TeleserviceId(&value));
    return value;
}

template <typename D> int32_t impl_ISmsTextMessage2<D>::ProtocolId() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ISmsTextMessage2)->get_ProtocolId(&value));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_ISmsWapMessage<D>::Timestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(ISmsWapMessage)->get_Timestamp(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISmsWapMessage<D>::To() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmsWapMessage)->get_To(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISmsWapMessage<D>::From() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmsWapMessage)->get_From(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISmsWapMessage<D>::ApplicationId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmsWapMessage)->get_ApplicationId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISmsWapMessage<D>::ContentType() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmsWapMessage)->get_ContentType(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_ISmsWapMessage<D>::BinaryBody() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(ISmsWapMessage)->get_BinaryBody(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMap<hstring, hstring> impl_ISmsWapMessage<D>::Headers() const
{
    Windows::Foundation::Collections::IMap<hstring, hstring> value;
    check_hresult(WINRT_SHIM(ISmsWapMessage)->get_Headers(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_ISmsAppMessage<D>::Timestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(ISmsAppMessage)->get_Timestamp(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISmsAppMessage<D>::To() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmsAppMessage)->get_To(put_abi(value)));
    return value;
}

template <typename D> void impl_ISmsAppMessage<D>::To(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISmsAppMessage)->put_To(get_abi(value)));
}

template <typename D> hstring impl_ISmsAppMessage<D>::From() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmsAppMessage)->get_From(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISmsAppMessage<D>::Body() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmsAppMessage)->get_Body(put_abi(value)));
    return value;
}

template <typename D> void impl_ISmsAppMessage<D>::Body(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISmsAppMessage)->put_Body(get_abi(value)));
}

template <typename D> hstring impl_ISmsAppMessage<D>::CallbackNumber() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmsAppMessage)->get_CallbackNumber(put_abi(value)));
    return value;
}

template <typename D> void impl_ISmsAppMessage<D>::CallbackNumber(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISmsAppMessage)->put_CallbackNumber(get_abi(value)));
}

template <typename D> bool impl_ISmsAppMessage<D>::IsDeliveryNotificationEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISmsAppMessage)->get_IsDeliveryNotificationEnabled(&value));
    return value;
}

template <typename D> void impl_ISmsAppMessage<D>::IsDeliveryNotificationEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(ISmsAppMessage)->put_IsDeliveryNotificationEnabled(value));
}

template <typename D> int32_t impl_ISmsAppMessage<D>::RetryAttemptCount() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ISmsAppMessage)->get_RetryAttemptCount(&value));
    return value;
}

template <typename D> void impl_ISmsAppMessage<D>::RetryAttemptCount(int32_t value) const
{
    check_hresult(WINRT_SHIM(ISmsAppMessage)->put_RetryAttemptCount(value));
}

template <typename D> Windows::Devices::Sms::SmsEncoding impl_ISmsAppMessage<D>::Encoding() const
{
    Windows::Devices::Sms::SmsEncoding value {};
    check_hresult(WINRT_SHIM(ISmsAppMessage)->get_Encoding(&value));
    return value;
}

template <typename D> void impl_ISmsAppMessage<D>::Encoding(Windows::Devices::Sms::SmsEncoding value) const
{
    check_hresult(WINRT_SHIM(ISmsAppMessage)->put_Encoding(value));
}

template <typename D> int32_t impl_ISmsAppMessage<D>::PortNumber() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ISmsAppMessage)->get_PortNumber(&value));
    return value;
}

template <typename D> void impl_ISmsAppMessage<D>::PortNumber(int32_t value) const
{
    check_hresult(WINRT_SHIM(ISmsAppMessage)->put_PortNumber(value));
}

template <typename D> int32_t impl_ISmsAppMessage<D>::TeleserviceId() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ISmsAppMessage)->get_TeleserviceId(&value));
    return value;
}

template <typename D> void impl_ISmsAppMessage<D>::TeleserviceId(int32_t value) const
{
    check_hresult(WINRT_SHIM(ISmsAppMessage)->put_TeleserviceId(value));
}

template <typename D> int32_t impl_ISmsAppMessage<D>::ProtocolId() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ISmsAppMessage)->get_ProtocolId(&value));
    return value;
}

template <typename D> void impl_ISmsAppMessage<D>::ProtocolId(int32_t value) const
{
    check_hresult(WINRT_SHIM(ISmsAppMessage)->put_ProtocolId(value));
}

template <typename D> Windows::Storage::Streams::IBuffer impl_ISmsAppMessage<D>::BinaryBody() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(ISmsAppMessage)->get_BinaryBody(put_abi(value)));
    return value;
}

template <typename D> void impl_ISmsAppMessage<D>::BinaryBody(const Windows::Storage::Streams::IBuffer & value) const
{
    check_hresult(WINRT_SHIM(ISmsAppMessage)->put_BinaryBody(get_abi(value)));
}

template <typename D> Windows::Foundation::DateTime impl_ISmsBroadcastMessage<D>::Timestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(ISmsBroadcastMessage)->get_Timestamp(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISmsBroadcastMessage<D>::To() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmsBroadcastMessage)->get_To(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISmsBroadcastMessage<D>::Body() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmsBroadcastMessage)->get_Body(put_abi(value)));
    return value;
}

template <typename D> int32_t impl_ISmsBroadcastMessage<D>::Channel() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ISmsBroadcastMessage)->get_Channel(&value));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsGeographicalScope impl_ISmsBroadcastMessage<D>::GeographicalScope() const
{
    Windows::Devices::Sms::SmsGeographicalScope value {};
    check_hresult(WINRT_SHIM(ISmsBroadcastMessage)->get_GeographicalScope(&value));
    return value;
}

template <typename D> int32_t impl_ISmsBroadcastMessage<D>::MessageCode() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ISmsBroadcastMessage)->get_MessageCode(&value));
    return value;
}

template <typename D> int32_t impl_ISmsBroadcastMessage<D>::UpdateNumber() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ISmsBroadcastMessage)->get_UpdateNumber(&value));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsBroadcastType impl_ISmsBroadcastMessage<D>::BroadcastType() const
{
    Windows::Devices::Sms::SmsBroadcastType value {};
    check_hresult(WINRT_SHIM(ISmsBroadcastMessage)->get_BroadcastType(&value));
    return value;
}

template <typename D> bool impl_ISmsBroadcastMessage<D>::IsEmergencyAlert() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISmsBroadcastMessage)->get_IsEmergencyAlert(&value));
    return value;
}

template <typename D> bool impl_ISmsBroadcastMessage<D>::IsUserPopupRequested() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISmsBroadcastMessage)->get_IsUserPopupRequested(&value));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_ISmsVoicemailMessage<D>::Timestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(ISmsVoicemailMessage)->get_Timestamp(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISmsVoicemailMessage<D>::To() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmsVoicemailMessage)->get_To(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISmsVoicemailMessage<D>::Body() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmsVoicemailMessage)->get_Body(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<int32_t> impl_ISmsVoicemailMessage<D>::MessageCount() const
{
    Windows::Foundation::IReference<int32_t> value;
    check_hresult(WINRT_SHIM(ISmsVoicemailMessage)->get_MessageCount(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISmsStatusMessage<D>::To() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmsStatusMessage)->get_To(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISmsStatusMessage<D>::From() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmsStatusMessage)->get_From(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISmsStatusMessage<D>::Body() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmsStatusMessage)->get_Body(put_abi(value)));
    return value;
}

template <typename D> int32_t impl_ISmsStatusMessage<D>::Status() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ISmsStatusMessage)->get_Status(&value));
    return value;
}

template <typename D> int32_t impl_ISmsStatusMessage<D>::MessageReferenceNumber() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ISmsStatusMessage)->get_MessageReferenceNumber(&value));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_ISmsStatusMessage<D>::ServiceCenterTimestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(ISmsStatusMessage)->get_ServiceCenterTimestamp(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_ISmsStatusMessage<D>::DischargeTime() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(ISmsStatusMessage)->get_DischargeTime(put_abi(value)));
    return value;
}

template <typename D> bool impl_ISmsSendMessageResult<D>::IsSuccessful() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISmsSendMessageResult)->get_IsSuccessful(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<int32_t> impl_ISmsSendMessageResult<D>::MessageReferenceNumbers() const
{
    Windows::Foundation::Collections::IVectorView<int32_t> value;
    check_hresult(WINRT_SHIM(ISmsSendMessageResult)->get_MessageReferenceNumbers(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sms::CellularClass impl_ISmsSendMessageResult<D>::CellularClass() const
{
    Windows::Devices::Sms::CellularClass value {};
    check_hresult(WINRT_SHIM(ISmsSendMessageResult)->get_CellularClass(&value));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsModemErrorCode impl_ISmsSendMessageResult<D>::ModemErrorCode() const
{
    Windows::Devices::Sms::SmsModemErrorCode value {};
    check_hresult(WINRT_SHIM(ISmsSendMessageResult)->get_ModemErrorCode(&value));
    return value;
}

template <typename D> bool impl_ISmsSendMessageResult<D>::IsErrorTransient() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISmsSendMessageResult)->get_IsErrorTransient(&value));
    return value;
}

template <typename D> int32_t impl_ISmsSendMessageResult<D>::NetworkCauseCode() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ISmsSendMessageResult)->get_NetworkCauseCode(&value));
    return value;
}

template <typename D> int32_t impl_ISmsSendMessageResult<D>::TransportFailureCause() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ISmsSendMessageResult)->get_TransportFailureCause(&value));
    return value;
}

template <typename D> hstring impl_ISmsDevice2Statics<D>::GetDeviceSelector() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmsDevice2Statics)->abi_GetDeviceSelector(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsDevice2 impl_ISmsDevice2Statics<D>::FromId(hstring_view deviceId) const
{
    Windows::Devices::Sms::SmsDevice2 value { nullptr };
    check_hresult(WINRT_SHIM(ISmsDevice2Statics)->abi_FromId(get_abi(deviceId), put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsDevice2 impl_ISmsDevice2Statics<D>::GetDefault() const
{
    Windows::Devices::Sms::SmsDevice2 value { nullptr };
    check_hresult(WINRT_SHIM(ISmsDevice2Statics)->abi_GetDefault(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsDevice2 impl_ISmsDevice2Statics<D>::FromParentId(hstring_view parentDeviceId) const
{
    Windows::Devices::Sms::SmsDevice2 value { nullptr };
    check_hresult(WINRT_SHIM(ISmsDevice2Statics)->abi_FromParentId(get_abi(parentDeviceId), put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISmsDevice2<D>::SmscAddress() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmsDevice2)->get_SmscAddress(put_abi(value)));
    return value;
}

template <typename D> void impl_ISmsDevice2<D>::SmscAddress(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISmsDevice2)->put_SmscAddress(get_abi(value)));
}

template <typename D> hstring impl_ISmsDevice2<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmsDevice2)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISmsDevice2<D>::ParentDeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmsDevice2)->get_ParentDeviceId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISmsDevice2<D>::AccountPhoneNumber() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmsDevice2)->get_AccountPhoneNumber(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sms::CellularClass impl_ISmsDevice2<D>::CellularClass() const
{
    Windows::Devices::Sms::CellularClass value {};
    check_hresult(WINRT_SHIM(ISmsDevice2)->get_CellularClass(&value));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsDeviceStatus impl_ISmsDevice2<D>::DeviceStatus() const
{
    Windows::Devices::Sms::SmsDeviceStatus value {};
    check_hresult(WINRT_SHIM(ISmsDevice2)->get_DeviceStatus(&value));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsEncodedLength impl_ISmsDevice2<D>::CalculateLength(const Windows::Devices::Sms::ISmsMessageBase & message) const
{
    Windows::Devices::Sms::SmsEncodedLength value {};
    check_hresult(WINRT_SHIM(ISmsDevice2)->abi_CalculateLength(get_abi(message), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Sms::SmsSendMessageResult> impl_ISmsDevice2<D>::SendMessageAndGetResultAsync(const Windows::Devices::Sms::ISmsMessageBase & message) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Sms::SmsSendMessageResult> asyncInfo;
    check_hresult(WINRT_SHIM(ISmsDevice2)->abi_SendMessageAndGetResultAsync(get_abi(message), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> event_token impl_ISmsDevice2<D>::DeviceStatusChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Sms::SmsDevice2, Windows::Foundation::IInspectable> & eventHandler) const
{
    event_token eventCookie {};
    check_hresult(WINRT_SHIM(ISmsDevice2)->add_DeviceStatusChanged(get_abi(eventHandler), &eventCookie));
    return eventCookie;
}

template <typename D> event_revoker<ISmsDevice2> impl_ISmsDevice2<D>::DeviceStatusChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Sms::SmsDevice2, Windows::Foundation::IInspectable> & eventHandler) const
{
    return impl::make_event_revoker<D, ISmsDevice2>(this, &ABI::Windows::Devices::Sms::ISmsDevice2::remove_DeviceStatusChanged, DeviceStatusChanged(eventHandler));
}

template <typename D> void impl_ISmsDevice2<D>::DeviceStatusChanged(event_token eventCookie) const
{
    check_hresult(WINRT_SHIM(ISmsDevice2)->remove_DeviceStatusChanged(eventCookie));
}

template <typename D> Windows::Devices::Sms::SmsMessageType impl_ISmsMessageReceivedTriggerDetails<D>::MessageType() const
{
    Windows::Devices::Sms::SmsMessageType value {};
    check_hresult(WINRT_SHIM(ISmsMessageReceivedTriggerDetails)->get_MessageType(&value));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsTextMessage2 impl_ISmsMessageReceivedTriggerDetails<D>::TextMessage() const
{
    Windows::Devices::Sms::SmsTextMessage2 value { nullptr };
    check_hresult(WINRT_SHIM(ISmsMessageReceivedTriggerDetails)->get_TextMessage(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsWapMessage impl_ISmsMessageReceivedTriggerDetails<D>::WapMessage() const
{
    Windows::Devices::Sms::SmsWapMessage value { nullptr };
    check_hresult(WINRT_SHIM(ISmsMessageReceivedTriggerDetails)->get_WapMessage(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsAppMessage impl_ISmsMessageReceivedTriggerDetails<D>::AppMessage() const
{
    Windows::Devices::Sms::SmsAppMessage value { nullptr };
    check_hresult(WINRT_SHIM(ISmsMessageReceivedTriggerDetails)->get_AppMessage(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsBroadcastMessage impl_ISmsMessageReceivedTriggerDetails<D>::BroadcastMessage() const
{
    Windows::Devices::Sms::SmsBroadcastMessage value { nullptr };
    check_hresult(WINRT_SHIM(ISmsMessageReceivedTriggerDetails)->get_BroadcastMessage(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsVoicemailMessage impl_ISmsMessageReceivedTriggerDetails<D>::VoicemailMessage() const
{
    Windows::Devices::Sms::SmsVoicemailMessage value { nullptr };
    check_hresult(WINRT_SHIM(ISmsMessageReceivedTriggerDetails)->get_VoicemailMessage(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsStatusMessage impl_ISmsMessageReceivedTriggerDetails<D>::StatusMessage() const
{
    Windows::Devices::Sms::SmsStatusMessage value { nullptr };
    check_hresult(WINRT_SHIM(ISmsMessageReceivedTriggerDetails)->get_StatusMessage(put_abi(value)));
    return value;
}

template <typename D> void impl_ISmsMessageReceivedTriggerDetails<D>::Drop() const
{
    check_hresult(WINRT_SHIM(ISmsMessageReceivedTriggerDetails)->abi_Drop());
}

template <typename D> void impl_ISmsMessageReceivedTriggerDetails<D>::Accept() const
{
    check_hresult(WINRT_SHIM(ISmsMessageReceivedTriggerDetails)->abi_Accept());
}

template <typename D> Windows::Devices::Sms::SmsMessageType impl_ISmsFilterRule<D>::MessageType() const
{
    Windows::Devices::Sms::SmsMessageType value {};
    check_hresult(WINRT_SHIM(ISmsFilterRule)->get_MessageType(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_ISmsFilterRule<D>::ImsiPrefixes() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(ISmsFilterRule)->get_ImsiPrefixes(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_ISmsFilterRule<D>::DeviceIds() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(ISmsFilterRule)->get_DeviceIds(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_ISmsFilterRule<D>::SenderNumbers() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(ISmsFilterRule)->get_SenderNumbers(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_ISmsFilterRule<D>::TextMessagePrefixes() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(ISmsFilterRule)->get_TextMessagePrefixes(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<int32_t> impl_ISmsFilterRule<D>::PortNumbers() const
{
    Windows::Foundation::Collections::IVector<int32_t> value;
    check_hresult(WINRT_SHIM(ISmsFilterRule)->get_PortNumbers(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sms::CellularClass impl_ISmsFilterRule<D>::CellularClass() const
{
    Windows::Devices::Sms::CellularClass value {};
    check_hresult(WINRT_SHIM(ISmsFilterRule)->get_CellularClass(&value));
    return value;
}

template <typename D> void impl_ISmsFilterRule<D>::CellularClass(Windows::Devices::Sms::CellularClass value) const
{
    check_hresult(WINRT_SHIM(ISmsFilterRule)->put_CellularClass(value));
}

template <typename D> Windows::Foundation::Collections::IVector<int32_t> impl_ISmsFilterRule<D>::ProtocolIds() const
{
    Windows::Foundation::Collections::IVector<int32_t> value;
    check_hresult(WINRT_SHIM(ISmsFilterRule)->get_ProtocolIds(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<int32_t> impl_ISmsFilterRule<D>::TeleserviceIds() const
{
    Windows::Foundation::Collections::IVector<int32_t> value;
    check_hresult(WINRT_SHIM(ISmsFilterRule)->get_TeleserviceIds(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_ISmsFilterRule<D>::WapApplicationIds() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(ISmsFilterRule)->get_WapApplicationIds(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_ISmsFilterRule<D>::WapContentTypes() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(ISmsFilterRule)->get_WapContentTypes(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<winrt::Windows::Devices::Sms::SmsBroadcastType> impl_ISmsFilterRule<D>::BroadcastTypes() const
{
    Windows::Foundation::Collections::IVector<winrt::Windows::Devices::Sms::SmsBroadcastType> value;
    check_hresult(WINRT_SHIM(ISmsFilterRule)->get_BroadcastTypes(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<int32_t> impl_ISmsFilterRule<D>::BroadcastChannels() const
{
    Windows::Foundation::Collections::IVector<int32_t> value;
    check_hresult(WINRT_SHIM(ISmsFilterRule)->get_BroadcastChannels(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsFilterRule impl_ISmsFilterRuleFactory<D>::CreateFilterRule(Windows::Devices::Sms::SmsMessageType messageType) const
{
    Windows::Devices::Sms::SmsFilterRule value { nullptr };
    check_hresult(WINRT_SHIM(ISmsFilterRuleFactory)->abi_CreateFilterRule(messageType, put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsFilterActionType impl_ISmsFilterRules<D>::ActionType() const
{
    Windows::Devices::Sms::SmsFilterActionType value {};
    check_hresult(WINRT_SHIM(ISmsFilterRules)->get_ActionType(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Devices::Sms::SmsFilterRule> impl_ISmsFilterRules<D>::Rules() const
{
    Windows::Foundation::Collections::IVector<Windows::Devices::Sms::SmsFilterRule> value;
    check_hresult(WINRT_SHIM(ISmsFilterRules)->get_Rules(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsFilterRules impl_ISmsFilterRulesFactory<D>::CreateFilterRules(Windows::Devices::Sms::SmsFilterActionType actionType) const
{
    Windows::Devices::Sms::SmsFilterRules value { nullptr };
    check_hresult(WINRT_SHIM(ISmsFilterRulesFactory)->abi_CreateFilterRules(actionType, put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Sms::SmsMessageRegistration> impl_ISmsMessageRegistrationStatics<D>::AllRegistrations() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Sms::SmsMessageRegistration> value;
    check_hresult(WINRT_SHIM(ISmsMessageRegistrationStatics)->get_AllRegistrations(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsMessageRegistration impl_ISmsMessageRegistrationStatics<D>::Register(hstring_view id, const Windows::Devices::Sms::SmsFilterRules & filterRules) const
{
    Windows::Devices::Sms::SmsMessageRegistration value { nullptr };
    check_hresult(WINRT_SHIM(ISmsMessageRegistrationStatics)->abi_Register(get_abi(id), get_abi(filterRules), put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISmsMessageRegistration<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmsMessageRegistration)->get_Id(put_abi(value)));
    return value;
}

template <typename D> void impl_ISmsMessageRegistration<D>::Unregister() const
{
    check_hresult(WINRT_SHIM(ISmsMessageRegistration)->abi_Unregister());
}

template <typename D> event_token impl_ISmsMessageRegistration<D>::MessageReceived(const Windows::Foundation::TypedEventHandler<Windows::Devices::Sms::SmsMessageRegistration, Windows::Devices::Sms::SmsMessageReceivedTriggerDetails> & eventHandler) const
{
    event_token eventCookie {};
    check_hresult(WINRT_SHIM(ISmsMessageRegistration)->add_MessageReceived(get_abi(eventHandler), &eventCookie));
    return eventCookie;
}

template <typename D> event_revoker<ISmsMessageRegistration> impl_ISmsMessageRegistration<D>::MessageReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Sms::SmsMessageRegistration, Windows::Devices::Sms::SmsMessageReceivedTriggerDetails> & eventHandler) const
{
    return impl::make_event_revoker<D, ISmsMessageRegistration>(this, &ABI::Windows::Devices::Sms::ISmsMessageRegistration::remove_MessageReceived, MessageReceived(eventHandler));
}

template <typename D> void impl_ISmsMessageRegistration<D>::MessageReceived(event_token eventCookie) const
{
    check_hresult(WINRT_SHIM(ISmsMessageRegistration)->remove_MessageReceived(eventCookie));
}

template <typename D> uint32_t impl_ISmsMessage<D>::Id() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ISmsMessage)->get_Id(&value));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsMessageClass impl_ISmsMessage<D>::MessageClass() const
{
    Windows::Devices::Sms::SmsMessageClass value {};
    check_hresult(WINRT_SHIM(ISmsMessage)->get_MessageClass(&value));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsDataFormat impl_ISmsBinaryMessage<D>::Format() const
{
    Windows::Devices::Sms::SmsDataFormat value {};
    check_hresult(WINRT_SHIM(ISmsBinaryMessage)->get_Format(&value));
    return value;
}

template <typename D> void impl_ISmsBinaryMessage<D>::Format(Windows::Devices::Sms::SmsDataFormat value) const
{
    check_hresult(WINRT_SHIM(ISmsBinaryMessage)->put_Format(value));
}

template <typename D> com_array<uint8_t> impl_ISmsBinaryMessage<D>::GetData() const
{
    com_array<uint8_t> value {};
    check_hresult(WINRT_SHIM(ISmsBinaryMessage)->abi_GetData(impl::put_size_abi(value), put_abi(value)));
    return value;
}

template <typename D> void impl_ISmsBinaryMessage<D>::SetData(array_view<const uint8_t> value) const
{
    check_hresult(WINRT_SHIM(ISmsBinaryMessage)->abi_SetData(value.size(), get_abi(value)));
}

template <typename D> Windows::Foundation::DateTime impl_ISmsTextMessage<D>::Timestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(ISmsTextMessage)->get_Timestamp(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_ISmsTextMessage<D>::PartReferenceId() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ISmsTextMessage)->get_PartReferenceId(&value));
    return value;
}

template <typename D> uint32_t impl_ISmsTextMessage<D>::PartNumber() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ISmsTextMessage)->get_PartNumber(&value));
    return value;
}

template <typename D> uint32_t impl_ISmsTextMessage<D>::PartCount() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ISmsTextMessage)->get_PartCount(&value));
    return value;
}

template <typename D> hstring impl_ISmsTextMessage<D>::To() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmsTextMessage)->get_To(put_abi(value)));
    return value;
}

template <typename D> void impl_ISmsTextMessage<D>::To(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISmsTextMessage)->put_To(get_abi(value)));
}

template <typename D> hstring impl_ISmsTextMessage<D>::From() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmsTextMessage)->get_From(put_abi(value)));
    return value;
}

template <typename D> void impl_ISmsTextMessage<D>::From(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISmsTextMessage)->put_From(get_abi(value)));
}

template <typename D> hstring impl_ISmsTextMessage<D>::Body() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmsTextMessage)->get_Body(put_abi(value)));
    return value;
}

template <typename D> void impl_ISmsTextMessage<D>::Body(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISmsTextMessage)->put_Body(get_abi(value)));
}

template <typename D> Windows::Devices::Sms::SmsEncoding impl_ISmsTextMessage<D>::Encoding() const
{
    Windows::Devices::Sms::SmsEncoding value {};
    check_hresult(WINRT_SHIM(ISmsTextMessage)->get_Encoding(&value));
    return value;
}

template <typename D> void impl_ISmsTextMessage<D>::Encoding(Windows::Devices::Sms::SmsEncoding value) const
{
    check_hresult(WINRT_SHIM(ISmsTextMessage)->put_Encoding(value));
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Sms::ISmsBinaryMessage> impl_ISmsTextMessage<D>::ToBinaryMessages(Windows::Devices::Sms::SmsDataFormat format) const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Sms::ISmsBinaryMessage> messages;
    check_hresult(WINRT_SHIM(ISmsTextMessage)->abi_ToBinaryMessages(format, put_abi(messages)));
    return messages;
}

template <typename D> Windows::Devices::Sms::SmsTextMessage impl_ISmsTextMessageStatics<D>::FromBinaryMessage(const Windows::Devices::Sms::SmsBinaryMessage & binaryMessage) const
{
    Windows::Devices::Sms::SmsTextMessage textMessage { nullptr };
    check_hresult(WINRT_SHIM(ISmsTextMessageStatics)->abi_FromBinaryMessage(get_abi(binaryMessage), put_abi(textMessage)));
    return textMessage;
}

template <typename D> Windows::Devices::Sms::SmsTextMessage impl_ISmsTextMessageStatics<D>::FromBinaryData(Windows::Devices::Sms::SmsDataFormat format, array_view<const uint8_t> value) const
{
    Windows::Devices::Sms::SmsTextMessage textMessage { nullptr };
    check_hresult(WINRT_SHIM(ISmsTextMessageStatics)->abi_FromBinaryData(format, value.size(), get_abi(value), put_abi(textMessage)));
    return textMessage;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ISmsDeviceMessageStore<D>::DeleteMessageAsync(uint32_t messageId) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(ISmsDeviceMessageStore)->abi_DeleteMessageAsync(messageId, put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ISmsDeviceMessageStore<D>::DeleteMessagesAsync(Windows::Devices::Sms::SmsMessageFilter messageFilter) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(ISmsDeviceMessageStore)->abi_DeleteMessagesAsync(messageFilter, put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Sms::ISmsMessage> impl_ISmsDeviceMessageStore<D>::GetMessageAsync(uint32_t messageId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Sms::ISmsMessage> asyncInfo;
    check_hresult(WINRT_SHIM(ISmsDeviceMessageStore)->abi_GetMessageAsync(messageId, put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sms::ISmsMessage>, int32_t> impl_ISmsDeviceMessageStore<D>::GetMessagesAsync(Windows::Devices::Sms::SmsMessageFilter messageFilter) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sms::ISmsMessage>, int32_t> asyncInfo;
    check_hresult(WINRT_SHIM(ISmsDeviceMessageStore)->abi_GetMessagesAsync(messageFilter, put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> uint32_t impl_ISmsDeviceMessageStore<D>::MaxMessages() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ISmsDeviceMessageStore)->get_MaxMessages(&value));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsTextMessage impl_ISmsMessageReceivedEventArgs<D>::TextMessage() const
{
    Windows::Devices::Sms::SmsTextMessage value { nullptr };
    check_hresult(WINRT_SHIM(ISmsMessageReceivedEventArgs)->get_TextMessage(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsBinaryMessage impl_ISmsMessageReceivedEventArgs<D>::BinaryMessage() const
{
    Windows::Devices::Sms::SmsBinaryMessage value { nullptr };
    check_hresult(WINRT_SHIM(ISmsMessageReceivedEventArgs)->get_BinaryMessage(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISmsDeviceStatics<D>::GetDeviceSelector() const
{
    hstring phstrDeviceClassSelector;
    check_hresult(WINRT_SHIM(ISmsDeviceStatics)->abi_GetDeviceSelector(put_abi(phstrDeviceClassSelector)));
    return phstrDeviceClassSelector;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Sms::SmsDevice> impl_ISmsDeviceStatics<D>::FromIdAsync(hstring_view deviceId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Sms::SmsDevice> asyncInfo;
    check_hresult(WINRT_SHIM(ISmsDeviceStatics)->abi_FromIdAsync(get_abi(deviceId), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Sms::SmsDevice> impl_ISmsDeviceStatics<D>::GetDefaultAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Sms::SmsDevice> asyncInfo;
    check_hresult(WINRT_SHIM(ISmsDeviceStatics)->abi_GetDefaultAsync(put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Sms::SmsDevice> impl_ISmsDeviceStatics2<D>::FromNetworkAccountIdAsync(hstring_view networkAccountId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Sms::SmsDevice> asyncInfo;
    check_hresult(WINRT_SHIM(ISmsDeviceStatics2)->abi_FromNetworkAccountIdAsync(get_abi(networkAccountId), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Devices::Sms::SendSmsMessageOperation impl_ISmsDevice<D>::SendMessageAsync(const Windows::Devices::Sms::ISmsMessage & message) const
{
    Windows::Devices::Sms::SendSmsMessageOperation asyncInfo { nullptr };
    check_hresult(WINRT_SHIM(ISmsDevice)->abi_SendMessageAsync(get_abi(message), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Devices::Sms::SmsEncodedLength impl_ISmsDevice<D>::CalculateLength(const Windows::Devices::Sms::SmsTextMessage & message) const
{
    Windows::Devices::Sms::SmsEncodedLength encodedLength {};
    check_hresult(WINRT_SHIM(ISmsDevice)->abi_CalculateLength(get_abi(message), put_abi(encodedLength)));
    return encodedLength;
}

template <typename D> hstring impl_ISmsDevice<D>::AccountPhoneNumber() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmsDevice)->get_AccountPhoneNumber(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sms::CellularClass impl_ISmsDevice<D>::CellularClass() const
{
    Windows::Devices::Sms::CellularClass value {};
    check_hresult(WINRT_SHIM(ISmsDevice)->get_CellularClass(&value));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsDeviceMessageStore impl_ISmsDevice<D>::MessageStore() const
{
    Windows::Devices::Sms::SmsDeviceMessageStore value { nullptr };
    check_hresult(WINRT_SHIM(ISmsDevice)->get_MessageStore(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsDeviceStatus impl_ISmsDevice<D>::DeviceStatus() const
{
    Windows::Devices::Sms::SmsDeviceStatus value {};
    check_hresult(WINRT_SHIM(ISmsDevice)->get_DeviceStatus(&value));
    return value;
}

template <typename D> event_token impl_ISmsDevice<D>::SmsMessageReceived(const Windows::Devices::Sms::SmsMessageReceivedEventHandler & eventHandler) const
{
    event_token eventCookie {};
    check_hresult(WINRT_SHIM(ISmsDevice)->add_SmsMessageReceived(get_abi(eventHandler), &eventCookie));
    return eventCookie;
}

template <typename D> event_revoker<ISmsDevice> impl_ISmsDevice<D>::SmsMessageReceived(auto_revoke_t, const Windows::Devices::Sms::SmsMessageReceivedEventHandler & eventHandler) const
{
    return impl::make_event_revoker<D, ISmsDevice>(this, &ABI::Windows::Devices::Sms::ISmsDevice::remove_SmsMessageReceived, SmsMessageReceived(eventHandler));
}

template <typename D> void impl_ISmsDevice<D>::SmsMessageReceived(event_token eventCookie) const
{
    check_hresult(WINRT_SHIM(ISmsDevice)->remove_SmsMessageReceived(eventCookie));
}

template <typename D> event_token impl_ISmsDevice<D>::SmsDeviceStatusChanged(const Windows::Devices::Sms::SmsDeviceStatusChangedEventHandler & eventHandler) const
{
    event_token eventCookie {};
    check_hresult(WINRT_SHIM(ISmsDevice)->add_SmsDeviceStatusChanged(get_abi(eventHandler), &eventCookie));
    return eventCookie;
}

template <typename D> event_revoker<ISmsDevice> impl_ISmsDevice<D>::SmsDeviceStatusChanged(auto_revoke_t, const Windows::Devices::Sms::SmsDeviceStatusChangedEventHandler & eventHandler) const
{
    return impl::make_event_revoker<D, ISmsDevice>(this, &ABI::Windows::Devices::Sms::ISmsDevice::remove_SmsDeviceStatusChanged, SmsDeviceStatusChanged(eventHandler));
}

template <typename D> void impl_ISmsDevice<D>::SmsDeviceStatusChanged(event_token eventCookie) const
{
    check_hresult(WINRT_SHIM(ISmsDevice)->remove_SmsDeviceStatusChanged(eventCookie));
}

template <typename D> hstring impl_ISmsReceivedEventDetails<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmsReceivedEventDetails)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_ISmsReceivedEventDetails<D>::MessageIndex() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ISmsReceivedEventDetails)->get_MessageIndex(&value));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsMessageClass impl_ISmsReceivedEventDetails2<D>::MessageClass() const
{
    Windows::Devices::Sms::SmsMessageClass value {};
    check_hresult(WINRT_SHIM(ISmsReceivedEventDetails2)->get_MessageClass(&value));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsBinaryMessage impl_ISmsReceivedEventDetails2<D>::BinaryMessage() const
{
    Windows::Devices::Sms::SmsBinaryMessage value { nullptr };
    check_hresult(WINRT_SHIM(ISmsReceivedEventDetails2)->get_BinaryMessage(put_abi(value)));
    return value;
}

inline SmsAppMessage::SmsAppMessage() :
    SmsAppMessage(activate_instance<SmsAppMessage>())
{}

inline SmsBinaryMessage::SmsBinaryMessage() :
    SmsBinaryMessage(activate_instance<SmsBinaryMessage>())
{}

inline hstring SmsDevice::GetDeviceSelector()
{
    return get_activation_factory<SmsDevice, ISmsDeviceStatics>().GetDeviceSelector();
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Sms::SmsDevice> SmsDevice::FromIdAsync(hstring_view deviceId)
{
    return get_activation_factory<SmsDevice, ISmsDeviceStatics>().FromIdAsync(deviceId);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Sms::SmsDevice> SmsDevice::GetDefaultAsync()
{
    return get_activation_factory<SmsDevice, ISmsDeviceStatics>().GetDefaultAsync();
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Sms::SmsDevice> SmsDevice::FromNetworkAccountIdAsync(hstring_view networkAccountId)
{
    return get_activation_factory<SmsDevice, ISmsDeviceStatics2>().FromNetworkAccountIdAsync(networkAccountId);
}

inline hstring SmsDevice2::GetDeviceSelector()
{
    return get_activation_factory<SmsDevice2, ISmsDevice2Statics>().GetDeviceSelector();
}

inline Windows::Devices::Sms::SmsDevice2 SmsDevice2::FromId(hstring_view deviceId)
{
    return get_activation_factory<SmsDevice2, ISmsDevice2Statics>().FromId(deviceId);
}

inline Windows::Devices::Sms::SmsDevice2 SmsDevice2::GetDefault()
{
    return get_activation_factory<SmsDevice2, ISmsDevice2Statics>().GetDefault();
}

inline Windows::Devices::Sms::SmsDevice2 SmsDevice2::FromParentId(hstring_view parentDeviceId)
{
    return get_activation_factory<SmsDevice2, ISmsDevice2Statics>().FromParentId(parentDeviceId);
}

inline SmsFilterRule::SmsFilterRule(Windows::Devices::Sms::SmsMessageType messageType) :
    SmsFilterRule(get_activation_factory<SmsFilterRule, ISmsFilterRuleFactory>().CreateFilterRule(messageType))
{}

inline SmsFilterRules::SmsFilterRules(Windows::Devices::Sms::SmsFilterActionType actionType) :
    SmsFilterRules(get_activation_factory<SmsFilterRules, ISmsFilterRulesFactory>().CreateFilterRules(actionType))
{}

inline Windows::Foundation::Collections::IVectorView<Windows::Devices::Sms::SmsMessageRegistration> SmsMessageRegistration::AllRegistrations()
{
    return get_activation_factory<SmsMessageRegistration, ISmsMessageRegistrationStatics>().AllRegistrations();
}

inline Windows::Devices::Sms::SmsMessageRegistration SmsMessageRegistration::Register(hstring_view id, const Windows::Devices::Sms::SmsFilterRules & filterRules)
{
    return get_activation_factory<SmsMessageRegistration, ISmsMessageRegistrationStatics>().Register(id, filterRules);
}

inline SmsTextMessage::SmsTextMessage() :
    SmsTextMessage(activate_instance<SmsTextMessage>())
{}

inline Windows::Devices::Sms::SmsTextMessage SmsTextMessage::FromBinaryMessage(const Windows::Devices::Sms::SmsBinaryMessage & binaryMessage)
{
    return get_activation_factory<SmsTextMessage, ISmsTextMessageStatics>().FromBinaryMessage(binaryMessage);
}

inline Windows::Devices::Sms::SmsTextMessage SmsTextMessage::FromBinaryData(Windows::Devices::Sms::SmsDataFormat format, array_view<const uint8_t> value)
{
    return get_activation_factory<SmsTextMessage, ISmsTextMessageStatics>().FromBinaryData(format, value);
}

inline SmsTextMessage2::SmsTextMessage2() :
    SmsTextMessage2(activate_instance<SmsTextMessage2>())
{}

}

}
#pragma warning(pop)
