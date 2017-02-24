// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Graphics.Imaging.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.ApplicationModel.SocialInfo.3.h"
#include "Windows.ApplicationModel.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::SocialInfo::ISocialFeedChildItem> : produce_base<D, Windows::ApplicationModel::SocialInfo::ISocialFeedChildItem>
{
    HRESULT __stdcall get_Author(impl::abi_arg_out<Windows::ApplicationModel::SocialInfo::ISocialUserInfo> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Author());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PrimaryContent(impl::abi_arg_out<Windows::ApplicationModel::SocialInfo::ISocialFeedContent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PrimaryContent());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SecondaryContent(impl::abi_arg_out<Windows::ApplicationModel::SocialInfo::ISocialFeedContent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SecondaryContent());
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

    HRESULT __stdcall get_Thumbnails(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::SocialInfo::SocialItemThumbnail>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Thumbnails());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SharedItem(impl::abi_arg_out<Windows::ApplicationModel::SocialInfo::ISocialFeedSharedItem> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SharedItem());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SharedItem(impl::abi_arg_in<Windows::ApplicationModel::SocialInfo::ISocialFeedSharedItem> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SharedItem(*reinterpret_cast<const Windows::ApplicationModel::SocialInfo::SocialFeedSharedItem *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::SocialInfo::ISocialFeedContent> : produce_base<D, Windows::ApplicationModel::SocialInfo::ISocialFeedContent>
{
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

    HRESULT __stdcall put_Message(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Message(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
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
struct produce<D, Windows::ApplicationModel::SocialInfo::ISocialFeedItem> : produce_base<D, Windows::ApplicationModel::SocialInfo::ISocialFeedItem>
{
    HRESULT __stdcall get_Author(impl::abi_arg_out<Windows::ApplicationModel::SocialInfo::ISocialUserInfo> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Author());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PrimaryContent(impl::abi_arg_out<Windows::ApplicationModel::SocialInfo::ISocialFeedContent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PrimaryContent());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SecondaryContent(impl::abi_arg_out<Windows::ApplicationModel::SocialInfo::ISocialFeedContent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SecondaryContent());
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

    HRESULT __stdcall get_Thumbnails(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::SocialInfo::SocialItemThumbnail>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Thumbnails());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SharedItem(impl::abi_arg_out<Windows::ApplicationModel::SocialInfo::ISocialFeedSharedItem> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SharedItem());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SharedItem(impl::abi_arg_in<Windows::ApplicationModel::SocialInfo::ISocialFeedSharedItem> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SharedItem(*reinterpret_cast<const Windows::ApplicationModel::SocialInfo::SocialFeedSharedItem *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BadgeStyle(Windows::ApplicationModel::SocialInfo::SocialItemBadgeStyle * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BadgeStyle());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BadgeStyle(Windows::ApplicationModel::SocialInfo::SocialItemBadgeStyle value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BadgeStyle(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BadgeCountValue(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BadgeCountValue());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BadgeCountValue(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BadgeCountValue(value);
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

    HRESULT __stdcall get_ChildItem(impl::abi_arg_out<Windows::ApplicationModel::SocialInfo::ISocialFeedChildItem> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ChildItem());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ChildItem(impl::abi_arg_in<Windows::ApplicationModel::SocialInfo::ISocialFeedChildItem> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ChildItem(*reinterpret_cast<const Windows::ApplicationModel::SocialInfo::SocialFeedChildItem *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Style(Windows::ApplicationModel::SocialInfo::SocialFeedItemStyle * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Style());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Style(Windows::ApplicationModel::SocialInfo::SocialFeedItemStyle value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Style(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::SocialInfo::ISocialFeedSharedItem> : produce_base<D, Windows::ApplicationModel::SocialInfo::ISocialFeedSharedItem>
{
    HRESULT __stdcall get_OriginalSource(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OriginalSource());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OriginalSource(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OriginalSource(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
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
};

template <typename D>
struct produce<D, Windows::ApplicationModel::SocialInfo::ISocialItemThumbnail> : produce_base<D, Windows::ApplicationModel::SocialInfo::ISocialItemThumbnail>
{
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

    HRESULT __stdcall get_ImageUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ImageUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ImageUri(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ImageUri(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BitmapSize(impl::abi_arg_out<Windows::Graphics::Imaging::BitmapSize> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BitmapSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BitmapSize(impl::abi_arg_in<Windows::Graphics::Imaging::BitmapSize> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BitmapSize(*reinterpret_cast<const Windows::Graphics::Imaging::BitmapSize *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetImageAsync(impl::abi_arg_in<Windows::Storage::Streams::IInputStream> image, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().SetImageAsync(*reinterpret_cast<const Windows::Storage::Streams::IInputStream *>(&image)));
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
struct produce<D, Windows::ApplicationModel::SocialInfo::ISocialUserInfo> : produce_base<D, Windows::ApplicationModel::SocialInfo::ISocialUserInfo>
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

    HRESULT __stdcall put_UserName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UserName(*reinterpret_cast<const hstring *>(&value));
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

}

namespace Windows::ApplicationModel::SocialInfo {

template <typename D> Windows::Foundation::Uri impl_ISocialItemThumbnail<D>::TargetUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(ISocialItemThumbnail)->get_TargetUri(put_abi(value)));
    return value;
}

template <typename D> void impl_ISocialItemThumbnail<D>::TargetUri(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(ISocialItemThumbnail)->put_TargetUri(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_ISocialItemThumbnail<D>::ImageUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(ISocialItemThumbnail)->get_ImageUri(put_abi(value)));
    return value;
}

template <typename D> void impl_ISocialItemThumbnail<D>::ImageUri(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(ISocialItemThumbnail)->put_ImageUri(get_abi(value)));
}

template <typename D> Windows::Graphics::Imaging::BitmapSize impl_ISocialItemThumbnail<D>::BitmapSize() const
{
    Windows::Graphics::Imaging::BitmapSize value {};
    check_hresult(WINRT_SHIM(ISocialItemThumbnail)->get_BitmapSize(put_abi(value)));
    return value;
}

template <typename D> void impl_ISocialItemThumbnail<D>::BitmapSize(const Windows::Graphics::Imaging::BitmapSize & value) const
{
    check_hresult(WINRT_SHIM(ISocialItemThumbnail)->put_BitmapSize(get_abi(value)));
}

template <typename D> Windows::Foundation::IAsyncAction impl_ISocialItemThumbnail<D>::SetImageAsync(const Windows::Storage::Streams::IInputStream & image) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(ISocialItemThumbnail)->abi_SetImageAsync(get_abi(image), put_abi(operation)));
    return operation;
}

template <typename D> hstring impl_ISocialFeedContent<D>::Title() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISocialFeedContent)->get_Title(put_abi(value)));
    return value;
}

template <typename D> void impl_ISocialFeedContent<D>::Title(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISocialFeedContent)->put_Title(get_abi(value)));
}

template <typename D> hstring impl_ISocialFeedContent<D>::Message() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISocialFeedContent)->get_Message(put_abi(value)));
    return value;
}

template <typename D> void impl_ISocialFeedContent<D>::Message(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISocialFeedContent)->put_Message(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_ISocialFeedContent<D>::TargetUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(ISocialFeedContent)->get_TargetUri(put_abi(value)));
    return value;
}

template <typename D> void impl_ISocialFeedContent<D>::TargetUri(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(ISocialFeedContent)->put_TargetUri(get_abi(value)));
}

template <typename D> hstring impl_ISocialUserInfo<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISocialUserInfo)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> void impl_ISocialUserInfo<D>::DisplayName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISocialUserInfo)->put_DisplayName(get_abi(value)));
}

template <typename D> hstring impl_ISocialUserInfo<D>::UserName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISocialUserInfo)->get_UserName(put_abi(value)));
    return value;
}

template <typename D> void impl_ISocialUserInfo<D>::UserName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISocialUserInfo)->put_UserName(get_abi(value)));
}

template <typename D> hstring impl_ISocialUserInfo<D>::RemoteId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISocialUserInfo)->get_RemoteId(put_abi(value)));
    return value;
}

template <typename D> void impl_ISocialUserInfo<D>::RemoteId(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISocialUserInfo)->put_RemoteId(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_ISocialUserInfo<D>::TargetUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(ISocialUserInfo)->get_TargetUri(put_abi(value)));
    return value;
}

template <typename D> void impl_ISocialUserInfo<D>::TargetUri(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(ISocialUserInfo)->put_TargetUri(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::SocialInfo::SocialUserInfo impl_ISocialFeedItem<D>::Author() const
{
    Windows::ApplicationModel::SocialInfo::SocialUserInfo value { nullptr };
    check_hresult(WINRT_SHIM(ISocialFeedItem)->get_Author(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::SocialInfo::SocialFeedContent impl_ISocialFeedItem<D>::PrimaryContent() const
{
    Windows::ApplicationModel::SocialInfo::SocialFeedContent value { nullptr };
    check_hresult(WINRT_SHIM(ISocialFeedItem)->get_PrimaryContent(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::SocialInfo::SocialFeedContent impl_ISocialFeedItem<D>::SecondaryContent() const
{
    Windows::ApplicationModel::SocialInfo::SocialFeedContent value { nullptr };
    check_hresult(WINRT_SHIM(ISocialFeedItem)->get_SecondaryContent(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_ISocialFeedItem<D>::Timestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(ISocialFeedItem)->get_Timestamp(put_abi(value)));
    return value;
}

template <typename D> void impl_ISocialFeedItem<D>::Timestamp(const Windows::Foundation::DateTime & value) const
{
    check_hresult(WINRT_SHIM(ISocialFeedItem)->put_Timestamp(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_ISocialFeedItem<D>::TargetUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(ISocialFeedItem)->get_TargetUri(put_abi(value)));
    return value;
}

template <typename D> void impl_ISocialFeedItem<D>::TargetUri(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(ISocialFeedItem)->put_TargetUri(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::ApplicationModel::SocialInfo::SocialItemThumbnail> impl_ISocialFeedItem<D>::Thumbnails() const
{
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::SocialInfo::SocialItemThumbnail> value;
    check_hresult(WINRT_SHIM(ISocialFeedItem)->get_Thumbnails(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::SocialInfo::SocialFeedSharedItem impl_ISocialFeedItem<D>::SharedItem() const
{
    Windows::ApplicationModel::SocialInfo::SocialFeedSharedItem value { nullptr };
    check_hresult(WINRT_SHIM(ISocialFeedItem)->get_SharedItem(put_abi(value)));
    return value;
}

template <typename D> void impl_ISocialFeedItem<D>::SharedItem(const Windows::ApplicationModel::SocialInfo::SocialFeedSharedItem & value) const
{
    check_hresult(WINRT_SHIM(ISocialFeedItem)->put_SharedItem(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::SocialInfo::SocialItemBadgeStyle impl_ISocialFeedItem<D>::BadgeStyle() const
{
    Windows::ApplicationModel::SocialInfo::SocialItemBadgeStyle value {};
    check_hresult(WINRT_SHIM(ISocialFeedItem)->get_BadgeStyle(&value));
    return value;
}

template <typename D> void impl_ISocialFeedItem<D>::BadgeStyle(Windows::ApplicationModel::SocialInfo::SocialItemBadgeStyle value) const
{
    check_hresult(WINRT_SHIM(ISocialFeedItem)->put_BadgeStyle(value));
}

template <typename D> int32_t impl_ISocialFeedItem<D>::BadgeCountValue() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ISocialFeedItem)->get_BadgeCountValue(&value));
    return value;
}

template <typename D> void impl_ISocialFeedItem<D>::BadgeCountValue(int32_t value) const
{
    check_hresult(WINRT_SHIM(ISocialFeedItem)->put_BadgeCountValue(value));
}

template <typename D> hstring impl_ISocialFeedItem<D>::RemoteId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISocialFeedItem)->get_RemoteId(put_abi(value)));
    return value;
}

template <typename D> void impl_ISocialFeedItem<D>::RemoteId(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISocialFeedItem)->put_RemoteId(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::SocialInfo::SocialFeedChildItem impl_ISocialFeedItem<D>::ChildItem() const
{
    Windows::ApplicationModel::SocialInfo::SocialFeedChildItem value { nullptr };
    check_hresult(WINRT_SHIM(ISocialFeedItem)->get_ChildItem(put_abi(value)));
    return value;
}

template <typename D> void impl_ISocialFeedItem<D>::ChildItem(const Windows::ApplicationModel::SocialInfo::SocialFeedChildItem & value) const
{
    check_hresult(WINRT_SHIM(ISocialFeedItem)->put_ChildItem(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::SocialInfo::SocialFeedItemStyle impl_ISocialFeedItem<D>::Style() const
{
    Windows::ApplicationModel::SocialInfo::SocialFeedItemStyle value {};
    check_hresult(WINRT_SHIM(ISocialFeedItem)->get_Style(&value));
    return value;
}

template <typename D> void impl_ISocialFeedItem<D>::Style(Windows::ApplicationModel::SocialInfo::SocialFeedItemStyle value) const
{
    check_hresult(WINRT_SHIM(ISocialFeedItem)->put_Style(value));
}

template <typename D> Windows::ApplicationModel::SocialInfo::SocialUserInfo impl_ISocialFeedChildItem<D>::Author() const
{
    Windows::ApplicationModel::SocialInfo::SocialUserInfo value { nullptr };
    check_hresult(WINRT_SHIM(ISocialFeedChildItem)->get_Author(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::SocialInfo::SocialFeedContent impl_ISocialFeedChildItem<D>::PrimaryContent() const
{
    Windows::ApplicationModel::SocialInfo::SocialFeedContent value { nullptr };
    check_hresult(WINRT_SHIM(ISocialFeedChildItem)->get_PrimaryContent(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::SocialInfo::SocialFeedContent impl_ISocialFeedChildItem<D>::SecondaryContent() const
{
    Windows::ApplicationModel::SocialInfo::SocialFeedContent value { nullptr };
    check_hresult(WINRT_SHIM(ISocialFeedChildItem)->get_SecondaryContent(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_ISocialFeedChildItem<D>::Timestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(ISocialFeedChildItem)->get_Timestamp(put_abi(value)));
    return value;
}

template <typename D> void impl_ISocialFeedChildItem<D>::Timestamp(const Windows::Foundation::DateTime & value) const
{
    check_hresult(WINRT_SHIM(ISocialFeedChildItem)->put_Timestamp(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_ISocialFeedChildItem<D>::TargetUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(ISocialFeedChildItem)->get_TargetUri(put_abi(value)));
    return value;
}

template <typename D> void impl_ISocialFeedChildItem<D>::TargetUri(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(ISocialFeedChildItem)->put_TargetUri(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::ApplicationModel::SocialInfo::SocialItemThumbnail> impl_ISocialFeedChildItem<D>::Thumbnails() const
{
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::SocialInfo::SocialItemThumbnail> value;
    check_hresult(WINRT_SHIM(ISocialFeedChildItem)->get_Thumbnails(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::SocialInfo::SocialFeedSharedItem impl_ISocialFeedChildItem<D>::SharedItem() const
{
    Windows::ApplicationModel::SocialInfo::SocialFeedSharedItem value { nullptr };
    check_hresult(WINRT_SHIM(ISocialFeedChildItem)->get_SharedItem(put_abi(value)));
    return value;
}

template <typename D> void impl_ISocialFeedChildItem<D>::SharedItem(const Windows::ApplicationModel::SocialInfo::SocialFeedSharedItem & value) const
{
    check_hresult(WINRT_SHIM(ISocialFeedChildItem)->put_SharedItem(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_ISocialFeedSharedItem<D>::OriginalSource() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(ISocialFeedSharedItem)->get_OriginalSource(put_abi(value)));
    return value;
}

template <typename D> void impl_ISocialFeedSharedItem<D>::OriginalSource(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(ISocialFeedSharedItem)->put_OriginalSource(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::SocialInfo::SocialFeedContent impl_ISocialFeedSharedItem<D>::Content() const
{
    Windows::ApplicationModel::SocialInfo::SocialFeedContent value { nullptr };
    check_hresult(WINRT_SHIM(ISocialFeedSharedItem)->get_Content(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_ISocialFeedSharedItem<D>::Timestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(ISocialFeedSharedItem)->get_Timestamp(put_abi(value)));
    return value;
}

template <typename D> void impl_ISocialFeedSharedItem<D>::Timestamp(const Windows::Foundation::DateTime & value) const
{
    check_hresult(WINRT_SHIM(ISocialFeedSharedItem)->put_Timestamp(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_ISocialFeedSharedItem<D>::TargetUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(ISocialFeedSharedItem)->get_TargetUri(put_abi(value)));
    return value;
}

template <typename D> void impl_ISocialFeedSharedItem<D>::TargetUri(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(ISocialFeedSharedItem)->put_TargetUri(get_abi(value)));
}

template <typename D> void impl_ISocialFeedSharedItem<D>::Thumbnail(const Windows::ApplicationModel::SocialInfo::SocialItemThumbnail & value) const
{
    check_hresult(WINRT_SHIM(ISocialFeedSharedItem)->put_Thumbnail(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::SocialInfo::SocialItemThumbnail impl_ISocialFeedSharedItem<D>::Thumbnail() const
{
    Windows::ApplicationModel::SocialInfo::SocialItemThumbnail value { nullptr };
    check_hresult(WINRT_SHIM(ISocialFeedSharedItem)->get_Thumbnail(put_abi(value)));
    return value;
}

inline SocialFeedChildItem::SocialFeedChildItem() :
    SocialFeedChildItem(activate_instance<SocialFeedChildItem>())
{}

inline SocialFeedItem::SocialFeedItem() :
    SocialFeedItem(activate_instance<SocialFeedItem>())
{}

inline SocialFeedSharedItem::SocialFeedSharedItem() :
    SocialFeedSharedItem(activate_instance<SocialFeedSharedItem>())
{}

inline SocialItemThumbnail::SocialItemThumbnail() :
    SocialItemThumbnail(activate_instance<SocialItemThumbnail>())
{}

}

}
#pragma warning(pop)
