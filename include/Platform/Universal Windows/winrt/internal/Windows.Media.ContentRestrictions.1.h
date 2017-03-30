// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Media.ContentRestrictions.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::ContentRestrictions {

struct __declspec(uuid("8c0133a4-442e-461a-8757-fad2f5bd37e4")) __declspec(novtable) IContentRestrictionsBrowsePolicy : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_GeographicRegion(hstring * value) = 0;
    virtual HRESULT __stdcall get_MaxBrowsableAgeRating(Windows::Foundation::IReference<uint32_t> ** value) = 0;
    virtual HRESULT __stdcall get_PreferredAgeRating(Windows::Foundation::IReference<uint32_t> ** value) = 0;
};

struct __declspec(uuid("694866df-66b2-4dc3-96b1-f090eedee255")) __declspec(novtable) IRatedContentDescription : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall put_Id(hstring value) = 0;
    virtual HRESULT __stdcall get_Title(hstring * value) = 0;
    virtual HRESULT __stdcall put_Title(hstring value) = 0;
    virtual HRESULT __stdcall get_Image(Windows::Storage::Streams::IRandomAccessStreamReference ** value) = 0;
    virtual HRESULT __stdcall put_Image(Windows::Storage::Streams::IRandomAccessStreamReference * value) = 0;
    virtual HRESULT __stdcall get_Category(winrt::Windows::Media::ContentRestrictions::RatedContentCategory * value) = 0;
    virtual HRESULT __stdcall put_Category(winrt::Windows::Media::ContentRestrictions::RatedContentCategory value) = 0;
    virtual HRESULT __stdcall get_Ratings(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall put_Ratings(Windows::Foundation::Collections::IVector<hstring> * value) = 0;
};

struct __declspec(uuid("2e38df62-9b90-4fa6-89c1-4b8d2ffb3573")) __declspec(novtable) IRatedContentDescriptionFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(hstring id, hstring title, winrt::Windows::Media::ContentRestrictions::RatedContentCategory category, Windows::Media::ContentRestrictions::IRatedContentDescription ** RatedContentDescription) = 0;
};

struct __declspec(uuid("3f7f23cb-ba07-4401-a49d-8b9222205723")) __declspec(novtable) IRatedContentRestrictions : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetBrowsePolicyAsync(Windows::Foundation::IAsyncOperation<Windows::Media::ContentRestrictions::ContentRestrictionsBrowsePolicy> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetRestrictionLevelAsync(Windows::Media::ContentRestrictions::IRatedContentDescription * RatedContentDescription, Windows::Foundation::IAsyncOperation<winrt::Windows::Media::ContentRestrictions::ContentAccessRestrictionLevel> ** operation) = 0;
    virtual HRESULT __stdcall abi_RequestContentAccessAsync(Windows::Media::ContentRestrictions::IRatedContentDescription * RatedContentDescription, Windows::Foundation::IAsyncOperation<bool> ** operation) = 0;
    virtual HRESULT __stdcall add_RestrictionsChanged(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_RestrictionsChanged(event_token token) = 0;
};

struct __declspec(uuid("fb4b2996-c3bd-4910-9619-97cfd0694d56")) __declspec(novtable) IRatedContentRestrictionsFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateWithMaxAgeRating(uint32_t maxAgeRating, Windows::Media::ContentRestrictions::IRatedContentRestrictions ** ratedContentRestrictions) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Media::ContentRestrictions::ContentRestrictionsBrowsePolicy> { using default_interface = Windows::Media::ContentRestrictions::IContentRestrictionsBrowsePolicy; };
template <> struct traits<Windows::Media::ContentRestrictions::RatedContentDescription> { using default_interface = Windows::Media::ContentRestrictions::IRatedContentDescription; };
template <> struct traits<Windows::Media::ContentRestrictions::RatedContentRestrictions> { using default_interface = Windows::Media::ContentRestrictions::IRatedContentRestrictions; };

}

namespace Windows::Media::ContentRestrictions {

template <typename D>
struct WINRT_EBO impl_IContentRestrictionsBrowsePolicy
{
    hstring GeographicRegion() const;
    Windows::Foundation::IReference<uint32_t> MaxBrowsableAgeRating() const;
    Windows::Foundation::IReference<uint32_t> PreferredAgeRating() const;
};

template <typename D>
struct WINRT_EBO impl_IRatedContentDescription
{
    hstring Id() const;
    void Id(hstring_view value) const;
    hstring Title() const;
    void Title(hstring_view value) const;
    Windows::Storage::Streams::IRandomAccessStreamReference Image() const;
    void Image(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const;
    Windows::Media::ContentRestrictions::RatedContentCategory Category() const;
    void Category(Windows::Media::ContentRestrictions::RatedContentCategory value) const;
    Windows::Foundation::Collections::IVector<hstring> Ratings() const;
    void Ratings(const Windows::Foundation::Collections::IVector<hstring> & value) const;
};

template <typename D>
struct WINRT_EBO impl_IRatedContentDescriptionFactory
{
    Windows::Media::ContentRestrictions::RatedContentDescription Create(hstring_view id, hstring_view title, Windows::Media::ContentRestrictions::RatedContentCategory category) const;
};

template <typename D>
struct WINRT_EBO impl_IRatedContentRestrictions
{
    Windows::Foundation::IAsyncOperation<Windows::Media::ContentRestrictions::ContentRestrictionsBrowsePolicy> GetBrowsePolicyAsync() const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Media::ContentRestrictions::ContentAccessRestrictionLevel> GetRestrictionLevelAsync(const Windows::Media::ContentRestrictions::RatedContentDescription & RatedContentDescription) const;
    Windows::Foundation::IAsyncOperation<bool> RequestContentAccessAsync(const Windows::Media::ContentRestrictions::RatedContentDescription & RatedContentDescription) const;
    event_token RestrictionsChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const;
    using RestrictionsChanged_revoker = event_revoker<IRatedContentRestrictions>;
    RestrictionsChanged_revoker RestrictionsChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const;
    void RestrictionsChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IRatedContentRestrictionsFactory
{
    Windows::Media::ContentRestrictions::RatedContentRestrictions CreateWithMaxAgeRating(uint32_t maxAgeRating) const;
};

}

namespace impl {

template <> struct traits<Windows::Media::ContentRestrictions::IContentRestrictionsBrowsePolicy>
{
    using abi = ABI::Windows::Media::ContentRestrictions::IContentRestrictionsBrowsePolicy;
    template <typename D> using consume = Windows::Media::ContentRestrictions::impl_IContentRestrictionsBrowsePolicy<D>;
};

template <> struct traits<Windows::Media::ContentRestrictions::IRatedContentDescription>
{
    using abi = ABI::Windows::Media::ContentRestrictions::IRatedContentDescription;
    template <typename D> using consume = Windows::Media::ContentRestrictions::impl_IRatedContentDescription<D>;
};

template <> struct traits<Windows::Media::ContentRestrictions::IRatedContentDescriptionFactory>
{
    using abi = ABI::Windows::Media::ContentRestrictions::IRatedContentDescriptionFactory;
    template <typename D> using consume = Windows::Media::ContentRestrictions::impl_IRatedContentDescriptionFactory<D>;
};

template <> struct traits<Windows::Media::ContentRestrictions::IRatedContentRestrictions>
{
    using abi = ABI::Windows::Media::ContentRestrictions::IRatedContentRestrictions;
    template <typename D> using consume = Windows::Media::ContentRestrictions::impl_IRatedContentRestrictions<D>;
};

template <> struct traits<Windows::Media::ContentRestrictions::IRatedContentRestrictionsFactory>
{
    using abi = ABI::Windows::Media::ContentRestrictions::IRatedContentRestrictionsFactory;
    template <typename D> using consume = Windows::Media::ContentRestrictions::impl_IRatedContentRestrictionsFactory<D>;
};

template <> struct traits<Windows::Media::ContentRestrictions::ContentRestrictionsBrowsePolicy>
{
    using abi = ABI::Windows::Media::ContentRestrictions::ContentRestrictionsBrowsePolicy;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.ContentRestrictions.ContentRestrictionsBrowsePolicy"; }
};

template <> struct traits<Windows::Media::ContentRestrictions::RatedContentDescription>
{
    using abi = ABI::Windows::Media::ContentRestrictions::RatedContentDescription;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.ContentRestrictions.RatedContentDescription"; }
};

template <> struct traits<Windows::Media::ContentRestrictions::RatedContentRestrictions>
{
    using abi = ABI::Windows::Media::ContentRestrictions::RatedContentRestrictions;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.ContentRestrictions.RatedContentRestrictions"; }
};

}

}
