// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Phone.PersonalInformation.3.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Phone::PersonalInformation::IContactAddress> : produce_base<D, Windows::Phone::PersonalInformation::IContactAddress>
{
    HRESULT __stdcall get_Country(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Country());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Country(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Country(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Locality(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Locality());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Locality(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Locality(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Region(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Region());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Region(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Region(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PostalCode(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PostalCode());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PostalCode(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PostalCode(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StreetAddress(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StreetAddress());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StreetAddress(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StreetAddress(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Phone::PersonalInformation::IContactChangeRecord> : produce_base<D, Windows::Phone::PersonalInformation::IContactChangeRecord>
{
    HRESULT __stdcall get_ChangeType(Windows::Phone::PersonalInformation::ContactChangeType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ChangeType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RevisionNumber(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RevisionNumber());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall get_RemoteId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RemoteId());
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
struct produce<D, Windows::Phone::PersonalInformation::IContactInformation> : produce_base<D, Windows::Phone::PersonalInformation::IContactInformation>
{
    HRESULT __stdcall get_DisplayName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DisplayName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FamilyName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FamilyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FamilyName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FamilyName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GivenName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GivenName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_GivenName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GivenName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HonorificPrefix(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HonorificPrefix());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_HonorificPrefix(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HonorificPrefix(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HonorificSuffix(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HonorificSuffix());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_HonorificSuffix(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HonorificSuffix(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDisplayPictureAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetDisplayPictureAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetDisplayPictureAsync(impl::abi_arg_in<Windows::Storage::Streams::IInputStream> stream, impl::abi_arg_out<Windows::Foundation::IAsyncAction> action) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *action = detach_abi(this->shim().SetDisplayPictureAsync(*reinterpret_cast<const Windows::Storage::Streams::IInputStream *>(&stream)));
            return S_OK;
        }
        catch (...)
        {
            *action = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayPicture(impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayPicture());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPropertiesAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::IInspectable>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetPropertiesAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ToVcardAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ToVcardAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ToVcardWithOptionsAsync(Windows::Phone::PersonalInformation::VCardFormat format, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ToVcardAsync(format));
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
struct produce<D, Windows::Phone::PersonalInformation::IContactInformation2> : produce_base<D, Windows::Phone::PersonalInformation::IContactInformation2>
{
    HRESULT __stdcall get_DisplayPictureDate(impl::abi_arg_out<Windows::Foundation::DateTime> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().DisplayPictureDate());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DisplayPictureDate(impl::abi_arg_in<Windows::Foundation::DateTime> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayPictureDate(*reinterpret_cast<const Windows::Foundation::DateTime *>(&returnValue));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Phone::PersonalInformation::IContactInformationStatics> : produce_base<D, Windows::Phone::PersonalInformation::IContactInformationStatics>
{
    HRESULT __stdcall abi_ParseVcardAsync(impl::abi_arg_in<Windows::Storage::Streams::IInputStream> vcard, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Phone::PersonalInformation::ContactInformation>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ParseVcardAsync(*reinterpret_cast<const Windows::Storage::Streams::IInputStream *>(&vcard)));
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
struct produce<D, Windows::Phone::PersonalInformation::IContactQueryOptions> : produce_base<D, Windows::Phone::PersonalInformation::IContactQueryOptions>
{
    HRESULT __stdcall get_DesiredFields(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DesiredFields());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OrderBy(Windows::Phone::PersonalInformation::ContactQueryResultOrdering * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OrderBy());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OrderBy(Windows::Phone::PersonalInformation::ContactQueryResultOrdering value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OrderBy(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Phone::PersonalInformation::IContactQueryResult> : produce_base<D, Windows::Phone::PersonalInformation::IContactQueryResult>
{
    HRESULT __stdcall abi_GetContactCountAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<uint32_t>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetContactCountAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetContactsAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Phone::PersonalInformation::StoredContact>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetContactsAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetContactsAsyncInRange(uint32_t startIndex, uint32_t maxNumberOfItems, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Phone::PersonalInformation::StoredContact>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetContactsAsync(startIndex, maxNumberOfItems));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCurrentQueryOptions(impl::abi_arg_out<Windows::Phone::PersonalInformation::IContactQueryOptions> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetCurrentQueryOptions());
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
struct produce<D, Windows::Phone::PersonalInformation::IContactStore> : produce_base<D, Windows::Phone::PersonalInformation::IContactStore>
{
    HRESULT __stdcall abi_FindContactByRemoteIdAsync(impl::abi_arg_in<hstring> id, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Phone::PersonalInformation::StoredContact>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().FindContactByRemoteIdAsync(*reinterpret_cast<const hstring *>(&id)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindContactByIdAsync(impl::abi_arg_in<hstring> id, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Phone::PersonalInformation::StoredContact>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().FindContactByIdAsync(*reinterpret_cast<const hstring *>(&id)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteContactAsync(impl::abi_arg_in<hstring> id, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().DeleteContactAsync(*reinterpret_cast<const hstring *>(&id)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateContactQueryDefault(impl::abi_arg_out<Windows::Phone::PersonalInformation::IContactQueryResult> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateContactQuery());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateContactQueryWithOptions(impl::abi_arg_in<Windows::Phone::PersonalInformation::IContactQueryOptions> options, impl::abi_arg_out<Windows::Phone::PersonalInformation::IContactQueryResult> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateContactQuery(*reinterpret_cast<const Windows::Phone::PersonalInformation::ContactQueryOptions *>(&options)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().DeleteAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RevisionNumber(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RevisionNumber());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetChangesAsync(uint64_t baseRevisionNumber, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Phone::PersonalInformation::ContactChangeRecord>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetChangesAsync(baseRevisionNumber));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LoadExtendedPropertiesAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::IInspectable>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().LoadExtendedPropertiesAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SaveExtendedPropertiesAsync(impl::abi_arg_in<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> data, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().SaveExtendedPropertiesAsync(*reinterpret_cast<const Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> *>(&data)));
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
struct produce<D, Windows::Phone::PersonalInformation::IContactStore2> : produce_base<D, Windows::Phone::PersonalInformation::IContactStore2>
{
    HRESULT __stdcall abi_CreateMeContactAsync(impl::abi_arg_in<hstring> id, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Phone::PersonalInformation::StoredContact>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreateMeContactAsync(*reinterpret_cast<const hstring *>(&id)));
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
struct produce<D, Windows::Phone::PersonalInformation::IContactStoreStatics> : produce_base<D, Windows::Phone::PersonalInformation::IContactStoreStatics>
{
    HRESULT __stdcall abi_CreateOrOpenAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Phone::PersonalInformation::ContactStore>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreateOrOpenAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateOrOpenWithOptionsAsync(Windows::Phone::PersonalInformation::ContactStoreSystemAccessMode access, Windows::Phone::PersonalInformation::ContactStoreApplicationAccessMode sharing, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Phone::PersonalInformation::ContactStore>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreateOrOpenAsync(access, sharing));
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
struct produce<D, Windows::Phone::PersonalInformation::IKnownContactPropertiesStatics> : produce_base<D, Windows::Phone::PersonalInformation::IKnownContactPropertiesStatics>
{
    HRESULT __stdcall get_DisplayName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FamilyName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FamilyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GivenName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GivenName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HonorificPrefix(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HonorificPrefix());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HonorificSuffix(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HonorificSuffix());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AdditionalName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AdditionalName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Address(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Address());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OtherAddress(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OtherAddress());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Email(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Email());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WorkAddress(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WorkAddress());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WorkTelephone(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WorkTelephone());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_JobTitle(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().JobTitle());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Birthdate(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Birthdate());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Anniversary(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Anniversary());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Telephone(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Telephone());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MobileTelephone(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MobileTelephone());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Url(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Url());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Notes(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Notes());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WorkFax(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WorkFax());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Children(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Children());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SignificantOther(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SignificantOther());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CompanyName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CompanyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CompanyTelephone(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CompanyTelephone());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HomeFax(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HomeFax());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AlternateTelephone(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AlternateTelephone());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Manager(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Manager());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Nickname(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Nickname());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OfficeLocation(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OfficeLocation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WorkEmail(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WorkEmail());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_YomiGivenName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().YomiGivenName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_YomiFamilyName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().YomiFamilyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_YomiCompanyName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().YomiCompanyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OtherEmail(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OtherEmail());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AlternateMobileTelephone(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AlternateMobileTelephone());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AlternateWorkTelephone(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AlternateWorkTelephone());
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
struct produce<D, Windows::Phone::PersonalInformation::IStoredContact> : produce_base<D, Windows::Phone::PersonalInformation::IStoredContact>
{
    HRESULT __stdcall get_Store(impl::abi_arg_out<Windows::Phone::PersonalInformation::IContactStore> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Store());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall get_RemoteId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RemoteId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RemoteId(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoteId(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetExtendedPropertiesAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::IInspectable>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetExtendedPropertiesAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SaveAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().SaveAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReplaceExistingContactAsync(impl::abi_arg_in<hstring> id, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReplaceExistingContactAsync(*reinterpret_cast<const hstring *>(&id)));
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
struct produce<D, Windows::Phone::PersonalInformation::IStoredContactFactory> : produce_base<D, Windows::Phone::PersonalInformation::IStoredContactFactory>
{
    HRESULT __stdcall abi_CreateStoredContact(impl::abi_arg_in<Windows::Phone::PersonalInformation::IContactStore> store, impl::abi_arg_out<Windows::Phone::PersonalInformation::IStoredContact> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateStoredContact(*reinterpret_cast<const Windows::Phone::PersonalInformation::ContactStore *>(&store)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateStoredContactFromInformation(impl::abi_arg_in<Windows::Phone::PersonalInformation::IContactStore> store, impl::abi_arg_in<Windows::Phone::PersonalInformation::IContactInformation> contact, impl::abi_arg_out<Windows::Phone::PersonalInformation::IStoredContact> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateStoredContactFromInformation(*reinterpret_cast<const Windows::Phone::PersonalInformation::ContactStore *>(&store), *reinterpret_cast<const Windows::Phone::PersonalInformation::ContactInformation *>(&contact)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Phone::PersonalInformation {

template <typename D> hstring impl_IContactAddress<D>::Country() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactAddress)->get_Country(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactAddress<D>::Country(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactAddress)->put_Country(get_abi(value)));
}

template <typename D> hstring impl_IContactAddress<D>::Locality() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactAddress)->get_Locality(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactAddress<D>::Locality(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactAddress)->put_Locality(get_abi(value)));
}

template <typename D> hstring impl_IContactAddress<D>::Region() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactAddress)->get_Region(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactAddress<D>::Region(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactAddress)->put_Region(get_abi(value)));
}

template <typename D> hstring impl_IContactAddress<D>::PostalCode() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactAddress)->get_PostalCode(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactAddress<D>::PostalCode(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactAddress)->put_PostalCode(get_abi(value)));
}

template <typename D> hstring impl_IContactAddress<D>::StreetAddress() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactAddress)->get_StreetAddress(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactAddress<D>::StreetAddress(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactAddress)->put_StreetAddress(get_abi(value)));
}

template <typename D> hstring impl_IContactInformation<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactInformation)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactInformation<D>::DisplayName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactInformation)->put_DisplayName(get_abi(value)));
}

template <typename D> hstring impl_IContactInformation<D>::FamilyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactInformation)->get_FamilyName(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactInformation<D>::FamilyName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactInformation)->put_FamilyName(get_abi(value)));
}

template <typename D> hstring impl_IContactInformation<D>::GivenName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactInformation)->get_GivenName(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactInformation<D>::GivenName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactInformation)->put_GivenName(get_abi(value)));
}

template <typename D> hstring impl_IContactInformation<D>::HonorificPrefix() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactInformation)->get_HonorificPrefix(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactInformation<D>::HonorificPrefix(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactInformation)->put_HonorificPrefix(get_abi(value)));
}

template <typename D> hstring impl_IContactInformation<D>::HonorificSuffix() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactInformation)->get_HonorificSuffix(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactInformation<D>::HonorificSuffix(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactInformation)->put_HonorificSuffix(get_abi(value)));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream> impl_IContactInformation<D>::GetDisplayPictureAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream> operation;
    check_hresult(WINRT_SHIM(IContactInformation)->abi_GetDisplayPictureAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IContactInformation<D>::SetDisplayPictureAsync(const Windows::Storage::Streams::IInputStream & stream) const
{
    Windows::Foundation::IAsyncAction action;
    check_hresult(WINRT_SHIM(IContactInformation)->abi_SetDisplayPictureAsync(get_abi(stream), put_abi(action)));
    return action;
}

template <typename D> Windows::Storage::Streams::IRandomAccessStreamReference impl_IContactInformation<D>::DisplayPicture() const
{
    Windows::Storage::Streams::IRandomAccessStreamReference value;
    check_hresult(WINRT_SHIM(IContactInformation)->get_DisplayPicture(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::IInspectable>> impl_IContactInformation<D>::GetPropertiesAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::IInspectable>> operation;
    check_hresult(WINRT_SHIM(IContactInformation)->abi_GetPropertiesAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream> impl_IContactInformation<D>::ToVcardAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream> operation;
    check_hresult(WINRT_SHIM(IContactInformation)->abi_ToVcardAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream> impl_IContactInformation<D>::ToVcardAsync(Windows::Phone::PersonalInformation::VCardFormat format) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream> operation;
    check_hresult(WINRT_SHIM(IContactInformation)->abi_ToVcardWithOptionsAsync(format, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::DateTime impl_IContactInformation2<D>::DisplayPictureDate() const
{
    Windows::Foundation::DateTime returnValue {};
    check_hresult(WINRT_SHIM(IContactInformation2)->get_DisplayPictureDate(put_abi(returnValue)));
    return returnValue;
}

template <typename D> void impl_IContactInformation2<D>::DisplayPictureDate(const Windows::Foundation::DateTime & returnValue) const
{
    check_hresult(WINRT_SHIM(IContactInformation2)->put_DisplayPictureDate(get_abi(returnValue)));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Phone::PersonalInformation::ContactInformation> impl_IContactInformationStatics<D>::ParseVcardAsync(const Windows::Storage::Streams::IInputStream & vcard) const
{
    Windows::Foundation::IAsyncOperation<Windows::Phone::PersonalInformation::ContactInformation> operation;
    check_hresult(WINRT_SHIM(IContactInformationStatics)->abi_ParseVcardAsync(get_abi(vcard), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Phone::PersonalInformation::ContactStore impl_IStoredContact<D>::Store() const
{
    Windows::Phone::PersonalInformation::ContactStore value { nullptr };
    check_hresult(WINRT_SHIM(IStoredContact)->get_Store(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStoredContact<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStoredContact)->get_Id(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStoredContact<D>::RemoteId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStoredContact)->get_RemoteId(put_abi(value)));
    return value;
}

template <typename D> void impl_IStoredContact<D>::RemoteId(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IStoredContact)->put_RemoteId(get_abi(value)));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::IInspectable>> impl_IStoredContact<D>::GetExtendedPropertiesAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::IInspectable>> operation;
    check_hresult(WINRT_SHIM(IStoredContact)->abi_GetExtendedPropertiesAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IStoredContact<D>::SaveAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IStoredContact)->abi_SaveAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IStoredContact<D>::ReplaceExistingContactAsync(hstring_view id) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IStoredContact)->abi_ReplaceExistingContactAsync(get_abi(id), put_abi(result)));
    return result;
}

template <typename D> Windows::Phone::PersonalInformation::StoredContact impl_IStoredContactFactory<D>::CreateStoredContact(const Windows::Phone::PersonalInformation::ContactStore & store) const
{
    Windows::Phone::PersonalInformation::StoredContact result { nullptr };
    check_hresult(WINRT_SHIM(IStoredContactFactory)->abi_CreateStoredContact(get_abi(store), put_abi(result)));
    return result;
}

template <typename D> Windows::Phone::PersonalInformation::StoredContact impl_IStoredContactFactory<D>::CreateStoredContactFromInformation(const Windows::Phone::PersonalInformation::ContactStore & store, const Windows::Phone::PersonalInformation::ContactInformation & contact) const
{
    Windows::Phone::PersonalInformation::StoredContact result { nullptr };
    check_hresult(WINRT_SHIM(IStoredContactFactory)->abi_CreateStoredContactFromInformation(get_abi(store), get_abi(contact), put_abi(result)));
    return result;
}

template <typename D> hstring impl_IKnownContactPropertiesStatics<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactPropertiesStatics)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownContactPropertiesStatics<D>::FamilyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactPropertiesStatics)->get_FamilyName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownContactPropertiesStatics<D>::GivenName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactPropertiesStatics)->get_GivenName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownContactPropertiesStatics<D>::HonorificPrefix() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactPropertiesStatics)->get_HonorificPrefix(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownContactPropertiesStatics<D>::HonorificSuffix() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactPropertiesStatics)->get_HonorificSuffix(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownContactPropertiesStatics<D>::AdditionalName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactPropertiesStatics)->get_AdditionalName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownContactPropertiesStatics<D>::Address() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactPropertiesStatics)->get_Address(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownContactPropertiesStatics<D>::OtherAddress() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactPropertiesStatics)->get_OtherAddress(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownContactPropertiesStatics<D>::Email() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactPropertiesStatics)->get_Email(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownContactPropertiesStatics<D>::WorkAddress() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactPropertiesStatics)->get_WorkAddress(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownContactPropertiesStatics<D>::WorkTelephone() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactPropertiesStatics)->get_WorkTelephone(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownContactPropertiesStatics<D>::JobTitle() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactPropertiesStatics)->get_JobTitle(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownContactPropertiesStatics<D>::Birthdate() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactPropertiesStatics)->get_Birthdate(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownContactPropertiesStatics<D>::Anniversary() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactPropertiesStatics)->get_Anniversary(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownContactPropertiesStatics<D>::Telephone() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactPropertiesStatics)->get_Telephone(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownContactPropertiesStatics<D>::MobileTelephone() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactPropertiesStatics)->get_MobileTelephone(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownContactPropertiesStatics<D>::Url() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactPropertiesStatics)->get_Url(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownContactPropertiesStatics<D>::Notes() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactPropertiesStatics)->get_Notes(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownContactPropertiesStatics<D>::WorkFax() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactPropertiesStatics)->get_WorkFax(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownContactPropertiesStatics<D>::Children() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactPropertiesStatics)->get_Children(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownContactPropertiesStatics<D>::SignificantOther() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactPropertiesStatics)->get_SignificantOther(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownContactPropertiesStatics<D>::CompanyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactPropertiesStatics)->get_CompanyName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownContactPropertiesStatics<D>::CompanyTelephone() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactPropertiesStatics)->get_CompanyTelephone(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownContactPropertiesStatics<D>::HomeFax() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactPropertiesStatics)->get_HomeFax(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownContactPropertiesStatics<D>::AlternateTelephone() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactPropertiesStatics)->get_AlternateTelephone(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownContactPropertiesStatics<D>::Manager() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactPropertiesStatics)->get_Manager(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownContactPropertiesStatics<D>::Nickname() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactPropertiesStatics)->get_Nickname(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownContactPropertiesStatics<D>::OfficeLocation() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactPropertiesStatics)->get_OfficeLocation(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownContactPropertiesStatics<D>::WorkEmail() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactPropertiesStatics)->get_WorkEmail(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownContactPropertiesStatics<D>::YomiGivenName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactPropertiesStatics)->get_YomiGivenName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownContactPropertiesStatics<D>::YomiFamilyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactPropertiesStatics)->get_YomiFamilyName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownContactPropertiesStatics<D>::YomiCompanyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactPropertiesStatics)->get_YomiCompanyName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownContactPropertiesStatics<D>::OtherEmail() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactPropertiesStatics)->get_OtherEmail(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownContactPropertiesStatics<D>::AlternateMobileTelephone() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactPropertiesStatics)->get_AlternateMobileTelephone(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownContactPropertiesStatics<D>::AlternateWorkTelephone() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactPropertiesStatics)->get_AlternateWorkTelephone(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<uint32_t> impl_IContactQueryResult<D>::GetContactCountAsync() const
{
    Windows::Foundation::IAsyncOperation<uint32_t> operation;
    check_hresult(WINRT_SHIM(IContactQueryResult)->abi_GetContactCountAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Phone::PersonalInformation::StoredContact>> impl_IContactQueryResult<D>::GetContactsAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Phone::PersonalInformation::StoredContact>> operation;
    check_hresult(WINRT_SHIM(IContactQueryResult)->abi_GetContactsAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Phone::PersonalInformation::StoredContact>> impl_IContactQueryResult<D>::GetContactsAsync(uint32_t startIndex, uint32_t maxNumberOfItems) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Phone::PersonalInformation::StoredContact>> operation;
    check_hresult(WINRT_SHIM(IContactQueryResult)->abi_GetContactsAsyncInRange(startIndex, maxNumberOfItems, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Phone::PersonalInformation::ContactQueryOptions impl_IContactQueryResult<D>::GetCurrentQueryOptions() const
{
    Windows::Phone::PersonalInformation::ContactQueryOptions value { nullptr };
    check_hresult(WINRT_SHIM(IContactQueryResult)->abi_GetCurrentQueryOptions(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IContactQueryOptions<D>::DesiredFields() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IContactQueryOptions)->get_DesiredFields(put_abi(value)));
    return value;
}

template <typename D> Windows::Phone::PersonalInformation::ContactQueryResultOrdering impl_IContactQueryOptions<D>::OrderBy() const
{
    Windows::Phone::PersonalInformation::ContactQueryResultOrdering value {};
    check_hresult(WINRT_SHIM(IContactQueryOptions)->get_OrderBy(&value));
    return value;
}

template <typename D> void impl_IContactQueryOptions<D>::OrderBy(Windows::Phone::PersonalInformation::ContactQueryResultOrdering value) const
{
    check_hresult(WINRT_SHIM(IContactQueryOptions)->put_OrderBy(value));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Phone::PersonalInformation::StoredContact> impl_IContactStore<D>::FindContactByRemoteIdAsync(hstring_view id) const
{
    Windows::Foundation::IAsyncOperation<Windows::Phone::PersonalInformation::StoredContact> operation;
    check_hresult(WINRT_SHIM(IContactStore)->abi_FindContactByRemoteIdAsync(get_abi(id), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Phone::PersonalInformation::StoredContact> impl_IContactStore<D>::FindContactByIdAsync(hstring_view id) const
{
    Windows::Foundation::IAsyncOperation<Windows::Phone::PersonalInformation::StoredContact> operation;
    check_hresult(WINRT_SHIM(IContactStore)->abi_FindContactByIdAsync(get_abi(id), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IContactStore<D>::DeleteContactAsync(hstring_view id) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IContactStore)->abi_DeleteContactAsync(get_abi(id), put_abi(result)));
    return result;
}

template <typename D> Windows::Phone::PersonalInformation::ContactQueryResult impl_IContactStore<D>::CreateContactQuery() const
{
    Windows::Phone::PersonalInformation::ContactQueryResult result { nullptr };
    check_hresult(WINRT_SHIM(IContactStore)->abi_CreateContactQueryDefault(put_abi(result)));
    return result;
}

template <typename D> Windows::Phone::PersonalInformation::ContactQueryResult impl_IContactStore<D>::CreateContactQuery(const Windows::Phone::PersonalInformation::ContactQueryOptions & options) const
{
    Windows::Phone::PersonalInformation::ContactQueryResult result { nullptr };
    check_hresult(WINRT_SHIM(IContactStore)->abi_CreateContactQueryWithOptions(get_abi(options), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IContactStore<D>::DeleteAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IContactStore)->abi_DeleteAsync(put_abi(result)));
    return result;
}

template <typename D> uint64_t impl_IContactStore<D>::RevisionNumber() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IContactStore)->get_RevisionNumber(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Phone::PersonalInformation::ContactChangeRecord>> impl_IContactStore<D>::GetChangesAsync(uint64_t baseRevisionNumber) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Phone::PersonalInformation::ContactChangeRecord>> operation;
    check_hresult(WINRT_SHIM(IContactStore)->abi_GetChangesAsync(baseRevisionNumber, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::IInspectable>> impl_IContactStore<D>::LoadExtendedPropertiesAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::IInspectable>> operation;
    check_hresult(WINRT_SHIM(IContactStore)->abi_LoadExtendedPropertiesAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IContactStore<D>::SaveExtendedPropertiesAsync(map_view<hstring, Windows::Foundation::IInspectable> data) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IContactStore)->abi_SaveExtendedPropertiesAsync(get_abi(data), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Phone::PersonalInformation::StoredContact> impl_IContactStore2<D>::CreateMeContactAsync(hstring_view id) const
{
    Windows::Foundation::IAsyncOperation<Windows::Phone::PersonalInformation::StoredContact> operation;
    check_hresult(WINRT_SHIM(IContactStore2)->abi_CreateMeContactAsync(get_abi(id), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Phone::PersonalInformation::ContactStore> impl_IContactStoreStatics<D>::CreateOrOpenAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Phone::PersonalInformation::ContactStore> operation;
    check_hresult(WINRT_SHIM(IContactStoreStatics)->abi_CreateOrOpenAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Phone::PersonalInformation::ContactStore> impl_IContactStoreStatics<D>::CreateOrOpenAsync(Windows::Phone::PersonalInformation::ContactStoreSystemAccessMode access, Windows::Phone::PersonalInformation::ContactStoreApplicationAccessMode sharing) const
{
    Windows::Foundation::IAsyncOperation<Windows::Phone::PersonalInformation::ContactStore> operation;
    check_hresult(WINRT_SHIM(IContactStoreStatics)->abi_CreateOrOpenWithOptionsAsync(access, sharing, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Phone::PersonalInformation::ContactChangeType impl_IContactChangeRecord<D>::ChangeType() const
{
    Windows::Phone::PersonalInformation::ContactChangeType value {};
    check_hresult(WINRT_SHIM(IContactChangeRecord)->get_ChangeType(&value));
    return value;
}

template <typename D> uint64_t impl_IContactChangeRecord<D>::RevisionNumber() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IContactChangeRecord)->get_RevisionNumber(&value));
    return value;
}

template <typename D> hstring impl_IContactChangeRecord<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactChangeRecord)->get_Id(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContactChangeRecord<D>::RemoteId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactChangeRecord)->get_RemoteId(put_abi(value)));
    return value;
}

inline ContactAddress::ContactAddress() :
    ContactAddress(activate_instance<ContactAddress>())
{}

inline ContactInformation::ContactInformation() :
    ContactInformation(activate_instance<ContactInformation>())
{}

inline Windows::Foundation::IAsyncOperation<Windows::Phone::PersonalInformation::ContactInformation> ContactInformation::ParseVcardAsync(const Windows::Storage::Streams::IInputStream & vcard)
{
    return get_activation_factory<ContactInformation, IContactInformationStatics>().ParseVcardAsync(vcard);
}

inline ContactQueryOptions::ContactQueryOptions() :
    ContactQueryOptions(activate_instance<ContactQueryOptions>())
{}

inline Windows::Foundation::IAsyncOperation<Windows::Phone::PersonalInformation::ContactStore> ContactStore::CreateOrOpenAsync()
{
    return get_activation_factory<ContactStore, IContactStoreStatics>().CreateOrOpenAsync();
}

inline Windows::Foundation::IAsyncOperation<Windows::Phone::PersonalInformation::ContactStore> ContactStore::CreateOrOpenAsync(Windows::Phone::PersonalInformation::ContactStoreSystemAccessMode access, Windows::Phone::PersonalInformation::ContactStoreApplicationAccessMode sharing)
{
    return get_activation_factory<ContactStore, IContactStoreStatics>().CreateOrOpenAsync(access, sharing);
}

inline hstring KnownContactProperties::DisplayName()
{
    return get_activation_factory<KnownContactProperties, IKnownContactPropertiesStatics>().DisplayName();
}

inline hstring KnownContactProperties::FamilyName()
{
    return get_activation_factory<KnownContactProperties, IKnownContactPropertiesStatics>().FamilyName();
}

inline hstring KnownContactProperties::GivenName()
{
    return get_activation_factory<KnownContactProperties, IKnownContactPropertiesStatics>().GivenName();
}

inline hstring KnownContactProperties::HonorificPrefix()
{
    return get_activation_factory<KnownContactProperties, IKnownContactPropertiesStatics>().HonorificPrefix();
}

inline hstring KnownContactProperties::HonorificSuffix()
{
    return get_activation_factory<KnownContactProperties, IKnownContactPropertiesStatics>().HonorificSuffix();
}

inline hstring KnownContactProperties::AdditionalName()
{
    return get_activation_factory<KnownContactProperties, IKnownContactPropertiesStatics>().AdditionalName();
}

inline hstring KnownContactProperties::Address()
{
    return get_activation_factory<KnownContactProperties, IKnownContactPropertiesStatics>().Address();
}

inline hstring KnownContactProperties::OtherAddress()
{
    return get_activation_factory<KnownContactProperties, IKnownContactPropertiesStatics>().OtherAddress();
}

inline hstring KnownContactProperties::Email()
{
    return get_activation_factory<KnownContactProperties, IKnownContactPropertiesStatics>().Email();
}

inline hstring KnownContactProperties::WorkAddress()
{
    return get_activation_factory<KnownContactProperties, IKnownContactPropertiesStatics>().WorkAddress();
}

inline hstring KnownContactProperties::WorkTelephone()
{
    return get_activation_factory<KnownContactProperties, IKnownContactPropertiesStatics>().WorkTelephone();
}

inline hstring KnownContactProperties::JobTitle()
{
    return get_activation_factory<KnownContactProperties, IKnownContactPropertiesStatics>().JobTitle();
}

inline hstring KnownContactProperties::Birthdate()
{
    return get_activation_factory<KnownContactProperties, IKnownContactPropertiesStatics>().Birthdate();
}

inline hstring KnownContactProperties::Anniversary()
{
    return get_activation_factory<KnownContactProperties, IKnownContactPropertiesStatics>().Anniversary();
}

inline hstring KnownContactProperties::Telephone()
{
    return get_activation_factory<KnownContactProperties, IKnownContactPropertiesStatics>().Telephone();
}

inline hstring KnownContactProperties::MobileTelephone()
{
    return get_activation_factory<KnownContactProperties, IKnownContactPropertiesStatics>().MobileTelephone();
}

inline hstring KnownContactProperties::Url()
{
    return get_activation_factory<KnownContactProperties, IKnownContactPropertiesStatics>().Url();
}

inline hstring KnownContactProperties::Notes()
{
    return get_activation_factory<KnownContactProperties, IKnownContactPropertiesStatics>().Notes();
}

inline hstring KnownContactProperties::WorkFax()
{
    return get_activation_factory<KnownContactProperties, IKnownContactPropertiesStatics>().WorkFax();
}

inline hstring KnownContactProperties::Children()
{
    return get_activation_factory<KnownContactProperties, IKnownContactPropertiesStatics>().Children();
}

inline hstring KnownContactProperties::SignificantOther()
{
    return get_activation_factory<KnownContactProperties, IKnownContactPropertiesStatics>().SignificantOther();
}

inline hstring KnownContactProperties::CompanyName()
{
    return get_activation_factory<KnownContactProperties, IKnownContactPropertiesStatics>().CompanyName();
}

inline hstring KnownContactProperties::CompanyTelephone()
{
    return get_activation_factory<KnownContactProperties, IKnownContactPropertiesStatics>().CompanyTelephone();
}

inline hstring KnownContactProperties::HomeFax()
{
    return get_activation_factory<KnownContactProperties, IKnownContactPropertiesStatics>().HomeFax();
}

inline hstring KnownContactProperties::AlternateTelephone()
{
    return get_activation_factory<KnownContactProperties, IKnownContactPropertiesStatics>().AlternateTelephone();
}

inline hstring KnownContactProperties::Manager()
{
    return get_activation_factory<KnownContactProperties, IKnownContactPropertiesStatics>().Manager();
}

inline hstring KnownContactProperties::Nickname()
{
    return get_activation_factory<KnownContactProperties, IKnownContactPropertiesStatics>().Nickname();
}

inline hstring KnownContactProperties::OfficeLocation()
{
    return get_activation_factory<KnownContactProperties, IKnownContactPropertiesStatics>().OfficeLocation();
}

inline hstring KnownContactProperties::WorkEmail()
{
    return get_activation_factory<KnownContactProperties, IKnownContactPropertiesStatics>().WorkEmail();
}

inline hstring KnownContactProperties::YomiGivenName()
{
    return get_activation_factory<KnownContactProperties, IKnownContactPropertiesStatics>().YomiGivenName();
}

inline hstring KnownContactProperties::YomiFamilyName()
{
    return get_activation_factory<KnownContactProperties, IKnownContactPropertiesStatics>().YomiFamilyName();
}

inline hstring KnownContactProperties::YomiCompanyName()
{
    return get_activation_factory<KnownContactProperties, IKnownContactPropertiesStatics>().YomiCompanyName();
}

inline hstring KnownContactProperties::OtherEmail()
{
    return get_activation_factory<KnownContactProperties, IKnownContactPropertiesStatics>().OtherEmail();
}

inline hstring KnownContactProperties::AlternateMobileTelephone()
{
    return get_activation_factory<KnownContactProperties, IKnownContactPropertiesStatics>().AlternateMobileTelephone();
}

inline hstring KnownContactProperties::AlternateWorkTelephone()
{
    return get_activation_factory<KnownContactProperties, IKnownContactPropertiesStatics>().AlternateWorkTelephone();
}

inline StoredContact::StoredContact(const Windows::Phone::PersonalInformation::ContactStore & store) :
    StoredContact(get_activation_factory<StoredContact, IStoredContactFactory>().CreateStoredContact(store))
{}

inline StoredContact::StoredContact(const Windows::Phone::PersonalInformation::ContactStore & store, const Windows::Phone::PersonalInformation::ContactInformation & contact) :
    StoredContact(get_activation_factory<StoredContact, IStoredContactFactory>().CreateStoredContactFromInformation(store, contact))
{}

}

}
#pragma warning(pop)
