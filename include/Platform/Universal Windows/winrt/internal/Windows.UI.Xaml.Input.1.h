// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.UI.Xaml.Input.0.h"
#include "Windows.Devices.Input.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.System.0.h"
#include "Windows.UI.Core.0.h"
#include "Windows.UI.Input.0.h"
#include "Windows.UI.Xaml.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.UI.Input.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Xaml::Input {

struct __declspec(uuid("3124d025-04a7-4d45-825e-8204a624dbf4")) __declspec(novtable) DoubleTappedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::Input::IDoubleTappedRoutedEventArgs * e) = 0;
};

struct __declspec(uuid("ecae8ccd-8e5e-4fbe-9846-30a6370afcdf")) __declspec(novtable) HoldingEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::Input::IHoldingRoutedEventArgs * e) = 0;
};

struct __declspec(uuid("8a610dc6-d72d-4ca8-9f66-556f35b513da")) __declspec(novtable) IAccessKeyDisplayDismissedEventArgs : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("0c079e55-13fe-4d03-a61d-e12f06567286")) __declspec(novtable) IAccessKeyDisplayRequestedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PressedKeys(hstring * value) = 0;
};

struct __declspec(uuid("cfe9cd97-c718-4091-b7dd-adf1c072b1e1")) __declspec(novtable) IAccessKeyInvokedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Handled(bool * value) = 0;
    virtual HRESULT __stdcall put_Handled(bool value) = 0;
};

struct __declspec(uuid("ecc973b0-2ee9-4b1c-98d7-6e0e816d334b")) __declspec(novtable) IAccessKeyManager : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("4ca0efe6-d9c8-4ebc-b4c7-30d1838a81f1")) __declspec(novtable) IAccessKeyManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsDisplayModeEnabled(bool * value) = 0;
    virtual HRESULT __stdcall add_IsDisplayModeEnabledChanged(Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_IsDisplayModeEnabledChanged(event_token token) = 0;
    virtual HRESULT __stdcall abi_ExitDisplayMode() = 0;
};

struct __declspec(uuid("e5af3542-ca67-4081-995b-709dd13792df")) __declspec(novtable) ICommand : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_CanExecuteChanged(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_CanExecuteChanged(event_token token) = 0;
    virtual HRESULT __stdcall abi_CanExecute(Windows::Foundation::IInspectable * parameter, bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_Execute(Windows::Foundation::IInspectable * parameter) = 0;
};

struct __declspec(uuid("42618e0a-1cb6-46fb-8374-0aec68aa5e51")) __declspec(novtable) IContextRequestedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Handled(bool * value) = 0;
    virtual HRESULT __stdcall put_Handled(bool value) = 0;
    virtual HRESULT __stdcall abi_TryGetPosition(Windows::UI::Xaml::IUIElement * relativeTo, Windows::Foundation::Point * point, bool * returnValue) = 0;
};

struct __declspec(uuid("af404424-26df-44f4-8714-9359249b62d3")) __declspec(novtable) IDoubleTappedRoutedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PointerDeviceType(winrt::Windows::Devices::Input::PointerDeviceType * value) = 0;
    virtual HRESULT __stdcall get_Handled(bool * value) = 0;
    virtual HRESULT __stdcall put_Handled(bool value) = 0;
    virtual HRESULT __stdcall abi_GetPosition(Windows::UI::Xaml::IUIElement * relativeTo, Windows::Foundation::Point * returnValue) = 0;
};

struct __declspec(uuid("c843f50b-3b83-4da1-9d6f-557c1169f341")) __declspec(novtable) IFocusManager : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("1eccd326-8182-4482-826a-0918e9ed9af7")) __declspec(novtable) IFocusManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetFocusedElement(Windows::Foundation::IInspectable ** returnValue) = 0;
};

struct __declspec(uuid("a920d761-dd87-4f31-beda-ef417fe7c04a")) __declspec(novtable) IFocusManagerStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_TryMoveFocus(winrt::Windows::UI::Xaml::Input::FocusNavigationDirection focusNavigationDirection, bool * returnValue) = 0;
};

struct __declspec(uuid("60805ebf-b149-417d-83f1-baeb560e2a47")) __declspec(novtable) IFocusManagerStatics3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FindNextFocusableElement(winrt::Windows::UI::Xaml::Input::FocusNavigationDirection focusNavigationDirection, Windows::UI::Xaml::IUIElement ** result) = 0;
    virtual HRESULT __stdcall abi_FindNextFocusableElementWithHint(winrt::Windows::UI::Xaml::Input::FocusNavigationDirection focusNavigationDirection, Windows::Foundation::Rect hintRect, Windows::UI::Xaml::IUIElement ** result) = 0;
};

struct __declspec(uuid("c246ff23-d80d-44de-8db9-0d815e269ac0")) __declspec(novtable) IHoldingRoutedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PointerDeviceType(winrt::Windows::Devices::Input::PointerDeviceType * value) = 0;
    virtual HRESULT __stdcall get_HoldingState(winrt::Windows::UI::Input::HoldingState * value) = 0;
    virtual HRESULT __stdcall get_Handled(bool * value) = 0;
    virtual HRESULT __stdcall put_Handled(bool value) = 0;
    virtual HRESULT __stdcall abi_GetPosition(Windows::UI::Xaml::IUIElement * relativeTo, Windows::Foundation::Point * returnValue) = 0;
};

struct __declspec(uuid("751d87e5-8d42-44c5-965e-3cd30cc9d6f7")) __declspec(novtable) IInertiaExpansionBehavior : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DesiredDeceleration(double * value) = 0;
    virtual HRESULT __stdcall put_DesiredDeceleration(double value) = 0;
    virtual HRESULT __stdcall get_DesiredExpansion(double * value) = 0;
    virtual HRESULT __stdcall put_DesiredExpansion(double value) = 0;
};

struct __declspec(uuid("424cfb2e-bbfd-4625-ae78-20c65bf1efaf")) __declspec(novtable) IInertiaRotationBehavior : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DesiredDeceleration(double * value) = 0;
    virtual HRESULT __stdcall put_DesiredDeceleration(double value) = 0;
    virtual HRESULT __stdcall get_DesiredRotation(double * value) = 0;
    virtual HRESULT __stdcall put_DesiredRotation(double value) = 0;
};

struct __declspec(uuid("45d3a512-3b32-4882-a4c2-ecfa2d4b6df0")) __declspec(novtable) IInertiaTranslationBehavior : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DesiredDeceleration(double * value) = 0;
    virtual HRESULT __stdcall put_DesiredDeceleration(double value) = 0;
    virtual HRESULT __stdcall get_DesiredDisplacement(double * value) = 0;
    virtual HRESULT __stdcall put_DesiredDisplacement(double value) = 0;
};

struct __declspec(uuid("5c0f85f3-f9d8-4220-b666-045d074d9bfa")) __declspec(novtable) IInputScope : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Names(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Input::InputScopeName> ** value) = 0;
};

struct __declspec(uuid("fd3e6997-08fb-4cba-a021-792d7589fd5a")) __declspec(novtable) IInputScopeName : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_NameValue(winrt::Windows::UI::Xaml::Input::InputScopeNameValue * value) = 0;
    virtual HRESULT __stdcall put_NameValue(winrt::Windows::UI::Xaml::Input::InputScopeNameValue value) = 0;
};

struct __declspec(uuid("4a40bb52-4bd7-4e54-8617-1cda8a1eda7f")) __declspec(novtable) IInputScopeNameFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(winrt::Windows::UI::Xaml::Input::InputScopeNameValue nameValue, Windows::UI::Xaml::Input::IInputScopeName ** instance) = 0;
};

struct __declspec(uuid("d4cd3dfe-4079-42e9-a39a-3095d3f049c6")) __declspec(novtable) IKeyRoutedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Key(winrt::Windows::System::VirtualKey * value) = 0;
    virtual HRESULT __stdcall get_KeyStatus(Windows::UI::Core::CorePhysicalKeyStatus * value) = 0;
    virtual HRESULT __stdcall get_Handled(bool * value) = 0;
    virtual HRESULT __stdcall put_Handled(bool value) = 0;
};

struct __declspec(uuid("1b02d57a-9634-4f14-91b2-133e42fdb3cd")) __declspec(novtable) IKeyRoutedEventArgs2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_OriginalKey(winrt::Windows::System::VirtualKey * value) = 0;
};

struct __declspec(uuid("2779f5b4-ca41-411b-a8ef-f4fc78e78057")) __declspec(novtable) IKeyRoutedEventArgs3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
};

struct __declspec(uuid("b5ad9b23-2f41-498e-8319-015ee8a75346")) __declspec(novtable) IManipulationCompletedRoutedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Container(Windows::UI::Xaml::IUIElement ** value) = 0;
    virtual HRESULT __stdcall get_Position(Windows::Foundation::Point * value) = 0;
    virtual HRESULT __stdcall get_IsInertial(bool * value) = 0;
    virtual HRESULT __stdcall get_Cumulative(Windows::UI::Input::ManipulationDelta * value) = 0;
    virtual HRESULT __stdcall get_Velocities(Windows::UI::Input::ManipulationVelocities * value) = 0;
    virtual HRESULT __stdcall get_Handled(bool * value) = 0;
    virtual HRESULT __stdcall put_Handled(bool value) = 0;
    virtual HRESULT __stdcall get_PointerDeviceType(winrt::Windows::Devices::Input::PointerDeviceType * value) = 0;
};

struct __declspec(uuid("400d5794-4c6f-491d-82d6-3517109399c6")) __declspec(novtable) IManipulationDeltaRoutedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Container(Windows::UI::Xaml::IUIElement ** value) = 0;
    virtual HRESULT __stdcall get_Position(Windows::Foundation::Point * value) = 0;
    virtual HRESULT __stdcall get_IsInertial(bool * value) = 0;
    virtual HRESULT __stdcall get_Delta(Windows::UI::Input::ManipulationDelta * value) = 0;
    virtual HRESULT __stdcall get_Cumulative(Windows::UI::Input::ManipulationDelta * value) = 0;
    virtual HRESULT __stdcall get_Velocities(Windows::UI::Input::ManipulationVelocities * value) = 0;
    virtual HRESULT __stdcall get_Handled(bool * value) = 0;
    virtual HRESULT __stdcall put_Handled(bool value) = 0;
    virtual HRESULT __stdcall get_PointerDeviceType(winrt::Windows::Devices::Input::PointerDeviceType * value) = 0;
    virtual HRESULT __stdcall abi_Complete() = 0;
};

struct __declspec(uuid("246a91a9-ca43-4c0b-acef-81e8b8147520")) __declspec(novtable) IManipulationInertiaStartingRoutedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Container(Windows::UI::Xaml::IUIElement ** value) = 0;
    virtual HRESULT __stdcall get_ExpansionBehavior(Windows::UI::Xaml::Input::IInertiaExpansionBehavior ** value) = 0;
    virtual HRESULT __stdcall put_ExpansionBehavior(Windows::UI::Xaml::Input::IInertiaExpansionBehavior * value) = 0;
    virtual HRESULT __stdcall get_RotationBehavior(Windows::UI::Xaml::Input::IInertiaRotationBehavior ** value) = 0;
    virtual HRESULT __stdcall put_RotationBehavior(Windows::UI::Xaml::Input::IInertiaRotationBehavior * value) = 0;
    virtual HRESULT __stdcall get_TranslationBehavior(Windows::UI::Xaml::Input::IInertiaTranslationBehavior ** value) = 0;
    virtual HRESULT __stdcall put_TranslationBehavior(Windows::UI::Xaml::Input::IInertiaTranslationBehavior * value) = 0;
    virtual HRESULT __stdcall get_Handled(bool * value) = 0;
    virtual HRESULT __stdcall put_Handled(bool value) = 0;
    virtual HRESULT __stdcall get_PointerDeviceType(winrt::Windows::Devices::Input::PointerDeviceType * value) = 0;
    virtual HRESULT __stdcall get_Delta(Windows::UI::Input::ManipulationDelta * value) = 0;
    virtual HRESULT __stdcall get_Cumulative(Windows::UI::Input::ManipulationDelta * value) = 0;
    virtual HRESULT __stdcall get_Velocities(Windows::UI::Input::ManipulationVelocities * value) = 0;
};

struct __declspec(uuid("2e3838a5-e6c2-4998-82ac-18748b141666")) __declspec(novtable) IManipulationPivot : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Center(Windows::Foundation::Point * value) = 0;
    virtual HRESULT __stdcall put_Center(Windows::Foundation::Point value) = 0;
    virtual HRESULT __stdcall get_Radius(double * value) = 0;
    virtual HRESULT __stdcall put_Radius(double value) = 0;
};

struct __declspec(uuid("6d05b039-3702-4396-ad9b-a825efa63a3b")) __declspec(novtable) IManipulationPivotFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithCenterAndRadius(Windows::Foundation::Point center, double radius, Windows::UI::Xaml::Input::IManipulationPivot ** instance) = 0;
};

struct __declspec(uuid("5db1aa05-9f80-48b6-ae6c-4f119de8ff13")) __declspec(novtable) IManipulationStartedRoutedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Container(Windows::UI::Xaml::IUIElement ** value) = 0;
    virtual HRESULT __stdcall get_Position(Windows::Foundation::Point * value) = 0;
    virtual HRESULT __stdcall get_Handled(bool * value) = 0;
    virtual HRESULT __stdcall put_Handled(bool value) = 0;
    virtual HRESULT __stdcall get_PointerDeviceType(winrt::Windows::Devices::Input::PointerDeviceType * value) = 0;
    virtual HRESULT __stdcall get_Cumulative(Windows::UI::Input::ManipulationDelta * value) = 0;
    virtual HRESULT __stdcall abi_Complete() = 0;
};

struct __declspec(uuid("84c1daa7-7272-4463-b6c3-a40b9ba151fc")) __declspec(novtable) IManipulationStartedRoutedEventArgsFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgs ** instance) = 0;
};

struct __declspec(uuid("18d636b7-53a4-4c15-a498-f3a9ca212a42")) __declspec(novtable) IManipulationStartingRoutedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Mode(winrt::Windows::UI::Xaml::Input::ManipulationModes * value) = 0;
    virtual HRESULT __stdcall put_Mode(winrt::Windows::UI::Xaml::Input::ManipulationModes value) = 0;
    virtual HRESULT __stdcall get_Container(Windows::UI::Xaml::IUIElement ** value) = 0;
    virtual HRESULT __stdcall put_Container(Windows::UI::Xaml::IUIElement * value) = 0;
    virtual HRESULT __stdcall get_Pivot(Windows::UI::Xaml::Input::IManipulationPivot ** value) = 0;
    virtual HRESULT __stdcall put_Pivot(Windows::UI::Xaml::Input::IManipulationPivot * value) = 0;
    virtual HRESULT __stdcall get_Handled(bool * value) = 0;
    virtual HRESULT __stdcall put_Handled(bool value) = 0;
};

struct __declspec(uuid("5ee8f39f-747d-4171-90e6-cd37a9dffb11")) __declspec(novtable) IPointer : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PointerId(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_PointerDeviceType(winrt::Windows::Devices::Input::PointerDeviceType * value) = 0;
    virtual HRESULT __stdcall get_IsInContact(bool * value) = 0;
    virtual HRESULT __stdcall get_IsInRange(bool * value) = 0;
};

struct __declspec(uuid("da628f0a-9752-49e2-bde2-49eccab9194d")) __declspec(novtable) IPointerRoutedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Pointer(Windows::UI::Xaml::Input::IPointer ** value) = 0;
    virtual HRESULT __stdcall get_KeyModifiers(winrt::Windows::System::VirtualKeyModifiers * value) = 0;
    virtual HRESULT __stdcall get_Handled(bool * value) = 0;
    virtual HRESULT __stdcall put_Handled(bool value) = 0;
    virtual HRESULT __stdcall abi_GetCurrentPoint(Windows::UI::Xaml::IUIElement * relativeTo, Windows::UI::Input::IPointerPoint ** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetIntermediatePoints(Windows::UI::Xaml::IUIElement * relativeTo, Windows::Foundation::Collections::IVector<Windows::UI::Input::PointerPoint> ** returnValue) = 0;
};

struct __declspec(uuid("6834869d-7bd5-4033-b237-172f79abe393")) __declspec(novtable) IRightTappedRoutedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PointerDeviceType(winrt::Windows::Devices::Input::PointerDeviceType * value) = 0;
    virtual HRESULT __stdcall get_Handled(bool * value) = 0;
    virtual HRESULT __stdcall put_Handled(bool value) = 0;
    virtual HRESULT __stdcall abi_GetPosition(Windows::UI::Xaml::IUIElement * relativeTo, Windows::Foundation::Point * returnValue) = 0;
};

struct __declspec(uuid("a099e6be-e624-459a-bb1d-e05c73e2cc66")) __declspec(novtable) ITappedRoutedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PointerDeviceType(winrt::Windows::Devices::Input::PointerDeviceType * value) = 0;
    virtual HRESULT __stdcall get_Handled(bool * value) = 0;
    virtual HRESULT __stdcall put_Handled(bool value) = 0;
    virtual HRESULT __stdcall abi_GetPosition(Windows::UI::Xaml::IUIElement * relativeTo, Windows::Foundation::Point * returnValue) = 0;
};

struct __declspec(uuid("7c63d2e5-7a0e-4e12-b96a-7715aa6ff1c8")) __declspec(novtable) KeyEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::Input::IKeyRoutedEventArgs * e) = 0;
};

struct __declspec(uuid("38ef4b0f-14f8-42df-9a1e-a4bcc4af77f4")) __declspec(novtable) ManipulationCompletedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::Input::IManipulationCompletedRoutedEventArgs * e) = 0;
};

struct __declspec(uuid("aa1160cb-dfb9-4c56-abdc-711b63c8eb94")) __declspec(novtable) ManipulationDeltaEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::Input::IManipulationDeltaRoutedEventArgs * e) = 0;
};

struct __declspec(uuid("d39d6322-7c9c-481b-827b-c8b2d9bb6fc7")) __declspec(novtable) ManipulationInertiaStartingEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::Input::IManipulationInertiaStartingRoutedEventArgs * e) = 0;
};

struct __declspec(uuid("f88345f8-e0a3-4be2-b90c-dc20e6d8beb0")) __declspec(novtable) ManipulationStartedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgs * e) = 0;
};

struct __declspec(uuid("10d0b04e-bfe4-42cb-823c-3fecd8770ef8")) __declspec(novtable) ManipulationStartingEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::Input::IManipulationStartingRoutedEventArgs * e) = 0;
};

struct __declspec(uuid("e4385929-c004-4bcf-8970-359486e39f88")) __declspec(novtable) PointerEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::Input::IPointerRoutedEventArgs * e) = 0;
};

struct __declspec(uuid("2532a062-f447-4950-9c46-f1e34a2c2238")) __declspec(novtable) RightTappedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::Input::IRightTappedRoutedEventArgs * e) = 0;
};

struct __declspec(uuid("68d940cc-9ff0-49ce-b141-3f07ec477b97")) __declspec(novtable) TappedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::Input::ITappedRoutedEventArgs * e) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::UI::Xaml::Input::AccessKeyDisplayDismissedEventArgs> { using default_interface = Windows::UI::Xaml::Input::IAccessKeyDisplayDismissedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Input::AccessKeyDisplayRequestedEventArgs> { using default_interface = Windows::UI::Xaml::Input::IAccessKeyDisplayRequestedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Input::AccessKeyInvokedEventArgs> { using default_interface = Windows::UI::Xaml::Input::IAccessKeyInvokedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Input::AccessKeyManager> { using default_interface = Windows::UI::Xaml::Input::IAccessKeyManager; };
template <> struct traits<Windows::UI::Xaml::Input::ContextRequestedEventArgs> { using default_interface = Windows::UI::Xaml::Input::IContextRequestedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Input::DoubleTappedRoutedEventArgs> { using default_interface = Windows::UI::Xaml::Input::IDoubleTappedRoutedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Input::FocusManager> { using default_interface = Windows::UI::Xaml::Input::IFocusManager; };
template <> struct traits<Windows::UI::Xaml::Input::HoldingRoutedEventArgs> { using default_interface = Windows::UI::Xaml::Input::IHoldingRoutedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Input::InertiaExpansionBehavior> { using default_interface = Windows::UI::Xaml::Input::IInertiaExpansionBehavior; };
template <> struct traits<Windows::UI::Xaml::Input::InertiaRotationBehavior> { using default_interface = Windows::UI::Xaml::Input::IInertiaRotationBehavior; };
template <> struct traits<Windows::UI::Xaml::Input::InertiaTranslationBehavior> { using default_interface = Windows::UI::Xaml::Input::IInertiaTranslationBehavior; };
template <> struct traits<Windows::UI::Xaml::Input::InputScope> { using default_interface = Windows::UI::Xaml::Input::IInputScope; };
template <> struct traits<Windows::UI::Xaml::Input::InputScopeName> { using default_interface = Windows::UI::Xaml::Input::IInputScopeName; };
template <> struct traits<Windows::UI::Xaml::Input::KeyRoutedEventArgs> { using default_interface = Windows::UI::Xaml::Input::IKeyRoutedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Input::ManipulationCompletedRoutedEventArgs> { using default_interface = Windows::UI::Xaml::Input::IManipulationCompletedRoutedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Input::ManipulationDeltaRoutedEventArgs> { using default_interface = Windows::UI::Xaml::Input::IManipulationDeltaRoutedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Input::ManipulationInertiaStartingRoutedEventArgs> { using default_interface = Windows::UI::Xaml::Input::IManipulationInertiaStartingRoutedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Input::ManipulationPivot> { using default_interface = Windows::UI::Xaml::Input::IManipulationPivot; };
template <> struct traits<Windows::UI::Xaml::Input::ManipulationStartedRoutedEventArgs> { using default_interface = Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Input::ManipulationStartingRoutedEventArgs> { using default_interface = Windows::UI::Xaml::Input::IManipulationStartingRoutedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Input::Pointer> { using default_interface = Windows::UI::Xaml::Input::IPointer; };
template <> struct traits<Windows::UI::Xaml::Input::PointerRoutedEventArgs> { using default_interface = Windows::UI::Xaml::Input::IPointerRoutedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Input::RightTappedRoutedEventArgs> { using default_interface = Windows::UI::Xaml::Input::IRightTappedRoutedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Input::TappedRoutedEventArgs> { using default_interface = Windows::UI::Xaml::Input::ITappedRoutedEventArgs; };

}

namespace Windows::UI::Xaml::Input {

template <typename D>
struct WINRT_EBO impl_IAccessKeyDisplayDismissedEventArgs
{
};

template <typename D>
struct WINRT_EBO impl_IAccessKeyDisplayRequestedEventArgs
{
    hstring PressedKeys() const;
};

template <typename D>
struct WINRT_EBO impl_IAccessKeyInvokedEventArgs
{
    bool Handled() const;
    void Handled(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IAccessKeyManager
{
};

template <typename D>
struct WINRT_EBO impl_IAccessKeyManagerStatics
{
    bool IsDisplayModeEnabled() const;
    event_token IsDisplayModeEnabledChanged(const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::Foundation::IInspectable> & value) const;
    using IsDisplayModeEnabledChanged_revoker = event_revoker<IAccessKeyManagerStatics>;
    IsDisplayModeEnabledChanged_revoker IsDisplayModeEnabledChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::Foundation::IInspectable> & value) const;
    void IsDisplayModeEnabledChanged(event_token token) const;
    void ExitDisplayMode() const;
};

template <typename D>
struct WINRT_EBO impl_ICommand
{
    event_token CanExecuteChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const;
    using CanExecuteChanged_revoker = event_revoker<ICommand>;
    CanExecuteChanged_revoker CanExecuteChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const;
    void CanExecuteChanged(event_token token) const;
    bool CanExecute(const Windows::Foundation::IInspectable & parameter) const;
    void Execute(const Windows::Foundation::IInspectable & parameter) const;
};

template <typename D>
struct WINRT_EBO impl_IContextRequestedEventArgs
{
    bool Handled() const;
    void Handled(bool value) const;
    bool TryGetPosition(const Windows::UI::Xaml::UIElement & relativeTo, Windows::Foundation::Point & point) const;
};

template <typename D>
struct WINRT_EBO impl_IDoubleTappedRoutedEventArgs
{
    Windows::Devices::Input::PointerDeviceType PointerDeviceType() const;
    bool Handled() const;
    void Handled(bool value) const;
    Windows::Foundation::Point GetPosition(const Windows::UI::Xaml::UIElement & relativeTo) const;
};

template <typename D>
struct WINRT_EBO impl_IFocusManager
{
};

template <typename D>
struct WINRT_EBO impl_IFocusManagerStatics
{
    Windows::Foundation::IInspectable GetFocusedElement() const;
};

template <typename D>
struct WINRT_EBO impl_IFocusManagerStatics2
{
    bool TryMoveFocus(Windows::UI::Xaml::Input::FocusNavigationDirection focusNavigationDirection) const;
};

template <typename D>
struct WINRT_EBO impl_IFocusManagerStatics3
{
    Windows::UI::Xaml::UIElement FindNextFocusableElement(Windows::UI::Xaml::Input::FocusNavigationDirection focusNavigationDirection) const;
    Windows::UI::Xaml::UIElement FindNextFocusableElement(Windows::UI::Xaml::Input::FocusNavigationDirection focusNavigationDirection, const Windows::Foundation::Rect & hintRect) const;
};

template <typename D>
struct WINRT_EBO impl_IHoldingRoutedEventArgs
{
    Windows::Devices::Input::PointerDeviceType PointerDeviceType() const;
    Windows::UI::Input::HoldingState HoldingState() const;
    bool Handled() const;
    void Handled(bool value) const;
    Windows::Foundation::Point GetPosition(const Windows::UI::Xaml::UIElement & relativeTo) const;
};

template <typename D>
struct WINRT_EBO impl_IInertiaExpansionBehavior
{
    double DesiredDeceleration() const;
    void DesiredDeceleration(double value) const;
    double DesiredExpansion() const;
    void DesiredExpansion(double value) const;
};

template <typename D>
struct WINRT_EBO impl_IInertiaRotationBehavior
{
    double DesiredDeceleration() const;
    void DesiredDeceleration(double value) const;
    double DesiredRotation() const;
    void DesiredRotation(double value) const;
};

template <typename D>
struct WINRT_EBO impl_IInertiaTranslationBehavior
{
    double DesiredDeceleration() const;
    void DesiredDeceleration(double value) const;
    double DesiredDisplacement() const;
    void DesiredDisplacement(double value) const;
};

template <typename D>
struct WINRT_EBO impl_IInputScope
{
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Input::InputScopeName> Names() const;
};

template <typename D>
struct WINRT_EBO impl_IInputScopeName
{
    Windows::UI::Xaml::Input::InputScopeNameValue NameValue() const;
    void NameValue(Windows::UI::Xaml::Input::InputScopeNameValue value) const;
};

template <typename D>
struct WINRT_EBO impl_IInputScopeNameFactory
{
    Windows::UI::Xaml::Input::InputScopeName CreateInstance(Windows::UI::Xaml::Input::InputScopeNameValue nameValue) const;
};

template <typename D>
struct WINRT_EBO impl_IKeyRoutedEventArgs
{
    Windows::System::VirtualKey Key() const;
    Windows::UI::Core::CorePhysicalKeyStatus KeyStatus() const;
    bool Handled() const;
    void Handled(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IKeyRoutedEventArgs2
{
    Windows::System::VirtualKey OriginalKey() const;
};

template <typename D>
struct WINRT_EBO impl_IKeyRoutedEventArgs3
{
    hstring DeviceId() const;
};

template <typename D>
struct WINRT_EBO impl_IManipulationCompletedRoutedEventArgs
{
    Windows::UI::Xaml::UIElement Container() const;
    Windows::Foundation::Point Position() const;
    bool IsInertial() const;
    Windows::UI::Input::ManipulationDelta Cumulative() const;
    Windows::UI::Input::ManipulationVelocities Velocities() const;
    bool Handled() const;
    void Handled(bool value) const;
    Windows::Devices::Input::PointerDeviceType PointerDeviceType() const;
};

template <typename D>
struct WINRT_EBO impl_IManipulationDeltaRoutedEventArgs
{
    Windows::UI::Xaml::UIElement Container() const;
    Windows::Foundation::Point Position() const;
    bool IsInertial() const;
    Windows::UI::Input::ManipulationDelta Delta() const;
    Windows::UI::Input::ManipulationDelta Cumulative() const;
    Windows::UI::Input::ManipulationVelocities Velocities() const;
    bool Handled() const;
    void Handled(bool value) const;
    Windows::Devices::Input::PointerDeviceType PointerDeviceType() const;
    void Complete() const;
};

template <typename D>
struct WINRT_EBO impl_IManipulationInertiaStartingRoutedEventArgs
{
    Windows::UI::Xaml::UIElement Container() const;
    Windows::UI::Xaml::Input::InertiaExpansionBehavior ExpansionBehavior() const;
    void ExpansionBehavior(const Windows::UI::Xaml::Input::InertiaExpansionBehavior & value) const;
    Windows::UI::Xaml::Input::InertiaRotationBehavior RotationBehavior() const;
    void RotationBehavior(const Windows::UI::Xaml::Input::InertiaRotationBehavior & value) const;
    Windows::UI::Xaml::Input::InertiaTranslationBehavior TranslationBehavior() const;
    void TranslationBehavior(const Windows::UI::Xaml::Input::InertiaTranslationBehavior & value) const;
    bool Handled() const;
    void Handled(bool value) const;
    Windows::Devices::Input::PointerDeviceType PointerDeviceType() const;
    Windows::UI::Input::ManipulationDelta Delta() const;
    Windows::UI::Input::ManipulationDelta Cumulative() const;
    Windows::UI::Input::ManipulationVelocities Velocities() const;
};

template <typename D>
struct WINRT_EBO impl_IManipulationPivot
{
    Windows::Foundation::Point Center() const;
    void Center(const Windows::Foundation::Point & value) const;
    double Radius() const;
    void Radius(double value) const;
};

template <typename D>
struct WINRT_EBO impl_IManipulationPivotFactory
{
    Windows::UI::Xaml::Input::ManipulationPivot CreateInstanceWithCenterAndRadius(const Windows::Foundation::Point & center, double radius) const;
};

template <typename D>
struct WINRT_EBO impl_IManipulationStartedRoutedEventArgs
{
    Windows::UI::Xaml::UIElement Container() const;
    Windows::Foundation::Point Position() const;
    bool Handled() const;
    void Handled(bool value) const;
    Windows::Devices::Input::PointerDeviceType PointerDeviceType() const;
    Windows::UI::Input::ManipulationDelta Cumulative() const;
    void Complete() const;
};

template <typename D>
struct WINRT_EBO impl_IManipulationStartedRoutedEventArgsFactory
{
    Windows::UI::Xaml::Input::ManipulationStartedRoutedEventArgs CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IManipulationStartingRoutedEventArgs
{
    Windows::UI::Xaml::Input::ManipulationModes Mode() const;
    void Mode(Windows::UI::Xaml::Input::ManipulationModes value) const;
    Windows::UI::Xaml::UIElement Container() const;
    void Container(const Windows::UI::Xaml::UIElement & value) const;
    Windows::UI::Xaml::Input::ManipulationPivot Pivot() const;
    void Pivot(const Windows::UI::Xaml::Input::ManipulationPivot & value) const;
    bool Handled() const;
    void Handled(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IPointer
{
    uint32_t PointerId() const;
    Windows::Devices::Input::PointerDeviceType PointerDeviceType() const;
    bool IsInContact() const;
    bool IsInRange() const;
};

template <typename D>
struct WINRT_EBO impl_IPointerRoutedEventArgs
{
    Windows::UI::Xaml::Input::Pointer Pointer() const;
    Windows::System::VirtualKeyModifiers KeyModifiers() const;
    bool Handled() const;
    void Handled(bool value) const;
    Windows::UI::Input::PointerPoint GetCurrentPoint(const Windows::UI::Xaml::UIElement & relativeTo) const;
    Windows::Foundation::Collections::IVector<Windows::UI::Input::PointerPoint> GetIntermediatePoints(const Windows::UI::Xaml::UIElement & relativeTo) const;
};

template <typename D>
struct WINRT_EBO impl_IRightTappedRoutedEventArgs
{
    Windows::Devices::Input::PointerDeviceType PointerDeviceType() const;
    bool Handled() const;
    void Handled(bool value) const;
    Windows::Foundation::Point GetPosition(const Windows::UI::Xaml::UIElement & relativeTo) const;
};

template <typename D>
struct WINRT_EBO impl_ITappedRoutedEventArgs
{
    Windows::Devices::Input::PointerDeviceType PointerDeviceType() const;
    bool Handled() const;
    void Handled(bool value) const;
    Windows::Foundation::Point GetPosition(const Windows::UI::Xaml::UIElement & relativeTo) const;
};

}

namespace impl {

template <> struct traits<Windows::UI::Xaml::Input::DoubleTappedEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::Input::DoubleTappedEventHandler;
};

template <> struct traits<Windows::UI::Xaml::Input::HoldingEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::Input::HoldingEventHandler;
};

template <> struct traits<Windows::UI::Xaml::Input::IAccessKeyDisplayDismissedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Input::IAccessKeyDisplayDismissedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Input::impl_IAccessKeyDisplayDismissedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Input::IAccessKeyDisplayRequestedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Input::IAccessKeyDisplayRequestedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Input::impl_IAccessKeyDisplayRequestedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Input::IAccessKeyInvokedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Input::IAccessKeyInvokedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Input::impl_IAccessKeyInvokedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Input::IAccessKeyManager>
{
    using abi = ABI::Windows::UI::Xaml::Input::IAccessKeyManager;
    template <typename D> using consume = Windows::UI::Xaml::Input::impl_IAccessKeyManager<D>;
};

template <> struct traits<Windows::UI::Xaml::Input::IAccessKeyManagerStatics>
{
    using abi = ABI::Windows::UI::Xaml::Input::IAccessKeyManagerStatics;
    template <typename D> using consume = Windows::UI::Xaml::Input::impl_IAccessKeyManagerStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Input::ICommand>
{
    using abi = ABI::Windows::UI::Xaml::Input::ICommand;
    template <typename D> using consume = Windows::UI::Xaml::Input::impl_ICommand<D>;
};

template <> struct traits<Windows::UI::Xaml::Input::IContextRequestedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Input::IContextRequestedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Input::impl_IContextRequestedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Input::IDoubleTappedRoutedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Input::IDoubleTappedRoutedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Input::impl_IDoubleTappedRoutedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Input::IFocusManager>
{
    using abi = ABI::Windows::UI::Xaml::Input::IFocusManager;
    template <typename D> using consume = Windows::UI::Xaml::Input::impl_IFocusManager<D>;
};

template <> struct traits<Windows::UI::Xaml::Input::IFocusManagerStatics>
{
    using abi = ABI::Windows::UI::Xaml::Input::IFocusManagerStatics;
    template <typename D> using consume = Windows::UI::Xaml::Input::impl_IFocusManagerStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Input::IFocusManagerStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Input::IFocusManagerStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Input::impl_IFocusManagerStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Input::IFocusManagerStatics3>
{
    using abi = ABI::Windows::UI::Xaml::Input::IFocusManagerStatics3;
    template <typename D> using consume = Windows::UI::Xaml::Input::impl_IFocusManagerStatics3<D>;
};

template <> struct traits<Windows::UI::Xaml::Input::IHoldingRoutedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Input::IHoldingRoutedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Input::impl_IHoldingRoutedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Input::IInertiaExpansionBehavior>
{
    using abi = ABI::Windows::UI::Xaml::Input::IInertiaExpansionBehavior;
    template <typename D> using consume = Windows::UI::Xaml::Input::impl_IInertiaExpansionBehavior<D>;
};

template <> struct traits<Windows::UI::Xaml::Input::IInertiaRotationBehavior>
{
    using abi = ABI::Windows::UI::Xaml::Input::IInertiaRotationBehavior;
    template <typename D> using consume = Windows::UI::Xaml::Input::impl_IInertiaRotationBehavior<D>;
};

template <> struct traits<Windows::UI::Xaml::Input::IInertiaTranslationBehavior>
{
    using abi = ABI::Windows::UI::Xaml::Input::IInertiaTranslationBehavior;
    template <typename D> using consume = Windows::UI::Xaml::Input::impl_IInertiaTranslationBehavior<D>;
};

template <> struct traits<Windows::UI::Xaml::Input::IInputScope>
{
    using abi = ABI::Windows::UI::Xaml::Input::IInputScope;
    template <typename D> using consume = Windows::UI::Xaml::Input::impl_IInputScope<D>;
};

template <> struct traits<Windows::UI::Xaml::Input::IInputScopeName>
{
    using abi = ABI::Windows::UI::Xaml::Input::IInputScopeName;
    template <typename D> using consume = Windows::UI::Xaml::Input::impl_IInputScopeName<D>;
};

template <> struct traits<Windows::UI::Xaml::Input::IInputScopeNameFactory>
{
    using abi = ABI::Windows::UI::Xaml::Input::IInputScopeNameFactory;
    template <typename D> using consume = Windows::UI::Xaml::Input::impl_IInputScopeNameFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Input::IKeyRoutedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Input::IKeyRoutedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Input::impl_IKeyRoutedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Input::IKeyRoutedEventArgs2>
{
    using abi = ABI::Windows::UI::Xaml::Input::IKeyRoutedEventArgs2;
    template <typename D> using consume = Windows::UI::Xaml::Input::impl_IKeyRoutedEventArgs2<D>;
};

template <> struct traits<Windows::UI::Xaml::Input::IKeyRoutedEventArgs3>
{
    using abi = ABI::Windows::UI::Xaml::Input::IKeyRoutedEventArgs3;
    template <typename D> using consume = Windows::UI::Xaml::Input::impl_IKeyRoutedEventArgs3<D>;
};

template <> struct traits<Windows::UI::Xaml::Input::IManipulationCompletedRoutedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Input::IManipulationCompletedRoutedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Input::impl_IManipulationCompletedRoutedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Input::IManipulationDeltaRoutedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Input::IManipulationDeltaRoutedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Input::impl_IManipulationDeltaRoutedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Input::IManipulationInertiaStartingRoutedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Input::IManipulationInertiaStartingRoutedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Input::impl_IManipulationInertiaStartingRoutedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Input::IManipulationPivot>
{
    using abi = ABI::Windows::UI::Xaml::Input::IManipulationPivot;
    template <typename D> using consume = Windows::UI::Xaml::Input::impl_IManipulationPivot<D>;
};

template <> struct traits<Windows::UI::Xaml::Input::IManipulationPivotFactory>
{
    using abi = ABI::Windows::UI::Xaml::Input::IManipulationPivotFactory;
    template <typename D> using consume = Windows::UI::Xaml::Input::impl_IManipulationPivotFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Input::impl_IManipulationStartedRoutedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgsFactory>
{
    using abi = ABI::Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgsFactory;
    template <typename D> using consume = Windows::UI::Xaml::Input::impl_IManipulationStartedRoutedEventArgsFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Input::IManipulationStartingRoutedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Input::IManipulationStartingRoutedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Input::impl_IManipulationStartingRoutedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Input::IPointer>
{
    using abi = ABI::Windows::UI::Xaml::Input::IPointer;
    template <typename D> using consume = Windows::UI::Xaml::Input::impl_IPointer<D>;
};

template <> struct traits<Windows::UI::Xaml::Input::IPointerRoutedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Input::impl_IPointerRoutedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Input::IRightTappedRoutedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Input::IRightTappedRoutedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Input::impl_IRightTappedRoutedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Input::ITappedRoutedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Input::ITappedRoutedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Input::impl_ITappedRoutedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Input::KeyEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::Input::KeyEventHandler;
};

template <> struct traits<Windows::UI::Xaml::Input::ManipulationCompletedEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::Input::ManipulationCompletedEventHandler;
};

template <> struct traits<Windows::UI::Xaml::Input::ManipulationDeltaEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::Input::ManipulationDeltaEventHandler;
};

template <> struct traits<Windows::UI::Xaml::Input::ManipulationInertiaStartingEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::Input::ManipulationInertiaStartingEventHandler;
};

template <> struct traits<Windows::UI::Xaml::Input::ManipulationStartedEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::Input::ManipulationStartedEventHandler;
};

template <> struct traits<Windows::UI::Xaml::Input::ManipulationStartingEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::Input::ManipulationStartingEventHandler;
};

template <> struct traits<Windows::UI::Xaml::Input::PointerEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::Input::PointerEventHandler;
};

template <> struct traits<Windows::UI::Xaml::Input::RightTappedEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::Input::RightTappedEventHandler;
};

template <> struct traits<Windows::UI::Xaml::Input::TappedEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::Input::TappedEventHandler;
};

template <> struct traits<Windows::UI::Xaml::Input::AccessKeyDisplayDismissedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Input::AccessKeyDisplayDismissedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Input.AccessKeyDisplayDismissedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Input::AccessKeyDisplayRequestedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Input::AccessKeyDisplayRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Input.AccessKeyDisplayRequestedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Input::AccessKeyInvokedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Input::AccessKeyInvokedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Input.AccessKeyInvokedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Input::AccessKeyManager>
{
    using abi = ABI::Windows::UI::Xaml::Input::AccessKeyManager;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Input.AccessKeyManager"; }
};

template <> struct traits<Windows::UI::Xaml::Input::ContextRequestedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Input::ContextRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Input.ContextRequestedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Input::DoubleTappedRoutedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Input::DoubleTappedRoutedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Input.DoubleTappedRoutedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Input::FocusManager>
{
    using abi = ABI::Windows::UI::Xaml::Input::FocusManager;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Input.FocusManager"; }
};

template <> struct traits<Windows::UI::Xaml::Input::HoldingRoutedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Input::HoldingRoutedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Input.HoldingRoutedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Input::InertiaExpansionBehavior>
{
    using abi = ABI::Windows::UI::Xaml::Input::InertiaExpansionBehavior;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Input.InertiaExpansionBehavior"; }
};

template <> struct traits<Windows::UI::Xaml::Input::InertiaRotationBehavior>
{
    using abi = ABI::Windows::UI::Xaml::Input::InertiaRotationBehavior;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Input.InertiaRotationBehavior"; }
};

template <> struct traits<Windows::UI::Xaml::Input::InertiaTranslationBehavior>
{
    using abi = ABI::Windows::UI::Xaml::Input::InertiaTranslationBehavior;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Input.InertiaTranslationBehavior"; }
};

template <> struct traits<Windows::UI::Xaml::Input::InputScope>
{
    using abi = ABI::Windows::UI::Xaml::Input::InputScope;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Input.InputScope"; }
};

template <> struct traits<Windows::UI::Xaml::Input::InputScopeName>
{
    using abi = ABI::Windows::UI::Xaml::Input::InputScopeName;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Input.InputScopeName"; }
};

template <> struct traits<Windows::UI::Xaml::Input::KeyRoutedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Input::KeyRoutedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Input.KeyRoutedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Input::ManipulationCompletedRoutedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Input::ManipulationCompletedRoutedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Input.ManipulationCompletedRoutedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Input::ManipulationDeltaRoutedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Input::ManipulationDeltaRoutedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Input.ManipulationDeltaRoutedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Input::ManipulationInertiaStartingRoutedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Input::ManipulationInertiaStartingRoutedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Input.ManipulationInertiaStartingRoutedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Input::ManipulationPivot>
{
    using abi = ABI::Windows::UI::Xaml::Input::ManipulationPivot;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Input.ManipulationPivot"; }
};

template <> struct traits<Windows::UI::Xaml::Input::ManipulationStartedRoutedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Input::ManipulationStartedRoutedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Input.ManipulationStartedRoutedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Input::ManipulationStartingRoutedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Input::ManipulationStartingRoutedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Input.ManipulationStartingRoutedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Input::Pointer>
{
    using abi = ABI::Windows::UI::Xaml::Input::Pointer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Input.Pointer"; }
};

template <> struct traits<Windows::UI::Xaml::Input::PointerRoutedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Input::PointerRoutedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Input.PointerRoutedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Input::RightTappedRoutedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Input::RightTappedRoutedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Input.RightTappedRoutedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Input::TappedRoutedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Input::TappedRoutedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Input.TappedRoutedEventArgs"; }
};

}

}
