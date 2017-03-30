// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.Store.Preview.InstallControl.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::Store::Preview::InstallControl {

struct WINRT_EBO AppInstallItem :
    Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem,
    impl::require<AppInstallItem, Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem2>
{
    AppInstallItem(std::nullptr_t) noexcept {}
    using impl_IAppInstallItem::Cancel;
    using impl_IAppInstallItem::Pause;
    using impl_IAppInstallItem::Restart;
    using impl_IAppInstallItem2::Cancel;
    using impl_IAppInstallItem2::Pause;
    using impl_IAppInstallItem2::Restart;
};

struct WINRT_EBO AppInstallManager :
    Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager,
    impl::require<AppInstallManager, Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager2, Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager3>
{
    AppInstallManager(std::nullptr_t) noexcept {}
    AppInstallManager();
    using impl_IAppInstallManager::Cancel;
    using impl_IAppInstallManager::GetIsAppAllowedToInstallAsync;
    using impl_IAppInstallManager::Pause;
    using impl_IAppInstallManager::Restart;
    using impl_IAppInstallManager::SearchForAllUpdatesAsync;
    using impl_IAppInstallManager::SearchForUpdatesAsync;
    using impl_IAppInstallManager::StartAppInstallAsync;
    using impl_IAppInstallManager::UpdateAppByPackageFamilyNameAsync;
    using impl_IAppInstallManager2::Cancel;
    using impl_IAppInstallManager2::GetIsAppAllowedToInstallAsync;
    using impl_IAppInstallManager2::Pause;
    using impl_IAppInstallManager2::Restart;
    using impl_IAppInstallManager2::SearchForAllUpdatesAsync;
    using impl_IAppInstallManager2::SearchForUpdatesAsync;
    using impl_IAppInstallManager2::StartAppInstallAsync;
    using impl_IAppInstallManager2::UpdateAppByPackageFamilyNameAsync;
};

struct WINRT_EBO AppInstallManagerItemEventArgs :
    Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManagerItemEventArgs
{
    AppInstallManagerItemEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AppInstallStatus :
    Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallStatus,
    impl::require<AppInstallStatus, Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallStatus2>
{
    AppInstallStatus(std::nullptr_t) noexcept {}
};

}

}
