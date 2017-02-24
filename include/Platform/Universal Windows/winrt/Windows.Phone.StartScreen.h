// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.UI.Notifications.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Phone.StartScreen.3.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Phone::StartScreen::IDualSimTile> : produce_base<D, Windows::Phone::StartScreen::IDualSimTile>
{
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

    HRESULT __stdcall get_IsPinnedToStart(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsPinnedToStart());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreateAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UpdateAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().UpdateAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().DeleteAsync());
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
struct produce<D, Windows::Phone::StartScreen::IDualSimTileStatics> : produce_base<D, Windows::Phone::StartScreen::IDualSimTileStatics>
{
    HRESULT __stdcall abi_GetTileForSim2(impl::abi_arg_out<Windows::Phone::StartScreen::IDualSimTile> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetTileForSim2());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UpdateDisplayNameForSim1Async(impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().UpdateDisplayNameForSim1Async(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateTileUpdaterForSim1(impl::abi_arg_out<Windows::UI::Notifications::ITileUpdater> updater) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *updater = detach_abi(this->shim().CreateTileUpdaterForSim1());
            return S_OK;
        }
        catch (...)
        {
            *updater = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateTileUpdaterForSim2(impl::abi_arg_out<Windows::UI::Notifications::ITileUpdater> updater) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *updater = detach_abi(this->shim().CreateTileUpdaterForSim2());
            return S_OK;
        }
        catch (...)
        {
            *updater = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateBadgeUpdaterForSim1(impl::abi_arg_out<Windows::UI::Notifications::IBadgeUpdater> updater) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *updater = detach_abi(this->shim().CreateBadgeUpdaterForSim1());
            return S_OK;
        }
        catch (...)
        {
            *updater = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateBadgeUpdaterForSim2(impl::abi_arg_out<Windows::UI::Notifications::IBadgeUpdater> updater) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *updater = detach_abi(this->shim().CreateBadgeUpdaterForSim2());
            return S_OK;
        }
        catch (...)
        {
            *updater = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateToastNotifierForSim1(impl::abi_arg_out<Windows::UI::Notifications::IToastNotifier> notifier) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *notifier = detach_abi(this->shim().CreateToastNotifierForSim1());
            return S_OK;
        }
        catch (...)
        {
            *notifier = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateToastNotifierForSim2(impl::abi_arg_out<Windows::UI::Notifications::IToastNotifier> notifier) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *notifier = detach_abi(this->shim().CreateToastNotifierForSim2());
            return S_OK;
        }
        catch (...)
        {
            *notifier = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Phone::StartScreen::IToastNotificationManagerStatics3> : produce_base<D, Windows::Phone::StartScreen::IToastNotificationManagerStatics3>
{
    HRESULT __stdcall abi_CreateToastNotifierForSecondaryTile(impl::abi_arg_in<hstring> tileId, impl::abi_arg_out<Windows::UI::Notifications::IToastNotifier> notifier) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *notifier = detach_abi(this->shim().CreateToastNotifierForSecondaryTile(*reinterpret_cast<const hstring *>(&tileId)));
            return S_OK;
        }
        catch (...)
        {
            *notifier = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Phone::StartScreen {

template <typename D> Windows::UI::Notifications::ToastNotifier impl_IToastNotificationManagerStatics3<D>::CreateToastNotifierForSecondaryTile(hstring_view tileId) const
{
    Windows::UI::Notifications::ToastNotifier notifier { nullptr };
    check_hresult(WINRT_SHIM(IToastNotificationManagerStatics3)->abi_CreateToastNotifierForSecondaryTile(get_abi(tileId), put_abi(notifier)));
    return notifier;
}

template <typename D> void impl_IDualSimTile<D>::DisplayName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IDualSimTile)->put_DisplayName(get_abi(value)));
}

template <typename D> hstring impl_IDualSimTile<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDualSimTile)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> bool impl_IDualSimTile<D>::IsPinnedToStart() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDualSimTile)->get_IsPinnedToStart(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IDualSimTile<D>::CreateAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(IDualSimTile)->abi_CreateAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IDualSimTile<D>::UpdateAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(IDualSimTile)->abi_UpdateAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IDualSimTile<D>::DeleteAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(IDualSimTile)->abi_DeleteAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Phone::StartScreen::DualSimTile impl_IDualSimTileStatics<D>::GetTileForSim2() const
{
    Windows::Phone::StartScreen::DualSimTile result { nullptr };
    check_hresult(WINRT_SHIM(IDualSimTileStatics)->abi_GetTileForSim2(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IDualSimTileStatics<D>::UpdateDisplayNameForSim1Async(hstring_view name) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(IDualSimTileStatics)->abi_UpdateDisplayNameForSim1Async(get_abi(name), put_abi(operation)));
    return operation;
}

template <typename D> Windows::UI::Notifications::TileUpdater impl_IDualSimTileStatics<D>::CreateTileUpdaterForSim1() const
{
    Windows::UI::Notifications::TileUpdater updater { nullptr };
    check_hresult(WINRT_SHIM(IDualSimTileStatics)->abi_CreateTileUpdaterForSim1(put_abi(updater)));
    return updater;
}

template <typename D> Windows::UI::Notifications::TileUpdater impl_IDualSimTileStatics<D>::CreateTileUpdaterForSim2() const
{
    Windows::UI::Notifications::TileUpdater updater { nullptr };
    check_hresult(WINRT_SHIM(IDualSimTileStatics)->abi_CreateTileUpdaterForSim2(put_abi(updater)));
    return updater;
}

template <typename D> Windows::UI::Notifications::BadgeUpdater impl_IDualSimTileStatics<D>::CreateBadgeUpdaterForSim1() const
{
    Windows::UI::Notifications::BadgeUpdater updater { nullptr };
    check_hresult(WINRT_SHIM(IDualSimTileStatics)->abi_CreateBadgeUpdaterForSim1(put_abi(updater)));
    return updater;
}

template <typename D> Windows::UI::Notifications::BadgeUpdater impl_IDualSimTileStatics<D>::CreateBadgeUpdaterForSim2() const
{
    Windows::UI::Notifications::BadgeUpdater updater { nullptr };
    check_hresult(WINRT_SHIM(IDualSimTileStatics)->abi_CreateBadgeUpdaterForSim2(put_abi(updater)));
    return updater;
}

template <typename D> Windows::UI::Notifications::ToastNotifier impl_IDualSimTileStatics<D>::CreateToastNotifierForSim1() const
{
    Windows::UI::Notifications::ToastNotifier notifier { nullptr };
    check_hresult(WINRT_SHIM(IDualSimTileStatics)->abi_CreateToastNotifierForSim1(put_abi(notifier)));
    return notifier;
}

template <typename D> Windows::UI::Notifications::ToastNotifier impl_IDualSimTileStatics<D>::CreateToastNotifierForSim2() const
{
    Windows::UI::Notifications::ToastNotifier notifier { nullptr };
    check_hresult(WINRT_SHIM(IDualSimTileStatics)->abi_CreateToastNotifierForSim2(put_abi(notifier)));
    return notifier;
}

inline DualSimTile::DualSimTile() :
    DualSimTile(activate_instance<DualSimTile>())
{}

inline Windows::Phone::StartScreen::DualSimTile DualSimTile::GetTileForSim2()
{
    return get_activation_factory<DualSimTile, IDualSimTileStatics>().GetTileForSim2();
}

inline Windows::Foundation::IAsyncOperation<bool> DualSimTile::UpdateDisplayNameForSim1Async(hstring_view name)
{
    return get_activation_factory<DualSimTile, IDualSimTileStatics>().UpdateDisplayNameForSim1Async(name);
}

inline Windows::UI::Notifications::TileUpdater DualSimTile::CreateTileUpdaterForSim1()
{
    return get_activation_factory<DualSimTile, IDualSimTileStatics>().CreateTileUpdaterForSim1();
}

inline Windows::UI::Notifications::TileUpdater DualSimTile::CreateTileUpdaterForSim2()
{
    return get_activation_factory<DualSimTile, IDualSimTileStatics>().CreateTileUpdaterForSim2();
}

inline Windows::UI::Notifications::BadgeUpdater DualSimTile::CreateBadgeUpdaterForSim1()
{
    return get_activation_factory<DualSimTile, IDualSimTileStatics>().CreateBadgeUpdaterForSim1();
}

inline Windows::UI::Notifications::BadgeUpdater DualSimTile::CreateBadgeUpdaterForSim2()
{
    return get_activation_factory<DualSimTile, IDualSimTileStatics>().CreateBadgeUpdaterForSim2();
}

inline Windows::UI::Notifications::ToastNotifier DualSimTile::CreateToastNotifierForSim1()
{
    return get_activation_factory<DualSimTile, IDualSimTileStatics>().CreateToastNotifierForSim1();
}

inline Windows::UI::Notifications::ToastNotifier DualSimTile::CreateToastNotifierForSim2()
{
    return get_activation_factory<DualSimTile, IDualSimTileStatics>().CreateToastNotifierForSim2();
}

}

}
#pragma warning(pop)
