// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.UI.Text.Core.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Globalization.0.h"
#include "Windows.UI.ViewManagement.1.h"
#include "Windows.Foundation.1.h"
#include "Windows.UI.Text.1.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Text::Core {

struct CoreTextRange
{
    int32_t StartCaretPosition;
    int32_t EndCaretPosition;
};

}

namespace Windows::UI::Text::Core {

using CoreTextRange = ABI::Windows::UI::Text::Core::CoreTextRange;

}

namespace ABI::Windows::UI::Text::Core {

struct __declspec(uuid("1f34ebb6-b79f-4121-a5e7-fda9b8616e30")) __declspec(novtable) ICoreTextCompositionCompletedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsCanceled(bool * value) = 0;
    virtual HRESULT __stdcall get_CompositionSegments(Windows::Foundation::Collections::IVectorView<Windows::UI::Text::Core::CoreTextCompositionSegment> ** value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("776c6bd9-4ead-4da7-8f47-3a88b523cc34")) __declspec(novtable) ICoreTextCompositionSegment : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PreconversionString(hstring * value) = 0;
    virtual HRESULT __stdcall get_Range(Windows::UI::Text::Core::CoreTextRange * value) = 0;
};

struct __declspec(uuid("276b16a9-64e7-4ab0-bc4b-a02d73835bfb")) __declspec(novtable) ICoreTextCompositionStartedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsCanceled(bool * value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("bf6608af-4041-47c3-b263-a918eb5eaef2")) __declspec(novtable) ICoreTextEditContext : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall put_Name(hstring value) = 0;
    virtual HRESULT __stdcall get_InputScope(winrt::Windows::UI::Text::Core::CoreTextInputScope * value) = 0;
    virtual HRESULT __stdcall put_InputScope(winrt::Windows::UI::Text::Core::CoreTextInputScope value) = 0;
    virtual HRESULT __stdcall get_IsReadOnly(bool * value) = 0;
    virtual HRESULT __stdcall put_IsReadOnly(bool value) = 0;
    virtual HRESULT __stdcall get_InputPaneDisplayPolicy(winrt::Windows::UI::Text::Core::CoreTextInputPaneDisplayPolicy * value) = 0;
    virtual HRESULT __stdcall put_InputPaneDisplayPolicy(winrt::Windows::UI::Text::Core::CoreTextInputPaneDisplayPolicy value) = 0;
    virtual HRESULT __stdcall add_TextRequested(Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextTextRequestedEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_TextRequested(event_token cookie) = 0;
    virtual HRESULT __stdcall add_SelectionRequested(Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextSelectionRequestedEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_SelectionRequested(event_token cookie) = 0;
    virtual HRESULT __stdcall add_LayoutRequested(Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextLayoutRequestedEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_LayoutRequested(event_token cookie) = 0;
    virtual HRESULT __stdcall add_TextUpdating(Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextTextUpdatingEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_TextUpdating(event_token cookie) = 0;
    virtual HRESULT __stdcall add_SelectionUpdating(Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextSelectionUpdatingEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_SelectionUpdating(event_token cookie) = 0;
    virtual HRESULT __stdcall add_FormatUpdating(Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextFormatUpdatingEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_FormatUpdating(event_token cookie) = 0;
    virtual HRESULT __stdcall add_CompositionStarted(Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextCompositionStartedEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_CompositionStarted(event_token cookie) = 0;
    virtual HRESULT __stdcall add_CompositionCompleted(Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextCompositionCompletedEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_CompositionCompleted(event_token cookie) = 0;
    virtual HRESULT __stdcall add_FocusRemoved(Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::Foundation::IInspectable> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_FocusRemoved(event_token cookie) = 0;
    virtual HRESULT __stdcall abi_NotifyFocusEnter() = 0;
    virtual HRESULT __stdcall abi_NotifyFocusLeave() = 0;
    virtual HRESULT __stdcall abi_NotifyTextChanged(Windows::UI::Text::Core::CoreTextRange modifiedRange, int32_t newLength, Windows::UI::Text::Core::CoreTextRange newSelection) = 0;
    virtual HRESULT __stdcall abi_NotifySelectionChanged(Windows::UI::Text::Core::CoreTextRange selection) = 0;
    virtual HRESULT __stdcall abi_NotifyLayoutChanged() = 0;
};

struct __declspec(uuid("b1867dbb-083b-49e1-b281-2b35d62bf466")) __declspec(novtable) ICoreTextEditContext2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_NotifyFocusLeaveCompleted(Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::Foundation::IInspectable> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_NotifyFocusLeaveCompleted(event_token cookie) = 0;
};

struct __declspec(uuid("7310bd33-b4a8-43b1-b37b-0724d4aca7ab")) __declspec(novtable) ICoreTextFormatUpdatingEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Range(Windows::UI::Text::Core::CoreTextRange * value) = 0;
    virtual HRESULT __stdcall get_TextColor(Windows::Foundation::IReference<winrt::Windows::UI::ViewManagement::UIElementType> ** value) = 0;
    virtual HRESULT __stdcall get_BackgroundColor(Windows::Foundation::IReference<winrt::Windows::UI::ViewManagement::UIElementType> ** value) = 0;
    virtual HRESULT __stdcall get_UnderlineColor(Windows::Foundation::IReference<winrt::Windows::UI::ViewManagement::UIElementType> ** value) = 0;
    virtual HRESULT __stdcall get_UnderlineType(Windows::Foundation::IReference<winrt::Windows::UI::Text::UnderlineType> ** value) = 0;
    virtual HRESULT __stdcall get_Reason(winrt::Windows::UI::Text::Core::CoreTextFormatUpdatingReason * value) = 0;
    virtual HRESULT __stdcall get_Result(winrt::Windows::UI::Text::Core::CoreTextFormatUpdatingResult * value) = 0;
    virtual HRESULT __stdcall put_Result(winrt::Windows::UI::Text::Core::CoreTextFormatUpdatingResult value) = 0;
    virtual HRESULT __stdcall get_IsCanceled(bool * value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("e972c974-4436-4917-80d0-a525e4ca6780")) __declspec(novtable) ICoreTextLayoutBounds : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TextBounds(Windows::Foundation::Rect * value) = 0;
    virtual HRESULT __stdcall put_TextBounds(Windows::Foundation::Rect value) = 0;
    virtual HRESULT __stdcall get_ControlBounds(Windows::Foundation::Rect * value) = 0;
    virtual HRESULT __stdcall put_ControlBounds(Windows::Foundation::Rect value) = 0;
};

struct __declspec(uuid("2555a8cc-51fd-4f03-98bf-ac78174d68e0")) __declspec(novtable) ICoreTextLayoutRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Range(Windows::UI::Text::Core::CoreTextRange * value) = 0;
    virtual HRESULT __stdcall get_LayoutBounds(Windows::UI::Text::Core::ICoreTextLayoutBounds ** value) = 0;
    virtual HRESULT __stdcall get_IsCanceled(bool * value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("b1dc6ae0-9a7b-4e9e-a566-4a6b5f8ad676")) __declspec(novtable) ICoreTextLayoutRequestedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Request(Windows::UI::Text::Core::ICoreTextLayoutRequest ** value) = 0;
};

struct __declspec(uuid("f0a70403-208b-4301-883c-74ca7485fd8d")) __declspec(novtable) ICoreTextSelectionRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Selection(Windows::UI::Text::Core::CoreTextRange * value) = 0;
    virtual HRESULT __stdcall put_Selection(Windows::UI::Text::Core::CoreTextRange value) = 0;
    virtual HRESULT __stdcall get_IsCanceled(bool * value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("13c6682b-f614-421a-8f4b-9ec8a5a37fcd")) __declspec(novtable) ICoreTextSelectionRequestedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Request(Windows::UI::Text::Core::ICoreTextSelectionRequest ** value) = 0;
};

struct __declspec(uuid("d445839f-fe7f-4bd5-8a26-0922c1b3e639")) __declspec(novtable) ICoreTextSelectionUpdatingEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Selection(Windows::UI::Text::Core::CoreTextRange * value) = 0;
    virtual HRESULT __stdcall get_Result(winrt::Windows::UI::Text::Core::CoreTextSelectionUpdatingResult * value) = 0;
    virtual HRESULT __stdcall put_Result(winrt::Windows::UI::Text::Core::CoreTextSelectionUpdatingResult value) = 0;
    virtual HRESULT __stdcall get_IsCanceled(bool * value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("c2507d83-6e0a-4a8a-bdf8-1948874854ba")) __declspec(novtable) ICoreTextServicesManager : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_InputLanguage(Windows::Globalization::ILanguage ** value) = 0;
    virtual HRESULT __stdcall add_InputLanguageChanged(Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextServicesManager, Windows::Foundation::IInspectable> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_InputLanguageChanged(event_token cookie) = 0;
    virtual HRESULT __stdcall abi_CreateEditContext(Windows::UI::Text::Core::ICoreTextEditContext ** value) = 0;
};

struct __declspec(uuid("1520a388-e2cf-4d65-aeb9-b32d86fe39b9")) __declspec(novtable) ICoreTextServicesManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetForCurrentView(Windows::UI::Text::Core::ICoreTextServicesManager ** value) = 0;
};

struct __declspec(uuid("91859a46-eccf-47a4-8ae7-098a9c6fbb15")) __declspec(novtable) ICoreTextServicesStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_HiddenCharacter(wchar_t * value) = 0;
};

struct __declspec(uuid("50d950a9-f51e-4cc1-8ca1-e6346d1a61be")) __declspec(novtable) ICoreTextTextRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Range(Windows::UI::Text::Core::CoreTextRange * value) = 0;
    virtual HRESULT __stdcall get_Text(hstring * value) = 0;
    virtual HRESULT __stdcall put_Text(hstring value) = 0;
    virtual HRESULT __stdcall get_IsCanceled(bool * value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("f096a2d0-41c6-4c02-8b1a-d953b00cabb3")) __declspec(novtable) ICoreTextTextRequestedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Request(Windows::UI::Text::Core::ICoreTextTextRequest ** value) = 0;
};

struct __declspec(uuid("eea7918d-cc2b-4f03-8ff6-02fd217db450")) __declspec(novtable) ICoreTextTextUpdatingEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Range(Windows::UI::Text::Core::CoreTextRange * value) = 0;
    virtual HRESULT __stdcall get_Text(hstring * value) = 0;
    virtual HRESULT __stdcall get_NewSelection(Windows::UI::Text::Core::CoreTextRange * value) = 0;
    virtual HRESULT __stdcall get_InputLanguage(Windows::Globalization::ILanguage ** value) = 0;
    virtual HRESULT __stdcall get_Result(winrt::Windows::UI::Text::Core::CoreTextTextUpdatingResult * value) = 0;
    virtual HRESULT __stdcall put_Result(winrt::Windows::UI::Text::Core::CoreTextTextUpdatingResult value) = 0;
    virtual HRESULT __stdcall get_IsCanceled(bool * value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::UI::Text::Core::CoreTextCompositionCompletedEventArgs> { using default_interface = Windows::UI::Text::Core::ICoreTextCompositionCompletedEventArgs; };
template <> struct traits<Windows::UI::Text::Core::CoreTextCompositionSegment> { using default_interface = Windows::UI::Text::Core::ICoreTextCompositionSegment; };
template <> struct traits<Windows::UI::Text::Core::CoreTextCompositionStartedEventArgs> { using default_interface = Windows::UI::Text::Core::ICoreTextCompositionStartedEventArgs; };
template <> struct traits<Windows::UI::Text::Core::CoreTextEditContext> { using default_interface = Windows::UI::Text::Core::ICoreTextEditContext; };
template <> struct traits<Windows::UI::Text::Core::CoreTextFormatUpdatingEventArgs> { using default_interface = Windows::UI::Text::Core::ICoreTextFormatUpdatingEventArgs; };
template <> struct traits<Windows::UI::Text::Core::CoreTextLayoutBounds> { using default_interface = Windows::UI::Text::Core::ICoreTextLayoutBounds; };
template <> struct traits<Windows::UI::Text::Core::CoreTextLayoutRequest> { using default_interface = Windows::UI::Text::Core::ICoreTextLayoutRequest; };
template <> struct traits<Windows::UI::Text::Core::CoreTextLayoutRequestedEventArgs> { using default_interface = Windows::UI::Text::Core::ICoreTextLayoutRequestedEventArgs; };
template <> struct traits<Windows::UI::Text::Core::CoreTextSelectionRequest> { using default_interface = Windows::UI::Text::Core::ICoreTextSelectionRequest; };
template <> struct traits<Windows::UI::Text::Core::CoreTextSelectionRequestedEventArgs> { using default_interface = Windows::UI::Text::Core::ICoreTextSelectionRequestedEventArgs; };
template <> struct traits<Windows::UI::Text::Core::CoreTextSelectionUpdatingEventArgs> { using default_interface = Windows::UI::Text::Core::ICoreTextSelectionUpdatingEventArgs; };
template <> struct traits<Windows::UI::Text::Core::CoreTextServicesManager> { using default_interface = Windows::UI::Text::Core::ICoreTextServicesManager; };
template <> struct traits<Windows::UI::Text::Core::CoreTextTextRequest> { using default_interface = Windows::UI::Text::Core::ICoreTextTextRequest; };
template <> struct traits<Windows::UI::Text::Core::CoreTextTextRequestedEventArgs> { using default_interface = Windows::UI::Text::Core::ICoreTextTextRequestedEventArgs; };
template <> struct traits<Windows::UI::Text::Core::CoreTextTextUpdatingEventArgs> { using default_interface = Windows::UI::Text::Core::ICoreTextTextUpdatingEventArgs; };

}

namespace Windows::UI::Text::Core {

template <typename D>
struct WINRT_EBO impl_ICoreTextCompositionCompletedEventArgs
{
    bool IsCanceled() const;
    Windows::Foundation::Collections::IVectorView<Windows::UI::Text::Core::CoreTextCompositionSegment> CompositionSegments() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_ICoreTextCompositionSegment
{
    hstring PreconversionString() const;
    Windows::UI::Text::Core::CoreTextRange Range() const;
};

template <typename D>
struct WINRT_EBO impl_ICoreTextCompositionStartedEventArgs
{
    bool IsCanceled() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_ICoreTextEditContext
{
    hstring Name() const;
    void Name(hstring_view value) const;
    Windows::UI::Text::Core::CoreTextInputScope InputScope() const;
    void InputScope(Windows::UI::Text::Core::CoreTextInputScope value) const;
    bool IsReadOnly() const;
    void IsReadOnly(bool value) const;
    Windows::UI::Text::Core::CoreTextInputPaneDisplayPolicy InputPaneDisplayPolicy() const;
    void InputPaneDisplayPolicy(Windows::UI::Text::Core::CoreTextInputPaneDisplayPolicy value) const;
    event_token TextRequested(const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextTextRequestedEventArgs> & handler) const;
    using TextRequested_revoker = event_revoker<ICoreTextEditContext>;
    TextRequested_revoker TextRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextTextRequestedEventArgs> & handler) const;
    void TextRequested(event_token cookie) const;
    event_token SelectionRequested(const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextSelectionRequestedEventArgs> & handler) const;
    using SelectionRequested_revoker = event_revoker<ICoreTextEditContext>;
    SelectionRequested_revoker SelectionRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextSelectionRequestedEventArgs> & handler) const;
    void SelectionRequested(event_token cookie) const;
    event_token LayoutRequested(const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextLayoutRequestedEventArgs> & handler) const;
    using LayoutRequested_revoker = event_revoker<ICoreTextEditContext>;
    LayoutRequested_revoker LayoutRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextLayoutRequestedEventArgs> & handler) const;
    void LayoutRequested(event_token cookie) const;
    event_token TextUpdating(const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextTextUpdatingEventArgs> & handler) const;
    using TextUpdating_revoker = event_revoker<ICoreTextEditContext>;
    TextUpdating_revoker TextUpdating(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextTextUpdatingEventArgs> & handler) const;
    void TextUpdating(event_token cookie) const;
    event_token SelectionUpdating(const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextSelectionUpdatingEventArgs> & handler) const;
    using SelectionUpdating_revoker = event_revoker<ICoreTextEditContext>;
    SelectionUpdating_revoker SelectionUpdating(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextSelectionUpdatingEventArgs> & handler) const;
    void SelectionUpdating(event_token cookie) const;
    event_token FormatUpdating(const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextFormatUpdatingEventArgs> & handler) const;
    using FormatUpdating_revoker = event_revoker<ICoreTextEditContext>;
    FormatUpdating_revoker FormatUpdating(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextFormatUpdatingEventArgs> & handler) const;
    void FormatUpdating(event_token cookie) const;
    event_token CompositionStarted(const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextCompositionStartedEventArgs> & handler) const;
    using CompositionStarted_revoker = event_revoker<ICoreTextEditContext>;
    CompositionStarted_revoker CompositionStarted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextCompositionStartedEventArgs> & handler) const;
    void CompositionStarted(event_token cookie) const;
    event_token CompositionCompleted(const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextCompositionCompletedEventArgs> & handler) const;
    using CompositionCompleted_revoker = event_revoker<ICoreTextEditContext>;
    CompositionCompleted_revoker CompositionCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::UI::Text::Core::CoreTextCompositionCompletedEventArgs> & handler) const;
    void CompositionCompleted(event_token cookie) const;
    event_token FocusRemoved(const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::Foundation::IInspectable> & handler) const;
    using FocusRemoved_revoker = event_revoker<ICoreTextEditContext>;
    FocusRemoved_revoker FocusRemoved(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::Foundation::IInspectable> & handler) const;
    void FocusRemoved(event_token cookie) const;
    void NotifyFocusEnter() const;
    void NotifyFocusLeave() const;
    void NotifyTextChanged(const Windows::UI::Text::Core::CoreTextRange & modifiedRange, int32_t newLength, const Windows::UI::Text::Core::CoreTextRange & newSelection) const;
    void NotifySelectionChanged(const Windows::UI::Text::Core::CoreTextRange & selection) const;
    void NotifyLayoutChanged() const;
};

template <typename D>
struct WINRT_EBO impl_ICoreTextEditContext2
{
    event_token NotifyFocusLeaveCompleted(const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::Foundation::IInspectable> & handler) const;
    using NotifyFocusLeaveCompleted_revoker = event_revoker<ICoreTextEditContext2>;
    NotifyFocusLeaveCompleted_revoker NotifyFocusLeaveCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextEditContext, Windows::Foundation::IInspectable> & handler) const;
    void NotifyFocusLeaveCompleted(event_token cookie) const;
};

template <typename D>
struct WINRT_EBO impl_ICoreTextFormatUpdatingEventArgs
{
    Windows::UI::Text::Core::CoreTextRange Range() const;
    Windows::Foundation::IReference<winrt::Windows::UI::ViewManagement::UIElementType> TextColor() const;
    Windows::Foundation::IReference<winrt::Windows::UI::ViewManagement::UIElementType> BackgroundColor() const;
    Windows::Foundation::IReference<winrt::Windows::UI::ViewManagement::UIElementType> UnderlineColor() const;
    Windows::Foundation::IReference<winrt::Windows::UI::Text::UnderlineType> UnderlineType() const;
    Windows::UI::Text::Core::CoreTextFormatUpdatingReason Reason() const;
    Windows::UI::Text::Core::CoreTextFormatUpdatingResult Result() const;
    void Result(Windows::UI::Text::Core::CoreTextFormatUpdatingResult value) const;
    bool IsCanceled() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_ICoreTextLayoutBounds
{
    Windows::Foundation::Rect TextBounds() const;
    void TextBounds(const Windows::Foundation::Rect & value) const;
    Windows::Foundation::Rect ControlBounds() const;
    void ControlBounds(const Windows::Foundation::Rect & value) const;
};

template <typename D>
struct WINRT_EBO impl_ICoreTextLayoutRequest
{
    Windows::UI::Text::Core::CoreTextRange Range() const;
    Windows::UI::Text::Core::CoreTextLayoutBounds LayoutBounds() const;
    bool IsCanceled() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_ICoreTextLayoutRequestedEventArgs
{
    Windows::UI::Text::Core::CoreTextLayoutRequest Request() const;
};

template <typename D>
struct WINRT_EBO impl_ICoreTextSelectionRequest
{
    Windows::UI::Text::Core::CoreTextRange Selection() const;
    void Selection(const Windows::UI::Text::Core::CoreTextRange & value) const;
    bool IsCanceled() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_ICoreTextSelectionRequestedEventArgs
{
    Windows::UI::Text::Core::CoreTextSelectionRequest Request() const;
};

template <typename D>
struct WINRT_EBO impl_ICoreTextSelectionUpdatingEventArgs
{
    Windows::UI::Text::Core::CoreTextRange Selection() const;
    Windows::UI::Text::Core::CoreTextSelectionUpdatingResult Result() const;
    void Result(Windows::UI::Text::Core::CoreTextSelectionUpdatingResult value) const;
    bool IsCanceled() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_ICoreTextServicesManager
{
    Windows::Globalization::Language InputLanguage() const;
    event_token InputLanguageChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextServicesManager, Windows::Foundation::IInspectable> & handler) const;
    using InputLanguageChanged_revoker = event_revoker<ICoreTextServicesManager>;
    InputLanguageChanged_revoker InputLanguageChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Text::Core::CoreTextServicesManager, Windows::Foundation::IInspectable> & handler) const;
    void InputLanguageChanged(event_token cookie) const;
    Windows::UI::Text::Core::CoreTextEditContext CreateEditContext() const;
};

template <typename D>
struct WINRT_EBO impl_ICoreTextServicesManagerStatics
{
    Windows::UI::Text::Core::CoreTextServicesManager GetForCurrentView() const;
};

template <typename D>
struct WINRT_EBO impl_ICoreTextServicesStatics
{
    wchar_t HiddenCharacter() const;
};

template <typename D>
struct WINRT_EBO impl_ICoreTextTextRequest
{
    Windows::UI::Text::Core::CoreTextRange Range() const;
    hstring Text() const;
    void Text(hstring_view value) const;
    bool IsCanceled() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_ICoreTextTextRequestedEventArgs
{
    Windows::UI::Text::Core::CoreTextTextRequest Request() const;
};

template <typename D>
struct WINRT_EBO impl_ICoreTextTextUpdatingEventArgs
{
    Windows::UI::Text::Core::CoreTextRange Range() const;
    hstring Text() const;
    Windows::UI::Text::Core::CoreTextRange NewSelection() const;
    Windows::Globalization::Language InputLanguage() const;
    Windows::UI::Text::Core::CoreTextTextUpdatingResult Result() const;
    void Result(Windows::UI::Text::Core::CoreTextTextUpdatingResult value) const;
    bool IsCanceled() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

}

namespace impl {

template <> struct traits<Windows::UI::Text::Core::ICoreTextCompositionCompletedEventArgs>
{
    using abi = ABI::Windows::UI::Text::Core::ICoreTextCompositionCompletedEventArgs;
    template <typename D> using consume = Windows::UI::Text::Core::impl_ICoreTextCompositionCompletedEventArgs<D>;
};

template <> struct traits<Windows::UI::Text::Core::ICoreTextCompositionSegment>
{
    using abi = ABI::Windows::UI::Text::Core::ICoreTextCompositionSegment;
    template <typename D> using consume = Windows::UI::Text::Core::impl_ICoreTextCompositionSegment<D>;
};

template <> struct traits<Windows::UI::Text::Core::ICoreTextCompositionStartedEventArgs>
{
    using abi = ABI::Windows::UI::Text::Core::ICoreTextCompositionStartedEventArgs;
    template <typename D> using consume = Windows::UI::Text::Core::impl_ICoreTextCompositionStartedEventArgs<D>;
};

template <> struct traits<Windows::UI::Text::Core::ICoreTextEditContext>
{
    using abi = ABI::Windows::UI::Text::Core::ICoreTextEditContext;
    template <typename D> using consume = Windows::UI::Text::Core::impl_ICoreTextEditContext<D>;
};

template <> struct traits<Windows::UI::Text::Core::ICoreTextEditContext2>
{
    using abi = ABI::Windows::UI::Text::Core::ICoreTextEditContext2;
    template <typename D> using consume = Windows::UI::Text::Core::impl_ICoreTextEditContext2<D>;
};

template <> struct traits<Windows::UI::Text::Core::ICoreTextFormatUpdatingEventArgs>
{
    using abi = ABI::Windows::UI::Text::Core::ICoreTextFormatUpdatingEventArgs;
    template <typename D> using consume = Windows::UI::Text::Core::impl_ICoreTextFormatUpdatingEventArgs<D>;
};

template <> struct traits<Windows::UI::Text::Core::ICoreTextLayoutBounds>
{
    using abi = ABI::Windows::UI::Text::Core::ICoreTextLayoutBounds;
    template <typename D> using consume = Windows::UI::Text::Core::impl_ICoreTextLayoutBounds<D>;
};

template <> struct traits<Windows::UI::Text::Core::ICoreTextLayoutRequest>
{
    using abi = ABI::Windows::UI::Text::Core::ICoreTextLayoutRequest;
    template <typename D> using consume = Windows::UI::Text::Core::impl_ICoreTextLayoutRequest<D>;
};

template <> struct traits<Windows::UI::Text::Core::ICoreTextLayoutRequestedEventArgs>
{
    using abi = ABI::Windows::UI::Text::Core::ICoreTextLayoutRequestedEventArgs;
    template <typename D> using consume = Windows::UI::Text::Core::impl_ICoreTextLayoutRequestedEventArgs<D>;
};

template <> struct traits<Windows::UI::Text::Core::ICoreTextSelectionRequest>
{
    using abi = ABI::Windows::UI::Text::Core::ICoreTextSelectionRequest;
    template <typename D> using consume = Windows::UI::Text::Core::impl_ICoreTextSelectionRequest<D>;
};

template <> struct traits<Windows::UI::Text::Core::ICoreTextSelectionRequestedEventArgs>
{
    using abi = ABI::Windows::UI::Text::Core::ICoreTextSelectionRequestedEventArgs;
    template <typename D> using consume = Windows::UI::Text::Core::impl_ICoreTextSelectionRequestedEventArgs<D>;
};

template <> struct traits<Windows::UI::Text::Core::ICoreTextSelectionUpdatingEventArgs>
{
    using abi = ABI::Windows::UI::Text::Core::ICoreTextSelectionUpdatingEventArgs;
    template <typename D> using consume = Windows::UI::Text::Core::impl_ICoreTextSelectionUpdatingEventArgs<D>;
};

template <> struct traits<Windows::UI::Text::Core::ICoreTextServicesManager>
{
    using abi = ABI::Windows::UI::Text::Core::ICoreTextServicesManager;
    template <typename D> using consume = Windows::UI::Text::Core::impl_ICoreTextServicesManager<D>;
};

template <> struct traits<Windows::UI::Text::Core::ICoreTextServicesManagerStatics>
{
    using abi = ABI::Windows::UI::Text::Core::ICoreTextServicesManagerStatics;
    template <typename D> using consume = Windows::UI::Text::Core::impl_ICoreTextServicesManagerStatics<D>;
};

template <> struct traits<Windows::UI::Text::Core::ICoreTextServicesStatics>
{
    using abi = ABI::Windows::UI::Text::Core::ICoreTextServicesStatics;
    template <typename D> using consume = Windows::UI::Text::Core::impl_ICoreTextServicesStatics<D>;
};

template <> struct traits<Windows::UI::Text::Core::ICoreTextTextRequest>
{
    using abi = ABI::Windows::UI::Text::Core::ICoreTextTextRequest;
    template <typename D> using consume = Windows::UI::Text::Core::impl_ICoreTextTextRequest<D>;
};

template <> struct traits<Windows::UI::Text::Core::ICoreTextTextRequestedEventArgs>
{
    using abi = ABI::Windows::UI::Text::Core::ICoreTextTextRequestedEventArgs;
    template <typename D> using consume = Windows::UI::Text::Core::impl_ICoreTextTextRequestedEventArgs<D>;
};

template <> struct traits<Windows::UI::Text::Core::ICoreTextTextUpdatingEventArgs>
{
    using abi = ABI::Windows::UI::Text::Core::ICoreTextTextUpdatingEventArgs;
    template <typename D> using consume = Windows::UI::Text::Core::impl_ICoreTextTextUpdatingEventArgs<D>;
};

template <> struct traits<Windows::UI::Text::Core::CoreTextCompositionCompletedEventArgs>
{
    using abi = ABI::Windows::UI::Text::Core::CoreTextCompositionCompletedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Text.Core.CoreTextCompositionCompletedEventArgs"; }
};

template <> struct traits<Windows::UI::Text::Core::CoreTextCompositionSegment>
{
    using abi = ABI::Windows::UI::Text::Core::CoreTextCompositionSegment;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Text.Core.CoreTextCompositionSegment"; }
};

template <> struct traits<Windows::UI::Text::Core::CoreTextCompositionStartedEventArgs>
{
    using abi = ABI::Windows::UI::Text::Core::CoreTextCompositionStartedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Text.Core.CoreTextCompositionStartedEventArgs"; }
};

template <> struct traits<Windows::UI::Text::Core::CoreTextEditContext>
{
    using abi = ABI::Windows::UI::Text::Core::CoreTextEditContext;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Text.Core.CoreTextEditContext"; }
};

template <> struct traits<Windows::UI::Text::Core::CoreTextFormatUpdatingEventArgs>
{
    using abi = ABI::Windows::UI::Text::Core::CoreTextFormatUpdatingEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Text.Core.CoreTextFormatUpdatingEventArgs"; }
};

template <> struct traits<Windows::UI::Text::Core::CoreTextLayoutBounds>
{
    using abi = ABI::Windows::UI::Text::Core::CoreTextLayoutBounds;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Text.Core.CoreTextLayoutBounds"; }
};

template <> struct traits<Windows::UI::Text::Core::CoreTextLayoutRequest>
{
    using abi = ABI::Windows::UI::Text::Core::CoreTextLayoutRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Text.Core.CoreTextLayoutRequest"; }
};

template <> struct traits<Windows::UI::Text::Core::CoreTextLayoutRequestedEventArgs>
{
    using abi = ABI::Windows::UI::Text::Core::CoreTextLayoutRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Text.Core.CoreTextLayoutRequestedEventArgs"; }
};

template <> struct traits<Windows::UI::Text::Core::CoreTextSelectionRequest>
{
    using abi = ABI::Windows::UI::Text::Core::CoreTextSelectionRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Text.Core.CoreTextSelectionRequest"; }
};

template <> struct traits<Windows::UI::Text::Core::CoreTextSelectionRequestedEventArgs>
{
    using abi = ABI::Windows::UI::Text::Core::CoreTextSelectionRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Text.Core.CoreTextSelectionRequestedEventArgs"; }
};

template <> struct traits<Windows::UI::Text::Core::CoreTextSelectionUpdatingEventArgs>
{
    using abi = ABI::Windows::UI::Text::Core::CoreTextSelectionUpdatingEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Text.Core.CoreTextSelectionUpdatingEventArgs"; }
};

template <> struct traits<Windows::UI::Text::Core::CoreTextServicesConstants>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Text.Core.CoreTextServicesConstants"; }
};

template <> struct traits<Windows::UI::Text::Core::CoreTextServicesManager>
{
    using abi = ABI::Windows::UI::Text::Core::CoreTextServicesManager;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Text.Core.CoreTextServicesManager"; }
};

template <> struct traits<Windows::UI::Text::Core::CoreTextTextRequest>
{
    using abi = ABI::Windows::UI::Text::Core::CoreTextTextRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Text.Core.CoreTextTextRequest"; }
};

template <> struct traits<Windows::UI::Text::Core::CoreTextTextRequestedEventArgs>
{
    using abi = ABI::Windows::UI::Text::Core::CoreTextTextRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Text.Core.CoreTextTextRequestedEventArgs"; }
};

template <> struct traits<Windows::UI::Text::Core::CoreTextTextUpdatingEventArgs>
{
    using abi = ABI::Windows::UI::Text::Core::CoreTextTextUpdatingEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Text.Core.CoreTextTextUpdatingEventArgs"; }
};

}

}
