// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Automation.1.h"
#include "Windows.UI.Xaml.1.h"
#include "Windows.UI.Xaml.2.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_42e26ae1_d357_57e8_bb48_f75c9ff69d91
#define WINRT_GENERIC_42e26ae1_d357_57e8_bb48_f75c9ff69d91
template <> struct __declspec(uuid("42e26ae1-d357-57e8-bb48-f75c9ff69d91")) __declspec(novtable) IIterable<Windows::UI::Xaml::UIElement> : impl_IIterable<Windows::UI::Xaml::UIElement> {};
#endif

#ifndef WINRT_GENERIC_b4c1e3ac_8768_5b9d_a661_f63330b8507b
#define WINRT_GENERIC_b4c1e3ac_8768_5b9d_a661_f63330b8507b
template <> struct __declspec(uuid("b4c1e3ac-8768-5b9d-a661-f63330b8507b")) __declspec(novtable) IVector<Windows::UI::Xaml::UIElement> : impl_IVector<Windows::UI::Xaml::UIElement> {};
#endif

#ifndef WINRT_GENERIC_771b857e_ab5c_5db8_a021_397c92cdc44c
#define WINRT_GENERIC_771b857e_ab5c_5db8_a021_397c92cdc44c
template <> struct __declspec(uuid("771b857e-ab5c-5db8-a021-397c92cdc44c")) __declspec(novtable) IVector<Windows::UI::Xaml::DependencyObject> : impl_IVector<Windows::UI::Xaml::DependencyObject> {};
#endif

#ifndef WINRT_GENERIC_f66c6bd3_55b4_5bbb_b82a_6d9ce383091a
#define WINRT_GENERIC_f66c6bd3_55b4_5bbb_b82a_6d9ce383091a
template <> struct __declspec(uuid("f66c6bd3-55b4-5bbb-b82a-6d9ce383091a")) __declspec(novtable) IIterable<Windows::UI::Xaml::DependencyObject> : impl_IIterable<Windows::UI::Xaml::DependencyObject> {};
#endif

#ifndef WINRT_GENERIC_73596c82_f6e5_5b57_8dc5_556cb7a8fbe6
#define WINRT_GENERIC_73596c82_f6e5_5b57_8dc5_556cb7a8fbe6
template <> struct __declspec(uuid("73596c82-f6e5-5b57-8dc5-556cb7a8fbe6")) __declspec(novtable) IVector<Windows::UI::Xaml::Automation::AutomationAnnotation> : impl_IVector<Windows::UI::Xaml::Automation::AutomationAnnotation> {};
#endif

#ifndef WINRT_GENERIC_1d1f9d60_d53b_57f7_b144_8f7c487846e8
#define WINRT_GENERIC_1d1f9d60_d53b_57f7_b144_8f7c487846e8
template <> struct __declspec(uuid("1d1f9d60-d53b-57f7-b144-8f7c487846e8")) __declspec(novtable) IIterator<Windows::UI::Xaml::UIElement> : impl_IIterator<Windows::UI::Xaml::UIElement> {};
#endif

#ifndef WINRT_GENERIC_f3864c10_14a4_5516_b1d9_63b6579429b1
#define WINRT_GENERIC_f3864c10_14a4_5516_b1d9_63b6579429b1
template <> struct __declspec(uuid("f3864c10-14a4-5516-b1d9-63b6579429b1")) __declspec(novtable) IVectorView<Windows::UI::Xaml::UIElement> : impl_IVectorView<Windows::UI::Xaml::UIElement> {};
#endif

#ifndef WINRT_GENERIC_29f8d454_905d_587e_b9d8_bfd418805a65
#define WINRT_GENERIC_29f8d454_905d_587e_b9d8_bfd418805a65
template <> struct __declspec(uuid("29f8d454-905d-587e-b9d8-bfd418805a65")) __declspec(novtable) IIterator<Windows::UI::Xaml::DependencyObject> : impl_IIterator<Windows::UI::Xaml::DependencyObject> {};
#endif

#ifndef WINRT_GENERIC_fe750d77_1307_5df2_a021_1c7a8d6b80ad
#define WINRT_GENERIC_fe750d77_1307_5df2_a021_1c7a8d6b80ad
template <> struct __declspec(uuid("fe750d77-1307-5df2-a021-1c7a8d6b80ad")) __declspec(novtable) IVectorView<Windows::UI::Xaml::DependencyObject> : impl_IVectorView<Windows::UI::Xaml::DependencyObject> {};
#endif

#ifndef WINRT_GENERIC_7ed32ba3_db0c_5a54_ab43_30628afbc2d8
#define WINRT_GENERIC_7ed32ba3_db0c_5a54_ab43_30628afbc2d8
template <> struct __declspec(uuid("7ed32ba3-db0c-5a54-ab43-30628afbc2d8")) __declspec(novtable) IIterator<Windows::UI::Xaml::Automation::AutomationAnnotation> : impl_IIterator<Windows::UI::Xaml::Automation::AutomationAnnotation> {};
#endif

#ifndef WINRT_GENERIC_c6e210cb_1c7b_5e6a_936b_61d4e536a291
#define WINRT_GENERIC_c6e210cb_1c7b_5e6a_936b_61d4e536a291
template <> struct __declspec(uuid("c6e210cb-1c7b-5e6a-936b-61d4e536a291")) __declspec(novtable) IIterable<Windows::UI::Xaml::Automation::AutomationAnnotation> : impl_IIterable<Windows::UI::Xaml::Automation::AutomationAnnotation> {};
#endif

#ifndef WINRT_GENERIC_a4b8a26c_9009_5394_98c8_98107e80db61
#define WINRT_GENERIC_a4b8a26c_9009_5394_98c8_98107e80db61
template <> struct __declspec(uuid("a4b8a26c-9009-5394-98c8-98107e80db61")) __declspec(novtable) IVectorView<Windows::UI::Xaml::Automation::AutomationAnnotation> : impl_IVectorView<Windows::UI::Xaml::Automation::AutomationAnnotation> {};
#endif


}

namespace Windows::UI::Xaml::Automation {

struct IAnnotationPatternIdentifiers :
    Windows::Foundation::IInspectable,
    impl::consume<IAnnotationPatternIdentifiers>
{
    IAnnotationPatternIdentifiers(std::nullptr_t = nullptr) noexcept {}
};

struct IAnnotationPatternIdentifiersStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IAnnotationPatternIdentifiersStatics>
{
    IAnnotationPatternIdentifiersStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IAutomationAnnotation :
    Windows::Foundation::IInspectable,
    impl::consume<IAutomationAnnotation>
{
    IAutomationAnnotation(std::nullptr_t = nullptr) noexcept {}
};

struct IAutomationAnnotationFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IAutomationAnnotationFactory>
{
    IAutomationAnnotationFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IAutomationAnnotationStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IAutomationAnnotationStatics>
{
    IAutomationAnnotationStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IAutomationElementIdentifiers :
    Windows::Foundation::IInspectable,
    impl::consume<IAutomationElementIdentifiers>
{
    IAutomationElementIdentifiers(std::nullptr_t = nullptr) noexcept {}
};

struct IAutomationElementIdentifiersStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IAutomationElementIdentifiersStatics>
{
    IAutomationElementIdentifiersStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IAutomationElementIdentifiersStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IAutomationElementIdentifiersStatics2>
{
    IAutomationElementIdentifiersStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct IAutomationElementIdentifiersStatics3 :
    Windows::Foundation::IInspectable,
    impl::consume<IAutomationElementIdentifiersStatics3>
{
    IAutomationElementIdentifiersStatics3(std::nullptr_t = nullptr) noexcept {}
};

struct IAutomationElementIdentifiersStatics4 :
    Windows::Foundation::IInspectable,
    impl::consume<IAutomationElementIdentifiersStatics4>
{
    IAutomationElementIdentifiersStatics4(std::nullptr_t = nullptr) noexcept {}
};

struct IAutomationElementIdentifiersStatics5 :
    Windows::Foundation::IInspectable,
    impl::consume<IAutomationElementIdentifiersStatics5>
{
    IAutomationElementIdentifiersStatics5(std::nullptr_t = nullptr) noexcept {}
};

struct IAutomationProperties :
    Windows::Foundation::IInspectable,
    impl::consume<IAutomationProperties>
{
    IAutomationProperties(std::nullptr_t = nullptr) noexcept {}
};

struct IAutomationPropertiesStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IAutomationPropertiesStatics>
{
    IAutomationPropertiesStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IAutomationPropertiesStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IAutomationPropertiesStatics2>
{
    IAutomationPropertiesStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct IAutomationPropertiesStatics3 :
    Windows::Foundation::IInspectable,
    impl::consume<IAutomationPropertiesStatics3>
{
    IAutomationPropertiesStatics3(std::nullptr_t = nullptr) noexcept {}
};

struct IAutomationPropertiesStatics4 :
    Windows::Foundation::IInspectable,
    impl::consume<IAutomationPropertiesStatics4>
{
    IAutomationPropertiesStatics4(std::nullptr_t = nullptr) noexcept {}
};

struct IAutomationPropertiesStatics5 :
    Windows::Foundation::IInspectable,
    impl::consume<IAutomationPropertiesStatics5>
{
    IAutomationPropertiesStatics5(std::nullptr_t = nullptr) noexcept {}
};

struct IAutomationProperty :
    Windows::Foundation::IInspectable,
    impl::consume<IAutomationProperty>
{
    IAutomationProperty(std::nullptr_t = nullptr) noexcept {}
};

struct IDockPatternIdentifiers :
    Windows::Foundation::IInspectable,
    impl::consume<IDockPatternIdentifiers>
{
    IDockPatternIdentifiers(std::nullptr_t = nullptr) noexcept {}
};

struct IDockPatternIdentifiersStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IDockPatternIdentifiersStatics>
{
    IDockPatternIdentifiersStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IDragPatternIdentifiers :
    Windows::Foundation::IInspectable,
    impl::consume<IDragPatternIdentifiers>
{
    IDragPatternIdentifiers(std::nullptr_t = nullptr) noexcept {}
};

struct IDragPatternIdentifiersStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IDragPatternIdentifiersStatics>
{
    IDragPatternIdentifiersStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IDropTargetPatternIdentifiers :
    Windows::Foundation::IInspectable,
    impl::consume<IDropTargetPatternIdentifiers>
{
    IDropTargetPatternIdentifiers(std::nullptr_t = nullptr) noexcept {}
};

struct IDropTargetPatternIdentifiersStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IDropTargetPatternIdentifiersStatics>
{
    IDropTargetPatternIdentifiersStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IExpandCollapsePatternIdentifiers :
    Windows::Foundation::IInspectable,
    impl::consume<IExpandCollapsePatternIdentifiers>
{
    IExpandCollapsePatternIdentifiers(std::nullptr_t = nullptr) noexcept {}
};

struct IExpandCollapsePatternIdentifiersStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IExpandCollapsePatternIdentifiersStatics>
{
    IExpandCollapsePatternIdentifiersStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IGridItemPatternIdentifiers :
    Windows::Foundation::IInspectable,
    impl::consume<IGridItemPatternIdentifiers>
{
    IGridItemPatternIdentifiers(std::nullptr_t = nullptr) noexcept {}
};

struct IGridItemPatternIdentifiersStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IGridItemPatternIdentifiersStatics>
{
    IGridItemPatternIdentifiersStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IGridPatternIdentifiers :
    Windows::Foundation::IInspectable,
    impl::consume<IGridPatternIdentifiers>
{
    IGridPatternIdentifiers(std::nullptr_t = nullptr) noexcept {}
};

struct IGridPatternIdentifiersStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IGridPatternIdentifiersStatics>
{
    IGridPatternIdentifiersStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IMultipleViewPatternIdentifiers :
    Windows::Foundation::IInspectable,
    impl::consume<IMultipleViewPatternIdentifiers>
{
    IMultipleViewPatternIdentifiers(std::nullptr_t = nullptr) noexcept {}
};

struct IMultipleViewPatternIdentifiersStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IMultipleViewPatternIdentifiersStatics>
{
    IMultipleViewPatternIdentifiersStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IRangeValuePatternIdentifiers :
    Windows::Foundation::IInspectable,
    impl::consume<IRangeValuePatternIdentifiers>
{
    IRangeValuePatternIdentifiers(std::nullptr_t = nullptr) noexcept {}
};

struct IRangeValuePatternIdentifiersStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IRangeValuePatternIdentifiersStatics>
{
    IRangeValuePatternIdentifiersStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IScrollPatternIdentifiers :
    Windows::Foundation::IInspectable,
    impl::consume<IScrollPatternIdentifiers>
{
    IScrollPatternIdentifiers(std::nullptr_t = nullptr) noexcept {}
};

struct IScrollPatternIdentifiersStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IScrollPatternIdentifiersStatics>
{
    IScrollPatternIdentifiersStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ISelectionItemPatternIdentifiers :
    Windows::Foundation::IInspectable,
    impl::consume<ISelectionItemPatternIdentifiers>
{
    ISelectionItemPatternIdentifiers(std::nullptr_t = nullptr) noexcept {}
};

struct ISelectionItemPatternIdentifiersStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ISelectionItemPatternIdentifiersStatics>
{
    ISelectionItemPatternIdentifiersStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ISelectionPatternIdentifiers :
    Windows::Foundation::IInspectable,
    impl::consume<ISelectionPatternIdentifiers>
{
    ISelectionPatternIdentifiers(std::nullptr_t = nullptr) noexcept {}
};

struct ISelectionPatternIdentifiersStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ISelectionPatternIdentifiersStatics>
{
    ISelectionPatternIdentifiersStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ISpreadsheetItemPatternIdentifiers :
    Windows::Foundation::IInspectable,
    impl::consume<ISpreadsheetItemPatternIdentifiers>
{
    ISpreadsheetItemPatternIdentifiers(std::nullptr_t = nullptr) noexcept {}
};

struct ISpreadsheetItemPatternIdentifiersStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ISpreadsheetItemPatternIdentifiersStatics>
{
    ISpreadsheetItemPatternIdentifiersStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IStylesPatternIdentifiers :
    Windows::Foundation::IInspectable,
    impl::consume<IStylesPatternIdentifiers>
{
    IStylesPatternIdentifiers(std::nullptr_t = nullptr) noexcept {}
};

struct IStylesPatternIdentifiersStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IStylesPatternIdentifiersStatics>
{
    IStylesPatternIdentifiersStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ITableItemPatternIdentifiers :
    Windows::Foundation::IInspectable,
    impl::consume<ITableItemPatternIdentifiers>
{
    ITableItemPatternIdentifiers(std::nullptr_t = nullptr) noexcept {}
};

struct ITableItemPatternIdentifiersStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ITableItemPatternIdentifiersStatics>
{
    ITableItemPatternIdentifiersStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ITablePatternIdentifiers :
    Windows::Foundation::IInspectable,
    impl::consume<ITablePatternIdentifiers>
{
    ITablePatternIdentifiers(std::nullptr_t = nullptr) noexcept {}
};

struct ITablePatternIdentifiersStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ITablePatternIdentifiersStatics>
{
    ITablePatternIdentifiersStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ITogglePatternIdentifiers :
    Windows::Foundation::IInspectable,
    impl::consume<ITogglePatternIdentifiers>
{
    ITogglePatternIdentifiers(std::nullptr_t = nullptr) noexcept {}
};

struct ITogglePatternIdentifiersStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ITogglePatternIdentifiersStatics>
{
    ITogglePatternIdentifiersStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ITransformPattern2Identifiers :
    Windows::Foundation::IInspectable,
    impl::consume<ITransformPattern2Identifiers>
{
    ITransformPattern2Identifiers(std::nullptr_t = nullptr) noexcept {}
};

struct ITransformPattern2IdentifiersStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ITransformPattern2IdentifiersStatics>
{
    ITransformPattern2IdentifiersStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ITransformPatternIdentifiers :
    Windows::Foundation::IInspectable,
    impl::consume<ITransformPatternIdentifiers>
{
    ITransformPatternIdentifiers(std::nullptr_t = nullptr) noexcept {}
};

struct ITransformPatternIdentifiersStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ITransformPatternIdentifiersStatics>
{
    ITransformPatternIdentifiersStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IValuePatternIdentifiers :
    Windows::Foundation::IInspectable,
    impl::consume<IValuePatternIdentifiers>
{
    IValuePatternIdentifiers(std::nullptr_t = nullptr) noexcept {}
};

struct IValuePatternIdentifiersStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IValuePatternIdentifiersStatics>
{
    IValuePatternIdentifiersStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IWindowPatternIdentifiers :
    Windows::Foundation::IInspectable,
    impl::consume<IWindowPatternIdentifiers>
{
    IWindowPatternIdentifiers(std::nullptr_t = nullptr) noexcept {}
};

struct IWindowPatternIdentifiersStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IWindowPatternIdentifiersStatics>
{
    IWindowPatternIdentifiersStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
