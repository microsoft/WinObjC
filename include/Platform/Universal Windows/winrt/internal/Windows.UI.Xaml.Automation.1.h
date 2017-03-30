// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.UI.Xaml.Automation.0.h"
#include "Windows.UI.Xaml.0.h"
#include "Windows.UI.Xaml.Automation.Peers.0.h"
#include "Windows.UI.Xaml.1.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Xaml::Automation {

struct __declspec(uuid("d475a0c1-48b2-4e40-a6cf-3dc4b638c0de")) __declspec(novtable) IAnnotationPatternIdentifiers : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("e0e3a35d-d167-46dc-95ab-330af61aebb5")) __declspec(novtable) IAnnotationPatternIdentifiersStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AnnotationTypeIdProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_AnnotationTypeNameProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_AuthorProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_DateTimeProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_TargetProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
};

struct __declspec(uuid("fb3c30ca-03d8-4618-91bf-e4d84f4af318")) __declspec(novtable) IAutomationAnnotation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Type(winrt::Windows::UI::Xaml::Automation::AnnotationType * value) = 0;
    virtual HRESULT __stdcall put_Type(winrt::Windows::UI::Xaml::Automation::AnnotationType value) = 0;
    virtual HRESULT __stdcall get_Element(Windows::UI::Xaml::IUIElement ** value) = 0;
    virtual HRESULT __stdcall put_Element(Windows::UI::Xaml::IUIElement * value) = 0;
};

struct __declspec(uuid("4906fa52-ddc0-4e69-b76b-019d928d822f")) __declspec(novtable) IAutomationAnnotationFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(winrt::Windows::UI::Xaml::Automation::AnnotationType type, Windows::UI::Xaml::Automation::IAutomationAnnotation ** instance) = 0;
    virtual HRESULT __stdcall abi_CreateWithElementParameter(winrt::Windows::UI::Xaml::Automation::AnnotationType type, Windows::UI::Xaml::IUIElement * element, Windows::UI::Xaml::Automation::IAutomationAnnotation ** instance) = 0;
};

struct __declspec(uuid("e503eab7-4ee5-48cb-b5b8-bbcd46c9d1da")) __declspec(novtable) IAutomationAnnotationStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TypeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ElementProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("e68a63cf-4345-4e2d-8a6a-49cce1fa2dcc")) __declspec(novtable) IAutomationElementIdentifiers : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("4549399f-8340-4d67-b9bf-8c2ac6a0773a")) __declspec(novtable) IAutomationElementIdentifiersStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AcceleratorKeyProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_AccessKeyProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_AutomationIdProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_BoundingRectangleProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_ClassNameProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_ClickablePointProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_ControlTypeProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_HasKeyboardFocusProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_HelpTextProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsContentElementProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsControlElementProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsEnabledProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsKeyboardFocusableProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsOffscreenProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsPasswordProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsRequiredForFormProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_ItemStatusProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_ItemTypeProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_LabeledByProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_LocalizedControlTypeProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_NameProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_OrientationProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_LiveSettingProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
};

struct __declspec(uuid("b5cbb1e2-d55f-46a9-9eda-1a4742515dc3")) __declspec(novtable) IAutomationElementIdentifiersStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ControlledPeersProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
};

struct __declspec(uuid("0f5cbebd-b3eb-4083-adc7-0c2f39bb3543")) __declspec(novtable) IAutomationElementIdentifiersStatics3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PositionInSetProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_SizeOfSetProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_LevelProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_AnnotationsProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
};

struct __declspec(uuid("5af51f75-5913-4d78-b330-a6f50b73ed9b")) __declspec(novtable) IAutomationElementIdentifiersStatics4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LandmarkTypeProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_LocalizedLandmarkTypeProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
};

struct __declspec(uuid("986a8206-de59-42f9-a1e7-62b8af9e756d")) __declspec(novtable) IAutomationElementIdentifiersStatics5 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsPeripheralProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsDataValidForFormProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_FullDescriptionProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_DescribedByProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_FlowsToProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_FlowsFromProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
};

struct __declspec(uuid("68d7232c-e622-48e9-af0b-1ffa33cc5cba")) __declspec(novtable) IAutomationProperties : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("b618fd7b-32d0-4970-9c42-7c039ac7be78")) __declspec(novtable) IAutomationPropertiesStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AcceleratorKeyProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetAcceleratorKey(Windows::UI::Xaml::IDependencyObject * element, hstring * value) = 0;
    virtual HRESULT __stdcall abi_SetAcceleratorKey(Windows::UI::Xaml::IDependencyObject * element, hstring value) = 0;
    virtual HRESULT __stdcall get_AccessKeyProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetAccessKey(Windows::UI::Xaml::IDependencyObject * element, hstring * value) = 0;
    virtual HRESULT __stdcall abi_SetAccessKey(Windows::UI::Xaml::IDependencyObject * element, hstring value) = 0;
    virtual HRESULT __stdcall get_AutomationIdProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetAutomationId(Windows::UI::Xaml::IDependencyObject * element, hstring * value) = 0;
    virtual HRESULT __stdcall abi_SetAutomationId(Windows::UI::Xaml::IDependencyObject * element, hstring value) = 0;
    virtual HRESULT __stdcall get_HelpTextProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetHelpText(Windows::UI::Xaml::IDependencyObject * element, hstring * value) = 0;
    virtual HRESULT __stdcall abi_SetHelpText(Windows::UI::Xaml::IDependencyObject * element, hstring value) = 0;
    virtual HRESULT __stdcall get_IsRequiredForFormProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetIsRequiredForForm(Windows::UI::Xaml::IDependencyObject * element, bool * value) = 0;
    virtual HRESULT __stdcall abi_SetIsRequiredForForm(Windows::UI::Xaml::IDependencyObject * element, bool value) = 0;
    virtual HRESULT __stdcall get_ItemStatusProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetItemStatus(Windows::UI::Xaml::IDependencyObject * element, hstring * value) = 0;
    virtual HRESULT __stdcall abi_SetItemStatus(Windows::UI::Xaml::IDependencyObject * element, hstring value) = 0;
    virtual HRESULT __stdcall get_ItemTypeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetItemType(Windows::UI::Xaml::IDependencyObject * element, hstring * value) = 0;
    virtual HRESULT __stdcall abi_SetItemType(Windows::UI::Xaml::IDependencyObject * element, hstring value) = 0;
    virtual HRESULT __stdcall get_LabeledByProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetLabeledBy(Windows::UI::Xaml::IDependencyObject * element, Windows::UI::Xaml::IUIElement ** value) = 0;
    virtual HRESULT __stdcall abi_SetLabeledBy(Windows::UI::Xaml::IDependencyObject * element, Windows::UI::Xaml::IUIElement * value) = 0;
    virtual HRESULT __stdcall get_NameProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetName(Windows::UI::Xaml::IDependencyObject * element, hstring * value) = 0;
    virtual HRESULT __stdcall abi_SetName(Windows::UI::Xaml::IDependencyObject * element, hstring value) = 0;
    virtual HRESULT __stdcall get_LiveSettingProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetLiveSetting(Windows::UI::Xaml::IDependencyObject * element, winrt::Windows::UI::Xaml::Automation::Peers::AutomationLiveSetting * value) = 0;
    virtual HRESULT __stdcall abi_SetLiveSetting(Windows::UI::Xaml::IDependencyObject * element, winrt::Windows::UI::Xaml::Automation::Peers::AutomationLiveSetting value) = 0;
};

struct __declspec(uuid("3976547f-7089-4801-8f1d-aab78090d1a0")) __declspec(novtable) IAutomationPropertiesStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AccessibilityViewProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetAccessibilityView(Windows::UI::Xaml::IDependencyObject * element, winrt::Windows::UI::Xaml::Automation::Peers::AccessibilityView * value) = 0;
    virtual HRESULT __stdcall abi_SetAccessibilityView(Windows::UI::Xaml::IDependencyObject * element, winrt::Windows::UI::Xaml::Automation::Peers::AccessibilityView value) = 0;
    virtual HRESULT __stdcall get_ControlledPeersProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetControlledPeers(Windows::UI::Xaml::IDependencyObject * element, Windows::Foundation::Collections::IVector<Windows::UI::Xaml::UIElement> ** value) = 0;
};

struct __declspec(uuid("7b75d735-5cb1-42ad-9b57-5faba8c1867f")) __declspec(novtable) IAutomationPropertiesStatics3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PositionInSetProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetPositionInSet(Windows::UI::Xaml::IDependencyObject * element, int32_t * value) = 0;
    virtual HRESULT __stdcall abi_SetPositionInSet(Windows::UI::Xaml::IDependencyObject * element, int32_t value) = 0;
    virtual HRESULT __stdcall get_SizeOfSetProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetSizeOfSet(Windows::UI::Xaml::IDependencyObject * element, int32_t * value) = 0;
    virtual HRESULT __stdcall abi_SetSizeOfSet(Windows::UI::Xaml::IDependencyObject * element, int32_t value) = 0;
    virtual HRESULT __stdcall get_LevelProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetLevel(Windows::UI::Xaml::IDependencyObject * element, int32_t * value) = 0;
    virtual HRESULT __stdcall abi_SetLevel(Windows::UI::Xaml::IDependencyObject * element, int32_t value) = 0;
    virtual HRESULT __stdcall get_AnnotationsProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetAnnotations(Windows::UI::Xaml::IDependencyObject * element, Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Automation::AutomationAnnotation> ** value) = 0;
};

struct __declspec(uuid("f7d62655-311a-4b7c-a131-524e89cd3cf9")) __declspec(novtable) IAutomationPropertiesStatics4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LandmarkTypeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetLandmarkType(Windows::UI::Xaml::IDependencyObject * element, winrt::Windows::UI::Xaml::Automation::Peers::AutomationLandmarkType * value) = 0;
    virtual HRESULT __stdcall abi_SetLandmarkType(Windows::UI::Xaml::IDependencyObject * element, winrt::Windows::UI::Xaml::Automation::Peers::AutomationLandmarkType value) = 0;
    virtual HRESULT __stdcall get_LocalizedLandmarkTypeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetLocalizedLandmarkType(Windows::UI::Xaml::IDependencyObject * element, hstring * value) = 0;
    virtual HRESULT __stdcall abi_SetLocalizedLandmarkType(Windows::UI::Xaml::IDependencyObject * element, hstring value) = 0;
};

struct __declspec(uuid("0be35b26-c8f9-41a2-b4db-e6a7a32b0c34")) __declspec(novtable) IAutomationPropertiesStatics5 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsPeripheralProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetIsPeripheral(Windows::UI::Xaml::IDependencyObject * element, bool * value) = 0;
    virtual HRESULT __stdcall abi_SetIsPeripheral(Windows::UI::Xaml::IDependencyObject * element, bool value) = 0;
    virtual HRESULT __stdcall get_IsDataValidForFormProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetIsDataValidForForm(Windows::UI::Xaml::IDependencyObject * element, bool * value) = 0;
    virtual HRESULT __stdcall abi_SetIsDataValidForForm(Windows::UI::Xaml::IDependencyObject * element, bool value) = 0;
    virtual HRESULT __stdcall get_FullDescriptionProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetFullDescription(Windows::UI::Xaml::IDependencyObject * element, hstring * value) = 0;
    virtual HRESULT __stdcall abi_SetFullDescription(Windows::UI::Xaml::IDependencyObject * element, hstring value) = 0;
    virtual HRESULT __stdcall get_LocalizedControlTypeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetLocalizedControlType(Windows::UI::Xaml::IDependencyObject * element, hstring * value) = 0;
    virtual HRESULT __stdcall abi_SetLocalizedControlType(Windows::UI::Xaml::IDependencyObject * element, hstring value) = 0;
    virtual HRESULT __stdcall get_DescribedByProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetDescribedBy(Windows::UI::Xaml::IDependencyObject * element, Windows::Foundation::Collections::IVector<Windows::UI::Xaml::DependencyObject> ** value) = 0;
    virtual HRESULT __stdcall get_FlowsToProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetFlowsTo(Windows::UI::Xaml::IDependencyObject * element, Windows::Foundation::Collections::IVector<Windows::UI::Xaml::DependencyObject> ** value) = 0;
    virtual HRESULT __stdcall get_FlowsFromProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetFlowsFrom(Windows::UI::Xaml::IDependencyObject * element, Windows::Foundation::Collections::IVector<Windows::UI::Xaml::DependencyObject> ** value) = 0;
};

struct __declspec(uuid("b627195b-3227-4e16-9534-ddece30ddb46")) __declspec(novtable) IAutomationProperty : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("ccd7f4e6-e4f9-47ff-bde7-378b11f78e09")) __declspec(novtable) IDockPatternIdentifiers : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("2b87245c-ed80-4fe5-8eb4-708a39c841e5")) __declspec(novtable) IDockPatternIdentifiersStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DockPositionProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
};

struct __declspec(uuid("6266e985-4d07-4e80-82eb-8f96690a1a0c")) __declspec(novtable) IDragPatternIdentifiers : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("2a05379d-1755-4082-9d90-46f1411d7986")) __declspec(novtable) IDragPatternIdentifiersStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DropEffectProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_DropEffectsProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_GrabbedItemsProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsGrabbedProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
};

struct __declspec(uuid("11865133-a6fe-4634-bd18-0ef612b7b208")) __declspec(novtable) IDropTargetPatternIdentifiers : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("1b693304-89fb-4b0a-9452-ca2c66aaf9f3")) __declspec(novtable) IDropTargetPatternIdentifiersStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DropTargetEffectProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_DropTargetEffectsProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
};

struct __declspec(uuid("b006bac0-751b-4d55-92cb-613ec1bdf5d0")) __declspec(novtable) IExpandCollapsePatternIdentifiers : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("d7816fd4-6ee0-4f38-8e14-56ef21adacfd")) __declspec(novtable) IExpandCollapsePatternIdentifiersStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ExpandCollapseStateProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
};

struct __declspec(uuid("757744f1-3285-4fb1-803b-2545bd431599")) __declspec(novtable) IGridItemPatternIdentifiers : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("217d2402-5e46-4d61-8794-b8ee8e774714")) __declspec(novtable) IGridItemPatternIdentifiersStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ColumnProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_ColumnSpanProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_ContainingGridProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_RowProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_RowSpanProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
};

struct __declspec(uuid("c902980f-96c5-450c-9044-7e52c24f9e94")) __declspec(novtable) IGridPatternIdentifiers : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("7bc452f3-a181-4137-8de9-1f9b1a8320ed")) __declspec(novtable) IGridPatternIdentifiersStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ColumnCountProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_RowCountProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
};

struct __declspec(uuid("5d5cd3b8-1e12-488b-b0ea-5e6cb89816e1")) __declspec(novtable) IMultipleViewPatternIdentifiers : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("a9cfa66f-6b84-4d71-9e48-d764d3bcda8e")) __declspec(novtable) IMultipleViewPatternIdentifiersStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CurrentViewProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_SupportedViewsProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
};

struct __declspec(uuid("f8760f45-33c9-467d-bc9e-d1515263ace1")) __declspec(novtable) IRangeValuePatternIdentifiers : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("ce23450f-1c27-457f-b815-7a5e46863dbb")) __declspec(novtable) IRangeValuePatternIdentifiersStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsReadOnlyProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_LargeChangeProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_MaximumProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_MinimumProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_SmallChangeProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_ValueProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
};

struct __declspec(uuid("366b1003-425c-4951-ae83-d521e73bc696")) __declspec(novtable) IScrollPatternIdentifiers : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("4bf8e0a1-fb7f-4fa4-83b3-cfaeb103a685")) __declspec(novtable) IScrollPatternIdentifiersStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_HorizontallyScrollableProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_HorizontalScrollPercentProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_HorizontalViewSizeProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_NoScroll(double * value) = 0;
    virtual HRESULT __stdcall get_VerticallyScrollableProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_VerticalScrollPercentProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_VerticalViewSizeProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
};

struct __declspec(uuid("2dafa41a-3ef8-4bb5-a02b-3ee1b2274740")) __declspec(novtable) ISelectionItemPatternIdentifiers : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("a918d163-487e-4e3e-9f86-7b44acbe27ce")) __declspec(novtable) ISelectionItemPatternIdentifiersStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsSelectedProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_SelectionContainerProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
};

struct __declspec(uuid("4aa66fb0-e3f7-475f-b78d-f8a83bb730c4")) __declspec(novtable) ISelectionPatternIdentifiers : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("93035b4c-6b50-40a1-b23f-5c78ddbd479a")) __declspec(novtable) ISelectionPatternIdentifiersStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CanSelectMultipleProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsSelectionRequiredProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_SelectionProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
};

struct __declspec(uuid("84347e19-ca4b-46a2-a794-c87928a3b1ab")) __declspec(novtable) ISpreadsheetItemPatternIdentifiers : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("43658779-5380-4f12-b468-b4f368ad4499")) __declspec(novtable) ISpreadsheetItemPatternIdentifiersStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FormulaProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
};

struct __declspec(uuid("b0e4e201-e89d-436b-8287-4f7903466879")) __declspec(novtable) IStylesPatternIdentifiers : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("528a457a-bc3c-4d48-94af-1f68703ca296")) __declspec(novtable) IStylesPatternIdentifiersStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ExtendedPropertiesProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_FillColorProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_FillPatternColorProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_FillPatternStyleProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_ShapeProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_StyleIdProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_StyleNameProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
};

struct __declspec(uuid("c326e5ad-8077-4c64-98e4-e83bcf1b4389")) __declspec(novtable) ITableItemPatternIdentifiers : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("24c4b923-e9a2-4de9-b2a4-a8b22d0be362")) __declspec(novtable) ITableItemPatternIdentifiersStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ColumnHeaderItemsProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_RowHeaderItemsProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
};

struct __declspec(uuid("38d104fe-0d0c-412a-bf8d-51ede683baf5")) __declspec(novtable) ITablePatternIdentifiers : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("75073d25-32c9-4903-aecf-dc3504cbd244")) __declspec(novtable) ITablePatternIdentifiersStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ColumnHeadersProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_RowHeadersProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_RowOrColumnMajorProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
};

struct __declspec(uuid("7e191f6b-34d4-4ae7-83ac-29f88882d985")) __declspec(novtable) ITogglePatternIdentifiers : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("c7f75544-14a5-4f2f-92fc-760524de06ea")) __declspec(novtable) ITogglePatternIdentifiersStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ToggleStateProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
};

struct __declspec(uuid("08aaa03d-dea7-402f-8097-9a2783d60e5d")) __declspec(novtable) ITransformPattern2Identifiers : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("78963644-11f0-467c-a72b-5dac41c1f6fe")) __declspec(novtable) ITransformPattern2IdentifiersStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CanZoomProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_ZoomLevelProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_MaxZoomProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_MinZoomProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
};

struct __declspec(uuid("e4115b8c-c3c8-4a37-b994-2709a7811665")) __declspec(novtable) ITransformPatternIdentifiers : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("4570edab-d705-40c4-a1dc-e9acfcef85f6")) __declspec(novtable) ITransformPatternIdentifiersStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CanMoveProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_CanResizeProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_CanRotateProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
};

struct __declspec(uuid("425bf64c-5333-4e41-b470-2bad14ecd085")) __declspec(novtable) IValuePatternIdentifiers : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("c247e8f7-adcc-440f-b123-33788a40525a")) __declspec(novtable) IValuePatternIdentifiersStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsReadOnlyProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_ValueProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
};

struct __declspec(uuid("39f78bb4-7032-41e2-b79e-27b74a8628de")) __declspec(novtable) IWindowPatternIdentifiers : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("07d0ad06-6302-4d29-878b-19da03fc228d")) __declspec(novtable) IWindowPatternIdentifiersStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CanMaximizeProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_CanMinimizeProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsModalProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsTopmostProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_WindowInteractionStateProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
    virtual HRESULT __stdcall get_WindowVisualStateProperty(Windows::UI::Xaml::Automation::IAutomationProperty ** value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::UI::Xaml::Automation::AnnotationPatternIdentifiers> { using default_interface = Windows::UI::Xaml::Automation::IAnnotationPatternIdentifiers; };
template <> struct traits<Windows::UI::Xaml::Automation::AutomationAnnotation> { using default_interface = Windows::UI::Xaml::Automation::IAutomationAnnotation; };
template <> struct traits<Windows::UI::Xaml::Automation::AutomationElementIdentifiers> { using default_interface = Windows::UI::Xaml::Automation::IAutomationElementIdentifiers; };
template <> struct traits<Windows::UI::Xaml::Automation::AutomationProperties> { using default_interface = Windows::UI::Xaml::Automation::IAutomationProperties; };
template <> struct traits<Windows::UI::Xaml::Automation::AutomationProperty> { using default_interface = Windows::UI::Xaml::Automation::IAutomationProperty; };
template <> struct traits<Windows::UI::Xaml::Automation::DockPatternIdentifiers> { using default_interface = Windows::UI::Xaml::Automation::IDockPatternIdentifiers; };
template <> struct traits<Windows::UI::Xaml::Automation::DragPatternIdentifiers> { using default_interface = Windows::UI::Xaml::Automation::IDragPatternIdentifiers; };
template <> struct traits<Windows::UI::Xaml::Automation::DropTargetPatternIdentifiers> { using default_interface = Windows::UI::Xaml::Automation::IDropTargetPatternIdentifiers; };
template <> struct traits<Windows::UI::Xaml::Automation::ExpandCollapsePatternIdentifiers> { using default_interface = Windows::UI::Xaml::Automation::IExpandCollapsePatternIdentifiers; };
template <> struct traits<Windows::UI::Xaml::Automation::GridItemPatternIdentifiers> { using default_interface = Windows::UI::Xaml::Automation::IGridItemPatternIdentifiers; };
template <> struct traits<Windows::UI::Xaml::Automation::GridPatternIdentifiers> { using default_interface = Windows::UI::Xaml::Automation::IGridPatternIdentifiers; };
template <> struct traits<Windows::UI::Xaml::Automation::MultipleViewPatternIdentifiers> { using default_interface = Windows::UI::Xaml::Automation::IMultipleViewPatternIdentifiers; };
template <> struct traits<Windows::UI::Xaml::Automation::RangeValuePatternIdentifiers> { using default_interface = Windows::UI::Xaml::Automation::IRangeValuePatternIdentifiers; };
template <> struct traits<Windows::UI::Xaml::Automation::ScrollPatternIdentifiers> { using default_interface = Windows::UI::Xaml::Automation::IScrollPatternIdentifiers; };
template <> struct traits<Windows::UI::Xaml::Automation::SelectionItemPatternIdentifiers> { using default_interface = Windows::UI::Xaml::Automation::ISelectionItemPatternIdentifiers; };
template <> struct traits<Windows::UI::Xaml::Automation::SelectionPatternIdentifiers> { using default_interface = Windows::UI::Xaml::Automation::ISelectionPatternIdentifiers; };
template <> struct traits<Windows::UI::Xaml::Automation::SpreadsheetItemPatternIdentifiers> { using default_interface = Windows::UI::Xaml::Automation::ISpreadsheetItemPatternIdentifiers; };
template <> struct traits<Windows::UI::Xaml::Automation::StylesPatternIdentifiers> { using default_interface = Windows::UI::Xaml::Automation::IStylesPatternIdentifiers; };
template <> struct traits<Windows::UI::Xaml::Automation::TableItemPatternIdentifiers> { using default_interface = Windows::UI::Xaml::Automation::ITableItemPatternIdentifiers; };
template <> struct traits<Windows::UI::Xaml::Automation::TablePatternIdentifiers> { using default_interface = Windows::UI::Xaml::Automation::ITablePatternIdentifiers; };
template <> struct traits<Windows::UI::Xaml::Automation::TogglePatternIdentifiers> { using default_interface = Windows::UI::Xaml::Automation::ITogglePatternIdentifiers; };
template <> struct traits<Windows::UI::Xaml::Automation::TransformPattern2Identifiers> { using default_interface = Windows::UI::Xaml::Automation::ITransformPattern2Identifiers; };
template <> struct traits<Windows::UI::Xaml::Automation::TransformPatternIdentifiers> { using default_interface = Windows::UI::Xaml::Automation::ITransformPatternIdentifiers; };
template <> struct traits<Windows::UI::Xaml::Automation::ValuePatternIdentifiers> { using default_interface = Windows::UI::Xaml::Automation::IValuePatternIdentifiers; };
template <> struct traits<Windows::UI::Xaml::Automation::WindowPatternIdentifiers> { using default_interface = Windows::UI::Xaml::Automation::IWindowPatternIdentifiers; };

}

namespace Windows::UI::Xaml::Automation {

template <typename D>
struct WINRT_EBO impl_IAnnotationPatternIdentifiers
{
};

template <typename D>
struct WINRT_EBO impl_IAnnotationPatternIdentifiersStatics
{
    Windows::UI::Xaml::Automation::AutomationProperty AnnotationTypeIdProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty AnnotationTypeNameProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty AuthorProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty DateTimeProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty TargetProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IAutomationAnnotation
{
    Windows::UI::Xaml::Automation::AnnotationType Type() const;
    void Type(Windows::UI::Xaml::Automation::AnnotationType value) const;
    Windows::UI::Xaml::UIElement Element() const;
    void Element(const Windows::UI::Xaml::UIElement & value) const;
};

template <typename D>
struct WINRT_EBO impl_IAutomationAnnotationFactory
{
    Windows::UI::Xaml::Automation::AutomationAnnotation CreateInstance(Windows::UI::Xaml::Automation::AnnotationType type) const;
    Windows::UI::Xaml::Automation::AutomationAnnotation CreateWithElementParameter(Windows::UI::Xaml::Automation::AnnotationType type, const Windows::UI::Xaml::UIElement & element) const;
};

template <typename D>
struct WINRT_EBO impl_IAutomationAnnotationStatics
{
    Windows::UI::Xaml::DependencyProperty TypeProperty() const;
    Windows::UI::Xaml::DependencyProperty ElementProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IAutomationElementIdentifiers
{
};

template <typename D>
struct WINRT_EBO impl_IAutomationElementIdentifiersStatics
{
    Windows::UI::Xaml::Automation::AutomationProperty AcceleratorKeyProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty AccessKeyProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty AutomationIdProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty BoundingRectangleProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty ClassNameProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty ClickablePointProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty ControlTypeProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty HasKeyboardFocusProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty HelpTextProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty IsContentElementProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty IsControlElementProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty IsEnabledProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty IsKeyboardFocusableProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty IsOffscreenProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty IsPasswordProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty IsRequiredForFormProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty ItemStatusProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty ItemTypeProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty LabeledByProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty LocalizedControlTypeProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty NameProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty OrientationProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty LiveSettingProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IAutomationElementIdentifiersStatics2
{
    Windows::UI::Xaml::Automation::AutomationProperty ControlledPeersProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IAutomationElementIdentifiersStatics3
{
    Windows::UI::Xaml::Automation::AutomationProperty PositionInSetProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty SizeOfSetProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty LevelProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty AnnotationsProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IAutomationElementIdentifiersStatics4
{
    Windows::UI::Xaml::Automation::AutomationProperty LandmarkTypeProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty LocalizedLandmarkTypeProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IAutomationElementIdentifiersStatics5
{
    Windows::UI::Xaml::Automation::AutomationProperty IsPeripheralProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty IsDataValidForFormProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty FullDescriptionProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty DescribedByProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty FlowsToProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty FlowsFromProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IAutomationProperties
{
};

template <typename D>
struct WINRT_EBO impl_IAutomationPropertiesStatics
{
    Windows::UI::Xaml::DependencyProperty AcceleratorKeyProperty() const;
    hstring GetAcceleratorKey(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetAcceleratorKey(const Windows::UI::Xaml::DependencyObject & element, hstring_view value) const;
    Windows::UI::Xaml::DependencyProperty AccessKeyProperty() const;
    hstring GetAccessKey(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetAccessKey(const Windows::UI::Xaml::DependencyObject & element, hstring_view value) const;
    Windows::UI::Xaml::DependencyProperty AutomationIdProperty() const;
    hstring GetAutomationId(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetAutomationId(const Windows::UI::Xaml::DependencyObject & element, hstring_view value) const;
    Windows::UI::Xaml::DependencyProperty HelpTextProperty() const;
    hstring GetHelpText(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetHelpText(const Windows::UI::Xaml::DependencyObject & element, hstring_view value) const;
    Windows::UI::Xaml::DependencyProperty IsRequiredForFormProperty() const;
    bool GetIsRequiredForForm(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetIsRequiredForForm(const Windows::UI::Xaml::DependencyObject & element, bool value) const;
    Windows::UI::Xaml::DependencyProperty ItemStatusProperty() const;
    hstring GetItemStatus(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetItemStatus(const Windows::UI::Xaml::DependencyObject & element, hstring_view value) const;
    Windows::UI::Xaml::DependencyProperty ItemTypeProperty() const;
    hstring GetItemType(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetItemType(const Windows::UI::Xaml::DependencyObject & element, hstring_view value) const;
    Windows::UI::Xaml::DependencyProperty LabeledByProperty() const;
    Windows::UI::Xaml::UIElement GetLabeledBy(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetLabeledBy(const Windows::UI::Xaml::DependencyObject & element, const Windows::UI::Xaml::UIElement & value) const;
    Windows::UI::Xaml::DependencyProperty NameProperty() const;
    hstring GetName(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetName(const Windows::UI::Xaml::DependencyObject & element, hstring_view value) const;
    Windows::UI::Xaml::DependencyProperty LiveSettingProperty() const;
    Windows::UI::Xaml::Automation::Peers::AutomationLiveSetting GetLiveSetting(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetLiveSetting(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::Automation::Peers::AutomationLiveSetting value) const;
};

template <typename D>
struct WINRT_EBO impl_IAutomationPropertiesStatics2
{
    Windows::UI::Xaml::DependencyProperty AccessibilityViewProperty() const;
    Windows::UI::Xaml::Automation::Peers::AccessibilityView GetAccessibilityView(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetAccessibilityView(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::Automation::Peers::AccessibilityView value) const;
    Windows::UI::Xaml::DependencyProperty ControlledPeersProperty() const;
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::UIElement> GetControlledPeers(const Windows::UI::Xaml::DependencyObject & element) const;
};

template <typename D>
struct WINRT_EBO impl_IAutomationPropertiesStatics3
{
    Windows::UI::Xaml::DependencyProperty PositionInSetProperty() const;
    int32_t GetPositionInSet(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetPositionInSet(const Windows::UI::Xaml::DependencyObject & element, int32_t value) const;
    Windows::UI::Xaml::DependencyProperty SizeOfSetProperty() const;
    int32_t GetSizeOfSet(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetSizeOfSet(const Windows::UI::Xaml::DependencyObject & element, int32_t value) const;
    Windows::UI::Xaml::DependencyProperty LevelProperty() const;
    int32_t GetLevel(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetLevel(const Windows::UI::Xaml::DependencyObject & element, int32_t value) const;
    Windows::UI::Xaml::DependencyProperty AnnotationsProperty() const;
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Automation::AutomationAnnotation> GetAnnotations(const Windows::UI::Xaml::DependencyObject & element) const;
};

template <typename D>
struct WINRT_EBO impl_IAutomationPropertiesStatics4
{
    Windows::UI::Xaml::DependencyProperty LandmarkTypeProperty() const;
    Windows::UI::Xaml::Automation::Peers::AutomationLandmarkType GetLandmarkType(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetLandmarkType(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::Automation::Peers::AutomationLandmarkType value) const;
    Windows::UI::Xaml::DependencyProperty LocalizedLandmarkTypeProperty() const;
    hstring GetLocalizedLandmarkType(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetLocalizedLandmarkType(const Windows::UI::Xaml::DependencyObject & element, hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IAutomationPropertiesStatics5
{
    Windows::UI::Xaml::DependencyProperty IsPeripheralProperty() const;
    bool GetIsPeripheral(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetIsPeripheral(const Windows::UI::Xaml::DependencyObject & element, bool value) const;
    Windows::UI::Xaml::DependencyProperty IsDataValidForFormProperty() const;
    bool GetIsDataValidForForm(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetIsDataValidForForm(const Windows::UI::Xaml::DependencyObject & element, bool value) const;
    Windows::UI::Xaml::DependencyProperty FullDescriptionProperty() const;
    hstring GetFullDescription(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetFullDescription(const Windows::UI::Xaml::DependencyObject & element, hstring_view value) const;
    Windows::UI::Xaml::DependencyProperty LocalizedControlTypeProperty() const;
    hstring GetLocalizedControlType(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetLocalizedControlType(const Windows::UI::Xaml::DependencyObject & element, hstring_view value) const;
    Windows::UI::Xaml::DependencyProperty DescribedByProperty() const;
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::DependencyObject> GetDescribedBy(const Windows::UI::Xaml::DependencyObject & element) const;
    Windows::UI::Xaml::DependencyProperty FlowsToProperty() const;
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::DependencyObject> GetFlowsTo(const Windows::UI::Xaml::DependencyObject & element) const;
    Windows::UI::Xaml::DependencyProperty FlowsFromProperty() const;
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::DependencyObject> GetFlowsFrom(const Windows::UI::Xaml::DependencyObject & element) const;
};

template <typename D>
struct WINRT_EBO impl_IAutomationProperty
{
};

template <typename D>
struct WINRT_EBO impl_IDockPatternIdentifiers
{
};

template <typename D>
struct WINRT_EBO impl_IDockPatternIdentifiersStatics
{
    Windows::UI::Xaml::Automation::AutomationProperty DockPositionProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IDragPatternIdentifiers
{
};

template <typename D>
struct WINRT_EBO impl_IDragPatternIdentifiersStatics
{
    Windows::UI::Xaml::Automation::AutomationProperty DropEffectProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty DropEffectsProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty GrabbedItemsProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty IsGrabbedProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IDropTargetPatternIdentifiers
{
};

template <typename D>
struct WINRT_EBO impl_IDropTargetPatternIdentifiersStatics
{
    Windows::UI::Xaml::Automation::AutomationProperty DropTargetEffectProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty DropTargetEffectsProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IExpandCollapsePatternIdentifiers
{
};

template <typename D>
struct WINRT_EBO impl_IExpandCollapsePatternIdentifiersStatics
{
    Windows::UI::Xaml::Automation::AutomationProperty ExpandCollapseStateProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IGridItemPatternIdentifiers
{
};

template <typename D>
struct WINRT_EBO impl_IGridItemPatternIdentifiersStatics
{
    Windows::UI::Xaml::Automation::AutomationProperty ColumnProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty ColumnSpanProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty ContainingGridProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty RowProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty RowSpanProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IGridPatternIdentifiers
{
};

template <typename D>
struct WINRT_EBO impl_IGridPatternIdentifiersStatics
{
    Windows::UI::Xaml::Automation::AutomationProperty ColumnCountProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty RowCountProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IMultipleViewPatternIdentifiers
{
};

template <typename D>
struct WINRT_EBO impl_IMultipleViewPatternIdentifiersStatics
{
    Windows::UI::Xaml::Automation::AutomationProperty CurrentViewProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty SupportedViewsProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IRangeValuePatternIdentifiers
{
};

template <typename D>
struct WINRT_EBO impl_IRangeValuePatternIdentifiersStatics
{
    Windows::UI::Xaml::Automation::AutomationProperty IsReadOnlyProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty LargeChangeProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty MaximumProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty MinimumProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty SmallChangeProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty ValueProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IScrollPatternIdentifiers
{
};

template <typename D>
struct WINRT_EBO impl_IScrollPatternIdentifiersStatics
{
    Windows::UI::Xaml::Automation::AutomationProperty HorizontallyScrollableProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty HorizontalScrollPercentProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty HorizontalViewSizeProperty() const;
    double NoScroll() const;
    Windows::UI::Xaml::Automation::AutomationProperty VerticallyScrollableProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty VerticalScrollPercentProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty VerticalViewSizeProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ISelectionItemPatternIdentifiers
{
};

template <typename D>
struct WINRT_EBO impl_ISelectionItemPatternIdentifiersStatics
{
    Windows::UI::Xaml::Automation::AutomationProperty IsSelectedProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty SelectionContainerProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ISelectionPatternIdentifiers
{
};

template <typename D>
struct WINRT_EBO impl_ISelectionPatternIdentifiersStatics
{
    Windows::UI::Xaml::Automation::AutomationProperty CanSelectMultipleProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty IsSelectionRequiredProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty SelectionProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ISpreadsheetItemPatternIdentifiers
{
};

template <typename D>
struct WINRT_EBO impl_ISpreadsheetItemPatternIdentifiersStatics
{
    Windows::UI::Xaml::Automation::AutomationProperty FormulaProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IStylesPatternIdentifiers
{
};

template <typename D>
struct WINRT_EBO impl_IStylesPatternIdentifiersStatics
{
    Windows::UI::Xaml::Automation::AutomationProperty ExtendedPropertiesProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty FillColorProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty FillPatternColorProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty FillPatternStyleProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty ShapeProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty StyleIdProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty StyleNameProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ITableItemPatternIdentifiers
{
};

template <typename D>
struct WINRT_EBO impl_ITableItemPatternIdentifiersStatics
{
    Windows::UI::Xaml::Automation::AutomationProperty ColumnHeaderItemsProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty RowHeaderItemsProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ITablePatternIdentifiers
{
};

template <typename D>
struct WINRT_EBO impl_ITablePatternIdentifiersStatics
{
    Windows::UI::Xaml::Automation::AutomationProperty ColumnHeadersProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty RowHeadersProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty RowOrColumnMajorProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ITogglePatternIdentifiers
{
};

template <typename D>
struct WINRT_EBO impl_ITogglePatternIdentifiersStatics
{
    Windows::UI::Xaml::Automation::AutomationProperty ToggleStateProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ITransformPattern2Identifiers
{
};

template <typename D>
struct WINRT_EBO impl_ITransformPattern2IdentifiersStatics
{
    Windows::UI::Xaml::Automation::AutomationProperty CanZoomProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty ZoomLevelProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty MaxZoomProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty MinZoomProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ITransformPatternIdentifiers
{
};

template <typename D>
struct WINRT_EBO impl_ITransformPatternIdentifiersStatics
{
    Windows::UI::Xaml::Automation::AutomationProperty CanMoveProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty CanResizeProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty CanRotateProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IValuePatternIdentifiers
{
};

template <typename D>
struct WINRT_EBO impl_IValuePatternIdentifiersStatics
{
    Windows::UI::Xaml::Automation::AutomationProperty IsReadOnlyProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty ValueProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IWindowPatternIdentifiers
{
};

template <typename D>
struct WINRT_EBO impl_IWindowPatternIdentifiersStatics
{
    Windows::UI::Xaml::Automation::AutomationProperty CanMaximizeProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty CanMinimizeProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty IsModalProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty IsTopmostProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty WindowInteractionStateProperty() const;
    Windows::UI::Xaml::Automation::AutomationProperty WindowVisualStateProperty() const;
};

}

namespace impl {

template <> struct traits<Windows::UI::Xaml::Automation::IAnnotationPatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IAnnotationPatternIdentifiers;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IAnnotationPatternIdentifiers<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IAnnotationPatternIdentifiersStatics>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IAnnotationPatternIdentifiersStatics;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IAnnotationPatternIdentifiersStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IAutomationAnnotation>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IAutomationAnnotation;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IAutomationAnnotation<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IAutomationAnnotationFactory>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IAutomationAnnotationFactory;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IAutomationAnnotationFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IAutomationAnnotationStatics>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IAutomationAnnotationStatics;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IAutomationAnnotationStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IAutomationElementIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IAutomationElementIdentifiers;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IAutomationElementIdentifiers<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IAutomationElementIdentifiersStatics>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IAutomationElementIdentifiersStatics;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IAutomationElementIdentifiersStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IAutomationElementIdentifiersStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IAutomationElementIdentifiersStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IAutomationElementIdentifiersStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IAutomationElementIdentifiersStatics3>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IAutomationElementIdentifiersStatics3;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IAutomationElementIdentifiersStatics3<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IAutomationElementIdentifiersStatics4>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IAutomationElementIdentifiersStatics4;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IAutomationElementIdentifiersStatics4<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IAutomationElementIdentifiersStatics5>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IAutomationElementIdentifiersStatics5;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IAutomationElementIdentifiersStatics5<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IAutomationProperties>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IAutomationProperties;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IAutomationProperties<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IAutomationPropertiesStatics>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IAutomationPropertiesStatics;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IAutomationPropertiesStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IAutomationPropertiesStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IAutomationPropertiesStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IAutomationPropertiesStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IAutomationPropertiesStatics3>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IAutomationPropertiesStatics3;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IAutomationPropertiesStatics3<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IAutomationPropertiesStatics4>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IAutomationPropertiesStatics4;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IAutomationPropertiesStatics4<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IAutomationPropertiesStatics5>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IAutomationPropertiesStatics5;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IAutomationPropertiesStatics5<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IAutomationProperty>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IAutomationProperty;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IAutomationProperty<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IDockPatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IDockPatternIdentifiers;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IDockPatternIdentifiers<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IDockPatternIdentifiersStatics>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IDockPatternIdentifiersStatics;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IDockPatternIdentifiersStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IDragPatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IDragPatternIdentifiers;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IDragPatternIdentifiers<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IDragPatternIdentifiersStatics>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IDragPatternIdentifiersStatics;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IDragPatternIdentifiersStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IDropTargetPatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IDropTargetPatternIdentifiers;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IDropTargetPatternIdentifiers<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IDropTargetPatternIdentifiersStatics>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IDropTargetPatternIdentifiersStatics;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IDropTargetPatternIdentifiersStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IExpandCollapsePatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IExpandCollapsePatternIdentifiers;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IExpandCollapsePatternIdentifiers<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IExpandCollapsePatternIdentifiersStatics>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IExpandCollapsePatternIdentifiersStatics;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IExpandCollapsePatternIdentifiersStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IGridItemPatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IGridItemPatternIdentifiers;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IGridItemPatternIdentifiers<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IGridItemPatternIdentifiersStatics>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IGridItemPatternIdentifiersStatics;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IGridItemPatternIdentifiersStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IGridPatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IGridPatternIdentifiers;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IGridPatternIdentifiers<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IGridPatternIdentifiersStatics>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IGridPatternIdentifiersStatics;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IGridPatternIdentifiersStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IMultipleViewPatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IMultipleViewPatternIdentifiers;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IMultipleViewPatternIdentifiers<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IMultipleViewPatternIdentifiersStatics>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IMultipleViewPatternIdentifiersStatics;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IMultipleViewPatternIdentifiersStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IRangeValuePatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IRangeValuePatternIdentifiers;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IRangeValuePatternIdentifiers<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IRangeValuePatternIdentifiersStatics>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IRangeValuePatternIdentifiersStatics;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IRangeValuePatternIdentifiersStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IScrollPatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IScrollPatternIdentifiers;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IScrollPatternIdentifiers<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IScrollPatternIdentifiersStatics>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IScrollPatternIdentifiersStatics;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IScrollPatternIdentifiersStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::ISelectionItemPatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::ISelectionItemPatternIdentifiers;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_ISelectionItemPatternIdentifiers<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::ISelectionItemPatternIdentifiersStatics>
{
    using abi = ABI::Windows::UI::Xaml::Automation::ISelectionItemPatternIdentifiersStatics;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_ISelectionItemPatternIdentifiersStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::ISelectionPatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::ISelectionPatternIdentifiers;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_ISelectionPatternIdentifiers<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::ISelectionPatternIdentifiersStatics>
{
    using abi = ABI::Windows::UI::Xaml::Automation::ISelectionPatternIdentifiersStatics;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_ISelectionPatternIdentifiersStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::ISpreadsheetItemPatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::ISpreadsheetItemPatternIdentifiers;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_ISpreadsheetItemPatternIdentifiers<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::ISpreadsheetItemPatternIdentifiersStatics>
{
    using abi = ABI::Windows::UI::Xaml::Automation::ISpreadsheetItemPatternIdentifiersStatics;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_ISpreadsheetItemPatternIdentifiersStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IStylesPatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IStylesPatternIdentifiers;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IStylesPatternIdentifiers<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IStylesPatternIdentifiersStatics>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IStylesPatternIdentifiersStatics;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IStylesPatternIdentifiersStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::ITableItemPatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::ITableItemPatternIdentifiers;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_ITableItemPatternIdentifiers<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::ITableItemPatternIdentifiersStatics>
{
    using abi = ABI::Windows::UI::Xaml::Automation::ITableItemPatternIdentifiersStatics;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_ITableItemPatternIdentifiersStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::ITablePatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::ITablePatternIdentifiers;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_ITablePatternIdentifiers<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::ITablePatternIdentifiersStatics>
{
    using abi = ABI::Windows::UI::Xaml::Automation::ITablePatternIdentifiersStatics;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_ITablePatternIdentifiersStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::ITogglePatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::ITogglePatternIdentifiers;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_ITogglePatternIdentifiers<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::ITogglePatternIdentifiersStatics>
{
    using abi = ABI::Windows::UI::Xaml::Automation::ITogglePatternIdentifiersStatics;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_ITogglePatternIdentifiersStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::ITransformPattern2Identifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::ITransformPattern2Identifiers;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_ITransformPattern2Identifiers<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::ITransformPattern2IdentifiersStatics>
{
    using abi = ABI::Windows::UI::Xaml::Automation::ITransformPattern2IdentifiersStatics;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_ITransformPattern2IdentifiersStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::ITransformPatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::ITransformPatternIdentifiers;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_ITransformPatternIdentifiers<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::ITransformPatternIdentifiersStatics>
{
    using abi = ABI::Windows::UI::Xaml::Automation::ITransformPatternIdentifiersStatics;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_ITransformPatternIdentifiersStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IValuePatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IValuePatternIdentifiers;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IValuePatternIdentifiers<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IValuePatternIdentifiersStatics>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IValuePatternIdentifiersStatics;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IValuePatternIdentifiersStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IWindowPatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IWindowPatternIdentifiers;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IWindowPatternIdentifiers<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::IWindowPatternIdentifiersStatics>
{
    using abi = ABI::Windows::UI::Xaml::Automation::IWindowPatternIdentifiersStatics;
    template <typename D> using consume = Windows::UI::Xaml::Automation::impl_IWindowPatternIdentifiersStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::AnnotationPatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::AnnotationPatternIdentifiers;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.AnnotationPatternIdentifiers"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::AutomationAnnotation>
{
    using abi = ABI::Windows::UI::Xaml::Automation::AutomationAnnotation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.AutomationAnnotation"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::AutomationElementIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::AutomationElementIdentifiers;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.AutomationElementIdentifiers"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::AutomationProperties>
{
    using abi = ABI::Windows::UI::Xaml::Automation::AutomationProperties;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.AutomationProperties"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::AutomationProperty>
{
    using abi = ABI::Windows::UI::Xaml::Automation::AutomationProperty;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.AutomationProperty"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::DockPatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::DockPatternIdentifiers;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.DockPatternIdentifiers"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::DragPatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::DragPatternIdentifiers;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.DragPatternIdentifiers"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::DropTargetPatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::DropTargetPatternIdentifiers;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.DropTargetPatternIdentifiers"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::ExpandCollapsePatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::ExpandCollapsePatternIdentifiers;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.ExpandCollapsePatternIdentifiers"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::GridItemPatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::GridItemPatternIdentifiers;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.GridItemPatternIdentifiers"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::GridPatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::GridPatternIdentifiers;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.GridPatternIdentifiers"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::MultipleViewPatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::MultipleViewPatternIdentifiers;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.MultipleViewPatternIdentifiers"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::RangeValuePatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::RangeValuePatternIdentifiers;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.RangeValuePatternIdentifiers"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::ScrollPatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::ScrollPatternIdentifiers;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.ScrollPatternIdentifiers"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::SelectionItemPatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::SelectionItemPatternIdentifiers;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.SelectionItemPatternIdentifiers"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::SelectionPatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::SelectionPatternIdentifiers;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.SelectionPatternIdentifiers"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::SpreadsheetItemPatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::SpreadsheetItemPatternIdentifiers;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.SpreadsheetItemPatternIdentifiers"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::StylesPatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::StylesPatternIdentifiers;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.StylesPatternIdentifiers"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::TableItemPatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::TableItemPatternIdentifiers;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.TableItemPatternIdentifiers"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::TablePatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::TablePatternIdentifiers;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.TablePatternIdentifiers"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::TogglePatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::TogglePatternIdentifiers;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.TogglePatternIdentifiers"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::TransformPattern2Identifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::TransformPattern2Identifiers;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.TransformPattern2Identifiers"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::TransformPatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::TransformPatternIdentifiers;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.TransformPatternIdentifiers"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::ValuePatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::ValuePatternIdentifiers;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.ValuePatternIdentifiers"; }
};

template <> struct traits<Windows::UI::Xaml::Automation::WindowPatternIdentifiers>
{
    using abi = ABI::Windows::UI::Xaml::Automation::WindowPatternIdentifiers;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.WindowPatternIdentifiers"; }
};

}

}
