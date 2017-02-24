// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.ApplicationModel.SocialInfo.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.ApplicationModel.SocialInfo.Provider.3.h"
#include "Windows.ApplicationModel.SocialInfo.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater> : produce_base<D, Windows::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater>
{
    HRESULT __stdcall get_OwnerRemoteId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OwnerRemoteId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Content(impl::abi_arg_out<Windows::ApplicationModel::SocialInfo::ISocialFeedContent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Content());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall put_Timestamp(impl::abi_arg_in<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Timestamp(*reinterpret_cast<const Windows::Foundation::DateTime *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Thumbnail(impl::abi_arg_in<Windows::ApplicationModel::SocialInfo::ISocialItemThumbnail> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Thumbnail(*reinterpret_cast<const Windows::ApplicationModel::SocialInfo::SocialItemThumbnail *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Thumbnail(impl::abi_arg_out<Windows::ApplicationModel::SocialInfo::ISocialItemThumbnail> value) noexcept override
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

    HRESULT __stdcall abi_CommitAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CommitAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TargetUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TargetUri(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TargetUri(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::SocialInfo::Provider::ISocialFeedUpdater> : produce_base<D, Windows::ApplicationModel::SocialInfo::Provider::ISocialFeedUpdater>
{
    HRESULT __stdcall get_OwnerRemoteId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OwnerRemoteId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Kind(Windows::ApplicationModel::SocialInfo::SocialFeedKind * value) noexcept override
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

    HRESULT __stdcall get_Items(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::SocialInfo::SocialFeedItem>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Items());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CommitAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CommitAsync());
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
struct produce<D, Windows::ApplicationModel::SocialInfo::Provider::ISocialInfoProviderManagerStatics> : produce_base<D, Windows::ApplicationModel::SocialInfo::Provider::ISocialInfoProviderManagerStatics>
{
    HRESULT __stdcall abi_CreateSocialFeedUpdaterAsync(Windows::ApplicationModel::SocialInfo::SocialFeedKind kind, Windows::ApplicationModel::SocialInfo::SocialFeedUpdateMode mode, impl::abi_arg_in<hstring> ownerRemoteId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::SocialInfo::Provider::SocialFeedUpdater>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreateSocialFeedUpdaterAsync(kind, mode, *reinterpret_cast<const hstring *>(&ownerRemoteId)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateDashboardItemUpdaterAsync(impl::abi_arg_in<hstring> ownerRemoteId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::SocialInfo::Provider::SocialDashboardItemUpdater>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreateDashboardItemUpdaterAsync(*reinterpret_cast<const hstring *>(&ownerRemoteId)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UpdateBadgeCountValue(impl::abi_arg_in<hstring> itemRemoteId, int32_t newCount) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UpdateBadgeCountValue(*reinterpret_cast<const hstring *>(&itemRemoteId), newCount);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportNewContentAvailable(impl::abi_arg_in<hstring> contactRemoteId, Windows::ApplicationModel::SocialInfo::SocialFeedKind kind) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportNewContentAvailable(*reinterpret_cast<const hstring *>(&contactRemoteId), kind);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ProvisionAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ProvisionAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeprovisionAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().DeprovisionAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::ApplicationModel::SocialInfo::Provider {

template <typename D> hstring impl_ISocialFeedUpdater<D>::OwnerRemoteId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISocialFeedUpdater)->get_OwnerRemoteId(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::SocialInfo::SocialFeedKind impl_ISocialFeedUpdater<D>::Kind() const
{
    Windows::ApplicationModel::SocialInfo::SocialFeedKind value {};
    check_hresult(WINRT_SHIM(ISocialFeedUpdater)->get_Kind(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::ApplicationModel::SocialInfo::SocialFeedItem> impl_ISocialFeedUpdater<D>::Items() const
{
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::SocialInfo::SocialFeedItem> value;
    check_hresult(WINRT_SHIM(ISocialFeedUpdater)->get_Items(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ISocialFeedUpdater<D>::CommitAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(ISocialFeedUpdater)->abi_CommitAsync(put_abi(operation)));
    return operation;
}

template <typename D> hstring impl_ISocialDashboardItemUpdater<D>::OwnerRemoteId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISocialDashboardItemUpdater)->get_OwnerRemoteId(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::SocialInfo::SocialFeedContent impl_ISocialDashboardItemUpdater<D>::Content() const
{
    Windows::ApplicationModel::SocialInfo::SocialFeedContent value { nullptr };
    check_hresult(WINRT_SHIM(ISocialDashboardItemUpdater)->get_Content(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_ISocialDashboardItemUpdater<D>::Timestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(ISocialDashboardItemUpdater)->get_Timestamp(put_abi(value)));
    return value;
}

template <typename D> void impl_ISocialDashboardItemUpdater<D>::Timestamp(const Windows::Foundation::DateTime & value) const
{
    check_hresult(WINRT_SHIM(ISocialDashboardItemUpdater)->put_Timestamp(get_abi(value)));
}

template <typename D> void impl_ISocialDashboardItemUpdater<D>::Thumbnail(const Windows::ApplicationModel::SocialInfo::SocialItemThumbnail & value) const
{
    check_hresult(WINRT_SHIM(ISocialDashboardItemUpdater)->put_Thumbnail(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::SocialInfo::SocialItemThumbnail impl_ISocialDashboardItemUpdater<D>::Thumbnail() const
{
    Windows::ApplicationModel::SocialInfo::SocialItemThumbnail value { nullptr };
    check_hresult(WINRT_SHIM(ISocialDashboardItemUpdater)->get_Thumbnail(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ISocialDashboardItemUpdater<D>::CommitAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(ISocialDashboardItemUpdater)->abi_CommitAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::Uri impl_ISocialDashboardItemUpdater<D>::TargetUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(ISocialDashboardItemUpdater)->get_TargetUri(put_abi(value)));
    return value;
}

template <typename D> void impl_ISocialDashboardItemUpdater<D>::TargetUri(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(ISocialDashboardItemUpdater)->put_TargetUri(get_abi(value)));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::SocialInfo::Provider::SocialFeedUpdater> impl_ISocialInfoProviderManagerStatics<D>::CreateSocialFeedUpdaterAsync(Windows::ApplicationModel::SocialInfo::SocialFeedKind kind, Windows::ApplicationModel::SocialInfo::SocialFeedUpdateMode mode, hstring_view ownerRemoteId) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::SocialInfo::Provider::SocialFeedUpdater> operation;
    check_hresult(WINRT_SHIM(ISocialInfoProviderManagerStatics)->abi_CreateSocialFeedUpdaterAsync(kind, mode, get_abi(ownerRemoteId), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::SocialInfo::Provider::SocialDashboardItemUpdater> impl_ISocialInfoProviderManagerStatics<D>::CreateDashboardItemUpdaterAsync(hstring_view ownerRemoteId) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::SocialInfo::Provider::SocialDashboardItemUpdater> operation;
    check_hresult(WINRT_SHIM(ISocialInfoProviderManagerStatics)->abi_CreateDashboardItemUpdaterAsync(get_abi(ownerRemoteId), put_abi(operation)));
    return operation;
}

template <typename D> void impl_ISocialInfoProviderManagerStatics<D>::UpdateBadgeCountValue(hstring_view itemRemoteId, int32_t newCount) const
{
    check_hresult(WINRT_SHIM(ISocialInfoProviderManagerStatics)->abi_UpdateBadgeCountValue(get_abi(itemRemoteId), newCount));
}

template <typename D> void impl_ISocialInfoProviderManagerStatics<D>::ReportNewContentAvailable(hstring_view contactRemoteId, Windows::ApplicationModel::SocialInfo::SocialFeedKind kind) const
{
    check_hresult(WINRT_SHIM(ISocialInfoProviderManagerStatics)->abi_ReportNewContentAvailable(get_abi(contactRemoteId), kind));
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ISocialInfoProviderManagerStatics<D>::ProvisionAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(ISocialInfoProviderManagerStatics)->abi_ProvisionAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ISocialInfoProviderManagerStatics<D>::DeprovisionAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(ISocialInfoProviderManagerStatics)->abi_DeprovisionAsync(put_abi(operation)));
    return operation;
}

inline Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::SocialInfo::Provider::SocialFeedUpdater> SocialInfoProviderManager::CreateSocialFeedUpdaterAsync(Windows::ApplicationModel::SocialInfo::SocialFeedKind kind, Windows::ApplicationModel::SocialInfo::SocialFeedUpdateMode mode, hstring_view ownerRemoteId)
{
    return get_activation_factory<SocialInfoProviderManager, ISocialInfoProviderManagerStatics>().CreateSocialFeedUpdaterAsync(kind, mode, ownerRemoteId);
}

inline Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::SocialInfo::Provider::SocialDashboardItemUpdater> SocialInfoProviderManager::CreateDashboardItemUpdaterAsync(hstring_view ownerRemoteId)
{
    return get_activation_factory<SocialInfoProviderManager, ISocialInfoProviderManagerStatics>().CreateDashboardItemUpdaterAsync(ownerRemoteId);
}

inline void SocialInfoProviderManager::UpdateBadgeCountValue(hstring_view itemRemoteId, int32_t newCount)
{
    get_activation_factory<SocialInfoProviderManager, ISocialInfoProviderManagerStatics>().UpdateBadgeCountValue(itemRemoteId, newCount);
}

inline void SocialInfoProviderManager::ReportNewContentAvailable(hstring_view contactRemoteId, Windows::ApplicationModel::SocialInfo::SocialFeedKind kind)
{
    get_activation_factory<SocialInfoProviderManager, ISocialInfoProviderManagerStatics>().ReportNewContentAvailable(contactRemoteId, kind);
}

inline Windows::Foundation::IAsyncOperation<bool> SocialInfoProviderManager::ProvisionAsync()
{
    return get_activation_factory<SocialInfoProviderManager, ISocialInfoProviderManagerStatics>().ProvisionAsync();
}

inline Windows::Foundation::IAsyncAction SocialInfoProviderManager::DeprovisionAsync()
{
    return get_activation_factory<SocialInfoProviderManager, ISocialInfoProviderManagerStatics>().DeprovisionAsync();
}

}

}
#pragma warning(pop)
