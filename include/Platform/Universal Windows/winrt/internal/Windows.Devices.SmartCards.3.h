// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.SmartCards.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::SmartCards {

template <typename H> struct impl_SmartCardPinResetHandler : implements<impl_SmartCardPinResetHandler<H>, abi<SmartCardPinResetHandler>>, H
{
    impl_SmartCardPinResetHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Devices::SmartCards::ISmartCardProvisioning> sender, impl::abi_arg_in<Windows::Devices::SmartCards::ISmartCardPinResetRequest> request) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Devices::SmartCards::SmartCardProvisioning *>(&sender), *reinterpret_cast<const Windows::Devices::SmartCards::SmartCardPinResetRequest *>(&request));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Devices::SmartCards {

struct WINRT_EBO CardAddedEventArgs :
    Windows::Devices::SmartCards::ICardAddedEventArgs
{
    CardAddedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CardRemovedEventArgs :
    Windows::Devices::SmartCards::ICardRemovedEventArgs
{
    CardRemovedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SmartCard :
    Windows::Devices::SmartCards::ISmartCard,
    impl::require<SmartCard, Windows::Devices::SmartCards::ISmartCardConnect>
{
    SmartCard(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SmartCardAppletIdGroup :
    Windows::Devices::SmartCards::ISmartCardAppletIdGroup
{
    SmartCardAppletIdGroup(std::nullptr_t) noexcept {}
    SmartCardAppletIdGroup();
    SmartCardAppletIdGroup(hstring_view displayName, const Windows::Foundation::Collections::IVector<Windows::Storage::Streams::IBuffer> & appletIds, Windows::Devices::SmartCards::SmartCardEmulationCategory emulationCategory, Windows::Devices::SmartCards::SmartCardEmulationType emulationType);
    static uint16_t MaxAppletIds();
};

struct WINRT_EBO SmartCardAppletIdGroupRegistration :
    Windows::Devices::SmartCards::ISmartCardAppletIdGroupRegistration
{
    SmartCardAppletIdGroupRegistration(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SmartCardAutomaticResponseApdu :
    Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu,
    impl::require<SmartCardAutomaticResponseApdu, Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu2, Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu3>
{
    SmartCardAutomaticResponseApdu(std::nullptr_t) noexcept {}
    SmartCardAutomaticResponseApdu(const Windows::Storage::Streams::IBuffer & commandApdu, const Windows::Storage::Streams::IBuffer & responseApdu);
};

struct WINRT_EBO SmartCardChallengeContext :
    Windows::Devices::SmartCards::ISmartCardChallengeContext
{
    SmartCardChallengeContext(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SmartCardConnection :
    Windows::Devices::SmartCards::ISmartCardConnection
{
    SmartCardConnection(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SmartCardCryptogramGenerator :
    Windows::Devices::SmartCards::ISmartCardCryptogramGenerator
{
    SmartCardCryptogramGenerator(std::nullptr_t) noexcept {}
    static Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardCryptogramGenerator> GetSmartCardCryptogramGeneratorAsync();
};

struct WINRT_EBO SmartCardCryptogramMaterialPossessionProof :
    Windows::Devices::SmartCards::ISmartCardCryptogramMaterialPossessionProof
{
    SmartCardCryptogramMaterialPossessionProof(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SmartCardCryptogramPlacementStep :
    Windows::Devices::SmartCards::ISmartCardCryptogramPlacementStep
{
    SmartCardCryptogramPlacementStep(std::nullptr_t) noexcept {}
    SmartCardCryptogramPlacementStep();
};

struct WINRT_EBO SmartCardCryptogramStorageKeyInfo :
    Windows::Devices::SmartCards::ISmartCardCryptogramStorageKeyInfo,
    impl::require<SmartCardCryptogramStorageKeyInfo, Windows::Devices::SmartCards::ISmartCardCryptogramStorageKeyInfo2>
{
    SmartCardCryptogramStorageKeyInfo(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SmartCardEmulator :
    Windows::Devices::SmartCards::ISmartCardEmulator,
    impl::require<SmartCardEmulator, Windows::Devices::SmartCards::ISmartCardEmulator2>
{
    SmartCardEmulator(std::nullptr_t) noexcept {}
    static Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardEmulator> GetDefaultAsync();
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration>> GetAppletIdGroupRegistrationsAsync();
    static Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration> RegisterAppletIdGroupAsync(const Windows::Devices::SmartCards::SmartCardAppletIdGroup & appletIdGroup);
    static Windows::Foundation::IAsyncAction UnregisterAppletIdGroupAsync(const Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration & registration);
    static uint16_t MaxAppletIdGroupRegistrations();
};

struct WINRT_EBO SmartCardEmulatorApduReceivedEventArgs :
    Windows::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgs,
    impl::require<SmartCardEmulatorApduReceivedEventArgs, Windows::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgs2, Windows::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgsWithCryptograms>
{
    SmartCardEmulatorApduReceivedEventArgs(std::nullptr_t) noexcept {}
    using impl_ISmartCardEmulatorApduReceivedEventArgs::TryRespondAsync;
    using impl_ISmartCardEmulatorApduReceivedEventArgs2::TryRespondAsync;
};

struct WINRT_EBO SmartCardEmulatorConnectionDeactivatedEventArgs :
    Windows::Devices::SmartCards::ISmartCardEmulatorConnectionDeactivatedEventArgs
{
    SmartCardEmulatorConnectionDeactivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SmartCardEmulatorConnectionProperties :
    Windows::Devices::SmartCards::ISmartCardEmulatorConnectionProperties
{
    SmartCardEmulatorConnectionProperties(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SmartCardPinPolicy :
    Windows::Devices::SmartCards::ISmartCardPinPolicy
{
    SmartCardPinPolicy(std::nullptr_t) noexcept {}
    SmartCardPinPolicy();
};

struct WINRT_EBO SmartCardPinResetDeferral :
    Windows::Devices::SmartCards::ISmartCardPinResetDeferral
{
    SmartCardPinResetDeferral(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SmartCardPinResetRequest :
    Windows::Devices::SmartCards::ISmartCardPinResetRequest
{
    SmartCardPinResetRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SmartCardProvisioning :
    Windows::Devices::SmartCards::ISmartCardProvisioning,
    impl::require<SmartCardProvisioning, Windows::Devices::SmartCards::ISmartCardProvisioning2>
{
    SmartCardProvisioning(std::nullptr_t) noexcept {}
    static Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> FromSmartCardAsync(const Windows::Devices::SmartCards::SmartCard & card);
    static Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> RequestVirtualSmartCardCreationAsync(hstring_view friendlyName, const Windows::Storage::Streams::IBuffer & administrativeKey, const Windows::Devices::SmartCards::SmartCardPinPolicy & pinPolicy);
    static Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> RequestVirtualSmartCardCreationAsync(hstring_view friendlyName, const Windows::Storage::Streams::IBuffer & administrativeKey, const Windows::Devices::SmartCards::SmartCardPinPolicy & pinPolicy, GUID cardId);
    static Windows::Foundation::IAsyncOperation<bool> RequestVirtualSmartCardDeletionAsync(const Windows::Devices::SmartCards::SmartCard & card);
    static Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> RequestAttestedVirtualSmartCardCreationAsync(hstring_view friendlyName, const Windows::Storage::Streams::IBuffer & administrativeKey, const Windows::Devices::SmartCards::SmartCardPinPolicy & pinPolicy);
    static Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> RequestAttestedVirtualSmartCardCreationAsync(hstring_view friendlyName, const Windows::Storage::Streams::IBuffer & administrativeKey, const Windows::Devices::SmartCards::SmartCardPinPolicy & pinPolicy, GUID cardId);
};

struct WINRT_EBO SmartCardReader :
    Windows::Devices::SmartCards::ISmartCardReader
{
    SmartCardReader(std::nullptr_t) noexcept {}
    static hstring GetDeviceSelector();
    static hstring GetDeviceSelector(Windows::Devices::SmartCards::SmartCardReaderKind kind);
    static Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardReader> FromIdAsync(hstring_view deviceId);
};

struct WINRT_EBO SmartCardTriggerDetails :
    Windows::Devices::SmartCards::ISmartCardTriggerDetails,
    impl::require<SmartCardTriggerDetails, Windows::Devices::SmartCards::ISmartCardTriggerDetails2>
{
    SmartCardTriggerDetails(std::nullptr_t) noexcept {}
};

}

}
