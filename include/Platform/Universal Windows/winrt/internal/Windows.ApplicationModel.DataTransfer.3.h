// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.DataTransfer.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::DataTransfer {

template <typename H> struct impl_DataProviderHandler : implements<impl_DataProviderHandler<H>, abi<DataProviderHandler>>, H
{
    impl_DataProviderHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::ApplicationModel::DataTransfer::IDataProviderRequest> request) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::ApplicationModel::DataTransfer::DataProviderRequest *>(&request));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::ApplicationModel::DataTransfer {

struct Clipboard
{
    Clipboard() = delete;
    static Windows::ApplicationModel::DataTransfer::DataPackageView GetContent();
    static void SetContent(const Windows::ApplicationModel::DataTransfer::DataPackage & content);
    static void Flush();
    static void Clear();
    static event_token ContentChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & changeHandler);
    using ContentChanged_revoker = factory_event_revoker<IClipboardStatics>;
    static ContentChanged_revoker ContentChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & changeHandler);
    static void ContentChanged(event_token token);
};

struct WINRT_EBO DataPackage :
    Windows::ApplicationModel::DataTransfer::IDataPackage,
    impl::require<DataPackage, Windows::ApplicationModel::DataTransfer::IDataPackage2>
{
    DataPackage(std::nullptr_t) noexcept {}
    DataPackage();
};

struct WINRT_EBO DataPackagePropertySet :
    Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet,
    impl::require<DataPackagePropertySet, Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet2, Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet3>
{
    DataPackagePropertySet(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DataPackagePropertySetView :
    Windows::ApplicationModel::DataTransfer::IDataPackagePropertySetView,
    impl::require<DataPackagePropertySetView, Windows::ApplicationModel::DataTransfer::IDataPackagePropertySetView2, Windows::ApplicationModel::DataTransfer::IDataPackagePropertySetView3>
{
    DataPackagePropertySetView(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DataPackageView :
    Windows::ApplicationModel::DataTransfer::IDataPackageView,
    impl::require<DataPackageView, Windows::ApplicationModel::DataTransfer::IDataPackageView2, Windows::ApplicationModel::DataTransfer::IDataPackageView3, Windows::ApplicationModel::DataTransfer::IDataPackageView4>
{
    DataPackageView(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DataProviderDeferral :
    Windows::ApplicationModel::DataTransfer::IDataProviderDeferral
{
    DataProviderDeferral(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DataProviderRequest :
    Windows::ApplicationModel::DataTransfer::IDataProviderRequest
{
    DataProviderRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DataRequest :
    Windows::ApplicationModel::DataTransfer::IDataRequest
{
    DataRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DataRequestDeferral :
    Windows::ApplicationModel::DataTransfer::IDataRequestDeferral
{
    DataRequestDeferral(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DataRequestedEventArgs :
    Windows::ApplicationModel::DataTransfer::IDataRequestedEventArgs
{
    DataRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DataTransferManager :
    Windows::ApplicationModel::DataTransfer::IDataTransferManager
{
    DataTransferManager(std::nullptr_t) noexcept {}
    static void ShowShareUI();
    static Windows::ApplicationModel::DataTransfer::DataTransferManager GetForCurrentView();
    static bool IsSupported();
};

struct HtmlFormatHelper
{
    HtmlFormatHelper() = delete;
    static hstring GetStaticFragment(hstring_view htmlFormat);
    static hstring CreateHtmlFormat(hstring_view htmlFragment);
};

struct WINRT_EBO OperationCompletedEventArgs :
    Windows::ApplicationModel::DataTransfer::IOperationCompletedEventArgs,
    impl::require<OperationCompletedEventArgs, Windows::ApplicationModel::DataTransfer::IOperationCompletedEventArgs2>
{
    OperationCompletedEventArgs(std::nullptr_t) noexcept {}
};

struct SharedStorageAccessManager
{
    SharedStorageAccessManager() = delete;
    static hstring AddFile(const Windows::Storage::IStorageFile & file);
    static Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> RedeemTokenForFileAsync(hstring_view token);
    static void RemoveFile(hstring_view token);
};

struct StandardDataFormats
{
    StandardDataFormats() = delete;
    static hstring Text();
    [[deprecated("Uri may be altered or unavailable for releases after Windows Phone 'OSVersion' (TBD). Instead, use WebLink or ApplicationLink.")]] static hstring Uri();
    static hstring Html();
    static hstring Rtf();
    static hstring Bitmap();
    static hstring StorageItems();
    static hstring WebLink();
    static hstring ApplicationLink();
};

struct WINRT_EBO TargetApplicationChosenEventArgs :
    Windows::ApplicationModel::DataTransfer::ITargetApplicationChosenEventArgs
{
    TargetApplicationChosenEventArgs(std::nullptr_t) noexcept {}
};

}

}
