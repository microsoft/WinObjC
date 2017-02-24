// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Globalization.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.UI.Text.Core.3.h"
#include "Windows.UI.Text.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::UI::Text::Core::ICoreTextCompositionCompletedEventArgs> : produce_base<D, Windows::UI::Text::Core::ICoreTextCompositionCompletedEventArgs>
{
    HRESULT __stdcall get_IsCanceled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsCanceled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CompositionSegments(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::UI::Text::Core::CoreTextCompositionSegment>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CompositionSegments());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> value) noexcept override
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
struct produce<D, Windows::UI::Text::Core::ICoreTextCompositionSegment> : produce_base<D, Windows::UI::Text::Core::ICoreTextCompositionSegment>
{
    HRESULT __stdcall get_PreconversionString(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PreconversionString());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Range(impl::abi_arg_out<Windows::UI::Text::Core::CoreTextRange> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Range());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Text::Core::ICoreTextCompositionStartedEventArgs> : produce_base<D, Windows::UI::Text::Core::ICoreTextCompositionStartedEventArgs>
{
    HRESULT __stdcall get_IsCanceled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsCanceled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> value) noexcept override
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
struct produce<D, Windows::UI::Text::Core::ICoreTextEditContext> : produce_base<D, Windows::UI::Text::Core::ICoreTextEditContext>
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

    HRESULT __stdcall get_InputScope(Windows::UI::Text::Core::CoreTextInputScope * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InputScope());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_InputScope(Windows::UI::Text::Core::CoreTextInputScope value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InputScope(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsReadOnly(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsReadOnly());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsReadOnly(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsReadOnly(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InputPaneDisplayPolicy(Windows::UI::Text::Core::CoreTextInputPaneDisplayPolicy * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InputPaneDisplayPolicy());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_InputPaneDisplayPolicy(Windows::UI::Text::Core::CoreTextInputPaneDisplayPolicy value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InputPaneDisplayPolicy(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_TextRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextTextRequestedEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().TextRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextTextRequestedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_TextRequested(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TextRequested(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_SelectionRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextSelectionRequestedEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().SelectionRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextSelectionRequestedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SelectionRequested(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SelectionRequested(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_LayoutRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextLayoutRequestedEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().LayoutRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextLayoutRequestedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_LayoutRequested(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LayoutRequested(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_TextUpdating(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextTextUpdatingEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().TextUpdating(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextTextUpdatingEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_TextUpdating(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TextUpdating(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_SelectionUpdating(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextSelectionUpdatingEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().SelectionUpdating(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextSelectionUpdatingEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SelectionUpdating(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SelectionUpdating(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_FormatUpdating(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextFormatUpdatingEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().FormatUpdating(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextFormatUpdatingEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_FormatUpdating(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FormatUpdating(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_CompositionStarted(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextCompositionStartedEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().CompositionStarted(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextCompositionStartedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_CompositionStarted(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CompositionStarted(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_CompositionCompleted(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextCompositionCompletedEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().CompositionCompleted(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextCompositionCompletedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_CompositionCompleted(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CompositionCompleted(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_FocusRemoved(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::Foundation::IInspectable>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().FocusRemoved(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_FocusRemoved(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FocusRemoved(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_NotifyFocusEnter() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyFocusEnter();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_NotifyFocusLeave() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyFocusLeave();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_NotifyTextChanged(impl::abi_arg_in<Windows::UI::Text::Core::CoreTextRange> modifiedRange, int32_t newLength, impl::abi_arg_in<Windows::UI::Text::Core::CoreTextRange> newSelection) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyTextChanged(*reinterpret_cast<const Windows::UI::Text::Core::CoreTextRange *>(&modifiedRange), newLength, *reinterpret_cast<const Windows::UI::Text::Core::CoreTextRange *>(&newSelection));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_NotifySelectionChanged(impl::abi_arg_in<Windows::UI::Text::Core::CoreTextRange> selection) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifySelectionChanged(*reinterpret_cast<const Windows::UI::Text::Core::CoreTextRange *>(&selection));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_NotifyLayoutChanged() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyLayoutChanged();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Text::Core::ICoreTextEditContext2> : produce_base<D, Windows::UI::Text::Core::ICoreTextEditContext2>
{
    HRESULT __stdcall add_NotifyFocusLeaveCompleted(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::Foundation::IInspectable>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().NotifyFocusLeaveCompleted(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_NotifyFocusLeaveCompleted(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyFocusLeaveCompleted(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Text::Core::ICoreTextFormatUpdatingEventArgs> : produce_base<D, Windows::UI::Text::Core::ICoreTextFormatUpdatingEventArgs>
{
    HRESULT __stdcall get_Range(impl::abi_arg_out<Windows::UI::Text::Core::CoreTextRange> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Range());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TextColor(impl::abi_arg_out<Windows::Foundation::IReference<winrt::Windows::UI::ViewManagement::UIElementType>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TextColor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BackgroundColor(impl::abi_arg_out<Windows::Foundation::IReference<winrt::Windows::UI::ViewManagement::UIElementType>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BackgroundColor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UnderlineColor(impl::abi_arg_out<Windows::Foundation::IReference<winrt::Windows::UI::ViewManagement::UIElementType>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UnderlineColor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UnderlineType(impl::abi_arg_out<Windows::Foundation::IReference<winrt::Windows::UI::Text::UnderlineType>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UnderlineType());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Reason(Windows::UI::Text::Core::CoreTextFormatUpdatingReason * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Reason());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Result(Windows::UI::Text::Core::CoreTextFormatUpdatingResult * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Result());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Result(Windows::UI::Text::Core::CoreTextFormatUpdatingResult value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Result(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsCanceled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsCanceled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> value) noexcept override
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
struct produce<D, Windows::UI::Text::Core::ICoreTextLayoutBounds> : produce_base<D, Windows::UI::Text::Core::ICoreTextLayoutBounds>
{
    HRESULT __stdcall get_TextBounds(impl::abi_arg_out<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TextBounds());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TextBounds(impl::abi_arg_in<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TextBounds(*reinterpret_cast<const Windows::Foundation::Rect *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ControlBounds(impl::abi_arg_out<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ControlBounds());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ControlBounds(impl::abi_arg_in<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ControlBounds(*reinterpret_cast<const Windows::Foundation::Rect *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Text::Core::ICoreTextLayoutRequest> : produce_base<D, Windows::UI::Text::Core::ICoreTextLayoutRequest>
{
    HRESULT __stdcall get_Range(impl::abi_arg_out<Windows::UI::Text::Core::CoreTextRange> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Range());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LayoutBounds(impl::abi_arg_out<Windows::UI::Text::Core::ICoreTextLayoutBounds> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LayoutBounds());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsCanceled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsCanceled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> value) noexcept override
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
struct produce<D, Windows::UI::Text::Core::ICoreTextLayoutRequestedEventArgs> : produce_base<D, Windows::UI::Text::Core::ICoreTextLayoutRequestedEventArgs>
{
    HRESULT __stdcall get_Request(impl::abi_arg_out<Windows::UI::Text::Core::ICoreTextLayoutRequest> value) noexcept override
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

template <typename D>
struct produce<D, Windows::UI::Text::Core::ICoreTextSelectionRequest> : produce_base<D, Windows::UI::Text::Core::ICoreTextSelectionRequest>
{
    HRESULT __stdcall get_Selection(impl::abi_arg_out<Windows::UI::Text::Core::CoreTextRange> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Selection());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Selection(impl::abi_arg_in<Windows::UI::Text::Core::CoreTextRange> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Selection(*reinterpret_cast<const Windows::UI::Text::Core::CoreTextRange *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsCanceled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsCanceled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> value) noexcept override
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
struct produce<D, Windows::UI::Text::Core::ICoreTextSelectionRequestedEventArgs> : produce_base<D, Windows::UI::Text::Core::ICoreTextSelectionRequestedEventArgs>
{
    HRESULT __stdcall get_Request(impl::abi_arg_out<Windows::UI::Text::Core::ICoreTextSelectionRequest> value) noexcept override
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

template <typename D>
struct produce<D, Windows::UI::Text::Core::ICoreTextSelectionUpdatingEventArgs> : produce_base<D, Windows::UI::Text::Core::ICoreTextSelectionUpdatingEventArgs>
{
    HRESULT __stdcall get_Selection(impl::abi_arg_out<Windows::UI::Text::Core::CoreTextRange> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Selection());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Result(Windows::UI::Text::Core::CoreTextSelectionUpdatingResult * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Result());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Result(Windows::UI::Text::Core::CoreTextSelectionUpdatingResult value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Result(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsCanceled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsCanceled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> value) noexcept override
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
struct produce<D, Windows::UI::Text::Core::ICoreTextServicesManager> : produce_base<D, Windows::UI::Text::Core::ICoreTextServicesManager>
{
    HRESULT __stdcall get_InputLanguage(impl::abi_arg_out<Windows::Globalization::ILanguage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InputLanguage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_InputLanguageChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextServicesManager, Windows::Foundation::IInspectable>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().InputLanguageChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextServicesManager, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_InputLanguageChanged(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InputLanguageChanged(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateEditContext(impl::abi_arg_out<Windows::UI::Text::Core::ICoreTextEditContext> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateEditContext());
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
struct produce<D, Windows::UI::Text::Core::ICoreTextServicesManagerStatics> : produce_base<D, Windows::UI::Text::Core::ICoreTextServicesManagerStatics>
{
    HRESULT __stdcall abi_GetForCurrentView(impl::abi_arg_out<Windows::UI::Text::Core::ICoreTextServicesManager> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetForCurrentView());
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
struct produce<D, Windows::UI::Text::Core::ICoreTextServicesStatics> : produce_base<D, Windows::UI::Text::Core::ICoreTextServicesStatics>
{
    HRESULT __stdcall get_HiddenCharacter(wchar_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HiddenCharacter());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Text::Core::ICoreTextTextRequest> : produce_base<D, Windows::UI::Text::Core::ICoreTextTextRequest>
{
    HRESULT __stdcall get_Range(impl::abi_arg_out<Windows::UI::Text::Core::CoreTextRange> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Range());
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

    HRESULT __stdcall get_IsCanceled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsCanceled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> value) noexcept override
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
struct produce<D, Windows::UI::Text::Core::ICoreTextTextRequestedEventArgs> : produce_base<D, Windows::UI::Text::Core::ICoreTextTextRequestedEventArgs>
{
    HRESULT __stdcall get_Request(impl::abi_arg_out<Windows::UI::Text::Core::ICoreTextTextRequest> value) noexcept override
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

template <typename D>
struct produce<D, Windows::UI::Text::Core::ICoreTextTextUpdatingEventArgs> : produce_base<D, Windows::UI::Text::Core::ICoreTextTextUpdatingEventArgs>
{
    HRESULT __stdcall get_Range(impl::abi_arg_out<Windows::UI::Text::Core::CoreTextRange> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Range());
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

    HRESULT __stdcall get_NewSelection(impl::abi_arg_out<Windows::UI::Text::Core::CoreTextRange> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NewSelection());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InputLanguage(impl::abi_arg_out<Windows::Globalization::ILanguage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InputLanguage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Result(Windows::UI::Text::Core::CoreTextTextUpdatingResult * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Result());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Result(Windows::UI::Text::Core::CoreTextTextUpdatingResult value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Result(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsCanceled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsCanceled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> value) noexcept override
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

}

namespace Windows::UI::Text::Core {

template <typename D> Windows::UI::Text::Core::CoreTextRange impl_ICoreTextTextRequest<D>::Range() const
{
    Windows::UI::Text::Core::CoreTextRange value {};
    check_hresult(WINRT_SHIM(ICoreTextTextRequest)->get_Range(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICoreTextTextRequest<D>::Text() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICoreTextTextRequest)->get_Text(put_abi(value)));
    return value;
}

template <typename D> void impl_ICoreTextTextRequest<D>::Text(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ICoreTextTextRequest)->put_Text(get_abi(value)));
}

template <typename D> bool impl_ICoreTextTextRequest<D>::IsCanceled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICoreTextTextRequest)->get_IsCanceled(&value));
    return value;
}

template <typename D> Windows::Foundation::Deferral impl_ICoreTextTextRequest<D>::GetDeferral() const
{
    Windows::Foundation::Deferral value { nullptr };
    check_hresult(WINRT_SHIM(ICoreTextTextRequest)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Text::Core::CoreTextTextRequest impl_ICoreTextTextRequestedEventArgs<D>::Request() const
{
    Windows::UI::Text::Core::CoreTextTextRequest value { nullptr };
    check_hresult(WINRT_SHIM(ICoreTextTextRequestedEventArgs)->get_Request(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Text::Core::CoreTextRange impl_ICoreTextSelectionRequest<D>::Selection() const
{
    Windows::UI::Text::Core::CoreTextRange value {};
    check_hresult(WINRT_SHIM(ICoreTextSelectionRequest)->get_Selection(put_abi(value)));
    return value;
}

template <typename D> void impl_ICoreTextSelectionRequest<D>::Selection(const Windows::UI::Text::Core::CoreTextRange & value) const
{
    check_hresult(WINRT_SHIM(ICoreTextSelectionRequest)->put_Selection(get_abi(value)));
}

template <typename D> bool impl_ICoreTextSelectionRequest<D>::IsCanceled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICoreTextSelectionRequest)->get_IsCanceled(&value));
    return value;
}

template <typename D> Windows::Foundation::Deferral impl_ICoreTextSelectionRequest<D>::GetDeferral() const
{
    Windows::Foundation::Deferral value { nullptr };
    check_hresult(WINRT_SHIM(ICoreTextSelectionRequest)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Text::Core::CoreTextSelectionRequest impl_ICoreTextSelectionRequestedEventArgs<D>::Request() const
{
    Windows::UI::Text::Core::CoreTextSelectionRequest value { nullptr };
    check_hresult(WINRT_SHIM(ICoreTextSelectionRequestedEventArgs)->get_Request(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Rect impl_ICoreTextLayoutBounds<D>::TextBounds() const
{
    Windows::Foundation::Rect value {};
    check_hresult(WINRT_SHIM(ICoreTextLayoutBounds)->get_TextBounds(put_abi(value)));
    return value;
}

template <typename D> void impl_ICoreTextLayoutBounds<D>::TextBounds(const Windows::Foundation::Rect & value) const
{
    check_hresult(WINRT_SHIM(ICoreTextLayoutBounds)->put_TextBounds(get_abi(value)));
}

template <typename D> Windows::Foundation::Rect impl_ICoreTextLayoutBounds<D>::ControlBounds() const
{
    Windows::Foundation::Rect value {};
    check_hresult(WINRT_SHIM(ICoreTextLayoutBounds)->get_ControlBounds(put_abi(value)));
    return value;
}

template <typename D> void impl_ICoreTextLayoutBounds<D>::ControlBounds(const Windows::Foundation::Rect & value) const
{
    check_hresult(WINRT_SHIM(ICoreTextLayoutBounds)->put_ControlBounds(get_abi(value)));
}

template <typename D> Windows::UI::Text::Core::CoreTextRange impl_ICoreTextLayoutRequest<D>::Range() const
{
    Windows::UI::Text::Core::CoreTextRange value {};
    check_hresult(WINRT_SHIM(ICoreTextLayoutRequest)->get_Range(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Text::Core::CoreTextLayoutBounds impl_ICoreTextLayoutRequest<D>::LayoutBounds() const
{
    Windows::UI::Text::Core::CoreTextLayoutBounds value { nullptr };
    check_hresult(WINRT_SHIM(ICoreTextLayoutRequest)->get_LayoutBounds(put_abi(value)));
    return value;
}

template <typename D> bool impl_ICoreTextLayoutRequest<D>::IsCanceled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICoreTextLayoutRequest)->get_IsCanceled(&value));
    return value;
}

template <typename D> Windows::Foundation::Deferral impl_ICoreTextLayoutRequest<D>::GetDeferral() const
{
    Windows::Foundation::Deferral value { nullptr };
    check_hresult(WINRT_SHIM(ICoreTextLayoutRequest)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Text::Core::CoreTextLayoutRequest impl_ICoreTextLayoutRequestedEventArgs<D>::Request() const
{
    Windows::UI::Text::Core::CoreTextLayoutRequest value { nullptr };
    check_hresult(WINRT_SHIM(ICoreTextLayoutRequestedEventArgs)->get_Request(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Text::Core::CoreTextRange impl_ICoreTextTextUpdatingEventArgs<D>::Range() const
{
    Windows::UI::Text::Core::CoreTextRange value {};
    check_hresult(WINRT_SHIM(ICoreTextTextUpdatingEventArgs)->get_Range(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICoreTextTextUpdatingEventArgs<D>::Text() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICoreTextTextUpdatingEventArgs)->get_Text(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Text::Core::CoreTextRange impl_ICoreTextTextUpdatingEventArgs<D>::NewSelection() const
{
    Windows::UI::Text::Core::CoreTextRange value {};
    check_hresult(WINRT_SHIM(ICoreTextTextUpdatingEventArgs)->get_NewSelection(put_abi(value)));
    return value;
}

template <typename D> Windows::Globalization::Language impl_ICoreTextTextUpdatingEventArgs<D>::InputLanguage() const
{
    Windows::Globalization::Language value { nullptr };
    check_hresult(WINRT_SHIM(ICoreTextTextUpdatingEventArgs)->get_InputLanguage(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Text::Core::CoreTextTextUpdatingResult impl_ICoreTextTextUpdatingEventArgs<D>::Result() const
{
    Windows::UI::Text::Core::CoreTextTextUpdatingResult value {};
    check_hresult(WINRT_SHIM(ICoreTextTextUpdatingEventArgs)->get_Result(&value));
    return value;
}

template <typename D> void impl_ICoreTextTextUpdatingEventArgs<D>::Result(Windows::UI::Text::Core::CoreTextTextUpdatingResult value) const
{
    check_hresult(WINRT_SHIM(ICoreTextTextUpdatingEventArgs)->put_Result(value));
}

template <typename D> bool impl_ICoreTextTextUpdatingEventArgs<D>::IsCanceled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICoreTextTextUpdatingEventArgs)->get_IsCanceled(&value));
    return value;
}

template <typename D> Windows::Foundation::Deferral impl_ICoreTextTextUpdatingEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral value { nullptr };
    check_hresult(WINRT_SHIM(ICoreTextTextUpdatingEventArgs)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Text::Core::CoreTextRange impl_ICoreTextSelectionUpdatingEventArgs<D>::Selection() const
{
    Windows::UI::Text::Core::CoreTextRange value {};
    check_hresult(WINRT_SHIM(ICoreTextSelectionUpdatingEventArgs)->get_Selection(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Text::Core::CoreTextSelectionUpdatingResult impl_ICoreTextSelectionUpdatingEventArgs<D>::Result() const
{
    Windows::UI::Text::Core::CoreTextSelectionUpdatingResult value {};
    check_hresult(WINRT_SHIM(ICoreTextSelectionUpdatingEventArgs)->get_Result(&value));
    return value;
}

template <typename D> void impl_ICoreTextSelectionUpdatingEventArgs<D>::Result(Windows::UI::Text::Core::CoreTextSelectionUpdatingResult value) const
{
    check_hresult(WINRT_SHIM(ICoreTextSelectionUpdatingEventArgs)->put_Result(value));
}

template <typename D> bool impl_ICoreTextSelectionUpdatingEventArgs<D>::IsCanceled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICoreTextSelectionUpdatingEventArgs)->get_IsCanceled(&value));
    return value;
}

template <typename D> Windows::Foundation::Deferral impl_ICoreTextSelectionUpdatingEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral value { nullptr };
    check_hresult(WINRT_SHIM(ICoreTextSelectionUpdatingEventArgs)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Text::Core::CoreTextRange impl_ICoreTextFormatUpdatingEventArgs<D>::Range() const
{
    Windows::UI::Text::Core::CoreTextRange value {};
    check_hresult(WINRT_SHIM(ICoreTextFormatUpdatingEventArgs)->get_Range(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<winrt::Windows::UI::ViewManagement::UIElementType> impl_ICoreTextFormatUpdatingEventArgs<D>::TextColor() const
{
    Windows::Foundation::IReference<winrt::Windows::UI::ViewManagement::UIElementType> value;
    check_hresult(WINRT_SHIM(ICoreTextFormatUpdatingEventArgs)->get_TextColor(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<winrt::Windows::UI::ViewManagement::UIElementType> impl_ICoreTextFormatUpdatingEventArgs<D>::BackgroundColor() const
{
    Windows::Foundation::IReference<winrt::Windows::UI::ViewManagement::UIElementType> value;
    check_hresult(WINRT_SHIM(ICoreTextFormatUpdatingEventArgs)->get_BackgroundColor(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<winrt::Windows::UI::ViewManagement::UIElementType> impl_ICoreTextFormatUpdatingEventArgs<D>::UnderlineColor() const
{
    Windows::Foundation::IReference<winrt::Windows::UI::ViewManagement::UIElementType> value;
    check_hresult(WINRT_SHIM(ICoreTextFormatUpdatingEventArgs)->get_UnderlineColor(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<winrt::Windows::UI::Text::UnderlineType> impl_ICoreTextFormatUpdatingEventArgs<D>::UnderlineType() const
{
    Windows::Foundation::IReference<winrt::Windows::UI::Text::UnderlineType> value;
    check_hresult(WINRT_SHIM(ICoreTextFormatUpdatingEventArgs)->get_UnderlineType(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Text::Core::CoreTextFormatUpdatingReason impl_ICoreTextFormatUpdatingEventArgs<D>::Reason() const
{
    Windows::UI::Text::Core::CoreTextFormatUpdatingReason value {};
    check_hresult(WINRT_SHIM(ICoreTextFormatUpdatingEventArgs)->get_Reason(&value));
    return value;
}

template <typename D> Windows::UI::Text::Core::CoreTextFormatUpdatingResult impl_ICoreTextFormatUpdatingEventArgs<D>::Result() const
{
    Windows::UI::Text::Core::CoreTextFormatUpdatingResult value {};
    check_hresult(WINRT_SHIM(ICoreTextFormatUpdatingEventArgs)->get_Result(&value));
    return value;
}

template <typename D> void impl_ICoreTextFormatUpdatingEventArgs<D>::Result(Windows::UI::Text::Core::CoreTextFormatUpdatingResult value) const
{
    check_hresult(WINRT_SHIM(ICoreTextFormatUpdatingEventArgs)->put_Result(value));
}

template <typename D> bool impl_ICoreTextFormatUpdatingEventArgs<D>::IsCanceled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICoreTextFormatUpdatingEventArgs)->get_IsCanceled(&value));
    return value;
}

template <typename D> Windows::Foundation::Deferral impl_ICoreTextFormatUpdatingEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral value { nullptr };
    check_hresult(WINRT_SHIM(ICoreTextFormatUpdatingEventArgs)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> bool impl_ICoreTextCompositionStartedEventArgs<D>::IsCanceled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICoreTextCompositionStartedEventArgs)->get_IsCanceled(&value));
    return value;
}

template <typename D> Windows::Foundation::Deferral impl_ICoreTextCompositionStartedEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral value { nullptr };
    check_hresult(WINRT_SHIM(ICoreTextCompositionStartedEventArgs)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> bool impl_ICoreTextCompositionCompletedEventArgs<D>::IsCanceled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICoreTextCompositionCompletedEventArgs)->get_IsCanceled(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::UI::Text::Core::CoreTextCompositionSegment> impl_ICoreTextCompositionCompletedEventArgs<D>::CompositionSegments() const
{
    Windows::Foundation::Collections::IVectorView<Windows::UI::Text::Core::CoreTextCompositionSegment> value;
    check_hresult(WINRT_SHIM(ICoreTextCompositionCompletedEventArgs)->get_CompositionSegments(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Deferral impl_ICoreTextCompositionCompletedEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral value { nullptr };
    check_hresult(WINRT_SHIM(ICoreTextCompositionCompletedEventArgs)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> event_token impl_ICoreTextEditContext2<D>::NotifyFocusLeaveCompleted(const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::Foundation::IInspectable> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICoreTextEditContext2)->add_NotifyFocusLeaveCompleted(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICoreTextEditContext2> impl_ICoreTextEditContext2<D>::NotifyFocusLeaveCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, ICoreTextEditContext2>(this, &ABI::Windows::UI::Text::Core::ICoreTextEditContext2::remove_NotifyFocusLeaveCompleted, NotifyFocusLeaveCompleted(handler));
}

template <typename D> void impl_ICoreTextEditContext2<D>::NotifyFocusLeaveCompleted(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreTextEditContext2)->remove_NotifyFocusLeaveCompleted(cookie));
}

template <typename D> hstring impl_ICoreTextEditContext<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICoreTextEditContext)->get_Name(put_abi(value)));
    return value;
}

template <typename D> void impl_ICoreTextEditContext<D>::Name(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ICoreTextEditContext)->put_Name(get_abi(value)));
}

template <typename D> Windows::UI::Text::Core::CoreTextInputScope impl_ICoreTextEditContext<D>::InputScope() const
{
    Windows::UI::Text::Core::CoreTextInputScope value {};
    check_hresult(WINRT_SHIM(ICoreTextEditContext)->get_InputScope(&value));
    return value;
}

template <typename D> void impl_ICoreTextEditContext<D>::InputScope(Windows::UI::Text::Core::CoreTextInputScope value) const
{
    check_hresult(WINRT_SHIM(ICoreTextEditContext)->put_InputScope(value));
}

template <typename D> bool impl_ICoreTextEditContext<D>::IsReadOnly() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICoreTextEditContext)->get_IsReadOnly(&value));
    return value;
}

template <typename D> void impl_ICoreTextEditContext<D>::IsReadOnly(bool value) const
{
    check_hresult(WINRT_SHIM(ICoreTextEditContext)->put_IsReadOnly(value));
}

template <typename D> Windows::UI::Text::Core::CoreTextInputPaneDisplayPolicy impl_ICoreTextEditContext<D>::InputPaneDisplayPolicy() const
{
    Windows::UI::Text::Core::CoreTextInputPaneDisplayPolicy value {};
    check_hresult(WINRT_SHIM(ICoreTextEditContext)->get_InputPaneDisplayPolicy(&value));
    return value;
}

template <typename D> void impl_ICoreTextEditContext<D>::InputPaneDisplayPolicy(Windows::UI::Text::Core::CoreTextInputPaneDisplayPolicy value) const
{
    check_hresult(WINRT_SHIM(ICoreTextEditContext)->put_InputPaneDisplayPolicy(value));
}

template <typename D> event_token impl_ICoreTextEditContext<D>::TextRequested(const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextTextRequestedEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICoreTextEditContext)->add_TextRequested(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICoreTextEditContext> impl_ICoreTextEditContext<D>::TextRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextTextRequestedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreTextEditContext>(this, &ABI::Windows::UI::Text::Core::ICoreTextEditContext::remove_TextRequested, TextRequested(handler));
}

template <typename D> void impl_ICoreTextEditContext<D>::TextRequested(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreTextEditContext)->remove_TextRequested(cookie));
}

template <typename D> event_token impl_ICoreTextEditContext<D>::SelectionRequested(const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextSelectionRequestedEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICoreTextEditContext)->add_SelectionRequested(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICoreTextEditContext> impl_ICoreTextEditContext<D>::SelectionRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextSelectionRequestedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreTextEditContext>(this, &ABI::Windows::UI::Text::Core::ICoreTextEditContext::remove_SelectionRequested, SelectionRequested(handler));
}

template <typename D> void impl_ICoreTextEditContext<D>::SelectionRequested(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreTextEditContext)->remove_SelectionRequested(cookie));
}

template <typename D> event_token impl_ICoreTextEditContext<D>::LayoutRequested(const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextLayoutRequestedEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICoreTextEditContext)->add_LayoutRequested(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICoreTextEditContext> impl_ICoreTextEditContext<D>::LayoutRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextLayoutRequestedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreTextEditContext>(this, &ABI::Windows::UI::Text::Core::ICoreTextEditContext::remove_LayoutRequested, LayoutRequested(handler));
}

template <typename D> void impl_ICoreTextEditContext<D>::LayoutRequested(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreTextEditContext)->remove_LayoutRequested(cookie));
}

template <typename D> event_token impl_ICoreTextEditContext<D>::TextUpdating(const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextTextUpdatingEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICoreTextEditContext)->add_TextUpdating(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICoreTextEditContext> impl_ICoreTextEditContext<D>::TextUpdating(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextTextUpdatingEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreTextEditContext>(this, &ABI::Windows::UI::Text::Core::ICoreTextEditContext::remove_TextUpdating, TextUpdating(handler));
}

template <typename D> void impl_ICoreTextEditContext<D>::TextUpdating(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreTextEditContext)->remove_TextUpdating(cookie));
}

template <typename D> event_token impl_ICoreTextEditContext<D>::SelectionUpdating(const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextSelectionUpdatingEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICoreTextEditContext)->add_SelectionUpdating(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICoreTextEditContext> impl_ICoreTextEditContext<D>::SelectionUpdating(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextSelectionUpdatingEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreTextEditContext>(this, &ABI::Windows::UI::Text::Core::ICoreTextEditContext::remove_SelectionUpdating, SelectionUpdating(handler));
}

template <typename D> void impl_ICoreTextEditContext<D>::SelectionUpdating(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreTextEditContext)->remove_SelectionUpdating(cookie));
}

template <typename D> event_token impl_ICoreTextEditContext<D>::FormatUpdating(const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextFormatUpdatingEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICoreTextEditContext)->add_FormatUpdating(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICoreTextEditContext> impl_ICoreTextEditContext<D>::FormatUpdating(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextFormatUpdatingEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreTextEditContext>(this, &ABI::Windows::UI::Text::Core::ICoreTextEditContext::remove_FormatUpdating, FormatUpdating(handler));
}

template <typename D> void impl_ICoreTextEditContext<D>::FormatUpdating(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreTextEditContext)->remove_FormatUpdating(cookie));
}

template <typename D> event_token impl_ICoreTextEditContext<D>::CompositionStarted(const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextCompositionStartedEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICoreTextEditContext)->add_CompositionStarted(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICoreTextEditContext> impl_ICoreTextEditContext<D>::CompositionStarted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextCompositionStartedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreTextEditContext>(this, &ABI::Windows::UI::Text::Core::ICoreTextEditContext::remove_CompositionStarted, CompositionStarted(handler));
}

template <typename D> void impl_ICoreTextEditContext<D>::CompositionStarted(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreTextEditContext)->remove_CompositionStarted(cookie));
}

template <typename D> event_token impl_ICoreTextEditContext<D>::CompositionCompleted(const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextCompositionCompletedEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICoreTextEditContext)->add_CompositionCompleted(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICoreTextEditContext> impl_ICoreTextEditContext<D>::CompositionCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextCompositionCompletedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreTextEditContext>(this, &ABI::Windows::UI::Text::Core::ICoreTextEditContext::remove_CompositionCompleted, CompositionCompleted(handler));
}

template <typename D> void impl_ICoreTextEditContext<D>::CompositionCompleted(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreTextEditContext)->remove_CompositionCompleted(cookie));
}

template <typename D> event_token impl_ICoreTextEditContext<D>::FocusRemoved(const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::Foundation::IInspectable> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICoreTextEditContext)->add_FocusRemoved(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICoreTextEditContext> impl_ICoreTextEditContext<D>::FocusRemoved(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, ICoreTextEditContext>(this, &ABI::Windows::UI::Text::Core::ICoreTextEditContext::remove_FocusRemoved, FocusRemoved(handler));
}

template <typename D> void impl_ICoreTextEditContext<D>::FocusRemoved(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreTextEditContext)->remove_FocusRemoved(cookie));
}

template <typename D> void impl_ICoreTextEditContext<D>::NotifyFocusEnter() const
{
    check_hresult(WINRT_SHIM(ICoreTextEditContext)->abi_NotifyFocusEnter());
}

template <typename D> void impl_ICoreTextEditContext<D>::NotifyFocusLeave() const
{
    check_hresult(WINRT_SHIM(ICoreTextEditContext)->abi_NotifyFocusLeave());
}

template <typename D> void impl_ICoreTextEditContext<D>::NotifyTextChanged(const Windows::UI::Text::Core::CoreTextRange & modifiedRange, int32_t newLength, const Windows::UI::Text::Core::CoreTextRange & newSelection) const
{
    check_hresult(WINRT_SHIM(ICoreTextEditContext)->abi_NotifyTextChanged(get_abi(modifiedRange), newLength, get_abi(newSelection)));
}

template <typename D> void impl_ICoreTextEditContext<D>::NotifySelectionChanged(const Windows::UI::Text::Core::CoreTextRange & selection) const
{
    check_hresult(WINRT_SHIM(ICoreTextEditContext)->abi_NotifySelectionChanged(get_abi(selection)));
}

template <typename D> void impl_ICoreTextEditContext<D>::NotifyLayoutChanged() const
{
    check_hresult(WINRT_SHIM(ICoreTextEditContext)->abi_NotifyLayoutChanged());
}

template <typename D> Windows::Globalization::Language impl_ICoreTextServicesManager<D>::InputLanguage() const
{
    Windows::Globalization::Language value { nullptr };
    check_hresult(WINRT_SHIM(ICoreTextServicesManager)->get_InputLanguage(put_abi(value)));
    return value;
}

template <typename D> event_token impl_ICoreTextServicesManager<D>::InputLanguageChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextServicesManager, Windows::Foundation::IInspectable> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICoreTextServicesManager)->add_InputLanguageChanged(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICoreTextServicesManager> impl_ICoreTextServicesManager<D>::InputLanguageChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextServicesManager, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, ICoreTextServicesManager>(this, &ABI::Windows::UI::Text::Core::ICoreTextServicesManager::remove_InputLanguageChanged, InputLanguageChanged(handler));
}

template <typename D> void impl_ICoreTextServicesManager<D>::InputLanguageChanged(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreTextServicesManager)->remove_InputLanguageChanged(cookie));
}

template <typename D> Windows::UI::Text::Core::CoreTextEditContext impl_ICoreTextServicesManager<D>::CreateEditContext() const
{
    Windows::UI::Text::Core::CoreTextEditContext value { nullptr };
    check_hresult(WINRT_SHIM(ICoreTextServicesManager)->abi_CreateEditContext(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Text::Core::CoreTextServicesManager impl_ICoreTextServicesManagerStatics<D>::GetForCurrentView() const
{
    Windows::UI::Text::Core::CoreTextServicesManager value { nullptr };
    check_hresult(WINRT_SHIM(ICoreTextServicesManagerStatics)->abi_GetForCurrentView(put_abi(value)));
    return value;
}

template <typename D> wchar_t impl_ICoreTextServicesStatics<D>::HiddenCharacter() const
{
    wchar_t value {};
    check_hresult(WINRT_SHIM(ICoreTextServicesStatics)->get_HiddenCharacter(&value));
    return value;
}

template <typename D> hstring impl_ICoreTextCompositionSegment<D>::PreconversionString() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICoreTextCompositionSegment)->get_PreconversionString(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Text::Core::CoreTextRange impl_ICoreTextCompositionSegment<D>::Range() const
{
    Windows::UI::Text::Core::CoreTextRange value {};
    check_hresult(WINRT_SHIM(ICoreTextCompositionSegment)->get_Range(put_abi(value)));
    return value;
}

inline wchar_t CoreTextServicesConstants::HiddenCharacter()
{
    return get_activation_factory<CoreTextServicesConstants, ICoreTextServicesStatics>().HiddenCharacter();
}

inline Windows::UI::Text::Core::CoreTextServicesManager CoreTextServicesManager::GetForCurrentView()
{
    return get_activation_factory<CoreTextServicesManager, ICoreTextServicesManagerStatics>().GetForCurrentView();
}

}

}
#pragma warning(pop)
