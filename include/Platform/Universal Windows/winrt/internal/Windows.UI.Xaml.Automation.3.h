// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Automation.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Automation {

struct WINRT_EBO AnnotationPatternIdentifiers :
    Windows::UI::Xaml::Automation::IAnnotationPatternIdentifiers
{
    AnnotationPatternIdentifiers(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::Automation::AutomationProperty AnnotationTypeIdProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty AnnotationTypeNameProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty AuthorProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty DateTimeProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty TargetProperty();
};

struct WINRT_EBO AutomationAnnotation :
    Windows::UI::Xaml::Automation::IAutomationAnnotation,
    impl::bases<AutomationAnnotation, Windows::UI::Xaml::DependencyObject>,
    impl::require<AutomationAnnotation, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    AutomationAnnotation(std::nullptr_t) noexcept {}
    AutomationAnnotation();
    AutomationAnnotation(Windows::UI::Xaml::Automation::AnnotationType type);
    AutomationAnnotation(Windows::UI::Xaml::Automation::AnnotationType type, const Windows::UI::Xaml::UIElement & element);
    static Windows::UI::Xaml::DependencyProperty TypeProperty();
    static Windows::UI::Xaml::DependencyProperty ElementProperty();
};

struct WINRT_EBO AutomationElementIdentifiers :
    Windows::UI::Xaml::Automation::IAutomationElementIdentifiers
{
    AutomationElementIdentifiers(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::Automation::AutomationProperty AcceleratorKeyProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty AccessKeyProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty AutomationIdProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty BoundingRectangleProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty ClassNameProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty ClickablePointProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty ControlTypeProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty HasKeyboardFocusProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty HelpTextProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty IsContentElementProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty IsControlElementProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty IsEnabledProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty IsKeyboardFocusableProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty IsOffscreenProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty IsPasswordProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty IsRequiredForFormProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty ItemStatusProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty ItemTypeProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty LabeledByProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty LocalizedControlTypeProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty NameProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty OrientationProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty LiveSettingProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty ControlledPeersProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty PositionInSetProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty SizeOfSetProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty LevelProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty AnnotationsProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty LandmarkTypeProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty LocalizedLandmarkTypeProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty IsPeripheralProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty IsDataValidForFormProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty FullDescriptionProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty DescribedByProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty FlowsToProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty FlowsFromProperty();
};

struct WINRT_EBO AutomationProperties :
    Windows::UI::Xaml::Automation::IAutomationProperties
{
    AutomationProperties(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::DependencyProperty AcceleratorKeyProperty();
    static hstring GetAcceleratorKey(const Windows::UI::Xaml::DependencyObject & element);
    static void SetAcceleratorKey(const Windows::UI::Xaml::DependencyObject & element, hstring_view value);
    static Windows::UI::Xaml::DependencyProperty AccessKeyProperty();
    static hstring GetAccessKey(const Windows::UI::Xaml::DependencyObject & element);
    static void SetAccessKey(const Windows::UI::Xaml::DependencyObject & element, hstring_view value);
    static Windows::UI::Xaml::DependencyProperty AutomationIdProperty();
    static hstring GetAutomationId(const Windows::UI::Xaml::DependencyObject & element);
    static void SetAutomationId(const Windows::UI::Xaml::DependencyObject & element, hstring_view value);
    static Windows::UI::Xaml::DependencyProperty HelpTextProperty();
    static hstring GetHelpText(const Windows::UI::Xaml::DependencyObject & element);
    static void SetHelpText(const Windows::UI::Xaml::DependencyObject & element, hstring_view value);
    static Windows::UI::Xaml::DependencyProperty IsRequiredForFormProperty();
    static bool GetIsRequiredForForm(const Windows::UI::Xaml::DependencyObject & element);
    static void SetIsRequiredForForm(const Windows::UI::Xaml::DependencyObject & element, bool value);
    static Windows::UI::Xaml::DependencyProperty ItemStatusProperty();
    static hstring GetItemStatus(const Windows::UI::Xaml::DependencyObject & element);
    static void SetItemStatus(const Windows::UI::Xaml::DependencyObject & element, hstring_view value);
    static Windows::UI::Xaml::DependencyProperty ItemTypeProperty();
    static hstring GetItemType(const Windows::UI::Xaml::DependencyObject & element);
    static void SetItemType(const Windows::UI::Xaml::DependencyObject & element, hstring_view value);
    static Windows::UI::Xaml::DependencyProperty LabeledByProperty();
    static Windows::UI::Xaml::UIElement GetLabeledBy(const Windows::UI::Xaml::DependencyObject & element);
    static void SetLabeledBy(const Windows::UI::Xaml::DependencyObject & element, const Windows::UI::Xaml::UIElement & value);
    static Windows::UI::Xaml::DependencyProperty NameProperty();
    static hstring GetName(const Windows::UI::Xaml::DependencyObject & element);
    static void SetName(const Windows::UI::Xaml::DependencyObject & element, hstring_view value);
    static Windows::UI::Xaml::DependencyProperty LiveSettingProperty();
    static Windows::UI::Xaml::Automation::Peers::AutomationLiveSetting GetLiveSetting(const Windows::UI::Xaml::DependencyObject & element);
    static void SetLiveSetting(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::Automation::Peers::AutomationLiveSetting value);
    static Windows::UI::Xaml::DependencyProperty AccessibilityViewProperty();
    static Windows::UI::Xaml::Automation::Peers::AccessibilityView GetAccessibilityView(const Windows::UI::Xaml::DependencyObject & element);
    static void SetAccessibilityView(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::Automation::Peers::AccessibilityView value);
    static Windows::UI::Xaml::DependencyProperty ControlledPeersProperty();
    static Windows::Foundation::Collections::IVector<Windows::UI::Xaml::UIElement> GetControlledPeers(const Windows::UI::Xaml::DependencyObject & element);
    static Windows::UI::Xaml::DependencyProperty PositionInSetProperty();
    static int32_t GetPositionInSet(const Windows::UI::Xaml::DependencyObject & element);
    static void SetPositionInSet(const Windows::UI::Xaml::DependencyObject & element, int32_t value);
    static Windows::UI::Xaml::DependencyProperty SizeOfSetProperty();
    static int32_t GetSizeOfSet(const Windows::UI::Xaml::DependencyObject & element);
    static void SetSizeOfSet(const Windows::UI::Xaml::DependencyObject & element, int32_t value);
    static Windows::UI::Xaml::DependencyProperty LevelProperty();
    static int32_t GetLevel(const Windows::UI::Xaml::DependencyObject & element);
    static void SetLevel(const Windows::UI::Xaml::DependencyObject & element, int32_t value);
    static Windows::UI::Xaml::DependencyProperty AnnotationsProperty();
    static Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Automation::AutomationAnnotation> GetAnnotations(const Windows::UI::Xaml::DependencyObject & element);
    static Windows::UI::Xaml::DependencyProperty LandmarkTypeProperty();
    static Windows::UI::Xaml::Automation::Peers::AutomationLandmarkType GetLandmarkType(const Windows::UI::Xaml::DependencyObject & element);
    static void SetLandmarkType(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::Automation::Peers::AutomationLandmarkType value);
    static Windows::UI::Xaml::DependencyProperty LocalizedLandmarkTypeProperty();
    static hstring GetLocalizedLandmarkType(const Windows::UI::Xaml::DependencyObject & element);
    static void SetLocalizedLandmarkType(const Windows::UI::Xaml::DependencyObject & element, hstring_view value);
    static Windows::UI::Xaml::DependencyProperty IsPeripheralProperty();
    static bool GetIsPeripheral(const Windows::UI::Xaml::DependencyObject & element);
    static void SetIsPeripheral(const Windows::UI::Xaml::DependencyObject & element, bool value);
    static Windows::UI::Xaml::DependencyProperty IsDataValidForFormProperty();
    static bool GetIsDataValidForForm(const Windows::UI::Xaml::DependencyObject & element);
    static void SetIsDataValidForForm(const Windows::UI::Xaml::DependencyObject & element, bool value);
    static Windows::UI::Xaml::DependencyProperty FullDescriptionProperty();
    static hstring GetFullDescription(const Windows::UI::Xaml::DependencyObject & element);
    static void SetFullDescription(const Windows::UI::Xaml::DependencyObject & element, hstring_view value);
    static Windows::UI::Xaml::DependencyProperty LocalizedControlTypeProperty();
    static hstring GetLocalizedControlType(const Windows::UI::Xaml::DependencyObject & element);
    static void SetLocalizedControlType(const Windows::UI::Xaml::DependencyObject & element, hstring_view value);
    static Windows::UI::Xaml::DependencyProperty DescribedByProperty();
    static Windows::Foundation::Collections::IVector<Windows::UI::Xaml::DependencyObject> GetDescribedBy(const Windows::UI::Xaml::DependencyObject & element);
    static Windows::UI::Xaml::DependencyProperty FlowsToProperty();
    static Windows::Foundation::Collections::IVector<Windows::UI::Xaml::DependencyObject> GetFlowsTo(const Windows::UI::Xaml::DependencyObject & element);
    static Windows::UI::Xaml::DependencyProperty FlowsFromProperty();
    static Windows::Foundation::Collections::IVector<Windows::UI::Xaml::DependencyObject> GetFlowsFrom(const Windows::UI::Xaml::DependencyObject & element);
};

struct WINRT_EBO AutomationProperty :
    Windows::UI::Xaml::Automation::IAutomationProperty
{
    AutomationProperty(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DockPatternIdentifiers :
    Windows::UI::Xaml::Automation::IDockPatternIdentifiers
{
    DockPatternIdentifiers(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::Automation::AutomationProperty DockPositionProperty();
};

struct WINRT_EBO DragPatternIdentifiers :
    Windows::UI::Xaml::Automation::IDragPatternIdentifiers
{
    DragPatternIdentifiers(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::Automation::AutomationProperty DropEffectProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty DropEffectsProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty GrabbedItemsProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty IsGrabbedProperty();
};

struct WINRT_EBO DropTargetPatternIdentifiers :
    Windows::UI::Xaml::Automation::IDropTargetPatternIdentifiers
{
    DropTargetPatternIdentifiers(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::Automation::AutomationProperty DropTargetEffectProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty DropTargetEffectsProperty();
};

struct WINRT_EBO ExpandCollapsePatternIdentifiers :
    Windows::UI::Xaml::Automation::IExpandCollapsePatternIdentifiers
{
    ExpandCollapsePatternIdentifiers(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::Automation::AutomationProperty ExpandCollapseStateProperty();
};

struct WINRT_EBO GridItemPatternIdentifiers :
    Windows::UI::Xaml::Automation::IGridItemPatternIdentifiers
{
    GridItemPatternIdentifiers(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::Automation::AutomationProperty ColumnProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty ColumnSpanProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty ContainingGridProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty RowProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty RowSpanProperty();
};

struct WINRT_EBO GridPatternIdentifiers :
    Windows::UI::Xaml::Automation::IGridPatternIdentifiers
{
    GridPatternIdentifiers(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::Automation::AutomationProperty ColumnCountProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty RowCountProperty();
};

struct WINRT_EBO MultipleViewPatternIdentifiers :
    Windows::UI::Xaml::Automation::IMultipleViewPatternIdentifiers
{
    MultipleViewPatternIdentifiers(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::Automation::AutomationProperty CurrentViewProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty SupportedViewsProperty();
};

struct WINRT_EBO RangeValuePatternIdentifiers :
    Windows::UI::Xaml::Automation::IRangeValuePatternIdentifiers
{
    RangeValuePatternIdentifiers(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::Automation::AutomationProperty IsReadOnlyProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty LargeChangeProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty MaximumProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty MinimumProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty SmallChangeProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty ValueProperty();
};

struct WINRT_EBO ScrollPatternIdentifiers :
    Windows::UI::Xaml::Automation::IScrollPatternIdentifiers
{
    ScrollPatternIdentifiers(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::Automation::AutomationProperty HorizontallyScrollableProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty HorizontalScrollPercentProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty HorizontalViewSizeProperty();
    static double NoScroll();
    static Windows::UI::Xaml::Automation::AutomationProperty VerticallyScrollableProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty VerticalScrollPercentProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty VerticalViewSizeProperty();
};

struct WINRT_EBO SelectionItemPatternIdentifiers :
    Windows::UI::Xaml::Automation::ISelectionItemPatternIdentifiers
{
    SelectionItemPatternIdentifiers(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::Automation::AutomationProperty IsSelectedProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty SelectionContainerProperty();
};

struct WINRT_EBO SelectionPatternIdentifiers :
    Windows::UI::Xaml::Automation::ISelectionPatternIdentifiers
{
    SelectionPatternIdentifiers(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::Automation::AutomationProperty CanSelectMultipleProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty IsSelectionRequiredProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty SelectionProperty();
};

struct WINRT_EBO SpreadsheetItemPatternIdentifiers :
    Windows::UI::Xaml::Automation::ISpreadsheetItemPatternIdentifiers
{
    SpreadsheetItemPatternIdentifiers(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::Automation::AutomationProperty FormulaProperty();
};

struct WINRT_EBO StylesPatternIdentifiers :
    Windows::UI::Xaml::Automation::IStylesPatternIdentifiers
{
    StylesPatternIdentifiers(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::Automation::AutomationProperty ExtendedPropertiesProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty FillColorProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty FillPatternColorProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty FillPatternStyleProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty ShapeProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty StyleIdProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty StyleNameProperty();
};

struct WINRT_EBO TableItemPatternIdentifiers :
    Windows::UI::Xaml::Automation::ITableItemPatternIdentifiers
{
    TableItemPatternIdentifiers(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::Automation::AutomationProperty ColumnHeaderItemsProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty RowHeaderItemsProperty();
};

struct WINRT_EBO TablePatternIdentifiers :
    Windows::UI::Xaml::Automation::ITablePatternIdentifiers
{
    TablePatternIdentifiers(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::Automation::AutomationProperty ColumnHeadersProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty RowHeadersProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty RowOrColumnMajorProperty();
};

struct WINRT_EBO TogglePatternIdentifiers :
    Windows::UI::Xaml::Automation::ITogglePatternIdentifiers
{
    TogglePatternIdentifiers(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::Automation::AutomationProperty ToggleStateProperty();
};

struct WINRT_EBO TransformPattern2Identifiers :
    Windows::UI::Xaml::Automation::ITransformPattern2Identifiers
{
    TransformPattern2Identifiers(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::Automation::AutomationProperty CanZoomProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty ZoomLevelProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty MaxZoomProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty MinZoomProperty();
};

struct WINRT_EBO TransformPatternIdentifiers :
    Windows::UI::Xaml::Automation::ITransformPatternIdentifiers
{
    TransformPatternIdentifiers(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::Automation::AutomationProperty CanMoveProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty CanResizeProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty CanRotateProperty();
};

struct WINRT_EBO ValuePatternIdentifiers :
    Windows::UI::Xaml::Automation::IValuePatternIdentifiers
{
    ValuePatternIdentifiers(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::Automation::AutomationProperty IsReadOnlyProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty ValueProperty();
};

struct WINRT_EBO WindowPatternIdentifiers :
    Windows::UI::Xaml::Automation::IWindowPatternIdentifiers
{
    WindowPatternIdentifiers(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::Automation::AutomationProperty CanMaximizeProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty CanMinimizeProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty IsModalProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty IsTopmostProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty WindowInteractionStateProperty();
    static Windows::UI::Xaml::Automation::AutomationProperty WindowVisualStateProperty();
};

}

}
