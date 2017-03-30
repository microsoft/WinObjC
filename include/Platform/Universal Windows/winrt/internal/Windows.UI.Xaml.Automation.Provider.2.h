// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Automation.Provider.1.h"
#include "Windows.UI.Xaml.1.h"
#include "Windows.UI.Xaml.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Automation::Provider {

struct IAnnotationProvider :
    Windows::Foundation::IInspectable,
    impl::consume<IAnnotationProvider>
{
    IAnnotationProvider(std::nullptr_t = nullptr) noexcept {}
};

struct ICustomNavigationProvider :
    Windows::Foundation::IInspectable,
    impl::consume<ICustomNavigationProvider>
{
    ICustomNavigationProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IDockProvider :
    Windows::Foundation::IInspectable,
    impl::consume<IDockProvider>
{
    IDockProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IDragProvider :
    Windows::Foundation::IInspectable,
    impl::consume<IDragProvider>
{
    IDragProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IDropTargetProvider :
    Windows::Foundation::IInspectable,
    impl::consume<IDropTargetProvider>
{
    IDropTargetProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IExpandCollapseProvider :
    Windows::Foundation::IInspectable,
    impl::consume<IExpandCollapseProvider>
{
    IExpandCollapseProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IGridItemProvider :
    Windows::Foundation::IInspectable,
    impl::consume<IGridItemProvider>
{
    IGridItemProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IGridProvider :
    Windows::Foundation::IInspectable,
    impl::consume<IGridProvider>
{
    IGridProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IIRawElementProviderSimple :
    Windows::Foundation::IInspectable,
    impl::consume<IIRawElementProviderSimple>
{
    IIRawElementProviderSimple(std::nullptr_t = nullptr) noexcept {}
};

struct IInvokeProvider :
    Windows::Foundation::IInspectable,
    impl::consume<IInvokeProvider>
{
    IInvokeProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IItemContainerProvider :
    Windows::Foundation::IInspectable,
    impl::consume<IItemContainerProvider>
{
    IItemContainerProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IMultipleViewProvider :
    Windows::Foundation::IInspectable,
    impl::consume<IMultipleViewProvider>
{
    IMultipleViewProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IObjectModelProvider :
    Windows::Foundation::IInspectable,
    impl::consume<IObjectModelProvider>
{
    IObjectModelProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IRangeValueProvider :
    Windows::Foundation::IInspectable,
    impl::consume<IRangeValueProvider>
{
    IRangeValueProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IScrollItemProvider :
    Windows::Foundation::IInspectable,
    impl::consume<IScrollItemProvider>
{
    IScrollItemProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IScrollProvider :
    Windows::Foundation::IInspectable,
    impl::consume<IScrollProvider>
{
    IScrollProvider(std::nullptr_t = nullptr) noexcept {}
};

struct ISelectionItemProvider :
    Windows::Foundation::IInspectable,
    impl::consume<ISelectionItemProvider>
{
    ISelectionItemProvider(std::nullptr_t = nullptr) noexcept {}
};

struct ISelectionProvider :
    Windows::Foundation::IInspectable,
    impl::consume<ISelectionProvider>
{
    ISelectionProvider(std::nullptr_t = nullptr) noexcept {}
};

struct ISpreadsheetItemProvider :
    Windows::Foundation::IInspectable,
    impl::consume<ISpreadsheetItemProvider>
{
    ISpreadsheetItemProvider(std::nullptr_t = nullptr) noexcept {}
};

struct ISpreadsheetProvider :
    Windows::Foundation::IInspectable,
    impl::consume<ISpreadsheetProvider>
{
    ISpreadsheetProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IStylesProvider :
    Windows::Foundation::IInspectable,
    impl::consume<IStylesProvider>
{
    IStylesProvider(std::nullptr_t = nullptr) noexcept {}
};

struct ISynchronizedInputProvider :
    Windows::Foundation::IInspectable,
    impl::consume<ISynchronizedInputProvider>
{
    ISynchronizedInputProvider(std::nullptr_t = nullptr) noexcept {}
};

struct ITableItemProvider :
    Windows::Foundation::IInspectable,
    impl::consume<ITableItemProvider>
{
    ITableItemProvider(std::nullptr_t = nullptr) noexcept {}
};

struct ITableProvider :
    Windows::Foundation::IInspectable,
    impl::consume<ITableProvider>
{
    ITableProvider(std::nullptr_t = nullptr) noexcept {}
};

struct ITextChildProvider :
    Windows::Foundation::IInspectable,
    impl::consume<ITextChildProvider>
{
    ITextChildProvider(std::nullptr_t = nullptr) noexcept {}
};

struct ITextEditProvider :
    Windows::Foundation::IInspectable,
    impl::consume<ITextEditProvider>,
    impl::require<ITextEditProvider, Windows::UI::Xaml::Automation::Provider::ITextProvider>
{
    ITextEditProvider(std::nullptr_t = nullptr) noexcept {}
};

struct ITextProvider :
    Windows::Foundation::IInspectable,
    impl::consume<ITextProvider>
{
    ITextProvider(std::nullptr_t = nullptr) noexcept {}
};

struct ITextProvider2 :
    Windows::Foundation::IInspectable,
    impl::consume<ITextProvider2>,
    impl::require<ITextProvider2, Windows::UI::Xaml::Automation::Provider::ITextProvider>
{
    ITextProvider2(std::nullptr_t = nullptr) noexcept {}
};

struct ITextRangeProvider :
    Windows::Foundation::IInspectable,
    impl::consume<ITextRangeProvider>
{
    ITextRangeProvider(std::nullptr_t = nullptr) noexcept {}
};

struct ITextRangeProvider2 :
    Windows::Foundation::IInspectable,
    impl::consume<ITextRangeProvider2>,
    impl::require<ITextRangeProvider2, Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>
{
    ITextRangeProvider2(std::nullptr_t = nullptr) noexcept {}
};

struct IToggleProvider :
    Windows::Foundation::IInspectable,
    impl::consume<IToggleProvider>
{
    IToggleProvider(std::nullptr_t = nullptr) noexcept {}
};

struct ITransformProvider :
    Windows::Foundation::IInspectable,
    impl::consume<ITransformProvider>
{
    ITransformProvider(std::nullptr_t = nullptr) noexcept {}
};

struct ITransformProvider2 :
    Windows::Foundation::IInspectable,
    impl::consume<ITransformProvider2>,
    impl::require<ITransformProvider2, Windows::UI::Xaml::Automation::Provider::ITransformProvider>
{
    ITransformProvider2(std::nullptr_t = nullptr) noexcept {}
};

struct IValueProvider :
    Windows::Foundation::IInspectable,
    impl::consume<IValueProvider>
{
    IValueProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IVirtualizedItemProvider :
    Windows::Foundation::IInspectable,
    impl::consume<IVirtualizedItemProvider>
{
    IVirtualizedItemProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IWindowProvider :
    Windows::Foundation::IInspectable,
    impl::consume<IWindowProvider>
{
    IWindowProvider(std::nullptr_t = nullptr) noexcept {}
};

}

}
