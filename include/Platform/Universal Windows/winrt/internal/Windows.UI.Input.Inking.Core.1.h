// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.UI.Input.Inking.Core.0.h"
#include "Windows.UI.Input.Inking.0.h"
#include "Windows.UI.Core.1.h"
#include "Windows.Foundation.1.h"
#include "Windows.UI.Input.Inking.1.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Input::Inking::Core {

struct __declspec(uuid("39b38da9-7639-4499-a5b5-191d00e35b16")) __declspec(novtable) ICoreInkIndependentInputSource : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_PointerEntering(Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_PointerEntering(event_token cookie) = 0;
    virtual HRESULT __stdcall add_PointerHovering(Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_PointerHovering(event_token cookie) = 0;
    virtual HRESULT __stdcall add_PointerExiting(Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_PointerExiting(event_token cookie) = 0;
    virtual HRESULT __stdcall add_PointerPressing(Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_PointerPressing(event_token cookie) = 0;
    virtual HRESULT __stdcall add_PointerMoving(Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_PointerMoving(event_token cookie) = 0;
    virtual HRESULT __stdcall add_PointerReleasing(Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_PointerReleasing(event_token cookie) = 0;
    virtual HRESULT __stdcall add_PointerLost(Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_PointerLost(event_token cookie) = 0;
    virtual HRESULT __stdcall get_InkPresenter(Windows::UI::Input::Inking::IInkPresenter ** value) = 0;
};

struct __declspec(uuid("73e6011b-80c0-4dfb-9b66-10ba7f3f9c84")) __declspec(novtable) ICoreInkIndependentInputSourceStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::UI::Input::Inking::IInkPresenter * inkPresenter, Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSource ** inkIndependentInputSource) = 0;
};

struct __declspec(uuid("fb07d14c-3380-457a-a987-991357896c1b")) __declspec(novtable) ICoreWetStrokeUpdateEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_NewInkPoints(Windows::Foundation::Collections::IVector<Windows::UI::Input::Inking::InkPoint> ** value) = 0;
    virtual HRESULT __stdcall get_PointerId(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_Disposition(winrt::Windows::UI::Input::Inking::Core::CoreWetStrokeDisposition * value) = 0;
    virtual HRESULT __stdcall put_Disposition(winrt::Windows::UI::Input::Inking::Core::CoreWetStrokeDisposition value) = 0;
};

struct __declspec(uuid("1f718e22-ee52-4e00-8209-4c3e5b21a3cc")) __declspec(novtable) ICoreWetStrokeUpdateSource : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_WetStrokeStarting(Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_WetStrokeStarting(event_token cookie) = 0;
    virtual HRESULT __stdcall add_WetStrokeContinuing(Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_WetStrokeContinuing(event_token cookie) = 0;
    virtual HRESULT __stdcall add_WetStrokeStopping(Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_WetStrokeStopping(event_token cookie) = 0;
    virtual HRESULT __stdcall add_WetStrokeCompleted(Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_WetStrokeCompleted(event_token cookie) = 0;
    virtual HRESULT __stdcall add_WetStrokeCanceled(Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_WetStrokeCanceled(event_token cookie) = 0;
    virtual HRESULT __stdcall get_InkPresenter(Windows::UI::Input::Inking::IInkPresenter ** value) = 0;
};

struct __declspec(uuid("3dad9cba-1d3d-46ae-ab9d-8647486c6f90")) __declspec(novtable) ICoreWetStrokeUpdateSourceStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::UI::Input::Inking::IInkPresenter * inkPresenter, Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource ** WetStrokeUpdateSource) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource> { using default_interface = Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSource; };
template <> struct traits<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> { using default_interface = Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateEventArgs; };
template <> struct traits<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource> { using default_interface = Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource; };

}

namespace Windows::UI::Input::Inking::Core {

template <typename D>
struct WINRT_EBO impl_ICoreInkIndependentInputSource
{
    event_token PointerEntering(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> & handler) const;
    using PointerEntering_revoker = event_revoker<ICoreInkIndependentInputSource>;
    PointerEntering_revoker PointerEntering(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> & handler) const;
    void PointerEntering(event_token cookie) const;
    event_token PointerHovering(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> & handler) const;
    using PointerHovering_revoker = event_revoker<ICoreInkIndependentInputSource>;
    PointerHovering_revoker PointerHovering(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> & handler) const;
    void PointerHovering(event_token cookie) const;
    event_token PointerExiting(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> & handler) const;
    using PointerExiting_revoker = event_revoker<ICoreInkIndependentInputSource>;
    PointerExiting_revoker PointerExiting(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> & handler) const;
    void PointerExiting(event_token cookie) const;
    event_token PointerPressing(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> & handler) const;
    using PointerPressing_revoker = event_revoker<ICoreInkIndependentInputSource>;
    PointerPressing_revoker PointerPressing(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> & handler) const;
    void PointerPressing(event_token cookie) const;
    event_token PointerMoving(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> & handler) const;
    using PointerMoving_revoker = event_revoker<ICoreInkIndependentInputSource>;
    PointerMoving_revoker PointerMoving(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> & handler) const;
    void PointerMoving(event_token cookie) const;
    event_token PointerReleasing(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> & handler) const;
    using PointerReleasing_revoker = event_revoker<ICoreInkIndependentInputSource>;
    PointerReleasing_revoker PointerReleasing(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> & handler) const;
    void PointerReleasing(event_token cookie) const;
    event_token PointerLost(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> & handler) const;
    using PointerLost_revoker = event_revoker<ICoreInkIndependentInputSource>;
    PointerLost_revoker PointerLost(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> & handler) const;
    void PointerLost(event_token cookie) const;
    Windows::UI::Input::Inking::InkPresenter InkPresenter() const;
};

template <typename D>
struct WINRT_EBO impl_ICoreInkIndependentInputSourceStatics
{
    Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource Create(const Windows::UI::Input::Inking::InkPresenter & inkPresenter) const;
};

template <typename D>
struct WINRT_EBO impl_ICoreWetStrokeUpdateEventArgs
{
    Windows::Foundation::Collections::IVector<Windows::UI::Input::Inking::InkPoint> NewInkPoints() const;
    uint32_t PointerId() const;
    Windows::UI::Input::Inking::Core::CoreWetStrokeDisposition Disposition() const;
    void Disposition(Windows::UI::Input::Inking::Core::CoreWetStrokeDisposition value) const;
};

template <typename D>
struct WINRT_EBO impl_ICoreWetStrokeUpdateSource
{
    event_token WetStrokeStarting(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> & handler) const;
    using WetStrokeStarting_revoker = event_revoker<ICoreWetStrokeUpdateSource>;
    WetStrokeStarting_revoker WetStrokeStarting(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> & handler) const;
    void WetStrokeStarting(event_token cookie) const;
    event_token WetStrokeContinuing(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> & handler) const;
    using WetStrokeContinuing_revoker = event_revoker<ICoreWetStrokeUpdateSource>;
    WetStrokeContinuing_revoker WetStrokeContinuing(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> & handler) const;
    void WetStrokeContinuing(event_token cookie) const;
    event_token WetStrokeStopping(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> & handler) const;
    using WetStrokeStopping_revoker = event_revoker<ICoreWetStrokeUpdateSource>;
    WetStrokeStopping_revoker WetStrokeStopping(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> & handler) const;
    void WetStrokeStopping(event_token cookie) const;
    event_token WetStrokeCompleted(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> & handler) const;
    using WetStrokeCompleted_revoker = event_revoker<ICoreWetStrokeUpdateSource>;
    WetStrokeCompleted_revoker WetStrokeCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> & handler) const;
    void WetStrokeCompleted(event_token cookie) const;
    event_token WetStrokeCanceled(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> & handler) const;
    using WetStrokeCanceled_revoker = event_revoker<ICoreWetStrokeUpdateSource>;
    WetStrokeCanceled_revoker WetStrokeCanceled(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> & handler) const;
    void WetStrokeCanceled(event_token cookie) const;
    Windows::UI::Input::Inking::InkPresenter InkPresenter() const;
};

template <typename D>
struct WINRT_EBO impl_ICoreWetStrokeUpdateSourceStatics
{
    Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource Create(const Windows::UI::Input::Inking::InkPresenter & inkPresenter) const;
};

}

namespace impl {

template <> struct traits<Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSource>
{
    using abi = ABI::Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSource;
    template <typename D> using consume = Windows::UI::Input::Inking::Core::impl_ICoreInkIndependentInputSource<D>;
};

template <> struct traits<Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSourceStatics>
{
    using abi = ABI::Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSourceStatics;
    template <typename D> using consume = Windows::UI::Input::Inking::Core::impl_ICoreInkIndependentInputSourceStatics<D>;
};

template <> struct traits<Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateEventArgs>
{
    using abi = ABI::Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateEventArgs;
    template <typename D> using consume = Windows::UI::Input::Inking::Core::impl_ICoreWetStrokeUpdateEventArgs<D>;
};

template <> struct traits<Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource>
{
    using abi = ABI::Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource;
    template <typename D> using consume = Windows::UI::Input::Inking::Core::impl_ICoreWetStrokeUpdateSource<D>;
};

template <> struct traits<Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateSourceStatics>
{
    using abi = ABI::Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateSourceStatics;
    template <typename D> using consume = Windows::UI::Input::Inking::Core::impl_ICoreWetStrokeUpdateSourceStatics<D>;
};

template <> struct traits<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource>
{
    using abi = ABI::Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Input.Inking.Core.CoreInkIndependentInputSource"; }
};

template <> struct traits<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs>
{
    using abi = ABI::Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Input.Inking.Core.CoreWetStrokeUpdateEventArgs"; }
};

template <> struct traits<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource>
{
    using abi = ABI::Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Input.Inking.Core.CoreWetStrokeUpdateSource"; }
};

}

}
