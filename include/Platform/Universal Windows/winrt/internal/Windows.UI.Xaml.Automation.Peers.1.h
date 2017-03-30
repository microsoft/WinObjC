// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.UI.Xaml.Automation.Peers.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.UI.Xaml.0.h"
#include "Windows.UI.Xaml.Automation.0.h"
#include "Windows.UI.Xaml.Automation.Provider.0.h"
#include "Windows.UI.Xaml.Controls.0.h"
#include "Windows.UI.Xaml.Controls.Primitives.0.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Xaml::Automation::Peers {

struct RawElementProviderRuntimeId
{
    uint32_t Part1;
    uint32_t Part2;
};

}

namespace Windows::UI::Xaml::Automation::Peers {

using RawElementProviderRuntimeId = ABI::Windows::UI::Xaml::Automation::Peers::RawElementProviderRuntimeId;

}

namespace ABI::Windows::UI::Xaml::Automation::Peers {

struct __declspec(uuid("8b4acfeb-89fa-4f13-84be-35ca5b7c9590")) __declspec(novtable) IAppBarAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("8360f4e2-e396-4517-af5d-f4cf34c54edf")) __declspec(novtable) IAppBarAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IAppBar * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IAppBarAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("443262b2-4f6d-4b76-9d2e-3eff777e8864")) __declspec(novtable) IAppBarButtonAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("aef0342a-acb7-42dc-97e3-847071865fd6")) __declspec(novtable) IAppBarButtonAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IAppBarButton * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IAppBarButtonAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("8464efad-9655-4aff-9550-63ae9ec8fe9c")) __declspec(novtable) IAppBarToggleButtonAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("d6f9139d-02c1-4221-9591-7d4efeb74701")) __declspec(novtable) IAppBarToggleButtonAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IAppBarToggleButton * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IAppBarToggleButtonAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("2f32c302-f99b-491d-9726-a5e181643efa")) __declspec(novtable) IAutoSuggestBoxAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("80046849-18e7-4475-b362-4bbd53d24562")) __declspec(novtable) IAutoSuggestBoxAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IAutoSuggestBox * owner, Windows::UI::Xaml::Automation::Peers::IAutoSuggestBoxAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("35aac87a-62ee-4d3e-a24c-2bc8432d68b7")) __declspec(novtable) IAutomationPeer : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_EventsSource(Windows::UI::Xaml::Automation::Peers::IAutomationPeer ** value) = 0;
    virtual HRESULT __stdcall put_EventsSource(Windows::UI::Xaml::Automation::Peers::IAutomationPeer * value) = 0;
    virtual HRESULT __stdcall abi_GetPattern(winrt::Windows::UI::Xaml::Automation::Peers::PatternInterface patternInterface, Windows::Foundation::IInspectable ** returnValue) = 0;
    virtual HRESULT __stdcall abi_RaiseAutomationEvent(winrt::Windows::UI::Xaml::Automation::Peers::AutomationEvents eventId) = 0;
    virtual HRESULT __stdcall abi_RaisePropertyChangedEvent(Windows::UI::Xaml::Automation::IAutomationProperty * automationProperty, Windows::Foundation::IInspectable * oldValue, Windows::Foundation::IInspectable * newValue) = 0;
    virtual HRESULT __stdcall abi_GetAcceleratorKey(hstring * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetAccessKey(hstring * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetAutomationControlType(winrt::Windows::UI::Xaml::Automation::Peers::AutomationControlType * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetAutomationId(hstring * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetBoundingRectangle(Windows::Foundation::Rect * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetChildren(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Automation::Peers::AutomationPeer> ** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetClassName(hstring * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetClickablePoint(Windows::Foundation::Point * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetHelpText(hstring * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetItemStatus(hstring * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetItemType(hstring * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetLabeledBy(Windows::UI::Xaml::Automation::Peers::IAutomationPeer ** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetLocalizedControlType(hstring * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetName(hstring * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetOrientation(winrt::Windows::UI::Xaml::Automation::Peers::AutomationOrientation * returnValue) = 0;
    virtual HRESULT __stdcall abi_HasKeyboardFocus(bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_IsContentElement(bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_IsControlElement(bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_IsEnabled(bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_IsKeyboardFocusable(bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_IsOffscreen(bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_IsPassword(bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_IsRequiredForForm(bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_SetFocus() = 0;
    virtual HRESULT __stdcall abi_GetParent(Windows::UI::Xaml::Automation::Peers::IAutomationPeer ** returnValue) = 0;
    virtual HRESULT __stdcall abi_InvalidatePeer() = 0;
    virtual HRESULT __stdcall abi_GetPeerFromPoint(Windows::Foundation::Point point, Windows::UI::Xaml::Automation::Peers::IAutomationPeer ** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetLiveSetting(winrt::Windows::UI::Xaml::Automation::Peers::AutomationLiveSetting * returnValue) = 0;
};

struct __declspec(uuid("ea1f89c7-ebf5-4ab8-88f7-680d821dac61")) __declspec(novtable) IAutomationPeer2 : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("d3cfb977-0084-41d7-a221-28158d3bc32c")) __declspec(novtable) IAutomationPeer3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Navigate(winrt::Windows::UI::Xaml::Automation::Peers::AutomationNavigationDirection direction, Windows::Foundation::IInspectable ** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetElementFromPoint(Windows::Foundation::Point pointInWindowCoordinates, Windows::Foundation::IInspectable ** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetFocusedElement(Windows::Foundation::IInspectable ** returnValue) = 0;
    virtual HRESULT __stdcall abi_ShowContextMenu() = 0;
    virtual HRESULT __stdcall abi_GetControlledPeers(Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Automation::Peers::AutomationPeer> ** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetAnnotations(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation> ** returnValue) = 0;
    virtual HRESULT __stdcall abi_SetParent(Windows::UI::Xaml::Automation::Peers::IAutomationPeer * peer) = 0;
    virtual HRESULT __stdcall abi_RaiseTextEditTextChangedEvent(winrt::Windows::UI::Xaml::Automation::AutomationTextEditChangeType automationTextEditChangeType, Windows::Foundation::Collections::IVectorView<hstring> * changedData) = 0;
    virtual HRESULT __stdcall abi_GetPositionInSet(int32_t * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetSizeOfSet(int32_t * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetLevel(int32_t * returnValue) = 0;
    virtual HRESULT __stdcall abi_RaiseStructureChangedEvent(winrt::Windows::UI::Xaml::Automation::Peers::AutomationStructureChangeType structureChangeType, Windows::UI::Xaml::Automation::Peers::IAutomationPeer * child) = 0;
};

struct __declspec(uuid("761ce752-73c1-4f44-be75-43c49ec0d4d5")) __declspec(novtable) IAutomationPeer4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetLandmarkType(winrt::Windows::UI::Xaml::Automation::Peers::AutomationLandmarkType * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetLocalizedLandmarkType(hstring * returnValue) = 0;
};

struct __declspec(uuid("f632e1c6-0a3f-4574-9fef-cdc151765674")) __declspec(novtable) IAutomationPeer5 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_IsPeripheral(bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_IsDataValidForForm(bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetFullDescription(hstring * returnValue) = 0;
};

struct __declspec(uuid("0c456061-52cf-43fa-82f8-07f137351e5a")) __declspec(novtable) IAutomationPeerAnnotation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Type(winrt::Windows::UI::Xaml::Automation::AnnotationType * value) = 0;
    virtual HRESULT __stdcall put_Type(winrt::Windows::UI::Xaml::Automation::AnnotationType value) = 0;
    virtual HRESULT __stdcall get_Peer(Windows::UI::Xaml::Automation::Peers::IAutomationPeer ** value) = 0;
    virtual HRESULT __stdcall put_Peer(Windows::UI::Xaml::Automation::Peers::IAutomationPeer * value) = 0;
};

struct __declspec(uuid("f59c439e-c65b-43cd-9009-03fc023363a7")) __declspec(novtable) IAutomationPeerAnnotationFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(winrt::Windows::UI::Xaml::Automation::AnnotationType type, Windows::UI::Xaml::Automation::Peers::IAutomationPeerAnnotation ** instance) = 0;
    virtual HRESULT __stdcall abi_CreateWithPeerParameter(winrt::Windows::UI::Xaml::Automation::AnnotationType type, Windows::UI::Xaml::Automation::Peers::IAutomationPeer * peer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerAnnotation ** instance) = 0;
};

struct __declspec(uuid("8809a87d-09b2-4d45-b78b-1d3b3b09f661")) __declspec(novtable) IAutomationPeerAnnotationStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TypeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PeerProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("20c27545-a88b-43c8-bc24-cea9dafd04a3")) __declspec(novtable) IAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("bea93e67-dbee-4f7b-af0d-a79aae5333bf")) __declspec(novtable) IAutomationPeerOverrides : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetPatternCore(winrt::Windows::UI::Xaml::Automation::Peers::PatternInterface patternInterface, Windows::Foundation::IInspectable ** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetAcceleratorKeyCore(hstring * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetAccessKeyCore(hstring * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetAutomationControlTypeCore(winrt::Windows::UI::Xaml::Automation::Peers::AutomationControlType * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetAutomationIdCore(hstring * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetBoundingRectangleCore(Windows::Foundation::Rect * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetChildrenCore(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Automation::Peers::AutomationPeer> ** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetClassNameCore(hstring * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetClickablePointCore(Windows::Foundation::Point * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetHelpTextCore(hstring * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetItemStatusCore(hstring * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetItemTypeCore(hstring * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetLabeledByCore(Windows::UI::Xaml::Automation::Peers::IAutomationPeer ** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetLocalizedControlTypeCore(hstring * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetNameCore(hstring * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetOrientationCore(winrt::Windows::UI::Xaml::Automation::Peers::AutomationOrientation * returnValue) = 0;
    virtual HRESULT __stdcall abi_HasKeyboardFocusCore(bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_IsContentElementCore(bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_IsControlElementCore(bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_IsEnabledCore(bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_IsKeyboardFocusableCore(bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_IsOffscreenCore(bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_IsPasswordCore(bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_IsRequiredForFormCore(bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_SetFocusCore() = 0;
    virtual HRESULT __stdcall abi_GetPeerFromPointCore(Windows::Foundation::Point point, Windows::UI::Xaml::Automation::Peers::IAutomationPeer ** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetLiveSettingCore(winrt::Windows::UI::Xaml::Automation::Peers::AutomationLiveSetting * returnValue) = 0;
};

struct __declspec(uuid("2603682a-9da6-4023-b496-496e5ef228d2")) __declspec(novtable) IAutomationPeerOverrides2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ShowContextMenuCore() = 0;
    virtual HRESULT __stdcall abi_GetControlledPeersCore(Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Automation::Peers::AutomationPeer> ** returnValue) = 0;
};

struct __declspec(uuid("b6f0c4ad-4d39-49e6-bb91-d924eefd8538")) __declspec(novtable) IAutomationPeerOverrides3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_NavigateCore(winrt::Windows::UI::Xaml::Automation::Peers::AutomationNavigationDirection direction, Windows::Foundation::IInspectable ** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetElementFromPointCore(Windows::Foundation::Point pointInWindowCoordinates, Windows::Foundation::IInspectable ** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetFocusedElementCore(Windows::Foundation::IInspectable ** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetAnnotationsCore(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation> ** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetPositionInSetCore(int32_t * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetSizeOfSetCore(int32_t * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetLevelCore(int32_t * returnValue) = 0;
};

struct __declspec(uuid("b186cda2-5d46-4bcd-a811-269ad15b3aee")) __declspec(novtable) IAutomationPeerOverrides4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetLandmarkTypeCore(winrt::Windows::UI::Xaml::Automation::Peers::AutomationLandmarkType * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetLocalizedLandmarkTypeCore(hstring * returnValue) = 0;
};

struct __declspec(uuid("2c847c85-781e-49f7-9fef-b9e14d014707")) __declspec(novtable) IAutomationPeerOverrides5 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_IsPeripheralCore(bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_IsDataValidForFormCore(bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetFullDescriptionCore(hstring * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetDescribedByCore(Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::Automation::Peers::AutomationPeer> ** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetFlowsToCore(Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::Automation::Peers::AutomationPeer> ** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetFlowsFromCore(Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::Automation::Peers::AutomationPeer> ** returnValue) = 0;
};

struct __declspec(uuid("f4b40e52-642f-4629-a54a-ea5d2349c448")) __declspec(novtable) IAutomationPeerProtected : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_PeerFromProvider(Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple * provider, Windows::UI::Xaml::Automation::Peers::IAutomationPeer ** returnValue) = 0;
    virtual HRESULT __stdcall abi_ProviderFromPeer(Windows::UI::Xaml::Automation::Peers::IAutomationPeer * peer, Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple ** returnValue) = 0;
};

struct __declspec(uuid("562f7fb0-a331-4a9c-9dec-bfb7586fffff")) __declspec(novtable) IAutomationPeerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ListenerExists(winrt::Windows::UI::Xaml::Automation::Peers::AutomationEvents eventId, bool * returnValue) = 0;
};

struct __declspec(uuid("572c5714-7f87-4271-819f-6cf4c4d022d0")) __declspec(novtable) IAutomationPeerStatics3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GenerateRawElementProviderRuntimeId(Windows::UI::Xaml::Automation::Peers::RawElementProviderRuntimeId * returnValue) = 0;
};

struct __declspec(uuid("fb77efbe-39ec-4508-8ac3-51a1424027d7")) __declspec(novtable) IButtonAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("3fdb9f49-f4ab-4780-8644-03376299a175")) __declspec(novtable) IButtonAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IButton * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IButtonAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("a4f3b5b6-7585-4e0b-96d2-08cf6f28befa")) __declspec(novtable) IButtonBaseAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("8a04091e-e6b2-4c60-a759-c13ca45165ed")) __declspec(novtable) IButtonBaseAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::Primitives::IButtonBase * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("dcc44ee0-fa45-45c6-8bb7-320d808f5958")) __declspec(novtable) ICaptureElementAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("9b92ef48-85e9-4869-b175-8f7cf45a6d9f")) __declspec(novtable) ICaptureElementAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::ICaptureElement * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::ICaptureElementAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("eb15bc42-c0a9-46c6-ac24-b83de429c733")) __declspec(novtable) ICheckBoxAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("b75c775d-eb8f-44ef-a27c-e26ac7de8333")) __declspec(novtable) ICheckBoxAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::ICheckBox * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::ICheckBoxAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("7eb40d0b-75c5-4263-ba6a-d4a54fb0f239")) __declspec(novtable) IComboBoxAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("098e5b0d-1b90-40b9-9be3-b23267eb13cf")) __declspec(novtable) IComboBoxAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IComboBox * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IComboBoxAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("12ddc76e-9552-446a-82ee-938cc371800f")) __declspec(novtable) IComboBoxItemAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("134ac7fc-397a-403f-a6ec-1ce8beda15e5")) __declspec(novtable) IComboBoxItemAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IComboBoxItem * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IComboBoxItemAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("4fef6df2-289c-4c04-831b-5a668c6d7104")) __declspec(novtable) IComboBoxItemDataAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("14a8d4f6-469a-41ba-9d93-44a1a55da872")) __declspec(novtable) IComboBoxItemDataAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithParentAndItem(Windows::Foundation::IInspectable * item, Windows::UI::Xaml::Automation::Peers::IComboBoxAutomationPeer * parent, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IComboBoxItemDataAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("d07d357f-a0b9-45dc-991a-76c505e7d0f5")) __declspec(novtable) IDatePickerAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("e5667d19-9157-4436-9f4d-7fb99174b48e")) __declspec(novtable) IDatePickerAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IDatePicker * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IDatePickerAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("752aed38-c2bf-4880-82b2-a6c05e90c135")) __declspec(novtable) IDatePickerFlyoutPresenterAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("8ec0353a-4284-4b00-aef8-a2688ea5e3c4")) __declspec(novtable) IFlipViewAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("4395ab0d-8d83-483c-88eb-e2617b0d293f")) __declspec(novtable) IFlipViewAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IFlipView * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IFlipViewAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("c83034de-fa08-4bd3-aeb2-d2e5bfa04df9")) __declspec(novtable) IFlipViewItemAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("69109356-d0e5-4c10-a09c-ad0bf1b0cb01")) __declspec(novtable) IFlipViewItemAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IFlipViewItem * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IFlipViewItemAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("b0986175-00bc-4118-8a6f-16ee9c15d968")) __declspec(novtable) IFlipViewItemDataAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("3c864393-0aea-4e78-bc11-b775cac4114c")) __declspec(novtable) IFlipViewItemDataAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithParentAndItem(Windows::Foundation::IInspectable * item, Windows::UI::Xaml::Automation::Peers::IFlipViewAutomationPeer * parent, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IFlipViewItemDataAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("a01840b4-5fca-456f-98ea-300eb40b585e")) __declspec(novtable) IFlyoutPresenterAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("f350155f-8924-44c0-ba44-653fe79f1efb")) __declspec(novtable) IFlyoutPresenterAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IFlyoutPresenter * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IFlyoutPresenterAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("b90ad781-bfeb-4451-bd47-9f3a63ebd24a")) __declspec(novtable) IFrameworkElementAutomationPeer : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Owner(Windows::UI::Xaml::IUIElement ** value) = 0;
};

struct __declspec(uuid("0db9b8bc-b812-48e3-af1f-dbc57600c325")) __declspec(novtable) IFrameworkElementAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::IFrameworkElement * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("b9c0b997-2820-44a1-a5a8-9b801edc269e")) __declspec(novtable) IFrameworkElementAutomationPeerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FromElement(Windows::UI::Xaml::IUIElement * element, Windows::UI::Xaml::Automation::Peers::IAutomationPeer ** returnValue) = 0;
    virtual HRESULT __stdcall abi_CreatePeerForElement(Windows::UI::Xaml::IUIElement * element, Windows::UI::Xaml::Automation::Peers::IAutomationPeer ** returnValue) = 0;
};

struct __declspec(uuid("1c4401a4-d951-49ca-8f82-c7f3c60681b0")) __declspec(novtable) IGridViewAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("8aca59dd-22a7-4800-894b-c1f485f38953")) __declspec(novtable) IGridViewAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IGridView * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IGridViewAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("e3dcef3a-e08a-48e7-b23a-2be5b66e474e")) __declspec(novtable) IGridViewHeaderItemAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("2c80b4d2-ffc2-4157-88dd-59cd92e39715")) __declspec(novtable) IGridViewHeaderItemAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IGridViewHeaderItem * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IGridViewHeaderItemAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("93ef2d07-346c-4166-a4ba-bc6a181e7f33")) __declspec(novtable) IGridViewItemAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("fafec376-f22e-466d-913c-ae24ccdb160f")) __declspec(novtable) IGridViewItemAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IGridViewItem * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IGridViewItemAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("f3f4868f-29d4-4094-8c54-ea61a88294a4")) __declspec(novtable) IGridViewItemDataAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("a65e7a88-770d-402c-996f-67506af2a4af")) __declspec(novtable) IGridViewItemDataAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithParentAndItem(Windows::Foundation::IInspectable * item, Windows::UI::Xaml::Automation::Peers::IGridViewAutomationPeer * parent, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IGridViewItemDataAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("1914fe6d-0740-4236-9ee1-38cf19c1c388")) __declspec(novtable) IGroupItemAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("56a64567-f21c-4c90-b379-15a27c7f8409")) __declspec(novtable) IGroupItemAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IGroupItem * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IGroupItemAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("4ddee056-4ebc-4620-a05d-903e3c9a4ead")) __declspec(novtable) IHubAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("c762d43f-79dd-43ee-8777-8d08b39aa065")) __declspec(novtable) IHubAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IHub * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IHubAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("16d91ff7-7431-4d82-83ce-cfa3192b0f18")) __declspec(novtable) IHubSectionAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("c68e27e8-17ec-4329-91ae-2d0b2339d498")) __declspec(novtable) IHubSectionAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IHubSection * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IHubSectionAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("aa7afcb1-0edf-46d9-aa9e-0eb21d140097")) __declspec(novtable) IHyperlinkButtonAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("59bc1661-c182-49af-9526-44b88e628455")) __declspec(novtable) IHyperlinkButtonAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IHyperlinkButton * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IHyperlinkButtonAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("9b0bbf8c-60a2-48bf-ab2c-1a52a451d2d4")) __declspec(novtable) IImageAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("90304003-687d-47bf-b3a2-4babcad8ef50")) __declspec(novtable) IImageAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IImage * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IImageAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("123baaa4-f2e8-4bcb-9382-5dfdd11fe45f")) __declspec(novtable) IInkToolbarAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("953c34f6-3b31-47a7-b3bf-25d3ae99c317")) __declspec(novtable) IItemAutomationPeer : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Item(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall get_ItemsControlAutomationPeer(Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer ** value) = 0;
};

struct __declspec(uuid("29065073-de3d-4d3f-97b4-4d6f9d53444d")) __declspec(novtable) IItemAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithParentAndItem(Windows::Foundation::IInspectable * item, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer * parent, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("96e76bf1-37f7-4088-925d-65268e83e34d")) __declspec(novtable) IItemsControlAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("c48d8917-95a8-47b8-a517-bf891a6c039b")) __declspec(novtable) IItemsControlAutomationPeer2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateItemAutomationPeer(Windows::Foundation::IInspectable * item, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer ** returnValue) = 0;
};

struct __declspec(uuid("4038a259-2e1a-49ca-a533-c64f181577e6")) __declspec(novtable) IItemsControlAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IItemsControl * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("361dc0e8-b56f-45e9-80fe-10a0fb0fe177")) __declspec(novtable) IItemsControlAutomationPeerOverrides2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_OnCreateItemAutomationPeer(Windows::Foundation::IInspectable * item, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer ** returnValue) = 0;
};

struct __declspec(uuid("8cd0d608-b402-4a6e-bd9a-343f8845eb32")) __declspec(novtable) IListBoxAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("e2362185-7df6-49f7-8abc-4c33f1a3d46e")) __declspec(novtable) IListBoxAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IListBox * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IListBoxAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("1bc6e1c6-2997-42df-99eb-92bc1dd149fb")) __declspec(novtable) IListBoxItemAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("509f9dd8-b0aa-443f-a110-41209af44f1c")) __declspec(novtable) IListBoxItemAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IListBoxItem * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IListBoxItemAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("fd7d5fee-fde0-482a-8084-dcebba5b9806")) __declspec(novtable) IListBoxItemDataAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("d7924e16-bd8d-4662-a995-20ff9a056093")) __declspec(novtable) IListBoxItemDataAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithParentAndItem(Windows::Foundation::IInspectable * item, Windows::UI::Xaml::Automation::Peers::IListBoxAutomationPeer * parent, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IListBoxItemDataAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("56dfdc58-2395-4060-8047-8ea463698a24")) __declspec(novtable) IListPickerFlyoutPresenterAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("73cecc87-c0dc-4260-9148-75e9864a7230")) __declspec(novtable) IListViewAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("65f39174-eaa2-4e44-8be6-4cca28cd0288")) __declspec(novtable) IListViewAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IListView * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IListViewAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("87ec7649-b83d-4e55-9afd-bd835e748f5c")) __declspec(novtable) IListViewBaseAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("70d3c2be-8950-4647-9362-fd002f8ff82e")) __declspec(novtable) IListViewBaseAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IListViewBase * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("7cb8b732-c1f0-4a3c-bc14-85dd48dedb85")) __declspec(novtable) IListViewBaseHeaderItemAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("40ec995f-d631-4004-832e-6d8643e51561")) __declspec(novtable) IListViewBaseHeaderItemAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IListViewBaseHeaderItem * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IListViewBaseHeaderItemAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("67ab1e4b-ad61-4c88-ba45-0f3a8d061f8f")) __declspec(novtable) IListViewHeaderItemAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("07668694-2ca5-4be4-a8b9-592d48f76087")) __declspec(novtable) IListViewHeaderItemAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IListViewHeaderItem * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IListViewHeaderItemAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("ca114e70-a16d-4d09-a1cf-1856ef98a9ec")) __declspec(novtable) IListViewItemAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("c47dfbc0-facc-4024-a73b-17ec4e662654")) __declspec(novtable) IListViewItemAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IListViewItem * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IListViewItemAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("15a8d7fd-d7a5-4a6c-963c-6f7ce464671a")) __declspec(novtable) IListViewItemDataAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("d0db12bb-d715-4523-acc0-1e1072d8e32b")) __declspec(novtable) IListViewItemDataAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithParentAndItem(Windows::Foundation::IInspectable * item, Windows::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeer * parent, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IListViewItemDataAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("50b406ca-bae9-4816-8a3a-0cb4f96478a2")) __declspec(novtable) ILoopingSelectorAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("d3fa68bf-04cf-4f4c-8d3e-4780a19d4788")) __declspec(novtable) ILoopingSelectorItemAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("ef567e32-7cd2-4d32-9590-1f588d5ef38d")) __declspec(novtable) ILoopingSelectorItemDataAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("425beee4-f2e8-4bcb-9382-5dfdd11fe45f")) __declspec(novtable) IMapControlAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("ba0b9fc2-a6e2-41a5-b17a-d1594613efba")) __declspec(novtable) IMediaElementAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("b2ad3b28-7575-4173-9bc7-80367a164ed2")) __declspec(novtable) IMediaElementAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IMediaElement * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IMediaElementAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("02bed209-3f65-4fdd-b5ca-c4750d4e6ea4")) __declspec(novtable) IMediaPlayerElementAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("08848077-82af-4d19-b170-282a9e0e7f37")) __declspec(novtable) IMediaPlayerElementAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IMediaPlayerElement * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IMediaPlayerElementAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("a3ad8d93-79f8-4958-a3c8-980defb83d15")) __declspec(novtable) IMediaTransportControlsAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("f41cb003-e103-4ab0-812a-a08fbdb570ce")) __declspec(novtable) IMediaTransportControlsAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IMediaTransportControls * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IMediaTransportControlsAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("1fc19462-21df-456e-aa11-8fac6b4b2af6")) __declspec(novtable) IMenuFlyoutItemAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("d08bfcb8-20d1-45d8-a2c2-2f130df714e0")) __declspec(novtable) IMenuFlyoutItemAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IMenuFlyoutItem * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IMenuFlyoutItemAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("e244a871-fcbb-48fc-8a93-41ea134b53ce")) __declspec(novtable) IMenuFlyoutPresenterAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("07b5172d-761d-452b-9e6d-fa2a8be0ad26")) __declspec(novtable) IMenuFlyoutPresenterAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IMenuFlyoutPresenter * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IMenuFlyoutPresenterAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("684f065e-3df3-4b9f-82ad-8819db3b218a")) __declspec(novtable) IPasswordBoxAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("ac3d7ede-dca4-481c-b520-4a9b3f3b179c")) __declspec(novtable) IPasswordBoxAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IPasswordBox * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IPasswordBoxAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("28414bf7-8382-4eae-93c1-d6f035aa8155")) __declspec(novtable) IPickerFlyoutPresenterAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("e715a8f8-3b9d-402c-81e2-6e912ef58981")) __declspec(novtable) IPivotAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("3efe0f94-0c91-4341-b9ac-1b56b4e6b84f")) __declspec(novtable) IPivotAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IPivot * owner, Windows::UI::Xaml::Automation::Peers::IPivotAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("1a4241ad-5d55-4d27-b40f-2d37506fbe78")) __declspec(novtable) IPivotItemAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("f2810471-183f-416b-b41a-1e5a958a91f4")) __declspec(novtable) IPivotItemAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IPivotItem * owner, Windows::UI::Xaml::Automation::Peers::IPivotItemAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("a2a3b788-ea1d-48b7-88ee-f08b6aa07fee")) __declspec(novtable) IPivotItemDataAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("517a2480-d3b6-412e-82b6-94a0a84c13b0")) __declspec(novtable) IPivotItemDataAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithParentAndItem(Windows::Foundation::IInspectable * item, Windows::UI::Xaml::Automation::Peers::IPivotAutomationPeer * parent, Windows::UI::Xaml::Automation::Peers::IPivotItemDataAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("93f48f86-d840-4fb6-ac2f-5f779b854b0d")) __declspec(novtable) IProgressBarAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("364679ab-b80f-41b4-8eea-2f5251bc739c")) __declspec(novtable) IProgressBarAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IProgressBar * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IProgressBarAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("bc305eee-39d3-4eeb-ac33-2394de123e2e")) __declspec(novtable) IProgressRingAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("f3db204b-157e-40bc-9593-55bc5c71a4f6")) __declspec(novtable) IProgressRingAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IProgressRing * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IProgressRingAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("7e6a5ed8-0b30-4743-b102-dcdf548e3131")) __declspec(novtable) IRadioButtonAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("4940c4fd-3d88-49ca-8f31-924187af0bfe")) __declspec(novtable) IRadioButtonAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IRadioButton * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IRadioButtonAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("e454b549-4b2c-42ad-b04b-d35947d1ee50")) __declspec(novtable) IRangeBaseAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("827c7601-3078-4479-95ea-91374ca06207")) __declspec(novtable) IRangeBaseAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::Primitives::IRangeBase * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("29e41ad5-a8ac-4e8a-83d8-09e37e054257")) __declspec(novtable) IRepeatButtonAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("6a6ff9d4-575e-4e60-bdd6-ec14419b4ff6")) __declspec(novtable) IRepeatButtonAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::Primitives::IRepeatButton * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IRepeatButtonAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("c69f5c04-16ee-467a-a833-c3da8458ad64")) __declspec(novtable) IRichEditBoxAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("752c8399-d296-4d87-9020-a4750e885b3c")) __declspec(novtable) IRichEditBoxAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IRichEditBox * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IRichEditBoxAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("93a01a9c-9609-41fa-82f3-909c09f49a72")) __declspec(novtable) IRichTextBlockAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("2038ae61-1389-467a-aed6-37334da9622b")) __declspec(novtable) IRichTextBlockAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IRichTextBlock * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IRichTextBlockAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("8c9a409a-2736-437b-ab36-a16a202f105d")) __declspec(novtable) IRichTextBlockOverflowAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("bd5eb663-2c14-4665-adef-f2b033947beb")) __declspec(novtable) IRichTextBlockOverflowAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IRichTextBlockOverflow * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IRichTextBlockOverflowAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("69e0c369-bbe7-41f2-87ca-aad813fe550e")) __declspec(novtable) IScrollBarAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("e1302110-afeb-4595-8e3d-edc0844a2b21")) __declspec(novtable) IScrollBarAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::Primitives::IScrollBar * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IScrollBarAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("d985f259-1b09-4e88-88fd-421750dc6b45")) __declspec(novtable) IScrollViewerAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("270dff7d-d96d-48f9-a36a-c252aa9c4670")) __declspec(novtable) IScrollViewerAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IScrollViewer * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IScrollViewerAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("854011a4-18a6-4f30-939b-8871afa3f5e9")) __declspec(novtable) ISearchBoxAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("b3c01430-7faa-41bb-8e91-7c761c5267f1")) __declspec(novtable) ISearchBoxAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::ISearchBox * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::ISearchBoxAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("162ac829-7115-43ec-b383-a7b71644069d")) __declspec(novtable) ISelectorAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("7b525646-829b-4dcc-bd52-5a8d0399387a")) __declspec(novtable) ISelectorAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::Primitives::ISelector * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("ae8b3477-860a-45bb-bf7c-e1b27419d1dd")) __declspec(novtable) ISelectorItemAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("66d7edfb-786d-4362-a964-ebfb21776c30")) __declspec(novtable) ISelectorItemAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithParentAndItem(Windows::Foundation::IInspectable * item, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer * parent, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("3c2fac6c-a977-47fc-b44e-2754c0b2bea9")) __declspec(novtable) ISemanticZoomAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("f518d44d-a493-4496-b077-9674c7f4c5fa")) __declspec(novtable) ISemanticZoomAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::ISemanticZoom * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::ISemanticZoomAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("d0de0cdb-30cf-47a6-a5eb-9c77f0b0d6dd")) __declspec(novtable) ISettingsFlyoutAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("f94762bd-8a14-40e4-94a7-3f33c922e945")) __declspec(novtable) ISettingsFlyoutAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::ISettingsFlyout * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::ISettingsFlyoutAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("ec30015a-d611-46d0-ae4f-6ecf27dfbaa5")) __declspec(novtable) ISliderAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("971b8056-9a7a-4df9-95fa-6f5c04c91cac")) __declspec(novtable) ISliderAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::ISlider * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::ISliderAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("be2057f5-6715-4e69-a050-92bd0ce232a9")) __declspec(novtable) ITextBlockAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("76bf924b-7ca0-4b01-bc5c-a8cf4d3691de")) __declspec(novtable) ITextBlockAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::ITextBlock * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::ITextBlockAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("3a4f1ca0-5e5d-4d26-9067-e740bf657a9f")) __declspec(novtable) ITextBoxAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("01f0c067-966b-4130-b872-469e42bd4a7f")) __declspec(novtable) ITextBoxAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::ITextBox * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::ITextBoxAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("dc2949b5-b45e-4d6d-892f-d9422c950efb")) __declspec(novtable) IThumbAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("970743ff-af41-4600-b55d-26d43df860e1")) __declspec(novtable) IThumbAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::Primitives::IThumb * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IThumbAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("a43d44ef-3285-4df7-b4a4-e4cdf36a3a17")) __declspec(novtable) ITimePickerAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("978f6671-47f8-40a7-9e21-68128b16b4fd")) __declspec(novtable) ITimePickerAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::ITimePicker * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::ITimePickerAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("da93ee27-82f1-4701-8706-be297bf06043")) __declspec(novtable) ITimePickerFlyoutPresenterAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("62dbe6c5-bc0a-45bb-bf77-ea0f1502891f")) __declspec(novtable) IToggleButtonAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("c9218cc4-ad4b-4d03-a6a4-7d59e6360004")) __declspec(novtable) IToggleButtonAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::Primitives::IToggleButton * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("6b57eafe-6af1-4903-8373-3437bf352345")) __declspec(novtable) IToggleMenuFlyoutItemAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("94364b77-8f6c-4837-aae3-94d010d8d162")) __declspec(novtable) IToggleMenuFlyoutItemAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IToggleMenuFlyoutItem * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IToggleMenuFlyoutItemAutomationPeer ** instance) = 0;
};

struct __declspec(uuid("c011f174-e89e-4790-bf9a-78ebb5f59e9f")) __declspec(novtable) IToggleSwitchAutomationPeer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("31f933e3-fef8-4419-9df5-d9ef7196ea34")) __declspec(novtable) IToggleSwitchAutomationPeerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithOwner(Windows::UI::Xaml::Controls::IToggleSwitch * owner, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Automation::Peers::IToggleSwitchAutomationPeer ** instance) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::UI::Xaml::Automation::Peers::AppBarAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IAppBarAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::AppBarButtonAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IAppBarButtonAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::AppBarToggleButtonAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IAppBarToggleButtonAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::AutoSuggestBoxAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IAutoSuggestBoxAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::AutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation> { using default_interface = Windows::UI::Xaml::Automation::Peers::IAutomationPeerAnnotation; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::ButtonAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IButtonAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::ButtonBaseAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::CaptureElementAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::ICaptureElementAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::CheckBoxAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::ICheckBoxAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::ComboBoxAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IComboBoxAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::ComboBoxItemAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IComboBoxItemAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::ComboBoxItemDataAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IComboBoxItemDataAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::DatePickerAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IDatePickerAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::DatePickerFlyoutPresenterAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IDatePickerFlyoutPresenterAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::FlipViewAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IFlipViewAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::FlipViewItemAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IFlipViewItemAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::FlipViewItemDataAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IFlipViewItemDataAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::FlyoutPresenterAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IFlyoutPresenterAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::GridViewAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IGridViewAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::GridViewHeaderItemAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IGridViewHeaderItemAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::GridViewItemAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IGridViewItemAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::GridViewItemDataAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IGridViewItemDataAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::GroupItemAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IGroupItemAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::HubAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IHubAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::HubSectionAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IHubSectionAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::HyperlinkButtonAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IHyperlinkButtonAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::ImageAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IImageAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::InkToolbarAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IInkToolbarAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::ItemAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::ListBoxAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IListBoxAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::ListBoxItemAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IListBoxItemAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::ListBoxItemDataAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IListBoxItemDataAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::ListPickerFlyoutPresenterAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IListPickerFlyoutPresenterAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::ListViewAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IListViewAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::ListViewBaseAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::ListViewBaseHeaderItemAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IListViewBaseHeaderItemAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::ListViewHeaderItemAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IListViewHeaderItemAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::ListViewItemAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IListViewItemAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::ListViewItemDataAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IListViewItemDataAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::LoopingSelectorAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::ILoopingSelectorAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::LoopingSelectorItemAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::ILoopingSelectorItemAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::LoopingSelectorItemDataAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::ILoopingSelectorItemDataAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::MapControlAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IMapControlAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::MediaElementAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IMediaElementAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::MediaPlayerElementAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IMediaPlayerElementAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::MediaTransportControlsAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IMediaTransportControlsAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::MenuFlyoutItemAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IMenuFlyoutItemAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::MenuFlyoutPresenterAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IMenuFlyoutPresenterAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::PasswordBoxAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IPasswordBoxAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::PickerFlyoutPresenterAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IPickerFlyoutPresenterAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::PivotAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IPivotAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::PivotItemAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IPivotItemAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::PivotItemDataAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IPivotItemDataAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::ProgressBarAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IProgressBarAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::ProgressRingAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IProgressRingAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::RadioButtonAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IRadioButtonAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::RangeBaseAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::RepeatButtonAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IRepeatButtonAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::RichEditBoxAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IRichEditBoxAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::RichTextBlockAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IRichTextBlockAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::RichTextBlockOverflowAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IRichTextBlockOverflowAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::ScrollBarAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IScrollBarAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::ScrollViewerAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IScrollViewerAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::SearchBoxAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::ISearchBoxAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::SelectorAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::SelectorItemAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::SemanticZoomAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::ISemanticZoomAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::SettingsFlyoutAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::ISettingsFlyoutAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::SliderAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::ISliderAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::TextBlockAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::ITextBlockAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::TextBoxAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::ITextBoxAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::ThumbAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IThumbAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::TimePickerAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::ITimePickerAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::TimePickerFlyoutPresenterAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::ITimePickerFlyoutPresenterAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::ToggleButtonAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::ToggleMenuFlyoutItemAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IToggleMenuFlyoutItemAutomationPeer; };
template <> struct traits<Windows::UI::Xaml::Automation::Peers::ToggleSwitchAutomationPeer> { using default_interface = Windows::UI::Xaml::Automation::Peers::IToggleSwitchAutomationPeer; };

}

namespace Windows::UI::Xaml::Automation::Peers {

template <typename D>
struct WINRT_EBO impl_IAppBarAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IAppBarAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::AppBarAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::AppBar & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IAppBarButtonAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IAppBarButtonAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::AppBarButtonAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::AppBarButton & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IAppBarToggleButtonAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IAppBarToggleButtonAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::AppBarToggleButtonAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::AppBarToggleButton & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IAutoSuggestBoxAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IAutoSuggestBoxAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::AutoSuggestBoxAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::AutoSuggestBox & owner) const;
};

template <typename D>
struct WINRT_EBO impl_IAutomationPeer
{
    Windows::UI::Xaml::Automation::Peers::AutomationPeer EventsSource() const;
    void EventsSource(const Windows::UI::Xaml::Automation::Peers::AutomationPeer & value) const;
    Windows::Foundation::IInspectable GetPattern(Windows::UI::Xaml::Automation::Peers::PatternInterface patternInterface) const;
    void RaiseAutomationEvent(Windows::UI::Xaml::Automation::Peers::AutomationEvents eventId) const;
    void RaisePropertyChangedEvent(const Windows::UI::Xaml::Automation::AutomationProperty & automationProperty, const Windows::Foundation::IInspectable & oldValue, const Windows::Foundation::IInspectable & newValue) const;
    hstring GetAcceleratorKey() const;
    hstring GetAccessKey() const;
    Windows::UI::Xaml::Automation::Peers::AutomationControlType GetAutomationControlType() const;
    hstring GetAutomationId() const;
    Windows::Foundation::Rect GetBoundingRectangle() const;
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Automation::Peers::AutomationPeer> GetChildren() const;
    hstring GetClassName() const;
    Windows::Foundation::Point GetClickablePoint() const;
    hstring GetHelpText() const;
    hstring GetItemStatus() const;
    hstring GetItemType() const;
    Windows::UI::Xaml::Automation::Peers::AutomationPeer GetLabeledBy() const;
    hstring GetLocalizedControlType() const;
    hstring GetName() const;
    Windows::UI::Xaml::Automation::Peers::AutomationOrientation GetOrientation() const;
    bool HasKeyboardFocus() const;
    bool IsContentElement() const;
    bool IsControlElement() const;
    bool IsEnabled() const;
    bool IsKeyboardFocusable() const;
    bool IsOffscreen() const;
    bool IsPassword() const;
    bool IsRequiredForForm() const;
    void SetFocus() const;
    [[deprecated("Consider using Navigate with AutomationNavigationDirection::Parent, which is an improved version of GetParent. For more info, see MSDN.")]] Windows::UI::Xaml::Automation::Peers::AutomationPeer GetParent() const;
    void InvalidatePeer() const;
    [[deprecated("Consider using GetElementFromPoint, which is an improved version of GetPeerFromPoint. For more info, see MSDN.")]] Windows::UI::Xaml::Automation::Peers::AutomationPeer GetPeerFromPoint(const Windows::Foundation::Point & point) const;
    Windows::UI::Xaml::Automation::Peers::AutomationLiveSetting GetLiveSetting() const;
};

template <typename D>
struct WINRT_EBO impl_IAutomationPeer2
{
};

template <typename D>
struct WINRT_EBO impl_IAutomationPeer3
{
    Windows::Foundation::IInspectable Navigate(Windows::UI::Xaml::Automation::Peers::AutomationNavigationDirection direction) const;
    Windows::Foundation::IInspectable GetElementFromPoint(const Windows::Foundation::Point & pointInWindowCoordinates) const;
    Windows::Foundation::IInspectable GetFocusedElement() const;
    void ShowContextMenu() const;
    Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Automation::Peers::AutomationPeer> GetControlledPeers() const;
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation> GetAnnotations() const;
    void SetParent(const Windows::UI::Xaml::Automation::Peers::AutomationPeer & peer) const;
    void RaiseTextEditTextChangedEvent(Windows::UI::Xaml::Automation::AutomationTextEditChangeType automationTextEditChangeType, vector_view<hstring> changedData) const;
    int32_t GetPositionInSet() const;
    int32_t GetSizeOfSet() const;
    int32_t GetLevel() const;
    void RaiseStructureChangedEvent(Windows::UI::Xaml::Automation::Peers::AutomationStructureChangeType structureChangeType, const Windows::UI::Xaml::Automation::Peers::AutomationPeer & child) const;
};

template <typename D>
struct WINRT_EBO impl_IAutomationPeer4
{
    Windows::UI::Xaml::Automation::Peers::AutomationLandmarkType GetLandmarkType() const;
    hstring GetLocalizedLandmarkType() const;
};

template <typename D>
struct WINRT_EBO impl_IAutomationPeer5
{
    bool IsPeripheral() const;
    bool IsDataValidForForm() const;
    hstring GetFullDescription() const;
};

template <typename D>
struct WINRT_EBO impl_IAutomationPeerAnnotation
{
    Windows::UI::Xaml::Automation::AnnotationType Type() const;
    void Type(Windows::UI::Xaml::Automation::AnnotationType value) const;
    Windows::UI::Xaml::Automation::Peers::AutomationPeer Peer() const;
    void Peer(const Windows::UI::Xaml::Automation::Peers::AutomationPeer & value) const;
};

template <typename D>
struct WINRT_EBO impl_IAutomationPeerAnnotationFactory
{
    Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation CreateInstance(Windows::UI::Xaml::Automation::AnnotationType type) const;
    Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation CreateWithPeerParameter(Windows::UI::Xaml::Automation::AnnotationType type, const Windows::UI::Xaml::Automation::Peers::AutomationPeer & peer) const;
};

template <typename D>
struct WINRT_EBO impl_IAutomationPeerAnnotationStatics
{
    Windows::UI::Xaml::DependencyProperty TypeProperty() const;
    Windows::UI::Xaml::DependencyProperty PeerProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::AutomationPeer CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IAutomationPeerOverrides
{
    Windows::Foundation::IInspectable GetPatternCore(Windows::UI::Xaml::Automation::Peers::PatternInterface patternInterface) const;
    hstring GetAcceleratorKeyCore() const;
    hstring GetAccessKeyCore() const;
    Windows::UI::Xaml::Automation::Peers::AutomationControlType GetAutomationControlTypeCore() const;
    hstring GetAutomationIdCore() const;
    Windows::Foundation::Rect GetBoundingRectangleCore() const;
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Automation::Peers::AutomationPeer> GetChildrenCore() const;
    hstring GetClassNameCore() const;
    Windows::Foundation::Point GetClickablePointCore() const;
    hstring GetHelpTextCore() const;
    hstring GetItemStatusCore() const;
    hstring GetItemTypeCore() const;
    Windows::UI::Xaml::Automation::Peers::AutomationPeer GetLabeledByCore() const;
    hstring GetLocalizedControlTypeCore() const;
    hstring GetNameCore() const;
    Windows::UI::Xaml::Automation::Peers::AutomationOrientation GetOrientationCore() const;
    bool HasKeyboardFocusCore() const;
    bool IsContentElementCore() const;
    bool IsControlElementCore() const;
    bool IsEnabledCore() const;
    bool IsKeyboardFocusableCore() const;
    bool IsOffscreenCore() const;
    bool IsPasswordCore() const;
    bool IsRequiredForFormCore() const;
    void SetFocusCore() const;
    Windows::UI::Xaml::Automation::Peers::AutomationPeer GetPeerFromPointCore(const Windows::Foundation::Point & point) const;
    Windows::UI::Xaml::Automation::Peers::AutomationLiveSetting GetLiveSettingCore() const;
};

template <typename D>
struct WINRT_EBO impl_IAutomationPeerOverrides2
{
    void ShowContextMenuCore() const;
    Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Automation::Peers::AutomationPeer> GetControlledPeersCore() const;
};

template <typename D>
struct WINRT_EBO impl_IAutomationPeerOverrides3
{
    Windows::Foundation::IInspectable NavigateCore(Windows::UI::Xaml::Automation::Peers::AutomationNavigationDirection direction) const;
    Windows::Foundation::IInspectable GetElementFromPointCore(const Windows::Foundation::Point & pointInWindowCoordinates) const;
    Windows::Foundation::IInspectable GetFocusedElementCore() const;
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation> GetAnnotationsCore() const;
    int32_t GetPositionInSetCore() const;
    int32_t GetSizeOfSetCore() const;
    int32_t GetLevelCore() const;
};

template <typename D>
struct WINRT_EBO impl_IAutomationPeerOverrides4
{
    Windows::UI::Xaml::Automation::Peers::AutomationLandmarkType GetLandmarkTypeCore() const;
    hstring GetLocalizedLandmarkTypeCore() const;
};

template <typename D>
struct WINRT_EBO impl_IAutomationPeerOverrides5
{
    bool IsPeripheralCore() const;
    bool IsDataValidForFormCore() const;
    hstring GetFullDescriptionCore() const;
    Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::Automation::Peers::AutomationPeer> GetDescribedByCore() const;
    Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::Automation::Peers::AutomationPeer> GetFlowsToCore() const;
    Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::Automation::Peers::AutomationPeer> GetFlowsFromCore() const;
};

template <typename D>
struct WINRT_EBO impl_IAutomationPeerProtected
{
    Windows::UI::Xaml::Automation::Peers::AutomationPeer PeerFromProvider(const Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple & provider) const;
    Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple ProviderFromPeer(const Windows::UI::Xaml::Automation::Peers::AutomationPeer & peer) const;
};

template <typename D>
struct WINRT_EBO impl_IAutomationPeerStatics
{
    bool ListenerExists(Windows::UI::Xaml::Automation::Peers::AutomationEvents eventId) const;
};

template <typename D>
struct WINRT_EBO impl_IAutomationPeerStatics3
{
    Windows::UI::Xaml::Automation::Peers::RawElementProviderRuntimeId GenerateRawElementProviderRuntimeId() const;
};

template <typename D>
struct WINRT_EBO impl_IButtonAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IButtonAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::ButtonAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::Button & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IButtonBaseAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IButtonBaseAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::ButtonBaseAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::Primitives::ButtonBase & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_ICaptureElementAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_ICaptureElementAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::CaptureElementAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::CaptureElement & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_ICheckBoxAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_ICheckBoxAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::CheckBoxAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::CheckBox & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IComboBoxAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IComboBoxAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::ComboBoxAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::ComboBox & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IComboBoxItemAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IComboBoxItemAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::ComboBoxItemAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::ComboBoxItem & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IComboBoxItemDataAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IComboBoxItemDataAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::ComboBoxItemDataAutomationPeer CreateInstanceWithParentAndItem(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::ComboBoxAutomationPeer & parent, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IDatePickerAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IDatePickerAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::DatePickerAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::DatePicker & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IDatePickerFlyoutPresenterAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IFlipViewAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IFlipViewAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::FlipViewAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::FlipView & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IFlipViewItemAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IFlipViewItemAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::FlipViewItemAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::FlipViewItem & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IFlipViewItemDataAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IFlipViewItemDataAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::FlipViewItemDataAutomationPeer CreateInstanceWithParentAndItem(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::FlipViewAutomationPeer & parent, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IFlyoutPresenterAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IFlyoutPresenterAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::FlyoutPresenterAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::FlyoutPresenter & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IFrameworkElementAutomationPeer
{
    Windows::UI::Xaml::UIElement Owner() const;
};

template <typename D>
struct WINRT_EBO impl_IFrameworkElementAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::FrameworkElement & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IFrameworkElementAutomationPeerStatics
{
    Windows::UI::Xaml::Automation::Peers::AutomationPeer FromElement(const Windows::UI::Xaml::UIElement & element) const;
    Windows::UI::Xaml::Automation::Peers::AutomationPeer CreatePeerForElement(const Windows::UI::Xaml::UIElement & element) const;
};

template <typename D>
struct WINRT_EBO impl_IGridViewAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IGridViewAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::GridViewAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::GridView & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IGridViewHeaderItemAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IGridViewHeaderItemAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::GridViewHeaderItemAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::GridViewHeaderItem & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IGridViewItemAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IGridViewItemAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::GridViewItemAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::GridViewItem & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IGridViewItemDataAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IGridViewItemDataAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::GridViewItemDataAutomationPeer CreateInstanceWithParentAndItem(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::GridViewAutomationPeer & parent, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IGroupItemAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IGroupItemAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::GroupItemAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::GroupItem & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IHubAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IHubAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::HubAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::Hub & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IHubSectionAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IHubSectionAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::HubSectionAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::HubSection & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IHyperlinkButtonAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IHyperlinkButtonAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::HyperlinkButtonAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::HyperlinkButton & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IImageAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IImageAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::ImageAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::Image & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IInkToolbarAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IItemAutomationPeer
{
    Windows::Foundation::IInspectable Item() const;
    Windows::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer ItemsControlAutomationPeer() const;
};

template <typename D>
struct WINRT_EBO impl_IItemAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::ItemAutomationPeer CreateInstanceWithParentAndItem(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer & parent, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IItemsControlAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IItemsControlAutomationPeer2
{
    Windows::UI::Xaml::Automation::Peers::ItemAutomationPeer CreateItemAutomationPeer(const Windows::Foundation::IInspectable & item) const;
};

template <typename D>
struct WINRT_EBO impl_IItemsControlAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::ItemsControl & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IItemsControlAutomationPeerOverrides2
{
    Windows::UI::Xaml::Automation::Peers::ItemAutomationPeer OnCreateItemAutomationPeer(const Windows::Foundation::IInspectable & item) const;
};

template <typename D>
struct WINRT_EBO impl_IListBoxAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IListBoxAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::ListBoxAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::ListBox & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IListBoxItemAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IListBoxItemAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::ListBoxItemAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::ListBoxItem & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IListBoxItemDataAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IListBoxItemDataAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::ListBoxItemDataAutomationPeer CreateInstanceWithParentAndItem(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::ListBoxAutomationPeer & parent, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IListPickerFlyoutPresenterAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IListViewAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IListViewAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::ListViewAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::ListView & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IListViewBaseAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IListViewBaseAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::ListViewBaseAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::ListViewBase & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IListViewBaseHeaderItemAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IListViewBaseHeaderItemAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::ListViewBaseHeaderItemAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::ListViewBaseHeaderItem & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IListViewHeaderItemAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IListViewHeaderItemAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::ListViewHeaderItemAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::ListViewHeaderItem & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IListViewItemAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IListViewItemAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::ListViewItemAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::ListViewItem & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IListViewItemDataAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IListViewItemDataAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::ListViewItemDataAutomationPeer CreateInstanceWithParentAndItem(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::ListViewBaseAutomationPeer & parent, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_ILoopingSelectorAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_ILoopingSelectorItemAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_ILoopingSelectorItemDataAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IMapControlAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IMediaElementAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IMediaElementAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::MediaElementAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::MediaElement & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlayerElementAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IMediaPlayerElementAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::MediaPlayerElementAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::MediaPlayerElement & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaTransportControlsAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IMediaTransportControlsAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::MediaTransportControlsAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::MediaTransportControls & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IMenuFlyoutItemAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IMenuFlyoutItemAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::MenuFlyoutItemAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::MenuFlyoutItem & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IMenuFlyoutPresenterAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IMenuFlyoutPresenterAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::MenuFlyoutPresenterAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::MenuFlyoutPresenter & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IPasswordBoxAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IPasswordBoxAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::PasswordBoxAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::PasswordBox & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IPickerFlyoutPresenterAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IPivotAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IPivotAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::PivotAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::Pivot & owner) const;
};

template <typename D>
struct WINRT_EBO impl_IPivotItemAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IPivotItemAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::PivotItemAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::PivotItem & owner) const;
};

template <typename D>
struct WINRT_EBO impl_IPivotItemDataAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IPivotItemDataAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::PivotItemDataAutomationPeer CreateInstanceWithParentAndItem(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::PivotAutomationPeer & parent) const;
};

template <typename D>
struct WINRT_EBO impl_IProgressBarAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IProgressBarAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::ProgressBarAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::ProgressBar & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IProgressRingAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IProgressRingAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::ProgressRingAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::ProgressRing & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IRadioButtonAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IRadioButtonAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::RadioButtonAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::RadioButton & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IRangeBaseAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IRangeBaseAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::RangeBaseAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::Primitives::RangeBase & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IRepeatButtonAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IRepeatButtonAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::RepeatButtonAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::Primitives::RepeatButton & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IRichEditBoxAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IRichEditBoxAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::RichEditBoxAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::RichEditBox & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IRichTextBlockAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IRichTextBlockAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::RichTextBlockAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::RichTextBlock & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IRichTextBlockOverflowAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IRichTextBlockOverflowAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::RichTextBlockOverflowAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::RichTextBlockOverflow & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IScrollBarAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IScrollBarAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::ScrollBarAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::Primitives::ScrollBar & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IScrollViewerAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IScrollViewerAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::ScrollViewerAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::ScrollViewer & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_ISearchBoxAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_ISearchBoxAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::SearchBoxAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::SearchBox & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_ISelectorAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_ISelectorAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::SelectorAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::Primitives::Selector & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_ISelectorItemAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_ISelectorItemAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::SelectorItemAutomationPeer CreateInstanceWithParentAndItem(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::SelectorAutomationPeer & parent, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_ISemanticZoomAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_ISemanticZoomAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::SemanticZoomAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::SemanticZoom & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_ISettingsFlyoutAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_ISettingsFlyoutAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::SettingsFlyoutAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::SettingsFlyout & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_ISliderAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_ISliderAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::SliderAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::Slider & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_ITextBlockAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_ITextBlockAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::TextBlockAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::TextBlock & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_ITextBoxAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_ITextBoxAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::TextBoxAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::TextBox & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IThumbAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IThumbAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::ThumbAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::Primitives::Thumb & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_ITimePickerAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_ITimePickerAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::TimePickerAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::TimePicker & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_ITimePickerFlyoutPresenterAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IToggleButtonAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IToggleButtonAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::ToggleButtonAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::Primitives::ToggleButton & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IToggleMenuFlyoutItemAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IToggleMenuFlyoutItemAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::ToggleMenuFlyoutItemAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::ToggleMenuFlyoutItem & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IToggleSwitchAutomationPeer
{
};

template <typename D>
struct WINRT_EBO impl_IToggleSwitchAutomationPeerFactory
{
    Windows::UI::Xaml::Automation::Peers::ToggleSwitchAutomationPeer CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::ToggleSwitch & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

}

namespace impl {

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IAppBarAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IAppBarAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IAppBarAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IAppBarAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IAppBarAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IAppBarAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IAppBarButtonAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IAppBarButtonAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IAppBarButtonAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IAppBarButtonAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IAppBarButtonAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IAppBarButtonAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IAppBarToggleButtonAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IAppBarToggleButtonAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IAppBarToggleButtonAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IAppBarToggleButtonAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IAppBarToggleButtonAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IAppBarToggleButtonAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IAutoSuggestBoxAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IAutoSuggestBoxAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IAutoSuggestBoxAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IAutoSuggestBoxAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IAutoSuggestBoxAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IAutoSuggestBoxAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IAutomationPeer2>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer2;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IAutomationPeer2<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IAutomationPeer3>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer3;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IAutomationPeer3<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IAutomationPeer4>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer4;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IAutomationPeer4<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IAutomationPeer5>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer5;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IAutomationPeer5<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IAutomationPeerAnnotation>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerAnnotation;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IAutomationPeerAnnotation<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IAutomationPeerAnnotationFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerAnnotationFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IAutomationPeerAnnotationFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IAutomationPeerAnnotationStatics>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerAnnotationStatics;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IAutomationPeerAnnotationStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IAutomationPeerOverrides<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IAutomationPeerOverrides2<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IAutomationPeerOverrides3<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IAutomationPeerOverrides4<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IAutomationPeerOverrides5<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IAutomationPeerProtected<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IAutomationPeerStatics>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerStatics;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IAutomationPeerStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IAutomationPeerStatics3>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerStatics3;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IAutomationPeerStatics3<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IButtonAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IButtonAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IButtonAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IButtonAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IButtonAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IButtonAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IButtonBaseAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IButtonBaseAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ICaptureElementAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ICaptureElementAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_ICaptureElementAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ICaptureElementAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ICaptureElementAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_ICaptureElementAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ICheckBoxAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ICheckBoxAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_ICheckBoxAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ICheckBoxAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ICheckBoxAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_ICheckBoxAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IComboBoxAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IComboBoxAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IComboBoxAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IComboBoxAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IComboBoxAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IComboBoxAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IComboBoxItemAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IComboBoxItemAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IComboBoxItemAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IComboBoxItemAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IComboBoxItemAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IComboBoxItemAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IComboBoxItemDataAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IComboBoxItemDataAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IComboBoxItemDataAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IComboBoxItemDataAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IComboBoxItemDataAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IComboBoxItemDataAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IDatePickerAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IDatePickerAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IDatePickerAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IDatePickerAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IDatePickerAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IDatePickerAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IDatePickerFlyoutPresenterAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IDatePickerFlyoutPresenterAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IDatePickerFlyoutPresenterAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IFlipViewAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IFlipViewAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IFlipViewAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IFlipViewAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IFlipViewAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IFlipViewAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IFlipViewItemAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IFlipViewItemAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IFlipViewItemAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IFlipViewItemAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IFlipViewItemAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IFlipViewItemAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IFlipViewItemDataAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IFlipViewItemDataAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IFlipViewItemDataAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IFlipViewItemDataAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IFlipViewItemDataAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IFlipViewItemDataAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IFlyoutPresenterAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IFlyoutPresenterAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IFlyoutPresenterAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IFlyoutPresenterAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IFlyoutPresenterAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IFlyoutPresenterAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IFrameworkElementAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IFrameworkElementAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeerStatics>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeerStatics;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IFrameworkElementAutomationPeerStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IGridViewAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IGridViewAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IGridViewAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IGridViewAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IGridViewAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IGridViewAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IGridViewHeaderItemAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IGridViewHeaderItemAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IGridViewHeaderItemAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IGridViewHeaderItemAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IGridViewHeaderItemAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IGridViewHeaderItemAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IGridViewItemAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IGridViewItemAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IGridViewItemAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IGridViewItemAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IGridViewItemAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IGridViewItemAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IGridViewItemDataAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IGridViewItemDataAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IGridViewItemDataAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IGridViewItemDataAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IGridViewItemDataAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IGridViewItemDataAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IGroupItemAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IGroupItemAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IGroupItemAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IGroupItemAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IGroupItemAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IGroupItemAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IHubAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IHubAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IHubAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IHubAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IHubAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IHubAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IHubSectionAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IHubSectionAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IHubSectionAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IHubSectionAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IHubSectionAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IHubSectionAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IHyperlinkButtonAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IHyperlinkButtonAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IHyperlinkButtonAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IHyperlinkButtonAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IHyperlinkButtonAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IHyperlinkButtonAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IImageAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IImageAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IImageAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IImageAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IImageAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IImageAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IInkToolbarAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IInkToolbarAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IInkToolbarAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IItemAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IItemAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IItemAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IItemAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IItemsControlAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IItemsControlAutomationPeer2<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IItemsControlAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IItemsControlAutomationPeerOverrides2<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IListBoxAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IListBoxAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IListBoxAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IListBoxAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IListBoxAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IListBoxAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IListBoxItemAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IListBoxItemAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IListBoxItemAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IListBoxItemAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IListBoxItemAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IListBoxItemAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IListBoxItemDataAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IListBoxItemDataAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IListBoxItemDataAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IListBoxItemDataAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IListBoxItemDataAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IListBoxItemDataAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IListPickerFlyoutPresenterAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IListPickerFlyoutPresenterAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IListPickerFlyoutPresenterAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IListViewAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IListViewAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IListViewAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IListViewAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IListViewAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IListViewAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IListViewBaseAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IListViewBaseAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IListViewBaseHeaderItemAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IListViewBaseHeaderItemAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IListViewBaseHeaderItemAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IListViewBaseHeaderItemAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IListViewBaseHeaderItemAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IListViewBaseHeaderItemAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IListViewHeaderItemAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IListViewHeaderItemAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IListViewHeaderItemAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IListViewHeaderItemAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IListViewHeaderItemAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IListViewHeaderItemAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IListViewItemAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IListViewItemAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IListViewItemAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IListViewItemAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IListViewItemAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IListViewItemAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IListViewItemDataAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IListViewItemDataAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IListViewItemDataAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IListViewItemDataAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IListViewItemDataAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IListViewItemDataAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ILoopingSelectorAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ILoopingSelectorAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_ILoopingSelectorAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ILoopingSelectorItemAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ILoopingSelectorItemAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_ILoopingSelectorItemAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ILoopingSelectorItemDataAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ILoopingSelectorItemDataAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_ILoopingSelectorItemDataAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IMapControlAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IMapControlAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IMapControlAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IMediaElementAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IMediaElementAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IMediaElementAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IMediaElementAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IMediaElementAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IMediaElementAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IMediaPlayerElementAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IMediaPlayerElementAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IMediaPlayerElementAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IMediaPlayerElementAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IMediaPlayerElementAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IMediaPlayerElementAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IMediaTransportControlsAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IMediaTransportControlsAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IMediaTransportControlsAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IMediaTransportControlsAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IMediaTransportControlsAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IMediaTransportControlsAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IMenuFlyoutItemAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IMenuFlyoutItemAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IMenuFlyoutItemAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IMenuFlyoutItemAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IMenuFlyoutItemAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IMenuFlyoutItemAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IMenuFlyoutPresenterAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IMenuFlyoutPresenterAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IMenuFlyoutPresenterAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IMenuFlyoutPresenterAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IMenuFlyoutPresenterAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IMenuFlyoutPresenterAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IPasswordBoxAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IPasswordBoxAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IPasswordBoxAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IPasswordBoxAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IPasswordBoxAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IPasswordBoxAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IPickerFlyoutPresenterAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IPickerFlyoutPresenterAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IPickerFlyoutPresenterAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IPivotAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IPivotAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IPivotAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IPivotAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IPivotAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IPivotAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IPivotItemAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IPivotItemAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IPivotItemAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IPivotItemAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IPivotItemAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IPivotItemAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IPivotItemDataAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IPivotItemDataAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IPivotItemDataAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IPivotItemDataAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IPivotItemDataAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IPivotItemDataAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IProgressBarAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IProgressBarAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IProgressBarAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IProgressBarAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IProgressBarAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IProgressBarAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IProgressRingAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IProgressRingAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IProgressRingAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IProgressRingAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IProgressRingAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IProgressRingAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IRadioButtonAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IRadioButtonAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IRadioButtonAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IRadioButtonAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IRadioButtonAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IRadioButtonAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IRangeBaseAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IRangeBaseAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IRepeatButtonAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IRepeatButtonAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IRepeatButtonAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IRepeatButtonAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IRepeatButtonAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IRepeatButtonAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IRichEditBoxAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IRichEditBoxAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IRichEditBoxAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IRichEditBoxAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IRichEditBoxAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IRichEditBoxAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IRichTextBlockAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IRichTextBlockAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IRichTextBlockAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IRichTextBlockAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IRichTextBlockAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IRichTextBlockAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IRichTextBlockOverflowAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IRichTextBlockOverflowAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IRichTextBlockOverflowAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IRichTextBlockOverflowAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IRichTextBlockOverflowAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IRichTextBlockOverflowAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IScrollBarAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IScrollBarAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IScrollBarAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IScrollBarAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IScrollBarAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IScrollBarAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IScrollViewerAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IScrollViewerAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IScrollViewerAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IScrollViewerAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IScrollViewerAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IScrollViewerAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ISearchBoxAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ISearchBoxAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_ISearchBoxAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ISearchBoxAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ISearchBoxAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_ISearchBoxAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_ISelectorAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_ISelectorAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_ISelectorItemAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_ISelectorItemAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ISemanticZoomAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ISemanticZoomAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_ISemanticZoomAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ISemanticZoomAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ISemanticZoomAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_ISemanticZoomAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ISettingsFlyoutAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ISettingsFlyoutAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_ISettingsFlyoutAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ISettingsFlyoutAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ISettingsFlyoutAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_ISettingsFlyoutAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ISliderAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ISliderAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_ISliderAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ISliderAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ISliderAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_ISliderAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ITextBlockAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ITextBlockAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_ITextBlockAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ITextBlockAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ITextBlockAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_ITextBlockAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ITextBoxAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ITextBoxAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_ITextBoxAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ITextBoxAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ITextBoxAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_ITextBoxAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IThumbAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IThumbAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IThumbAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IThumbAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IThumbAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IThumbAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ITimePickerAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ITimePickerAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_ITimePickerAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ITimePickerAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ITimePickerAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_ITimePickerAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ITimePickerFlyoutPresenterAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ITimePickerFlyoutPresenterAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_ITimePickerFlyoutPresenterAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IToggleButtonAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IToggleButtonAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IToggleMenuFlyoutItemAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IToggleMenuFlyoutItemAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IToggleMenuFlyoutItemAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IToggleMenuFlyoutItemAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IToggleMenuFlyoutItemAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IToggleMenuFlyoutItemAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IToggleSwitchAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IToggleSwitchAutomationPeer;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IToggleSwitchAutomationPeer<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::IToggleSwitchAutomationPeerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::IToggleSwitchAutomationPeerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Peers::impl_IToggleSwitchAutomationPeerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::AppBarAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::AppBarAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.AppBarAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::AppBarButtonAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::AppBarButtonAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.AppBarButtonAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::AppBarToggleButtonAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::AppBarToggleButtonAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.AppBarToggleButtonAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::AutoSuggestBoxAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::AutoSuggestBoxAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.AutoSuggestBoxAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::AutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.AutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.AutomationPeerAnnotation"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ButtonAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ButtonAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.ButtonAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ButtonBaseAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ButtonBaseAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.ButtonBaseAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::CaptureElementAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::CaptureElementAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.CaptureElementAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::CheckBoxAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::CheckBoxAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.CheckBoxAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ComboBoxAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ComboBoxAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.ComboBoxAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ComboBoxItemAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ComboBoxItemAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.ComboBoxItemAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ComboBoxItemDataAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ComboBoxItemDataAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.ComboBoxItemDataAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::DatePickerAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::DatePickerAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.DatePickerAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::DatePickerFlyoutPresenterAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::DatePickerFlyoutPresenterAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.DatePickerFlyoutPresenterAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::FlipViewAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::FlipViewAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.FlipViewAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::FlipViewItemAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::FlipViewItemAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.FlipViewItemAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::FlipViewItemDataAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::FlipViewItemDataAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.FlipViewItemDataAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::FlyoutPresenterAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::FlyoutPresenterAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.FlyoutPresenterAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.FrameworkElementAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::GridViewAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::GridViewAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.GridViewAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::GridViewHeaderItemAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::GridViewHeaderItemAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.GridViewHeaderItemAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::GridViewItemAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::GridViewItemAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.GridViewItemAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::GridViewItemDataAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::GridViewItemDataAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.GridViewItemDataAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::GroupItemAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::GroupItemAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.GroupItemAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::HubAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::HubAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.HubAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::HubSectionAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::HubSectionAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.HubSectionAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::HyperlinkButtonAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::HyperlinkButtonAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.HyperlinkButtonAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ImageAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ImageAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.ImageAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::InkToolbarAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::InkToolbarAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.InkToolbarAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ItemAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ItemAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.ItemAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.ItemsControlAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ListBoxAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ListBoxAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.ListBoxAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ListBoxItemAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ListBoxItemAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.ListBoxItemAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ListBoxItemDataAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ListBoxItemDataAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.ListBoxItemDataAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ListPickerFlyoutPresenterAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ListPickerFlyoutPresenterAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.ListPickerFlyoutPresenterAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ListViewAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ListViewAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.ListViewAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ListViewBaseAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ListViewBaseAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.ListViewBaseAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ListViewBaseHeaderItemAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ListViewBaseHeaderItemAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.ListViewBaseHeaderItemAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ListViewHeaderItemAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ListViewHeaderItemAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.ListViewHeaderItemAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ListViewItemAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ListViewItemAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.ListViewItemAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ListViewItemDataAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ListViewItemDataAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.ListViewItemDataAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::LoopingSelectorAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::LoopingSelectorAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.LoopingSelectorAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::LoopingSelectorItemAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::LoopingSelectorItemAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.LoopingSelectorItemAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::LoopingSelectorItemDataAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::LoopingSelectorItemDataAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.LoopingSelectorItemDataAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::MapControlAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::MapControlAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.MapControlAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::MediaElementAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::MediaElementAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.MediaElementAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::MediaPlayerElementAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::MediaPlayerElementAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.MediaPlayerElementAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::MediaTransportControlsAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::MediaTransportControlsAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.MediaTransportControlsAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::MenuFlyoutItemAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::MenuFlyoutItemAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.MenuFlyoutItemAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::MenuFlyoutPresenterAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::MenuFlyoutPresenterAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.MenuFlyoutPresenterAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::PasswordBoxAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::PasswordBoxAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.PasswordBoxAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::PickerFlyoutPresenterAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::PickerFlyoutPresenterAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.PickerFlyoutPresenterAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::PivotAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::PivotAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.PivotAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::PivotItemAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::PivotItemAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.PivotItemAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::PivotItemDataAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::PivotItemDataAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.PivotItemDataAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ProgressBarAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ProgressBarAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.ProgressBarAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ProgressRingAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ProgressRingAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.ProgressRingAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::RadioButtonAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::RadioButtonAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.RadioButtonAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::RangeBaseAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::RangeBaseAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.RangeBaseAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::RepeatButtonAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::RepeatButtonAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.RepeatButtonAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::RichEditBoxAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::RichEditBoxAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.RichEditBoxAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::RichTextBlockAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::RichTextBlockAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.RichTextBlockAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::RichTextBlockOverflowAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::RichTextBlockOverflowAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.RichTextBlockOverflowAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ScrollBarAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ScrollBarAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.ScrollBarAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ScrollViewerAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ScrollViewerAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.ScrollViewerAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::SearchBoxAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::SearchBoxAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.SearchBoxAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::SelectorAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::SelectorAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.SelectorAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::SelectorItemAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::SelectorItemAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.SelectorItemAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::SemanticZoomAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::SemanticZoomAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.SemanticZoomAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::SettingsFlyoutAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::SettingsFlyoutAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.SettingsFlyoutAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::SliderAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::SliderAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.SliderAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::TextBlockAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::TextBlockAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.TextBlockAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::TextBoxAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::TextBoxAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.TextBoxAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ThumbAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ThumbAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.ThumbAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::TimePickerAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::TimePickerAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.TimePickerAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::TimePickerFlyoutPresenterAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::TimePickerFlyoutPresenterAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.TimePickerFlyoutPresenterAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ToggleButtonAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ToggleButtonAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.ToggleButtonAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ToggleMenuFlyoutItemAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ToggleMenuFlyoutItemAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.ToggleMenuFlyoutItemAutomationPeer"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::Peers::ToggleSwitchAutomationPeer>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Peers::ToggleSwitchAutomationPeer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Peers.ToggleSwitchAutomationPeer"; }
};

}

}
