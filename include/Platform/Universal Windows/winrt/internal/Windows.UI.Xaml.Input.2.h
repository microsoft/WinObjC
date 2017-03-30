// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Input.1.h"
#include "Windows.UI.Xaml.1.h"
#include "Windows.UI.Xaml.2.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_c50898f6_c536_5f47_8583_8b2c2438a13b
#define WINRT_GENERIC_c50898f6_c536_5f47_8583_8b2c2438a13b
template <> struct __declspec(uuid("c50898f6-c536-5f47-8583-8b2c2438a13b")) __declspec(novtable) EventHandler<Windows::Foundation::IInspectable> : impl_EventHandler<Windows::Foundation::IInspectable> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_dfa655cf_fde7_5048_b4bf_c909231b7edb
#define WINRT_GENERIC_dfa655cf_fde7_5048_b4bf_c909231b7edb
template <> struct __declspec(uuid("dfa655cf-fde7-5048-b4bf-c909231b7edb")) __declspec(novtable) IVector<Windows::UI::Input::PointerPoint> : impl_IVector<Windows::UI::Input::PointerPoint> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_c7e65ce2_fad5_5e3b_9c58_186ca8c1dd57
#define WINRT_GENERIC_c7e65ce2_fad5_5e3b_9c58_186ca8c1dd57
template <> struct __declspec(uuid("c7e65ce2-fad5-5e3b-9c58-186ca8c1dd57")) __declspec(novtable) TypedEventHandler<Windows::Foundation::IInspectable, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::Foundation::IInspectable, Windows::Foundation::IInspectable> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_703fe123_d766_562f_b210_1980bb2a0d33
#define WINRT_GENERIC_703fe123_d766_562f_b210_1980bb2a0d33
template <> struct __declspec(uuid("703fe123-d766-562f-b210-1980bb2a0d33")) __declspec(novtable) IVector<Windows::UI::Xaml::Input::InputScopeName> : impl_IVector<Windows::UI::Xaml::Input::InputScopeName> {};
#endif

#ifndef WINRT_GENERIC_721fe01c_5ad4_5262_b078_3ab345105db8
#define WINRT_GENERIC_721fe01c_5ad4_5262_b078_3ab345105db8
template <> struct __declspec(uuid("721fe01c-5ad4-5262-b078-3ab345105db8")) __declspec(novtable) IIterator<Windows::UI::Input::PointerPoint> : impl_IIterator<Windows::UI::Input::PointerPoint> {};
#endif

#ifndef WINRT_GENERIC_f6f2cba6_7076_5b59_9631_f6ac32b57695
#define WINRT_GENERIC_f6f2cba6_7076_5b59_9631_f6ac32b57695
template <> struct __declspec(uuid("f6f2cba6-7076-5b59-9631-f6ac32b57695")) __declspec(novtable) IIterable<Windows::UI::Input::PointerPoint> : impl_IIterable<Windows::UI::Input::PointerPoint> {};
#endif

#ifndef WINRT_GENERIC_f0f57411_7786_5174_8752_4c5e834b6da2
#define WINRT_GENERIC_f0f57411_7786_5174_8752_4c5e834b6da2
template <> struct __declspec(uuid("f0f57411-7786-5174-8752-4c5e834b6da2")) __declspec(novtable) IVectorView<Windows::UI::Input::PointerPoint> : impl_IVectorView<Windows::UI::Input::PointerPoint> {};
#endif

#ifndef WINRT_GENERIC_7ac16ff4_5857_5001_b87f_327093f68392
#define WINRT_GENERIC_7ac16ff4_5857_5001_b87f_327093f68392
template <> struct __declspec(uuid("7ac16ff4-5857-5001-b87f-327093f68392")) __declspec(novtable) IIterator<Windows::UI::Xaml::Input::InputScopeName> : impl_IIterator<Windows::UI::Xaml::Input::InputScopeName> {};
#endif

#ifndef WINRT_GENERIC_81416296_95d0_5100_b59b_bea1c27d2002
#define WINRT_GENERIC_81416296_95d0_5100_b59b_bea1c27d2002
template <> struct __declspec(uuid("81416296-95d0-5100-b59b-bea1c27d2002")) __declspec(novtable) IIterable<Windows::UI::Xaml::Input::InputScopeName> : impl_IIterable<Windows::UI::Xaml::Input::InputScopeName> {};
#endif

#ifndef WINRT_GENERIC_fcd65a82_5328_53bc_a884_c209aafabf78
#define WINRT_GENERIC_fcd65a82_5328_53bc_a884_c209aafabf78
template <> struct __declspec(uuid("fcd65a82-5328-53bc-a884-c209aafabf78")) __declspec(novtable) IVectorView<Windows::UI::Xaml::Input::InputScopeName> : impl_IVectorView<Windows::UI::Xaml::Input::InputScopeName> {};
#endif


}

namespace Windows::UI::Xaml::Input {

struct DoubleTappedEventHandler : Windows::Foundation::IUnknown
{
    DoubleTappedEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> DoubleTappedEventHandler(L lambda);
    template <typename F> DoubleTappedEventHandler (F * function);
    template <typename O, typename M> DoubleTappedEventHandler(O * object, M method);
    void operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Input::DoubleTappedRoutedEventArgs & e) const;
};

struct HoldingEventHandler : Windows::Foundation::IUnknown
{
    HoldingEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> HoldingEventHandler(L lambda);
    template <typename F> HoldingEventHandler (F * function);
    template <typename O, typename M> HoldingEventHandler(O * object, M method);
    void operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Input::HoldingRoutedEventArgs & e) const;
};

struct KeyEventHandler : Windows::Foundation::IUnknown
{
    KeyEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> KeyEventHandler(L lambda);
    template <typename F> KeyEventHandler (F * function);
    template <typename O, typename M> KeyEventHandler(O * object, M method);
    void operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Input::KeyRoutedEventArgs & e) const;
};

struct ManipulationCompletedEventHandler : Windows::Foundation::IUnknown
{
    ManipulationCompletedEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> ManipulationCompletedEventHandler(L lambda);
    template <typename F> ManipulationCompletedEventHandler (F * function);
    template <typename O, typename M> ManipulationCompletedEventHandler(O * object, M method);
    void operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Input::ManipulationCompletedRoutedEventArgs & e) const;
};

struct ManipulationDeltaEventHandler : Windows::Foundation::IUnknown
{
    ManipulationDeltaEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> ManipulationDeltaEventHandler(L lambda);
    template <typename F> ManipulationDeltaEventHandler (F * function);
    template <typename O, typename M> ManipulationDeltaEventHandler(O * object, M method);
    void operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Input::ManipulationDeltaRoutedEventArgs & e) const;
};

struct ManipulationInertiaStartingEventHandler : Windows::Foundation::IUnknown
{
    ManipulationInertiaStartingEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> ManipulationInertiaStartingEventHandler(L lambda);
    template <typename F> ManipulationInertiaStartingEventHandler (F * function);
    template <typename O, typename M> ManipulationInertiaStartingEventHandler(O * object, M method);
    void operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Input::ManipulationInertiaStartingRoutedEventArgs & e) const;
};

struct ManipulationStartedEventHandler : Windows::Foundation::IUnknown
{
    ManipulationStartedEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> ManipulationStartedEventHandler(L lambda);
    template <typename F> ManipulationStartedEventHandler (F * function);
    template <typename O, typename M> ManipulationStartedEventHandler(O * object, M method);
    void operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Input::ManipulationStartedRoutedEventArgs & e) const;
};

struct ManipulationStartingEventHandler : Windows::Foundation::IUnknown
{
    ManipulationStartingEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> ManipulationStartingEventHandler(L lambda);
    template <typename F> ManipulationStartingEventHandler (F * function);
    template <typename O, typename M> ManipulationStartingEventHandler(O * object, M method);
    void operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Input::ManipulationStartingRoutedEventArgs & e) const;
};

struct PointerEventHandler : Windows::Foundation::IUnknown
{
    PointerEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> PointerEventHandler(L lambda);
    template <typename F> PointerEventHandler (F * function);
    template <typename O, typename M> PointerEventHandler(O * object, M method);
    void operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Input::PointerRoutedEventArgs & e) const;
};

struct RightTappedEventHandler : Windows::Foundation::IUnknown
{
    RightTappedEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> RightTappedEventHandler(L lambda);
    template <typename F> RightTappedEventHandler (F * function);
    template <typename O, typename M> RightTappedEventHandler(O * object, M method);
    void operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Input::RightTappedRoutedEventArgs & e) const;
};

struct TappedEventHandler : Windows::Foundation::IUnknown
{
    TappedEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> TappedEventHandler(L lambda);
    template <typename F> TappedEventHandler (F * function);
    template <typename O, typename M> TappedEventHandler(O * object, M method);
    void operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Input::TappedRoutedEventArgs & e) const;
};

struct IAccessKeyDisplayDismissedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IAccessKeyDisplayDismissedEventArgs>
{
    IAccessKeyDisplayDismissedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IAccessKeyDisplayRequestedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IAccessKeyDisplayRequestedEventArgs>
{
    IAccessKeyDisplayRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IAccessKeyInvokedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IAccessKeyInvokedEventArgs>
{
    IAccessKeyInvokedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IAccessKeyManager :
    Windows::Foundation::IInspectable,
    impl::consume<IAccessKeyManager>
{
    IAccessKeyManager(std::nullptr_t = nullptr) noexcept {}
};

struct IAccessKeyManagerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IAccessKeyManagerStatics>
{
    IAccessKeyManagerStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ICommand :
    Windows::Foundation::IInspectable,
    impl::consume<ICommand>
{
    ICommand(std::nullptr_t = nullptr) noexcept {}
};

struct IContextRequestedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IContextRequestedEventArgs>
{
    IContextRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IDoubleTappedRoutedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IDoubleTappedRoutedEventArgs>
{
    IDoubleTappedRoutedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IFocusManager :
    Windows::Foundation::IInspectable,
    impl::consume<IFocusManager>
{
    IFocusManager(std::nullptr_t = nullptr) noexcept {}
};

struct IFocusManagerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IFocusManagerStatics>
{
    IFocusManagerStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IFocusManagerStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IFocusManagerStatics2>
{
    IFocusManagerStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct IFocusManagerStatics3 :
    Windows::Foundation::IInspectable,
    impl::consume<IFocusManagerStatics3>
{
    IFocusManagerStatics3(std::nullptr_t = nullptr) noexcept {}
};

struct IHoldingRoutedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IHoldingRoutedEventArgs>
{
    IHoldingRoutedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IInertiaExpansionBehavior :
    Windows::Foundation::IInspectable,
    impl::consume<IInertiaExpansionBehavior>
{
    IInertiaExpansionBehavior(std::nullptr_t = nullptr) noexcept {}
};

struct IInertiaRotationBehavior :
    Windows::Foundation::IInspectable,
    impl::consume<IInertiaRotationBehavior>
{
    IInertiaRotationBehavior(std::nullptr_t = nullptr) noexcept {}
};

struct IInertiaTranslationBehavior :
    Windows::Foundation::IInspectable,
    impl::consume<IInertiaTranslationBehavior>
{
    IInertiaTranslationBehavior(std::nullptr_t = nullptr) noexcept {}
};

struct IInputScope :
    Windows::Foundation::IInspectable,
    impl::consume<IInputScope>
{
    IInputScope(std::nullptr_t = nullptr) noexcept {}
};

struct IInputScopeName :
    Windows::Foundation::IInspectable,
    impl::consume<IInputScopeName>
{
    IInputScopeName(std::nullptr_t = nullptr) noexcept {}
};

struct IInputScopeNameFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IInputScopeNameFactory>
{
    IInputScopeNameFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IKeyRoutedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IKeyRoutedEventArgs>
{
    IKeyRoutedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IKeyRoutedEventArgs2 :
    Windows::Foundation::IInspectable,
    impl::consume<IKeyRoutedEventArgs2>
{
    IKeyRoutedEventArgs2(std::nullptr_t = nullptr) noexcept {}
};

struct IKeyRoutedEventArgs3 :
    Windows::Foundation::IInspectable,
    impl::consume<IKeyRoutedEventArgs3>
{
    IKeyRoutedEventArgs3(std::nullptr_t = nullptr) noexcept {}
};

struct IManipulationCompletedRoutedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IManipulationCompletedRoutedEventArgs>
{
    IManipulationCompletedRoutedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IManipulationDeltaRoutedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IManipulationDeltaRoutedEventArgs>
{
    IManipulationDeltaRoutedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IManipulationInertiaStartingRoutedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IManipulationInertiaStartingRoutedEventArgs>
{
    IManipulationInertiaStartingRoutedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IManipulationPivot :
    Windows::Foundation::IInspectable,
    impl::consume<IManipulationPivot>
{
    IManipulationPivot(std::nullptr_t = nullptr) noexcept {}
};

struct IManipulationPivotFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IManipulationPivotFactory>
{
    IManipulationPivotFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IManipulationStartedRoutedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IManipulationStartedRoutedEventArgs>
{
    IManipulationStartedRoutedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IManipulationStartedRoutedEventArgsFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IManipulationStartedRoutedEventArgsFactory>
{
    IManipulationStartedRoutedEventArgsFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IManipulationStartingRoutedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IManipulationStartingRoutedEventArgs>
{
    IManipulationStartingRoutedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IPointer :
    Windows::Foundation::IInspectable,
    impl::consume<IPointer>
{
    IPointer(std::nullptr_t = nullptr) noexcept {}
};

struct IPointerRoutedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IPointerRoutedEventArgs>
{
    IPointerRoutedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IRightTappedRoutedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IRightTappedRoutedEventArgs>
{
    IRightTappedRoutedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct ITappedRoutedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<ITappedRoutedEventArgs>
{
    ITappedRoutedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

}

}
