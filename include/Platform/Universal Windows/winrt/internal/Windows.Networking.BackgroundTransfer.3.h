// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Networking.BackgroundTransfer.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Networking::BackgroundTransfer {

struct WINRT_EBO BackgroundDownloader :
    Windows::Networking::BackgroundTransfer::IBackgroundDownloader,
    impl::require<BackgroundDownloader, Windows::Networking::BackgroundTransfer::IBackgroundDownloader2, Windows::Networking::BackgroundTransfer::IBackgroundDownloader3>
{
    BackgroundDownloader(std::nullptr_t) noexcept {}
    BackgroundDownloader();
    BackgroundDownloader(const Windows::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup & completionGroup);
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::DownloadOperation>> GetCurrentDownloadsAsync();
    [[deprecated("GetCurrentDownloadsAsync(group) may be altered or unavailable for releases after Windows 8.1. Instead, use GetCurrentDownloadsForTransferGroupAsync.")]] static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::DownloadOperation>> GetCurrentDownloadsAsync(hstring_view group);
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::DownloadOperation>> GetCurrentDownloadsForTransferGroupAsync(const Windows::Networking::BackgroundTransfer::BackgroundTransferGroup & group);
    [[deprecated("RequestUnconstrainedDownloadsAsync is deprecated and may not work on all platforms. For more info, see MSDN.")]] static Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UnconstrainedTransferRequestResult> RequestUnconstrainedDownloadsAsync(iterable<Windows::Networking::BackgroundTransfer::DownloadOperation> operations);
};

struct WINRT_EBO BackgroundTransferCompletionGroup :
    Windows::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroup
{
    BackgroundTransferCompletionGroup(std::nullptr_t) noexcept {}
    BackgroundTransferCompletionGroup();
};

struct WINRT_EBO BackgroundTransferCompletionGroupTriggerDetails :
    Windows::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroupTriggerDetails
{
    BackgroundTransferCompletionGroupTriggerDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO BackgroundTransferContentPart :
    Windows::Networking::BackgroundTransfer::IBackgroundTransferContentPart
{
    BackgroundTransferContentPart(std::nullptr_t) noexcept {}
    BackgroundTransferContentPart();
    BackgroundTransferContentPart(hstring_view name);
    BackgroundTransferContentPart(hstring_view name, hstring_view fileName);
};

struct BackgroundTransferError
{
    BackgroundTransferError() = delete;
    static Windows::Web::WebErrorStatus GetStatus(int32_t hresult);
};

struct WINRT_EBO BackgroundTransferGroup :
    Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup
{
    BackgroundTransferGroup(std::nullptr_t) noexcept {}
    static Windows::Networking::BackgroundTransfer::BackgroundTransferGroup CreateGroup(hstring_view name);
};

struct WINRT_EBO BackgroundUploader :
    Windows::Networking::BackgroundTransfer::IBackgroundUploader,
    impl::require<BackgroundUploader, Windows::Networking::BackgroundTransfer::IBackgroundUploader2, Windows::Networking::BackgroundTransfer::IBackgroundUploader3>
{
    BackgroundUploader(std::nullptr_t) noexcept {}
    BackgroundUploader();
    BackgroundUploader(const Windows::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup & completionGroup);
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::UploadOperation>> GetCurrentUploadsAsync();
    [[deprecated("GetCurrentUploadsAsync(group) may be altered or unavailable for releases after Windows 8.1. Instead, use GetCurrentUploadsForTransferGroupAsync.")]] static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::UploadOperation>> GetCurrentUploadsAsync(hstring_view group);
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::UploadOperation>> GetCurrentUploadsForTransferGroupAsync(const Windows::Networking::BackgroundTransfer::BackgroundTransferGroup & group);
    [[deprecated("RequestUnconstrainedUploadsAsync is deprecated and may not work on all platforms. For more info, see MSDN.")]] static Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UnconstrainedTransferRequestResult> RequestUnconstrainedUploadsAsync(iterable<Windows::Networking::BackgroundTransfer::UploadOperation> operations);
};

struct ContentPrefetcher
{
    ContentPrefetcher() = delete;
    static Windows::Foundation::Collections::IVector<Windows::Foundation::Uri> ContentUris();
    static void IndirectContentUri(const Windows::Foundation::Uri & value);
    static Windows::Foundation::Uri IndirectContentUri();
    static Windows::Foundation::IReference<Windows::Foundation::DateTime> LastSuccessfulPrefetchTime();
};

struct WINRT_EBO DownloadOperation :
    Windows::Networking::BackgroundTransfer::IDownloadOperation,
    impl::require<DownloadOperation, Windows::Networking::BackgroundTransfer::IBackgroundTransferOperationPriority, Windows::Networking::BackgroundTransfer::IDownloadOperation2>
{
    DownloadOperation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ResponseInformation :
    Windows::Networking::BackgroundTransfer::IResponseInformation
{
    ResponseInformation(std::nullptr_t) noexcept {}
};

struct [[deprecated("UnconstrainedTransferRequestResult is deprecated and may not work on all platforms. For more info, see MSDN.")]] WINRT_EBO UnconstrainedTransferRequestResult :
    Windows::Networking::BackgroundTransfer::IUnconstrainedTransferRequestResult
{
    UnconstrainedTransferRequestResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO UploadOperation :
    Windows::Networking::BackgroundTransfer::IUploadOperation,
    impl::require<UploadOperation, Windows::Networking::BackgroundTransfer::IBackgroundTransferOperationPriority, Windows::Networking::BackgroundTransfer::IUploadOperation2>
{
    UploadOperation(std::nullptr_t) noexcept {}
};

}

}
