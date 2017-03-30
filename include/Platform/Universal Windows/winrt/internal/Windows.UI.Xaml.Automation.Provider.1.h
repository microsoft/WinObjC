// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.UI.Xaml.Automation.Provider.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.UI.0.h"
#include "Windows.UI.Xaml.Automation.0.h"
#include "Windows.UI.Xaml.Automation.Peers.0.h"
#include "Windows.UI.Xaml.Automation.Text.0.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Xaml::Automation::Provider {

struct __declspec(uuid("95ba1417-4437-451b-9461-050a49b59d06")) __declspec(novtable) IAnnotationProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AnnotationTypeId(int32_t * value) = 0;
    virtual HRESULT __stdcall get_AnnotationTypeName(hstring * value) = 0;
    virtual HRESULT __stdcall get_Author(hstring * value) = 0;
    virtual HRESULT __stdcall get_DateTime(hstring * value) = 0;
    virtual HRESULT __stdcall get_Target(Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple ** value) = 0;
};

struct __declspec(uuid("2bd8a6d0-2fa3-4717-b28c-4917ce54928d")) __declspec(novtable) ICustomNavigationProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_NavigateCustom(winrt::Windows::UI::Xaml::Automation::Peers::AutomationNavigationDirection direction, Windows::Foundation::IInspectable ** returnValue) = 0;
};

struct __declspec(uuid("48c243f8-78b1-44a0-ac5f-750757bcde3c")) __declspec(novtable) IDockProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DockPosition(winrt::Windows::UI::Xaml::Automation::DockPosition * value) = 0;
    virtual HRESULT __stdcall abi_SetDockPosition(winrt::Windows::UI::Xaml::Automation::DockPosition dockPosition) = 0;
};

struct __declspec(uuid("2e7786a9-7ffc-4f57-b965-1ef1f373f546")) __declspec(novtable) IDragProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsGrabbed(bool * value) = 0;
    virtual HRESULT __stdcall get_DropEffect(hstring * value) = 0;
    virtual HRESULT __stdcall get_DropEffects(uint32_t * __valueSize, hstring ** value) = 0;
    virtual HRESULT __stdcall abi_GetGrabbedItems(uint32_t * __returnValueSize, Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple *** returnValue) = 0;
};

struct __declspec(uuid("7a245bdd-b458-4fe0-98c8-aac89df56d61")) __declspec(novtable) IDropTargetProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DropEffect(hstring * value) = 0;
    virtual HRESULT __stdcall get_DropEffects(uint32_t * __valueSize, hstring ** value) = 0;
};

struct __declspec(uuid("49ac8399-d626-4543-94b9-a6d9a9593af6")) __declspec(novtable) IExpandCollapseProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ExpandCollapseState(winrt::Windows::UI::Xaml::Automation::ExpandCollapseState * value) = 0;
    virtual HRESULT __stdcall abi_Collapse() = 0;
    virtual HRESULT __stdcall abi_Expand() = 0;
};

struct __declspec(uuid("fff3683c-7407-45bb-a936-df3ed6d3837d")) __declspec(novtable) IGridItemProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Column(int32_t * value) = 0;
    virtual HRESULT __stdcall get_ColumnSpan(int32_t * value) = 0;
    virtual HRESULT __stdcall get_ContainingGrid(Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple ** value) = 0;
    virtual HRESULT __stdcall get_Row(int32_t * value) = 0;
    virtual HRESULT __stdcall get_RowSpan(int32_t * value) = 0;
};

struct __declspec(uuid("8b62b7a0-932c-4490-9a13-02fdb39a8f5b")) __declspec(novtable) IGridProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ColumnCount(int32_t * value) = 0;
    virtual HRESULT __stdcall get_RowCount(int32_t * value) = 0;
    virtual HRESULT __stdcall abi_GetItem(int32_t row, int32_t column, Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple ** returnValue) = 0;
};

struct __declspec(uuid("ec752224-9b77-4720-bb21-4ac89fdb1afd")) __declspec(novtable) IIRawElementProviderSimple : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("f7d1a187-b13c-4540-b09e-6778e2dc9ba5")) __declspec(novtable) IInvokeProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Invoke() = 0;
};

struct __declspec(uuid("ef5cd845-e1d4-40f4-bad5-c7fad44a703e")) __declspec(novtable) IItemContainerProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FindItemByProperty(Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple * startAfter, Windows::UI::Xaml::Automation::IAutomationProperty * automationProperty, Windows::Foundation::IInspectable * value, Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple ** returnValue) = 0;
};

struct __declspec(uuid("d014e196-0e50-4843-a5d2-c22897c8845a")) __declspec(novtable) IMultipleViewProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CurrentView(int32_t * value) = 0;
    virtual HRESULT __stdcall abi_GetSupportedViews(uint32_t * __returnValueSize, int32_t ** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetViewName(int32_t viewId, hstring * returnValue) = 0;
    virtual HRESULT __stdcall abi_SetCurrentView(int32_t viewId) = 0;
};

struct __declspec(uuid("c3ca36b9-0793-4ed0-bbf4-9ff4e0f98f80")) __declspec(novtable) IObjectModelProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetUnderlyingObjectModel(Windows::Foundation::IInspectable ** returnValue) = 0;
};

struct __declspec(uuid("838a34a8-7d5f-4079-af03-c3d015e93413")) __declspec(novtable) IRangeValueProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsReadOnly(bool * value) = 0;
    virtual HRESULT __stdcall get_LargeChange(double * value) = 0;
    virtual HRESULT __stdcall get_Maximum(double * value) = 0;
    virtual HRESULT __stdcall get_Minimum(double * value) = 0;
    virtual HRESULT __stdcall get_SmallChange(double * value) = 0;
    virtual HRESULT __stdcall get_Value(double * value) = 0;
    virtual HRESULT __stdcall abi_SetValue(double value) = 0;
};

struct __declspec(uuid("9a3ec090-5d2c-4e42-9ee6-9d58db100b55")) __declspec(novtable) IScrollItemProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ScrollIntoView() = 0;
};

struct __declspec(uuid("374bf581-7716-4bbc-82eb-d997006ea999")) __declspec(novtable) IScrollProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_HorizontallyScrollable(bool * value) = 0;
    virtual HRESULT __stdcall get_HorizontalScrollPercent(double * value) = 0;
    virtual HRESULT __stdcall get_HorizontalViewSize(double * value) = 0;
    virtual HRESULT __stdcall get_VerticallyScrollable(bool * value) = 0;
    virtual HRESULT __stdcall get_VerticalScrollPercent(double * value) = 0;
    virtual HRESULT __stdcall get_VerticalViewSize(double * value) = 0;
    virtual HRESULT __stdcall abi_Scroll(winrt::Windows::UI::Xaml::Automation::ScrollAmount horizontalAmount, winrt::Windows::UI::Xaml::Automation::ScrollAmount verticalAmount) = 0;
    virtual HRESULT __stdcall abi_SetScrollPercent(double horizontalPercent, double verticalPercent) = 0;
};

struct __declspec(uuid("6a4977c1-830d-42d2-bf62-042ebddecc19")) __declspec(novtable) ISelectionItemProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsSelected(bool * value) = 0;
    virtual HRESULT __stdcall get_SelectionContainer(Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple ** value) = 0;
    virtual HRESULT __stdcall abi_AddToSelection() = 0;
    virtual HRESULT __stdcall abi_RemoveFromSelection() = 0;
    virtual HRESULT __stdcall abi_Select() = 0;
};

struct __declspec(uuid("1f018fca-b944-4395-8de1-88f674af51d3")) __declspec(novtable) ISelectionProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CanSelectMultiple(bool * value) = 0;
    virtual HRESULT __stdcall get_IsSelectionRequired(bool * value) = 0;
    virtual HRESULT __stdcall abi_GetSelection(uint32_t * __returnValueSize, Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple *** returnValue) = 0;
};

struct __declspec(uuid("ebde8f92-6015-4826-b719-47521a81c67e")) __declspec(novtable) ISpreadsheetItemProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Formula(hstring * value) = 0;
    virtual HRESULT __stdcall abi_GetAnnotationObjects(uint32_t * __returnValueSize, Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple *** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetAnnotationTypes(uint32_t * __returnValueSize, winrt::Windows::UI::Xaml::Automation::AnnotationType ** returnValue) = 0;
};

struct __declspec(uuid("15359093-bd99-4cfd-9f07-3b14b315e23d")) __declspec(novtable) ISpreadsheetProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetItemByName(hstring name, Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple ** returnValue) = 0;
};

struct __declspec(uuid("1a5b7a17-7c01-4bec-9cd4-2dfa7dc246cd")) __declspec(novtable) IStylesProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ExtendedProperties(hstring * value) = 0;
    virtual HRESULT __stdcall get_FillColor(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_FillPatternColor(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_FillPatternStyle(hstring * value) = 0;
    virtual HRESULT __stdcall get_Shape(hstring * value) = 0;
    virtual HRESULT __stdcall get_StyleId(int32_t * value) = 0;
    virtual HRESULT __stdcall get_StyleName(hstring * value) = 0;
};

struct __declspec(uuid("3d60cecb-da54-4aa3-b915-e3244427d4ac")) __declspec(novtable) ISynchronizedInputProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Cancel() = 0;
    virtual HRESULT __stdcall abi_StartListening(winrt::Windows::UI::Xaml::Automation::SynchronizedInputType inputType) = 0;
};

struct __declspec(uuid("3b2c49cd-1de2-4ee2-a3e1-fb553559d15d")) __declspec(novtable) ITableItemProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetColumnHeaderItems(uint32_t * __returnValueSize, Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple *** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetRowHeaderItems(uint32_t * __returnValueSize, Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple *** returnValue) = 0;
};

struct __declspec(uuid("7a8ed399-6824-4595-bab3-464bc9a04417")) __declspec(novtable) ITableProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RowOrColumnMajor(winrt::Windows::UI::Xaml::Automation::RowOrColumnMajor * value) = 0;
    virtual HRESULT __stdcall abi_GetColumnHeaders(uint32_t * __returnValueSize, Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple *** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetRowHeaders(uint32_t * __returnValueSize, Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple *** returnValue) = 0;
};

struct __declspec(uuid("1133c336-a89b-4130-9be6-55e33334f557")) __declspec(novtable) ITextChildProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TextContainer(Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple ** value) = 0;
    virtual HRESULT __stdcall get_TextRange(Windows::UI::Xaml::Automation::Provider::ITextRangeProvider ** value) = 0;
};

struct __declspec(uuid("ea3605b4-3a05-400e-b5f9-4e91b40f6176")) __declspec(novtable) ITextEditProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetActiveComposition(Windows::UI::Xaml::Automation::Provider::ITextRangeProvider ** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetConversionTarget(Windows::UI::Xaml::Automation::Provider::ITextRangeProvider ** returnValue) = 0;
};

struct __declspec(uuid("db5bbc9f-4807-4f2a-8678-1b13f3c60e22")) __declspec(novtable) ITextProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DocumentRange(Windows::UI::Xaml::Automation::Provider::ITextRangeProvider ** value) = 0;
    virtual HRESULT __stdcall get_SupportedTextSelection(winrt::Windows::UI::Xaml::Automation::SupportedTextSelection * value) = 0;
    virtual HRESULT __stdcall abi_GetSelection(uint32_t * __returnValueSize, Windows::UI::Xaml::Automation::Provider::ITextRangeProvider *** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetVisibleRanges(uint32_t * __returnValueSize, Windows::UI::Xaml::Automation::Provider::ITextRangeProvider *** returnValue) = 0;
    virtual HRESULT __stdcall abi_RangeFromChild(Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple * childElement, Windows::UI::Xaml::Automation::Provider::ITextRangeProvider ** returnValue) = 0;
    virtual HRESULT __stdcall abi_RangeFromPoint(Windows::Foundation::Point screenLocation, Windows::UI::Xaml::Automation::Provider::ITextRangeProvider ** returnValue) = 0;
};

struct __declspec(uuid("df1d48bc-0487-4e7f-9d5e-f09e77e41246")) __declspec(novtable) ITextProvider2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RangeFromAnnotation(Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple * annotationElement, Windows::UI::Xaml::Automation::Provider::ITextRangeProvider ** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetCaretRange(bool * isActive, Windows::UI::Xaml::Automation::Provider::ITextRangeProvider ** returnValue) = 0;
};

struct __declspec(uuid("0274688d-06e9-4f66-9446-28a5be98fbd0")) __declspec(novtable) ITextRangeProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Clone(Windows::UI::Xaml::Automation::Provider::ITextRangeProvider ** returnValue) = 0;
    virtual HRESULT __stdcall abi_Compare(Windows::UI::Xaml::Automation::Provider::ITextRangeProvider * textRangeProvider, bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_CompareEndpoints(winrt::Windows::UI::Xaml::Automation::Text::TextPatternRangeEndpoint endpoint, Windows::UI::Xaml::Automation::Provider::ITextRangeProvider * textRangeProvider, winrt::Windows::UI::Xaml::Automation::Text::TextPatternRangeEndpoint targetEndpoint, int32_t * returnValue) = 0;
    virtual HRESULT __stdcall abi_ExpandToEnclosingUnit(winrt::Windows::UI::Xaml::Automation::Text::TextUnit unit) = 0;
    virtual HRESULT __stdcall abi_FindAttribute(int32_t attributeId, Windows::Foundation::IInspectable * value, bool backward, Windows::UI::Xaml::Automation::Provider::ITextRangeProvider ** returnValue) = 0;
    virtual HRESULT __stdcall abi_FindText(hstring text, bool backward, bool ignoreCase, Windows::UI::Xaml::Automation::Provider::ITextRangeProvider ** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetAttributeValue(int32_t attributeId, Windows::Foundation::IInspectable ** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetBoundingRectangles(uint32_t * __returnValueSize, double ** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetEnclosingElement(Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple ** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetText(int32_t maxLength, hstring * returnValue) = 0;
    virtual HRESULT __stdcall abi_Move(winrt::Windows::UI::Xaml::Automation::Text::TextUnit unit, int32_t count, int32_t * returnValue) = 0;
    virtual HRESULT __stdcall abi_MoveEndpointByUnit(winrt::Windows::UI::Xaml::Automation::Text::TextPatternRangeEndpoint endpoint, winrt::Windows::UI::Xaml::Automation::Text::TextUnit unit, int32_t count, int32_t * returnValue) = 0;
    virtual HRESULT __stdcall abi_MoveEndpointByRange(winrt::Windows::UI::Xaml::Automation::Text::TextPatternRangeEndpoint endpoint, Windows::UI::Xaml::Automation::Provider::ITextRangeProvider * textRangeProvider, winrt::Windows::UI::Xaml::Automation::Text::TextPatternRangeEndpoint targetEndpoint) = 0;
    virtual HRESULT __stdcall abi_Select() = 0;
    virtual HRESULT __stdcall abi_AddToSelection() = 0;
    virtual HRESULT __stdcall abi_RemoveFromSelection() = 0;
    virtual HRESULT __stdcall abi_ScrollIntoView(bool alignToTop) = 0;
    virtual HRESULT __stdcall abi_GetChildren(uint32_t * __returnValueSize, Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple *** returnValue) = 0;
};

struct __declspec(uuid("d3be3dfb-9f54-4642-a7a5-5c18d5ee2a3f")) __declspec(novtable) ITextRangeProvider2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ShowContextMenu() = 0;
};

struct __declspec(uuid("93b88290-656f-44f7-aeaf-78b8f944d062")) __declspec(novtable) IToggleProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ToggleState(winrt::Windows::UI::Xaml::Automation::ToggleState * value) = 0;
    virtual HRESULT __stdcall abi_Toggle() = 0;
};

struct __declspec(uuid("79670fdd-f6a9-4a65-af17-861db799a2da")) __declspec(novtable) ITransformProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CanMove(bool * value) = 0;
    virtual HRESULT __stdcall get_CanResize(bool * value) = 0;
    virtual HRESULT __stdcall get_CanRotate(bool * value) = 0;
    virtual HRESULT __stdcall abi_Move(double x, double y) = 0;
    virtual HRESULT __stdcall abi_Resize(double width, double height) = 0;
    virtual HRESULT __stdcall abi_Rotate(double degrees) = 0;
};

struct __declspec(uuid("a8b11756-a39f-4e97-8c7d-c1ea8dd633c5")) __declspec(novtable) ITransformProvider2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CanZoom(bool * value) = 0;
    virtual HRESULT __stdcall get_ZoomLevel(double * value) = 0;
    virtual HRESULT __stdcall get_MaxZoom(double * value) = 0;
    virtual HRESULT __stdcall get_MinZoom(double * value) = 0;
    virtual HRESULT __stdcall abi_Zoom(double zoom) = 0;
    virtual HRESULT __stdcall abi_ZoomByUnit(winrt::Windows::UI::Xaml::Automation::ZoomUnit zoomUnit) = 0;
};

struct __declspec(uuid("2086b7a7-ac0e-47d1-ab9b-2a64292afdf8")) __declspec(novtable) IValueProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsReadOnly(bool * value) = 0;
    virtual HRESULT __stdcall get_Value(hstring * value) = 0;
    virtual HRESULT __stdcall abi_SetValue(hstring value) = 0;
};

struct __declspec(uuid("17d4a04b-d658-48e0-a574-5a516c58dfa7")) __declspec(novtable) IVirtualizedItemProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Realize() = 0;
};

struct __declspec(uuid("1baa8b3d-38cf-415a-85d3-20e43a0ec1b1")) __declspec(novtable) IWindowProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsModal(bool * value) = 0;
    virtual HRESULT __stdcall get_IsTopmost(bool * value) = 0;
    virtual HRESULT __stdcall get_Maximizable(bool * value) = 0;
    virtual HRESULT __stdcall get_Minimizable(bool * value) = 0;
    virtual HRESULT __stdcall get_InteractionState(winrt::Windows::UI::Xaml::Automation::WindowInteractionState * value) = 0;
    virtual HRESULT __stdcall get_VisualState(winrt::Windows::UI::Xaml::Automation::WindowVisualState * value) = 0;
    virtual HRESULT __stdcall abi_Close() = 0;
    virtual HRESULT __stdcall abi_SetVisualState(winrt::Windows::UI::Xaml::Automation::WindowVisualState state) = 0;
    virtual HRESULT __stdcall abi_WaitForInputIdle(int32_t milliseconds, bool * returnValue) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple> { using default_interface = Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple; };

}

namespace Windows::UI::Xaml::Automation::Provider {

template <typename D>
struct WINRT_EBO impl_IAnnotationProvider
{
    int32_t AnnotationTypeId() const;
    hstring AnnotationTypeName() const;
    hstring Author() const;
    hstring DateTime() const;
    Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple Target() const;
};

template <typename D>
struct WINRT_EBO impl_ICustomNavigationProvider
{
    Windows::Foundation::IInspectable NavigateCustom(Windows::UI::Xaml::Automation::Peers::AutomationNavigationDirection direction) const;
};

template <typename D>
struct WINRT_EBO impl_IDockProvider
{
    Windows::UI::Xaml::Automation::DockPosition DockPosition() const;
    void SetDockPosition(Windows::UI::Xaml::Automation::DockPosition dockPosition) const;
};

template <typename D>
struct WINRT_EBO impl_IDragProvider
{
    bool IsGrabbed() const;
    hstring DropEffect() const;
    com_array<hstring> DropEffects() const;
    com_array<Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple> GetGrabbedItems() const;
};

template <typename D>
struct WINRT_EBO impl_IDropTargetProvider
{
    hstring DropEffect() const;
    com_array<hstring> DropEffects() const;
};

template <typename D>
struct WINRT_EBO impl_IExpandCollapseProvider
{
    Windows::UI::Xaml::Automation::ExpandCollapseState ExpandCollapseState() const;
    void Collapse() const;
    void Expand() const;
};

template <typename D>
struct WINRT_EBO impl_IGridItemProvider
{
    int32_t Column() const;
    int32_t ColumnSpan() const;
    Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple ContainingGrid() const;
    int32_t Row() const;
    int32_t RowSpan() const;
};

template <typename D>
struct WINRT_EBO impl_IGridProvider
{
    int32_t ColumnCount() const;
    int32_t RowCount() const;
    Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple GetItem(int32_t row, int32_t column) const;
};

template <typename D>
struct WINRT_EBO impl_IIRawElementProviderSimple
{
};

template <typename D>
struct WINRT_EBO impl_IInvokeProvider
{
    void Invoke() const;
};

template <typename D>
struct WINRT_EBO impl_IItemContainerProvider
{
    Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple FindItemByProperty(const Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple & startAfter, const Windows::UI::Xaml::Automation::AutomationProperty & automationProperty, const Windows::Foundation::IInspectable & value) const;
};

template <typename D>
struct WINRT_EBO impl_IMultipleViewProvider
{
    int32_t CurrentView() const;
    com_array<int32_t> GetSupportedViews() const;
    hstring GetViewName(int32_t viewId) const;
    void SetCurrentView(int32_t viewId) const;
};

template <typename D>
struct WINRT_EBO impl_IObjectModelProvider
{
    Windows::Foundation::IInspectable GetUnderlyingObjectModel() const;
};

template <typename D>
struct WINRT_EBO impl_IRangeValueProvider
{
    bool IsReadOnly() const;
    double LargeChange() const;
    double Maximum() const;
    double Minimum() const;
    double SmallChange() const;
    double Value() const;
    void SetValue(double value) const;
};

template <typename D>
struct WINRT_EBO impl_IScrollItemProvider
{
    void ScrollIntoView() const;
};

template <typename D>
struct WINRT_EBO impl_IScrollProvider
{
    bool HorizontallyScrollable() const;
    double HorizontalScrollPercent() const;
    double HorizontalViewSize() const;
    bool VerticallyScrollable() const;
    double VerticalScrollPercent() const;
    double VerticalViewSize() const;
    void Scroll(Windows::UI::Xaml::Automation::ScrollAmount horizontalAmount, Windows::UI::Xaml::Automation::ScrollAmount verticalAmount) const;
    void SetScrollPercent(double horizontalPercent, double verticalPercent) const;
};

template <typename D>
struct WINRT_EBO impl_ISelectionItemProvider
{
    bool IsSelected() const;
    Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple SelectionContainer() const;
    void AddToSelection() const;
    void RemoveFromSelection() const;
    void Select() const;
};

template <typename D>
struct WINRT_EBO impl_ISelectionProvider
{
    bool CanSelectMultiple() const;
    bool IsSelectionRequired() const;
    com_array<Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple> GetSelection() const;
};

template <typename D>
struct WINRT_EBO impl_ISpreadsheetItemProvider
{
    hstring Formula() const;
    com_array<Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple> GetAnnotationObjects() const;
    com_array<Windows::UI::Xaml::Automation::AnnotationType> GetAnnotationTypes() const;
};

template <typename D>
struct WINRT_EBO impl_ISpreadsheetProvider
{
    Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple GetItemByName(hstring_view name) const;
};

template <typename D>
struct WINRT_EBO impl_IStylesProvider
{
    hstring ExtendedProperties() const;
    Windows::UI::Color FillColor() const;
    Windows::UI::Color FillPatternColor() const;
    hstring FillPatternStyle() const;
    hstring Shape() const;
    int32_t StyleId() const;
    hstring StyleName() const;
};

template <typename D>
struct WINRT_EBO impl_ISynchronizedInputProvider
{
    void Cancel() const;
    void StartListening(Windows::UI::Xaml::Automation::SynchronizedInputType inputType) const;
};

template <typename D>
struct WINRT_EBO impl_ITableItemProvider
{
    com_array<Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple> GetColumnHeaderItems() const;
    com_array<Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple> GetRowHeaderItems() const;
};

template <typename D>
struct WINRT_EBO impl_ITableProvider
{
    Windows::UI::Xaml::Automation::RowOrColumnMajor RowOrColumnMajor() const;
    com_array<Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple> GetColumnHeaders() const;
    com_array<Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple> GetRowHeaders() const;
};

template <typename D>
struct WINRT_EBO impl_ITextChildProvider
{
    Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple TextContainer() const;
    Windows::UI::Xaml::Automation::Provider::ITextRangeProvider TextRange() const;
};

template <typename D>
struct WINRT_EBO impl_ITextEditProvider
{
    Windows::UI::Xaml::Automation::Provider::ITextRangeProvider GetActiveComposition() const;
    Windows::UI::Xaml::Automation::Provider::ITextRangeProvider GetConversionTarget() const;
};

template <typename D>
struct WINRT_EBO impl_ITextProvider
{
    Windows::UI::Xaml::Automation::Provider::ITextRangeProvider DocumentRange() const;
    Windows::UI::Xaml::Automation::SupportedTextSelection SupportedTextSelection() const;
    com_array<Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> GetSelection() const;
    com_array<Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> GetVisibleRanges() const;
    Windows::UI::Xaml::Automation::Provider::ITextRangeProvider RangeFromChild(const Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple & childElement) const;
    Windows::UI::Xaml::Automation::Provider::ITextRangeProvider RangeFromPoint(const Windows::Foundation::Point & screenLocation) const;
};

template <typename D>
struct WINRT_EBO impl_ITextProvider2
{
    Windows::UI::Xaml::Automation::Provider::ITextRangeProvider RangeFromAnnotation(const Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple & annotationElement) const;
    Windows::UI::Xaml::Automation::Provider::ITextRangeProvider GetCaretRange(bool & isActive) const;
};

template <typename D>
struct WINRT_EBO impl_ITextRangeProvider
{
    Windows::UI::Xaml::Automation::Provider::ITextRangeProvider Clone() const;
    bool Compare(const Windows::UI::Xaml::Automation::Provider::ITextRangeProvider & textRangeProvider) const;
    int32_t CompareEndpoints(Windows::UI::Xaml::Automation::Text::TextPatternRangeEndpoint endpoint, const Windows::UI::Xaml::Automation::Provider::ITextRangeProvider & textRangeProvider, Windows::UI::Xaml::Automation::Text::TextPatternRangeEndpoint targetEndpoint) const;
    void ExpandToEnclosingUnit(Windows::UI::Xaml::Automation::Text::TextUnit unit) const;
    Windows::UI::Xaml::Automation::Provider::ITextRangeProvider FindAttribute(int32_t attributeId, const Windows::Foundation::IInspectable & value, bool backward) const;
    Windows::UI::Xaml::Automation::Provider::ITextRangeProvider FindText(hstring_view text, bool backward, bool ignoreCase) const;
    Windows::Foundation::IInspectable GetAttributeValue(int32_t attributeId) const;
    void GetBoundingRectangles(com_array<double> & returnValue) const;
    Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple GetEnclosingElement() const;
    hstring GetText(int32_t maxLength) const;
    int32_t Move(Windows::UI::Xaml::Automation::Text::TextUnit unit, int32_t count) const;
    int32_t MoveEndpointByUnit(Windows::UI::Xaml::Automation::Text::TextPatternRangeEndpoint endpoint, Windows::UI::Xaml::Automation::Text::TextUnit unit, int32_t count) const;
    void MoveEndpointByRange(Windows::UI::Xaml::Automation::Text::TextPatternRangeEndpoint endpoint, const Windows::UI::Xaml::Automation::Provider::ITextRangeProvider & textRangeProvider, Windows::UI::Xaml::Automation::Text::TextPatternRangeEndpoint targetEndpoint) const;
    void Select() const;
    void AddToSelection() const;
    void RemoveFromSelection() const;
    void ScrollIntoView(bool alignToTop) const;
    com_array<Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple> GetChildren() const;
};

template <typename D>
struct WINRT_EBO impl_ITextRangeProvider2
{
    void ShowContextMenu() const;
};

template <typename D>
struct WINRT_EBO impl_IToggleProvider
{
    Windows::UI::Xaml::Automation::ToggleState ToggleState() const;
    void Toggle() const;
};

template <typename D>
struct WINRT_EBO impl_ITransformProvider
{
    bool CanMove() const;
    bool CanResize() const;
    bool CanRotate() const;
    void Move(double x, double y) const;
    void Resize(double width, double height) const;
    void Rotate(double degrees) const;
};

template <typename D>
struct WINRT_EBO impl_ITransformProvider2
{
    bool CanZoom() const;
    double ZoomLevel() const;
    double MaxZoom() const;
    double MinZoom() const;
    void Zoom(double zoom) const;
    void ZoomByUnit(Windows::UI::Xaml::Automation::ZoomUnit zoomUnit) const;
};

template <typename D>
struct WINRT_EBO impl_IValueProvider
{
    bool IsReadOnly() const;
    hstring Value() const;
    void SetValue(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IVirtualizedItemProvider
{
    void Realize() const;
};

template <typename D>
struct WINRT_EBO impl_IWindowProvider
{
    bool IsModal() const;
    bool IsTopmost() const;
    bool Maximizable() const;
    bool Minimizable() const;
    Windows::UI::Xaml::Automation::WindowInteractionState InteractionState() const;
    Windows::UI::Xaml::Automation::WindowVisualState VisualState() const;
    void Close() const;
    void SetVisualState(Windows::UI::Xaml::Automation::WindowVisualState state) const;
    bool WaitForInputIdle(int32_t milliseconds) const;
};

}

namespace impl {

template <> struct traits<Windows::UI::Xaml::Automation::Provider::IAnnotationProvider>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Provider::IAnnotationProvider;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Provider::impl_IAnnotationProvider<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Provider::ICustomNavigationProvider>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Provider::ICustomNavigationProvider;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Provider::impl_ICustomNavigationProvider<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Provider::IDockProvider>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Provider::IDockProvider;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Provider::impl_IDockProvider<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Provider::IDragProvider>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Provider::IDragProvider;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Provider::impl_IDragProvider<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Provider::IDropTargetProvider>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Provider::IDropTargetProvider;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Provider::impl_IDropTargetProvider<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Provider::IExpandCollapseProvider>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Provider::IExpandCollapseProvider;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Provider::impl_IExpandCollapseProvider<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Provider::IGridItemProvider>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Provider::IGridItemProvider;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Provider::impl_IGridItemProvider<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Provider::IGridProvider>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Provider::IGridProvider;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Provider::impl_IGridProvider<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Provider::impl_IIRawElementProviderSimple<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Provider::IInvokeProvider>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Provider::IInvokeProvider;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Provider::impl_IInvokeProvider<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Provider::IItemContainerProvider>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Provider::IItemContainerProvider;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Provider::impl_IItemContainerProvider<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Provider::IMultipleViewProvider>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Provider::IMultipleViewProvider;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Provider::impl_IMultipleViewProvider<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Provider::IObjectModelProvider>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Provider::IObjectModelProvider;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Provider::impl_IObjectModelProvider<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Provider::IRangeValueProvider>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Provider::IRangeValueProvider;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Provider::impl_IRangeValueProvider<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Provider::IScrollItemProvider>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Provider::IScrollItemProvider;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Provider::impl_IScrollItemProvider<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Provider::IScrollProvider>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Provider::impl_IScrollProvider<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Provider::impl_ISelectionItemProvider<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Provider::ISelectionProvider>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Provider::ISelectionProvider;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Provider::impl_ISelectionProvider<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Provider::ISpreadsheetItemProvider>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Provider::ISpreadsheetItemProvider;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Provider::impl_ISpreadsheetItemProvider<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Provider::ISpreadsheetProvider>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Provider::ISpreadsheetProvider;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Provider::impl_ISpreadsheetProvider<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Provider::IStylesProvider>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Provider::IStylesProvider;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Provider::impl_IStylesProvider<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Provider::ISynchronizedInputProvider>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Provider::ISynchronizedInputProvider;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Provider::impl_ISynchronizedInputProvider<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Provider::ITableItemProvider>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Provider::ITableItemProvider;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Provider::impl_ITableItemProvider<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Provider::ITableProvider>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Provider::ITableProvider;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Provider::impl_ITableProvider<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Provider::ITextChildProvider>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Provider::ITextChildProvider;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Provider::impl_ITextChildProvider<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Provider::ITextEditProvider>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Provider::ITextEditProvider;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Provider::impl_ITextEditProvider<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Provider::ITextProvider>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Provider::ITextProvider;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Provider::impl_ITextProvider<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Provider::ITextProvider2>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Provider::ITextProvider2;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Provider::impl_ITextProvider2<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Provider::impl_ITextRangeProvider<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Provider::ITextRangeProvider2>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider2;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Provider::impl_ITextRangeProvider2<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Provider::IToggleProvider>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Provider::IToggleProvider;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Provider::impl_IToggleProvider<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Provider::ITransformProvider>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Provider::ITransformProvider;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Provider::impl_ITransformProvider<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Provider::ITransformProvider2>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Provider::ITransformProvider2;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Provider::impl_ITransformProvider2<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Provider::IValueProvider>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Provider::IValueProvider;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Provider::impl_IValueProvider<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Provider::impl_IVirtualizedItemProvider<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Provider::IWindowProvider>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Provider::IWindowProvider;
    template <typename D> using consume = Windows::UI::Xaml::Automation::Provider::impl_IWindowProvider<D>;
};

template <> struct traits<Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple>
{
    using abi = ABI::Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Automation.Provider.IRawElementProviderSimple"; }
};

}

}
