// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Graphics.Printing.0.h"
#include "Windows.ApplicationModel.DataTransfer.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Graphics::Printing {

struct PrintPageDescription
{
    Windows::Foundation::Size PageSize;
    Windows::Foundation::Rect ImageableRect;
    uint32_t DpiX;
    uint32_t DpiY;
};

}

namespace Windows::Graphics::Printing {

using PrintPageDescription = ABI::Windows::Graphics::Printing::PrintPageDescription;

}

namespace ABI::Windows::Graphics::Printing {

struct __declspec(uuid("dedc0c30-f1eb-47df-aae6-ed5427511f01")) __declspec(novtable) IPrintDocumentSource : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("ff2a9694-8c99-44fd-ae4a-19d9aa9a0f0a")) __declspec(novtable) IPrintManager : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_PrintTaskRequested(Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing::PrintManager, Windows::Graphics::Printing::PrintTaskRequestedEventArgs> * eventHandler, event_token * eventCookie) = 0;
    virtual HRESULT __stdcall remove_PrintTaskRequested(event_token eventCookie) = 0;
};

struct __declspec(uuid("58185dcd-e634-4654-84f0-e0152a8217ac")) __declspec(novtable) IPrintManagerStatic : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetForCurrentView(Windows::Graphics::Printing::IPrintManager ** printingManager) = 0;
    virtual HRESULT __stdcall abi_ShowPrintUIAsync(Windows::Foundation::IAsyncOperation<bool> ** operation) = 0;
};

struct __declspec(uuid("35a99955-e6ab-4139-9abd-b86a729b3598")) __declspec(novtable) IPrintManagerStatic2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_IsSupported(bool * result) = 0;
};

struct __declspec(uuid("dd4be9c9-a6a1-4ada-930e-da872a4f23d3")) __declspec(novtable) IPrintPageInfo : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_MediaSize(winrt::Windows::Graphics::Printing::PrintMediaSize value) = 0;
    virtual HRESULT __stdcall get_MediaSize(winrt::Windows::Graphics::Printing::PrintMediaSize * value) = 0;
    virtual HRESULT __stdcall put_PageSize(Windows::Foundation::Size value) = 0;
    virtual HRESULT __stdcall get_PageSize(Windows::Foundation::Size * value) = 0;
    virtual HRESULT __stdcall put_DpiX(uint32_t value) = 0;
    virtual HRESULT __stdcall get_DpiX(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_DpiY(uint32_t value) = 0;
    virtual HRESULT __stdcall get_DpiY(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_Orientation(winrt::Windows::Graphics::Printing::PrintOrientation value) = 0;
    virtual HRESULT __stdcall get_Orientation(winrt::Windows::Graphics::Printing::PrintOrientation * value) = 0;
};

struct __declspec(uuid("61d80247-6cf6-4fad-84e2-a5e82e2d4ceb")) __declspec(novtable) IPrintTask : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Properties(Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet ** value) = 0;
    virtual HRESULT __stdcall get_Source(Windows::Graphics::Printing::IPrintDocumentSource ** value) = 0;
    virtual HRESULT __stdcall get_Options(Windows::Graphics::Printing::IPrintTaskOptionsCore ** value) = 0;
    virtual HRESULT __stdcall add_Previewing(Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing::PrintTask, Windows::Foundation::IInspectable> * eventHandler, event_token * eventCookie) = 0;
    virtual HRESULT __stdcall remove_Previewing(event_token eventCookie) = 0;
    virtual HRESULT __stdcall add_Submitting(Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing::PrintTask, Windows::Foundation::IInspectable> * eventHandler, event_token * eventCookie) = 0;
    virtual HRESULT __stdcall remove_Submitting(event_token eventCookie) = 0;
    virtual HRESULT __stdcall add_Progressing(Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing::PrintTask, Windows::Graphics::Printing::PrintTaskProgressingEventArgs> * eventHandler, event_token * eventCookie) = 0;
    virtual HRESULT __stdcall remove_Progressing(event_token eventCookie) = 0;
    virtual HRESULT __stdcall add_Completed(Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing::PrintTask, Windows::Graphics::Printing::PrintTaskCompletedEventArgs> * eventHandler, event_token * eventCookie) = 0;
    virtual HRESULT __stdcall remove_Completed(event_token eventCookie) = 0;
};

struct __declspec(uuid("36234877-3e53-4d9d-8f5e-316ac8dedae1")) __declspec(novtable) IPrintTask2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_IsPreviewEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsPreviewEnabled(bool * value) = 0;
};

struct __declspec(uuid("5bcd34af-24e9-4c10-8d07-14c346ba3fce")) __declspec(novtable) IPrintTaskCompletedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Completion(winrt::Windows::Graphics::Printing::PrintTaskCompletion * value) = 0;
};

struct __declspec(uuid("5a0a66bb-d289-41bb-96dd-57e28338ae3f")) __declspec(novtable) IPrintTaskOptions : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_Bordering(winrt::Windows::Graphics::Printing::PrintBordering value) = 0;
    virtual HRESULT __stdcall get_Bordering(winrt::Windows::Graphics::Printing::PrintBordering * value) = 0;
    virtual HRESULT __stdcall abi_GetPagePrintTicket(Windows::Graphics::Printing::IPrintPageInfo * printPageInfo, Windows::Storage::Streams::IRandomAccessStream ** printTicket) = 0;
};

struct __declspec(uuid("1bdbb474-4ed1-41eb-be3c-72d18ed67337")) __declspec(novtable) IPrintTaskOptionsCore : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetPageDescription(uint32_t jobPageNumber, Windows::Graphics::Printing::PrintPageDescription * description) = 0;
};

struct __declspec(uuid("c1b71832-9e93-4e55-814b-3326a59efce1")) __declspec(novtable) IPrintTaskOptionsCoreProperties : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_MediaSize(winrt::Windows::Graphics::Printing::PrintMediaSize value) = 0;
    virtual HRESULT __stdcall get_MediaSize(winrt::Windows::Graphics::Printing::PrintMediaSize * value) = 0;
    virtual HRESULT __stdcall put_MediaType(winrt::Windows::Graphics::Printing::PrintMediaType value) = 0;
    virtual HRESULT __stdcall get_MediaType(winrt::Windows::Graphics::Printing::PrintMediaType * value) = 0;
    virtual HRESULT __stdcall put_Orientation(winrt::Windows::Graphics::Printing::PrintOrientation value) = 0;
    virtual HRESULT __stdcall get_Orientation(winrt::Windows::Graphics::Printing::PrintOrientation * value) = 0;
    virtual HRESULT __stdcall put_PrintQuality(winrt::Windows::Graphics::Printing::PrintQuality value) = 0;
    virtual HRESULT __stdcall get_PrintQuality(winrt::Windows::Graphics::Printing::PrintQuality * value) = 0;
    virtual HRESULT __stdcall put_ColorMode(winrt::Windows::Graphics::Printing::PrintColorMode value) = 0;
    virtual HRESULT __stdcall get_ColorMode(winrt::Windows::Graphics::Printing::PrintColorMode * value) = 0;
    virtual HRESULT __stdcall put_Duplex(winrt::Windows::Graphics::Printing::PrintDuplex value) = 0;
    virtual HRESULT __stdcall get_Duplex(winrt::Windows::Graphics::Printing::PrintDuplex * value) = 0;
    virtual HRESULT __stdcall put_Collation(winrt::Windows::Graphics::Printing::PrintCollation value) = 0;
    virtual HRESULT __stdcall get_Collation(winrt::Windows::Graphics::Printing::PrintCollation * value) = 0;
    virtual HRESULT __stdcall put_Staple(winrt::Windows::Graphics::Printing::PrintStaple value) = 0;
    virtual HRESULT __stdcall get_Staple(winrt::Windows::Graphics::Printing::PrintStaple * value) = 0;
    virtual HRESULT __stdcall put_HolePunch(winrt::Windows::Graphics::Printing::PrintHolePunch value) = 0;
    virtual HRESULT __stdcall get_HolePunch(winrt::Windows::Graphics::Printing::PrintHolePunch * value) = 0;
    virtual HRESULT __stdcall put_Binding(winrt::Windows::Graphics::Printing::PrintBinding value) = 0;
    virtual HRESULT __stdcall get_Binding(winrt::Windows::Graphics::Printing::PrintBinding * value) = 0;
    virtual HRESULT __stdcall get_MinCopies(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_MaxCopies(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_NumberOfCopies(uint32_t value) = 0;
    virtual HRESULT __stdcall get_NumberOfCopies(uint32_t * value) = 0;
};

struct __declspec(uuid("62e69e23-9a1e-4336-b74f-3cc7f4cff709")) __declspec(novtable) IPrintTaskOptionsCoreUIConfiguration : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DisplayedOptions(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
};

struct __declspec(uuid("810cd3cb-b410-4282-a073-5ac378234174")) __declspec(novtable) IPrintTaskProgressingEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DocumentPageCount(uint32_t * value) = 0;
};

struct __declspec(uuid("6ff61e2e-2722-4240-a67c-f364849a17f3")) __declspec(novtable) IPrintTaskRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Deadline(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall abi_CreatePrintTask(hstring title, Windows::Graphics::Printing::PrintTaskSourceRequestedHandler * handler, Windows::Graphics::Printing::IPrintTask ** task) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Graphics::Printing::IPrintTaskRequestedDeferral ** deferral) = 0;
};

struct __declspec(uuid("cfefb3f0-ce3e-42c7-9496-64800c622c44")) __declspec(novtable) IPrintTaskRequestedDeferral : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Complete() = 0;
};

struct __declspec(uuid("d0aff924-a31b-454c-a7b6-5d0cc522fc16")) __declspec(novtable) IPrintTaskRequestedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Request(Windows::Graphics::Printing::IPrintTaskRequest ** value) = 0;
};

struct __declspec(uuid("f9f067be-f456-41f0-9c98-5ce73e851410")) __declspec(novtable) IPrintTaskSourceRequestedArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Deadline(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall abi_SetSource(Windows::Graphics::Printing::IPrintDocumentSource * source) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Graphics::Printing::IPrintTaskSourceRequestedDeferral ** deferral) = 0;
};

struct __declspec(uuid("4a1560d1-6992-4d9d-8555-4ca4563fb166")) __declspec(novtable) IPrintTaskSourceRequestedDeferral : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Complete() = 0;
};

struct __declspec(uuid("295d70c0-c2cb-4b7d-b0ea-93095091a220")) __declspec(novtable) IPrintTaskTargetDeviceSupport : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_IsPrinterTargetEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsPrinterTargetEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_Is3DManufacturingTargetEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_Is3DManufacturingTargetEnabled(bool * value) = 0;
};

struct __declspec(uuid("b4483d26-0dd0-4cd4-baff-930fc7d6a574")) __declspec(novtable) IStandardPrintTaskOptionsStatic : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MediaSize(hstring * value) = 0;
    virtual HRESULT __stdcall get_MediaType(hstring * value) = 0;
    virtual HRESULT __stdcall get_Orientation(hstring * value) = 0;
    virtual HRESULT __stdcall get_PrintQuality(hstring * value) = 0;
    virtual HRESULT __stdcall get_ColorMode(hstring * value) = 0;
    virtual HRESULT __stdcall get_Duplex(hstring * value) = 0;
    virtual HRESULT __stdcall get_Collation(hstring * value) = 0;
    virtual HRESULT __stdcall get_Staple(hstring * value) = 0;
    virtual HRESULT __stdcall get_HolePunch(hstring * value) = 0;
    virtual HRESULT __stdcall get_Binding(hstring * value) = 0;
    virtual HRESULT __stdcall get_Copies(hstring * value) = 0;
    virtual HRESULT __stdcall get_NUp(hstring * value) = 0;
    virtual HRESULT __stdcall get_InputBin(hstring * value) = 0;
};

struct __declspec(uuid("3be38bf4-7a44-4269-9a52-81261e289ee9")) __declspec(novtable) IStandardPrintTaskOptionsStatic2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Bordering(hstring * value) = 0;
};

struct __declspec(uuid("6c109fa8-5cb6-4b3a-8663-f39cb02dc9b4")) __declspec(novtable) PrintTaskSourceRequestedHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Graphics::Printing::IPrintTaskSourceRequestedArgs * args) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Graphics::Printing::PrintManager> { using default_interface = Windows::Graphics::Printing::IPrintManager; };
template <> struct traits<Windows::Graphics::Printing::PrintPageInfo> { using default_interface = Windows::Graphics::Printing::IPrintPageInfo; };
template <> struct traits<Windows::Graphics::Printing::PrintTask> { using default_interface = Windows::Graphics::Printing::IPrintTask; };
template <> struct traits<Windows::Graphics::Printing::PrintTaskCompletedEventArgs> { using default_interface = Windows::Graphics::Printing::IPrintTaskCompletedEventArgs; };
template <> struct traits<Windows::Graphics::Printing::PrintTaskOptions> { using default_interface = Windows::Graphics::Printing::IPrintTaskOptionsCore; };
template <> struct traits<Windows::Graphics::Printing::PrintTaskProgressingEventArgs> { using default_interface = Windows::Graphics::Printing::IPrintTaskProgressingEventArgs; };
template <> struct traits<Windows::Graphics::Printing::PrintTaskRequest> { using default_interface = Windows::Graphics::Printing::IPrintTaskRequest; };
template <> struct traits<Windows::Graphics::Printing::PrintTaskRequestedDeferral> { using default_interface = Windows::Graphics::Printing::IPrintTaskRequestedDeferral; };
template <> struct traits<Windows::Graphics::Printing::PrintTaskRequestedEventArgs> { using default_interface = Windows::Graphics::Printing::IPrintTaskRequestedEventArgs; };
template <> struct traits<Windows::Graphics::Printing::PrintTaskSourceRequestedArgs> { using default_interface = Windows::Graphics::Printing::IPrintTaskSourceRequestedArgs; };
template <> struct traits<Windows::Graphics::Printing::PrintTaskSourceRequestedDeferral> { using default_interface = Windows::Graphics::Printing::IPrintTaskSourceRequestedDeferral; };

}

namespace Windows::Graphics::Printing {

template <typename D>
struct WINRT_EBO impl_IPrintDocumentSource
{
};

template <typename D>
struct WINRT_EBO impl_IPrintManager
{
    event_token PrintTaskRequested(const Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing::PrintManager, Windows::Graphics::Printing::PrintTaskRequestedEventArgs> & eventHandler) const;
    using PrintTaskRequested_revoker = event_revoker<IPrintManager>;
    PrintTaskRequested_revoker PrintTaskRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing::PrintManager, Windows::Graphics::Printing::PrintTaskRequestedEventArgs> & eventHandler) const;
    void PrintTaskRequested(event_token eventCookie) const;
};

template <typename D>
struct WINRT_EBO impl_IPrintManagerStatic
{
    Windows::Graphics::Printing::PrintManager GetForCurrentView() const;
    Windows::Foundation::IAsyncOperation<bool> ShowPrintUIAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IPrintManagerStatic2
{
    bool IsSupported() const;
};

template <typename D>
struct WINRT_EBO impl_IPrintPageInfo
{
    void MediaSize(Windows::Graphics::Printing::PrintMediaSize value) const;
    Windows::Graphics::Printing::PrintMediaSize MediaSize() const;
    void PageSize(const Windows::Foundation::Size & value) const;
    Windows::Foundation::Size PageSize() const;
    void DpiX(uint32_t value) const;
    uint32_t DpiX() const;
    void DpiY(uint32_t value) const;
    uint32_t DpiY() const;
    void Orientation(Windows::Graphics::Printing::PrintOrientation value) const;
    Windows::Graphics::Printing::PrintOrientation Orientation() const;
};

template <typename D>
struct WINRT_EBO impl_IPrintTask
{
    Windows::ApplicationModel::DataTransfer::DataPackagePropertySet Properties() const;
    Windows::Graphics::Printing::IPrintDocumentSource Source() const;
    Windows::Graphics::Printing::PrintTaskOptions Options() const;
    event_token Previewing(const Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing::PrintTask, Windows::Foundation::IInspectable> & eventHandler) const;
    using Previewing_revoker = event_revoker<IPrintTask>;
    Previewing_revoker Previewing(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing::PrintTask, Windows::Foundation::IInspectable> & eventHandler) const;
    void Previewing(event_token eventCookie) const;
    event_token Submitting(const Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing::PrintTask, Windows::Foundation::IInspectable> & eventHandler) const;
    using Submitting_revoker = event_revoker<IPrintTask>;
    Submitting_revoker Submitting(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing::PrintTask, Windows::Foundation::IInspectable> & eventHandler) const;
    void Submitting(event_token eventCookie) const;
    event_token Progressing(const Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing::PrintTask, Windows::Graphics::Printing::PrintTaskProgressingEventArgs> & eventHandler) const;
    using Progressing_revoker = event_revoker<IPrintTask>;
    Progressing_revoker Progressing(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing::PrintTask, Windows::Graphics::Printing::PrintTaskProgressingEventArgs> & eventHandler) const;
    void Progressing(event_token eventCookie) const;
    event_token Completed(const Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing::PrintTask, Windows::Graphics::Printing::PrintTaskCompletedEventArgs> & eventHandler) const;
    using Completed_revoker = event_revoker<IPrintTask>;
    Completed_revoker Completed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing::PrintTask, Windows::Graphics::Printing::PrintTaskCompletedEventArgs> & eventHandler) const;
    void Completed(event_token eventCookie) const;
};

template <typename D>
struct WINRT_EBO impl_IPrintTask2
{
    void IsPreviewEnabled(bool value) const;
    bool IsPreviewEnabled() const;
};

template <typename D>
struct WINRT_EBO impl_IPrintTaskCompletedEventArgs
{
    Windows::Graphics::Printing::PrintTaskCompletion Completion() const;
};

template <typename D>
struct WINRT_EBO impl_IPrintTaskOptions
{
    void Bordering(Windows::Graphics::Printing::PrintBordering value) const;
    Windows::Graphics::Printing::PrintBordering Bordering() const;
    Windows::Storage::Streams::IRandomAccessStream GetPagePrintTicket(const Windows::Graphics::Printing::PrintPageInfo & printPageInfo) const;
};

template <typename D>
struct WINRT_EBO impl_IPrintTaskOptionsCore
{
    Windows::Graphics::Printing::PrintPageDescription GetPageDescription(uint32_t jobPageNumber) const;
};

template <typename D>
struct WINRT_EBO impl_IPrintTaskOptionsCoreProperties
{
    void MediaSize(Windows::Graphics::Printing::PrintMediaSize value) const;
    Windows::Graphics::Printing::PrintMediaSize MediaSize() const;
    void MediaType(Windows::Graphics::Printing::PrintMediaType value) const;
    Windows::Graphics::Printing::PrintMediaType MediaType() const;
    void Orientation(Windows::Graphics::Printing::PrintOrientation value) const;
    Windows::Graphics::Printing::PrintOrientation Orientation() const;
    void PrintQuality(Windows::Graphics::Printing::PrintQuality value) const;
    Windows::Graphics::Printing::PrintQuality PrintQuality() const;
    void ColorMode(Windows::Graphics::Printing::PrintColorMode value) const;
    Windows::Graphics::Printing::PrintColorMode ColorMode() const;
    void Duplex(Windows::Graphics::Printing::PrintDuplex value) const;
    Windows::Graphics::Printing::PrintDuplex Duplex() const;
    void Collation(Windows::Graphics::Printing::PrintCollation value) const;
    Windows::Graphics::Printing::PrintCollation Collation() const;
    void Staple(Windows::Graphics::Printing::PrintStaple value) const;
    Windows::Graphics::Printing::PrintStaple Staple() const;
    void HolePunch(Windows::Graphics::Printing::PrintHolePunch value) const;
    Windows::Graphics::Printing::PrintHolePunch HolePunch() const;
    void Binding(Windows::Graphics::Printing::PrintBinding value) const;
    Windows::Graphics::Printing::PrintBinding Binding() const;
    uint32_t MinCopies() const;
    uint32_t MaxCopies() const;
    void NumberOfCopies(uint32_t value) const;
    uint32_t NumberOfCopies() const;
};

template <typename D>
struct WINRT_EBO impl_IPrintTaskOptionsCoreUIConfiguration
{
    Windows::Foundation::Collections::IVector<hstring> DisplayedOptions() const;
};

template <typename D>
struct WINRT_EBO impl_IPrintTaskProgressingEventArgs
{
    uint32_t DocumentPageCount() const;
};

template <typename D>
struct WINRT_EBO impl_IPrintTaskRequest
{
    Windows::Foundation::DateTime Deadline() const;
    Windows::Graphics::Printing::PrintTask CreatePrintTask(hstring_view title, const Windows::Graphics::Printing::PrintTaskSourceRequestedHandler & handler) const;
    Windows::Graphics::Printing::PrintTaskRequestedDeferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IPrintTaskRequestedDeferral
{
    void Complete() const;
};

template <typename D>
struct WINRT_EBO impl_IPrintTaskRequestedEventArgs
{
    Windows::Graphics::Printing::PrintTaskRequest Request() const;
};

template <typename D>
struct WINRT_EBO impl_IPrintTaskSourceRequestedArgs
{
    Windows::Foundation::DateTime Deadline() const;
    void SetSource(const Windows::Graphics::Printing::IPrintDocumentSource & source) const;
    Windows::Graphics::Printing::PrintTaskSourceRequestedDeferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IPrintTaskSourceRequestedDeferral
{
    void Complete() const;
};

template <typename D>
struct WINRT_EBO impl_IPrintTaskTargetDeviceSupport
{
    void IsPrinterTargetEnabled(bool value) const;
    bool IsPrinterTargetEnabled() const;
    void Is3DManufacturingTargetEnabled(bool value) const;
    bool Is3DManufacturingTargetEnabled() const;
};

template <typename D>
struct WINRT_EBO impl_IStandardPrintTaskOptionsStatic
{
    hstring MediaSize() const;
    hstring MediaType() const;
    hstring Orientation() const;
    hstring PrintQuality() const;
    hstring ColorMode() const;
    hstring Duplex() const;
    hstring Collation() const;
    hstring Staple() const;
    hstring HolePunch() const;
    hstring Binding() const;
    hstring Copies() const;
    hstring NUp() const;
    hstring InputBin() const;
};

template <typename D>
struct WINRT_EBO impl_IStandardPrintTaskOptionsStatic2
{
    hstring Bordering() const;
};

}

namespace impl {

template <> struct traits<Windows::Graphics::Printing::IPrintDocumentSource>
{
    using abi = ABI::Windows::Graphics::Printing::IPrintDocumentSource;
    template <typename D> using consume = Windows::Graphics::Printing::impl_IPrintDocumentSource<D>;
};

template <> struct traits<Windows::Graphics::Printing::IPrintManager>
{
    using abi = ABI::Windows::Graphics::Printing::IPrintManager;
    template <typename D> using consume = Windows::Graphics::Printing::impl_IPrintManager<D>;
};

template <> struct traits<Windows::Graphics::Printing::IPrintManagerStatic>
{
    using abi = ABI::Windows::Graphics::Printing::IPrintManagerStatic;
    template <typename D> using consume = Windows::Graphics::Printing::impl_IPrintManagerStatic<D>;
};

template <> struct traits<Windows::Graphics::Printing::IPrintManagerStatic2>
{
    using abi = ABI::Windows::Graphics::Printing::IPrintManagerStatic2;
    template <typename D> using consume = Windows::Graphics::Printing::impl_IPrintManagerStatic2<D>;
};

template <> struct traits<Windows::Graphics::Printing::IPrintPageInfo>
{
    using abi = ABI::Windows::Graphics::Printing::IPrintPageInfo;
    template <typename D> using consume = Windows::Graphics::Printing::impl_IPrintPageInfo<D>;
};

template <> struct traits<Windows::Graphics::Printing::IPrintTask>
{
    using abi = ABI::Windows::Graphics::Printing::IPrintTask;
    template <typename D> using consume = Windows::Graphics::Printing::impl_IPrintTask<D>;
};

template <> struct traits<Windows::Graphics::Printing::IPrintTask2>
{
    using abi = ABI::Windows::Graphics::Printing::IPrintTask2;
    template <typename D> using consume = Windows::Graphics::Printing::impl_IPrintTask2<D>;
};

template <> struct traits<Windows::Graphics::Printing::IPrintTaskCompletedEventArgs>
{
    using abi = ABI::Windows::Graphics::Printing::IPrintTaskCompletedEventArgs;
    template <typename D> using consume = Windows::Graphics::Printing::impl_IPrintTaskCompletedEventArgs<D>;
};

template <> struct traits<Windows::Graphics::Printing::IPrintTaskOptions>
{
    using abi = ABI::Windows::Graphics::Printing::IPrintTaskOptions;
    template <typename D> using consume = Windows::Graphics::Printing::impl_IPrintTaskOptions<D>;
};

template <> struct traits<Windows::Graphics::Printing::IPrintTaskOptionsCore>
{
    using abi = ABI::Windows::Graphics::Printing::IPrintTaskOptionsCore;
    template <typename D> using consume = Windows::Graphics::Printing::impl_IPrintTaskOptionsCore<D>;
};

template <> struct traits<Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>
{
    using abi = ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties;
    template <typename D> using consume = Windows::Graphics::Printing::impl_IPrintTaskOptionsCoreProperties<D>;
};

template <> struct traits<Windows::Graphics::Printing::IPrintTaskOptionsCoreUIConfiguration>
{
    using abi = ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreUIConfiguration;
    template <typename D> using consume = Windows::Graphics::Printing::impl_IPrintTaskOptionsCoreUIConfiguration<D>;
};

template <> struct traits<Windows::Graphics::Printing::IPrintTaskProgressingEventArgs>
{
    using abi = ABI::Windows::Graphics::Printing::IPrintTaskProgressingEventArgs;
    template <typename D> using consume = Windows::Graphics::Printing::impl_IPrintTaskProgressingEventArgs<D>;
};

template <> struct traits<Windows::Graphics::Printing::IPrintTaskRequest>
{
    using abi = ABI::Windows::Graphics::Printing::IPrintTaskRequest;
    template <typename D> using consume = Windows::Graphics::Printing::impl_IPrintTaskRequest<D>;
};

template <> struct traits<Windows::Graphics::Printing::IPrintTaskRequestedDeferral>
{
    using abi = ABI::Windows::Graphics::Printing::IPrintTaskRequestedDeferral;
    template <typename D> using consume = Windows::Graphics::Printing::impl_IPrintTaskRequestedDeferral<D>;
};

template <> struct traits<Windows::Graphics::Printing::IPrintTaskRequestedEventArgs>
{
    using abi = ABI::Windows::Graphics::Printing::IPrintTaskRequestedEventArgs;
    template <typename D> using consume = Windows::Graphics::Printing::impl_IPrintTaskRequestedEventArgs<D>;
};

template <> struct traits<Windows::Graphics::Printing::IPrintTaskSourceRequestedArgs>
{
    using abi = ABI::Windows::Graphics::Printing::IPrintTaskSourceRequestedArgs;
    template <typename D> using consume = Windows::Graphics::Printing::impl_IPrintTaskSourceRequestedArgs<D>;
};

template <> struct traits<Windows::Graphics::Printing::IPrintTaskSourceRequestedDeferral>
{
    using abi = ABI::Windows::Graphics::Printing::IPrintTaskSourceRequestedDeferral;
    template <typename D> using consume = Windows::Graphics::Printing::impl_IPrintTaskSourceRequestedDeferral<D>;
};

template <> struct traits<Windows::Graphics::Printing::IPrintTaskTargetDeviceSupport>
{
    using abi = ABI::Windows::Graphics::Printing::IPrintTaskTargetDeviceSupport;
    template <typename D> using consume = Windows::Graphics::Printing::impl_IPrintTaskTargetDeviceSupport<D>;
};

template <> struct traits<Windows::Graphics::Printing::IStandardPrintTaskOptionsStatic>
{
    using abi = ABI::Windows::Graphics::Printing::IStandardPrintTaskOptionsStatic;
    template <typename D> using consume = Windows::Graphics::Printing::impl_IStandardPrintTaskOptionsStatic<D>;
};

template <> struct traits<Windows::Graphics::Printing::IStandardPrintTaskOptionsStatic2>
{
    using abi = ABI::Windows::Graphics::Printing::IStandardPrintTaskOptionsStatic2;
    template <typename D> using consume = Windows::Graphics::Printing::impl_IStandardPrintTaskOptionsStatic2<D>;
};

template <> struct traits<Windows::Graphics::Printing::PrintTaskSourceRequestedHandler>
{
    using abi = ABI::Windows::Graphics::Printing::PrintTaskSourceRequestedHandler;
};

template <> struct traits<Windows::Graphics::Printing::PrintManager>
{
    using abi = ABI::Windows::Graphics::Printing::PrintManager;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Printing.PrintManager"; }
};

template <> struct traits<Windows::Graphics::Printing::PrintPageInfo>
{
    using abi = ABI::Windows::Graphics::Printing::PrintPageInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Printing.PrintPageInfo"; }
};

template <> struct traits<Windows::Graphics::Printing::PrintTask>
{
    using abi = ABI::Windows::Graphics::Printing::PrintTask;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Printing.PrintTask"; }
};

template <> struct traits<Windows::Graphics::Printing::PrintTaskCompletedEventArgs>
{
    using abi = ABI::Windows::Graphics::Printing::PrintTaskCompletedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Printing.PrintTaskCompletedEventArgs"; }
};

template <> struct traits<Windows::Graphics::Printing::PrintTaskOptions>
{
    using abi = ABI::Windows::Graphics::Printing::PrintTaskOptions;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Printing.PrintTaskOptions"; }
};

template <> struct traits<Windows::Graphics::Printing::PrintTaskProgressingEventArgs>
{
    using abi = ABI::Windows::Graphics::Printing::PrintTaskProgressingEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Printing.PrintTaskProgressingEventArgs"; }
};

template <> struct traits<Windows::Graphics::Printing::PrintTaskRequest>
{
    using abi = ABI::Windows::Graphics::Printing::PrintTaskRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Printing.PrintTaskRequest"; }
};

template <> struct traits<Windows::Graphics::Printing::PrintTaskRequestedDeferral>
{
    using abi = ABI::Windows::Graphics::Printing::PrintTaskRequestedDeferral;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Printing.PrintTaskRequestedDeferral"; }
};

template <> struct traits<Windows::Graphics::Printing::PrintTaskRequestedEventArgs>
{
    using abi = ABI::Windows::Graphics::Printing::PrintTaskRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Printing.PrintTaskRequestedEventArgs"; }
};

template <> struct traits<Windows::Graphics::Printing::PrintTaskSourceRequestedArgs>
{
    using abi = ABI::Windows::Graphics::Printing::PrintTaskSourceRequestedArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Printing.PrintTaskSourceRequestedArgs"; }
};

template <> struct traits<Windows::Graphics::Printing::PrintTaskSourceRequestedDeferral>
{
    using abi = ABI::Windows::Graphics::Printing::PrintTaskSourceRequestedDeferral;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Printing.PrintTaskSourceRequestedDeferral"; }
};

template <> struct traits<Windows::Graphics::Printing::StandardPrintTaskOptions>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Printing.StandardPrintTaskOptions"; }
};

}

}
