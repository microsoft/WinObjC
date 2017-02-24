// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Devices.Printers.Extensions.3.h"
#include "Windows.Devices.Printers.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::Printers::Extensions::IPrint3DWorkflow> : produce_base<D, Windows::Devices::Printers::Extensions::IPrint3DWorkflow>
{
    HRESULT __stdcall get_DeviceID(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceID());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPrintModelPackage(impl::abi_arg_out<Windows::Foundation::IInspectable> printModelPackage) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *printModelPackage = detach_abi(this->shim().GetPrintModelPackage());
            return S_OK;
        }
        catch (...)
        {
            *printModelPackage = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsPrintReady(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsPrintReady());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsPrintReady(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsPrintReady(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PrintRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrintRequestedEventArgs>> eventHandler, event_token * eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_abi(this->shim().PrintRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrintRequestedEventArgs> *>(&eventHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PrintRequested(event_token eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PrintRequested(eventCookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Printers::Extensions::IPrint3DWorkflow2> : produce_base<D, Windows::Devices::Printers::Extensions::IPrint3DWorkflow2>
{
    HRESULT __stdcall add_PrinterChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrinterChangedEventArgs>> eventHandler, event_token * eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_abi(this->shim().PrinterChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrinterChangedEventArgs> *>(&eventHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PrinterChanged(event_token eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PrinterChanged(eventCookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrintRequestedEventArgs> : produce_base<D, Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrintRequestedEventArgs>
{
    HRESULT __stdcall get_Status(Windows::Devices::Printers::Extensions::Print3DWorkflowStatus * value) noexcept override
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

    HRESULT __stdcall abi_SetExtendedStatus(Windows::Devices::Printers::Extensions::Print3DWorkflowDetail value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetExtendedStatus(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetSource(impl::abi_arg_in<Windows::Foundation::IInspectable> source) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetSource(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&source));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetSourceChanged(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetSourceChanged(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrinterChangedEventArgs> : produce_base<D, Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrinterChangedEventArgs>
{
    HRESULT __stdcall get_NewDeviceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NewDeviceId());
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
struct produce<D, Windows::Devices::Printers::Extensions::IPrintExtensionContextStatic> : produce_base<D, Windows::Devices::Printers::Extensions::IPrintExtensionContextStatic>
{
    HRESULT __stdcall abi_FromDeviceId(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_out<Windows::Foundation::IInspectable> context) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *context = detach_abi(this->shim().FromDeviceId(*reinterpret_cast<const hstring *>(&deviceId)));
            return S_OK;
        }
        catch (...)
        {
            *context = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Printers::Extensions::IPrintNotificationEventDetails> : produce_base<D, Windows::Devices::Printers::Extensions::IPrintNotificationEventDetails>
{
    HRESULT __stdcall get_PrinterName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PrinterName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EventData(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EventData());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EventData(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EventData(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Printers::Extensions::IPrintTaskConfiguration> : produce_base<D, Windows::Devices::Printers::Extensions::IPrintTaskConfiguration>
{
    HRESULT __stdcall get_PrinterExtensionContext(impl::abi_arg_out<Windows::Foundation::IInspectable> context) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *context = detach_abi(this->shim().PrinterExtensionContext());
            return S_OK;
        }
        catch (...)
        {
            *context = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_SaveRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::PrintTaskConfiguration, Windows::Devices::Printers::Extensions::PrintTaskConfigurationSaveRequestedEventArgs>> eventHandler, event_token * eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_abi(this->shim().SaveRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::PrintTaskConfiguration, Windows::Devices::Printers::Extensions::PrintTaskConfigurationSaveRequestedEventArgs> *>(&eventHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SaveRequested(event_token eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SaveRequested(eventCookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequest> : produce_base<D, Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequest>
{
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

    HRESULT __stdcall abi_Save(impl::abi_arg_in<Windows::Foundation::IInspectable> printerExtensionContext) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Save(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&printerExtensionContext));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequestedDeferral> deferral) noexcept override
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

    HRESULT __stdcall get_Deadline(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Deadline());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequestedDeferral> : produce_base<D, Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequestedDeferral>
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
struct produce<D, Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequestedEventArgs> : produce_base<D, Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequestedEventArgs>
{
    HRESULT __stdcall get_Request(impl::abi_arg_out<Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequest> context) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *context = detach_abi(this->shim().Request());
            return S_OK;
        }
        catch (...)
        {
            *context = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Devices::Printers::Extensions {

template <typename D> Windows::Devices::Printers::Extensions::Print3DWorkflowStatus impl_IPrint3DWorkflowPrintRequestedEventArgs<D>::Status() const
{
    Windows::Devices::Printers::Extensions::Print3DWorkflowStatus value {};
    check_hresult(WINRT_SHIM(IPrint3DWorkflowPrintRequestedEventArgs)->get_Status(&value));
    return value;
}

template <typename D> void impl_IPrint3DWorkflowPrintRequestedEventArgs<D>::SetExtendedStatus(Windows::Devices::Printers::Extensions::Print3DWorkflowDetail value) const
{
    check_hresult(WINRT_SHIM(IPrint3DWorkflowPrintRequestedEventArgs)->abi_SetExtendedStatus(value));
}

template <typename D> void impl_IPrint3DWorkflowPrintRequestedEventArgs<D>::SetSource(const Windows::Foundation::IInspectable & source) const
{
    check_hresult(WINRT_SHIM(IPrint3DWorkflowPrintRequestedEventArgs)->abi_SetSource(get_abi(source)));
}

template <typename D> void impl_IPrint3DWorkflowPrintRequestedEventArgs<D>::SetSourceChanged(bool value) const
{
    check_hresult(WINRT_SHIM(IPrint3DWorkflowPrintRequestedEventArgs)->abi_SetSourceChanged(value));
}

template <typename D> hstring impl_IPrint3DWorkflowPrinterChangedEventArgs<D>::NewDeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPrint3DWorkflowPrinterChangedEventArgs)->get_NewDeviceId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IPrint3DWorkflow<D>::DeviceID() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPrint3DWorkflow)->get_DeviceID(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IInspectable impl_IPrint3DWorkflow<D>::GetPrintModelPackage() const
{
    Windows::Foundation::IInspectable printModelPackage;
    check_hresult(WINRT_SHIM(IPrint3DWorkflow)->abi_GetPrintModelPackage(put_abi(printModelPackage)));
    return printModelPackage;
}

template <typename D> bool impl_IPrint3DWorkflow<D>::IsPrintReady() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPrint3DWorkflow)->get_IsPrintReady(&value));
    return value;
}

template <typename D> void impl_IPrint3DWorkflow<D>::IsPrintReady(bool value) const
{
    check_hresult(WINRT_SHIM(IPrint3DWorkflow)->put_IsPrintReady(value));
}

template <typename D> event_token impl_IPrint3DWorkflow<D>::PrintRequested(const Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrintRequestedEventArgs> & eventHandler) const
{
    event_token eventCookie {};
    check_hresult(WINRT_SHIM(IPrint3DWorkflow)->add_PrintRequested(get_abi(eventHandler), &eventCookie));
    return eventCookie;
}

template <typename D> event_revoker<IPrint3DWorkflow> impl_IPrint3DWorkflow<D>::PrintRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrintRequestedEventArgs> & eventHandler) const
{
    return impl::make_event_revoker<D, IPrint3DWorkflow>(this, &ABI::Windows::Devices::Printers::Extensions::IPrint3DWorkflow::remove_PrintRequested, PrintRequested(eventHandler));
}

template <typename D> void impl_IPrint3DWorkflow<D>::PrintRequested(event_token eventCookie) const
{
    check_hresult(WINRT_SHIM(IPrint3DWorkflow)->remove_PrintRequested(eventCookie));
}

template <typename D> event_token impl_IPrint3DWorkflow2<D>::PrinterChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrinterChangedEventArgs> & eventHandler) const
{
    event_token eventCookie {};
    check_hresult(WINRT_SHIM(IPrint3DWorkflow2)->add_PrinterChanged(get_abi(eventHandler), &eventCookie));
    return eventCookie;
}

template <typename D> event_revoker<IPrint3DWorkflow2> impl_IPrint3DWorkflow2<D>::PrinterChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrinterChangedEventArgs> & eventHandler) const
{
    return impl::make_event_revoker<D, IPrint3DWorkflow2>(this, &ABI::Windows::Devices::Printers::Extensions::IPrint3DWorkflow2::remove_PrinterChanged, PrinterChanged(eventHandler));
}

template <typename D> void impl_IPrint3DWorkflow2<D>::PrinterChanged(event_token eventCookie) const
{
    check_hresult(WINRT_SHIM(IPrint3DWorkflow2)->remove_PrinterChanged(eventCookie));
}

template <typename D> void impl_IPrintTaskConfigurationSaveRequestedDeferral<D>::Complete() const
{
    check_hresult(WINRT_SHIM(IPrintTaskConfigurationSaveRequestedDeferral)->abi_Complete());
}

template <typename D> void impl_IPrintTaskConfigurationSaveRequest<D>::Cancel() const
{
    check_hresult(WINRT_SHIM(IPrintTaskConfigurationSaveRequest)->abi_Cancel());
}

template <typename D> void impl_IPrintTaskConfigurationSaveRequest<D>::Save(const Windows::Foundation::IInspectable & printerExtensionContext) const
{
    check_hresult(WINRT_SHIM(IPrintTaskConfigurationSaveRequest)->abi_Save(get_abi(printerExtensionContext)));
}

template <typename D> Windows::Devices::Printers::Extensions::PrintTaskConfigurationSaveRequestedDeferral impl_IPrintTaskConfigurationSaveRequest<D>::GetDeferral() const
{
    Windows::Devices::Printers::Extensions::PrintTaskConfigurationSaveRequestedDeferral deferral { nullptr };
    check_hresult(WINRT_SHIM(IPrintTaskConfigurationSaveRequest)->abi_GetDeferral(put_abi(deferral)));
    return deferral;
}

template <typename D> Windows::Foundation::DateTime impl_IPrintTaskConfigurationSaveRequest<D>::Deadline() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IPrintTaskConfigurationSaveRequest)->get_Deadline(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Printers::Extensions::PrintTaskConfigurationSaveRequest impl_IPrintTaskConfigurationSaveRequestedEventArgs<D>::Request() const
{
    Windows::Devices::Printers::Extensions::PrintTaskConfigurationSaveRequest context { nullptr };
    check_hresult(WINRT_SHIM(IPrintTaskConfigurationSaveRequestedEventArgs)->get_Request(put_abi(context)));
    return context;
}

template <typename D> Windows::Foundation::IInspectable impl_IPrintTaskConfiguration<D>::PrinterExtensionContext() const
{
    Windows::Foundation::IInspectable context;
    check_hresult(WINRT_SHIM(IPrintTaskConfiguration)->get_PrinterExtensionContext(put_abi(context)));
    return context;
}

template <typename D> event_token impl_IPrintTaskConfiguration<D>::SaveRequested(const Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::PrintTaskConfiguration, Windows::Devices::Printers::Extensions::PrintTaskConfigurationSaveRequestedEventArgs> & eventHandler) const
{
    event_token eventCookie {};
    check_hresult(WINRT_SHIM(IPrintTaskConfiguration)->add_SaveRequested(get_abi(eventHandler), &eventCookie));
    return eventCookie;
}

template <typename D> event_revoker<IPrintTaskConfiguration> impl_IPrintTaskConfiguration<D>::SaveRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::PrintTaskConfiguration, Windows::Devices::Printers::Extensions::PrintTaskConfigurationSaveRequestedEventArgs> & eventHandler) const
{
    return impl::make_event_revoker<D, IPrintTaskConfiguration>(this, &ABI::Windows::Devices::Printers::Extensions::IPrintTaskConfiguration::remove_SaveRequested, SaveRequested(eventHandler));
}

template <typename D> void impl_IPrintTaskConfiguration<D>::SaveRequested(event_token eventCookie) const
{
    check_hresult(WINRT_SHIM(IPrintTaskConfiguration)->remove_SaveRequested(eventCookie));
}

template <typename D> hstring impl_IPrintNotificationEventDetails<D>::PrinterName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPrintNotificationEventDetails)->get_PrinterName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IPrintNotificationEventDetails<D>::EventData() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPrintNotificationEventDetails)->get_EventData(put_abi(value)));
    return value;
}

template <typename D> void impl_IPrintNotificationEventDetails<D>::EventData(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPrintNotificationEventDetails)->put_EventData(get_abi(value)));
}

template <typename D> Windows::Foundation::IInspectable impl_IPrintExtensionContextStatic<D>::FromDeviceId(hstring_view deviceId) const
{
    Windows::Foundation::IInspectable context;
    check_hresult(WINRT_SHIM(IPrintExtensionContextStatic)->abi_FromDeviceId(get_abi(deviceId), put_abi(context)));
    return context;
}

inline Windows::Foundation::IInspectable PrintExtensionContext::FromDeviceId(hstring_view deviceId)
{
    return get_activation_factory<PrintExtensionContext, IPrintExtensionContextStatic>().FromDeviceId(deviceId);
}

}

}
#pragma warning(pop)
