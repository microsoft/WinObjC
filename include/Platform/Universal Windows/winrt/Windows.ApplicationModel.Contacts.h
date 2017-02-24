// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.UI.ViewManagement.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.UI.Popups.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.System.3.h"
#include "internal/Windows.ApplicationModel.Contacts.3.h"
#include "Windows.ApplicationModel.h"
#include "Windows.Foundation.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::Contacts::IAggregateContactManager> : produce_base<D, Windows::ApplicationModel::Contacts::IAggregateContactManager>
{
    HRESULT __stdcall abi_FindRawContactsAsync(impl::abi_arg_in<Windows::ApplicationModel::Contacts::IContact> contact, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::Contact>>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FindRawContactsAsync(*reinterpret_cast<const Windows::ApplicationModel::Contacts::Contact *>(&contact)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryLinkContactsAsync(impl::abi_arg_in<Windows::ApplicationModel::Contacts::IContact> primaryContact, impl::abi_arg_in<Windows::ApplicationModel::Contacts::IContact> secondaryContact, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact>> contact) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *contact = detach_abi(this->shim().TryLinkContactsAsync(*reinterpret_cast<const Windows::ApplicationModel::Contacts::Contact *>(&primaryContact), *reinterpret_cast<const Windows::ApplicationModel::Contacts::Contact *>(&secondaryContact)));
            return S_OK;
        }
        catch (...)
        {
            *contact = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UnlinkRawContactAsync(impl::abi_arg_in<Windows::ApplicationModel::Contacts::IContact> contact, impl::abi_arg_out<Windows::Foundation::IAsyncAction> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UnlinkRawContactAsync(*reinterpret_cast<const Windows::ApplicationModel::Contacts::Contact *>(&contact)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TrySetPreferredSourceForPictureAsync(impl::abi_arg_in<Windows::ApplicationModel::Contacts::IContact> aggregateContact, impl::abi_arg_in<Windows::ApplicationModel::Contacts::IContact> rawContact, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TrySetPreferredSourceForPictureAsync(*reinterpret_cast<const Windows::ApplicationModel::Contacts::Contact *>(&aggregateContact), *reinterpret_cast<const Windows::ApplicationModel::Contacts::Contact *>(&rawContact)));
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
struct produce<D, Windows::ApplicationModel::Contacts::IAggregateContactManager2> : produce_base<D, Windows::ApplicationModel::Contacts::IAggregateContactManager2>
{
    HRESULT __stdcall abi_SetRemoteIdentificationInformationAsync(impl::abi_arg_in<hstring> contactListId, impl::abi_arg_in<hstring> remoteSourceId, impl::abi_arg_in<hstring> accountId, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().SetRemoteIdentificationInformationAsync(*reinterpret_cast<const hstring *>(&contactListId), *reinterpret_cast<const hstring *>(&remoteSourceId), *reinterpret_cast<const hstring *>(&accountId)));
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
struct produce<D, Windows::ApplicationModel::Contacts::IContact> : produce_base<D, Windows::ApplicationModel::Contacts::IContact>
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

    HRESULT __stdcall get_Thumbnail(impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Thumbnail());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Thumbnail(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Thumbnail(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Fields(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::IContactField>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Fields());
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
struct produce<D, Windows::ApplicationModel::Contacts::IContact2> : produce_base<D, Windows::ApplicationModel::Contacts::IContact2>
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

    HRESULT __stdcall put_Id(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Id(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
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

    HRESULT __stdcall put_Notes(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Notes(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Phones(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactPhone>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Phones());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Emails(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactEmail>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Emails());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Addresses(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactAddress>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Addresses());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ConnectedServiceAccounts(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactConnectedServiceAccount>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ConnectedServiceAccounts());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ImportantDates(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactDate>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ImportantDates());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DataSuppliers(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DataSuppliers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_JobInfo(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactJobInfo>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().JobInfo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SignificantOthers(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactSignificantOther>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SignificantOthers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Websites(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactWebsite>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Websites());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProviderProperties(impl::abi_arg_out<Windows::Foundation::Collections::IPropertySet> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProviderProperties());
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
struct produce<D, Windows::ApplicationModel::Contacts::IContact3> : produce_base<D, Windows::ApplicationModel::Contacts::IContact3>
{
    HRESULT __stdcall get_ContactListId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContactListId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayPictureUserUpdateTime(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayPictureUserUpdateTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DisplayPictureUserUpdateTime(impl::abi_arg_in<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayPictureUserUpdateTime(*reinterpret_cast<const Windows::Foundation::DateTime *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsMe(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsMe());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AggregateId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AggregateId());
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

    HRESULT __stdcall get_RingToneToken(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RingToneToken());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RingToneToken(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RingToneToken(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsDisplayPictureManuallySet(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDisplayPictureManuallySet());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LargeDisplayPicture(impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LargeDisplayPicture());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SmallDisplayPicture(impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SmallDisplayPicture());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SourceDisplayPicture(impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourceDisplayPicture());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SourceDisplayPicture(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceDisplayPicture(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TextToneToken(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TextToneToken());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TextToneToken(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TextToneToken(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsAggregate(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsAggregate());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FullName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FullName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayNameOverride(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayNameOverride());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DisplayNameOverride(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayNameOverride(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
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

    HRESULT __stdcall put_Nickname(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Nickname(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SortName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SortName());
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
struct produce<D, Windows::ApplicationModel::Contacts::IContactAddress> : produce_base<D, Windows::ApplicationModel::Contacts::IContactAddress>
{
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

    HRESULT __stdcall get_Kind(Windows::ApplicationModel::Contacts::ContactAddressKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Kind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Kind(Windows::ApplicationModel::Contacts::ContactAddressKind value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Kind(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall put_Description(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Description(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Contacts::IContactAnnotation> : produce_base<D, Windows::ApplicationModel::Contacts::IContactAnnotation>
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

    HRESULT __stdcall get_AnnotationListId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AnnotationListId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContactId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContactId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ContactId(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContactId(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
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

    HRESULT __stdcall get_SupportedOperations(Windows::ApplicationModel::Contacts::ContactAnnotationOperations * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportedOperations());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SupportedOperations(Windows::ApplicationModel::Contacts::ContactAnnotationOperations value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SupportedOperations(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsDisabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDisabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProviderProperties(impl::abi_arg_out<Windows::Foundation::Collections::IPropertySet> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProviderProperties());
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
struct produce<D, Windows::ApplicationModel::Contacts::IContactAnnotationList> : produce_base<D, Windows::ApplicationModel::Contacts::IContactAnnotationList>
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

    HRESULT __stdcall get_ProviderPackageFamilyName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProviderPackageFamilyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UserDataAccountId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UserDataAccountId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeleteAsync());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TrySaveAnnotationAsync(impl::abi_arg_in<Windows::ApplicationModel::Contacts::IContactAnnotation> annotation, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> ppResult) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *ppResult = detach_abi(this->shim().TrySaveAnnotationAsync(*reinterpret_cast<const Windows::ApplicationModel::Contacts::ContactAnnotation *>(&annotation)));
            return S_OK;
        }
        catch (...)
        {
            *ppResult = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAnnotationAsync(impl::abi_arg_in<hstring> annotationId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactAnnotation>> annotation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *annotation = detach_abi(this->shim().GetAnnotationAsync(*reinterpret_cast<const hstring *>(&annotationId)));
            return S_OK;
        }
        catch (...)
        {
            *annotation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAnnotationsByRemoteIdAsync(impl::abi_arg_in<hstring> remoteId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactAnnotation>>> annotations) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *annotations = detach_abi(this->shim().FindAnnotationsByRemoteIdAsync(*reinterpret_cast<const hstring *>(&remoteId)));
            return S_OK;
        }
        catch (...)
        {
            *annotations = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAnnotationsAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactAnnotation>>> annotations) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *annotations = detach_abi(this->shim().FindAnnotationsAsync());
            return S_OK;
        }
        catch (...)
        {
            *annotations = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteAnnotationAsync(impl::abi_arg_in<Windows::ApplicationModel::Contacts::IContactAnnotation> annotation, impl::abi_arg_out<Windows::Foundation::IAsyncAction> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeleteAnnotationAsync(*reinterpret_cast<const Windows::ApplicationModel::Contacts::ContactAnnotation *>(&annotation)));
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
struct produce<D, Windows::ApplicationModel::Contacts::IContactAnnotationStore> : produce_base<D, Windows::ApplicationModel::Contacts::IContactAnnotationStore>
{
    HRESULT __stdcall abi_FindContactIdsByEmailAsync(impl::abi_arg_in<hstring> emailAddress, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<hstring>>> contactIds) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *contactIds = detach_abi(this->shim().FindContactIdsByEmailAsync(*reinterpret_cast<const hstring *>(&emailAddress)));
            return S_OK;
        }
        catch (...)
        {
            *contactIds = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindContactIdsByPhoneNumberAsync(impl::abi_arg_in<hstring> phoneNumber, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<hstring>>> contactIds) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *contactIds = detach_abi(this->shim().FindContactIdsByPhoneNumberAsync(*reinterpret_cast<const hstring *>(&phoneNumber)));
            return S_OK;
        }
        catch (...)
        {
            *contactIds = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAnnotationsForContactAsync(impl::abi_arg_in<Windows::ApplicationModel::Contacts::IContact> contact, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactAnnotation>>> annotations) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *annotations = detach_abi(this->shim().FindAnnotationsForContactAsync(*reinterpret_cast<const Windows::ApplicationModel::Contacts::Contact *>(&contact)));
            return S_OK;
        }
        catch (...)
        {
            *annotations = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DisableAnnotationAsync(impl::abi_arg_in<Windows::ApplicationModel::Contacts::IContactAnnotation> annotation, impl::abi_arg_out<Windows::Foundation::IAsyncAction> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisableAnnotationAsync(*reinterpret_cast<const Windows::ApplicationModel::Contacts::ContactAnnotation *>(&annotation)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateAnnotationListAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactAnnotationList>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateAnnotationListAsync());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateAnnotationListInAccountAsync(impl::abi_arg_in<hstring> userDataAccountId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactAnnotationList>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateAnnotationListAsync(*reinterpret_cast<const hstring *>(&userDataAccountId)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAnnotationListAsync(impl::abi_arg_in<hstring> annotationListId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactAnnotationList>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetAnnotationListAsync(*reinterpret_cast<const hstring *>(&annotationListId)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAnnotationListsAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactAnnotationList>>> lists) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *lists = detach_abi(this->shim().FindAnnotationListsAsync());
            return S_OK;
        }
        catch (...)
        {
            *lists = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Contacts::IContactBatch> : produce_base<D, Windows::ApplicationModel::Contacts::IContactBatch>
{
    HRESULT __stdcall get_Contacts(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::Contact>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Contacts());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Status(Windows::ApplicationModel::Contacts::ContactBatchStatus * value) noexcept override
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
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Contacts::IContactCardDelayedDataLoader> : produce_base<D, Windows::ApplicationModel::Contacts::IContactCardDelayedDataLoader>
{
    HRESULT __stdcall abi_SetData(impl::abi_arg_in<Windows::ApplicationModel::Contacts::IContact> contact) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetData(*reinterpret_cast<const Windows::ApplicationModel::Contacts::Contact *>(&contact));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Contacts::IContactCardOptions> : produce_base<D, Windows::ApplicationModel::Contacts::IContactCardOptions>
{
    HRESULT __stdcall get_HeaderKind(Windows::ApplicationModel::Contacts::ContactCardHeaderKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HeaderKind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_HeaderKind(Windows::ApplicationModel::Contacts::ContactCardHeaderKind value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HeaderKind(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InitialTabKind(Windows::ApplicationModel::Contacts::ContactCardTabKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InitialTabKind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_InitialTabKind(Windows::ApplicationModel::Contacts::ContactCardTabKind value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InitialTabKind(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Contacts::IContactCardOptions2> : produce_base<D, Windows::ApplicationModel::Contacts::IContactCardOptions2>
{
    HRESULT __stdcall get_ServerSearchContactListIds(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServerSearchContactListIds());
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
struct produce<D, Windows::ApplicationModel::Contacts::IContactChange> : produce_base<D, Windows::ApplicationModel::Contacts::IContactChange>
{
    HRESULT __stdcall get_ChangeType(Windows::ApplicationModel::Contacts::ContactChangeType * value) noexcept override
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

    HRESULT __stdcall get_Contact(impl::abi_arg_out<Windows::ApplicationModel::Contacts::IContact> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Contact());
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
struct produce<D, Windows::ApplicationModel::Contacts::IContactChangeReader> : produce_base<D, Windows::ApplicationModel::Contacts::IContactChangeReader>
{
    HRESULT __stdcall abi_AcceptChanges() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AcceptChanges();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AcceptChangesThrough(impl::abi_arg_in<Windows::ApplicationModel::Contacts::IContactChange> lastChangeToAccept) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AcceptChangesThrough(*reinterpret_cast<const Windows::ApplicationModel::Contacts::ContactChange *>(&lastChangeToAccept));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReadBatchAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactChange>>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReadBatchAsync());
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
struct produce<D, Windows::ApplicationModel::Contacts::IContactChangeTracker> : produce_base<D, Windows::ApplicationModel::Contacts::IContactChangeTracker>
{
    HRESULT __stdcall abi_Enable() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Enable();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetChangeReader(impl::abi_arg_out<Windows::ApplicationModel::Contacts::IContactChangeReader> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetChangeReader());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Reset() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Reset();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Contacts::IContactChangedDeferral> : produce_base<D, Windows::ApplicationModel::Contacts::IContactChangedDeferral>
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
struct produce<D, Windows::ApplicationModel::Contacts::IContactChangedEventArgs> : produce_base<D, Windows::ApplicationModel::Contacts::IContactChangedEventArgs>
{
    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::ApplicationModel::Contacts::IContactChangedDeferral> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDeferral());
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
struct produce<D, Windows::ApplicationModel::Contacts::IContactConnectedServiceAccount> : produce_base<D, Windows::ApplicationModel::Contacts::IContactConnectedServiceAccount>
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

    HRESULT __stdcall put_Id(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Id(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServiceName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServiceName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ServiceName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ServiceName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Contacts::IContactDate> : produce_base<D, Windows::ApplicationModel::Contacts::IContactDate>
{
    HRESULT __stdcall get_Day(impl::abi_arg_out<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Day());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Day(impl::abi_arg_in<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Day(*reinterpret_cast<const Windows::Foundation::IReference<uint32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Month(impl::abi_arg_out<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Month());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Month(impl::abi_arg_in<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Month(*reinterpret_cast<const Windows::Foundation::IReference<uint32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Year(impl::abi_arg_out<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Year());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Year(impl::abi_arg_in<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Year(*reinterpret_cast<const Windows::Foundation::IReference<int32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Kind(Windows::ApplicationModel::Contacts::ContactDateKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Kind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Kind(Windows::ApplicationModel::Contacts::ContactDateKind value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Kind(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall put_Description(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Description(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Contacts::IContactEmail> : produce_base<D, Windows::ApplicationModel::Contacts::IContactEmail>
{
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

    HRESULT __stdcall put_Address(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Address(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Kind(Windows::ApplicationModel::Contacts::ContactEmailKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Kind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Kind(Windows::ApplicationModel::Contacts::ContactEmailKind value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Kind(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall put_Description(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Description(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Contacts::IContactField> : produce_base<D, Windows::ApplicationModel::Contacts::IContactField>
{
    HRESULT __stdcall get_Type(Windows::ApplicationModel::Contacts::ContactFieldType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Type());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Category(Windows::ApplicationModel::Contacts::ContactFieldCategory * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Category());
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

    HRESULT __stdcall get_Value(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Value());
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
struct produce<D, Windows::ApplicationModel::Contacts::IContactFieldFactory> : produce_base<D, Windows::ApplicationModel::Contacts::IContactFieldFactory>
{
    HRESULT __stdcall abi_CreateField_Default(impl::abi_arg_in<hstring> value, Windows::ApplicationModel::Contacts::ContactFieldType type, impl::abi_arg_out<Windows::ApplicationModel::Contacts::IContactField> field) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *field = detach_abi(this->shim().CreateField(*reinterpret_cast<const hstring *>(&value), type));
            return S_OK;
        }
        catch (...)
        {
            *field = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateField_Category(impl::abi_arg_in<hstring> value, Windows::ApplicationModel::Contacts::ContactFieldType type, Windows::ApplicationModel::Contacts::ContactFieldCategory category, impl::abi_arg_out<Windows::ApplicationModel::Contacts::IContactField> field) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *field = detach_abi(this->shim().CreateField(*reinterpret_cast<const hstring *>(&value), type, category));
            return S_OK;
        }
        catch (...)
        {
            *field = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateField_Custom(impl::abi_arg_in<hstring> name, impl::abi_arg_in<hstring> value, Windows::ApplicationModel::Contacts::ContactFieldType type, Windows::ApplicationModel::Contacts::ContactFieldCategory category, impl::abi_arg_out<Windows::ApplicationModel::Contacts::IContactField> field) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *field = detach_abi(this->shim().CreateField(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const hstring *>(&value), type, category));
            return S_OK;
        }
        catch (...)
        {
            *field = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Contacts::IContactInformation> : produce_base<D, Windows::ApplicationModel::Contacts::IContactInformation>
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

    HRESULT __stdcall abi_GetThumbnailAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamWithContentType>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetThumbnailAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Emails(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactField>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Emails());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PhoneNumbers(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactField>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PhoneNumbers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Locations(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactLocationField>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Locations());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InstantMessages(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactInstantMessageField>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InstantMessages());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CustomFields(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactField>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CustomFields());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_QueryCustomFields(impl::abi_arg_in<hstring> customName, impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactField>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().QueryCustomFields(*reinterpret_cast<const hstring *>(&customName)));
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
struct produce<D, Windows::ApplicationModel::Contacts::IContactInstantMessageField> : produce_base<D, Windows::ApplicationModel::Contacts::IContactInstantMessageField>
{
    HRESULT __stdcall get_UserName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UserName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Service(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Service());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayText(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayText());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LaunchUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LaunchUri());
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
struct produce<D, Windows::ApplicationModel::Contacts::IContactInstantMessageFieldFactory> : produce_base<D, Windows::ApplicationModel::Contacts::IContactInstantMessageFieldFactory>
{
    HRESULT __stdcall abi_CreateInstantMessage_Default(impl::abi_arg_in<hstring> userName, impl::abi_arg_out<Windows::ApplicationModel::Contacts::IContactInstantMessageField> field) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *field = detach_abi(this->shim().CreateInstantMessage(*reinterpret_cast<const hstring *>(&userName)));
            return S_OK;
        }
        catch (...)
        {
            *field = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateInstantMessage_Category(impl::abi_arg_in<hstring> userName, Windows::ApplicationModel::Contacts::ContactFieldCategory category, impl::abi_arg_out<Windows::ApplicationModel::Contacts::IContactInstantMessageField> field) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *field = detach_abi(this->shim().CreateInstantMessage(*reinterpret_cast<const hstring *>(&userName), category));
            return S_OK;
        }
        catch (...)
        {
            *field = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateInstantMessage_All(impl::abi_arg_in<hstring> userName, Windows::ApplicationModel::Contacts::ContactFieldCategory category, impl::abi_arg_in<hstring> service, impl::abi_arg_in<hstring> displayText, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> verb, impl::abi_arg_out<Windows::ApplicationModel::Contacts::IContactInstantMessageField> field) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *field = detach_abi(this->shim().CreateInstantMessage(*reinterpret_cast<const hstring *>(&userName), category, *reinterpret_cast<const hstring *>(&service), *reinterpret_cast<const hstring *>(&displayText), *reinterpret_cast<const Windows::Foundation::Uri *>(&verb)));
            return S_OK;
        }
        catch (...)
        {
            *field = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Contacts::IContactJobInfo> : produce_base<D, Windows::ApplicationModel::Contacts::IContactJobInfo>
{
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

    HRESULT __stdcall put_CompanyName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CompanyName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CompanyYomiName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CompanyYomiName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CompanyYomiName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CompanyYomiName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Department(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Department());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Department(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Department(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Title(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Title());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Title(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Title(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
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

    HRESULT __stdcall put_Manager(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Manager(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Office(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Office());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Office(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Office(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CompanyAddress(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CompanyAddress());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CompanyAddress(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CompanyAddress(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall put_Description(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Description(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Contacts::IContactLaunchActionVerbsStatics> : produce_base<D, Windows::ApplicationModel::Contacts::IContactLaunchActionVerbsStatics>
{
    HRESULT __stdcall get_Call(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Call());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Message(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Message());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Map(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Map());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Post(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Post());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VideoCall(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideoCall());
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
struct produce<D, Windows::ApplicationModel::Contacts::IContactList> : produce_base<D, Windows::ApplicationModel::Contacts::IContactList>
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

    HRESULT __stdcall get_SourceDisplayName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourceDisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsHidden(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsHidden());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsHidden(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsHidden(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OtherAppReadAccess(Windows::ApplicationModel::Contacts::ContactListOtherAppReadAccess * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OtherAppReadAccess());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OtherAppReadAccess(Windows::ApplicationModel::Contacts::ContactListOtherAppReadAccess value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OtherAppReadAccess(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OtherAppWriteAccess(Windows::ApplicationModel::Contacts::ContactListOtherAppWriteAccess * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OtherAppWriteAccess());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OtherAppWriteAccess(Windows::ApplicationModel::Contacts::ContactListOtherAppWriteAccess value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OtherAppWriteAccess(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ChangeTracker(impl::abi_arg_out<Windows::ApplicationModel::Contacts::IContactChangeTracker> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ChangeTracker());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SyncManager(impl::abi_arg_out<Windows::ApplicationModel::Contacts::IContactListSyncManager> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SyncManager());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportsServerSearch(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportsServerSearch());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UserDataAccountId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UserDataAccountId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ContactChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Contacts::ContactList, Windows::ApplicationModel::Contacts::ContactChangedEventArgs>> value, event_token * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().ContactChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Contacts::ContactList, Windows::ApplicationModel::Contacts::ContactChangedEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ContactChanged(event_token value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContactChanged(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SaveAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().SaveAsync());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().DeleteAsync());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetContactFromRemoteIdAsync(impl::abi_arg_in<hstring> remoteId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact>> contact) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *contact = detach_abi(this->shim().GetContactFromRemoteIdAsync(*reinterpret_cast<const hstring *>(&remoteId)));
            return S_OK;
        }
        catch (...)
        {
            *contact = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetMeContactAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact>> meContact) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *meContact = detach_abi(this->shim().GetMeContactAsync());
            return S_OK;
        }
        catch (...)
        {
            *meContact = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetContactReader(impl::abi_arg_out<Windows::ApplicationModel::Contacts::IContactReader> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetContactReader());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetContactReaderWithOptions(impl::abi_arg_in<Windows::ApplicationModel::Contacts::IContactQueryOptions> options, impl::abi_arg_out<Windows::ApplicationModel::Contacts::IContactReader> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetContactReader(*reinterpret_cast<const Windows::ApplicationModel::Contacts::ContactQueryOptions *>(&options)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SaveContactAsync(impl::abi_arg_in<Windows::ApplicationModel::Contacts::IContact> contact, impl::abi_arg_out<Windows::Foundation::IAsyncAction> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SaveContactAsync(*reinterpret_cast<const Windows::ApplicationModel::Contacts::Contact *>(&contact)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteContactAsync(impl::abi_arg_in<Windows::ApplicationModel::Contacts::IContact> contact, impl::abi_arg_out<Windows::Foundation::IAsyncAction> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeleteContactAsync(*reinterpret_cast<const Windows::ApplicationModel::Contacts::Contact *>(&contact)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetContactAsync(impl::abi_arg_in<hstring> contactId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact>> contacts) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *contacts = detach_abi(this->shim().GetContactAsync(*reinterpret_cast<const hstring *>(&contactId)));
            return S_OK;
        }
        catch (...)
        {
            *contacts = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Contacts::IContactList2> : produce_base<D, Windows::ApplicationModel::Contacts::IContactList2>
{
    HRESULT __stdcall abi_RegisterSyncManagerAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RegisterSyncManagerAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SupportsServerSearch(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SupportsServerSearch(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SyncConstraints(impl::abi_arg_out<Windows::ApplicationModel::Contacts::IContactListSyncConstraints> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SyncConstraints());
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
struct produce<D, Windows::ApplicationModel::Contacts::IContactListSyncConstraints> : produce_base<D, Windows::ApplicationModel::Contacts::IContactListSyncConstraints>
{
    HRESULT __stdcall get_CanSyncDescriptions(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanSyncDescriptions());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CanSyncDescriptions(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanSyncDescriptions(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxHomePhoneNumbers(impl::abi_arg_out<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxHomePhoneNumbers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxHomePhoneNumbers(impl::abi_arg_in<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxHomePhoneNumbers(*reinterpret_cast<const Windows::Foundation::IReference<int32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxMobilePhoneNumbers(impl::abi_arg_out<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxMobilePhoneNumbers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxMobilePhoneNumbers(impl::abi_arg_in<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxMobilePhoneNumbers(*reinterpret_cast<const Windows::Foundation::IReference<int32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxWorkPhoneNumbers(impl::abi_arg_out<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxWorkPhoneNumbers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxWorkPhoneNumbers(impl::abi_arg_in<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxWorkPhoneNumbers(*reinterpret_cast<const Windows::Foundation::IReference<int32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxOtherPhoneNumbers(impl::abi_arg_out<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxOtherPhoneNumbers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxOtherPhoneNumbers(impl::abi_arg_in<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxOtherPhoneNumbers(*reinterpret_cast<const Windows::Foundation::IReference<int32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxPagerPhoneNumbers(impl::abi_arg_out<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxPagerPhoneNumbers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxPagerPhoneNumbers(impl::abi_arg_in<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxPagerPhoneNumbers(*reinterpret_cast<const Windows::Foundation::IReference<int32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxBusinessFaxPhoneNumbers(impl::abi_arg_out<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxBusinessFaxPhoneNumbers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxBusinessFaxPhoneNumbers(impl::abi_arg_in<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxBusinessFaxPhoneNumbers(*reinterpret_cast<const Windows::Foundation::IReference<int32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxHomeFaxPhoneNumbers(impl::abi_arg_out<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxHomeFaxPhoneNumbers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxHomeFaxPhoneNumbers(impl::abi_arg_in<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxHomeFaxPhoneNumbers(*reinterpret_cast<const Windows::Foundation::IReference<int32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxCompanyPhoneNumbers(impl::abi_arg_out<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxCompanyPhoneNumbers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxCompanyPhoneNumbers(impl::abi_arg_in<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxCompanyPhoneNumbers(*reinterpret_cast<const Windows::Foundation::IReference<int32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxAssistantPhoneNumbers(impl::abi_arg_out<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxAssistantPhoneNumbers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxAssistantPhoneNumbers(impl::abi_arg_in<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxAssistantPhoneNumbers(*reinterpret_cast<const Windows::Foundation::IReference<int32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxRadioPhoneNumbers(impl::abi_arg_out<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxRadioPhoneNumbers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxRadioPhoneNumbers(impl::abi_arg_in<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxRadioPhoneNumbers(*reinterpret_cast<const Windows::Foundation::IReference<int32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxPersonalEmailAddresses(impl::abi_arg_out<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxPersonalEmailAddresses());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxPersonalEmailAddresses(impl::abi_arg_in<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxPersonalEmailAddresses(*reinterpret_cast<const Windows::Foundation::IReference<int32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxWorkEmailAddresses(impl::abi_arg_out<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxWorkEmailAddresses());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxWorkEmailAddresses(impl::abi_arg_in<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxWorkEmailAddresses(*reinterpret_cast<const Windows::Foundation::IReference<int32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxOtherEmailAddresses(impl::abi_arg_out<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxOtherEmailAddresses());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxOtherEmailAddresses(impl::abi_arg_in<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxOtherEmailAddresses(*reinterpret_cast<const Windows::Foundation::IReference<int32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxHomeAddresses(impl::abi_arg_out<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxHomeAddresses());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxHomeAddresses(impl::abi_arg_in<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxHomeAddresses(*reinterpret_cast<const Windows::Foundation::IReference<int32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxWorkAddresses(impl::abi_arg_out<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxWorkAddresses());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxWorkAddresses(impl::abi_arg_in<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxWorkAddresses(*reinterpret_cast<const Windows::Foundation::IReference<int32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxOtherAddresses(impl::abi_arg_out<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxOtherAddresses());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxOtherAddresses(impl::abi_arg_in<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxOtherAddresses(*reinterpret_cast<const Windows::Foundation::IReference<int32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxBirthdayDates(impl::abi_arg_out<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxBirthdayDates());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxBirthdayDates(impl::abi_arg_in<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxBirthdayDates(*reinterpret_cast<const Windows::Foundation::IReference<int32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxAnniversaryDates(impl::abi_arg_out<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxAnniversaryDates());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxAnniversaryDates(impl::abi_arg_in<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxAnniversaryDates(*reinterpret_cast<const Windows::Foundation::IReference<int32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxOtherDates(impl::abi_arg_out<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxOtherDates());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxOtherDates(impl::abi_arg_in<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxOtherDates(*reinterpret_cast<const Windows::Foundation::IReference<int32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxOtherRelationships(impl::abi_arg_out<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxOtherRelationships());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxOtherRelationships(impl::abi_arg_in<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxOtherRelationships(*reinterpret_cast<const Windows::Foundation::IReference<int32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxSpouseRelationships(impl::abi_arg_out<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxSpouseRelationships());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxSpouseRelationships(impl::abi_arg_in<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxSpouseRelationships(*reinterpret_cast<const Windows::Foundation::IReference<int32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxPartnerRelationships(impl::abi_arg_out<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxPartnerRelationships());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxPartnerRelationships(impl::abi_arg_in<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxPartnerRelationships(*reinterpret_cast<const Windows::Foundation::IReference<int32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxSiblingRelationships(impl::abi_arg_out<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxSiblingRelationships());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxSiblingRelationships(impl::abi_arg_in<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxSiblingRelationships(*reinterpret_cast<const Windows::Foundation::IReference<int32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxParentRelationships(impl::abi_arg_out<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxParentRelationships());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxParentRelationships(impl::abi_arg_in<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxParentRelationships(*reinterpret_cast<const Windows::Foundation::IReference<int32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxChildRelationships(impl::abi_arg_out<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxChildRelationships());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxChildRelationships(impl::abi_arg_in<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxChildRelationships(*reinterpret_cast<const Windows::Foundation::IReference<int32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxJobInfo(impl::abi_arg_out<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxJobInfo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxJobInfo(impl::abi_arg_in<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxJobInfo(*reinterpret_cast<const Windows::Foundation::IReference<int32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxWebsites(impl::abi_arg_out<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxWebsites());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxWebsites(impl::abi_arg_in<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxWebsites(*reinterpret_cast<const Windows::Foundation::IReference<int32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Contacts::IContactListSyncManager> : produce_base<D, Windows::ApplicationModel::Contacts::IContactListSyncManager>
{
    HRESULT __stdcall get_Status(Windows::ApplicationModel::Contacts::ContactListSyncStatus * value) noexcept override
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

    HRESULT __stdcall get_LastSuccessfulSyncTime(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LastSuccessfulSyncTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LastAttemptedSyncTime(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LastAttemptedSyncTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SyncAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().SyncAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_SyncStatusChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Contacts::ContactListSyncManager, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().SyncStatusChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Contacts::ContactListSyncManager, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SyncStatusChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SyncStatusChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Contacts::IContactListSyncManager2> : produce_base<D, Windows::ApplicationModel::Contacts::IContactListSyncManager2>
{
    HRESULT __stdcall put_Status(Windows::ApplicationModel::Contacts::ContactListSyncStatus value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Status(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LastSuccessfulSyncTime(impl::abi_arg_in<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LastSuccessfulSyncTime(*reinterpret_cast<const Windows::Foundation::DateTime *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LastAttemptedSyncTime(impl::abi_arg_in<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LastAttemptedSyncTime(*reinterpret_cast<const Windows::Foundation::DateTime *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Contacts::IContactLocationField> : produce_base<D, Windows::ApplicationModel::Contacts::IContactLocationField>
{
    HRESULT __stdcall get_UnstructuredAddress(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UnstructuredAddress());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Street(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Street());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_City(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().City());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
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
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Contacts::IContactLocationFieldFactory> : produce_base<D, Windows::ApplicationModel::Contacts::IContactLocationFieldFactory>
{
    HRESULT __stdcall abi_CreateLocation_Default(impl::abi_arg_in<hstring> unstructuredAddress, impl::abi_arg_out<Windows::ApplicationModel::Contacts::IContactLocationField> field) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *field = detach_abi(this->shim().CreateLocation(*reinterpret_cast<const hstring *>(&unstructuredAddress)));
            return S_OK;
        }
        catch (...)
        {
            *field = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateLocation_Category(impl::abi_arg_in<hstring> unstructuredAddress, Windows::ApplicationModel::Contacts::ContactFieldCategory category, impl::abi_arg_out<Windows::ApplicationModel::Contacts::IContactLocationField> field) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *field = detach_abi(this->shim().CreateLocation(*reinterpret_cast<const hstring *>(&unstructuredAddress), category));
            return S_OK;
        }
        catch (...)
        {
            *field = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateLocation_All(impl::abi_arg_in<hstring> unstructuredAddress, Windows::ApplicationModel::Contacts::ContactFieldCategory category, impl::abi_arg_in<hstring> street, impl::abi_arg_in<hstring> city, impl::abi_arg_in<hstring> region, impl::abi_arg_in<hstring> country, impl::abi_arg_in<hstring> postalCode, impl::abi_arg_out<Windows::ApplicationModel::Contacts::IContactLocationField> field) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *field = detach_abi(this->shim().CreateLocation(*reinterpret_cast<const hstring *>(&unstructuredAddress), category, *reinterpret_cast<const hstring *>(&street), *reinterpret_cast<const hstring *>(&city), *reinterpret_cast<const hstring *>(&region), *reinterpret_cast<const hstring *>(&country), *reinterpret_cast<const hstring *>(&postalCode)));
            return S_OK;
        }
        catch (...)
        {
            *field = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Contacts::IContactManagerForUser> : produce_base<D, Windows::ApplicationModel::Contacts::IContactManagerForUser>
{
    HRESULT __stdcall abi_ConvertContactToVCardAsync(impl::abi_arg_in<Windows::ApplicationModel::Contacts::IContact> contact, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::RandomAccessStreamReference>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ConvertContactToVCardAsync(*reinterpret_cast<const Windows::ApplicationModel::Contacts::Contact *>(&contact)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ConvertContactToVCardAsyncWithMaxBytes(impl::abi_arg_in<Windows::ApplicationModel::Contacts::IContact> contact, uint32_t maxBytes, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::RandomAccessStreamReference>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ConvertContactToVCardAsync(*reinterpret_cast<const Windows::ApplicationModel::Contacts::Contact *>(&contact), maxBytes));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ConvertVCardToContactAsync(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> vCard, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ConvertVCardToContactAsync(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&vCard)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestStoreAsync(Windows::ApplicationModel::Contacts::ContactStoreAccessType accessType, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactStore>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestStoreAsync(accessType));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestAnnotationStoreAsync(Windows::ApplicationModel::Contacts::ContactAnnotationStoreAccessType accessType, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactAnnotationStore>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestAnnotationStoreAsync(accessType));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SystemDisplayNameOrder(Windows::ApplicationModel::Contacts::ContactNameOrder * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SystemDisplayNameOrder());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SystemDisplayNameOrder(Windows::ApplicationModel::Contacts::ContactNameOrder value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SystemDisplayNameOrder(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SystemSortOrder(Windows::ApplicationModel::Contacts::ContactNameOrder * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SystemSortOrder());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SystemSortOrder(Windows::ApplicationModel::Contacts::ContactNameOrder value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SystemSortOrder(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

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
struct produce<D, Windows::ApplicationModel::Contacts::IContactManagerStatics> : produce_base<D, Windows::ApplicationModel::Contacts::IContactManagerStatics>
{
    HRESULT __stdcall abi_ShowContactCard(impl::abi_arg_in<Windows::ApplicationModel::Contacts::IContact> contact, impl::abi_arg_in<Windows::Foundation::Rect> selection) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowContactCard(*reinterpret_cast<const Windows::ApplicationModel::Contacts::Contact *>(&contact), *reinterpret_cast<const Windows::Foundation::Rect *>(&selection));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowContactCardWithPlacement(impl::abi_arg_in<Windows::ApplicationModel::Contacts::IContact> contact, impl::abi_arg_in<Windows::Foundation::Rect> selection, Windows::UI::Popups::Placement preferredPlacement) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowContactCard(*reinterpret_cast<const Windows::ApplicationModel::Contacts::Contact *>(&contact), *reinterpret_cast<const Windows::Foundation::Rect *>(&selection), preferredPlacement);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowDelayLoadedContactCard(impl::abi_arg_in<Windows::ApplicationModel::Contacts::IContact> contact, impl::abi_arg_in<Windows::Foundation::Rect> selection, Windows::UI::Popups::Placement preferredPlacement, impl::abi_arg_out<Windows::ApplicationModel::Contacts::IContactCardDelayedDataLoader> dataLoader) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *dataLoader = detach_abi(this->shim().ShowDelayLoadedContactCard(*reinterpret_cast<const Windows::ApplicationModel::Contacts::Contact *>(&contact), *reinterpret_cast<const Windows::Foundation::Rect *>(&selection), preferredPlacement));
            return S_OK;
        }
        catch (...)
        {
            *dataLoader = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Contacts::IContactManagerStatics2> : produce_base<D, Windows::ApplicationModel::Contacts::IContactManagerStatics2>
{
    HRESULT __stdcall abi_RequestStoreAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactStore>> store) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *store = detach_abi(this->shim().RequestStoreAsync());
            return S_OK;
        }
        catch (...)
        {
            *store = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Contacts::IContactManagerStatics3> : produce_base<D, Windows::ApplicationModel::Contacts::IContactManagerStatics3>
{
    HRESULT __stdcall abi_ConvertContactToVCardAsync(impl::abi_arg_in<Windows::ApplicationModel::Contacts::IContact> contact, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::RandomAccessStreamReference>> vCard) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *vCard = detach_abi(this->shim().ConvertContactToVCardAsync(*reinterpret_cast<const Windows::ApplicationModel::Contacts::Contact *>(&contact)));
            return S_OK;
        }
        catch (...)
        {
            *vCard = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ConvertContactToVCardAsyncWithMaxBytes(impl::abi_arg_in<Windows::ApplicationModel::Contacts::IContact> contact, uint32_t maxBytes, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::RandomAccessStreamReference>> vCard) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *vCard = detach_abi(this->shim().ConvertContactToVCardAsync(*reinterpret_cast<const Windows::ApplicationModel::Contacts::Contact *>(&contact), maxBytes));
            return S_OK;
        }
        catch (...)
        {
            *vCard = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ConvertVCardToContactAsync(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> vCard, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact>> contact) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *contact = detach_abi(this->shim().ConvertVCardToContactAsync(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&vCard)));
            return S_OK;
        }
        catch (...)
        {
            *contact = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestStoreAsyncWithAccessType(Windows::ApplicationModel::Contacts::ContactStoreAccessType accessType, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactStore>> store) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *store = detach_abi(this->shim().RequestStoreAsync(accessType));
            return S_OK;
        }
        catch (...)
        {
            *store = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestAnnotationStoreAsync(Windows::ApplicationModel::Contacts::ContactAnnotationStoreAccessType accessType, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactAnnotationStore>> store) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *store = detach_abi(this->shim().RequestAnnotationStoreAsync(accessType));
            return S_OK;
        }
        catch (...)
        {
            *store = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsShowContactCardSupported(bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsShowContactCardSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowContactCardWithOptions(impl::abi_arg_in<Windows::ApplicationModel::Contacts::IContact> contact, impl::abi_arg_in<Windows::Foundation::Rect> selection, Windows::UI::Popups::Placement preferredPlacement, impl::abi_arg_in<Windows::ApplicationModel::Contacts::IContactCardOptions> contactCardOptions) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowContactCard(*reinterpret_cast<const Windows::ApplicationModel::Contacts::Contact *>(&contact), *reinterpret_cast<const Windows::Foundation::Rect *>(&selection), preferredPlacement, *reinterpret_cast<const Windows::ApplicationModel::Contacts::ContactCardOptions *>(&contactCardOptions));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsShowDelayLoadedContactCardSupported(bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsShowDelayLoadedContactCardSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowDelayLoadedContactCardWithOptions(impl::abi_arg_in<Windows::ApplicationModel::Contacts::IContact> contact, impl::abi_arg_in<Windows::Foundation::Rect> selection, Windows::UI::Popups::Placement preferredPlacement, impl::abi_arg_in<Windows::ApplicationModel::Contacts::IContactCardOptions> contactCardOptions, impl::abi_arg_out<Windows::ApplicationModel::Contacts::IContactCardDelayedDataLoader> dataLoader) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *dataLoader = detach_abi(this->shim().ShowDelayLoadedContactCard(*reinterpret_cast<const Windows::ApplicationModel::Contacts::Contact *>(&contact), *reinterpret_cast<const Windows::Foundation::Rect *>(&selection), preferredPlacement, *reinterpret_cast<const Windows::ApplicationModel::Contacts::ContactCardOptions *>(&contactCardOptions)));
            return S_OK;
        }
        catch (...)
        {
            *dataLoader = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowFullContactCard(impl::abi_arg_in<Windows::ApplicationModel::Contacts::IContact> contact, impl::abi_arg_in<Windows::ApplicationModel::Contacts::IFullContactCardOptions> fullContactCardOptions) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowFullContactCard(*reinterpret_cast<const Windows::ApplicationModel::Contacts::Contact *>(&contact), *reinterpret_cast<const Windows::ApplicationModel::Contacts::FullContactCardOptions *>(&fullContactCardOptions));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SystemDisplayNameOrder(Windows::ApplicationModel::Contacts::ContactNameOrder * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SystemDisplayNameOrder());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SystemDisplayNameOrder(Windows::ApplicationModel::Contacts::ContactNameOrder value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SystemDisplayNameOrder(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SystemSortOrder(Windows::ApplicationModel::Contacts::ContactNameOrder * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SystemSortOrder());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SystemSortOrder(Windows::ApplicationModel::Contacts::ContactNameOrder value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SystemSortOrder(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Contacts::IContactManagerStatics4> : produce_base<D, Windows::ApplicationModel::Contacts::IContactManagerStatics4>
{
    HRESULT __stdcall abi_GetForUser(impl::abi_arg_in<Windows::System::IUser> user, impl::abi_arg_out<Windows::ApplicationModel::Contacts::IContactManagerForUser> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetForUser(*reinterpret_cast<const Windows::System::User *>(&user)));
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
struct produce<D, Windows::ApplicationModel::Contacts::IContactMatchReason> : produce_base<D, Windows::ApplicationModel::Contacts::IContactMatchReason>
{
    HRESULT __stdcall get_Field(Windows::ApplicationModel::Contacts::ContactMatchReasonKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Field());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Segments(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Data::Text::TextSegment>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Segments());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Text(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Text());
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
struct produce<D, Windows::ApplicationModel::Contacts::IContactName> : produce_base<D, Windows::ApplicationModel::Contacts::IContactName>
{
    HRESULT __stdcall get_FirstName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FirstName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FirstName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FirstName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LastName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LastName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LastName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LastName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MiddleName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MiddleName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MiddleName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MiddleName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
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

    HRESULT __stdcall put_YomiGivenName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().YomiGivenName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
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

    HRESULT __stdcall put_YomiFamilyName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().YomiFamilyName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HonorificNameSuffix(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HonorificNameSuffix());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_HonorificNameSuffix(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HonorificNameSuffix(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HonorificNamePrefix(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HonorificNamePrefix());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_HonorificNamePrefix(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HonorificNamePrefix(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall get_YomiDisplayName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().YomiDisplayName());
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
struct produce<D, Windows::ApplicationModel::Contacts::IContactPhone> : produce_base<D, Windows::ApplicationModel::Contacts::IContactPhone>
{
    HRESULT __stdcall get_Number(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Number());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Number(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Number(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Kind(Windows::ApplicationModel::Contacts::ContactPhoneKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Kind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Kind(Windows::ApplicationModel::Contacts::ContactPhoneKind value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Kind(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall put_Description(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Description(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Contacts::IContactPicker> : produce_base<D, Windows::ApplicationModel::Contacts::IContactPicker>
{
    HRESULT __stdcall get_CommitButtonText(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CommitButtonText());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CommitButtonText(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CommitButtonText(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SelectionMode(Windows::ApplicationModel::Contacts::ContactSelectionMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SelectionMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SelectionMode(Windows::ApplicationModel::Contacts::ContactSelectionMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SelectionMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall abi_PickSingleContactAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactInformation>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().PickSingleContactAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PickMultipleContactsAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactInformation>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().PickMultipleContactsAsync());
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
struct produce<D, Windows::ApplicationModel::Contacts::IContactPicker2> : produce_base<D, Windows::ApplicationModel::Contacts::IContactPicker2>
{
    HRESULT __stdcall get_DesiredFieldsWithContactFieldType(impl::abi_arg_out<Windows::Foundation::Collections::IVector<winrt::Windows::ApplicationModel::Contacts::ContactFieldType>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DesiredFieldsWithContactFieldType());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PickContactAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().PickContactAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PickContactsAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::Contact>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().PickContactsAsync());
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
struct produce<D, Windows::ApplicationModel::Contacts::IContactQueryOptions> : produce_base<D, Windows::ApplicationModel::Contacts::IContactQueryOptions>
{
    HRESULT __stdcall get_TextSearch(impl::abi_arg_out<Windows::ApplicationModel::Contacts::IContactQueryTextSearch> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TextSearch());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContactListIds(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContactListIds());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IncludeContactsFromHiddenLists(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IncludeContactsFromHiddenLists());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IncludeContactsFromHiddenLists(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IncludeContactsFromHiddenLists(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DesiredFields(Windows::ApplicationModel::Contacts::ContactQueryDesiredFields * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DesiredFields());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DesiredFields(Windows::ApplicationModel::Contacts::ContactQueryDesiredFields value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DesiredFields(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DesiredOperations(Windows::ApplicationModel::Contacts::ContactAnnotationOperations * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DesiredOperations());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DesiredOperations(Windows::ApplicationModel::Contacts::ContactAnnotationOperations value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DesiredOperations(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AnnotationListIds(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AnnotationListIds());
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
struct produce<D, Windows::ApplicationModel::Contacts::IContactQueryOptionsFactory> : produce_base<D, Windows::ApplicationModel::Contacts::IContactQueryOptionsFactory>
{
    HRESULT __stdcall abi_CreateWithText(impl::abi_arg_in<hstring> text, impl::abi_arg_out<Windows::ApplicationModel::Contacts::IContactQueryOptions> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateWithText(*reinterpret_cast<const hstring *>(&text)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithTextAndFields(impl::abi_arg_in<hstring> text, Windows::ApplicationModel::Contacts::ContactQuerySearchFields fields, impl::abi_arg_out<Windows::ApplicationModel::Contacts::IContactQueryOptions> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateWithTextAndFields(*reinterpret_cast<const hstring *>(&text), fields));
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
struct produce<D, Windows::ApplicationModel::Contacts::IContactQueryTextSearch> : produce_base<D, Windows::ApplicationModel::Contacts::IContactQueryTextSearch>
{
    HRESULT __stdcall get_Fields(Windows::ApplicationModel::Contacts::ContactQuerySearchFields * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Fields());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Fields(Windows::ApplicationModel::Contacts::ContactQuerySearchFields value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Fields(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Text(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Text());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Text(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Text(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SearchScope(Windows::ApplicationModel::Contacts::ContactQuerySearchScope * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SearchScope());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SearchScope(Windows::ApplicationModel::Contacts::ContactQuerySearchScope value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SearchScope(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Contacts::IContactReader> : produce_base<D, Windows::ApplicationModel::Contacts::IContactReader>
{
    HRESULT __stdcall abi_ReadBatchAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactBatch>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReadBatchAsync());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetMatchingPropertiesWithMatchReason(impl::abi_arg_in<Windows::ApplicationModel::Contacts::IContact> contact, impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactMatchReason>> ppRetVal) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *ppRetVal = detach_abi(this->shim().GetMatchingPropertiesWithMatchReason(*reinterpret_cast<const Windows::ApplicationModel::Contacts::Contact *>(&contact)));
            return S_OK;
        }
        catch (...)
        {
            *ppRetVal = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Contacts::IContactSignificantOther> : produce_base<D, Windows::ApplicationModel::Contacts::IContactSignificantOther>
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

    HRESULT __stdcall put_Description(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Description(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Contacts::IContactSignificantOther2> : produce_base<D, Windows::ApplicationModel::Contacts::IContactSignificantOther2>
{
    HRESULT __stdcall get_Relationship(Windows::ApplicationModel::Contacts::ContactRelationship * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Relationship());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Relationship(Windows::ApplicationModel::Contacts::ContactRelationship value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Relationship(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Contacts::IContactStore> : produce_base<D, Windows::ApplicationModel::Contacts::IContactStore>
{
    HRESULT __stdcall abi_FindContactsAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::Contact>>> contacts) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *contacts = detach_abi(this->shim().FindContactsAsync());
            return S_OK;
        }
        catch (...)
        {
            *contacts = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindContactsWithSearchTextAsync(impl::abi_arg_in<hstring> searchText, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::Contact>>> contacts) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *contacts = detach_abi(this->shim().FindContactsAsync(*reinterpret_cast<const hstring *>(&searchText)));
            return S_OK;
        }
        catch (...)
        {
            *contacts = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetContactAsync(impl::abi_arg_in<hstring> contactId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact>> contacts) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *contacts = detach_abi(this->shim().GetContactAsync(*reinterpret_cast<const hstring *>(&contactId)));
            return S_OK;
        }
        catch (...)
        {
            *contacts = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Contacts::IContactStore2> : produce_base<D, Windows::ApplicationModel::Contacts::IContactStore2>
{
    HRESULT __stdcall get_ChangeTracker(impl::abi_arg_out<Windows::ApplicationModel::Contacts::IContactChangeTracker> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ChangeTracker());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ContactChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Contacts::ContactStore, Windows::ApplicationModel::Contacts::ContactChangedEventArgs>> value, event_token * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().ContactChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Contacts::ContactStore, Windows::ApplicationModel::Contacts::ContactChangedEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ContactChanged(event_token value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContactChanged(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AggregateContactManager(impl::abi_arg_out<Windows::ApplicationModel::Contacts::IAggregateContactManager> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AggregateContactManager());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindContactListsAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactList>>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FindContactListsAsync());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetContactListAsync(impl::abi_arg_in<hstring> contactListId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactList>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetContactListAsync(*reinterpret_cast<const hstring *>(&contactListId)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateContactListAsync(impl::abi_arg_in<hstring> displayName, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactList>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateContactListAsync(*reinterpret_cast<const hstring *>(&displayName)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetMeContactAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact>> meContact) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *meContact = detach_abi(this->shim().GetMeContactAsync());
            return S_OK;
        }
        catch (...)
        {
            *meContact = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetContactReader(impl::abi_arg_out<Windows::ApplicationModel::Contacts::IContactReader> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetContactReader());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetContactReaderWithOptions(impl::abi_arg_in<Windows::ApplicationModel::Contacts::IContactQueryOptions> options, impl::abi_arg_out<Windows::ApplicationModel::Contacts::IContactReader> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetContactReader(*reinterpret_cast<const Windows::ApplicationModel::Contacts::ContactQueryOptions *>(&options)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateContactListInAccountAsync(impl::abi_arg_in<hstring> displayName, impl::abi_arg_in<hstring> userDataAccountId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactList>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateContactListAsync(*reinterpret_cast<const hstring *>(&displayName), *reinterpret_cast<const hstring *>(&userDataAccountId)));
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
struct produce<D, Windows::ApplicationModel::Contacts::IContactStoreNotificationTriggerDetails> : produce_base<D, Windows::ApplicationModel::Contacts::IContactStoreNotificationTriggerDetails>
{};

template <typename D>
struct produce<D, Windows::ApplicationModel::Contacts::IContactWebsite> : produce_base<D, Windows::ApplicationModel::Contacts::IContactWebsite>
{
    HRESULT __stdcall get_Uri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Uri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Uri(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Uri(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall put_Description(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Description(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Contacts::IContactWebsite2> : produce_base<D, Windows::ApplicationModel::Contacts::IContactWebsite2>
{
    HRESULT __stdcall get_RawValue(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RawValue());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RawValue(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RawValue(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Contacts::IFullContactCardOptions> : produce_base<D, Windows::ApplicationModel::Contacts::IFullContactCardOptions>
{
    HRESULT __stdcall get_DesiredRemainingView(Windows::UI::ViewManagement::ViewSizePreference * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DesiredRemainingView());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DesiredRemainingView(Windows::UI::ViewManagement::ViewSizePreference value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DesiredRemainingView(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Contacts::IKnownContactFieldStatics> : produce_base<D, Windows::ApplicationModel::Contacts::IKnownContactFieldStatics>
{
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

    HRESULT __stdcall get_PhoneNumber(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PhoneNumber());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Location(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Location());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InstantMessage(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InstantMessage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ConvertNameToType(impl::abi_arg_in<hstring> name, Windows::ApplicationModel::Contacts::ContactFieldType * type) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *type = detach_abi(this->shim().ConvertNameToType(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ConvertTypeToName(Windows::ApplicationModel::Contacts::ContactFieldType type, impl::abi_arg_out<hstring> name) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *name = detach_abi(this->shim().ConvertTypeToName(type));
            return S_OK;
        }
        catch (...)
        {
            *name = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::ApplicationModel::Contacts {

template <typename D> Windows::ApplicationModel::Contacts::ContactCardHeaderKind impl_IContactCardOptions<D>::HeaderKind() const
{
    Windows::ApplicationModel::Contacts::ContactCardHeaderKind value {};
    check_hresult(WINRT_SHIM(IContactCardOptions)->get_HeaderKind(&value));
    return value;
}

template <typename D> void impl_IContactCardOptions<D>::HeaderKind(Windows::ApplicationModel::Contacts::ContactCardHeaderKind value) const
{
    check_hresult(WINRT_SHIM(IContactCardOptions)->put_HeaderKind(value));
}

template <typename D> Windows::ApplicationModel::Contacts::ContactCardTabKind impl_IContactCardOptions<D>::InitialTabKind() const
{
    Windows::ApplicationModel::Contacts::ContactCardTabKind value {};
    check_hresult(WINRT_SHIM(IContactCardOptions)->get_InitialTabKind(&value));
    return value;
}

template <typename D> void impl_IContactCardOptions<D>::InitialTabKind(Windows::ApplicationModel::Contacts::ContactCardTabKind value) const
{
    check_hresult(WINRT_SHIM(IContactCardOptions)->put_InitialTabKind(value));
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IContactCardOptions2<D>::ServerSearchContactListIds() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IContactCardOptions2)->get_ServerSearchContactListIds(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::ViewManagement::ViewSizePreference impl_IFullContactCardOptions<D>::DesiredRemainingView() const
{
    Windows::UI::ViewManagement::ViewSizePreference value {};
    check_hresult(WINRT_SHIM(IFullContactCardOptions)->get_DesiredRemainingView(&value));
    return value;
}

template <typename D> void impl_IFullContactCardOptions<D>::DesiredRemainingView(Windows::UI::ViewManagement::ViewSizePreference value) const
{
    check_hresult(WINRT_SHIM(IFullContactCardOptions)->put_DesiredRemainingView(value));
}

template <typename D> void impl_IContactManagerStatics<D>::ShowContactCard(const Windows::ApplicationModel::Contacts::Contact & contact, const Windows::Foundation::Rect & selection) const
{
    check_hresult(WINRT_SHIM(IContactManagerStatics)->abi_ShowContactCard(get_abi(contact), get_abi(selection)));
}

template <typename D> void impl_IContactManagerStatics<D>::ShowContactCard(const Windows::ApplicationModel::Contacts::Contact & contact, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement) const
{
    check_hresult(WINRT_SHIM(IContactManagerStatics)->abi_ShowContactCardWithPlacement(get_abi(contact), get_abi(selection), preferredPlacement));
}

template <typename D> Windows::ApplicationModel::Contacts::ContactCardDelayedDataLoader impl_IContactManagerStatics<D>::ShowDelayLoadedContactCard(const Windows::ApplicationModel::Contacts::Contact & contact, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement) const
{
    Windows::ApplicationModel::Contacts::ContactCardDelayedDataLoader dataLoader { nullptr };
    check_hresult(WINRT_SHIM(IContactManagerStatics)->abi_ShowDelayLoadedContactCard(get_abi(contact), get_abi(selection), preferredPlacement, put_abi(dataLoader)));
    return dataLoader;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactStore> impl_IContactManagerStatics2<D>::RequestStoreAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactStore> store;
    check_hresult(WINRT_SHIM(IContactManagerStatics2)->abi_RequestStoreAsync(put_abi(store)));
    return store;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::RandomAccessStreamReference> impl_IContactManagerStatics3<D>::ConvertContactToVCardAsync(const Windows::ApplicationModel::Contacts::Contact & contact) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::RandomAccessStreamReference> vCard;
    check_hresult(WINRT_SHIM(IContactManagerStatics3)->abi_ConvertContactToVCardAsync(get_abi(contact), put_abi(vCard)));
    return vCard;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::RandomAccessStreamReference> impl_IContactManagerStatics3<D>::ConvertContactToVCardAsync(const Windows::ApplicationModel::Contacts::Contact & contact, uint32_t maxBytes) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::RandomAccessStreamReference> vCard;
    check_hresult(WINRT_SHIM(IContactManagerStatics3)->abi_ConvertContactToVCardAsyncWithMaxBytes(get_abi(contact), maxBytes, put_abi(vCard)));
    return vCard;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact> impl_IContactManagerStatics3<D>::ConvertVCardToContactAsync(const Windows::Storage::Streams::IRandomAccessStreamReference & vCard) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact> contact;
    check_hresult(WINRT_SHIM(IContactManagerStatics3)->abi_ConvertVCardToContactAsync(get_abi(vCard), put_abi(contact)));
    return contact;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactStore> impl_IContactManagerStatics3<D>::RequestStoreAsync(Windows::ApplicationModel::Contacts::ContactStoreAccessType accessType) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactStore> store;
    check_hresult(WINRT_SHIM(IContactManagerStatics3)->abi_RequestStoreAsyncWithAccessType(accessType, put_abi(store)));
    return store;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactAnnotationStore> impl_IContactManagerStatics3<D>::RequestAnnotationStoreAsync(Windows::ApplicationModel::Contacts::ContactAnnotationStoreAccessType accessType) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactAnnotationStore> store;
    check_hresult(WINRT_SHIM(IContactManagerStatics3)->abi_RequestAnnotationStoreAsync(accessType, put_abi(store)));
    return store;
}

template <typename D> bool impl_IContactManagerStatics3<D>::IsShowContactCardSupported() const
{
    bool result {};
    check_hresult(WINRT_SHIM(IContactManagerStatics3)->abi_IsShowContactCardSupported(&result));
    return result;
}

template <typename D> void impl_IContactManagerStatics3<D>::ShowContactCard(const Windows::ApplicationModel::Contacts::Contact & contact, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement, const Windows::ApplicationModel::Contacts::ContactCardOptions & contactCardOptions) const
{
    check_hresult(WINRT_SHIM(IContactManagerStatics3)->abi_ShowContactCardWithOptions(get_abi(contact), get_abi(selection), preferredPlacement, get_abi(contactCardOptions)));
}

template <typename D> bool impl_IContactManagerStatics3<D>::IsShowDelayLoadedContactCardSupported() const
{
    bool result {};
    check_hresult(WINRT_SHIM(IContactManagerStatics3)->abi_IsShowDelayLoadedContactCardSupported(&result));
    return result;
}

template <typename D> Windows::ApplicationModel::Contacts::ContactCardDelayedDataLoader impl_IContactManagerStatics3<D>::ShowDelayLoadedContactCard(const Windows::ApplicationModel::Contacts::Contact & contact, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement, const Windows::ApplicationModel::Contacts::ContactCardOptions & contactCardOptions) const
{
    Windows::ApplicationModel::Contacts::ContactCardDelayedDataLoader dataLoader { nullptr };
    check_hresult(WINRT_SHIM(IContactManagerStatics3)->abi_ShowDelayLoadedContactCardWithOptions(get_abi(contact), get_abi(selection), preferredPlacement, get_abi(contactCardOptions), put_abi(dataLoader)));
    return dataLoader;
}

template <typename D> void impl_IContactManagerStatics3<D>::ShowFullContactCard(const Windows::ApplicationModel::Contacts::Contact & contact, const Windows::ApplicationModel::Contacts::FullContactCardOptions & fullContactCardOptions) const
{
    check_hresult(WINRT_SHIM(IContactManagerStatics3)->abi_ShowFullContactCard(get_abi(contact), get_abi(fullContactCardOptions)));
}

template <typename D> Windows::ApplicationModel::Contacts::ContactNameOrder impl_IContactManagerStatics3<D>::SystemDisplayNameOrder() const
{
    Windows::ApplicationModel::Contacts::ContactNameOrder value {};
    check_hresult(WINRT_SHIM(IContactManagerStatics3)->get_SystemDisplayNameOrder(&value));
    return value;
}

template <typename D> void impl_IContactManagerStatics3<D>::SystemDisplayNameOrder(Windows::ApplicationModel::Contacts::ContactNameOrder value) const
{
    check_hresult(WINRT_SHIM(IContactManagerStatics3)->put_SystemDisplayNameOrder(value));
}

template <typename D> Windows::ApplicationModel::Contacts::ContactNameOrder impl_IContactManagerStatics3<D>::SystemSortOrder() const
{
    Windows::ApplicationModel::Contacts::ContactNameOrder value {};
    check_hresult(WINRT_SHIM(IContactManagerStatics3)->get_SystemSortOrder(&value));
    return value;
}

template <typename D> void impl_IContactManagerStatics3<D>::SystemSortOrder(Windows::ApplicationModel::Contacts::ContactNameOrder value) const
{
    check_hresult(WINRT_SHIM(IContactManagerStatics3)->put_SystemSortOrder(value));
}

template <typename D> Windows::ApplicationModel::Contacts::ContactManagerForUser impl_IContactManagerStatics4<D>::GetForUser(const Windows::System::User & user) const
{
    Windows::ApplicationModel::Contacts::ContactManagerForUser result { nullptr };
    check_hresult(WINRT_SHIM(IContactManagerStatics4)->abi_GetForUser(get_abi(user), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::RandomAccessStreamReference> impl_IContactManagerForUser<D>::ConvertContactToVCardAsync(const Windows::ApplicationModel::Contacts::Contact & contact) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::RandomAccessStreamReference> result;
    check_hresult(WINRT_SHIM(IContactManagerForUser)->abi_ConvertContactToVCardAsync(get_abi(contact), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::RandomAccessStreamReference> impl_IContactManagerForUser<D>::ConvertContactToVCardAsync(const Windows::ApplicationModel::Contacts::Contact & contact, uint32_t maxBytes) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::RandomAccessStreamReference> result;
    check_hresult(WINRT_SHIM(IContactManagerForUser)->abi_ConvertContactToVCardAsyncWithMaxBytes(get_abi(contact), maxBytes, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact> impl_IContactManagerForUser<D>::ConvertVCardToContactAsync(const Windows::Storage::Streams::IRandomAccessStreamReference & vCard) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact> result;
    check_hresult(WINRT_SHIM(IContactManagerForUser)->abi_ConvertVCardToContactAsync(get_abi(vCard), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactStore> impl_IContactManagerForUser<D>::RequestStoreAsync(Windows::ApplicationModel::Contacts::ContactStoreAccessType accessType) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactStore> result;
    check_hresult(WINRT_SHIM(IContactManagerForUser)->abi_RequestStoreAsync(accessType, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactAnnotationStore> impl_IContactManagerForUser<D>::RequestAnnotationStoreAsync(Windows::ApplicationModel::Contacts::ContactAnnotationStoreAccessType accessType) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactAnnotationStore> result;
    check_hresult(WINRT_SHIM(IContactManagerForUser)->abi_RequestAnnotationStoreAsync(accessType, put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Contacts::ContactNameOrder impl_IContactManagerForUser<D>::SystemDisplayNameOrder() const
{
    Windows::ApplicationModel::Contacts::ContactNameOrder value {};
    check_hresult(WINRT_SHIM(IContactManagerForUser)->get_SystemDisplayNameOrder(&value));
    return value;
}

template <typename D> void impl_IContactManagerForUser<D>::SystemDisplayNameOrder(Windows::ApplicationModel::Contacts::ContactNameOrder value) const
{
    check_hresult(WINRT_SHIM(IContactManagerForUser)->put_SystemDisplayNameOrder(value));
}

template <typename D> Windows::ApplicationModel::Contacts::ContactNameOrder impl_IContactManagerForUser<D>::SystemSortOrder() const
{
    Windows::ApplicationModel::Contacts::ContactNameOrder value {};
    check_hresult(WINRT_SHIM(IContactManagerForUser)->get_SystemSortOrder(&value));
    return value;
}

template <typename D> void impl_IContactManagerForUser<D>::SystemSortOrder(Windows::ApplicationModel::Contacts::ContactNameOrder value) const
{
    check_hresult(WINRT_SHIM(IContactManagerForUser)->put_SystemSortOrder(value));
}

template <typename D> Windows::System::User impl_IContactManagerForUser<D>::User() const
{
    Windows::System::User value { nullptr };
    check_hresult(WINRT_SHIM(IContactManagerForUser)->get_User(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::Contact>> impl_IAggregateContactManager<D>::FindRawContactsAsync(const Windows::ApplicationModel::Contacts::Contact & contact) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::Contact>> value;
    check_hresult(WINRT_SHIM(IAggregateContactManager)->abi_FindRawContactsAsync(get_abi(contact), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact> impl_IAggregateContactManager<D>::TryLinkContactsAsync(const Windows::ApplicationModel::Contacts::Contact & primaryContact, const Windows::ApplicationModel::Contacts::Contact & secondaryContact) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact> contact;
    check_hresult(WINRT_SHIM(IAggregateContactManager)->abi_TryLinkContactsAsync(get_abi(primaryContact), get_abi(secondaryContact), put_abi(contact)));
    return contact;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IAggregateContactManager<D>::UnlinkRawContactAsync(const Windows::ApplicationModel::Contacts::Contact & contact) const
{
    Windows::Foundation::IAsyncAction value;
    check_hresult(WINRT_SHIM(IAggregateContactManager)->abi_UnlinkRawContactAsync(get_abi(contact), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IAggregateContactManager<D>::TrySetPreferredSourceForPictureAsync(const Windows::ApplicationModel::Contacts::Contact & aggregateContact, const Windows::ApplicationModel::Contacts::Contact & rawContact) const
{
    Windows::Foundation::IAsyncOperation<bool> value;
    check_hresult(WINRT_SHIM(IAggregateContactManager)->abi_TrySetPreferredSourceForPictureAsync(get_abi(aggregateContact), get_abi(rawContact), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IAggregateContactManager2<D>::SetRemoteIdentificationInformationAsync(hstring_view contactListId, hstring_view remoteSourceId, hstring_view accountId) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IAggregateContactManager2)->abi_SetRemoteIdentificationInformationAsync(get_abi(contactListId), get_abi(remoteSourceId), get_abi(accountId), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<hstring>> impl_IContactAnnotationStore<D>::FindContactIdsByEmailAsync(hstring_view emailAddress) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<hstring>> contactIds;
    check_hresult(WINRT_SHIM(IContactAnnotationStore)->abi_FindContactIdsByEmailAsync(get_abi(emailAddress), put_abi(contactIds)));
    return contactIds;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<hstring>> impl_IContactAnnotationStore<D>::FindContactIdsByPhoneNumberAsync(hstring_view phoneNumber) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<hstring>> contactIds;
    check_hresult(WINRT_SHIM(IContactAnnotationStore)->abi_FindContactIdsByPhoneNumberAsync(get_abi(phoneNumber), put_abi(contactIds)));
    return contactIds;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactAnnotation>> impl_IContactAnnotationStore<D>::FindAnnotationsForContactAsync(const Windows::ApplicationModel::Contacts::Contact & contact) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactAnnotation>> annotations;
    check_hresult(WINRT_SHIM(IContactAnnotationStore)->abi_FindAnnotationsForContactAsync(get_abi(contact), put_abi(annotations)));
    return annotations;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IContactAnnotationStore<D>::DisableAnnotationAsync(const Windows::ApplicationModel::Contacts::ContactAnnotation & annotation) const
{
    Windows::Foundation::IAsyncAction value;
    check_hresult(WINRT_SHIM(IContactAnnotationStore)->abi_DisableAnnotationAsync(get_abi(annotation), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactAnnotationList> impl_IContactAnnotationStore<D>::CreateAnnotationListAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactAnnotationList> value;
    check_hresult(WINRT_SHIM(IContactAnnotationStore)->abi_CreateAnnotationListAsync(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactAnnotationList> impl_IContactAnnotationStore<D>::CreateAnnotationListAsync(hstring_view userDataAccountId) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactAnnotationList> value;
    check_hresult(WINRT_SHIM(IContactAnnotationStore)->abi_CreateAnnotationListInAccountAsync(get_abi(userDataAccountId), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactAnnotationList> impl_IContactAnnotationStore<D>::GetAnnotationListAsync(hstring_view annotationListId) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactAnnotationList> value;
    check_hresult(WINRT_SHIM(IContactAnnotationStore)->abi_GetAnnotationListAsync(get_abi(annotationListId), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactAnnotationList>> impl_IContactAnnotationStore<D>::FindAnnotationListsAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactAnnotationList>> lists;
    check_hresult(WINRT_SHIM(IContactAnnotationStore)->abi_FindAnnotationListsAsync(put_abi(lists)));
    return lists;
}

template <typename D> hstring impl_IContactAnnotationList<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactAnnotationList)->get_Id(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContactAnnotationList<D>::ProviderPackageFamilyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactAnnotationList)->get_ProviderPackageFamilyName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContactAnnotationList<D>::UserDataAccountId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactAnnotationList)->get_UserDataAccountId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IContactAnnotationList<D>::DeleteAsync() const
{
    Windows::Foundation::IAsyncAction value;
    check_hresult(WINRT_SHIM(IContactAnnotationList)->abi_DeleteAsync(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IContactAnnotationList<D>::TrySaveAnnotationAsync(const Windows::ApplicationModel::Contacts::ContactAnnotation & annotation) const
{
    Windows::Foundation::IAsyncOperation<bool> ppResult;
    check_hresult(WINRT_SHIM(IContactAnnotationList)->abi_TrySaveAnnotationAsync(get_abi(annotation), put_abi(ppResult)));
    return ppResult;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactAnnotation> impl_IContactAnnotationList<D>::GetAnnotationAsync(hstring_view annotationId) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactAnnotation> annotation;
    check_hresult(WINRT_SHIM(IContactAnnotationList)->abi_GetAnnotationAsync(get_abi(annotationId), put_abi(annotation)));
    return annotation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactAnnotation>> impl_IContactAnnotationList<D>::FindAnnotationsByRemoteIdAsync(hstring_view remoteId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactAnnotation>> annotations;
    check_hresult(WINRT_SHIM(IContactAnnotationList)->abi_FindAnnotationsByRemoteIdAsync(get_abi(remoteId), put_abi(annotations)));
    return annotations;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactAnnotation>> impl_IContactAnnotationList<D>::FindAnnotationsAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactAnnotation>> annotations;
    check_hresult(WINRT_SHIM(IContactAnnotationList)->abi_FindAnnotationsAsync(put_abi(annotations)));
    return annotations;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IContactAnnotationList<D>::DeleteAnnotationAsync(const Windows::ApplicationModel::Contacts::ContactAnnotation & annotation) const
{
    Windows::Foundation::IAsyncAction value;
    check_hresult(WINRT_SHIM(IContactAnnotationList)->abi_DeleteAnnotationAsync(get_abi(annotation), put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContactAnnotation<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactAnnotation)->get_Id(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContactAnnotation<D>::AnnotationListId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactAnnotation)->get_AnnotationListId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContactAnnotation<D>::ContactId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactAnnotation)->get_ContactId(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactAnnotation<D>::ContactId(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactAnnotation)->put_ContactId(get_abi(value)));
}

template <typename D> hstring impl_IContactAnnotation<D>::RemoteId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactAnnotation)->get_RemoteId(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactAnnotation<D>::RemoteId(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactAnnotation)->put_RemoteId(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Contacts::ContactAnnotationOperations impl_IContactAnnotation<D>::SupportedOperations() const
{
    Windows::ApplicationModel::Contacts::ContactAnnotationOperations value {};
    check_hresult(WINRT_SHIM(IContactAnnotation)->get_SupportedOperations(&value));
    return value;
}

template <typename D> void impl_IContactAnnotation<D>::SupportedOperations(Windows::ApplicationModel::Contacts::ContactAnnotationOperations value) const
{
    check_hresult(WINRT_SHIM(IContactAnnotation)->put_SupportedOperations(value));
}

template <typename D> bool impl_IContactAnnotation<D>::IsDisabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IContactAnnotation)->get_IsDisabled(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::ValueSet impl_IContactAnnotation<D>::ProviderProperties() const
{
    Windows::Foundation::Collections::ValueSet value { nullptr };
    check_hresult(WINRT_SHIM(IContactAnnotation)->get_ProviderProperties(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::Contact>> impl_IContactStore<D>::FindContactsAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::Contact>> contacts;
    check_hresult(WINRT_SHIM(IContactStore)->abi_FindContactsAsync(put_abi(contacts)));
    return contacts;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::Contact>> impl_IContactStore<D>::FindContactsAsync(hstring_view searchText) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::Contact>> contacts;
    check_hresult(WINRT_SHIM(IContactStore)->abi_FindContactsWithSearchTextAsync(get_abi(searchText), put_abi(contacts)));
    return contacts;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact> impl_IContactStore<D>::GetContactAsync(hstring_view contactId) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact> contacts;
    check_hresult(WINRT_SHIM(IContactStore)->abi_GetContactAsync(get_abi(contactId), put_abi(contacts)));
    return contacts;
}

template <typename D> Windows::ApplicationModel::Contacts::ContactChangeTracker impl_IContactStore2<D>::ChangeTracker() const
{
    Windows::ApplicationModel::Contacts::ContactChangeTracker value { nullptr };
    check_hresult(WINRT_SHIM(IContactStore2)->get_ChangeTracker(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IContactStore2<D>::ContactChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Contacts::ContactStore, Windows::ApplicationModel::Contacts::ContactChangedEventArgs> & value) const
{
    event_token returnValue {};
    check_hresult(WINRT_SHIM(IContactStore2)->add_ContactChanged(get_abi(value), &returnValue));
    return returnValue;
}

template <typename D> event_revoker<IContactStore2> impl_IContactStore2<D>::ContactChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Contacts::ContactStore, Windows::ApplicationModel::Contacts::ContactChangedEventArgs> & value) const
{
    return impl::make_event_revoker<D, IContactStore2>(this, &ABI::Windows::ApplicationModel::Contacts::IContactStore2::remove_ContactChanged, ContactChanged(value));
}

template <typename D> void impl_IContactStore2<D>::ContactChanged(event_token value) const
{
    check_hresult(WINRT_SHIM(IContactStore2)->remove_ContactChanged(value));
}

template <typename D> Windows::ApplicationModel::Contacts::AggregateContactManager impl_IContactStore2<D>::AggregateContactManager() const
{
    Windows::ApplicationModel::Contacts::AggregateContactManager value { nullptr };
    check_hresult(WINRT_SHIM(IContactStore2)->get_AggregateContactManager(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactList>> impl_IContactStore2<D>::FindContactListsAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactList>> value;
    check_hresult(WINRT_SHIM(IContactStore2)->abi_FindContactListsAsync(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactList> impl_IContactStore2<D>::GetContactListAsync(hstring_view contactListId) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactList> value;
    check_hresult(WINRT_SHIM(IContactStore2)->abi_GetContactListAsync(get_abi(contactListId), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactList> impl_IContactStore2<D>::CreateContactListAsync(hstring_view displayName) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactList> value;
    check_hresult(WINRT_SHIM(IContactStore2)->abi_CreateContactListAsync(get_abi(displayName), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact> impl_IContactStore2<D>::GetMeContactAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact> meContact;
    check_hresult(WINRT_SHIM(IContactStore2)->abi_GetMeContactAsync(put_abi(meContact)));
    return meContact;
}

template <typename D> Windows::ApplicationModel::Contacts::ContactReader impl_IContactStore2<D>::GetContactReader() const
{
    Windows::ApplicationModel::Contacts::ContactReader value { nullptr };
    check_hresult(WINRT_SHIM(IContactStore2)->abi_GetContactReader(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Contacts::ContactReader impl_IContactStore2<D>::GetContactReader(const Windows::ApplicationModel::Contacts::ContactQueryOptions & options) const
{
    Windows::ApplicationModel::Contacts::ContactReader value { nullptr };
    check_hresult(WINRT_SHIM(IContactStore2)->abi_GetContactReaderWithOptions(get_abi(options), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactList> impl_IContactStore2<D>::CreateContactListAsync(hstring_view displayName, hstring_view userDataAccountId) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactList> value;
    check_hresult(WINRT_SHIM(IContactStore2)->abi_CreateContactListInAccountAsync(get_abi(displayName), get_abi(userDataAccountId), put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContactList<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactList)->get_Id(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContactList<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactList)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactList<D>::DisplayName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactList)->put_DisplayName(get_abi(value)));
}

template <typename D> hstring impl_IContactList<D>::SourceDisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactList)->get_SourceDisplayName(put_abi(value)));
    return value;
}

template <typename D> bool impl_IContactList<D>::IsHidden() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IContactList)->get_IsHidden(&value));
    return value;
}

template <typename D> void impl_IContactList<D>::IsHidden(bool value) const
{
    check_hresult(WINRT_SHIM(IContactList)->put_IsHidden(value));
}

template <typename D> Windows::ApplicationModel::Contacts::ContactListOtherAppReadAccess impl_IContactList<D>::OtherAppReadAccess() const
{
    Windows::ApplicationModel::Contacts::ContactListOtherAppReadAccess value {};
    check_hresult(WINRT_SHIM(IContactList)->get_OtherAppReadAccess(&value));
    return value;
}

template <typename D> void impl_IContactList<D>::OtherAppReadAccess(Windows::ApplicationModel::Contacts::ContactListOtherAppReadAccess value) const
{
    check_hresult(WINRT_SHIM(IContactList)->put_OtherAppReadAccess(value));
}

template <typename D> Windows::ApplicationModel::Contacts::ContactListOtherAppWriteAccess impl_IContactList<D>::OtherAppWriteAccess() const
{
    Windows::ApplicationModel::Contacts::ContactListOtherAppWriteAccess value {};
    check_hresult(WINRT_SHIM(IContactList)->get_OtherAppWriteAccess(&value));
    return value;
}

template <typename D> void impl_IContactList<D>::OtherAppWriteAccess(Windows::ApplicationModel::Contacts::ContactListOtherAppWriteAccess value) const
{
    check_hresult(WINRT_SHIM(IContactList)->put_OtherAppWriteAccess(value));
}

template <typename D> Windows::ApplicationModel::Contacts::ContactChangeTracker impl_IContactList<D>::ChangeTracker() const
{
    Windows::ApplicationModel::Contacts::ContactChangeTracker value { nullptr };
    check_hresult(WINRT_SHIM(IContactList)->get_ChangeTracker(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Contacts::ContactListSyncManager impl_IContactList<D>::SyncManager() const
{
    Windows::ApplicationModel::Contacts::ContactListSyncManager value { nullptr };
    check_hresult(WINRT_SHIM(IContactList)->get_SyncManager(put_abi(value)));
    return value;
}

template <typename D> bool impl_IContactList<D>::SupportsServerSearch() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IContactList)->get_SupportsServerSearch(&value));
    return value;
}

template <typename D> hstring impl_IContactList<D>::UserDataAccountId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactList)->get_UserDataAccountId(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IContactList<D>::ContactChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Contacts::ContactList, Windows::ApplicationModel::Contacts::ContactChangedEventArgs> & value) const
{
    event_token returnValue {};
    check_hresult(WINRT_SHIM(IContactList)->add_ContactChanged(get_abi(value), &returnValue));
    return returnValue;
}

template <typename D> event_revoker<IContactList> impl_IContactList<D>::ContactChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Contacts::ContactList, Windows::ApplicationModel::Contacts::ContactChangedEventArgs> & value) const
{
    return impl::make_event_revoker<D, IContactList>(this, &ABI::Windows::ApplicationModel::Contacts::IContactList::remove_ContactChanged, ContactChanged(value));
}

template <typename D> void impl_IContactList<D>::ContactChanged(event_token value) const
{
    check_hresult(WINRT_SHIM(IContactList)->remove_ContactChanged(value));
}

template <typename D> Windows::Foundation::IAsyncAction impl_IContactList<D>::SaveAsync() const
{
    Windows::Foundation::IAsyncAction returnValue;
    check_hresult(WINRT_SHIM(IContactList)->abi_SaveAsync(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IContactList<D>::DeleteAsync() const
{
    Windows::Foundation::IAsyncAction returnValue;
    check_hresult(WINRT_SHIM(IContactList)->abi_DeleteAsync(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact> impl_IContactList<D>::GetContactFromRemoteIdAsync(hstring_view remoteId) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact> contact;
    check_hresult(WINRT_SHIM(IContactList)->abi_GetContactFromRemoteIdAsync(get_abi(remoteId), put_abi(contact)));
    return contact;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact> impl_IContactList<D>::GetMeContactAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact> meContact;
    check_hresult(WINRT_SHIM(IContactList)->abi_GetMeContactAsync(put_abi(meContact)));
    return meContact;
}

template <typename D> Windows::ApplicationModel::Contacts::ContactReader impl_IContactList<D>::GetContactReader() const
{
    Windows::ApplicationModel::Contacts::ContactReader value { nullptr };
    check_hresult(WINRT_SHIM(IContactList)->abi_GetContactReader(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Contacts::ContactReader impl_IContactList<D>::GetContactReader(const Windows::ApplicationModel::Contacts::ContactQueryOptions & options) const
{
    Windows::ApplicationModel::Contacts::ContactReader value { nullptr };
    check_hresult(WINRT_SHIM(IContactList)->abi_GetContactReaderWithOptions(get_abi(options), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IContactList<D>::SaveContactAsync(const Windows::ApplicationModel::Contacts::Contact & contact) const
{
    Windows::Foundation::IAsyncAction value;
    check_hresult(WINRT_SHIM(IContactList)->abi_SaveContactAsync(get_abi(contact), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IContactList<D>::DeleteContactAsync(const Windows::ApplicationModel::Contacts::Contact & contact) const
{
    Windows::Foundation::IAsyncAction value;
    check_hresult(WINRT_SHIM(IContactList)->abi_DeleteContactAsync(get_abi(contact), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact> impl_IContactList<D>::GetContactAsync(hstring_view contactId) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact> contacts;
    check_hresult(WINRT_SHIM(IContactList)->abi_GetContactAsync(get_abi(contactId), put_abi(contacts)));
    return contacts;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IContactList2<D>::RegisterSyncManagerAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IContactList2)->abi_RegisterSyncManagerAsync(put_abi(result)));
    return result;
}

template <typename D> void impl_IContactList2<D>::SupportsServerSearch(bool value) const
{
    check_hresult(WINRT_SHIM(IContactList2)->put_SupportsServerSearch(value));
}

template <typename D> Windows::ApplicationModel::Contacts::ContactListSyncConstraints impl_IContactList2<D>::SyncConstraints() const
{
    Windows::ApplicationModel::Contacts::ContactListSyncConstraints value { nullptr };
    check_hresult(WINRT_SHIM(IContactList2)->get_SyncConstraints(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Contacts::ContactListSyncStatus impl_IContactListSyncManager<D>::Status() const
{
    Windows::ApplicationModel::Contacts::ContactListSyncStatus value {};
    check_hresult(WINRT_SHIM(IContactListSyncManager)->get_Status(&value));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IContactListSyncManager<D>::LastSuccessfulSyncTime() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IContactListSyncManager)->get_LastSuccessfulSyncTime(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IContactListSyncManager<D>::LastAttemptedSyncTime() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IContactListSyncManager)->get_LastAttemptedSyncTime(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IContactListSyncManager<D>::SyncAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IContactListSyncManager)->abi_SyncAsync(put_abi(result)));
    return result;
}

template <typename D> event_token impl_IContactListSyncManager<D>::SyncStatusChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Contacts::ContactListSyncManager, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IContactListSyncManager)->add_SyncStatusChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IContactListSyncManager> impl_IContactListSyncManager<D>::SyncStatusChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Contacts::ContactListSyncManager, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IContactListSyncManager>(this, &ABI::Windows::ApplicationModel::Contacts::IContactListSyncManager::remove_SyncStatusChanged, SyncStatusChanged(handler));
}

template <typename D> void impl_IContactListSyncManager<D>::SyncStatusChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IContactListSyncManager)->remove_SyncStatusChanged(token));
}

template <typename D> void impl_IContactListSyncManager2<D>::Status(Windows::ApplicationModel::Contacts::ContactListSyncStatus value) const
{
    check_hresult(WINRT_SHIM(IContactListSyncManager2)->put_Status(value));
}

template <typename D> void impl_IContactListSyncManager2<D>::LastSuccessfulSyncTime(const Windows::Foundation::DateTime & value) const
{
    check_hresult(WINRT_SHIM(IContactListSyncManager2)->put_LastSuccessfulSyncTime(get_abi(value)));
}

template <typename D> void impl_IContactListSyncManager2<D>::LastAttemptedSyncTime(const Windows::Foundation::DateTime & value) const
{
    check_hresult(WINRT_SHIM(IContactListSyncManager2)->put_LastAttemptedSyncTime(get_abi(value)));
}

template <typename D> bool impl_IContactListSyncConstraints<D>::CanSyncDescriptions() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->get_CanSyncDescriptions(&value));
    return value;
}

template <typename D> void impl_IContactListSyncConstraints<D>::CanSyncDescriptions(bool value) const
{
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->put_CanSyncDescriptions(value));
}

template <typename D> Windows::Foundation::IReference<int32_t> impl_IContactListSyncConstraints<D>::MaxHomePhoneNumbers() const
{
    Windows::Foundation::IReference<int32_t> value;
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->get_MaxHomePhoneNumbers(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactListSyncConstraints<D>::MaxHomePhoneNumbers(const optional<int32_t> & value) const
{
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->put_MaxHomePhoneNumbers(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<int32_t> impl_IContactListSyncConstraints<D>::MaxMobilePhoneNumbers() const
{
    Windows::Foundation::IReference<int32_t> value;
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->get_MaxMobilePhoneNumbers(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactListSyncConstraints<D>::MaxMobilePhoneNumbers(const optional<int32_t> & value) const
{
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->put_MaxMobilePhoneNumbers(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<int32_t> impl_IContactListSyncConstraints<D>::MaxWorkPhoneNumbers() const
{
    Windows::Foundation::IReference<int32_t> value;
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->get_MaxWorkPhoneNumbers(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactListSyncConstraints<D>::MaxWorkPhoneNumbers(const optional<int32_t> & value) const
{
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->put_MaxWorkPhoneNumbers(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<int32_t> impl_IContactListSyncConstraints<D>::MaxOtherPhoneNumbers() const
{
    Windows::Foundation::IReference<int32_t> value;
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->get_MaxOtherPhoneNumbers(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactListSyncConstraints<D>::MaxOtherPhoneNumbers(const optional<int32_t> & value) const
{
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->put_MaxOtherPhoneNumbers(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<int32_t> impl_IContactListSyncConstraints<D>::MaxPagerPhoneNumbers() const
{
    Windows::Foundation::IReference<int32_t> value;
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->get_MaxPagerPhoneNumbers(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactListSyncConstraints<D>::MaxPagerPhoneNumbers(const optional<int32_t> & value) const
{
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->put_MaxPagerPhoneNumbers(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<int32_t> impl_IContactListSyncConstraints<D>::MaxBusinessFaxPhoneNumbers() const
{
    Windows::Foundation::IReference<int32_t> value;
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->get_MaxBusinessFaxPhoneNumbers(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactListSyncConstraints<D>::MaxBusinessFaxPhoneNumbers(const optional<int32_t> & value) const
{
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->put_MaxBusinessFaxPhoneNumbers(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<int32_t> impl_IContactListSyncConstraints<D>::MaxHomeFaxPhoneNumbers() const
{
    Windows::Foundation::IReference<int32_t> value;
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->get_MaxHomeFaxPhoneNumbers(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactListSyncConstraints<D>::MaxHomeFaxPhoneNumbers(const optional<int32_t> & value) const
{
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->put_MaxHomeFaxPhoneNumbers(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<int32_t> impl_IContactListSyncConstraints<D>::MaxCompanyPhoneNumbers() const
{
    Windows::Foundation::IReference<int32_t> value;
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->get_MaxCompanyPhoneNumbers(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactListSyncConstraints<D>::MaxCompanyPhoneNumbers(const optional<int32_t> & value) const
{
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->put_MaxCompanyPhoneNumbers(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<int32_t> impl_IContactListSyncConstraints<D>::MaxAssistantPhoneNumbers() const
{
    Windows::Foundation::IReference<int32_t> value;
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->get_MaxAssistantPhoneNumbers(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactListSyncConstraints<D>::MaxAssistantPhoneNumbers(const optional<int32_t> & value) const
{
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->put_MaxAssistantPhoneNumbers(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<int32_t> impl_IContactListSyncConstraints<D>::MaxRadioPhoneNumbers() const
{
    Windows::Foundation::IReference<int32_t> value;
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->get_MaxRadioPhoneNumbers(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactListSyncConstraints<D>::MaxRadioPhoneNumbers(const optional<int32_t> & value) const
{
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->put_MaxRadioPhoneNumbers(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<int32_t> impl_IContactListSyncConstraints<D>::MaxPersonalEmailAddresses() const
{
    Windows::Foundation::IReference<int32_t> value;
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->get_MaxPersonalEmailAddresses(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactListSyncConstraints<D>::MaxPersonalEmailAddresses(const optional<int32_t> & value) const
{
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->put_MaxPersonalEmailAddresses(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<int32_t> impl_IContactListSyncConstraints<D>::MaxWorkEmailAddresses() const
{
    Windows::Foundation::IReference<int32_t> value;
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->get_MaxWorkEmailAddresses(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactListSyncConstraints<D>::MaxWorkEmailAddresses(const optional<int32_t> & value) const
{
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->put_MaxWorkEmailAddresses(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<int32_t> impl_IContactListSyncConstraints<D>::MaxOtherEmailAddresses() const
{
    Windows::Foundation::IReference<int32_t> value;
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->get_MaxOtherEmailAddresses(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactListSyncConstraints<D>::MaxOtherEmailAddresses(const optional<int32_t> & value) const
{
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->put_MaxOtherEmailAddresses(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<int32_t> impl_IContactListSyncConstraints<D>::MaxHomeAddresses() const
{
    Windows::Foundation::IReference<int32_t> value;
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->get_MaxHomeAddresses(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactListSyncConstraints<D>::MaxHomeAddresses(const optional<int32_t> & value) const
{
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->put_MaxHomeAddresses(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<int32_t> impl_IContactListSyncConstraints<D>::MaxWorkAddresses() const
{
    Windows::Foundation::IReference<int32_t> value;
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->get_MaxWorkAddresses(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactListSyncConstraints<D>::MaxWorkAddresses(const optional<int32_t> & value) const
{
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->put_MaxWorkAddresses(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<int32_t> impl_IContactListSyncConstraints<D>::MaxOtherAddresses() const
{
    Windows::Foundation::IReference<int32_t> value;
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->get_MaxOtherAddresses(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactListSyncConstraints<D>::MaxOtherAddresses(const optional<int32_t> & value) const
{
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->put_MaxOtherAddresses(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<int32_t> impl_IContactListSyncConstraints<D>::MaxBirthdayDates() const
{
    Windows::Foundation::IReference<int32_t> value;
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->get_MaxBirthdayDates(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactListSyncConstraints<D>::MaxBirthdayDates(const optional<int32_t> & value) const
{
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->put_MaxBirthdayDates(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<int32_t> impl_IContactListSyncConstraints<D>::MaxAnniversaryDates() const
{
    Windows::Foundation::IReference<int32_t> value;
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->get_MaxAnniversaryDates(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactListSyncConstraints<D>::MaxAnniversaryDates(const optional<int32_t> & value) const
{
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->put_MaxAnniversaryDates(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<int32_t> impl_IContactListSyncConstraints<D>::MaxOtherDates() const
{
    Windows::Foundation::IReference<int32_t> value;
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->get_MaxOtherDates(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactListSyncConstraints<D>::MaxOtherDates(const optional<int32_t> & value) const
{
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->put_MaxOtherDates(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<int32_t> impl_IContactListSyncConstraints<D>::MaxOtherRelationships() const
{
    Windows::Foundation::IReference<int32_t> value;
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->get_MaxOtherRelationships(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactListSyncConstraints<D>::MaxOtherRelationships(const optional<int32_t> & value) const
{
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->put_MaxOtherRelationships(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<int32_t> impl_IContactListSyncConstraints<D>::MaxSpouseRelationships() const
{
    Windows::Foundation::IReference<int32_t> value;
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->get_MaxSpouseRelationships(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactListSyncConstraints<D>::MaxSpouseRelationships(const optional<int32_t> & value) const
{
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->put_MaxSpouseRelationships(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<int32_t> impl_IContactListSyncConstraints<D>::MaxPartnerRelationships() const
{
    Windows::Foundation::IReference<int32_t> value;
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->get_MaxPartnerRelationships(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactListSyncConstraints<D>::MaxPartnerRelationships(const optional<int32_t> & value) const
{
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->put_MaxPartnerRelationships(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<int32_t> impl_IContactListSyncConstraints<D>::MaxSiblingRelationships() const
{
    Windows::Foundation::IReference<int32_t> value;
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->get_MaxSiblingRelationships(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactListSyncConstraints<D>::MaxSiblingRelationships(const optional<int32_t> & value) const
{
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->put_MaxSiblingRelationships(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<int32_t> impl_IContactListSyncConstraints<D>::MaxParentRelationships() const
{
    Windows::Foundation::IReference<int32_t> value;
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->get_MaxParentRelationships(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactListSyncConstraints<D>::MaxParentRelationships(const optional<int32_t> & value) const
{
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->put_MaxParentRelationships(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<int32_t> impl_IContactListSyncConstraints<D>::MaxChildRelationships() const
{
    Windows::Foundation::IReference<int32_t> value;
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->get_MaxChildRelationships(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactListSyncConstraints<D>::MaxChildRelationships(const optional<int32_t> & value) const
{
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->put_MaxChildRelationships(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<int32_t> impl_IContactListSyncConstraints<D>::MaxJobInfo() const
{
    Windows::Foundation::IReference<int32_t> value;
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->get_MaxJobInfo(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactListSyncConstraints<D>::MaxJobInfo(const optional<int32_t> & value) const
{
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->put_MaxJobInfo(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<int32_t> impl_IContactListSyncConstraints<D>::MaxWebsites() const
{
    Windows::Foundation::IReference<int32_t> value;
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->get_MaxWebsites(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactListSyncConstraints<D>::MaxWebsites(const optional<int32_t> & value) const
{
    check_hresult(WINRT_SHIM(IContactListSyncConstraints)->put_MaxWebsites(get_abi(value)));
}

template <typename D> hstring impl_IContactConnectedServiceAccount<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactConnectedServiceAccount)->get_Id(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactConnectedServiceAccount<D>::Id(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactConnectedServiceAccount)->put_Id(get_abi(value)));
}

template <typename D> hstring impl_IContactConnectedServiceAccount<D>::ServiceName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactConnectedServiceAccount)->get_ServiceName(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactConnectedServiceAccount<D>::ServiceName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactConnectedServiceAccount)->put_ServiceName(get_abi(value)));
}

template <typename D> hstring impl_IContactSignificantOther<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactSignificantOther)->get_Name(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactSignificantOther<D>::Name(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactSignificantOther)->put_Name(get_abi(value)));
}

template <typename D> hstring impl_IContactSignificantOther<D>::Description() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactSignificantOther)->get_Description(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactSignificantOther<D>::Description(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactSignificantOther)->put_Description(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Contacts::ContactRelationship impl_IContactSignificantOther2<D>::Relationship() const
{
    Windows::ApplicationModel::Contacts::ContactRelationship value {};
    check_hresult(WINRT_SHIM(IContactSignificantOther2)->get_Relationship(&value));
    return value;
}

template <typename D> void impl_IContactSignificantOther2<D>::Relationship(Windows::ApplicationModel::Contacts::ContactRelationship value) const
{
    check_hresult(WINRT_SHIM(IContactSignificantOther2)->put_Relationship(value));
}

template <typename D> Windows::Foundation::Uri impl_IContactWebsite<D>::Uri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IContactWebsite)->get_Uri(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactWebsite<D>::Uri(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(IContactWebsite)->put_Uri(get_abi(value)));
}

template <typename D> hstring impl_IContactWebsite<D>::Description() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactWebsite)->get_Description(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactWebsite<D>::Description(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactWebsite)->put_Description(get_abi(value)));
}

template <typename D> hstring impl_IContactWebsite2<D>::RawValue() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactWebsite2)->get_RawValue(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactWebsite2<D>::RawValue(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactWebsite2)->put_RawValue(get_abi(value)));
}

template <typename D> hstring impl_IContactEmail<D>::Address() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactEmail)->get_Address(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactEmail<D>::Address(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactEmail)->put_Address(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Contacts::ContactEmailKind impl_IContactEmail<D>::Kind() const
{
    Windows::ApplicationModel::Contacts::ContactEmailKind value {};
    check_hresult(WINRT_SHIM(IContactEmail)->get_Kind(&value));
    return value;
}

template <typename D> void impl_IContactEmail<D>::Kind(Windows::ApplicationModel::Contacts::ContactEmailKind value) const
{
    check_hresult(WINRT_SHIM(IContactEmail)->put_Kind(value));
}

template <typename D> hstring impl_IContactEmail<D>::Description() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactEmail)->get_Description(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactEmail<D>::Description(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactEmail)->put_Description(get_abi(value)));
}

template <typename D> hstring impl_IContactPhone<D>::Number() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactPhone)->get_Number(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactPhone<D>::Number(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactPhone)->put_Number(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Contacts::ContactPhoneKind impl_IContactPhone<D>::Kind() const
{
    Windows::ApplicationModel::Contacts::ContactPhoneKind value {};
    check_hresult(WINRT_SHIM(IContactPhone)->get_Kind(&value));
    return value;
}

template <typename D> void impl_IContactPhone<D>::Kind(Windows::ApplicationModel::Contacts::ContactPhoneKind value) const
{
    check_hresult(WINRT_SHIM(IContactPhone)->put_Kind(value));
}

template <typename D> hstring impl_IContactPhone<D>::Description() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactPhone)->get_Description(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactPhone<D>::Description(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactPhone)->put_Description(get_abi(value)));
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

template <typename D> Windows::ApplicationModel::Contacts::ContactAddressKind impl_IContactAddress<D>::Kind() const
{
    Windows::ApplicationModel::Contacts::ContactAddressKind value {};
    check_hresult(WINRT_SHIM(IContactAddress)->get_Kind(&value));
    return value;
}

template <typename D> void impl_IContactAddress<D>::Kind(Windows::ApplicationModel::Contacts::ContactAddressKind value) const
{
    check_hresult(WINRT_SHIM(IContactAddress)->put_Kind(value));
}

template <typename D> hstring impl_IContactAddress<D>::Description() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactAddress)->get_Description(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactAddress<D>::Description(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactAddress)->put_Description(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<uint32_t> impl_IContactDate<D>::Day() const
{
    Windows::Foundation::IReference<uint32_t> value;
    check_hresult(WINRT_SHIM(IContactDate)->get_Day(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactDate<D>::Day(const optional<uint32_t> & value) const
{
    check_hresult(WINRT_SHIM(IContactDate)->put_Day(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<uint32_t> impl_IContactDate<D>::Month() const
{
    Windows::Foundation::IReference<uint32_t> value;
    check_hresult(WINRT_SHIM(IContactDate)->get_Month(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactDate<D>::Month(const optional<uint32_t> & value) const
{
    check_hresult(WINRT_SHIM(IContactDate)->put_Month(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<int32_t> impl_IContactDate<D>::Year() const
{
    Windows::Foundation::IReference<int32_t> value;
    check_hresult(WINRT_SHIM(IContactDate)->get_Year(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactDate<D>::Year(const optional<int32_t> & value) const
{
    check_hresult(WINRT_SHIM(IContactDate)->put_Year(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Contacts::ContactDateKind impl_IContactDate<D>::Kind() const
{
    Windows::ApplicationModel::Contacts::ContactDateKind value {};
    check_hresult(WINRT_SHIM(IContactDate)->get_Kind(&value));
    return value;
}

template <typename D> void impl_IContactDate<D>::Kind(Windows::ApplicationModel::Contacts::ContactDateKind value) const
{
    check_hresult(WINRT_SHIM(IContactDate)->put_Kind(value));
}

template <typename D> hstring impl_IContactDate<D>::Description() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactDate)->get_Description(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactDate<D>::Description(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactDate)->put_Description(get_abi(value)));
}

template <typename D> hstring impl_IContactJobInfo<D>::CompanyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactJobInfo)->get_CompanyName(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactJobInfo<D>::CompanyName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactJobInfo)->put_CompanyName(get_abi(value)));
}

template <typename D> hstring impl_IContactJobInfo<D>::CompanyYomiName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactJobInfo)->get_CompanyYomiName(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactJobInfo<D>::CompanyYomiName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactJobInfo)->put_CompanyYomiName(get_abi(value)));
}

template <typename D> hstring impl_IContactJobInfo<D>::Department() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactJobInfo)->get_Department(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactJobInfo<D>::Department(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactJobInfo)->put_Department(get_abi(value)));
}

template <typename D> hstring impl_IContactJobInfo<D>::Title() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactJobInfo)->get_Title(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactJobInfo<D>::Title(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactJobInfo)->put_Title(get_abi(value)));
}

template <typename D> hstring impl_IContactJobInfo<D>::Manager() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactJobInfo)->get_Manager(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactJobInfo<D>::Manager(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactJobInfo)->put_Manager(get_abi(value)));
}

template <typename D> hstring impl_IContactJobInfo<D>::Office() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactJobInfo)->get_Office(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactJobInfo<D>::Office(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactJobInfo)->put_Office(get_abi(value)));
}

template <typename D> hstring impl_IContactJobInfo<D>::CompanyAddress() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactJobInfo)->get_CompanyAddress(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactJobInfo<D>::CompanyAddress(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactJobInfo)->put_CompanyAddress(get_abi(value)));
}

template <typename D> hstring impl_IContactJobInfo<D>::Description() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactJobInfo)->get_Description(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactJobInfo<D>::Description(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactJobInfo)->put_Description(get_abi(value)));
}

template <typename D> hstring impl_IContact<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContact)->get_Name(put_abi(value)));
    return value;
}

template <typename D> void impl_IContact<D>::Name(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContact)->put_Name(get_abi(value)));
}

template <typename D> Windows::Storage::Streams::IRandomAccessStreamReference impl_IContact<D>::Thumbnail() const
{
    Windows::Storage::Streams::IRandomAccessStreamReference value;
    check_hresult(WINRT_SHIM(IContact)->get_Thumbnail(put_abi(value)));
    return value;
}

template <typename D> void impl_IContact<D>::Thumbnail(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const
{
    check_hresult(WINRT_SHIM(IContact)->put_Thumbnail(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::IContactField> impl_IContact<D>::Fields() const
{
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::IContactField> value;
    check_hresult(WINRT_SHIM(IContact)->get_Fields(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Contacts::ContactFieldType impl_IContactField<D>::Type() const
{
    Windows::ApplicationModel::Contacts::ContactFieldType value {};
    check_hresult(WINRT_SHIM(IContactField)->get_Type(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Contacts::ContactFieldCategory impl_IContactField<D>::Category() const
{
    Windows::ApplicationModel::Contacts::ContactFieldCategory value {};
    check_hresult(WINRT_SHIM(IContactField)->get_Category(&value));
    return value;
}

template <typename D> hstring impl_IContactField<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactField)->get_Name(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContactField<D>::Value() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactField)->get_Value(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContactName<D>::FirstName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactName)->get_FirstName(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactName<D>::FirstName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactName)->put_FirstName(get_abi(value)));
}

template <typename D> hstring impl_IContactName<D>::LastName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactName)->get_LastName(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactName<D>::LastName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactName)->put_LastName(get_abi(value)));
}

template <typename D> hstring impl_IContactName<D>::MiddleName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactName)->get_MiddleName(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactName<D>::MiddleName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactName)->put_MiddleName(get_abi(value)));
}

template <typename D> hstring impl_IContactName<D>::YomiGivenName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactName)->get_YomiGivenName(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactName<D>::YomiGivenName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactName)->put_YomiGivenName(get_abi(value)));
}

template <typename D> hstring impl_IContactName<D>::YomiFamilyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactName)->get_YomiFamilyName(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactName<D>::YomiFamilyName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactName)->put_YomiFamilyName(get_abi(value)));
}

template <typename D> hstring impl_IContactName<D>::HonorificNameSuffix() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactName)->get_HonorificNameSuffix(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactName<D>::HonorificNameSuffix(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactName)->put_HonorificNameSuffix(get_abi(value)));
}

template <typename D> hstring impl_IContactName<D>::HonorificNamePrefix() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactName)->get_HonorificNamePrefix(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactName<D>::HonorificNamePrefix(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactName)->put_HonorificNamePrefix(get_abi(value)));
}

template <typename D> hstring impl_IContactName<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactName)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContactName<D>::YomiDisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactName)->get_YomiDisplayName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContact2<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContact2)->get_Id(put_abi(value)));
    return value;
}

template <typename D> void impl_IContact2<D>::Id(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContact2)->put_Id(get_abi(value)));
}

template <typename D> hstring impl_IContact2<D>::Notes() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContact2)->get_Notes(put_abi(value)));
    return value;
}

template <typename D> void impl_IContact2<D>::Notes(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContact2)->put_Notes(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactPhone> impl_IContact2<D>::Phones() const
{
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactPhone> value;
    check_hresult(WINRT_SHIM(IContact2)->get_Phones(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactEmail> impl_IContact2<D>::Emails() const
{
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactEmail> value;
    check_hresult(WINRT_SHIM(IContact2)->get_Emails(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactAddress> impl_IContact2<D>::Addresses() const
{
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactAddress> value;
    check_hresult(WINRT_SHIM(IContact2)->get_Addresses(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactConnectedServiceAccount> impl_IContact2<D>::ConnectedServiceAccounts() const
{
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactConnectedServiceAccount> value;
    check_hresult(WINRT_SHIM(IContact2)->get_ConnectedServiceAccounts(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactDate> impl_IContact2<D>::ImportantDates() const
{
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactDate> value;
    check_hresult(WINRT_SHIM(IContact2)->get_ImportantDates(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IContact2<D>::DataSuppliers() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IContact2)->get_DataSuppliers(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactJobInfo> impl_IContact2<D>::JobInfo() const
{
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactJobInfo> value;
    check_hresult(WINRT_SHIM(IContact2)->get_JobInfo(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactSignificantOther> impl_IContact2<D>::SignificantOthers() const
{
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactSignificantOther> value;
    check_hresult(WINRT_SHIM(IContact2)->get_SignificantOthers(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactWebsite> impl_IContact2<D>::Websites() const
{
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactWebsite> value;
    check_hresult(WINRT_SHIM(IContact2)->get_Websites(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IPropertySet impl_IContact2<D>::ProviderProperties() const
{
    Windows::Foundation::Collections::IPropertySet value;
    check_hresult(WINRT_SHIM(IContact2)->get_ProviderProperties(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContact3<D>::ContactListId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContact3)->get_ContactListId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IContact3<D>::DisplayPictureUserUpdateTime() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IContact3)->get_DisplayPictureUserUpdateTime(put_abi(value)));
    return value;
}

template <typename D> void impl_IContact3<D>::DisplayPictureUserUpdateTime(const Windows::Foundation::DateTime & value) const
{
    check_hresult(WINRT_SHIM(IContact3)->put_DisplayPictureUserUpdateTime(get_abi(value)));
}

template <typename D> bool impl_IContact3<D>::IsMe() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IContact3)->get_IsMe(&value));
    return value;
}

template <typename D> hstring impl_IContact3<D>::AggregateId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContact3)->get_AggregateId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContact3<D>::RemoteId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContact3)->get_RemoteId(put_abi(value)));
    return value;
}

template <typename D> void impl_IContact3<D>::RemoteId(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContact3)->put_RemoteId(get_abi(value)));
}

template <typename D> hstring impl_IContact3<D>::RingToneToken() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContact3)->get_RingToneToken(put_abi(value)));
    return value;
}

template <typename D> void impl_IContact3<D>::RingToneToken(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContact3)->put_RingToneToken(get_abi(value)));
}

template <typename D> bool impl_IContact3<D>::IsDisplayPictureManuallySet() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IContact3)->get_IsDisplayPictureManuallySet(&value));
    return value;
}

template <typename D> Windows::Storage::Streams::IRandomAccessStreamReference impl_IContact3<D>::LargeDisplayPicture() const
{
    Windows::Storage::Streams::IRandomAccessStreamReference value;
    check_hresult(WINRT_SHIM(IContact3)->get_LargeDisplayPicture(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IRandomAccessStreamReference impl_IContact3<D>::SmallDisplayPicture() const
{
    Windows::Storage::Streams::IRandomAccessStreamReference value;
    check_hresult(WINRT_SHIM(IContact3)->get_SmallDisplayPicture(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IRandomAccessStreamReference impl_IContact3<D>::SourceDisplayPicture() const
{
    Windows::Storage::Streams::IRandomAccessStreamReference value;
    check_hresult(WINRT_SHIM(IContact3)->get_SourceDisplayPicture(put_abi(value)));
    return value;
}

template <typename D> void impl_IContact3<D>::SourceDisplayPicture(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const
{
    check_hresult(WINRT_SHIM(IContact3)->put_SourceDisplayPicture(get_abi(value)));
}

template <typename D> hstring impl_IContact3<D>::TextToneToken() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContact3)->get_TextToneToken(put_abi(value)));
    return value;
}

template <typename D> void impl_IContact3<D>::TextToneToken(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContact3)->put_TextToneToken(get_abi(value)));
}

template <typename D> bool impl_IContact3<D>::IsAggregate() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IContact3)->get_IsAggregate(&value));
    return value;
}

template <typename D> hstring impl_IContact3<D>::FullName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContact3)->get_FullName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContact3<D>::DisplayNameOverride() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContact3)->get_DisplayNameOverride(put_abi(value)));
    return value;
}

template <typename D> void impl_IContact3<D>::DisplayNameOverride(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContact3)->put_DisplayNameOverride(get_abi(value)));
}

template <typename D> hstring impl_IContact3<D>::Nickname() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContact3)->get_Nickname(put_abi(value)));
    return value;
}

template <typename D> void impl_IContact3<D>::Nickname(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContact3)->put_Nickname(get_abi(value)));
}

template <typename D> hstring impl_IContact3<D>::SortName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContact3)->get_SortName(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Contacts::ContactChangeType impl_IContactChange<D>::ChangeType() const
{
    Windows::ApplicationModel::Contacts::ContactChangeType value {};
    check_hresult(WINRT_SHIM(IContactChange)->get_ChangeType(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Contacts::Contact impl_IContactChange<D>::Contact() const
{
    Windows::ApplicationModel::Contacts::Contact value { nullptr };
    check_hresult(WINRT_SHIM(IContactChange)->get_Contact(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactChangedDeferral<D>::Complete() const
{
    check_hresult(WINRT_SHIM(IContactChangedDeferral)->abi_Complete());
}

template <typename D> Windows::ApplicationModel::Contacts::ContactChangedDeferral impl_IContactChangedEventArgs<D>::GetDeferral() const
{
    Windows::ApplicationModel::Contacts::ContactChangedDeferral value { nullptr };
    check_hresult(WINRT_SHIM(IContactChangedEventArgs)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactChangeReader<D>::AcceptChanges() const
{
    check_hresult(WINRT_SHIM(IContactChangeReader)->abi_AcceptChanges());
}

template <typename D> void impl_IContactChangeReader<D>::AcceptChangesThrough(const Windows::ApplicationModel::Contacts::ContactChange & lastChangeToAccept) const
{
    check_hresult(WINRT_SHIM(IContactChangeReader)->abi_AcceptChangesThrough(get_abi(lastChangeToAccept)));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactChange>> impl_IContactChangeReader<D>::ReadBatchAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactChange>> value;
    check_hresult(WINRT_SHIM(IContactChangeReader)->abi_ReadBatchAsync(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactChangeTracker<D>::Enable() const
{
    check_hresult(WINRT_SHIM(IContactChangeTracker)->abi_Enable());
}

template <typename D> Windows::ApplicationModel::Contacts::ContactChangeReader impl_IContactChangeTracker<D>::GetChangeReader() const
{
    Windows::ApplicationModel::Contacts::ContactChangeReader value { nullptr };
    check_hresult(WINRT_SHIM(IContactChangeTracker)->abi_GetChangeReader(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactChangeTracker<D>::Reset() const
{
    check_hresult(WINRT_SHIM(IContactChangeTracker)->abi_Reset());
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactBatch> impl_IContactReader<D>::ReadBatchAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactBatch> value;
    check_hresult(WINRT_SHIM(IContactReader)->abi_ReadBatchAsync(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactMatchReason> impl_IContactReader<D>::GetMatchingPropertiesWithMatchReason(const Windows::ApplicationModel::Contacts::Contact & contact) const
{
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactMatchReason> ppRetVal;
    check_hresult(WINRT_SHIM(IContactReader)->abi_GetMatchingPropertiesWithMatchReason(get_abi(contact), put_abi(ppRetVal)));
    return ppRetVal;
}

template <typename D> Windows::ApplicationModel::Contacts::ContactQuerySearchFields impl_IContactQueryTextSearch<D>::Fields() const
{
    Windows::ApplicationModel::Contacts::ContactQuerySearchFields value {};
    check_hresult(WINRT_SHIM(IContactQueryTextSearch)->get_Fields(&value));
    return value;
}

template <typename D> void impl_IContactQueryTextSearch<D>::Fields(Windows::ApplicationModel::Contacts::ContactQuerySearchFields value) const
{
    check_hresult(WINRT_SHIM(IContactQueryTextSearch)->put_Fields(value));
}

template <typename D> hstring impl_IContactQueryTextSearch<D>::Text() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactQueryTextSearch)->get_Text(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactQueryTextSearch<D>::Text(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactQueryTextSearch)->put_Text(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Contacts::ContactQuerySearchScope impl_IContactQueryTextSearch<D>::SearchScope() const
{
    Windows::ApplicationModel::Contacts::ContactQuerySearchScope value {};
    check_hresult(WINRT_SHIM(IContactQueryTextSearch)->get_SearchScope(&value));
    return value;
}

template <typename D> void impl_IContactQueryTextSearch<D>::SearchScope(Windows::ApplicationModel::Contacts::ContactQuerySearchScope value) const
{
    check_hresult(WINRT_SHIM(IContactQueryTextSearch)->put_SearchScope(value));
}

template <typename D> Windows::ApplicationModel::Contacts::ContactQueryOptions impl_IContactQueryOptionsFactory<D>::CreateWithText(hstring_view text) const
{
    Windows::ApplicationModel::Contacts::ContactQueryOptions result { nullptr };
    check_hresult(WINRT_SHIM(IContactQueryOptionsFactory)->abi_CreateWithText(get_abi(text), put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Contacts::ContactQueryOptions impl_IContactQueryOptionsFactory<D>::CreateWithTextAndFields(hstring_view text, Windows::ApplicationModel::Contacts::ContactQuerySearchFields fields) const
{
    Windows::ApplicationModel::Contacts::ContactQueryOptions result { nullptr };
    check_hresult(WINRT_SHIM(IContactQueryOptionsFactory)->abi_CreateWithTextAndFields(get_abi(text), fields, put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Contacts::ContactQueryTextSearch impl_IContactQueryOptions<D>::TextSearch() const
{
    Windows::ApplicationModel::Contacts::ContactQueryTextSearch value { nullptr };
    check_hresult(WINRT_SHIM(IContactQueryOptions)->get_TextSearch(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IContactQueryOptions<D>::ContactListIds() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IContactQueryOptions)->get_ContactListIds(put_abi(value)));
    return value;
}

template <typename D> bool impl_IContactQueryOptions<D>::IncludeContactsFromHiddenLists() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IContactQueryOptions)->get_IncludeContactsFromHiddenLists(&value));
    return value;
}

template <typename D> void impl_IContactQueryOptions<D>::IncludeContactsFromHiddenLists(bool value) const
{
    check_hresult(WINRT_SHIM(IContactQueryOptions)->put_IncludeContactsFromHiddenLists(value));
}

template <typename D> Windows::ApplicationModel::Contacts::ContactQueryDesiredFields impl_IContactQueryOptions<D>::DesiredFields() const
{
    Windows::ApplicationModel::Contacts::ContactQueryDesiredFields value {};
    check_hresult(WINRT_SHIM(IContactQueryOptions)->get_DesiredFields(&value));
    return value;
}

template <typename D> void impl_IContactQueryOptions<D>::DesiredFields(Windows::ApplicationModel::Contacts::ContactQueryDesiredFields value) const
{
    check_hresult(WINRT_SHIM(IContactQueryOptions)->put_DesiredFields(value));
}

template <typename D> Windows::ApplicationModel::Contacts::ContactAnnotationOperations impl_IContactQueryOptions<D>::DesiredOperations() const
{
    Windows::ApplicationModel::Contacts::ContactAnnotationOperations value {};
    check_hresult(WINRT_SHIM(IContactQueryOptions)->get_DesiredOperations(&value));
    return value;
}

template <typename D> void impl_IContactQueryOptions<D>::DesiredOperations(Windows::ApplicationModel::Contacts::ContactAnnotationOperations value) const
{
    check_hresult(WINRT_SHIM(IContactQueryOptions)->put_DesiredOperations(value));
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IContactQueryOptions<D>::AnnotationListIds() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IContactQueryOptions)->get_AnnotationListIds(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::Contact> impl_IContactBatch<D>::Contacts() const
{
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::Contact> value;
    check_hresult(WINRT_SHIM(IContactBatch)->get_Contacts(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Contacts::ContactBatchStatus impl_IContactBatch<D>::Status() const
{
    Windows::ApplicationModel::Contacts::ContactBatchStatus value {};
    check_hresult(WINRT_SHIM(IContactBatch)->get_Status(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Contacts::ContactMatchReasonKind impl_IContactMatchReason<D>::Field() const
{
    Windows::ApplicationModel::Contacts::ContactMatchReasonKind value {};
    check_hresult(WINRT_SHIM(IContactMatchReason)->get_Field(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Data::Text::TextSegment> impl_IContactMatchReason<D>::Segments() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Data::Text::TextSegment> value;
    check_hresult(WINRT_SHIM(IContactMatchReason)->get_Segments(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContactMatchReason<D>::Text() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactMatchReason)->get_Text(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContactLaunchActionVerbsStatics<D>::Call() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactLaunchActionVerbsStatics)->get_Call(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContactLaunchActionVerbsStatics<D>::Message() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactLaunchActionVerbsStatics)->get_Message(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContactLaunchActionVerbsStatics<D>::Map() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactLaunchActionVerbsStatics)->get_Map(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContactLaunchActionVerbsStatics<D>::Post() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactLaunchActionVerbsStatics)->get_Post(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContactLaunchActionVerbsStatics<D>::VideoCall() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactLaunchActionVerbsStatics)->get_VideoCall(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContactLocationField<D>::UnstructuredAddress() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactLocationField)->get_UnstructuredAddress(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContactLocationField<D>::Street() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactLocationField)->get_Street(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContactLocationField<D>::City() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactLocationField)->get_City(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContactLocationField<D>::Region() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactLocationField)->get_Region(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContactLocationField<D>::Country() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactLocationField)->get_Country(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContactLocationField<D>::PostalCode() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactLocationField)->get_PostalCode(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContactInstantMessageField<D>::UserName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactInstantMessageField)->get_UserName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContactInstantMessageField<D>::Service() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactInstantMessageField)->get_Service(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContactInstantMessageField<D>::DisplayText() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactInstantMessageField)->get_DisplayText(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_IContactInstantMessageField<D>::LaunchUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IContactInstantMessageField)->get_LaunchUri(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownContactFieldStatics<D>::Email() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactFieldStatics)->get_Email(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownContactFieldStatics<D>::PhoneNumber() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactFieldStatics)->get_PhoneNumber(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownContactFieldStatics<D>::Location() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactFieldStatics)->get_Location(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownContactFieldStatics<D>::InstantMessage() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownContactFieldStatics)->get_InstantMessage(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Contacts::ContactFieldType impl_IKnownContactFieldStatics<D>::ConvertNameToType(hstring_view name) const
{
    Windows::ApplicationModel::Contacts::ContactFieldType type {};
    check_hresult(WINRT_SHIM(IKnownContactFieldStatics)->abi_ConvertNameToType(get_abi(name), &type));
    return type;
}

template <typename D> hstring impl_IKnownContactFieldStatics<D>::ConvertTypeToName(Windows::ApplicationModel::Contacts::ContactFieldType type) const
{
    hstring name;
    check_hresult(WINRT_SHIM(IKnownContactFieldStatics)->abi_ConvertTypeToName(type, put_abi(name)));
    return name;
}

template <typename D> hstring impl_IContactInformation<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactInformation)->get_Name(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamWithContentType> impl_IContactInformation<D>::GetThumbnailAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamWithContentType> operation;
    check_hresult(WINRT_SHIM(IContactInformation)->abi_GetThumbnailAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactField> impl_IContactInformation<D>::Emails() const
{
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactField> value;
    check_hresult(WINRT_SHIM(IContactInformation)->get_Emails(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactField> impl_IContactInformation<D>::PhoneNumbers() const
{
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactField> value;
    check_hresult(WINRT_SHIM(IContactInformation)->get_PhoneNumbers(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactLocationField> impl_IContactInformation<D>::Locations() const
{
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactLocationField> value;
    check_hresult(WINRT_SHIM(IContactInformation)->get_Locations(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactInstantMessageField> impl_IContactInformation<D>::InstantMessages() const
{
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactInstantMessageField> value;
    check_hresult(WINRT_SHIM(IContactInformation)->get_InstantMessages(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactField> impl_IContactInformation<D>::CustomFields() const
{
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactField> value;
    check_hresult(WINRT_SHIM(IContactInformation)->get_CustomFields(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactField> impl_IContactInformation<D>::QueryCustomFields(hstring_view customName) const
{
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactField> value;
    check_hresult(WINRT_SHIM(IContactInformation)->abi_QueryCustomFields(get_abi(customName), put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Contacts::ContactField impl_IContactFieldFactory<D>::CreateField(hstring_view value, Windows::ApplicationModel::Contacts::ContactFieldType type) const
{
    Windows::ApplicationModel::Contacts::ContactField field { nullptr };
    check_hresult(WINRT_SHIM(IContactFieldFactory)->abi_CreateField_Default(get_abi(value), type, put_abi(field)));
    return field;
}

template <typename D> Windows::ApplicationModel::Contacts::ContactField impl_IContactFieldFactory<D>::CreateField(hstring_view value, Windows::ApplicationModel::Contacts::ContactFieldType type, Windows::ApplicationModel::Contacts::ContactFieldCategory category) const
{
    Windows::ApplicationModel::Contacts::ContactField field { nullptr };
    check_hresult(WINRT_SHIM(IContactFieldFactory)->abi_CreateField_Category(get_abi(value), type, category, put_abi(field)));
    return field;
}

template <typename D> Windows::ApplicationModel::Contacts::ContactField impl_IContactFieldFactory<D>::CreateField(hstring_view name, hstring_view value, Windows::ApplicationModel::Contacts::ContactFieldType type, Windows::ApplicationModel::Contacts::ContactFieldCategory category) const
{
    Windows::ApplicationModel::Contacts::ContactField field { nullptr };
    check_hresult(WINRT_SHIM(IContactFieldFactory)->abi_CreateField_Custom(get_abi(name), get_abi(value), type, category, put_abi(field)));
    return field;
}

template <typename D> Windows::ApplicationModel::Contacts::ContactLocationField impl_IContactLocationFieldFactory<D>::CreateLocation(hstring_view unstructuredAddress) const
{
    Windows::ApplicationModel::Contacts::ContactLocationField field { nullptr };
    check_hresult(WINRT_SHIM(IContactLocationFieldFactory)->abi_CreateLocation_Default(get_abi(unstructuredAddress), put_abi(field)));
    return field;
}

template <typename D> Windows::ApplicationModel::Contacts::ContactLocationField impl_IContactLocationFieldFactory<D>::CreateLocation(hstring_view unstructuredAddress, Windows::ApplicationModel::Contacts::ContactFieldCategory category) const
{
    Windows::ApplicationModel::Contacts::ContactLocationField field { nullptr };
    check_hresult(WINRT_SHIM(IContactLocationFieldFactory)->abi_CreateLocation_Category(get_abi(unstructuredAddress), category, put_abi(field)));
    return field;
}

template <typename D> Windows::ApplicationModel::Contacts::ContactLocationField impl_IContactLocationFieldFactory<D>::CreateLocation(hstring_view unstructuredAddress, Windows::ApplicationModel::Contacts::ContactFieldCategory category, hstring_view street, hstring_view city, hstring_view region, hstring_view country, hstring_view postalCode) const
{
    Windows::ApplicationModel::Contacts::ContactLocationField field { nullptr };
    check_hresult(WINRT_SHIM(IContactLocationFieldFactory)->abi_CreateLocation_All(get_abi(unstructuredAddress), category, get_abi(street), get_abi(city), get_abi(region), get_abi(country), get_abi(postalCode), put_abi(field)));
    return field;
}

template <typename D> Windows::ApplicationModel::Contacts::ContactInstantMessageField impl_IContactInstantMessageFieldFactory<D>::CreateInstantMessage(hstring_view userName) const
{
    Windows::ApplicationModel::Contacts::ContactInstantMessageField field { nullptr };
    check_hresult(WINRT_SHIM(IContactInstantMessageFieldFactory)->abi_CreateInstantMessage_Default(get_abi(userName), put_abi(field)));
    return field;
}

template <typename D> Windows::ApplicationModel::Contacts::ContactInstantMessageField impl_IContactInstantMessageFieldFactory<D>::CreateInstantMessage(hstring_view userName, Windows::ApplicationModel::Contacts::ContactFieldCategory category) const
{
    Windows::ApplicationModel::Contacts::ContactInstantMessageField field { nullptr };
    check_hresult(WINRT_SHIM(IContactInstantMessageFieldFactory)->abi_CreateInstantMessage_Category(get_abi(userName), category, put_abi(field)));
    return field;
}

template <typename D> Windows::ApplicationModel::Contacts::ContactInstantMessageField impl_IContactInstantMessageFieldFactory<D>::CreateInstantMessage(hstring_view userName, Windows::ApplicationModel::Contacts::ContactFieldCategory category, hstring_view service, hstring_view displayText, const Windows::Foundation::Uri & verb) const
{
    Windows::ApplicationModel::Contacts::ContactInstantMessageField field { nullptr };
    check_hresult(WINRT_SHIM(IContactInstantMessageFieldFactory)->abi_CreateInstantMessage_All(get_abi(userName), category, get_abi(service), get_abi(displayText), get_abi(verb), put_abi(field)));
    return field;
}

template <typename D> hstring impl_IContactPicker<D>::CommitButtonText() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactPicker)->get_CommitButtonText(put_abi(value)));
    return value;
}

template <typename D> void impl_IContactPicker<D>::CommitButtonText(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IContactPicker)->put_CommitButtonText(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Contacts::ContactSelectionMode impl_IContactPicker<D>::SelectionMode() const
{
    Windows::ApplicationModel::Contacts::ContactSelectionMode value {};
    check_hresult(WINRT_SHIM(IContactPicker)->get_SelectionMode(&value));
    return value;
}

template <typename D> void impl_IContactPicker<D>::SelectionMode(Windows::ApplicationModel::Contacts::ContactSelectionMode value) const
{
    check_hresult(WINRT_SHIM(IContactPicker)->put_SelectionMode(value));
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IContactPicker<D>::DesiredFields() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IContactPicker)->get_DesiredFields(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactInformation> impl_IContactPicker<D>::PickSingleContactAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactInformation> result;
    check_hresult(WINRT_SHIM(IContactPicker)->abi_PickSingleContactAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactInformation>> impl_IContactPicker<D>::PickMultipleContactsAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactInformation>> result;
    check_hresult(WINRT_SHIM(IContactPicker)->abi_PickMultipleContactsAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Collections::IVector<winrt::Windows::ApplicationModel::Contacts::ContactFieldType> impl_IContactPicker2<D>::DesiredFieldsWithContactFieldType() const
{
    Windows::Foundation::Collections::IVector<winrt::Windows::ApplicationModel::Contacts::ContactFieldType> value;
    check_hresult(WINRT_SHIM(IContactPicker2)->get_DesiredFieldsWithContactFieldType(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact> impl_IContactPicker2<D>::PickContactAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact> result;
    check_hresult(WINRT_SHIM(IContactPicker2)->abi_PickContactAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::Contact>> impl_IContactPicker2<D>::PickContactsAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::Contact>> result;
    check_hresult(WINRT_SHIM(IContactPicker2)->abi_PickContactsAsync(put_abi(result)));
    return result;
}

template <typename D> void impl_IContactCardDelayedDataLoader<D>::SetData(const Windows::ApplicationModel::Contacts::Contact & contact) const
{
    check_hresult(WINRT_SHIM(IContactCardDelayedDataLoader)->abi_SetData(get_abi(contact)));
}

inline Contact::Contact() :
    Contact(activate_instance<Contact>())
{}

inline ContactAddress::ContactAddress() :
    ContactAddress(activate_instance<ContactAddress>())
{}

inline ContactAnnotation::ContactAnnotation() :
    ContactAnnotation(activate_instance<ContactAnnotation>())
{}

inline ContactCardOptions::ContactCardOptions() :
    ContactCardOptions(activate_instance<ContactCardOptions>())
{}

inline ContactConnectedServiceAccount::ContactConnectedServiceAccount() :
    ContactConnectedServiceAccount(activate_instance<ContactConnectedServiceAccount>())
{}

inline ContactDate::ContactDate() :
    ContactDate(activate_instance<ContactDate>())
{}

inline ContactEmail::ContactEmail() :
    ContactEmail(activate_instance<ContactEmail>())
{}

inline ContactField::ContactField(hstring_view value, Windows::ApplicationModel::Contacts::ContactFieldType type) :
    ContactField(get_activation_factory<ContactField, IContactFieldFactory>().CreateField(value, type))
{}

inline ContactField::ContactField(hstring_view value, Windows::ApplicationModel::Contacts::ContactFieldType type, Windows::ApplicationModel::Contacts::ContactFieldCategory category) :
    ContactField(get_activation_factory<ContactField, IContactFieldFactory>().CreateField(value, type, category))
{}

inline ContactField::ContactField(hstring_view name, hstring_view value, Windows::ApplicationModel::Contacts::ContactFieldType type, Windows::ApplicationModel::Contacts::ContactFieldCategory category) :
    ContactField(get_activation_factory<ContactField, IContactFieldFactory>().CreateField(name, value, type, category))
{}

inline ContactFieldFactory::ContactFieldFactory() :
    ContactFieldFactory(activate_instance<ContactFieldFactory>())
{}

inline ContactInstantMessageField::ContactInstantMessageField(hstring_view userName) :
    ContactInstantMessageField(get_activation_factory<ContactInstantMessageField, IContactInstantMessageFieldFactory>().CreateInstantMessage(userName))
{}

inline ContactInstantMessageField::ContactInstantMessageField(hstring_view userName, Windows::ApplicationModel::Contacts::ContactFieldCategory category) :
    ContactInstantMessageField(get_activation_factory<ContactInstantMessageField, IContactInstantMessageFieldFactory>().CreateInstantMessage(userName, category))
{}

inline ContactInstantMessageField::ContactInstantMessageField(hstring_view userName, Windows::ApplicationModel::Contacts::ContactFieldCategory category, hstring_view service, hstring_view displayText, const Windows::Foundation::Uri & verb) :
    ContactInstantMessageField(get_activation_factory<ContactInstantMessageField, IContactInstantMessageFieldFactory>().CreateInstantMessage(userName, category, service, displayText, verb))
{}

inline ContactJobInfo::ContactJobInfo() :
    ContactJobInfo(activate_instance<ContactJobInfo>())
{}

inline hstring ContactLaunchActionVerbs::Call()
{
    return get_activation_factory<ContactLaunchActionVerbs, IContactLaunchActionVerbsStatics>().Call();
}

inline hstring ContactLaunchActionVerbs::Message()
{
    return get_activation_factory<ContactLaunchActionVerbs, IContactLaunchActionVerbsStatics>().Message();
}

inline hstring ContactLaunchActionVerbs::Map()
{
    return get_activation_factory<ContactLaunchActionVerbs, IContactLaunchActionVerbsStatics>().Map();
}

inline hstring ContactLaunchActionVerbs::Post()
{
    return get_activation_factory<ContactLaunchActionVerbs, IContactLaunchActionVerbsStatics>().Post();
}

inline hstring ContactLaunchActionVerbs::VideoCall()
{
    return get_activation_factory<ContactLaunchActionVerbs, IContactLaunchActionVerbsStatics>().VideoCall();
}

inline ContactLocationField::ContactLocationField(hstring_view unstructuredAddress) :
    ContactLocationField(get_activation_factory<ContactLocationField, IContactLocationFieldFactory>().CreateLocation(unstructuredAddress))
{}

inline ContactLocationField::ContactLocationField(hstring_view unstructuredAddress, Windows::ApplicationModel::Contacts::ContactFieldCategory category) :
    ContactLocationField(get_activation_factory<ContactLocationField, IContactLocationFieldFactory>().CreateLocation(unstructuredAddress, category))
{}

inline ContactLocationField::ContactLocationField(hstring_view unstructuredAddress, Windows::ApplicationModel::Contacts::ContactFieldCategory category, hstring_view street, hstring_view city, hstring_view region, hstring_view country, hstring_view postalCode) :
    ContactLocationField(get_activation_factory<ContactLocationField, IContactLocationFieldFactory>().CreateLocation(unstructuredAddress, category, street, city, region, country, postalCode))
{}

inline void ContactManager::ShowContactCard(const Windows::ApplicationModel::Contacts::Contact & contact, const Windows::Foundation::Rect & selection)
{
    get_activation_factory<ContactManager, IContactManagerStatics>().ShowContactCard(contact, selection);
}

inline void ContactManager::ShowContactCard(const Windows::ApplicationModel::Contacts::Contact & contact, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement)
{
    get_activation_factory<ContactManager, IContactManagerStatics>().ShowContactCard(contact, selection, preferredPlacement);
}

inline Windows::ApplicationModel::Contacts::ContactCardDelayedDataLoader ContactManager::ShowDelayLoadedContactCard(const Windows::ApplicationModel::Contacts::Contact & contact, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement)
{
    return get_activation_factory<ContactManager, IContactManagerStatics>().ShowDelayLoadedContactCard(contact, selection, preferredPlacement);
}

inline Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactStore> ContactManager::RequestStoreAsync()
{
    return get_activation_factory<ContactManager, IContactManagerStatics2>().RequestStoreAsync();
}

inline Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::RandomAccessStreamReference> ContactManager::ConvertContactToVCardAsync(const Windows::ApplicationModel::Contacts::Contact & contact)
{
    return get_activation_factory<ContactManager, IContactManagerStatics3>().ConvertContactToVCardAsync(contact);
}

inline Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::RandomAccessStreamReference> ContactManager::ConvertContactToVCardAsync(const Windows::ApplicationModel::Contacts::Contact & contact, uint32_t maxBytes)
{
    return get_activation_factory<ContactManager, IContactManagerStatics3>().ConvertContactToVCardAsync(contact, maxBytes);
}

inline Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact> ContactManager::ConvertVCardToContactAsync(const Windows::Storage::Streams::IRandomAccessStreamReference & vCard)
{
    return get_activation_factory<ContactManager, IContactManagerStatics3>().ConvertVCardToContactAsync(vCard);
}

inline Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactStore> ContactManager::RequestStoreAsync(Windows::ApplicationModel::Contacts::ContactStoreAccessType accessType)
{
    return get_activation_factory<ContactManager, IContactManagerStatics3>().RequestStoreAsync(accessType);
}

inline Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactAnnotationStore> ContactManager::RequestAnnotationStoreAsync(Windows::ApplicationModel::Contacts::ContactAnnotationStoreAccessType accessType)
{
    return get_activation_factory<ContactManager, IContactManagerStatics3>().RequestAnnotationStoreAsync(accessType);
}

inline bool ContactManager::IsShowContactCardSupported()
{
    return get_activation_factory<ContactManager, IContactManagerStatics3>().IsShowContactCardSupported();
}

inline void ContactManager::ShowContactCard(const Windows::ApplicationModel::Contacts::Contact & contact, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement, const Windows::ApplicationModel::Contacts::ContactCardOptions & contactCardOptions)
{
    get_activation_factory<ContactManager, IContactManagerStatics3>().ShowContactCard(contact, selection, preferredPlacement, contactCardOptions);
}

inline bool ContactManager::IsShowDelayLoadedContactCardSupported()
{
    return get_activation_factory<ContactManager, IContactManagerStatics3>().IsShowDelayLoadedContactCardSupported();
}

inline Windows::ApplicationModel::Contacts::ContactCardDelayedDataLoader ContactManager::ShowDelayLoadedContactCard(const Windows::ApplicationModel::Contacts::Contact & contact, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement, const Windows::ApplicationModel::Contacts::ContactCardOptions & contactCardOptions)
{
    return get_activation_factory<ContactManager, IContactManagerStatics3>().ShowDelayLoadedContactCard(contact, selection, preferredPlacement, contactCardOptions);
}

inline void ContactManager::ShowFullContactCard(const Windows::ApplicationModel::Contacts::Contact & contact, const Windows::ApplicationModel::Contacts::FullContactCardOptions & fullContactCardOptions)
{
    get_activation_factory<ContactManager, IContactManagerStatics3>().ShowFullContactCard(contact, fullContactCardOptions);
}

inline Windows::ApplicationModel::Contacts::ContactNameOrder ContactManager::SystemDisplayNameOrder()
{
    return get_activation_factory<ContactManager, IContactManagerStatics3>().SystemDisplayNameOrder();
}

inline void ContactManager::SystemDisplayNameOrder(Windows::ApplicationModel::Contacts::ContactNameOrder value)
{
    get_activation_factory<ContactManager, IContactManagerStatics3>().SystemDisplayNameOrder(value);
}

inline Windows::ApplicationModel::Contacts::ContactNameOrder ContactManager::SystemSortOrder()
{
    return get_activation_factory<ContactManager, IContactManagerStatics3>().SystemSortOrder();
}

inline void ContactManager::SystemSortOrder(Windows::ApplicationModel::Contacts::ContactNameOrder value)
{
    get_activation_factory<ContactManager, IContactManagerStatics3>().SystemSortOrder(value);
}

inline Windows::ApplicationModel::Contacts::ContactManagerForUser ContactManager::GetForUser(const Windows::System::User & user)
{
    return get_activation_factory<ContactManager, IContactManagerStatics4>().GetForUser(user);
}

inline ContactPhone::ContactPhone() :
    ContactPhone(activate_instance<ContactPhone>())
{}

inline ContactPicker::ContactPicker() :
    ContactPicker(activate_instance<ContactPicker>())
{}

inline ContactQueryOptions::ContactQueryOptions() :
    ContactQueryOptions(activate_instance<ContactQueryOptions>())
{}

inline ContactQueryOptions::ContactQueryOptions(hstring_view text) :
    ContactQueryOptions(get_activation_factory<ContactQueryOptions, IContactQueryOptionsFactory>().CreateWithText(text))
{}

inline ContactQueryOptions::ContactQueryOptions(hstring_view text, Windows::ApplicationModel::Contacts::ContactQuerySearchFields fields) :
    ContactQueryOptions(get_activation_factory<ContactQueryOptions, IContactQueryOptionsFactory>().CreateWithTextAndFields(text, fields))
{}

inline ContactSignificantOther::ContactSignificantOther() :
    ContactSignificantOther(activate_instance<ContactSignificantOther>())
{}

inline ContactWebsite::ContactWebsite() :
    ContactWebsite(activate_instance<ContactWebsite>())
{}

inline FullContactCardOptions::FullContactCardOptions() :
    FullContactCardOptions(activate_instance<FullContactCardOptions>())
{}

inline hstring KnownContactField::Email()
{
    return get_activation_factory<KnownContactField, IKnownContactFieldStatics>().Email();
}

inline hstring KnownContactField::PhoneNumber()
{
    return get_activation_factory<KnownContactField, IKnownContactFieldStatics>().PhoneNumber();
}

inline hstring KnownContactField::Location()
{
    return get_activation_factory<KnownContactField, IKnownContactFieldStatics>().Location();
}

inline hstring KnownContactField::InstantMessage()
{
    return get_activation_factory<KnownContactField, IKnownContactFieldStatics>().InstantMessage();
}

inline Windows::ApplicationModel::Contacts::ContactFieldType KnownContactField::ConvertNameToType(hstring_view name)
{
    return get_activation_factory<KnownContactField, IKnownContactFieldStatics>().ConvertNameToType(name);
}

inline hstring KnownContactField::ConvertTypeToName(Windows::ApplicationModel::Contacts::ContactFieldType type)
{
    return get_activation_factory<KnownContactField, IKnownContactFieldStatics>().ConvertTypeToName(type);
}

}

}
#pragma warning(pop)
