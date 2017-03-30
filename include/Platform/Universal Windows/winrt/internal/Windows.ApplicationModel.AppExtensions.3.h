// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.AppExtensions.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::AppExtensions {

struct WINRT_EBO AppExtension :
    Windows::ApplicationModel::AppExtensions::IAppExtension
{
    AppExtension(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AppExtensionCatalog :
    Windows::ApplicationModel::AppExtensions::IAppExtensionCatalog
{
    AppExtensionCatalog(std::nullptr_t) noexcept {}
    static Windows::ApplicationModel::AppExtensions::AppExtensionCatalog Open(hstring_view appExtensionName);
};

struct WINRT_EBO AppExtensionPackageInstalledEventArgs :
    Windows::ApplicationModel::AppExtensions::IAppExtensionPackageInstalledEventArgs
{
    AppExtensionPackageInstalledEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AppExtensionPackageStatusChangedEventArgs :
    Windows::ApplicationModel::AppExtensions::IAppExtensionPackageStatusChangedEventArgs
{
    AppExtensionPackageStatusChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AppExtensionPackageUninstallingEventArgs :
    Windows::ApplicationModel::AppExtensions::IAppExtensionPackageUninstallingEventArgs
{
    AppExtensionPackageUninstallingEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AppExtensionPackageUpdatedEventArgs :
    Windows::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatedEventArgs
{
    AppExtensionPackageUpdatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AppExtensionPackageUpdatingEventArgs :
    Windows::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatingEventArgs
{
    AppExtensionPackageUpdatingEventArgs(std::nullptr_t) noexcept {}
};

}

}
