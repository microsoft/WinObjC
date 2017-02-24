// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.ApplicationModel.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Gaming.Preview.GamesEnumeration.3.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Gaming::Preview::GamesEnumeration {

template <typename L> GameListChangedEventHandler::GameListChangedEventHandler(L lambda) :
    GameListChangedEventHandler(impl::make_delegate<impl_GameListChangedEventHandler<L>, GameListChangedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> GameListChangedEventHandler::GameListChangedEventHandler(F * function) :
    GameListChangedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> GameListChangedEventHandler::GameListChangedEventHandler(O * object, M method) :
    GameListChangedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void GameListChangedEventHandler::operator()(const Windows::Gaming::Preview::GamesEnumeration::GameListEntry & game) const
{
    check_hresult((*(abi<GameListChangedEventHandler> **)this)->abi_Invoke(get_abi(game)));
}

template <typename L> GameListRemovedEventHandler::GameListRemovedEventHandler(L lambda) :
    GameListRemovedEventHandler(impl::make_delegate<impl_GameListRemovedEventHandler<L>, GameListRemovedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> GameListRemovedEventHandler::GameListRemovedEventHandler(F * function) :
    GameListRemovedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> GameListRemovedEventHandler::GameListRemovedEventHandler(O * object, M method) :
    GameListRemovedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void GameListRemovedEventHandler::operator()(hstring_view identifier) const
{
    check_hresult((*(abi<GameListRemovedEventHandler> **)this)->abi_Invoke(get_abi(identifier)));
}

}

namespace impl {

template <typename D>
struct produce<D, Windows::Gaming::Preview::GamesEnumeration::IGameListEntry> : produce_base<D, Windows::Gaming::Preview::GamesEnumeration::IGameListEntry>
{
    HRESULT __stdcall get_DisplayInfo(impl::abi_arg_out<Windows::ApplicationModel::IAppDisplayInfo> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayInfo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LaunchAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().LaunchAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Category(Windows::Gaming::Preview::GamesEnumeration::GameListCategory * value) noexcept override
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

    HRESULT __stdcall get_Properties(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Properties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetCategoryAsync(Windows::Gaming::Preview::GamesEnumeration::GameListCategory value, impl::abi_arg_out<Windows::Foundation::IAsyncAction> action) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *action = detach_abi(this->shim().SetCategoryAsync(value));
            return S_OK;
        }
        catch (...)
        {
            *action = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Gaming::Preview::GamesEnumeration::IGameListStatics> : produce_base<D, Windows::Gaming::Preview::GamesEnumeration::IGameListStatics>
{
    HRESULT __stdcall abi_FindAllAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Gaming::Preview::GamesEnumeration::GameListEntry>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().FindAllAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAllAsyncPackageFamilyName(impl::abi_arg_in<hstring> packageFamilyName, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Gaming::Preview::GamesEnumeration::GameListEntry>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().FindAllAsync(*reinterpret_cast<const hstring *>(&packageFamilyName)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_GameAdded(impl::abi_arg_in<Windows::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().GameAdded(*reinterpret_cast<const Windows::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_GameAdded(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GameAdded(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_GameRemoved(impl::abi_arg_in<Windows::Gaming::Preview::GamesEnumeration::GameListRemovedEventHandler> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().GameRemoved(*reinterpret_cast<const Windows::Gaming::Preview::GamesEnumeration::GameListRemovedEventHandler *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_GameRemoved(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GameRemoved(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_GameUpdated(impl::abi_arg_in<Windows::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().GameUpdated(*reinterpret_cast<const Windows::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_GameUpdated(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GameUpdated(token);
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

template <typename D> Windows::ApplicationModel::AppDisplayInfo impl_IGameListEntry<D>::DisplayInfo() const
{
    Windows::ApplicationModel::AppDisplayInfo value { nullptr };
    check_hresult(WINRT_SHIM(IGameListEntry)->get_DisplayInfo(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IGameListEntry<D>::LaunchAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(IGameListEntry)->abi_LaunchAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Gaming::Preview::GamesEnumeration::GameListCategory impl_IGameListEntry<D>::Category() const
{
    Windows::Gaming::Preview::GamesEnumeration::GameListCategory value {};
    check_hresult(WINRT_SHIM(IGameListEntry)->get_Category(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> impl_IGameListEntry<D>::Properties() const
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> value;
    check_hresult(WINRT_SHIM(IGameListEntry)->get_Properties(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IGameListEntry<D>::SetCategoryAsync(Windows::Gaming::Preview::GamesEnumeration::GameListCategory value) const
{
    Windows::Foundation::IAsyncAction action;
    check_hresult(WINRT_SHIM(IGameListEntry)->abi_SetCategoryAsync(value, put_abi(action)));
    return action;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Gaming::Preview::GamesEnumeration::GameListEntry>> impl_IGameListStatics<D>::FindAllAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Gaming::Preview::GamesEnumeration::GameListEntry>> operation;
    check_hresult(WINRT_SHIM(IGameListStatics)->abi_FindAllAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Gaming::Preview::GamesEnumeration::GameListEntry>> impl_IGameListStatics<D>::FindAllAsync(hstring_view packageFamilyName) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Gaming::Preview::GamesEnumeration::GameListEntry>> operation;
    check_hresult(WINRT_SHIM(IGameListStatics)->abi_FindAllAsyncPackageFamilyName(get_abi(packageFamilyName), put_abi(operation)));
    return operation;
}

template <typename D> event_token impl_IGameListStatics<D>::GameAdded(const Windows::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IGameListStatics)->add_GameAdded(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IGameListStatics> impl_IGameListStatics<D>::GameAdded(auto_revoke_t, const Windows::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler & handler) const
{
    return impl::make_event_revoker<D, IGameListStatics>(this, &ABI::Windows::Gaming::Preview::GamesEnumeration::IGameListStatics::remove_GameAdded, GameAdded(handler));
}

template <typename D> void impl_IGameListStatics<D>::GameAdded(event_token token) const
{
    check_hresult(WINRT_SHIM(IGameListStatics)->remove_GameAdded(token));
}

template <typename D> event_token impl_IGameListStatics<D>::GameRemoved(const Windows::Gaming::Preview::GamesEnumeration::GameListRemovedEventHandler & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IGameListStatics)->add_GameRemoved(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IGameListStatics> impl_IGameListStatics<D>::GameRemoved(auto_revoke_t, const Windows::Gaming::Preview::GamesEnumeration::GameListRemovedEventHandler & handler) const
{
    return impl::make_event_revoker<D, IGameListStatics>(this, &ABI::Windows::Gaming::Preview::GamesEnumeration::IGameListStatics::remove_GameRemoved, GameRemoved(handler));
}

template <typename D> void impl_IGameListStatics<D>::GameRemoved(event_token token) const
{
    check_hresult(WINRT_SHIM(IGameListStatics)->remove_GameRemoved(token));
}

template <typename D> event_token impl_IGameListStatics<D>::GameUpdated(const Windows::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IGameListStatics)->add_GameUpdated(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IGameListStatics> impl_IGameListStatics<D>::GameUpdated(auto_revoke_t, const Windows::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler & handler) const
{
    return impl::make_event_revoker<D, IGameListStatics>(this, &ABI::Windows::Gaming::Preview::GamesEnumeration::IGameListStatics::remove_GameUpdated, GameUpdated(handler));
}

template <typename D> void impl_IGameListStatics<D>::GameUpdated(event_token token) const
{
    check_hresult(WINRT_SHIM(IGameListStatics)->remove_GameUpdated(token));
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Gaming::Preview::GamesEnumeration::GameListEntry>> GameList::FindAllAsync()
{
    return get_activation_factory<GameList, IGameListStatics>().FindAllAsync();
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Gaming::Preview::GamesEnumeration::GameListEntry>> GameList::FindAllAsync(hstring_view packageFamilyName)
{
    return get_activation_factory<GameList, IGameListStatics>().FindAllAsync(packageFamilyName);
}

inline event_token GameList::GameAdded(const Windows::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler & handler)
{
    return get_activation_factory<GameList, IGameListStatics>().GameAdded(handler);
}

inline factory_event_revoker<IGameListStatics> GameList::GameAdded(auto_revoke_t, const Windows::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler & handler)
{
    auto factory = get_activation_factory<GameList, IGameListStatics>();
    return { factory, &ABI::Windows::Gaming::Preview::GamesEnumeration::IGameListStatics::remove_GameAdded, factory.GameAdded(handler) };
}

inline void GameList::GameAdded(event_token token)
{
    get_activation_factory<GameList, IGameListStatics>().GameAdded(token);
}

inline event_token GameList::GameRemoved(const Windows::Gaming::Preview::GamesEnumeration::GameListRemovedEventHandler & handler)
{
    return get_activation_factory<GameList, IGameListStatics>().GameRemoved(handler);
}

inline factory_event_revoker<IGameListStatics> GameList::GameRemoved(auto_revoke_t, const Windows::Gaming::Preview::GamesEnumeration::GameListRemovedEventHandler & handler)
{
    auto factory = get_activation_factory<GameList, IGameListStatics>();
    return { factory, &ABI::Windows::Gaming::Preview::GamesEnumeration::IGameListStatics::remove_GameRemoved, factory.GameRemoved(handler) };
}

inline void GameList::GameRemoved(event_token token)
{
    get_activation_factory<GameList, IGameListStatics>().GameRemoved(token);
}

inline event_token GameList::GameUpdated(const Windows::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler & handler)
{
    return get_activation_factory<GameList, IGameListStatics>().GameUpdated(handler);
}

inline factory_event_revoker<IGameListStatics> GameList::GameUpdated(auto_revoke_t, const Windows::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler & handler)
{
    auto factory = get_activation_factory<GameList, IGameListStatics>();
    return { factory, &ABI::Windows::Gaming::Preview::GamesEnumeration::IGameListStatics::remove_GameUpdated, factory.GameUpdated(handler) };
}

inline void GameList::GameUpdated(event_token token)
{
    get_activation_factory<GameList, IGameListStatics>().GameUpdated(token);
}

}

}
#pragma warning(pop)
