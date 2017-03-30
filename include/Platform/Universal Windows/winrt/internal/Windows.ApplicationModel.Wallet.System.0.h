// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::Wallet::System {

struct IWalletItemSystemStore;
struct IWalletItemSystemStore2;
struct IWalletManagerSystemStatics;
struct WalletItemSystemStore;

}

namespace Windows::ApplicationModel::Wallet::System {

struct IWalletItemSystemStore;
struct IWalletItemSystemStore2;
struct IWalletManagerSystemStatics;
struct WalletItemSystemStore;
struct WalletManagerSystem;

}

namespace Windows::ApplicationModel::Wallet::System {

template <typename T> struct impl_IWalletItemSystemStore;
template <typename T> struct impl_IWalletItemSystemStore2;
template <typename T> struct impl_IWalletManagerSystemStatics;

}

namespace Windows::ApplicationModel::Wallet::System {

enum class WalletItemAppAssociation
{
    None = 0,
    AppInstalled = 1,
    AppNotInstalled = 2,
};

}

}
