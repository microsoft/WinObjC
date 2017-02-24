// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.UI.3.h"
#include "internal/Windows.UI.Popups.3.h"
#include "internal/Windows.UI.StartScreen.3.h"
#include "Windows.UI.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::UI::StartScreen::IJumpList> : produce_base<D, Windows::UI::StartScreen::IJumpList>
{
    HRESULT __stdcall get_Items(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::StartScreen::JumpListItem>> value) noexcept override
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

    HRESULT __stdcall get_SystemGroupKind(Windows::UI::StartScreen::JumpListSystemGroupKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SystemGroupKind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SystemGroupKind(Windows::UI::StartScreen::JumpListSystemGroupKind value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SystemGroupKind(value);
            return S_OK;
        }
        catch (...)
        {
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
};

template <typename D>
struct produce<D, Windows::UI::StartScreen::IJumpListItem> : produce_base<D, Windows::UI::StartScreen::IJumpListItem>
{
    HRESULT __stdcall get_Kind(Windows::UI::StartScreen::JumpListItemKind * value) noexcept override
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

    HRESULT __stdcall get_Arguments(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Arguments());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RemovedByUser(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RemovedByUser());
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

    HRESULT __stdcall get_GroupName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GroupName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_GroupName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GroupName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Logo(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Logo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Logo(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Logo(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::StartScreen::IJumpListItemStatics> : produce_base<D, Windows::UI::StartScreen::IJumpListItemStatics>
{
    HRESULT __stdcall abi_CreateWithArguments(impl::abi_arg_in<hstring> arguments, impl::abi_arg_in<hstring> displayName, impl::abi_arg_out<Windows::UI::StartScreen::IJumpListItem> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateWithArguments(*reinterpret_cast<const hstring *>(&arguments), *reinterpret_cast<const hstring *>(&displayName)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateSeparator(impl::abi_arg_out<Windows::UI::StartScreen::IJumpListItem> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateSeparator());
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
struct produce<D, Windows::UI::StartScreen::IJumpListStatics> : produce_base<D, Windows::UI::StartScreen::IJumpListStatics>
{
    HRESULT __stdcall abi_LoadCurrentAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::UI::StartScreen::JumpList>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().LoadCurrentAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsSupported(bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::StartScreen::ISecondaryTile> : produce_base<D, Windows::UI::StartScreen::ISecondaryTile>
{
    HRESULT __stdcall put_TileId(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TileId(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TileId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TileId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Arguments(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Arguments(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Arguments(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Arguments());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ShortName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShortName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ShortName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ShortName());
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

    HRESULT __stdcall put_Logo(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Logo(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Logo(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Logo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SmallLogo(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SmallLogo(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SmallLogo(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SmallLogo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_WideLogo(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WideLogo(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WideLogo(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WideLogo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LockScreenBadgeLogo(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LockScreenBadgeLogo(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LockScreenBadgeLogo(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LockScreenBadgeLogo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LockScreenDisplayBadgeAndTileText(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LockScreenDisplayBadgeAndTileText(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LockScreenDisplayBadgeAndTileText(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LockScreenDisplayBadgeAndTileText());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TileOptions(Windows::UI::StartScreen::TileOptions value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TileOptions(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TileOptions(Windows::UI::StartScreen::TileOptions * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TileOptions());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ForegroundText(Windows::UI::StartScreen::ForegroundText value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ForegroundText(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ForegroundText(Windows::UI::StartScreen::ForegroundText * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ForegroundText());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BackgroundColor(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BackgroundColor(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BackgroundColor(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BackgroundColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestCreateAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RequestCreateAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestCreateAsyncWithPoint(impl::abi_arg_in<Windows::Foundation::Point> invocationPoint, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RequestCreateAsync(*reinterpret_cast<const Windows::Foundation::Point *>(&invocationPoint)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestCreateAsyncWithRect(impl::abi_arg_in<Windows::Foundation::Rect> selection, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RequestCreateForSelectionAsync(*reinterpret_cast<const Windows::Foundation::Rect *>(&selection)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestCreateAsyncWithRectAndPlacement(impl::abi_arg_in<Windows::Foundation::Rect> selection, Windows::UI::Popups::Placement preferredPlacement, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RequestCreateForSelectionAsync(*reinterpret_cast<const Windows::Foundation::Rect *>(&selection), preferredPlacement));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestDeleteAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RequestDeleteAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestDeleteAsyncWithPoint(impl::abi_arg_in<Windows::Foundation::Point> invocationPoint, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RequestDeleteAsync(*reinterpret_cast<const Windows::Foundation::Point *>(&invocationPoint)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestDeleteAsyncWithRect(impl::abi_arg_in<Windows::Foundation::Rect> selection, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RequestDeleteForSelectionAsync(*reinterpret_cast<const Windows::Foundation::Rect *>(&selection)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestDeleteAsyncWithRectAndPlacement(impl::abi_arg_in<Windows::Foundation::Rect> selection, Windows::UI::Popups::Placement preferredPlacement, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RequestDeleteForSelectionAsync(*reinterpret_cast<const Windows::Foundation::Rect *>(&selection), preferredPlacement));
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
};

template <typename D>
struct produce<D, Windows::UI::StartScreen::ISecondaryTile2> : produce_base<D, Windows::UI::StartScreen::ISecondaryTile2>
{
    HRESULT __stdcall put_PhoneticName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PhoneticName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PhoneticName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PhoneticName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VisualElements(impl::abi_arg_out<Windows::UI::StartScreen::ISecondaryTileVisualElements> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VisualElements());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RoamingEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RoamingEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RoamingEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RoamingEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_VisualElementsRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::StartScreen::SecondaryTile, Windows::UI::StartScreen::VisualElementsRequestedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().VisualElementsRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::StartScreen::SecondaryTile, Windows::UI::StartScreen::VisualElementsRequestedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_VisualElementsRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VisualElementsRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::StartScreen::ISecondaryTileFactory> : produce_base<D, Windows::UI::StartScreen::ISecondaryTileFactory>
{
    HRESULT __stdcall abi_CreateTile(impl::abi_arg_in<hstring> tileId, impl::abi_arg_in<hstring> shortName, impl::abi_arg_in<hstring> displayName, impl::abi_arg_in<hstring> arguments, Windows::UI::StartScreen::TileOptions tileOptions, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> logoReference, impl::abi_arg_out<Windows::UI::StartScreen::ISecondaryTile> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateTile(*reinterpret_cast<const hstring *>(&tileId), *reinterpret_cast<const hstring *>(&shortName), *reinterpret_cast<const hstring *>(&displayName), *reinterpret_cast<const hstring *>(&arguments), tileOptions, *reinterpret_cast<const Windows::Foundation::Uri *>(&logoReference)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWideTile(impl::abi_arg_in<hstring> tileId, impl::abi_arg_in<hstring> shortName, impl::abi_arg_in<hstring> displayName, impl::abi_arg_in<hstring> arguments, Windows::UI::StartScreen::TileOptions tileOptions, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> logoReference, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> wideLogoReference, impl::abi_arg_out<Windows::UI::StartScreen::ISecondaryTile> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateWideTile(*reinterpret_cast<const hstring *>(&tileId), *reinterpret_cast<const hstring *>(&shortName), *reinterpret_cast<const hstring *>(&displayName), *reinterpret_cast<const hstring *>(&arguments), tileOptions, *reinterpret_cast<const Windows::Foundation::Uri *>(&logoReference), *reinterpret_cast<const Windows::Foundation::Uri *>(&wideLogoReference)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithId(impl::abi_arg_in<hstring> tileId, impl::abi_arg_out<Windows::UI::StartScreen::ISecondaryTile> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateWithId(*reinterpret_cast<const hstring *>(&tileId)));
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
struct produce<D, Windows::UI::StartScreen::ISecondaryTileFactory2> : produce_base<D, Windows::UI::StartScreen::ISecondaryTileFactory2>
{
    HRESULT __stdcall abi_CreateMinimalTile(impl::abi_arg_in<hstring> tileId, impl::abi_arg_in<hstring> displayName, impl::abi_arg_in<hstring> arguments, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> square150x150Logo, Windows::UI::StartScreen::TileSize desiredSize, impl::abi_arg_out<Windows::UI::StartScreen::ISecondaryTile> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateMinimalTile(*reinterpret_cast<const hstring *>(&tileId), *reinterpret_cast<const hstring *>(&displayName), *reinterpret_cast<const hstring *>(&arguments), *reinterpret_cast<const Windows::Foundation::Uri *>(&square150x150Logo), desiredSize));
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
struct produce<D, Windows::UI::StartScreen::ISecondaryTileStatics> : produce_base<D, Windows::UI::StartScreen::ISecondaryTileStatics>
{
    HRESULT __stdcall abi_Exists(impl::abi_arg_in<hstring> tileId, bool * exists) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *exists = detach_abi(this->shim().Exists(*reinterpret_cast<const hstring *>(&tileId)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAllAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::UI::StartScreen::SecondaryTile>>> operation) noexcept override
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

    HRESULT __stdcall abi_FindAllForApplicationAsync(impl::abi_arg_in<hstring> applicationId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::UI::StartScreen::SecondaryTile>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().FindAllAsync(*reinterpret_cast<const hstring *>(&applicationId)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAllForPackageAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::UI::StartScreen::SecondaryTile>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().FindAllForPackageAsync());
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
struct produce<D, Windows::UI::StartScreen::ISecondaryTileVisualElements> : produce_base<D, Windows::UI::StartScreen::ISecondaryTileVisualElements>
{
    HRESULT __stdcall put_Square30x30Logo(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Square30x30Logo(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Square30x30Logo(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Square30x30Logo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Square70x70Logo(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Square70x70Logo(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Square70x70Logo(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Square70x70Logo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Square150x150Logo(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Square150x150Logo(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Square150x150Logo(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Square150x150Logo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Wide310x150Logo(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Wide310x150Logo(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Wide310x150Logo(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Wide310x150Logo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Square310x310Logo(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Square310x310Logo(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Square310x310Logo(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Square310x310Logo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ForegroundText(Windows::UI::StartScreen::ForegroundText value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ForegroundText(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ForegroundText(Windows::UI::StartScreen::ForegroundText * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ForegroundText());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BackgroundColor(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BackgroundColor(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BackgroundColor(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BackgroundColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ShowNameOnSquare150x150Logo(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowNameOnSquare150x150Logo(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ShowNameOnSquare150x150Logo(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ShowNameOnSquare150x150Logo());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ShowNameOnWide310x150Logo(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowNameOnWide310x150Logo(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ShowNameOnWide310x150Logo(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ShowNameOnWide310x150Logo());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ShowNameOnSquare310x310Logo(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowNameOnSquare310x310Logo(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ShowNameOnSquare310x310Logo(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ShowNameOnSquare310x310Logo());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::StartScreen::ISecondaryTileVisualElements2> : produce_base<D, Windows::UI::StartScreen::ISecondaryTileVisualElements2>
{
    HRESULT __stdcall put_Square71x71Logo(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Square71x71Logo(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Square71x71Logo(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Square71x71Logo());
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
struct produce<D, Windows::UI::StartScreen::ISecondaryTileVisualElements3> : produce_base<D, Windows::UI::StartScreen::ISecondaryTileVisualElements3>
{
    HRESULT __stdcall put_Square44x44Logo(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Square44x44Logo(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Square44x44Logo(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Square44x44Logo());
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
struct produce<D, Windows::UI::StartScreen::IVisualElementsRequest> : produce_base<D, Windows::UI::StartScreen::IVisualElementsRequest>
{
    HRESULT __stdcall get_VisualElements(impl::abi_arg_out<Windows::UI::StartScreen::ISecondaryTileVisualElements> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VisualElements());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AlternateVisualElements(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::UI::StartScreen::SecondaryTileVisualElements>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AlternateVisualElements());
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

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::UI::StartScreen::IVisualElementsRequestDeferral> deferral) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deferral = detach_abi(this->shim().GetDeferral());
            return S_OK;
        }
        catch (...)
        {
            *deferral = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::StartScreen::IVisualElementsRequestDeferral> : produce_base<D, Windows::UI::StartScreen::IVisualElementsRequestDeferral>
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
struct produce<D, Windows::UI::StartScreen::IVisualElementsRequestedEventArgs> : produce_base<D, Windows::UI::StartScreen::IVisualElementsRequestedEventArgs>
{
    HRESULT __stdcall get_Request(impl::abi_arg_out<Windows::UI::StartScreen::IVisualElementsRequest> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Request());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::UI::StartScreen {

template <typename D> Windows::UI::StartScreen::JumpListItemKind impl_IJumpListItem<D>::Kind() const
{
    Windows::UI::StartScreen::JumpListItemKind value {};
    check_hresult(WINRT_SHIM(IJumpListItem)->get_Kind(&value));
    return value;
}

template <typename D> hstring impl_IJumpListItem<D>::Arguments() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IJumpListItem)->get_Arguments(put_abi(value)));
    return value;
}

template <typename D> bool impl_IJumpListItem<D>::RemovedByUser() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IJumpListItem)->get_RemovedByUser(&value));
    return value;
}

template <typename D> hstring impl_IJumpListItem<D>::Description() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IJumpListItem)->get_Description(put_abi(value)));
    return value;
}

template <typename D> void impl_IJumpListItem<D>::Description(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IJumpListItem)->put_Description(get_abi(value)));
}

template <typename D> hstring impl_IJumpListItem<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IJumpListItem)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> void impl_IJumpListItem<D>::DisplayName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IJumpListItem)->put_DisplayName(get_abi(value)));
}

template <typename D> hstring impl_IJumpListItem<D>::GroupName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IJumpListItem)->get_GroupName(put_abi(value)));
    return value;
}

template <typename D> void impl_IJumpListItem<D>::GroupName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IJumpListItem)->put_GroupName(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_IJumpListItem<D>::Logo() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IJumpListItem)->get_Logo(put_abi(value)));
    return value;
}

template <typename D> void impl_IJumpListItem<D>::Logo(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(IJumpListItem)->put_Logo(get_abi(value)));
}

template <typename D> Windows::UI::StartScreen::JumpListItem impl_IJumpListItemStatics<D>::CreateWithArguments(hstring_view arguments, hstring_view displayName) const
{
    Windows::UI::StartScreen::JumpListItem result { nullptr };
    check_hresult(WINRT_SHIM(IJumpListItemStatics)->abi_CreateWithArguments(get_abi(arguments), get_abi(displayName), put_abi(result)));
    return result;
}

template <typename D> Windows::UI::StartScreen::JumpListItem impl_IJumpListItemStatics<D>::CreateSeparator() const
{
    Windows::UI::StartScreen::JumpListItem result { nullptr };
    check_hresult(WINRT_SHIM(IJumpListItemStatics)->abi_CreateSeparator(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::UI::StartScreen::JumpListItem> impl_IJumpList<D>::Items() const
{
    Windows::Foundation::Collections::IVector<Windows::UI::StartScreen::JumpListItem> value;
    check_hresult(WINRT_SHIM(IJumpList)->get_Items(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::StartScreen::JumpListSystemGroupKind impl_IJumpList<D>::SystemGroupKind() const
{
    Windows::UI::StartScreen::JumpListSystemGroupKind value {};
    check_hresult(WINRT_SHIM(IJumpList)->get_SystemGroupKind(&value));
    return value;
}

template <typename D> void impl_IJumpList<D>::SystemGroupKind(Windows::UI::StartScreen::JumpListSystemGroupKind value) const
{
    check_hresult(WINRT_SHIM(IJumpList)->put_SystemGroupKind(value));
}

template <typename D> Windows::Foundation::IAsyncAction impl_IJumpList<D>::SaveAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IJumpList)->abi_SaveAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::UI::StartScreen::JumpList> impl_IJumpListStatics<D>::LoadCurrentAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::UI::StartScreen::JumpList> result;
    check_hresult(WINRT_SHIM(IJumpListStatics)->abi_LoadCurrentAsync(put_abi(result)));
    return result;
}

template <typename D> bool impl_IJumpListStatics<D>::IsSupported() const
{
    bool result {};
    check_hresult(WINRT_SHIM(IJumpListStatics)->abi_IsSupported(&result));
    return result;
}

template <typename D> void impl_ISecondaryTile<D>::TileId(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISecondaryTile)->put_TileId(get_abi(value)));
}

template <typename D> hstring impl_ISecondaryTile<D>::TileId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISecondaryTile)->get_TileId(put_abi(value)));
    return value;
}

template <typename D> void impl_ISecondaryTile<D>::Arguments(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISecondaryTile)->put_Arguments(get_abi(value)));
}

template <typename D> hstring impl_ISecondaryTile<D>::Arguments() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISecondaryTile)->get_Arguments(put_abi(value)));
    return value;
}

template <typename D> void impl_ISecondaryTile<D>::ShortName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISecondaryTile)->put_ShortName(get_abi(value)));
}

template <typename D> hstring impl_ISecondaryTile<D>::ShortName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISecondaryTile)->get_ShortName(put_abi(value)));
    return value;
}

template <typename D> void impl_ISecondaryTile<D>::DisplayName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISecondaryTile)->put_DisplayName(get_abi(value)));
}

template <typename D> hstring impl_ISecondaryTile<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISecondaryTile)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> void impl_ISecondaryTile<D>::Logo(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(ISecondaryTile)->put_Logo(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_ISecondaryTile<D>::Logo() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(ISecondaryTile)->get_Logo(put_abi(value)));
    return value;
}

template <typename D> void impl_ISecondaryTile<D>::SmallLogo(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(ISecondaryTile)->put_SmallLogo(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_ISecondaryTile<D>::SmallLogo() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(ISecondaryTile)->get_SmallLogo(put_abi(value)));
    return value;
}

template <typename D> void impl_ISecondaryTile<D>::WideLogo(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(ISecondaryTile)->put_WideLogo(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_ISecondaryTile<D>::WideLogo() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(ISecondaryTile)->get_WideLogo(put_abi(value)));
    return value;
}

template <typename D> void impl_ISecondaryTile<D>::LockScreenBadgeLogo(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(ISecondaryTile)->put_LockScreenBadgeLogo(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_ISecondaryTile<D>::LockScreenBadgeLogo() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(ISecondaryTile)->get_LockScreenBadgeLogo(put_abi(value)));
    return value;
}

template <typename D> void impl_ISecondaryTile<D>::LockScreenDisplayBadgeAndTileText(bool value) const
{
    check_hresult(WINRT_SHIM(ISecondaryTile)->put_LockScreenDisplayBadgeAndTileText(value));
}

template <typename D> bool impl_ISecondaryTile<D>::LockScreenDisplayBadgeAndTileText() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISecondaryTile)->get_LockScreenDisplayBadgeAndTileText(&value));
    return value;
}

template <typename D> void impl_ISecondaryTile<D>::TileOptions(Windows::UI::StartScreen::TileOptions value) const
{
    check_hresult(WINRT_SHIM(ISecondaryTile)->put_TileOptions(value));
}

template <typename D> Windows::UI::StartScreen::TileOptions impl_ISecondaryTile<D>::TileOptions() const
{
    Windows::UI::StartScreen::TileOptions value {};
    check_hresult(WINRT_SHIM(ISecondaryTile)->get_TileOptions(&value));
    return value;
}

template <typename D> void impl_ISecondaryTile<D>::ForegroundText(Windows::UI::StartScreen::ForegroundText value) const
{
    check_hresult(WINRT_SHIM(ISecondaryTile)->put_ForegroundText(value));
}

template <typename D> Windows::UI::StartScreen::ForegroundText impl_ISecondaryTile<D>::ForegroundText() const
{
    Windows::UI::StartScreen::ForegroundText value {};
    check_hresult(WINRT_SHIM(ISecondaryTile)->get_ForegroundText(&value));
    return value;
}

template <typename D> void impl_ISecondaryTile<D>::BackgroundColor(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(ISecondaryTile)->put_BackgroundColor(get_abi(value)));
}

template <typename D> Windows::UI::Color impl_ISecondaryTile<D>::BackgroundColor() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(ISecondaryTile)->get_BackgroundColor(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ISecondaryTile<D>::RequestCreateAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(ISecondaryTile)->abi_RequestCreateAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ISecondaryTile<D>::RequestCreateAsync(const Windows::Foundation::Point & invocationPoint) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(ISecondaryTile)->abi_RequestCreateAsyncWithPoint(get_abi(invocationPoint), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ISecondaryTile<D>::RequestCreateForSelectionAsync(const Windows::Foundation::Rect & selection) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(ISecondaryTile)->abi_RequestCreateAsyncWithRect(get_abi(selection), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ISecondaryTile<D>::RequestCreateForSelectionAsync(const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(ISecondaryTile)->abi_RequestCreateAsyncWithRectAndPlacement(get_abi(selection), preferredPlacement, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ISecondaryTile<D>::RequestDeleteAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(ISecondaryTile)->abi_RequestDeleteAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ISecondaryTile<D>::RequestDeleteAsync(const Windows::Foundation::Point & invocationPoint) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(ISecondaryTile)->abi_RequestDeleteAsyncWithPoint(get_abi(invocationPoint), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ISecondaryTile<D>::RequestDeleteForSelectionAsync(const Windows::Foundation::Rect & selection) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(ISecondaryTile)->abi_RequestDeleteAsyncWithRect(get_abi(selection), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ISecondaryTile<D>::RequestDeleteForSelectionAsync(const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(ISecondaryTile)->abi_RequestDeleteAsyncWithRectAndPlacement(get_abi(selection), preferredPlacement, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ISecondaryTile<D>::UpdateAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(ISecondaryTile)->abi_UpdateAsync(put_abi(operation)));
    return operation;
}

template <typename D> void impl_ISecondaryTile2<D>::PhoneticName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISecondaryTile2)->put_PhoneticName(get_abi(value)));
}

template <typename D> hstring impl_ISecondaryTile2<D>::PhoneticName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISecondaryTile2)->get_PhoneticName(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::StartScreen::SecondaryTileVisualElements impl_ISecondaryTile2<D>::VisualElements() const
{
    Windows::UI::StartScreen::SecondaryTileVisualElements value { nullptr };
    check_hresult(WINRT_SHIM(ISecondaryTile2)->get_VisualElements(put_abi(value)));
    return value;
}

template <typename D> void impl_ISecondaryTile2<D>::RoamingEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(ISecondaryTile2)->put_RoamingEnabled(value));
}

template <typename D> bool impl_ISecondaryTile2<D>::RoamingEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISecondaryTile2)->get_RoamingEnabled(&value));
    return value;
}

template <typename D> event_token impl_ISecondaryTile2<D>::VisualElementsRequested(const Windows::Foundation::TypedEventHandler<Windows::UI::StartScreen::SecondaryTile, Windows::UI::StartScreen::VisualElementsRequestedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ISecondaryTile2)->add_VisualElementsRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ISecondaryTile2> impl_ISecondaryTile2<D>::VisualElementsRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::StartScreen::SecondaryTile, Windows::UI::StartScreen::VisualElementsRequestedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ISecondaryTile2>(this, &ABI::Windows::UI::StartScreen::ISecondaryTile2::remove_VisualElementsRequested, VisualElementsRequested(handler));
}

template <typename D> void impl_ISecondaryTile2<D>::VisualElementsRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(ISecondaryTile2)->remove_VisualElementsRequested(token));
}

template <typename D> void impl_ISecondaryTileVisualElements<D>::Square30x30Logo(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(ISecondaryTileVisualElements)->put_Square30x30Logo(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_ISecondaryTileVisualElements<D>::Square30x30Logo() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(ISecondaryTileVisualElements)->get_Square30x30Logo(put_abi(value)));
    return value;
}

template <typename D> void impl_ISecondaryTileVisualElements<D>::Square70x70Logo(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(ISecondaryTileVisualElements)->put_Square70x70Logo(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_ISecondaryTileVisualElements<D>::Square70x70Logo() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(ISecondaryTileVisualElements)->get_Square70x70Logo(put_abi(value)));
    return value;
}

template <typename D> void impl_ISecondaryTileVisualElements<D>::Square150x150Logo(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(ISecondaryTileVisualElements)->put_Square150x150Logo(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_ISecondaryTileVisualElements<D>::Square150x150Logo() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(ISecondaryTileVisualElements)->get_Square150x150Logo(put_abi(value)));
    return value;
}

template <typename D> void impl_ISecondaryTileVisualElements<D>::Wide310x150Logo(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(ISecondaryTileVisualElements)->put_Wide310x150Logo(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_ISecondaryTileVisualElements<D>::Wide310x150Logo() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(ISecondaryTileVisualElements)->get_Wide310x150Logo(put_abi(value)));
    return value;
}

template <typename D> void impl_ISecondaryTileVisualElements<D>::Square310x310Logo(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(ISecondaryTileVisualElements)->put_Square310x310Logo(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_ISecondaryTileVisualElements<D>::Square310x310Logo() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(ISecondaryTileVisualElements)->get_Square310x310Logo(put_abi(value)));
    return value;
}

template <typename D> void impl_ISecondaryTileVisualElements<D>::ForegroundText(Windows::UI::StartScreen::ForegroundText value) const
{
    check_hresult(WINRT_SHIM(ISecondaryTileVisualElements)->put_ForegroundText(value));
}

template <typename D> Windows::UI::StartScreen::ForegroundText impl_ISecondaryTileVisualElements<D>::ForegroundText() const
{
    Windows::UI::StartScreen::ForegroundText value {};
    check_hresult(WINRT_SHIM(ISecondaryTileVisualElements)->get_ForegroundText(&value));
    return value;
}

template <typename D> void impl_ISecondaryTileVisualElements<D>::BackgroundColor(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(ISecondaryTileVisualElements)->put_BackgroundColor(get_abi(value)));
}

template <typename D> Windows::UI::Color impl_ISecondaryTileVisualElements<D>::BackgroundColor() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(ISecondaryTileVisualElements)->get_BackgroundColor(put_abi(value)));
    return value;
}

template <typename D> void impl_ISecondaryTileVisualElements<D>::ShowNameOnSquare150x150Logo(bool value) const
{
    check_hresult(WINRT_SHIM(ISecondaryTileVisualElements)->put_ShowNameOnSquare150x150Logo(value));
}

template <typename D> bool impl_ISecondaryTileVisualElements<D>::ShowNameOnSquare150x150Logo() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISecondaryTileVisualElements)->get_ShowNameOnSquare150x150Logo(&value));
    return value;
}

template <typename D> void impl_ISecondaryTileVisualElements<D>::ShowNameOnWide310x150Logo(bool value) const
{
    check_hresult(WINRT_SHIM(ISecondaryTileVisualElements)->put_ShowNameOnWide310x150Logo(value));
}

template <typename D> bool impl_ISecondaryTileVisualElements<D>::ShowNameOnWide310x150Logo() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISecondaryTileVisualElements)->get_ShowNameOnWide310x150Logo(&value));
    return value;
}

template <typename D> void impl_ISecondaryTileVisualElements<D>::ShowNameOnSquare310x310Logo(bool value) const
{
    check_hresult(WINRT_SHIM(ISecondaryTileVisualElements)->put_ShowNameOnSquare310x310Logo(value));
}

template <typename D> bool impl_ISecondaryTileVisualElements<D>::ShowNameOnSquare310x310Logo() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISecondaryTileVisualElements)->get_ShowNameOnSquare310x310Logo(&value));
    return value;
}

template <typename D> void impl_ISecondaryTileVisualElements2<D>::Square71x71Logo(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(ISecondaryTileVisualElements2)->put_Square71x71Logo(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_ISecondaryTileVisualElements2<D>::Square71x71Logo() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(ISecondaryTileVisualElements2)->get_Square71x71Logo(put_abi(value)));
    return value;
}

template <typename D> void impl_ISecondaryTileVisualElements3<D>::Square44x44Logo(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(ISecondaryTileVisualElements3)->put_Square44x44Logo(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_ISecondaryTileVisualElements3<D>::Square44x44Logo() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(ISecondaryTileVisualElements3)->get_Square44x44Logo(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::StartScreen::SecondaryTile impl_ISecondaryTileFactory<D>::CreateTile(hstring_view tileId, hstring_view shortName, hstring_view displayName, hstring_view arguments, Windows::UI::StartScreen::TileOptions tileOptions, const Windows::Foundation::Uri & logoReference) const
{
    Windows::UI::StartScreen::SecondaryTile value { nullptr };
    check_hresult(WINRT_SHIM(ISecondaryTileFactory)->abi_CreateTile(get_abi(tileId), get_abi(shortName), get_abi(displayName), get_abi(arguments), tileOptions, get_abi(logoReference), put_abi(value)));
    return value;
}

template <typename D> Windows::UI::StartScreen::SecondaryTile impl_ISecondaryTileFactory<D>::CreateWideTile(hstring_view tileId, hstring_view shortName, hstring_view displayName, hstring_view arguments, Windows::UI::StartScreen::TileOptions tileOptions, const Windows::Foundation::Uri & logoReference, const Windows::Foundation::Uri & wideLogoReference) const
{
    Windows::UI::StartScreen::SecondaryTile value { nullptr };
    check_hresult(WINRT_SHIM(ISecondaryTileFactory)->abi_CreateWideTile(get_abi(tileId), get_abi(shortName), get_abi(displayName), get_abi(arguments), tileOptions, get_abi(logoReference), get_abi(wideLogoReference), put_abi(value)));
    return value;
}

template <typename D> Windows::UI::StartScreen::SecondaryTile impl_ISecondaryTileFactory<D>::CreateWithId(hstring_view tileId) const
{
    Windows::UI::StartScreen::SecondaryTile value { nullptr };
    check_hresult(WINRT_SHIM(ISecondaryTileFactory)->abi_CreateWithId(get_abi(tileId), put_abi(value)));
    return value;
}

template <typename D> Windows::UI::StartScreen::SecondaryTile impl_ISecondaryTileFactory2<D>::CreateMinimalTile(hstring_view tileId, hstring_view displayName, hstring_view arguments, const Windows::Foundation::Uri & square150x150Logo, Windows::UI::StartScreen::TileSize desiredSize) const
{
    Windows::UI::StartScreen::SecondaryTile value { nullptr };
    check_hresult(WINRT_SHIM(ISecondaryTileFactory2)->abi_CreateMinimalTile(get_abi(tileId), get_abi(displayName), get_abi(arguments), get_abi(square150x150Logo), desiredSize, put_abi(value)));
    return value;
}

template <typename D> bool impl_ISecondaryTileStatics<D>::Exists(hstring_view tileId) const
{
    bool exists {};
    check_hresult(WINRT_SHIM(ISecondaryTileStatics)->abi_Exists(get_abi(tileId), &exists));
    return exists;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::UI::StartScreen::SecondaryTile>> impl_ISecondaryTileStatics<D>::FindAllAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::UI::StartScreen::SecondaryTile>> operation;
    check_hresult(WINRT_SHIM(ISecondaryTileStatics)->abi_FindAllAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::UI::StartScreen::SecondaryTile>> impl_ISecondaryTileStatics<D>::FindAllAsync(hstring_view applicationId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::UI::StartScreen::SecondaryTile>> operation;
    check_hresult(WINRT_SHIM(ISecondaryTileStatics)->abi_FindAllForApplicationAsync(get_abi(applicationId), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::UI::StartScreen::SecondaryTile>> impl_ISecondaryTileStatics<D>::FindAllForPackageAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::UI::StartScreen::SecondaryTile>> operation;
    check_hresult(WINRT_SHIM(ISecondaryTileStatics)->abi_FindAllForPackageAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::UI::StartScreen::VisualElementsRequest impl_IVisualElementsRequestedEventArgs<D>::Request() const
{
    Windows::UI::StartScreen::VisualElementsRequest value { nullptr };
    check_hresult(WINRT_SHIM(IVisualElementsRequestedEventArgs)->get_Request(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::StartScreen::SecondaryTileVisualElements impl_IVisualElementsRequest<D>::VisualElements() const
{
    Windows::UI::StartScreen::SecondaryTileVisualElements value { nullptr };
    check_hresult(WINRT_SHIM(IVisualElementsRequest)->get_VisualElements(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::UI::StartScreen::SecondaryTileVisualElements> impl_IVisualElementsRequest<D>::AlternateVisualElements() const
{
    Windows::Foundation::Collections::IVectorView<Windows::UI::StartScreen::SecondaryTileVisualElements> value;
    check_hresult(WINRT_SHIM(IVisualElementsRequest)->get_AlternateVisualElements(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IVisualElementsRequest<D>::Deadline() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IVisualElementsRequest)->get_Deadline(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::StartScreen::VisualElementsRequestDeferral impl_IVisualElementsRequest<D>::GetDeferral() const
{
    Windows::UI::StartScreen::VisualElementsRequestDeferral deferral { nullptr };
    check_hresult(WINRT_SHIM(IVisualElementsRequest)->abi_GetDeferral(put_abi(deferral)));
    return deferral;
}

template <typename D> void impl_IVisualElementsRequestDeferral<D>::Complete() const
{
    check_hresult(WINRT_SHIM(IVisualElementsRequestDeferral)->abi_Complete());
}

inline Windows::Foundation::IAsyncOperation<Windows::UI::StartScreen::JumpList> JumpList::LoadCurrentAsync()
{
    return get_activation_factory<JumpList, IJumpListStatics>().LoadCurrentAsync();
}

inline bool JumpList::IsSupported()
{
    return get_activation_factory<JumpList, IJumpListStatics>().IsSupported();
}

inline Windows::UI::StartScreen::JumpListItem JumpListItem::CreateWithArguments(hstring_view arguments, hstring_view displayName)
{
    return get_activation_factory<JumpListItem, IJumpListItemStatics>().CreateWithArguments(arguments, displayName);
}

inline Windows::UI::StartScreen::JumpListItem JumpListItem::CreateSeparator()
{
    return get_activation_factory<JumpListItem, IJumpListItemStatics>().CreateSeparator();
}

inline SecondaryTile::SecondaryTile() :
    SecondaryTile(activate_instance<SecondaryTile>())
{}

inline SecondaryTile::SecondaryTile(hstring_view tileId, hstring_view shortName, hstring_view displayName, hstring_view arguments, Windows::UI::StartScreen::TileOptions tileOptions, const Windows::Foundation::Uri & logoReference) :
    SecondaryTile(get_activation_factory<SecondaryTile, ISecondaryTileFactory>().CreateTile(tileId, shortName, displayName, arguments, tileOptions, logoReference))
{}

inline SecondaryTile::SecondaryTile(hstring_view tileId, hstring_view shortName, hstring_view displayName, hstring_view arguments, Windows::UI::StartScreen::TileOptions tileOptions, const Windows::Foundation::Uri & logoReference, const Windows::Foundation::Uri & wideLogoReference) :
    SecondaryTile(get_activation_factory<SecondaryTile, ISecondaryTileFactory>().CreateWideTile(tileId, shortName, displayName, arguments, tileOptions, logoReference, wideLogoReference))
{}

inline SecondaryTile::SecondaryTile(hstring_view tileId) :
    SecondaryTile(get_activation_factory<SecondaryTile, ISecondaryTileFactory>().CreateWithId(tileId))
{}

inline SecondaryTile::SecondaryTile(hstring_view tileId, hstring_view displayName, hstring_view arguments, const Windows::Foundation::Uri & square150x150Logo, Windows::UI::StartScreen::TileSize desiredSize) :
    SecondaryTile(get_activation_factory<SecondaryTile, ISecondaryTileFactory2>().CreateMinimalTile(tileId, displayName, arguments, square150x150Logo, desiredSize))
{}

inline bool SecondaryTile::Exists(hstring_view tileId)
{
    return get_activation_factory<SecondaryTile, ISecondaryTileStatics>().Exists(tileId);
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::UI::StartScreen::SecondaryTile>> SecondaryTile::FindAllAsync()
{
    return get_activation_factory<SecondaryTile, ISecondaryTileStatics>().FindAllAsync();
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::UI::StartScreen::SecondaryTile>> SecondaryTile::FindAllAsync(hstring_view applicationId)
{
    return get_activation_factory<SecondaryTile, ISecondaryTileStatics>().FindAllAsync(applicationId);
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::UI::StartScreen::SecondaryTile>> SecondaryTile::FindAllForPackageAsync()
{
    return get_activation_factory<SecondaryTile, ISecondaryTileStatics>().FindAllForPackageAsync();
}

}

}
#pragma warning(pop)
