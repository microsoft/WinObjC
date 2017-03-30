// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Gaming.Preview.GamesEnumeration.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Gaming::Preview::GamesEnumeration {

template <typename H> struct impl_GameListChangedEventHandler : implements<impl_GameListChangedEventHandler<H>, abi<GameListChangedEventHandler>>, H
{
    impl_GameListChangedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Gaming::Preview::GamesEnumeration::IGameListEntry> game) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Gaming::Preview::GamesEnumeration::GameListEntry *>(&game));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_GameListRemovedEventHandler : implements<impl_GameListRemovedEventHandler<H>, abi<GameListRemovedEventHandler>>, H
{
    impl_GameListRemovedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<hstring> identifier) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const hstring *>(&identifier));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Gaming::Preview::GamesEnumeration {

struct GameList
{
    GameList() = delete;
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Gaming::Preview::GamesEnumeration::GameListEntry>> FindAllAsync();
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Gaming::Preview::GamesEnumeration::GameListEntry>> FindAllAsync(hstring_view packageFamilyName);
    static event_token GameAdded(const Windows::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler & handler);
    using GameAdded_revoker = factory_event_revoker<IGameListStatics>;
    static GameAdded_revoker GameAdded(auto_revoke_t, const Windows::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler & handler);
    static void GameAdded(event_token token);
    static event_token GameRemoved(const Windows::Gaming::Preview::GamesEnumeration::GameListRemovedEventHandler & handler);
    using GameRemoved_revoker = factory_event_revoker<IGameListStatics>;
    static GameRemoved_revoker GameRemoved(auto_revoke_t, const Windows::Gaming::Preview::GamesEnumeration::GameListRemovedEventHandler & handler);
    static void GameRemoved(event_token token);
    static event_token GameUpdated(const Windows::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler & handler);
    using GameUpdated_revoker = factory_event_revoker<IGameListStatics>;
    static GameUpdated_revoker GameUpdated(auto_revoke_t, const Windows::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler & handler);
    static void GameUpdated(event_token token);
};

struct WINRT_EBO GameListEntry :
    Windows::Gaming::Preview::GamesEnumeration::IGameListEntry
{
    GameListEntry(std::nullptr_t) noexcept {}
};

}

}
