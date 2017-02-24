// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Storage.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Networking.3.h"
#include "internal/Windows.Security.EnterpriseData.3.h"
#include "Windows.Foundation.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Security::EnterpriseData::IBufferProtectUnprotectResult> : produce_base<D, Windows::Security::EnterpriseData::IBufferProtectUnprotectResult>
{
    HRESULT __stdcall get_Buffer(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Buffer());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProtectionInfo(impl::abi_arg_out<Windows::Security::EnterpriseData::IDataProtectionInfo> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProtectionInfo());
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
struct produce<D, Windows::Security::EnterpriseData::IDataProtectionInfo> : produce_base<D, Windows::Security::EnterpriseData::IDataProtectionInfo>
{
    HRESULT __stdcall get_Status(Windows::Security::EnterpriseData::DataProtectionStatus * value) noexcept override
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

    HRESULT __stdcall get_Identity(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Identity());
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
struct produce<D, Windows::Security::EnterpriseData::IDataProtectionManagerStatics> : produce_base<D, Windows::Security::EnterpriseData::IDataProtectionManagerStatics>
{
    HRESULT __stdcall abi_ProtectAsync(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> data, impl::abi_arg_in<hstring> identity, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::BufferProtectUnprotectResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ProtectAsync(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&data), *reinterpret_cast<const hstring *>(&identity)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UnprotectAsync(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> data, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::BufferProtectUnprotectResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().UnprotectAsync(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&data)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ProtectStreamAsync(impl::abi_arg_in<Windows::Storage::Streams::IInputStream> unprotectedStream, impl::abi_arg_in<hstring> identity, impl::abi_arg_in<Windows::Storage::Streams::IOutputStream> protectedStream, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::DataProtectionInfo>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ProtectStreamAsync(*reinterpret_cast<const Windows::Storage::Streams::IInputStream *>(&unprotectedStream), *reinterpret_cast<const hstring *>(&identity), *reinterpret_cast<const Windows::Storage::Streams::IOutputStream *>(&protectedStream)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UnprotectStreamAsync(impl::abi_arg_in<Windows::Storage::Streams::IInputStream> protectedStream, impl::abi_arg_in<Windows::Storage::Streams::IOutputStream> unprotectedStream, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::DataProtectionInfo>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().UnprotectStreamAsync(*reinterpret_cast<const Windows::Storage::Streams::IInputStream *>(&protectedStream), *reinterpret_cast<const Windows::Storage::Streams::IOutputStream *>(&unprotectedStream)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetProtectionInfoAsync(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> protectedData, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::DataProtectionInfo>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetProtectionInfoAsync(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&protectedData)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStreamProtectionInfoAsync(impl::abi_arg_in<Windows::Storage::Streams::IInputStream> protectedStream, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::DataProtectionInfo>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetStreamProtectionInfoAsync(*reinterpret_cast<const Windows::Storage::Streams::IInputStream *>(&protectedStream)));
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
struct produce<D, Windows::Security::EnterpriseData::IFileProtectionInfo> : produce_base<D, Windows::Security::EnterpriseData::IFileProtectionInfo>
{
    HRESULT __stdcall get_Status(Windows::Security::EnterpriseData::FileProtectionStatus * value) noexcept override
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

    HRESULT __stdcall get_IsRoamable(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsRoamable());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Identity(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Identity());
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
struct produce<D, Windows::Security::EnterpriseData::IFileProtectionManagerStatics> : produce_base<D, Windows::Security::EnterpriseData::IFileProtectionManagerStatics>
{
    HRESULT __stdcall abi_ProtectAsync(impl::abi_arg_in<Windows::Storage::IStorageItem> target, impl::abi_arg_in<hstring> identity, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::FileProtectionInfo>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ProtectAsync(*reinterpret_cast<const Windows::Storage::IStorageItem *>(&target), *reinterpret_cast<const hstring *>(&identity)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CopyProtectionAsync(impl::abi_arg_in<Windows::Storage::IStorageItem> source, impl::abi_arg_in<Windows::Storage::IStorageItem> target, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CopyProtectionAsync(*reinterpret_cast<const Windows::Storage::IStorageItem *>(&source), *reinterpret_cast<const Windows::Storage::IStorageItem *>(&target)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetProtectionInfoAsync(impl::abi_arg_in<Windows::Storage::IStorageItem> source, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::FileProtectionInfo>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetProtectionInfoAsync(*reinterpret_cast<const Windows::Storage::IStorageItem *>(&source)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SaveFileAsContainerAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> protectedFile, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::ProtectedContainerExportResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().SaveFileAsContainerAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&protectedFile)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LoadFileFromContainerAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> containerFile, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::ProtectedContainerImportResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().LoadFileFromContainerAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&containerFile)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LoadFileFromContainerWithTargetAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> containerFile, impl::abi_arg_in<Windows::Storage::IStorageItem> target, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::ProtectedContainerImportResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().LoadFileFromContainerAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&containerFile), *reinterpret_cast<const Windows::Storage::IStorageItem *>(&target)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateProtectedAndOpenAsync(impl::abi_arg_in<Windows::Storage::IStorageFolder> parentFolder, impl::abi_arg_in<hstring> desiredName, impl::abi_arg_in<hstring> identity, Windows::Storage::CreationCollisionOption collisionOption, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::ProtectedFileCreateResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateProtectedAndOpenAsync(*reinterpret_cast<const Windows::Storage::IStorageFolder *>(&parentFolder), *reinterpret_cast<const hstring *>(&desiredName), *reinterpret_cast<const hstring *>(&identity), collisionOption));
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
struct produce<D, Windows::Security::EnterpriseData::IFileProtectionManagerStatics2> : produce_base<D, Windows::Security::EnterpriseData::IFileProtectionManagerStatics2>
{
    HRESULT __stdcall abi_IsContainerAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsContainerAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LoadFileFromContainerWithTargetAndNameCollisionOptionAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> containerFile, impl::abi_arg_in<Windows::Storage::IStorageItem> target, Windows::Storage::NameCollisionOption collisionOption, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::ProtectedContainerImportResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().LoadFileFromContainerAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&containerFile), *reinterpret_cast<const Windows::Storage::IStorageItem *>(&target), collisionOption));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SaveFileAsContainerWithSharingAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> protectedFile, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> sharedWithIdentities, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::ProtectedContainerExportResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().SaveFileAsContainerAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&protectedFile), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&sharedWithIdentities)));
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
struct produce<D, Windows::Security::EnterpriseData::IFileRevocationManagerStatics> : produce_base<D, Windows::Security::EnterpriseData::IFileRevocationManagerStatics>
{
    HRESULT __stdcall abi_ProtectAsync(impl::abi_arg_in<Windows::Storage::IStorageItem> storageItem, impl::abi_arg_in<hstring> enterpriseIdentity, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::FileProtectionStatus>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ProtectAsync(*reinterpret_cast<const Windows::Storage::IStorageItem *>(&storageItem), *reinterpret_cast<const hstring *>(&enterpriseIdentity)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CopyProtectionAsync(impl::abi_arg_in<Windows::Storage::IStorageItem> sourceStorageItem, impl::abi_arg_in<Windows::Storage::IStorageItem> targetStorageItem, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CopyProtectionAsync(*reinterpret_cast<const Windows::Storage::IStorageItem *>(&sourceStorageItem), *reinterpret_cast<const Windows::Storage::IStorageItem *>(&targetStorageItem)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Revoke(impl::abi_arg_in<hstring> enterpriseIdentity) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Revoke(*reinterpret_cast<const hstring *>(&enterpriseIdentity));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStatusAsync(impl::abi_arg_in<Windows::Storage::IStorageItem> storageItem, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::FileProtectionStatus>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetStatusAsync(*reinterpret_cast<const Windows::Storage::IStorageItem *>(&storageItem)));
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
struct produce<D, Windows::Security::EnterpriseData::IProtectedAccessResumedEventArgs> : produce_base<D, Windows::Security::EnterpriseData::IProtectedAccessResumedEventArgs>
{
    HRESULT __stdcall get_Identities(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Identities());
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
struct produce<D, Windows::Security::EnterpriseData::IProtectedAccessSuspendingEventArgs> : produce_base<D, Windows::Security::EnterpriseData::IProtectedAccessSuspendingEventArgs>
{
    HRESULT __stdcall get_Identities(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Identities());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
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

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDeferral());
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
struct produce<D, Windows::Security::EnterpriseData::IProtectedContainerExportResult> : produce_base<D, Windows::Security::EnterpriseData::IProtectedContainerExportResult>
{
    HRESULT __stdcall get_Status(Windows::Security::EnterpriseData::ProtectedImportExportStatus * value) noexcept override
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
struct produce<D, Windows::Security::EnterpriseData::IProtectedContainerImportResult> : produce_base<D, Windows::Security::EnterpriseData::IProtectedContainerImportResult>
{
    HRESULT __stdcall get_Status(Windows::Security::EnterpriseData::ProtectedImportExportStatus * value) noexcept override
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
struct produce<D, Windows::Security::EnterpriseData::IProtectedContentRevokedEventArgs> : produce_base<D, Windows::Security::EnterpriseData::IProtectedContentRevokedEventArgs>
{
    HRESULT __stdcall get_Identities(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Identities());
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
struct produce<D, Windows::Security::EnterpriseData::IProtectedFileCreateResult> : produce_base<D, Windows::Security::EnterpriseData::IProtectedFileCreateResult>
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

    HRESULT __stdcall get_Stream(impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStream> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Stream());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProtectionInfo(impl::abi_arg_out<Windows::Security::EnterpriseData::IFileProtectionInfo> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProtectionInfo());
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
struct produce<D, Windows::Security::EnterpriseData::IProtectionPolicyAuditInfo> : produce_base<D, Windows::Security::EnterpriseData::IProtectionPolicyAuditInfo>
{
    HRESULT __stdcall put_Action(Windows::Security::EnterpriseData::ProtectionPolicyAuditAction value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Action(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Action(Windows::Security::EnterpriseData::ProtectionPolicyAuditAction * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Action());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DataDescription(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DataDescription(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DataDescription(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DataDescription());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SourceDescription(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceDescription(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SourceDescription(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourceDescription());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TargetDescription(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TargetDescription(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TargetDescription(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetDescription());
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
struct produce<D, Windows::Security::EnterpriseData::IProtectionPolicyAuditInfoFactory> : produce_base<D, Windows::Security::EnterpriseData::IProtectionPolicyAuditInfoFactory>
{
    HRESULT __stdcall abi_Create(Windows::Security::EnterpriseData::ProtectionPolicyAuditAction action, impl::abi_arg_in<hstring> dataDescription, impl::abi_arg_in<hstring> sourceDescription, impl::abi_arg_in<hstring> targetDescription, impl::abi_arg_out<Windows::Security::EnterpriseData::IProtectionPolicyAuditInfo> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(action, *reinterpret_cast<const hstring *>(&dataDescription), *reinterpret_cast<const hstring *>(&sourceDescription), *reinterpret_cast<const hstring *>(&targetDescription)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithActionAndDataDescription(Windows::Security::EnterpriseData::ProtectionPolicyAuditAction action, impl::abi_arg_in<hstring> dataDescription, impl::abi_arg_out<Windows::Security::EnterpriseData::IProtectionPolicyAuditInfo> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateWithActionAndDataDescription(action, *reinterpret_cast<const hstring *>(&dataDescription)));
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
struct produce<D, Windows::Security::EnterpriseData::IProtectionPolicyManager> : produce_base<D, Windows::Security::EnterpriseData::IProtectionPolicyManager>
{
    HRESULT __stdcall put_Identity(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Identity(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Identity(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Identity());
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
struct produce<D, Windows::Security::EnterpriseData::IProtectionPolicyManager2> : produce_base<D, Windows::Security::EnterpriseData::IProtectionPolicyManager2>
{
    HRESULT __stdcall put_ShowEnterpriseIndicator(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowEnterpriseIndicator(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ShowEnterpriseIndicator(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ShowEnterpriseIndicator());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::EnterpriseData::IProtectionPolicyManagerStatics> : produce_base<D, Windows::Security::EnterpriseData::IProtectionPolicyManagerStatics>
{
    HRESULT __stdcall abi_IsIdentityManaged(impl::abi_arg_in<hstring> identity, bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsIdentityManaged(*reinterpret_cast<const hstring *>(&identity)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryApplyProcessUIPolicy(impl::abi_arg_in<hstring> identity, bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryApplyProcessUIPolicy(*reinterpret_cast<const hstring *>(&identity)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ClearProcessUIPolicy() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClearProcessUIPolicy();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateCurrentThreadNetworkContext(impl::abi_arg_in<hstring> identity, impl::abi_arg_out<Windows::Security::EnterpriseData::IThreadNetworkContext> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateCurrentThreadNetworkContext(*reinterpret_cast<const hstring *>(&identity)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPrimaryManagedIdentityForNetworkEndpointAsync(impl::abi_arg_in<Windows::Networking::IHostName> endpointHost, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetPrimaryManagedIdentityForNetworkEndpointAsync(*reinterpret_cast<const Windows::Networking::HostName *>(&endpointHost)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RevokeContent(impl::abi_arg_in<hstring> identity) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RevokeContent(*reinterpret_cast<const hstring *>(&identity));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetForCurrentView(impl::abi_arg_out<Windows::Security::EnterpriseData::IProtectionPolicyManager> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetForCurrentView());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ProtectedAccessSuspending(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Security::EnterpriseData::ProtectedAccessSuspendingEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ProtectedAccessSuspending(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Security::EnterpriseData::ProtectedAccessSuspendingEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ProtectedAccessSuspending(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProtectedAccessSuspending(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ProtectedAccessResumed(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Security::EnterpriseData::ProtectedAccessResumedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ProtectedAccessResumed(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Security::EnterpriseData::ProtectedAccessResumedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ProtectedAccessResumed(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProtectedAccessResumed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ProtectedContentRevoked(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Security::EnterpriseData::ProtectedContentRevokedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ProtectedContentRevoked(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Security::EnterpriseData::ProtectedContentRevokedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ProtectedContentRevoked(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProtectedContentRevoked(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CheckAccess(impl::abi_arg_in<hstring> sourceIdentity, impl::abi_arg_in<hstring> targetIdentity, Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CheckAccess(*reinterpret_cast<const hstring *>(&sourceIdentity), *reinterpret_cast<const hstring *>(&targetIdentity)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestAccessAsync(impl::abi_arg_in<hstring> sourceIdentity, impl::abi_arg_in<hstring> targetIdentity, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestAccessAsync(*reinterpret_cast<const hstring *>(&sourceIdentity), *reinterpret_cast<const hstring *>(&targetIdentity)));
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
struct produce<D, Windows::Security::EnterpriseData::IProtectionPolicyManagerStatics2> : produce_base<D, Windows::Security::EnterpriseData::IProtectionPolicyManagerStatics2>
{
    HRESULT __stdcall abi_HasContentBeenRevokedSince(impl::abi_arg_in<hstring> identity, impl::abi_arg_in<Windows::Foundation::DateTime> since, bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().HasContentBeenRevokedSince(*reinterpret_cast<const hstring *>(&identity), *reinterpret_cast<const Windows::Foundation::DateTime *>(&since)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CheckAccessForApp(impl::abi_arg_in<hstring> sourceIdentity, impl::abi_arg_in<hstring> appPackageFamilyName, Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CheckAccessForApp(*reinterpret_cast<const hstring *>(&sourceIdentity), *reinterpret_cast<const hstring *>(&appPackageFamilyName)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestAccessForAppAsync(impl::abi_arg_in<hstring> sourceIdentity, impl::abi_arg_in<hstring> appPackageFamilyName, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestAccessForAppAsync(*reinterpret_cast<const hstring *>(&sourceIdentity), *reinterpret_cast<const hstring *>(&appPackageFamilyName)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetEnforcementLevel(impl::abi_arg_in<hstring> identity, Windows::Security::EnterpriseData::EnforcementLevel * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetEnforcementLevel(*reinterpret_cast<const hstring *>(&identity)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsUserDecryptionAllowed(impl::abi_arg_in<hstring> identity, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsUserDecryptionAllowed(*reinterpret_cast<const hstring *>(&identity)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsProtectionUnderLockRequired(impl::abi_arg_in<hstring> identity, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsProtectionUnderLockRequired(*reinterpret_cast<const hstring *>(&identity)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PolicyChanged(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().PolicyChanged(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PolicyChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PolicyChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsProtectionEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsProtectionEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::EnterpriseData::IProtectionPolicyManagerStatics3> : produce_base<D, Windows::Security::EnterpriseData::IProtectionPolicyManagerStatics3>
{
    HRESULT __stdcall abi_RequestAccessWithAuditingInfoAsync(impl::abi_arg_in<hstring> sourceIdentity, impl::abi_arg_in<hstring> targetIdentity, impl::abi_arg_in<Windows::Security::EnterpriseData::IProtectionPolicyAuditInfo> auditInfo, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestAccessAsync(*reinterpret_cast<const hstring *>(&sourceIdentity), *reinterpret_cast<const hstring *>(&targetIdentity), *reinterpret_cast<const Windows::Security::EnterpriseData::ProtectionPolicyAuditInfo *>(&auditInfo)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestAccessWithMessageAsync(impl::abi_arg_in<hstring> sourceIdentity, impl::abi_arg_in<hstring> targetIdentity, impl::abi_arg_in<Windows::Security::EnterpriseData::IProtectionPolicyAuditInfo> auditInfo, impl::abi_arg_in<hstring> messageFromApp, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestAccessAsync(*reinterpret_cast<const hstring *>(&sourceIdentity), *reinterpret_cast<const hstring *>(&targetIdentity), *reinterpret_cast<const Windows::Security::EnterpriseData::ProtectionPolicyAuditInfo *>(&auditInfo), *reinterpret_cast<const hstring *>(&messageFromApp)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestAccessForAppWithAuditingInfoAsync(impl::abi_arg_in<hstring> sourceIdentity, impl::abi_arg_in<hstring> appPackageFamilyName, impl::abi_arg_in<Windows::Security::EnterpriseData::IProtectionPolicyAuditInfo> auditInfo, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestAccessForAppAsync(*reinterpret_cast<const hstring *>(&sourceIdentity), *reinterpret_cast<const hstring *>(&appPackageFamilyName), *reinterpret_cast<const Windows::Security::EnterpriseData::ProtectionPolicyAuditInfo *>(&auditInfo)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestAccessForAppWithMessageAsync(impl::abi_arg_in<hstring> sourceIdentity, impl::abi_arg_in<hstring> appPackageFamilyName, impl::abi_arg_in<Windows::Security::EnterpriseData::IProtectionPolicyAuditInfo> auditInfo, impl::abi_arg_in<hstring> messageFromApp, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestAccessForAppAsync(*reinterpret_cast<const hstring *>(&sourceIdentity), *reinterpret_cast<const hstring *>(&appPackageFamilyName), *reinterpret_cast<const Windows::Security::EnterpriseData::ProtectionPolicyAuditInfo *>(&auditInfo), *reinterpret_cast<const hstring *>(&messageFromApp)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LogAuditEvent(impl::abi_arg_in<hstring> sourceIdentity, impl::abi_arg_in<hstring> targetIdentity, impl::abi_arg_in<Windows::Security::EnterpriseData::IProtectionPolicyAuditInfo> auditInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LogAuditEvent(*reinterpret_cast<const hstring *>(&sourceIdentity), *reinterpret_cast<const hstring *>(&targetIdentity), *reinterpret_cast<const Windows::Security::EnterpriseData::ProtectionPolicyAuditInfo *>(&auditInfo));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::EnterpriseData::IThreadNetworkContext> : produce_base<D, Windows::Security::EnterpriseData::IThreadNetworkContext>
{};

}

namespace Windows::Security::EnterpriseData {

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::FileProtectionStatus> impl_IFileRevocationManagerStatics<D>::ProtectAsync(const Windows::Storage::IStorageItem & storageItem, hstring_view enterpriseIdentity) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::FileProtectionStatus> result;
    check_hresult(WINRT_SHIM(IFileRevocationManagerStatics)->abi_ProtectAsync(get_abi(storageItem), get_abi(enterpriseIdentity), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IFileRevocationManagerStatics<D>::CopyProtectionAsync(const Windows::Storage::IStorageItem & sourceStorageItem, const Windows::Storage::IStorageItem & targetStorageItem) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IFileRevocationManagerStatics)->abi_CopyProtectionAsync(get_abi(sourceStorageItem), get_abi(targetStorageItem), put_abi(result)));
    return result;
}

template <typename D> void impl_IFileRevocationManagerStatics<D>::Revoke(hstring_view enterpriseIdentity) const
{
    check_hresult(WINRT_SHIM(IFileRevocationManagerStatics)->abi_Revoke(get_abi(enterpriseIdentity)));
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::FileProtectionStatus> impl_IFileRevocationManagerStatics<D>::GetStatusAsync(const Windows::Storage::IStorageItem & storageItem) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::FileProtectionStatus> result;
    check_hresult(WINRT_SHIM(IFileRevocationManagerStatics)->abi_GetStatusAsync(get_abi(storageItem), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::FileProtectionInfo> impl_IFileProtectionManagerStatics<D>::ProtectAsync(const Windows::Storage::IStorageItem & target, hstring_view identity) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::FileProtectionInfo> result;
    check_hresult(WINRT_SHIM(IFileProtectionManagerStatics)->abi_ProtectAsync(get_abi(target), get_abi(identity), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IFileProtectionManagerStatics<D>::CopyProtectionAsync(const Windows::Storage::IStorageItem & source, const Windows::Storage::IStorageItem & target) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IFileProtectionManagerStatics)->abi_CopyProtectionAsync(get_abi(source), get_abi(target), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::FileProtectionInfo> impl_IFileProtectionManagerStatics<D>::GetProtectionInfoAsync(const Windows::Storage::IStorageItem & source) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::FileProtectionInfo> result;
    check_hresult(WINRT_SHIM(IFileProtectionManagerStatics)->abi_GetProtectionInfoAsync(get_abi(source), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::ProtectedContainerExportResult> impl_IFileProtectionManagerStatics<D>::SaveFileAsContainerAsync(const Windows::Storage::IStorageFile & protectedFile) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::ProtectedContainerExportResult> result;
    check_hresult(WINRT_SHIM(IFileProtectionManagerStatics)->abi_SaveFileAsContainerAsync(get_abi(protectedFile), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::ProtectedContainerImportResult> impl_IFileProtectionManagerStatics<D>::LoadFileFromContainerAsync(const Windows::Storage::IStorageFile & containerFile) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::ProtectedContainerImportResult> result;
    check_hresult(WINRT_SHIM(IFileProtectionManagerStatics)->abi_LoadFileFromContainerAsync(get_abi(containerFile), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::ProtectedContainerImportResult> impl_IFileProtectionManagerStatics<D>::LoadFileFromContainerAsync(const Windows::Storage::IStorageFile & containerFile, const Windows::Storage::IStorageItem & target) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::ProtectedContainerImportResult> result;
    check_hresult(WINRT_SHIM(IFileProtectionManagerStatics)->abi_LoadFileFromContainerWithTargetAsync(get_abi(containerFile), get_abi(target), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::ProtectedFileCreateResult> impl_IFileProtectionManagerStatics<D>::CreateProtectedAndOpenAsync(const Windows::Storage::IStorageFolder & parentFolder, hstring_view desiredName, hstring_view identity, Windows::Storage::CreationCollisionOption collisionOption) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::ProtectedFileCreateResult> result;
    check_hresult(WINRT_SHIM(IFileProtectionManagerStatics)->abi_CreateProtectedAndOpenAsync(get_abi(parentFolder), get_abi(desiredName), get_abi(identity), collisionOption, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IFileProtectionManagerStatics2<D>::IsContainerAsync(const Windows::Storage::IStorageFile & file) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IFileProtectionManagerStatics2)->abi_IsContainerAsync(get_abi(file), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::ProtectedContainerImportResult> impl_IFileProtectionManagerStatics2<D>::LoadFileFromContainerAsync(const Windows::Storage::IStorageFile & containerFile, const Windows::Storage::IStorageItem & target, Windows::Storage::NameCollisionOption collisionOption) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::ProtectedContainerImportResult> result;
    check_hresult(WINRT_SHIM(IFileProtectionManagerStatics2)->abi_LoadFileFromContainerWithTargetAndNameCollisionOptionAsync(get_abi(containerFile), get_abi(target), collisionOption, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::ProtectedContainerExportResult> impl_IFileProtectionManagerStatics2<D>::SaveFileAsContainerAsync(const Windows::Storage::IStorageFile & protectedFile, iterable<hstring> sharedWithIdentities) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::ProtectedContainerExportResult> result;
    check_hresult(WINRT_SHIM(IFileProtectionManagerStatics2)->abi_SaveFileAsContainerWithSharingAsync(get_abi(protectedFile), get_abi(sharedWithIdentities), put_abi(result)));
    return result;
}

template <typename D> Windows::Storage::StorageFile impl_IProtectedFileCreateResult<D>::File() const
{
    Windows::Storage::StorageFile value { nullptr };
    check_hresult(WINRT_SHIM(IProtectedFileCreateResult)->get_File(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IRandomAccessStream impl_IProtectedFileCreateResult<D>::Stream() const
{
    Windows::Storage::Streams::IRandomAccessStream value;
    check_hresult(WINRT_SHIM(IProtectedFileCreateResult)->get_Stream(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::EnterpriseData::FileProtectionInfo impl_IProtectedFileCreateResult<D>::ProtectionInfo() const
{
    Windows::Security::EnterpriseData::FileProtectionInfo value { nullptr };
    check_hresult(WINRT_SHIM(IProtectedFileCreateResult)->get_ProtectionInfo(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::EnterpriseData::FileProtectionStatus impl_IFileProtectionInfo<D>::Status() const
{
    Windows::Security::EnterpriseData::FileProtectionStatus value {};
    check_hresult(WINRT_SHIM(IFileProtectionInfo)->get_Status(&value));
    return value;
}

template <typename D> bool impl_IFileProtectionInfo<D>::IsRoamable() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IFileProtectionInfo)->get_IsRoamable(&value));
    return value;
}

template <typename D> hstring impl_IFileProtectionInfo<D>::Identity() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IFileProtectionInfo)->get_Identity(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::EnterpriseData::ProtectedImportExportStatus impl_IProtectedContainerExportResult<D>::Status() const
{
    Windows::Security::EnterpriseData::ProtectedImportExportStatus value {};
    check_hresult(WINRT_SHIM(IProtectedContainerExportResult)->get_Status(&value));
    return value;
}

template <typename D> Windows::Storage::StorageFile impl_IProtectedContainerExportResult<D>::File() const
{
    Windows::Storage::StorageFile value { nullptr };
    check_hresult(WINRT_SHIM(IProtectedContainerExportResult)->get_File(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::EnterpriseData::ProtectedImportExportStatus impl_IProtectedContainerImportResult<D>::Status() const
{
    Windows::Security::EnterpriseData::ProtectedImportExportStatus value {};
    check_hresult(WINRT_SHIM(IProtectedContainerImportResult)->get_Status(&value));
    return value;
}

template <typename D> Windows::Storage::StorageFile impl_IProtectedContainerImportResult<D>::File() const
{
    Windows::Storage::StorageFile value { nullptr };
    check_hresult(WINRT_SHIM(IProtectedContainerImportResult)->get_File(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::BufferProtectUnprotectResult> impl_IDataProtectionManagerStatics<D>::ProtectAsync(const Windows::Storage::Streams::IBuffer & data, hstring_view identity) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::BufferProtectUnprotectResult> result;
    check_hresult(WINRT_SHIM(IDataProtectionManagerStatics)->abi_ProtectAsync(get_abi(data), get_abi(identity), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::BufferProtectUnprotectResult> impl_IDataProtectionManagerStatics<D>::UnprotectAsync(const Windows::Storage::Streams::IBuffer & data) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::BufferProtectUnprotectResult> result;
    check_hresult(WINRT_SHIM(IDataProtectionManagerStatics)->abi_UnprotectAsync(get_abi(data), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::DataProtectionInfo> impl_IDataProtectionManagerStatics<D>::ProtectStreamAsync(const Windows::Storage::Streams::IInputStream & unprotectedStream, hstring_view identity, const Windows::Storage::Streams::IOutputStream & protectedStream) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::DataProtectionInfo> result;
    check_hresult(WINRT_SHIM(IDataProtectionManagerStatics)->abi_ProtectStreamAsync(get_abi(unprotectedStream), get_abi(identity), get_abi(protectedStream), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::DataProtectionInfo> impl_IDataProtectionManagerStatics<D>::UnprotectStreamAsync(const Windows::Storage::Streams::IInputStream & protectedStream, const Windows::Storage::Streams::IOutputStream & unprotectedStream) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::DataProtectionInfo> result;
    check_hresult(WINRT_SHIM(IDataProtectionManagerStatics)->abi_UnprotectStreamAsync(get_abi(protectedStream), get_abi(unprotectedStream), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::DataProtectionInfo> impl_IDataProtectionManagerStatics<D>::GetProtectionInfoAsync(const Windows::Storage::Streams::IBuffer & protectedData) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::DataProtectionInfo> result;
    check_hresult(WINRT_SHIM(IDataProtectionManagerStatics)->abi_GetProtectionInfoAsync(get_abi(protectedData), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::DataProtectionInfo> impl_IDataProtectionManagerStatics<D>::GetStreamProtectionInfoAsync(const Windows::Storage::Streams::IInputStream & protectedStream) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::DataProtectionInfo> result;
    check_hresult(WINRT_SHIM(IDataProtectionManagerStatics)->abi_GetStreamProtectionInfoAsync(get_abi(protectedStream), put_abi(result)));
    return result;
}

template <typename D> Windows::Security::EnterpriseData::DataProtectionStatus impl_IDataProtectionInfo<D>::Status() const
{
    Windows::Security::EnterpriseData::DataProtectionStatus value {};
    check_hresult(WINRT_SHIM(IDataProtectionInfo)->get_Status(&value));
    return value;
}

template <typename D> hstring impl_IDataProtectionInfo<D>::Identity() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDataProtectionInfo)->get_Identity(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IBufferProtectUnprotectResult<D>::Buffer() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IBufferProtectUnprotectResult)->get_Buffer(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::EnterpriseData::DataProtectionInfo impl_IBufferProtectUnprotectResult<D>::ProtectionInfo() const
{
    Windows::Security::EnterpriseData::DataProtectionInfo value { nullptr };
    check_hresult(WINRT_SHIM(IBufferProtectUnprotectResult)->get_ProtectionInfo(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::EnterpriseData::ProtectionPolicyAuditInfo impl_IProtectionPolicyAuditInfoFactory<D>::Create(Windows::Security::EnterpriseData::ProtectionPolicyAuditAction action, hstring_view dataDescription, hstring_view sourceDescription, hstring_view targetDescription) const
{
    Windows::Security::EnterpriseData::ProtectionPolicyAuditInfo result { nullptr };
    check_hresult(WINRT_SHIM(IProtectionPolicyAuditInfoFactory)->abi_Create(action, get_abi(dataDescription), get_abi(sourceDescription), get_abi(targetDescription), put_abi(result)));
    return result;
}

template <typename D> Windows::Security::EnterpriseData::ProtectionPolicyAuditInfo impl_IProtectionPolicyAuditInfoFactory<D>::CreateWithActionAndDataDescription(Windows::Security::EnterpriseData::ProtectionPolicyAuditAction action, hstring_view dataDescription) const
{
    Windows::Security::EnterpriseData::ProtectionPolicyAuditInfo result { nullptr };
    check_hresult(WINRT_SHIM(IProtectionPolicyAuditInfoFactory)->abi_CreateWithActionAndDataDescription(action, get_abi(dataDescription), put_abi(result)));
    return result;
}

template <typename D> void impl_IProtectionPolicyAuditInfo<D>::Action(Windows::Security::EnterpriseData::ProtectionPolicyAuditAction value) const
{
    check_hresult(WINRT_SHIM(IProtectionPolicyAuditInfo)->put_Action(value));
}

template <typename D> Windows::Security::EnterpriseData::ProtectionPolicyAuditAction impl_IProtectionPolicyAuditInfo<D>::Action() const
{
    Windows::Security::EnterpriseData::ProtectionPolicyAuditAction value {};
    check_hresult(WINRT_SHIM(IProtectionPolicyAuditInfo)->get_Action(&value));
    return value;
}

template <typename D> void impl_IProtectionPolicyAuditInfo<D>::DataDescription(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IProtectionPolicyAuditInfo)->put_DataDescription(get_abi(value)));
}

template <typename D> hstring impl_IProtectionPolicyAuditInfo<D>::DataDescription() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IProtectionPolicyAuditInfo)->get_DataDescription(put_abi(value)));
    return value;
}

template <typename D> void impl_IProtectionPolicyAuditInfo<D>::SourceDescription(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IProtectionPolicyAuditInfo)->put_SourceDescription(get_abi(value)));
}

template <typename D> hstring impl_IProtectionPolicyAuditInfo<D>::SourceDescription() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IProtectionPolicyAuditInfo)->get_SourceDescription(put_abi(value)));
    return value;
}

template <typename D> void impl_IProtectionPolicyAuditInfo<D>::TargetDescription(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IProtectionPolicyAuditInfo)->put_TargetDescription(get_abi(value)));
}

template <typename D> hstring impl_IProtectionPolicyAuditInfo<D>::TargetDescription() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IProtectionPolicyAuditInfo)->get_TargetDescription(put_abi(value)));
    return value;
}

template <typename D> void impl_IProtectionPolicyManager<D>::Identity(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IProtectionPolicyManager)->put_Identity(get_abi(value)));
}

template <typename D> hstring impl_IProtectionPolicyManager<D>::Identity() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IProtectionPolicyManager)->get_Identity(put_abi(value)));
    return value;
}

template <typename D> void impl_IProtectionPolicyManager2<D>::ShowEnterpriseIndicator(bool value) const
{
    check_hresult(WINRT_SHIM(IProtectionPolicyManager2)->put_ShowEnterpriseIndicator(value));
}

template <typename D> bool impl_IProtectionPolicyManager2<D>::ShowEnterpriseIndicator() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IProtectionPolicyManager2)->get_ShowEnterpriseIndicator(&value));
    return value;
}

template <typename D> bool impl_IProtectionPolicyManagerStatics<D>::IsIdentityManaged(hstring_view identity) const
{
    bool result {};
    check_hresult(WINRT_SHIM(IProtectionPolicyManagerStatics)->abi_IsIdentityManaged(get_abi(identity), &result));
    return result;
}

template <typename D> bool impl_IProtectionPolicyManagerStatics<D>::TryApplyProcessUIPolicy(hstring_view identity) const
{
    bool result {};
    check_hresult(WINRT_SHIM(IProtectionPolicyManagerStatics)->abi_TryApplyProcessUIPolicy(get_abi(identity), &result));
    return result;
}

template <typename D> void impl_IProtectionPolicyManagerStatics<D>::ClearProcessUIPolicy() const
{
    check_hresult(WINRT_SHIM(IProtectionPolicyManagerStatics)->abi_ClearProcessUIPolicy());
}

template <typename D> Windows::Security::EnterpriseData::ThreadNetworkContext impl_IProtectionPolicyManagerStatics<D>::CreateCurrentThreadNetworkContext(hstring_view identity) const
{
    Windows::Security::EnterpriseData::ThreadNetworkContext result { nullptr };
    check_hresult(WINRT_SHIM(IProtectionPolicyManagerStatics)->abi_CreateCurrentThreadNetworkContext(get_abi(identity), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_IProtectionPolicyManagerStatics<D>::GetPrimaryManagedIdentityForNetworkEndpointAsync(const Windows::Networking::HostName & endpointHost) const
{
    Windows::Foundation::IAsyncOperation<hstring> result;
    check_hresult(WINRT_SHIM(IProtectionPolicyManagerStatics)->abi_GetPrimaryManagedIdentityForNetworkEndpointAsync(get_abi(endpointHost), put_abi(result)));
    return result;
}

template <typename D> void impl_IProtectionPolicyManagerStatics<D>::RevokeContent(hstring_view identity) const
{
    check_hresult(WINRT_SHIM(IProtectionPolicyManagerStatics)->abi_RevokeContent(get_abi(identity)));
}

template <typename D> Windows::Security::EnterpriseData::ProtectionPolicyManager impl_IProtectionPolicyManagerStatics<D>::GetForCurrentView() const
{
    Windows::Security::EnterpriseData::ProtectionPolicyManager result { nullptr };
    check_hresult(WINRT_SHIM(IProtectionPolicyManagerStatics)->abi_GetForCurrentView(put_abi(result)));
    return result;
}

template <typename D> event_token impl_IProtectionPolicyManagerStatics<D>::ProtectedAccessSuspending(const Windows::Foundation::EventHandler<Windows::Security::EnterpriseData::ProtectedAccessSuspendingEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IProtectionPolicyManagerStatics)->add_ProtectedAccessSuspending(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IProtectionPolicyManagerStatics> impl_IProtectionPolicyManagerStatics<D>::ProtectedAccessSuspending(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Security::EnterpriseData::ProtectedAccessSuspendingEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IProtectionPolicyManagerStatics>(this, &ABI::Windows::Security::EnterpriseData::IProtectionPolicyManagerStatics::remove_ProtectedAccessSuspending, ProtectedAccessSuspending(handler));
}

template <typename D> void impl_IProtectionPolicyManagerStatics<D>::ProtectedAccessSuspending(event_token token) const
{
    check_hresult(WINRT_SHIM(IProtectionPolicyManagerStatics)->remove_ProtectedAccessSuspending(token));
}

template <typename D> event_token impl_IProtectionPolicyManagerStatics<D>::ProtectedAccessResumed(const Windows::Foundation::EventHandler<Windows::Security::EnterpriseData::ProtectedAccessResumedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IProtectionPolicyManagerStatics)->add_ProtectedAccessResumed(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IProtectionPolicyManagerStatics> impl_IProtectionPolicyManagerStatics<D>::ProtectedAccessResumed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Security::EnterpriseData::ProtectedAccessResumedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IProtectionPolicyManagerStatics>(this, &ABI::Windows::Security::EnterpriseData::IProtectionPolicyManagerStatics::remove_ProtectedAccessResumed, ProtectedAccessResumed(handler));
}

template <typename D> void impl_IProtectionPolicyManagerStatics<D>::ProtectedAccessResumed(event_token token) const
{
    check_hresult(WINRT_SHIM(IProtectionPolicyManagerStatics)->remove_ProtectedAccessResumed(token));
}

template <typename D> event_token impl_IProtectionPolicyManagerStatics<D>::ProtectedContentRevoked(const Windows::Foundation::EventHandler<Windows::Security::EnterpriseData::ProtectedContentRevokedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IProtectionPolicyManagerStatics)->add_ProtectedContentRevoked(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IProtectionPolicyManagerStatics> impl_IProtectionPolicyManagerStatics<D>::ProtectedContentRevoked(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Security::EnterpriseData::ProtectedContentRevokedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IProtectionPolicyManagerStatics>(this, &ABI::Windows::Security::EnterpriseData::IProtectionPolicyManagerStatics::remove_ProtectedContentRevoked, ProtectedContentRevoked(handler));
}

template <typename D> void impl_IProtectionPolicyManagerStatics<D>::ProtectedContentRevoked(event_token token) const
{
    check_hresult(WINRT_SHIM(IProtectionPolicyManagerStatics)->remove_ProtectedContentRevoked(token));
}

template <typename D> Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult impl_IProtectionPolicyManagerStatics<D>::CheckAccess(hstring_view sourceIdentity, hstring_view targetIdentity) const
{
    Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult result {};
    check_hresult(WINRT_SHIM(IProtectionPolicyManagerStatics)->abi_CheckAccess(get_abi(sourceIdentity), get_abi(targetIdentity), &result));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult> impl_IProtectionPolicyManagerStatics<D>::RequestAccessAsync(hstring_view sourceIdentity, hstring_view targetIdentity) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult> result;
    check_hresult(WINRT_SHIM(IProtectionPolicyManagerStatics)->abi_RequestAccessAsync(get_abi(sourceIdentity), get_abi(targetIdentity), put_abi(result)));
    return result;
}

template <typename D> bool impl_IProtectionPolicyManagerStatics2<D>::HasContentBeenRevokedSince(hstring_view identity, const Windows::Foundation::DateTime & since) const
{
    bool result {};
    check_hresult(WINRT_SHIM(IProtectionPolicyManagerStatics2)->abi_HasContentBeenRevokedSince(get_abi(identity), get_abi(since), &result));
    return result;
}

template <typename D> Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult impl_IProtectionPolicyManagerStatics2<D>::CheckAccessForApp(hstring_view sourceIdentity, hstring_view appPackageFamilyName) const
{
    Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult result {};
    check_hresult(WINRT_SHIM(IProtectionPolicyManagerStatics2)->abi_CheckAccessForApp(get_abi(sourceIdentity), get_abi(appPackageFamilyName), &result));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult> impl_IProtectionPolicyManagerStatics2<D>::RequestAccessForAppAsync(hstring_view sourceIdentity, hstring_view appPackageFamilyName) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult> result;
    check_hresult(WINRT_SHIM(IProtectionPolicyManagerStatics2)->abi_RequestAccessForAppAsync(get_abi(sourceIdentity), get_abi(appPackageFamilyName), put_abi(result)));
    return result;
}

template <typename D> Windows::Security::EnterpriseData::EnforcementLevel impl_IProtectionPolicyManagerStatics2<D>::GetEnforcementLevel(hstring_view identity) const
{
    Windows::Security::EnterpriseData::EnforcementLevel value {};
    check_hresult(WINRT_SHIM(IProtectionPolicyManagerStatics2)->abi_GetEnforcementLevel(get_abi(identity), &value));
    return value;
}

template <typename D> bool impl_IProtectionPolicyManagerStatics2<D>::IsUserDecryptionAllowed(hstring_view identity) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IProtectionPolicyManagerStatics2)->abi_IsUserDecryptionAllowed(get_abi(identity), &value));
    return value;
}

template <typename D> bool impl_IProtectionPolicyManagerStatics2<D>::IsProtectionUnderLockRequired(hstring_view identity) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IProtectionPolicyManagerStatics2)->abi_IsProtectionUnderLockRequired(get_abi(identity), &value));
    return value;
}

template <typename D> event_token impl_IProtectionPolicyManagerStatics2<D>::PolicyChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IProtectionPolicyManagerStatics2)->add_PolicyChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IProtectionPolicyManagerStatics2> impl_IProtectionPolicyManagerStatics2<D>::PolicyChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IProtectionPolicyManagerStatics2>(this, &ABI::Windows::Security::EnterpriseData::IProtectionPolicyManagerStatics2::remove_PolicyChanged, PolicyChanged(handler));
}

template <typename D> void impl_IProtectionPolicyManagerStatics2<D>::PolicyChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IProtectionPolicyManagerStatics2)->remove_PolicyChanged(token));
}

template <typename D> bool impl_IProtectionPolicyManagerStatics2<D>::IsProtectionEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IProtectionPolicyManagerStatics2)->get_IsProtectionEnabled(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult> impl_IProtectionPolicyManagerStatics3<D>::RequestAccessAsync(hstring_view sourceIdentity, hstring_view targetIdentity, const Windows::Security::EnterpriseData::ProtectionPolicyAuditInfo & auditInfo) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult> result;
    check_hresult(WINRT_SHIM(IProtectionPolicyManagerStatics3)->abi_RequestAccessWithAuditingInfoAsync(get_abi(sourceIdentity), get_abi(targetIdentity), get_abi(auditInfo), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult> impl_IProtectionPolicyManagerStatics3<D>::RequestAccessAsync(hstring_view sourceIdentity, hstring_view targetIdentity, const Windows::Security::EnterpriseData::ProtectionPolicyAuditInfo & auditInfo, hstring_view messageFromApp) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult> result;
    check_hresult(WINRT_SHIM(IProtectionPolicyManagerStatics3)->abi_RequestAccessWithMessageAsync(get_abi(sourceIdentity), get_abi(targetIdentity), get_abi(auditInfo), get_abi(messageFromApp), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult> impl_IProtectionPolicyManagerStatics3<D>::RequestAccessForAppAsync(hstring_view sourceIdentity, hstring_view appPackageFamilyName, const Windows::Security::EnterpriseData::ProtectionPolicyAuditInfo & auditInfo) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult> result;
    check_hresult(WINRT_SHIM(IProtectionPolicyManagerStatics3)->abi_RequestAccessForAppWithAuditingInfoAsync(get_abi(sourceIdentity), get_abi(appPackageFamilyName), get_abi(auditInfo), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult> impl_IProtectionPolicyManagerStatics3<D>::RequestAccessForAppAsync(hstring_view sourceIdentity, hstring_view appPackageFamilyName, const Windows::Security::EnterpriseData::ProtectionPolicyAuditInfo & auditInfo, hstring_view messageFromApp) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult> result;
    check_hresult(WINRT_SHIM(IProtectionPolicyManagerStatics3)->abi_RequestAccessForAppWithMessageAsync(get_abi(sourceIdentity), get_abi(appPackageFamilyName), get_abi(auditInfo), get_abi(messageFromApp), put_abi(result)));
    return result;
}

template <typename D> void impl_IProtectionPolicyManagerStatics3<D>::LogAuditEvent(hstring_view sourceIdentity, hstring_view targetIdentity, const Windows::Security::EnterpriseData::ProtectionPolicyAuditInfo & auditInfo) const
{
    check_hresult(WINRT_SHIM(IProtectionPolicyManagerStatics3)->abi_LogAuditEvent(get_abi(sourceIdentity), get_abi(targetIdentity), get_abi(auditInfo)));
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IProtectedAccessSuspendingEventArgs<D>::Identities() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(IProtectedAccessSuspendingEventArgs)->get_Identities(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IProtectedAccessSuspendingEventArgs<D>::Deadline() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IProtectedAccessSuspendingEventArgs)->get_Deadline(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Deferral impl_IProtectedAccessSuspendingEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral result { nullptr };
    check_hresult(WINRT_SHIM(IProtectedAccessSuspendingEventArgs)->abi_GetDeferral(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IProtectedAccessResumedEventArgs<D>::Identities() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(IProtectedAccessResumedEventArgs)->get_Identities(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IProtectedContentRevokedEventArgs<D>::Identities() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(IProtectedContentRevokedEventArgs)->get_Identities(put_abi(value)));
    return value;
}

inline Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::BufferProtectUnprotectResult> DataProtectionManager::ProtectAsync(const Windows::Storage::Streams::IBuffer & data, hstring_view identity)
{
    return get_activation_factory<DataProtectionManager, IDataProtectionManagerStatics>().ProtectAsync(data, identity);
}

inline Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::BufferProtectUnprotectResult> DataProtectionManager::UnprotectAsync(const Windows::Storage::Streams::IBuffer & data)
{
    return get_activation_factory<DataProtectionManager, IDataProtectionManagerStatics>().UnprotectAsync(data);
}

inline Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::DataProtectionInfo> DataProtectionManager::ProtectStreamAsync(const Windows::Storage::Streams::IInputStream & unprotectedStream, hstring_view identity, const Windows::Storage::Streams::IOutputStream & protectedStream)
{
    return get_activation_factory<DataProtectionManager, IDataProtectionManagerStatics>().ProtectStreamAsync(unprotectedStream, identity, protectedStream);
}

inline Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::DataProtectionInfo> DataProtectionManager::UnprotectStreamAsync(const Windows::Storage::Streams::IInputStream & protectedStream, const Windows::Storage::Streams::IOutputStream & unprotectedStream)
{
    return get_activation_factory<DataProtectionManager, IDataProtectionManagerStatics>().UnprotectStreamAsync(protectedStream, unprotectedStream);
}

inline Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::DataProtectionInfo> DataProtectionManager::GetProtectionInfoAsync(const Windows::Storage::Streams::IBuffer & protectedData)
{
    return get_activation_factory<DataProtectionManager, IDataProtectionManagerStatics>().GetProtectionInfoAsync(protectedData);
}

inline Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::DataProtectionInfo> DataProtectionManager::GetStreamProtectionInfoAsync(const Windows::Storage::Streams::IInputStream & protectedStream)
{
    return get_activation_factory<DataProtectionManager, IDataProtectionManagerStatics>().GetStreamProtectionInfoAsync(protectedStream);
}

inline Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::FileProtectionInfo> FileProtectionManager::ProtectAsync(const Windows::Storage::IStorageItem & target, hstring_view identity)
{
    return get_activation_factory<FileProtectionManager, IFileProtectionManagerStatics>().ProtectAsync(target, identity);
}

inline Windows::Foundation::IAsyncOperation<bool> FileProtectionManager::CopyProtectionAsync(const Windows::Storage::IStorageItem & source, const Windows::Storage::IStorageItem & target)
{
    return get_activation_factory<FileProtectionManager, IFileProtectionManagerStatics>().CopyProtectionAsync(source, target);
}

inline Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::FileProtectionInfo> FileProtectionManager::GetProtectionInfoAsync(const Windows::Storage::IStorageItem & source)
{
    return get_activation_factory<FileProtectionManager, IFileProtectionManagerStatics>().GetProtectionInfoAsync(source);
}

inline Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::ProtectedContainerExportResult> FileProtectionManager::SaveFileAsContainerAsync(const Windows::Storage::IStorageFile & protectedFile)
{
    return get_activation_factory<FileProtectionManager, IFileProtectionManagerStatics>().SaveFileAsContainerAsync(protectedFile);
}

inline Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::ProtectedContainerImportResult> FileProtectionManager::LoadFileFromContainerAsync(const Windows::Storage::IStorageFile & containerFile)
{
    return get_activation_factory<FileProtectionManager, IFileProtectionManagerStatics>().LoadFileFromContainerAsync(containerFile);
}

inline Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::ProtectedContainerImportResult> FileProtectionManager::LoadFileFromContainerAsync(const Windows::Storage::IStorageFile & containerFile, const Windows::Storage::IStorageItem & target)
{
    return get_activation_factory<FileProtectionManager, IFileProtectionManagerStatics>().LoadFileFromContainerAsync(containerFile, target);
}

inline Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::ProtectedFileCreateResult> FileProtectionManager::CreateProtectedAndOpenAsync(const Windows::Storage::IStorageFolder & parentFolder, hstring_view desiredName, hstring_view identity, Windows::Storage::CreationCollisionOption collisionOption)
{
    return get_activation_factory<FileProtectionManager, IFileProtectionManagerStatics>().CreateProtectedAndOpenAsync(parentFolder, desiredName, identity, collisionOption);
}

inline Windows::Foundation::IAsyncOperation<bool> FileProtectionManager::IsContainerAsync(const Windows::Storage::IStorageFile & file)
{
    return get_activation_factory<FileProtectionManager, IFileProtectionManagerStatics2>().IsContainerAsync(file);
}

inline Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::ProtectedContainerImportResult> FileProtectionManager::LoadFileFromContainerAsync(const Windows::Storage::IStorageFile & containerFile, const Windows::Storage::IStorageItem & target, Windows::Storage::NameCollisionOption collisionOption)
{
    return get_activation_factory<FileProtectionManager, IFileProtectionManagerStatics2>().LoadFileFromContainerAsync(containerFile, target, collisionOption);
}

inline Windows::Foundation::IAsyncOperation<Windows::Security::EnterpriseData::ProtectedContainerExportResult> FileProtectionManager::SaveFileAsContainerAsync(const Windows::Storage::IStorageFile & protectedFile, iterable<hstring> sharedWithIdentities)
{
    return get_activation_factory<FileProtectionManager, IFileProtectionManagerStatics2>().SaveFileAsContainerAsync(protectedFile, sharedWithIdentities);
}

inline Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::FileProtectionStatus> FileRevocationManager::ProtectAsync(const Windows::Storage::IStorageItem & storageItem, hstring_view enterpriseIdentity)
{
    return get_activation_factory<FileRevocationManager, IFileRevocationManagerStatics>().ProtectAsync(storageItem, enterpriseIdentity);
}

inline Windows::Foundation::IAsyncOperation<bool> FileRevocationManager::CopyProtectionAsync(const Windows::Storage::IStorageItem & sourceStorageItem, const Windows::Storage::IStorageItem & targetStorageItem)
{
    return get_activation_factory<FileRevocationManager, IFileRevocationManagerStatics>().CopyProtectionAsync(sourceStorageItem, targetStorageItem);
}

inline void FileRevocationManager::Revoke(hstring_view enterpriseIdentity)
{
    get_activation_factory<FileRevocationManager, IFileRevocationManagerStatics>().Revoke(enterpriseIdentity);
}

inline Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::FileProtectionStatus> FileRevocationManager::GetStatusAsync(const Windows::Storage::IStorageItem & storageItem)
{
    return get_activation_factory<FileRevocationManager, IFileRevocationManagerStatics>().GetStatusAsync(storageItem);
}

inline ProtectionPolicyAuditInfo::ProtectionPolicyAuditInfo(Windows::Security::EnterpriseData::ProtectionPolicyAuditAction action, hstring_view dataDescription, hstring_view sourceDescription, hstring_view targetDescription) :
    ProtectionPolicyAuditInfo(get_activation_factory<ProtectionPolicyAuditInfo, IProtectionPolicyAuditInfoFactory>().Create(action, dataDescription, sourceDescription, targetDescription))
{}

inline ProtectionPolicyAuditInfo::ProtectionPolicyAuditInfo(Windows::Security::EnterpriseData::ProtectionPolicyAuditAction action, hstring_view dataDescription) :
    ProtectionPolicyAuditInfo(get_activation_factory<ProtectionPolicyAuditInfo, IProtectionPolicyAuditInfoFactory>().CreateWithActionAndDataDescription(action, dataDescription))
{}

inline bool ProtectionPolicyManager::IsIdentityManaged(hstring_view identity)
{
    return get_activation_factory<ProtectionPolicyManager, IProtectionPolicyManagerStatics>().IsIdentityManaged(identity);
}

inline bool ProtectionPolicyManager::TryApplyProcessUIPolicy(hstring_view identity)
{
    return get_activation_factory<ProtectionPolicyManager, IProtectionPolicyManagerStatics>().TryApplyProcessUIPolicy(identity);
}

inline void ProtectionPolicyManager::ClearProcessUIPolicy()
{
    get_activation_factory<ProtectionPolicyManager, IProtectionPolicyManagerStatics>().ClearProcessUIPolicy();
}

inline Windows::Security::EnterpriseData::ThreadNetworkContext ProtectionPolicyManager::CreateCurrentThreadNetworkContext(hstring_view identity)
{
    return get_activation_factory<ProtectionPolicyManager, IProtectionPolicyManagerStatics>().CreateCurrentThreadNetworkContext(identity);
}

inline Windows::Foundation::IAsyncOperation<hstring> ProtectionPolicyManager::GetPrimaryManagedIdentityForNetworkEndpointAsync(const Windows::Networking::HostName & endpointHost)
{
    return get_activation_factory<ProtectionPolicyManager, IProtectionPolicyManagerStatics>().GetPrimaryManagedIdentityForNetworkEndpointAsync(endpointHost);
}

inline void ProtectionPolicyManager::RevokeContent(hstring_view identity)
{
    get_activation_factory<ProtectionPolicyManager, IProtectionPolicyManagerStatics>().RevokeContent(identity);
}

inline Windows::Security::EnterpriseData::ProtectionPolicyManager ProtectionPolicyManager::GetForCurrentView()
{
    return get_activation_factory<ProtectionPolicyManager, IProtectionPolicyManagerStatics>().GetForCurrentView();
}

inline event_token ProtectionPolicyManager::ProtectedAccessSuspending(const Windows::Foundation::EventHandler<Windows::Security::EnterpriseData::ProtectedAccessSuspendingEventArgs> & handler)
{
    return get_activation_factory<ProtectionPolicyManager, IProtectionPolicyManagerStatics>().ProtectedAccessSuspending(handler);
}

inline factory_event_revoker<IProtectionPolicyManagerStatics> ProtectionPolicyManager::ProtectedAccessSuspending(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Security::EnterpriseData::ProtectedAccessSuspendingEventArgs> & handler)
{
    auto factory = get_activation_factory<ProtectionPolicyManager, IProtectionPolicyManagerStatics>();
    return { factory, &ABI::Windows::Security::EnterpriseData::IProtectionPolicyManagerStatics::remove_ProtectedAccessSuspending, factory.ProtectedAccessSuspending(handler) };
}

inline void ProtectionPolicyManager::ProtectedAccessSuspending(event_token token)
{
    get_activation_factory<ProtectionPolicyManager, IProtectionPolicyManagerStatics>().ProtectedAccessSuspending(token);
}

inline event_token ProtectionPolicyManager::ProtectedAccessResumed(const Windows::Foundation::EventHandler<Windows::Security::EnterpriseData::ProtectedAccessResumedEventArgs> & handler)
{
    return get_activation_factory<ProtectionPolicyManager, IProtectionPolicyManagerStatics>().ProtectedAccessResumed(handler);
}

inline factory_event_revoker<IProtectionPolicyManagerStatics> ProtectionPolicyManager::ProtectedAccessResumed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Security::EnterpriseData::ProtectedAccessResumedEventArgs> & handler)
{
    auto factory = get_activation_factory<ProtectionPolicyManager, IProtectionPolicyManagerStatics>();
    return { factory, &ABI::Windows::Security::EnterpriseData::IProtectionPolicyManagerStatics::remove_ProtectedAccessResumed, factory.ProtectedAccessResumed(handler) };
}

inline void ProtectionPolicyManager::ProtectedAccessResumed(event_token token)
{
    get_activation_factory<ProtectionPolicyManager, IProtectionPolicyManagerStatics>().ProtectedAccessResumed(token);
}

inline event_token ProtectionPolicyManager::ProtectedContentRevoked(const Windows::Foundation::EventHandler<Windows::Security::EnterpriseData::ProtectedContentRevokedEventArgs> & handler)
{
    return get_activation_factory<ProtectionPolicyManager, IProtectionPolicyManagerStatics>().ProtectedContentRevoked(handler);
}

inline factory_event_revoker<IProtectionPolicyManagerStatics> ProtectionPolicyManager::ProtectedContentRevoked(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Security::EnterpriseData::ProtectedContentRevokedEventArgs> & handler)
{
    auto factory = get_activation_factory<ProtectionPolicyManager, IProtectionPolicyManagerStatics>();
    return { factory, &ABI::Windows::Security::EnterpriseData::IProtectionPolicyManagerStatics::remove_ProtectedContentRevoked, factory.ProtectedContentRevoked(handler) };
}

inline void ProtectionPolicyManager::ProtectedContentRevoked(event_token token)
{
    get_activation_factory<ProtectionPolicyManager, IProtectionPolicyManagerStatics>().ProtectedContentRevoked(token);
}

inline Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult ProtectionPolicyManager::CheckAccess(hstring_view sourceIdentity, hstring_view targetIdentity)
{
    return get_activation_factory<ProtectionPolicyManager, IProtectionPolicyManagerStatics>().CheckAccess(sourceIdentity, targetIdentity);
}

inline Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult> ProtectionPolicyManager::RequestAccessAsync(hstring_view sourceIdentity, hstring_view targetIdentity)
{
    return get_activation_factory<ProtectionPolicyManager, IProtectionPolicyManagerStatics>().RequestAccessAsync(sourceIdentity, targetIdentity);
}

inline bool ProtectionPolicyManager::HasContentBeenRevokedSince(hstring_view identity, const Windows::Foundation::DateTime & since)
{
    return get_activation_factory<ProtectionPolicyManager, IProtectionPolicyManagerStatics2>().HasContentBeenRevokedSince(identity, since);
}

inline Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult ProtectionPolicyManager::CheckAccessForApp(hstring_view sourceIdentity, hstring_view appPackageFamilyName)
{
    return get_activation_factory<ProtectionPolicyManager, IProtectionPolicyManagerStatics2>().CheckAccessForApp(sourceIdentity, appPackageFamilyName);
}

inline Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult> ProtectionPolicyManager::RequestAccessForAppAsync(hstring_view sourceIdentity, hstring_view appPackageFamilyName)
{
    return get_activation_factory<ProtectionPolicyManager, IProtectionPolicyManagerStatics2>().RequestAccessForAppAsync(sourceIdentity, appPackageFamilyName);
}

inline Windows::Security::EnterpriseData::EnforcementLevel ProtectionPolicyManager::GetEnforcementLevel(hstring_view identity)
{
    return get_activation_factory<ProtectionPolicyManager, IProtectionPolicyManagerStatics2>().GetEnforcementLevel(identity);
}

inline bool ProtectionPolicyManager::IsUserDecryptionAllowed(hstring_view identity)
{
    return get_activation_factory<ProtectionPolicyManager, IProtectionPolicyManagerStatics2>().IsUserDecryptionAllowed(identity);
}

inline bool ProtectionPolicyManager::IsProtectionUnderLockRequired(hstring_view identity)
{
    return get_activation_factory<ProtectionPolicyManager, IProtectionPolicyManagerStatics2>().IsProtectionUnderLockRequired(identity);
}

inline event_token ProtectionPolicyManager::PolicyChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    return get_activation_factory<ProtectionPolicyManager, IProtectionPolicyManagerStatics2>().PolicyChanged(handler);
}

inline factory_event_revoker<IProtectionPolicyManagerStatics2> ProtectionPolicyManager::PolicyChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    auto factory = get_activation_factory<ProtectionPolicyManager, IProtectionPolicyManagerStatics2>();
    return { factory, &ABI::Windows::Security::EnterpriseData::IProtectionPolicyManagerStatics2::remove_PolicyChanged, factory.PolicyChanged(handler) };
}

inline void ProtectionPolicyManager::PolicyChanged(event_token token)
{
    get_activation_factory<ProtectionPolicyManager, IProtectionPolicyManagerStatics2>().PolicyChanged(token);
}

inline bool ProtectionPolicyManager::IsProtectionEnabled()
{
    return get_activation_factory<ProtectionPolicyManager, IProtectionPolicyManagerStatics2>().IsProtectionEnabled();
}

inline Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult> ProtectionPolicyManager::RequestAccessAsync(hstring_view sourceIdentity, hstring_view targetIdentity, const Windows::Security::EnterpriseData::ProtectionPolicyAuditInfo & auditInfo)
{
    return get_activation_factory<ProtectionPolicyManager, IProtectionPolicyManagerStatics3>().RequestAccessAsync(sourceIdentity, targetIdentity, auditInfo);
}

inline Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult> ProtectionPolicyManager::RequestAccessAsync(hstring_view sourceIdentity, hstring_view targetIdentity, const Windows::Security::EnterpriseData::ProtectionPolicyAuditInfo & auditInfo, hstring_view messageFromApp)
{
    return get_activation_factory<ProtectionPolicyManager, IProtectionPolicyManagerStatics3>().RequestAccessAsync(sourceIdentity, targetIdentity, auditInfo, messageFromApp);
}

inline Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult> ProtectionPolicyManager::RequestAccessForAppAsync(hstring_view sourceIdentity, hstring_view appPackageFamilyName, const Windows::Security::EnterpriseData::ProtectionPolicyAuditInfo & auditInfo)
{
    return get_activation_factory<ProtectionPolicyManager, IProtectionPolicyManagerStatics3>().RequestAccessForAppAsync(sourceIdentity, appPackageFamilyName, auditInfo);
}

inline Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult> ProtectionPolicyManager::RequestAccessForAppAsync(hstring_view sourceIdentity, hstring_view appPackageFamilyName, const Windows::Security::EnterpriseData::ProtectionPolicyAuditInfo & auditInfo, hstring_view messageFromApp)
{
    return get_activation_factory<ProtectionPolicyManager, IProtectionPolicyManagerStatics3>().RequestAccessForAppAsync(sourceIdentity, appPackageFamilyName, auditInfo, messageFromApp);
}

inline void ProtectionPolicyManager::LogAuditEvent(hstring_view sourceIdentity, hstring_view targetIdentity, const Windows::Security::EnterpriseData::ProtectionPolicyAuditInfo & auditInfo)
{
    get_activation_factory<ProtectionPolicyManager, IProtectionPolicyManagerStatics3>().LogAuditEvent(sourceIdentity, targetIdentity, auditInfo);
}

}

}
#pragma warning(pop)
