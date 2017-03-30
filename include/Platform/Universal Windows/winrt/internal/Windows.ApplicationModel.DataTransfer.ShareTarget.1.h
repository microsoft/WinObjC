// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.ApplicationModel.DataTransfer.ShareTarget.0.h"
#include "Windows.ApplicationModel.DataTransfer.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::DataTransfer::ShareTarget {

struct __declspec(uuid("603e4308-f0be-4adc-acc9-8b27ab9cf556")) __declspec(novtable) IQuickLink : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Title(hstring * value) = 0;
    virtual HRESULT __stdcall put_Title(hstring value) = 0;
    virtual HRESULT __stdcall get_Thumbnail(Windows::Storage::Streams::IRandomAccessStreamReference ** value) = 0;
    virtual HRESULT __stdcall put_Thumbnail(Windows::Storage::Streams::IRandomAccessStreamReference * value) = 0;
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall put_Id(hstring value) = 0;
    virtual HRESULT __stdcall get_SupportedDataFormats(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_SupportedFileTypes(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
};

struct __declspec(uuid("2246bab8-d0f8-41c1-a82a-4137db6504fb")) __declspec(novtable) IShareOperation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Data(Windows::ApplicationModel::DataTransfer::IDataPackageView ** value) = 0;
    virtual HRESULT __stdcall get_QuickLinkId(hstring * value) = 0;
    virtual HRESULT __stdcall abi_RemoveThisQuickLink() = 0;
    virtual HRESULT __stdcall abi_ReportStarted() = 0;
    virtual HRESULT __stdcall abi_ReportDataRetrieved() = 0;
    virtual HRESULT __stdcall abi_ReportSubmittedBackgroundTask() = 0;
    virtual HRESULT __stdcall abi_ReportCompletedWithQuickLink(Windows::ApplicationModel::DataTransfer::ShareTarget::IQuickLink * quicklink) = 0;
    virtual HRESULT __stdcall abi_ReportCompleted() = 0;
    virtual HRESULT __stdcall abi_ReportError(hstring value) = 0;
};

struct __declspec(uuid("0ffb97c1-9778-4a09-8e5b-cb5e482d0555")) __declspec(novtable) IShareOperation2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_DismissUI() = 0;
};

}

namespace ABI {

template <> struct traits<Windows::ApplicationModel::DataTransfer::ShareTarget::QuickLink> { using default_interface = Windows::ApplicationModel::DataTransfer::ShareTarget::IQuickLink; };
template <> struct traits<Windows::ApplicationModel::DataTransfer::ShareTarget::ShareOperation> { using default_interface = Windows::ApplicationModel::DataTransfer::ShareTarget::IShareOperation; };

}

namespace Windows::ApplicationModel::DataTransfer::ShareTarget {

template <typename D>
struct WINRT_EBO impl_IQuickLink
{
    hstring Title() const;
    void Title(hstring_view value) const;
    Windows::Storage::Streams::RandomAccessStreamReference Thumbnail() const;
    void Thumbnail(const Windows::Storage::Streams::RandomAccessStreamReference & value) const;
    hstring Id() const;
    void Id(hstring_view value) const;
    Windows::Foundation::Collections::IVector<hstring> SupportedDataFormats() const;
    Windows::Foundation::Collections::IVector<hstring> SupportedFileTypes() const;
};

template <typename D>
struct WINRT_EBO impl_IShareOperation
{
    Windows::ApplicationModel::DataTransfer::DataPackageView Data() const;
    hstring QuickLinkId() const;
    void RemoveThisQuickLink() const;
    [[deprecated("ReportStarted is deprecated and might not work on all platforms. For more info, see MSDN.")]] void ReportStarted() const;
    void ReportDataRetrieved() const;
    [[deprecated("ReportSubmittedBackgroundTask is deprecated and might not work on all platforms. For more info, see MSDN.")]] void ReportSubmittedBackgroundTask() const;
    void ReportCompleted(const Windows::ApplicationModel::DataTransfer::ShareTarget::QuickLink & quicklink) const;
    void ReportCompleted() const;
    [[deprecated("ReportError is deprecated and might not work on all platforms. For more info, see MSDN.")]] void ReportError(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IShareOperation2
{
    [[deprecated("DismissUI is deprecated and might not work on all platforms. For more info, see MSDN.")]] void DismissUI() const;
};

}

namespace impl {

template <> struct traits<Windows::ApplicationModel::DataTransfer::ShareTarget::IQuickLink>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::ShareTarget::IQuickLink;
    template <typename D> using consume = Windows::ApplicationModel::DataTransfer::ShareTarget::impl_IQuickLink<D>;
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::ShareTarget::IShareOperation>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::ShareTarget::IShareOperation;
    template <typename D> using consume = Windows::ApplicationModel::DataTransfer::ShareTarget::impl_IShareOperation<D>;
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::ShareTarget::IShareOperation2>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::ShareTarget::IShareOperation2;
    template <typename D> using consume = Windows::ApplicationModel::DataTransfer::ShareTarget::impl_IShareOperation2<D>;
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::ShareTarget::QuickLink>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::ShareTarget::QuickLink;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.DataTransfer.ShareTarget.QuickLink"; }
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::ShareTarget::ShareOperation>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::ShareTarget::ShareOperation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.DataTransfer.ShareTarget.ShareOperation"; }
};

}

}
