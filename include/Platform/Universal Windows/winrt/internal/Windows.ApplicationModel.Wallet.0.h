// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::Wallet {

struct IWalletBarcode;
struct IWalletBarcodeFactory;
struct IWalletItem;
struct IWalletItemCustomProperty;
struct IWalletItemCustomPropertyFactory;
struct IWalletItemFactory;
struct IWalletItemStore;
struct IWalletItemStore2;
struct IWalletManagerStatics;
struct IWalletRelevantLocation;
struct IWalletTransaction;
struct IWalletVerb;
struct IWalletVerbFactory;
struct WalletBarcode;
struct WalletItem;
struct WalletItemCustomProperty;
struct WalletItemStore;
struct WalletRelevantLocation;
struct WalletTransaction;
struct WalletVerb;

}

namespace Windows::ApplicationModel::Wallet {

struct IWalletBarcode;
struct IWalletBarcodeFactory;
struct IWalletItem;
struct IWalletItemCustomProperty;
struct IWalletItemCustomPropertyFactory;
struct IWalletItemFactory;
struct IWalletItemStore;
struct IWalletItemStore2;
struct IWalletManagerStatics;
struct IWalletRelevantLocation;
struct IWalletTransaction;
struct IWalletVerb;
struct IWalletVerbFactory;
struct WalletBarcode;
struct WalletItem;
struct WalletItemCustomProperty;
struct WalletItemStore;
struct WalletManager;
struct WalletRelevantLocation;
struct WalletTransaction;
struct WalletVerb;

}

namespace Windows::ApplicationModel::Wallet {

template <typename T> struct impl_IWalletBarcode;
template <typename T> struct impl_IWalletBarcodeFactory;
template <typename T> struct impl_IWalletItem;
template <typename T> struct impl_IWalletItemCustomProperty;
template <typename T> struct impl_IWalletItemCustomPropertyFactory;
template <typename T> struct impl_IWalletItemFactory;
template <typename T> struct impl_IWalletItemStore;
template <typename T> struct impl_IWalletItemStore2;
template <typename T> struct impl_IWalletManagerStatics;
template <typename T> struct impl_IWalletRelevantLocation;
template <typename T> struct impl_IWalletTransaction;
template <typename T> struct impl_IWalletVerb;
template <typename T> struct impl_IWalletVerbFactory;

}

namespace Windows::ApplicationModel::Wallet {

enum class WalletActionKind
{
    OpenItem = 0,
    Transaction = 1,
    MoreTransactions = 2,
    Message = 3,
    Verb = 4,
};

enum class WalletBarcodeSymbology
{
    Invalid = 0,
    Upca = 1,
    Upce = 2,
    Ean13 = 3,
    Ean8 = 4,
    Itf = 5,
    Code39 = 6,
    Code128 = 7,
    Qr = 8,
    Pdf417 = 9,
    Aztec = 10,
    Custom = 100000,
};

enum class WalletDetailViewPosition
{
    Hidden = 0,
    HeaderField1 = 1,
    HeaderField2 = 2,
    PrimaryField1 = 3,
    PrimaryField2 = 4,
    SecondaryField1 = 5,
    SecondaryField2 = 6,
    SecondaryField3 = 7,
    SecondaryField4 = 8,
    SecondaryField5 = 9,
    CenterField1 = 10,
    FooterField1 = 11,
    FooterField2 = 12,
    FooterField3 = 13,
    FooterField4 = 14,
};

enum class WalletItemKind
{
    Invalid = 0,
    Deal = 1,
    General = 2,
    PaymentInstrument = 3,
    Ticket = 4,
    BoardingPass = 5,
    MembershipCard = 6,
};

enum class WalletSummaryViewPosition
{
    Hidden = 0,
    Field1 = 1,
    Field2 = 2,
};

}

}
