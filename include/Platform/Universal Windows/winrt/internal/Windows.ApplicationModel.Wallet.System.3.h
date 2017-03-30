// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.Wallet.System.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::Wallet::System {

struct WINRT_EBO WalletItemSystemStore :
    Windows::ApplicationModel::Wallet::System::IWalletItemSystemStore,
    impl::require<WalletItemSystemStore, Windows::ApplicationModel::Wallet::System::IWalletItemSystemStore2>
{
    WalletItemSystemStore(std::nullptr_t) noexcept {}
};

struct WalletManagerSystem
{
    WalletManagerSystem() = delete;
    static Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::System::WalletItemSystemStore> RequestStoreAsync();
};

}

}
