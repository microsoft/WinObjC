// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Gaming.Preview.GamesEnumeration.0.h"
#include "Windows.ApplicationModel.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Gaming::Preview::GamesEnumeration {

struct __declspec(uuid("25f6a421-d8f5-4d91-b40e-53d5e86fde64")) __declspec(novtable) GameListChangedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Gaming::Preview::GamesEnumeration::IGameListEntry * game) = 0;
};

struct __declspec(uuid("10c5648f-6c8f-4712-9b38-474bc22e76d8")) __declspec(novtable) GameListRemovedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(hstring identifier) = 0;
};

struct __declspec(uuid("735924d3-811f-4494-b69c-c641a0c61543")) __declspec(novtable) IGameListEntry : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DisplayInfo(Windows::ApplicationModel::IAppDisplayInfo ** value) = 0;
    virtual HRESULT __stdcall abi_LaunchAsync(Windows::Foundation::IAsyncOperation<bool> ** operation) = 0;
    virtual HRESULT __stdcall get_Category(winrt::Windows::Gaming::Preview::GamesEnumeration::GameListCategory * value) = 0;
    virtual HRESULT __stdcall get_Properties(Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> ** value) = 0;
    virtual HRESULT __stdcall abi_SetCategoryAsync(winrt::Windows::Gaming::Preview::GamesEnumeration::GameListCategory value, Windows::Foundation::IAsyncAction ** action) = 0;
};

struct __declspec(uuid("2ddd0f6f-9c66-4b05-945c-d6ed78491b8c")) __declspec(novtable) IGameListStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FindAllAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Gaming::Preview::GamesEnumeration::GameListEntry>> ** operation) = 0;
    virtual HRESULT __stdcall abi_FindAllAsyncPackageFamilyName(hstring packageFamilyName, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Gaming::Preview::GamesEnumeration::GameListEntry>> ** operation) = 0;
    virtual HRESULT __stdcall add_GameAdded(Windows::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_GameAdded(event_token token) = 0;
    virtual HRESULT __stdcall add_GameRemoved(Windows::Gaming::Preview::GamesEnumeration::GameListRemovedEventHandler * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_GameRemoved(event_token token) = 0;
    virtual HRESULT __stdcall add_GameUpdated(Windows::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_GameUpdated(event_token token) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Gaming::Preview::GamesEnumeration::GameListEntry> { using default_interface = Windows::Gaming::Preview::GamesEnumeration::IGameListEntry; };

}

namespace Windows::Gaming::Preview::GamesEnumeration {

template <typename D>
struct WINRT_EBO impl_IGameListEntry
{
    Windows::ApplicationModel::AppDisplayInfo DisplayInfo() const;
    Windows::Foundation::IAsyncOperation<bool> LaunchAsync() const;
    Windows::Gaming::Preview::GamesEnumeration::GameListCategory Category() const;
    Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> Properties() const;
    Windows::Foundation::IAsyncAction SetCategoryAsync(Windows::Gaming::Preview::GamesEnumeration::GameListCategory value) const;
};

template <typename D>
struct WINRT_EBO impl_IGameListStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Gaming::Preview::GamesEnumeration::GameListEntry>> FindAllAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Gaming::Preview::GamesEnumeration::GameListEntry>> FindAllAsync(hstring_view packageFamilyName) const;
    event_token GameAdded(const Windows::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler & handler) const;
    using GameAdded_revoker = event_revoker<IGameListStatics>;
    GameAdded_revoker GameAdded(auto_revoke_t, const Windows::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler & handler) const;
    void GameAdded(event_token token) const;
    event_token GameRemoved(const Windows::Gaming::Preview::GamesEnumeration::GameListRemovedEventHandler & handler) const;
    using GameRemoved_revoker = event_revoker<IGameListStatics>;
    GameRemoved_revoker GameRemoved(auto_revoke_t, const Windows::Gaming::Preview::GamesEnumeration::GameListRemovedEventHandler & handler) const;
    void GameRemoved(event_token token) const;
    event_token GameUpdated(const Windows::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler & handler) const;
    using GameUpdated_revoker = event_revoker<IGameListStatics>;
    GameUpdated_revoker GameUpdated(auto_revoke_t, const Windows::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler & handler) const;
    void GameUpdated(event_token token) const;
};

}

namespace impl {

template <> struct traits<Windows::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler>
{
    using abi = ABI::Windows::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler;
};

template <> struct traits<Windows::Gaming::Preview::GamesEnumeration::GameListRemovedEventHandler>
{
    using abi = ABI::Windows::Gaming::Preview::GamesEnumeration::GameListRemovedEventHandler;
};

template <> struct traits<Windows::Gaming::Preview::GamesEnumeration::IGameListEntry>
{
    using abi = ABI::Windows::Gaming::Preview::GamesEnumeration::IGameListEntry;
    template <typename D> using consume = Windows::Gaming::Preview::GamesEnumeration::impl_IGameListEntry<D>;
};

template <> struct traits<Windows::Gaming::Preview::GamesEnumeration::IGameListStatics>
{
    using abi = ABI::Windows::Gaming::Preview::GamesEnumeration::IGameListStatics;
    template <typename D> using consume = Windows::Gaming::Preview::GamesEnumeration::impl_IGameListStatics<D>;
};

template <> struct traits<Windows::Gaming::Preview::GamesEnumeration::GameList>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Gaming.Preview.GamesEnumeration.GameList"; }
};

template <> struct traits<Windows::Gaming::Preview::GamesEnumeration::GameListEntry>
{
    using abi = ABI::Windows::Gaming::Preview::GamesEnumeration::GameListEntry;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Gaming.Preview.GamesEnumeration.GameListEntry"; }
};

}

}
