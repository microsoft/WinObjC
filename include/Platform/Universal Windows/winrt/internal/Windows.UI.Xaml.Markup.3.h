// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Markup.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Markup {

struct WINRT_EBO XamlBinaryWriter :
    Windows::UI::Xaml::Markup::IXamlBinaryWriter
{
    XamlBinaryWriter(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::Markup::XamlBinaryWriterErrorInformation Write(const Windows::Foundation::Collections::IVector<Windows::Storage::Streams::IRandomAccessStream> & inputStreams, const Windows::Foundation::Collections::IVector<Windows::Storage::Streams::IRandomAccessStream> & outputStreams, const Windows::UI::Xaml::Markup::IXamlMetadataProvider & xamlMetadataProvider);
};

struct WINRT_EBO XamlBindingHelper :
    Windows::UI::Xaml::Markup::IXamlBindingHelper
{
    XamlBindingHelper(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::DependencyProperty DataTemplateComponentProperty();
    static Windows::UI::Xaml::Markup::IDataTemplateComponent GetDataTemplateComponent(const Windows::UI::Xaml::DependencyObject & element);
    static void SetDataTemplateComponent(const Windows::UI::Xaml::DependencyObject & element, const Windows::UI::Xaml::Markup::IDataTemplateComponent & value);
    static void SuspendRendering(const Windows::UI::Xaml::UIElement & target);
    static void ResumeRendering(const Windows::UI::Xaml::UIElement & target);
    static Windows::Foundation::IInspectable ConvertValue(const Windows::UI::Xaml::Interop::TypeName & type, const Windows::Foundation::IInspectable & value);
    static void SetPropertyFromString(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, hstring_view value);
    static void SetPropertyFromBoolean(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, bool value);
    static void SetPropertyFromChar16(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, wchar_t value);
    static void SetPropertyFromDateTime(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, const Windows::Foundation::DateTime & value);
    static void SetPropertyFromDouble(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, double value);
    static void SetPropertyFromInt32(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, int32_t value);
    static void SetPropertyFromUInt32(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, uint32_t value);
    static void SetPropertyFromInt64(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, int64_t value);
    static void SetPropertyFromUInt64(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, uint64_t value);
    static void SetPropertyFromSingle(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, float value);
    static void SetPropertyFromPoint(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, const Windows::Foundation::Point & value);
    static void SetPropertyFromRect(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, const Windows::Foundation::Rect & value);
    static void SetPropertyFromSize(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, const Windows::Foundation::Size & value);
    static void SetPropertyFromTimeSpan(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, const Windows::Foundation::TimeSpan & value);
    static void SetPropertyFromByte(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, uint8_t value);
    static void SetPropertyFromUri(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, const Windows::Foundation::Uri & value);
    static void SetPropertyFromObject(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, const Windows::Foundation::IInspectable & value);
};

struct WINRT_EBO XamlReader :
    Windows::UI::Xaml::Markup::IXamlReader
{
    XamlReader(std::nullptr_t) noexcept {}
    static Windows::Foundation::IInspectable Load(hstring_view xaml);
    static Windows::Foundation::IInspectable LoadWithInitialTemplateValidation(hstring_view xaml);
};

}

}
