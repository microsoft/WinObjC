// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Devices.SmartCards.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Security.Cryptography.Core.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Storage.Streams.1.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::SmartCards {

struct __declspec(uuid("18bbef98-f18b-4dd3-b118-dfb2c8e23cc6")) __declspec(novtable) ICardAddedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SmartCard(Windows::Devices::SmartCards::ISmartCard ** value) = 0;
};

struct __declspec(uuid("15331aaf-22d7-4945-afc9-03b46f42a6cd")) __declspec(novtable) ICardRemovedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SmartCard(Windows::Devices::SmartCards::ISmartCard ** value) = 0;
};

struct __declspec(uuid("1b718871-6434-43f4-b55a-6a29623870aa")) __declspec(novtable) ISmartCard : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Reader(Windows::Devices::SmartCards::ISmartCardReader ** value) = 0;
    virtual HRESULT __stdcall abi_GetStatusAsync(Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardStatus> ** result) = 0;
    virtual HRESULT __stdcall abi_GetAnswerToResetAsync(Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> ** result) = 0;
};

struct __declspec(uuid("7db165e6-6264-56f4-5e03-c86385395eb1")) __declspec(novtable) ISmartCardAppletIdGroup : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall put_DisplayName(hstring value) = 0;
    virtual HRESULT __stdcall get_AppletIds(Windows::Foundation::Collections::IVector<Windows::Storage::Streams::IBuffer> ** value) = 0;
    virtual HRESULT __stdcall get_SmartCardEmulationCategory(winrt::Windows::Devices::SmartCards::SmartCardEmulationCategory * value) = 0;
    virtual HRESULT __stdcall put_SmartCardEmulationCategory(winrt::Windows::Devices::SmartCards::SmartCardEmulationCategory value) = 0;
    virtual HRESULT __stdcall get_SmartCardEmulationType(winrt::Windows::Devices::SmartCards::SmartCardEmulationType * value) = 0;
    virtual HRESULT __stdcall put_SmartCardEmulationType(winrt::Windows::Devices::SmartCards::SmartCardEmulationType value) = 0;
    virtual HRESULT __stdcall get_AutomaticEnablement(bool * value) = 0;
    virtual HRESULT __stdcall put_AutomaticEnablement(bool value) = 0;
};

struct __declspec(uuid("9105eb4d-4a65-4e41-8061-cbe83f3695e5")) __declspec(novtable) ISmartCardAppletIdGroupFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(hstring displayName, Windows::Foundation::Collections::IVector<Windows::Storage::Streams::IBuffer> * appletIds, winrt::Windows::Devices::SmartCards::SmartCardEmulationCategory emulationCategory, winrt::Windows::Devices::SmartCards::SmartCardEmulationType emulationType, Windows::Devices::SmartCards::ISmartCardAppletIdGroup ** result) = 0;
};

struct __declspec(uuid("df1208d1-31bb-5596-43b1-6d69a0257b3a")) __declspec(novtable) ISmartCardAppletIdGroupRegistration : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ActivationPolicy(winrt::Windows::Devices::SmartCards::SmartCardAppletIdGroupActivationPolicy * value) = 0;
    virtual HRESULT __stdcall get_AppletIdGroup(Windows::Devices::SmartCards::ISmartCardAppletIdGroup ** value) = 0;
    virtual HRESULT __stdcall abi_RequestActivationPolicyChangeAsync(winrt::Windows::Devices::SmartCards::SmartCardAppletIdGroupActivationPolicy policy, Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardActivationPolicyChangeResult> ** result) = 0;
    virtual HRESULT __stdcall get_Id(GUID * value) = 0;
    virtual HRESULT __stdcall abi_SetAutomaticResponseApdusAsync(Windows::Foundation::Collections::IIterable<Windows::Devices::SmartCards::SmartCardAutomaticResponseApdu> * apdus, Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("ab2899a9-e76c-45cf-bf1d-90eaa6205927")) __declspec(novtable) ISmartCardAppletIdGroupStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MaxAppletIds(uint16_t * value) = 0;
};

struct __declspec(uuid("52152bab-c63e-4531-a857-d756d99b986a")) __declspec(novtable) ISmartCardAutomaticResponseApdu : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CommandApdu(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall put_CommandApdu(Windows::Storage::Streams::IBuffer * value) = 0;
    virtual HRESULT __stdcall get_CommandApduBitMask(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall put_CommandApduBitMask(Windows::Storage::Streams::IBuffer * value) = 0;
    virtual HRESULT __stdcall get_ShouldMatchLength(bool * value) = 0;
    virtual HRESULT __stdcall put_ShouldMatchLength(bool value) = 0;
    virtual HRESULT __stdcall get_AppletId(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall put_AppletId(Windows::Storage::Streams::IBuffer * value) = 0;
    virtual HRESULT __stdcall get_ResponseApdu(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall put_ResponseApdu(Windows::Storage::Streams::IBuffer * value) = 0;
};

struct __declspec(uuid("44aebb14-559d-4531-4e51-89db6fa8a57a")) __declspec(novtable) ISmartCardAutomaticResponseApdu2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_InputState(Windows::Foundation::IReference<uint32_t> ** value) = 0;
    virtual HRESULT __stdcall put_InputState(Windows::Foundation::IReference<uint32_t> * value) = 0;
    virtual HRESULT __stdcall get_OutputState(Windows::Foundation::IReference<uint32_t> ** value) = 0;
    virtual HRESULT __stdcall put_OutputState(Windows::Foundation::IReference<uint32_t> * value) = 0;
};

struct __declspec(uuid("bf43da74-6576-4392-9367-fe3bc9e2d496")) __declspec(novtable) ISmartCardAutomaticResponseApdu3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AllowWhenCryptogramGeneratorNotPrepared(bool * value) = 0;
    virtual HRESULT __stdcall put_AllowWhenCryptogramGeneratorNotPrepared(bool value) = 0;
};

struct __declspec(uuid("e97ea2fa-d02c-4c55-b02a-8cff7fa9f05b")) __declspec(novtable) ISmartCardAutomaticResponseApduFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Storage::Streams::IBuffer * commandApdu, Windows::Storage::Streams::IBuffer * responseApdu, Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu ** result) = 0;
};

struct __declspec(uuid("192a5319-c9c4-4947-81cc-44794a61ef91")) __declspec(novtable) ISmartCardChallengeContext : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Challenge(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall abi_VerifyResponseAsync(Windows::Storage::Streams::IBuffer * response, Windows::Foundation::IAsyncOperation<bool> ** result) = 0;
    virtual HRESULT __stdcall abi_ProvisionAsync(Windows::Storage::Streams::IBuffer * response, bool formatCard, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_ProvisionAsyncWithNewCardId(Windows::Storage::Streams::IBuffer * response, bool formatCard, GUID newCardId, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_ChangeAdministrativeKeyAsync(Windows::Storage::Streams::IBuffer * response, Windows::Storage::Streams::IBuffer * newAdministrativeKey, Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("2fdf87e5-028d-491e-a058-3382c3986f40")) __declspec(novtable) ISmartCardConnect : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ConnectAsync(Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardConnection> ** result) = 0;
};

struct __declspec(uuid("7edb991a-a81a-47bc-a649-156be6b7f231")) __declspec(novtable) ISmartCardConnection : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_TransmitAsync(Windows::Storage::Streams::IBuffer * command, Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> ** result) = 0;
};

struct __declspec(uuid("e39f587b-edd3-4e49-b594-0ff5e4d0c76f")) __declspec(novtable) ISmartCardCryptogramGenerator : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SupportedCryptogramMaterialTypes(Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::SmartCards::SmartCardCryptogramMaterialType> ** result) = 0;
    virtual HRESULT __stdcall get_SupportedCryptogramAlgorithms(Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::SmartCards::SmartCardCryptogramAlgorithm> ** result) = 0;
    virtual HRESULT __stdcall get_SupportedCryptogramMaterialPackageFormats(Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageFormat> ** result) = 0;
    virtual HRESULT __stdcall get_SupportedCryptogramMaterialPackageConfirmationResponseFormats(Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageConfirmationResponseFormat> ** result) = 0;
    virtual HRESULT __stdcall get_SupportedSmartCardCryptogramStorageKeyCapabilities(Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyCapabilities> ** result) = 0;
    virtual HRESULT __stdcall abi_DeleteCryptogramMaterialStorageKeyAsync(hstring storageKeyName, Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus> ** result) = 0;
    virtual HRESULT __stdcall abi_CreateCryptogramMaterialStorageKeyAsync(winrt::Windows::Devices::SmartCards::SmartCardUnlockPromptingBehavior promptingBehavior, hstring storageKeyName, winrt::Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyAlgorithm algorithm, winrt::Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyCapabilities capabilities, Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus> ** result) = 0;
    virtual HRESULT __stdcall abi_RequestCryptogramMaterialStorageKeyInfoAsync(winrt::Windows::Devices::SmartCards::SmartCardUnlockPromptingBehavior promptingBehavior, hstring storageKeyName, winrt::Windows::Security::Cryptography::Core::CryptographicPublicKeyBlobType format, Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyInfo> ** result) = 0;
    virtual HRESULT __stdcall abi_ImportCryptogramMaterialPackageAsync(winrt::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageFormat format, hstring storageKeyName, hstring materialPackageName, Windows::Storage::Streams::IBuffer * cryptogramMaterialPackage, Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus> ** result) = 0;
    virtual HRESULT __stdcall abi_TryProvePossessionOfCryptogramMaterialPackageAsync(winrt::Windows::Devices::SmartCards::SmartCardUnlockPromptingBehavior promptingBehavior, winrt::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageConfirmationResponseFormat responseFormat, hstring materialPackageName, hstring materialName, Windows::Storage::Streams::IBuffer * challenge, Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardCryptogramMaterialPossessionProof> ** result) = 0;
    virtual HRESULT __stdcall abi_RequestUnlockCryptogramMaterialForUseAsync(winrt::Windows::Devices::SmartCards::SmartCardUnlockPromptingBehavior promptingBehavior, Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus> ** result) = 0;
    virtual HRESULT __stdcall abi_DeleteCryptogramMaterialPackageAsync(hstring materialPackageName, Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus> ** result) = 0;
};

struct __declspec(uuid("09933910-cb9c-4015-967d-5234f3b02900")) __declspec(novtable) ISmartCardCryptogramGeneratorStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetSmartCardCryptogramGeneratorAsync(Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardCryptogramGenerator> ** result) = 0;
};

struct __declspec(uuid("e5b9ab8c-a141-4135-9add-b0d2e3aa1fc9")) __declspec(novtable) ISmartCardCryptogramMaterialPossessionProof : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_OperationStatus(winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus * value) = 0;
    virtual HRESULT __stdcall get_Proof(Windows::Storage::Streams::IBuffer ** value) = 0;
};

struct __declspec(uuid("947b03eb-8342-4792-a2e5-925636378a53")) __declspec(novtable) ISmartCardCryptogramPlacementStep : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Algorithm(winrt::Windows::Devices::SmartCards::SmartCardCryptogramAlgorithm * value) = 0;
    virtual HRESULT __stdcall put_Algorithm(winrt::Windows::Devices::SmartCards::SmartCardCryptogramAlgorithm value) = 0;
    virtual HRESULT __stdcall get_SourceData(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall put_SourceData(Windows::Storage::Streams::IBuffer * value) = 0;
    virtual HRESULT __stdcall get_CryptogramMaterialPackageName(hstring * value) = 0;
    virtual HRESULT __stdcall put_CryptogramMaterialPackageName(hstring value) = 0;
    virtual HRESULT __stdcall get_CryptogramMaterialName(hstring * value) = 0;
    virtual HRESULT __stdcall put_CryptogramMaterialName(hstring value) = 0;
    virtual HRESULT __stdcall get_TemplateOffset(int32_t * value) = 0;
    virtual HRESULT __stdcall put_TemplateOffset(int32_t value) = 0;
    virtual HRESULT __stdcall get_CryptogramOffset(int32_t * value) = 0;
    virtual HRESULT __stdcall put_CryptogramOffset(int32_t value) = 0;
    virtual HRESULT __stdcall get_CryptogramLength(int32_t * value) = 0;
    virtual HRESULT __stdcall put_CryptogramLength(int32_t value) = 0;
    virtual HRESULT __stdcall get_CryptogramPlacementOptions(winrt::Windows::Devices::SmartCards::SmartCardCryptogramPlacementOptions * value) = 0;
    virtual HRESULT __stdcall put_CryptogramPlacementOptions(winrt::Windows::Devices::SmartCards::SmartCardCryptogramPlacementOptions value) = 0;
    virtual HRESULT __stdcall get_ChainedOutputStep(Windows::Devices::SmartCards::ISmartCardCryptogramPlacementStep ** value) = 0;
    virtual HRESULT __stdcall put_ChainedOutputStep(Windows::Devices::SmartCards::ISmartCardCryptogramPlacementStep * value) = 0;
};

struct __declspec(uuid("77b0f00d-b097-4f61-a26a-9561639c9c3a")) __declspec(novtable) ISmartCardCryptogramStorageKeyInfo : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_OperationStatus(winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus * value) = 0;
    virtual HRESULT __stdcall get_PublicKeyBlobType(winrt::Windows::Security::Cryptography::Core::CryptographicPublicKeyBlobType * value) = 0;
    virtual HRESULT __stdcall get_PublicKey(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall get_AttestationStatus(winrt::Windows::Devices::SmartCards::SmartCardCryptographicKeyAttestationStatus * value) = 0;
    virtual HRESULT __stdcall get_Attestation(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall get_AttestationCertificateChain(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall get_Capabilities(winrt::Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyCapabilities * value) = 0;
};

struct __declspec(uuid("000440f9-f7fd-417d-89e1-fbb0382adc4d")) __declspec(novtable) ISmartCardCryptogramStorageKeyInfo2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_OperationalRequirements(hstring * value) = 0;
};

struct __declspec(uuid("dfb906b2-875e-47e5-8077-e8bff1b1c6fb")) __declspec(novtable) ISmartCardEmulator : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_EnablementPolicy(winrt::Windows::Devices::SmartCards::SmartCardEmulatorEnablementPolicy * value) = 0;
};

struct __declspec(uuid("fe3fc0b8-8529-411a-807b-48edc2a0ab44")) __declspec(novtable) ISmartCardEmulator2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_ApduReceived(Windows::Foundation::TypedEventHandler<Windows::Devices::SmartCards::SmartCardEmulator, Windows::Devices::SmartCards::SmartCardEmulatorApduReceivedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ApduReceived(event_token value) = 0;
    virtual HRESULT __stdcall add_ConnectionDeactivated(Windows::Foundation::TypedEventHandler<Windows::Devices::SmartCards::SmartCardEmulator, Windows::Devices::SmartCards::SmartCardEmulatorConnectionDeactivatedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ConnectionDeactivated(event_token value) = 0;
    virtual HRESULT __stdcall abi_Start() = 0;
    virtual HRESULT __stdcall abi_IsHostCardEmulationSupported(bool * value) = 0;
};

struct __declspec(uuid("d55d1576-69d2-5333-5b5f-f8c0d6e9f09f")) __declspec(novtable) ISmartCardEmulatorApduReceivedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CommandApdu(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall get_ConnectionProperties(Windows::Devices::SmartCards::ISmartCardEmulatorConnectionProperties ** value) = 0;
    virtual HRESULT __stdcall abi_TryRespondAsync(Windows::Storage::Streams::IBuffer * responseApdu, Windows::Foundation::IAsyncOperation<bool> ** result) = 0;
    virtual HRESULT __stdcall get_AutomaticResponseStatus(winrt::Windows::Devices::SmartCards::SmartCardAutomaticResponseStatus * value) = 0;
};

struct __declspec(uuid("8bf93df0-22e1-4238-8610-94ce4a965425")) __declspec(novtable) ISmartCardEmulatorApduReceivedEventArgs2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_State(uint32_t * value) = 0;
    virtual HRESULT __stdcall abi_TryRespondWithStateAsync(Windows::Storage::Streams::IBuffer * responseApdu, Windows::Foundation::IReference<uint32_t> * nextState, Windows::Foundation::IAsyncOperation<bool> ** result) = 0;
};

struct __declspec(uuid("d550bac7-b7bf-4e29-9294-0c4ac3c941bd")) __declspec(novtable) ISmartCardEmulatorApduReceivedEventArgsWithCryptograms : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_TryRespondWithCryptogramsAsync(Windows::Storage::Streams::IBuffer * responseTemplate, Windows::Foundation::Collections::IIterable<Windows::Devices::SmartCards::SmartCardCryptogramPlacementStep> * cryptogramPlacementSteps, Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus> ** result) = 0;
    virtual HRESULT __stdcall abi_TryRespondWithCryptogramsAndStateAsync(Windows::Storage::Streams::IBuffer * responseTemplate, Windows::Foundation::Collections::IIterable<Windows::Devices::SmartCards::SmartCardCryptogramPlacementStep> * cryptogramPlacementSteps, Windows::Foundation::IReference<uint32_t> * nextState, Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus> ** result) = 0;
};

struct __declspec(uuid("2186d8d3-c5eb-5262-43df-62a0a1b55557")) __declspec(novtable) ISmartCardEmulatorConnectionDeactivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ConnectionProperties(Windows::Devices::SmartCards::ISmartCardEmulatorConnectionProperties ** value) = 0;
    virtual HRESULT __stdcall get_Reason(winrt::Windows::Devices::SmartCards::SmartCardEmulatorConnectionDeactivatedReason * value) = 0;
};

struct __declspec(uuid("4e2ca5ee-f969-507d-6cf9-34e2d18df311")) __declspec(novtable) ISmartCardEmulatorConnectionProperties : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(GUID * value) = 0;
    virtual HRESULT __stdcall get_Source(winrt::Windows::Devices::SmartCards::SmartCardEmulatorConnectionSource * value) = 0;
};

struct __declspec(uuid("7a9bfc4b-c4d3-494f-b8a2-6215d81e85b2")) __declspec(novtable) ISmartCardEmulatorStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDefaultAsync(Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardEmulator> ** result) = 0;
};

struct __declspec(uuid("69ae9f8a-b775-488b-8436-6c1e28ed731f")) __declspec(novtable) ISmartCardEmulatorStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetAppletIdGroupRegistrationsAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration>> ** result) = 0;
    virtual HRESULT __stdcall abi_RegisterAppletIdGroupAsync(Windows::Devices::SmartCards::ISmartCardAppletIdGroup * appletIdGroup, Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration> ** result) = 0;
    virtual HRESULT __stdcall abi_UnregisterAppletIdGroupAsync(Windows::Devices::SmartCards::ISmartCardAppletIdGroupRegistration * registration, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall get_MaxAppletIdGroupRegistrations(uint16_t * value) = 0;
};

struct __declspec(uuid("183ce184-4db6-4841-ac9e-2ac1f39b7304")) __declspec(novtable) ISmartCardPinPolicy : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MinLength(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_MinLength(uint32_t value) = 0;
    virtual HRESULT __stdcall get_MaxLength(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_MaxLength(uint32_t value) = 0;
    virtual HRESULT __stdcall get_UppercaseLetters(winrt::Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption * value) = 0;
    virtual HRESULT __stdcall put_UppercaseLetters(winrt::Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption value) = 0;
    virtual HRESULT __stdcall get_LowercaseLetters(winrt::Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption * value) = 0;
    virtual HRESULT __stdcall put_LowercaseLetters(winrt::Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption value) = 0;
    virtual HRESULT __stdcall get_Digits(winrt::Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption * value) = 0;
    virtual HRESULT __stdcall put_Digits(winrt::Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption value) = 0;
    virtual HRESULT __stdcall get_SpecialCharacters(winrt::Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption * value) = 0;
    virtual HRESULT __stdcall put_SpecialCharacters(winrt::Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption value) = 0;
};

struct __declspec(uuid("18c94aac-7805-4004-85e4-bbefac8f6884")) __declspec(novtable) ISmartCardPinResetDeferral : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Complete() = 0;
};

struct __declspec(uuid("12fe3c4d-5fb9-4e8e-9ff6-61f475124fef")) __declspec(novtable) ISmartCardPinResetRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Challenge(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall get_Deadline(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Devices::SmartCards::ISmartCardPinResetDeferral ** result) = 0;
    virtual HRESULT __stdcall abi_SetResponse(Windows::Storage::Streams::IBuffer * response) = 0;
};

struct __declspec(uuid("19eeedbd-1fab-477c-b712-1a2c5af1fd6e")) __declspec(novtable) ISmartCardProvisioning : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SmartCard(Windows::Devices::SmartCards::ISmartCard ** value) = 0;
    virtual HRESULT __stdcall abi_GetIdAsync(Windows::Foundation::IAsyncOperation<GUID> ** result) = 0;
    virtual HRESULT __stdcall abi_GetNameAsync(Windows::Foundation::IAsyncOperation<hstring> ** result) = 0;
    virtual HRESULT __stdcall abi_GetChallengeContextAsync(Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardChallengeContext> ** result) = 0;
    virtual HRESULT __stdcall abi_RequestPinChangeAsync(Windows::Foundation::IAsyncOperation<bool> ** result) = 0;
    virtual HRESULT __stdcall abi_RequestPinResetAsync(Windows::Devices::SmartCards::SmartCardPinResetHandler * handler, Windows::Foundation::IAsyncOperation<bool> ** result) = 0;
};

struct __declspec(uuid("10fd28eb-3f79-4b66-9b7c-11c149b7d0bc")) __declspec(novtable) ISmartCardProvisioning2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetAuthorityKeyContainerNameAsync(Windows::Foundation::IAsyncOperation<hstring> ** result) = 0;
};

struct __declspec(uuid("13882848-0d13-4e70-9735-51daeca5254f")) __declspec(novtable) ISmartCardProvisioningStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FromSmartCardAsync(Windows::Devices::SmartCards::ISmartCard * card, Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> ** result) = 0;
    virtual HRESULT __stdcall abi_RequestVirtualSmartCardCreationAsync(hstring friendlyName, Windows::Storage::Streams::IBuffer * administrativeKey, Windows::Devices::SmartCards::ISmartCardPinPolicy * pinPolicy, Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> ** result) = 0;
    virtual HRESULT __stdcall abi_RequestVirtualSmartCardCreationAsyncWithCardId(hstring friendlyName, Windows::Storage::Streams::IBuffer * administrativeKey, Windows::Devices::SmartCards::ISmartCardPinPolicy * pinPolicy, GUID cardId, Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> ** result) = 0;
    virtual HRESULT __stdcall abi_RequestVirtualSmartCardDeletionAsync(Windows::Devices::SmartCards::ISmartCard * card, Windows::Foundation::IAsyncOperation<bool> ** result) = 0;
};

struct __declspec(uuid("3447c6a8-c9a0-4bd6-b50d-251f4e8d3a62")) __declspec(novtable) ISmartCardProvisioningStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RequestAttestedVirtualSmartCardCreationAsync(hstring friendlyName, Windows::Storage::Streams::IBuffer * administrativeKey, Windows::Devices::SmartCards::ISmartCardPinPolicy * pinPolicy, Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> ** result) = 0;
    virtual HRESULT __stdcall abi_RequestAttestedVirtualSmartCardCreationAsyncWithCardId(hstring friendlyName, Windows::Storage::Streams::IBuffer * administrativeKey, Windows::Devices::SmartCards::ISmartCardPinPolicy * pinPolicy, GUID cardId, Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> ** result) = 0;
};

struct __declspec(uuid("1074b4e0-54c2-4df0-817a-14c14378f06c")) __declspec(novtable) ISmartCardReader : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall get_Kind(winrt::Windows::Devices::SmartCards::SmartCardReaderKind * value) = 0;
    virtual HRESULT __stdcall abi_GetStatusAsync(Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardReaderStatus> ** result) = 0;
    virtual HRESULT __stdcall abi_FindAllCardsAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::SmartCards::SmartCard>> ** result) = 0;
    virtual HRESULT __stdcall add_CardAdded(Windows::Foundation::TypedEventHandler<Windows::Devices::SmartCards::SmartCardReader, Windows::Devices::SmartCards::CardAddedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_CardAdded(event_token token) = 0;
    virtual HRESULT __stdcall add_CardRemoved(Windows::Foundation::TypedEventHandler<Windows::Devices::SmartCards::SmartCardReader, Windows::Devices::SmartCards::CardRemovedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_CardRemoved(event_token token) = 0;
};

struct __declspec(uuid("103c04e1-a1ca-48f2-a281-5b6f669af107")) __declspec(novtable) ISmartCardReaderStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDeviceSelector(hstring * selector) = 0;
    virtual HRESULT __stdcall abi_GetDeviceSelectorWithKind(winrt::Windows::Devices::SmartCards::SmartCardReaderKind kind, hstring * selector) = 0;
    virtual HRESULT __stdcall abi_FromIdAsync(hstring deviceId, Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardReader> ** result) = 0;
};

struct __declspec(uuid("5f9bf11e-39ef-4f2b-b44f-0a9155b177bc")) __declspec(novtable) ISmartCardTriggerDetails : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TriggerType(winrt::Windows::Devices::SmartCards::SmartCardTriggerType * value) = 0;
    virtual HRESULT __stdcall get_SourceAppletId(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall get_TriggerData(Windows::Storage::Streams::IBuffer ** value) = 0;
};

struct __declspec(uuid("2945c569-8975-4a51-9e1a-5f8a76ee51af")) __declspec(novtable) ISmartCardTriggerDetails2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Emulator(Windows::Devices::SmartCards::ISmartCardEmulator ** value) = 0;
    virtual HRESULT __stdcall abi_TryLaunchCurrentAppAsync(hstring arguments, Windows::Foundation::IAsyncOperation<bool> ** result) = 0;
    virtual HRESULT __stdcall abi_TryLaunchCurrentAppWithBehaviorAsync(hstring arguments, winrt::Windows::Devices::SmartCards::SmartCardLaunchBehavior behavior, Windows::Foundation::IAsyncOperation<bool> ** result) = 0;
};

struct __declspec(uuid("138d5e40-f3bc-4a5c-b41d-4b4ef684e237")) __declspec(novtable) SmartCardPinResetHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Devices::SmartCards::ISmartCardProvisioning * sender, Windows::Devices::SmartCards::ISmartCardPinResetRequest * request) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Devices::SmartCards::CardAddedEventArgs> { using default_interface = Windows::Devices::SmartCards::ICardAddedEventArgs; };
template <> struct traits<Windows::Devices::SmartCards::CardRemovedEventArgs> { using default_interface = Windows::Devices::SmartCards::ICardRemovedEventArgs; };
template <> struct traits<Windows::Devices::SmartCards::SmartCard> { using default_interface = Windows::Devices::SmartCards::ISmartCard; };
template <> struct traits<Windows::Devices::SmartCards::SmartCardAppletIdGroup> { using default_interface = Windows::Devices::SmartCards::ISmartCardAppletIdGroup; };
template <> struct traits<Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration> { using default_interface = Windows::Devices::SmartCards::ISmartCardAppletIdGroupRegistration; };
template <> struct traits<Windows::Devices::SmartCards::SmartCardAutomaticResponseApdu> { using default_interface = Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu; };
template <> struct traits<Windows::Devices::SmartCards::SmartCardChallengeContext> { using default_interface = Windows::Devices::SmartCards::ISmartCardChallengeContext; };
template <> struct traits<Windows::Devices::SmartCards::SmartCardConnection> { using default_interface = Windows::Devices::SmartCards::ISmartCardConnection; };
template <> struct traits<Windows::Devices::SmartCards::SmartCardCryptogramGenerator> { using default_interface = Windows::Devices::SmartCards::ISmartCardCryptogramGenerator; };
template <> struct traits<Windows::Devices::SmartCards::SmartCardCryptogramMaterialPossessionProof> { using default_interface = Windows::Devices::SmartCards::ISmartCardCryptogramMaterialPossessionProof; };
template <> struct traits<Windows::Devices::SmartCards::SmartCardCryptogramPlacementStep> { using default_interface = Windows::Devices::SmartCards::ISmartCardCryptogramPlacementStep; };
template <> struct traits<Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyInfo> { using default_interface = Windows::Devices::SmartCards::ISmartCardCryptogramStorageKeyInfo; };
template <> struct traits<Windows::Devices::SmartCards::SmartCardEmulator> { using default_interface = Windows::Devices::SmartCards::ISmartCardEmulator; };
template <> struct traits<Windows::Devices::SmartCards::SmartCardEmulatorApduReceivedEventArgs> { using default_interface = Windows::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgs; };
template <> struct traits<Windows::Devices::SmartCards::SmartCardEmulatorConnectionDeactivatedEventArgs> { using default_interface = Windows::Devices::SmartCards::ISmartCardEmulatorConnectionDeactivatedEventArgs; };
template <> struct traits<Windows::Devices::SmartCards::SmartCardEmulatorConnectionProperties> { using default_interface = Windows::Devices::SmartCards::ISmartCardEmulatorConnectionProperties; };
template <> struct traits<Windows::Devices::SmartCards::SmartCardPinPolicy> { using default_interface = Windows::Devices::SmartCards::ISmartCardPinPolicy; };
template <> struct traits<Windows::Devices::SmartCards::SmartCardPinResetDeferral> { using default_interface = Windows::Devices::SmartCards::ISmartCardPinResetDeferral; };
template <> struct traits<Windows::Devices::SmartCards::SmartCardPinResetRequest> { using default_interface = Windows::Devices::SmartCards::ISmartCardPinResetRequest; };
template <> struct traits<Windows::Devices::SmartCards::SmartCardProvisioning> { using default_interface = Windows::Devices::SmartCards::ISmartCardProvisioning; };
template <> struct traits<Windows::Devices::SmartCards::SmartCardReader> { using default_interface = Windows::Devices::SmartCards::ISmartCardReader; };
template <> struct traits<Windows::Devices::SmartCards::SmartCardTriggerDetails> { using default_interface = Windows::Devices::SmartCards::ISmartCardTriggerDetails; };

}

namespace Windows::Devices::SmartCards {

template <typename D>
struct WINRT_EBO impl_ICardAddedEventArgs
{
    Windows::Devices::SmartCards::SmartCard SmartCard() const;
};

template <typename D>
struct WINRT_EBO impl_ICardRemovedEventArgs
{
    Windows::Devices::SmartCards::SmartCard SmartCard() const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCard
{
    Windows::Devices::SmartCards::SmartCardReader Reader() const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardStatus> GetStatusAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> GetAnswerToResetAsync() const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardAppletIdGroup
{
    hstring DisplayName() const;
    void DisplayName(hstring_view value) const;
    Windows::Foundation::Collections::IVector<Windows::Storage::Streams::IBuffer> AppletIds() const;
    Windows::Devices::SmartCards::SmartCardEmulationCategory SmartCardEmulationCategory() const;
    void SmartCardEmulationCategory(Windows::Devices::SmartCards::SmartCardEmulationCategory value) const;
    Windows::Devices::SmartCards::SmartCardEmulationType SmartCardEmulationType() const;
    void SmartCardEmulationType(Windows::Devices::SmartCards::SmartCardEmulationType value) const;
    bool AutomaticEnablement() const;
    void AutomaticEnablement(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardAppletIdGroupFactory
{
    Windows::Devices::SmartCards::SmartCardAppletIdGroup Create(hstring_view displayName, const Windows::Foundation::Collections::IVector<Windows::Storage::Streams::IBuffer> & appletIds, Windows::Devices::SmartCards::SmartCardEmulationCategory emulationCategory, Windows::Devices::SmartCards::SmartCardEmulationType emulationType) const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardAppletIdGroupRegistration
{
    Windows::Devices::SmartCards::SmartCardAppletIdGroupActivationPolicy ActivationPolicy() const;
    Windows::Devices::SmartCards::SmartCardAppletIdGroup AppletIdGroup() const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardActivationPolicyChangeResult> RequestActivationPolicyChangeAsync(Windows::Devices::SmartCards::SmartCardAppletIdGroupActivationPolicy policy) const;
    GUID Id() const;
    Windows::Foundation::IAsyncAction SetAutomaticResponseApdusAsync(iterable<Windows::Devices::SmartCards::SmartCardAutomaticResponseApdu> apdus) const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardAppletIdGroupStatics
{
    uint16_t MaxAppletIds() const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardAutomaticResponseApdu
{
    Windows::Storage::Streams::IBuffer CommandApdu() const;
    void CommandApdu(const Windows::Storage::Streams::IBuffer & value) const;
    Windows::Storage::Streams::IBuffer CommandApduBitMask() const;
    void CommandApduBitMask(const Windows::Storage::Streams::IBuffer & value) const;
    bool ShouldMatchLength() const;
    void ShouldMatchLength(bool value) const;
    Windows::Storage::Streams::IBuffer AppletId() const;
    void AppletId(const Windows::Storage::Streams::IBuffer & value) const;
    Windows::Storage::Streams::IBuffer ResponseApdu() const;
    void ResponseApdu(const Windows::Storage::Streams::IBuffer & value) const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardAutomaticResponseApdu2
{
    Windows::Foundation::IReference<uint32_t> InputState() const;
    void InputState(const optional<uint32_t> & value) const;
    Windows::Foundation::IReference<uint32_t> OutputState() const;
    void OutputState(const optional<uint32_t> & value) const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardAutomaticResponseApdu3
{
    bool AllowWhenCryptogramGeneratorNotPrepared() const;
    void AllowWhenCryptogramGeneratorNotPrepared(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardAutomaticResponseApduFactory
{
    Windows::Devices::SmartCards::SmartCardAutomaticResponseApdu Create(const Windows::Storage::Streams::IBuffer & commandApdu, const Windows::Storage::Streams::IBuffer & responseApdu) const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardChallengeContext
{
    Windows::Storage::Streams::IBuffer Challenge() const;
    Windows::Foundation::IAsyncOperation<bool> VerifyResponseAsync(const Windows::Storage::Streams::IBuffer & response) const;
    Windows::Foundation::IAsyncAction ProvisionAsync(const Windows::Storage::Streams::IBuffer & response, bool formatCard) const;
    Windows::Foundation::IAsyncAction ProvisionAsync(const Windows::Storage::Streams::IBuffer & response, bool formatCard, GUID newCardId) const;
    Windows::Foundation::IAsyncAction ChangeAdministrativeKeyAsync(const Windows::Storage::Streams::IBuffer & response, const Windows::Storage::Streams::IBuffer & newAdministrativeKey) const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardConnect
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardConnection> ConnectAsync() const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardConnection
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> TransmitAsync(const Windows::Storage::Streams::IBuffer & command) const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardCryptogramGenerator
{
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::SmartCards::SmartCardCryptogramMaterialType> SupportedCryptogramMaterialTypes() const;
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::SmartCards::SmartCardCryptogramAlgorithm> SupportedCryptogramAlgorithms() const;
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageFormat> SupportedCryptogramMaterialPackageFormats() const;
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageConfirmationResponseFormat> SupportedCryptogramMaterialPackageConfirmationResponseFormats() const;
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyCapabilities> SupportedSmartCardCryptogramStorageKeyCapabilities() const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus> DeleteCryptogramMaterialStorageKeyAsync(hstring_view storageKeyName) const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus> CreateCryptogramMaterialStorageKeyAsync(Windows::Devices::SmartCards::SmartCardUnlockPromptingBehavior promptingBehavior, hstring_view storageKeyName, Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyAlgorithm algorithm, Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyCapabilities capabilities) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyInfo> RequestCryptogramMaterialStorageKeyInfoAsync(Windows::Devices::SmartCards::SmartCardUnlockPromptingBehavior promptingBehavior, hstring_view storageKeyName, Windows::Security::Cryptography::Core::CryptographicPublicKeyBlobType format) const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus> ImportCryptogramMaterialPackageAsync(Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageFormat format, hstring_view storageKeyName, hstring_view materialPackageName, const Windows::Storage::Streams::IBuffer & cryptogramMaterialPackage) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardCryptogramMaterialPossessionProof> TryProvePossessionOfCryptogramMaterialPackageAsync(Windows::Devices::SmartCards::SmartCardUnlockPromptingBehavior promptingBehavior, Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageConfirmationResponseFormat responseFormat, hstring_view materialPackageName, hstring_view materialName, const Windows::Storage::Streams::IBuffer & challenge) const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus> RequestUnlockCryptogramMaterialForUseAsync(Windows::Devices::SmartCards::SmartCardUnlockPromptingBehavior promptingBehavior) const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus> DeleteCryptogramMaterialPackageAsync(hstring_view materialPackageName) const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardCryptogramGeneratorStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardCryptogramGenerator> GetSmartCardCryptogramGeneratorAsync() const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardCryptogramMaterialPossessionProof
{
    Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus OperationStatus() const;
    Windows::Storage::Streams::IBuffer Proof() const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardCryptogramPlacementStep
{
    Windows::Devices::SmartCards::SmartCardCryptogramAlgorithm Algorithm() const;
    void Algorithm(Windows::Devices::SmartCards::SmartCardCryptogramAlgorithm value) const;
    Windows::Storage::Streams::IBuffer SourceData() const;
    void SourceData(const Windows::Storage::Streams::IBuffer & value) const;
    hstring CryptogramMaterialPackageName() const;
    void CryptogramMaterialPackageName(hstring_view value) const;
    hstring CryptogramMaterialName() const;
    void CryptogramMaterialName(hstring_view value) const;
    int32_t TemplateOffset() const;
    void TemplateOffset(int32_t value) const;
    int32_t CryptogramOffset() const;
    void CryptogramOffset(int32_t value) const;
    int32_t CryptogramLength() const;
    void CryptogramLength(int32_t value) const;
    Windows::Devices::SmartCards::SmartCardCryptogramPlacementOptions CryptogramPlacementOptions() const;
    void CryptogramPlacementOptions(Windows::Devices::SmartCards::SmartCardCryptogramPlacementOptions value) const;
    Windows::Devices::SmartCards::SmartCardCryptogramPlacementStep ChainedOutputStep() const;
    void ChainedOutputStep(const Windows::Devices::SmartCards::SmartCardCryptogramPlacementStep & value) const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardCryptogramStorageKeyInfo
{
    Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus OperationStatus() const;
    Windows::Security::Cryptography::Core::CryptographicPublicKeyBlobType PublicKeyBlobType() const;
    Windows::Storage::Streams::IBuffer PublicKey() const;
    Windows::Devices::SmartCards::SmartCardCryptographicKeyAttestationStatus AttestationStatus() const;
    Windows::Storage::Streams::IBuffer Attestation() const;
    Windows::Storage::Streams::IBuffer AttestationCertificateChain() const;
    Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyCapabilities Capabilities() const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardCryptogramStorageKeyInfo2
{
    hstring OperationalRequirements() const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardEmulator
{
    Windows::Devices::SmartCards::SmartCardEmulatorEnablementPolicy EnablementPolicy() const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardEmulator2
{
    event_token ApduReceived(const Windows::Foundation::TypedEventHandler<Windows::Devices::SmartCards::SmartCardEmulator, Windows::Devices::SmartCards::SmartCardEmulatorApduReceivedEventArgs> & value) const;
    using ApduReceived_revoker = event_revoker<ISmartCardEmulator2>;
    ApduReceived_revoker ApduReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::SmartCards::SmartCardEmulator, Windows::Devices::SmartCards::SmartCardEmulatorApduReceivedEventArgs> & value) const;
    void ApduReceived(event_token value) const;
    event_token ConnectionDeactivated(const Windows::Foundation::TypedEventHandler<Windows::Devices::SmartCards::SmartCardEmulator, Windows::Devices::SmartCards::SmartCardEmulatorConnectionDeactivatedEventArgs> & value) const;
    using ConnectionDeactivated_revoker = event_revoker<ISmartCardEmulator2>;
    ConnectionDeactivated_revoker ConnectionDeactivated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::SmartCards::SmartCardEmulator, Windows::Devices::SmartCards::SmartCardEmulatorConnectionDeactivatedEventArgs> & value) const;
    void ConnectionDeactivated(event_token value) const;
    void Start() const;
    bool IsHostCardEmulationSupported() const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardEmulatorApduReceivedEventArgs
{
    Windows::Storage::Streams::IBuffer CommandApdu() const;
    Windows::Devices::SmartCards::SmartCardEmulatorConnectionProperties ConnectionProperties() const;
    Windows::Foundation::IAsyncOperation<bool> TryRespondAsync(const Windows::Storage::Streams::IBuffer & responseApdu) const;
    Windows::Devices::SmartCards::SmartCardAutomaticResponseStatus AutomaticResponseStatus() const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardEmulatorApduReceivedEventArgs2
{
    uint32_t State() const;
    Windows::Foundation::IAsyncOperation<bool> TryRespondAsync(const Windows::Storage::Streams::IBuffer & responseApdu, const optional<uint32_t> & nextState) const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardEmulatorApduReceivedEventArgsWithCryptograms
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus> TryRespondWithCryptogramsAsync(const Windows::Storage::Streams::IBuffer & responseTemplate, iterable<Windows::Devices::SmartCards::SmartCardCryptogramPlacementStep> cryptogramPlacementSteps) const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus> TryRespondWithCryptogramsAsync(const Windows::Storage::Streams::IBuffer & responseTemplate, iterable<Windows::Devices::SmartCards::SmartCardCryptogramPlacementStep> cryptogramPlacementSteps, const optional<uint32_t> & nextState) const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardEmulatorConnectionDeactivatedEventArgs
{
    Windows::Devices::SmartCards::SmartCardEmulatorConnectionProperties ConnectionProperties() const;
    Windows::Devices::SmartCards::SmartCardEmulatorConnectionDeactivatedReason Reason() const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardEmulatorConnectionProperties
{
    GUID Id() const;
    Windows::Devices::SmartCards::SmartCardEmulatorConnectionSource Source() const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardEmulatorStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardEmulator> GetDefaultAsync() const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardEmulatorStatics2
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration>> GetAppletIdGroupRegistrationsAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration> RegisterAppletIdGroupAsync(const Windows::Devices::SmartCards::SmartCardAppletIdGroup & appletIdGroup) const;
    Windows::Foundation::IAsyncAction UnregisterAppletIdGroupAsync(const Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration & registration) const;
    uint16_t MaxAppletIdGroupRegistrations() const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardPinPolicy
{
    uint32_t MinLength() const;
    void MinLength(uint32_t value) const;
    uint32_t MaxLength() const;
    void MaxLength(uint32_t value) const;
    Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption UppercaseLetters() const;
    void UppercaseLetters(Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption value) const;
    Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption LowercaseLetters() const;
    void LowercaseLetters(Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption value) const;
    Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption Digits() const;
    void Digits(Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption value) const;
    Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption SpecialCharacters() const;
    void SpecialCharacters(Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption value) const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardPinResetDeferral
{
    void Complete() const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardPinResetRequest
{
    Windows::Storage::Streams::IBuffer Challenge() const;
    Windows::Foundation::DateTime Deadline() const;
    Windows::Devices::SmartCards::SmartCardPinResetDeferral GetDeferral() const;
    void SetResponse(const Windows::Storage::Streams::IBuffer & response) const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardProvisioning
{
    Windows::Devices::SmartCards::SmartCard SmartCard() const;
    Windows::Foundation::IAsyncOperation<GUID> GetIdAsync() const;
    Windows::Foundation::IAsyncOperation<hstring> GetNameAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardChallengeContext> GetChallengeContextAsync() const;
    Windows::Foundation::IAsyncOperation<bool> RequestPinChangeAsync() const;
    Windows::Foundation::IAsyncOperation<bool> RequestPinResetAsync(const Windows::Devices::SmartCards::SmartCardPinResetHandler & handler) const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardProvisioning2
{
    Windows::Foundation::IAsyncOperation<hstring> GetAuthorityKeyContainerNameAsync() const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardProvisioningStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> FromSmartCardAsync(const Windows::Devices::SmartCards::SmartCard & card) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> RequestVirtualSmartCardCreationAsync(hstring_view friendlyName, const Windows::Storage::Streams::IBuffer & administrativeKey, const Windows::Devices::SmartCards::SmartCardPinPolicy & pinPolicy) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> RequestVirtualSmartCardCreationAsync(hstring_view friendlyName, const Windows::Storage::Streams::IBuffer & administrativeKey, const Windows::Devices::SmartCards::SmartCardPinPolicy & pinPolicy, GUID cardId) const;
    Windows::Foundation::IAsyncOperation<bool> RequestVirtualSmartCardDeletionAsync(const Windows::Devices::SmartCards::SmartCard & card) const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardProvisioningStatics2
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> RequestAttestedVirtualSmartCardCreationAsync(hstring_view friendlyName, const Windows::Storage::Streams::IBuffer & administrativeKey, const Windows::Devices::SmartCards::SmartCardPinPolicy & pinPolicy) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> RequestAttestedVirtualSmartCardCreationAsync(hstring_view friendlyName, const Windows::Storage::Streams::IBuffer & administrativeKey, const Windows::Devices::SmartCards::SmartCardPinPolicy & pinPolicy, GUID cardId) const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardReader
{
    hstring DeviceId() const;
    hstring Name() const;
    Windows::Devices::SmartCards::SmartCardReaderKind Kind() const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardReaderStatus> GetStatusAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::SmartCards::SmartCard>> FindAllCardsAsync() const;
    event_token CardAdded(const Windows::Foundation::TypedEventHandler<Windows::Devices::SmartCards::SmartCardReader, Windows::Devices::SmartCards::CardAddedEventArgs> & handler) const;
    using CardAdded_revoker = event_revoker<ISmartCardReader>;
    CardAdded_revoker CardAdded(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::SmartCards::SmartCardReader, Windows::Devices::SmartCards::CardAddedEventArgs> & handler) const;
    void CardAdded(event_token token) const;
    event_token CardRemoved(const Windows::Foundation::TypedEventHandler<Windows::Devices::SmartCards::SmartCardReader, Windows::Devices::SmartCards::CardRemovedEventArgs> & handler) const;
    using CardRemoved_revoker = event_revoker<ISmartCardReader>;
    CardRemoved_revoker CardRemoved(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::SmartCards::SmartCardReader, Windows::Devices::SmartCards::CardRemovedEventArgs> & handler) const;
    void CardRemoved(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardReaderStatics
{
    hstring GetDeviceSelector() const;
    hstring GetDeviceSelector(Windows::Devices::SmartCards::SmartCardReaderKind kind) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardReader> FromIdAsync(hstring_view deviceId) const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardTriggerDetails
{
    Windows::Devices::SmartCards::SmartCardTriggerType TriggerType() const;
    Windows::Storage::Streams::IBuffer SourceAppletId() const;
    Windows::Storage::Streams::IBuffer TriggerData() const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardTriggerDetails2
{
    Windows::Devices::SmartCards::SmartCardEmulator Emulator() const;
    Windows::Foundation::IAsyncOperation<bool> TryLaunchCurrentAppAsync(hstring_view arguments) const;
    Windows::Foundation::IAsyncOperation<bool> TryLaunchCurrentAppAsync(hstring_view arguments, Windows::Devices::SmartCards::SmartCardLaunchBehavior behavior) const;
};

}

namespace impl {

template <> struct traits<Windows::Devices::SmartCards::ICardAddedEventArgs>
{
    using abi = ABI::Windows::Devices::SmartCards::ICardAddedEventArgs;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ICardAddedEventArgs<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ICardRemovedEventArgs>
{
    using abi = ABI::Windows::Devices::SmartCards::ICardRemovedEventArgs;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ICardRemovedEventArgs<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ISmartCard>
{
    using abi = ABI::Windows::Devices::SmartCards::ISmartCard;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ISmartCard<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ISmartCardAppletIdGroup>
{
    using abi = ABI::Windows::Devices::SmartCards::ISmartCardAppletIdGroup;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ISmartCardAppletIdGroup<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ISmartCardAppletIdGroupFactory>
{
    using abi = ABI::Windows::Devices::SmartCards::ISmartCardAppletIdGroupFactory;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ISmartCardAppletIdGroupFactory<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ISmartCardAppletIdGroupRegistration>
{
    using abi = ABI::Windows::Devices::SmartCards::ISmartCardAppletIdGroupRegistration;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ISmartCardAppletIdGroupRegistration<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ISmartCardAppletIdGroupStatics>
{
    using abi = ABI::Windows::Devices::SmartCards::ISmartCardAppletIdGroupStatics;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ISmartCardAppletIdGroupStatics<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu>
{
    using abi = ABI::Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ISmartCardAutomaticResponseApdu<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu2>
{
    using abi = ABI::Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu2;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ISmartCardAutomaticResponseApdu2<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu3>
{
    using abi = ABI::Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu3;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ISmartCardAutomaticResponseApdu3<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ISmartCardAutomaticResponseApduFactory>
{
    using abi = ABI::Windows::Devices::SmartCards::ISmartCardAutomaticResponseApduFactory;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ISmartCardAutomaticResponseApduFactory<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ISmartCardChallengeContext>
{
    using abi = ABI::Windows::Devices::SmartCards::ISmartCardChallengeContext;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ISmartCardChallengeContext<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ISmartCardConnect>
{
    using abi = ABI::Windows::Devices::SmartCards::ISmartCardConnect;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ISmartCardConnect<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ISmartCardConnection>
{
    using abi = ABI::Windows::Devices::SmartCards::ISmartCardConnection;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ISmartCardConnection<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ISmartCardCryptogramGenerator>
{
    using abi = ABI::Windows::Devices::SmartCards::ISmartCardCryptogramGenerator;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ISmartCardCryptogramGenerator<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ISmartCardCryptogramGeneratorStatics>
{
    using abi = ABI::Windows::Devices::SmartCards::ISmartCardCryptogramGeneratorStatics;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ISmartCardCryptogramGeneratorStatics<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ISmartCardCryptogramMaterialPossessionProof>
{
    using abi = ABI::Windows::Devices::SmartCards::ISmartCardCryptogramMaterialPossessionProof;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ISmartCardCryptogramMaterialPossessionProof<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ISmartCardCryptogramPlacementStep>
{
    using abi = ABI::Windows::Devices::SmartCards::ISmartCardCryptogramPlacementStep;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ISmartCardCryptogramPlacementStep<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ISmartCardCryptogramStorageKeyInfo>
{
    using abi = ABI::Windows::Devices::SmartCards::ISmartCardCryptogramStorageKeyInfo;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ISmartCardCryptogramStorageKeyInfo<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ISmartCardCryptogramStorageKeyInfo2>
{
    using abi = ABI::Windows::Devices::SmartCards::ISmartCardCryptogramStorageKeyInfo2;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ISmartCardCryptogramStorageKeyInfo2<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ISmartCardEmulator>
{
    using abi = ABI::Windows::Devices::SmartCards::ISmartCardEmulator;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ISmartCardEmulator<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ISmartCardEmulator2>
{
    using abi = ABI::Windows::Devices::SmartCards::ISmartCardEmulator2;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ISmartCardEmulator2<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgs>
{
    using abi = ABI::Windows::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgs;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ISmartCardEmulatorApduReceivedEventArgs<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgs2>
{
    using abi = ABI::Windows::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgs2;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ISmartCardEmulatorApduReceivedEventArgs2<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgsWithCryptograms>
{
    using abi = ABI::Windows::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgsWithCryptograms;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ISmartCardEmulatorApduReceivedEventArgsWithCryptograms<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ISmartCardEmulatorConnectionDeactivatedEventArgs>
{
    using abi = ABI::Windows::Devices::SmartCards::ISmartCardEmulatorConnectionDeactivatedEventArgs;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ISmartCardEmulatorConnectionDeactivatedEventArgs<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ISmartCardEmulatorConnectionProperties>
{
    using abi = ABI::Windows::Devices::SmartCards::ISmartCardEmulatorConnectionProperties;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ISmartCardEmulatorConnectionProperties<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ISmartCardEmulatorStatics>
{
    using abi = ABI::Windows::Devices::SmartCards::ISmartCardEmulatorStatics;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ISmartCardEmulatorStatics<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ISmartCardEmulatorStatics2>
{
    using abi = ABI::Windows::Devices::SmartCards::ISmartCardEmulatorStatics2;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ISmartCardEmulatorStatics2<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ISmartCardPinPolicy>
{
    using abi = ABI::Windows::Devices::SmartCards::ISmartCardPinPolicy;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ISmartCardPinPolicy<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ISmartCardPinResetDeferral>
{
    using abi = ABI::Windows::Devices::SmartCards::ISmartCardPinResetDeferral;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ISmartCardPinResetDeferral<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ISmartCardPinResetRequest>
{
    using abi = ABI::Windows::Devices::SmartCards::ISmartCardPinResetRequest;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ISmartCardPinResetRequest<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ISmartCardProvisioning>
{
    using abi = ABI::Windows::Devices::SmartCards::ISmartCardProvisioning;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ISmartCardProvisioning<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ISmartCardProvisioning2>
{
    using abi = ABI::Windows::Devices::SmartCards::ISmartCardProvisioning2;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ISmartCardProvisioning2<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ISmartCardProvisioningStatics>
{
    using abi = ABI::Windows::Devices::SmartCards::ISmartCardProvisioningStatics;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ISmartCardProvisioningStatics<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ISmartCardProvisioningStatics2>
{
    using abi = ABI::Windows::Devices::SmartCards::ISmartCardProvisioningStatics2;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ISmartCardProvisioningStatics2<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ISmartCardReader>
{
    using abi = ABI::Windows::Devices::SmartCards::ISmartCardReader;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ISmartCardReader<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ISmartCardReaderStatics>
{
    using abi = ABI::Windows::Devices::SmartCards::ISmartCardReaderStatics;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ISmartCardReaderStatics<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ISmartCardTriggerDetails>
{
    using abi = ABI::Windows::Devices::SmartCards::ISmartCardTriggerDetails;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ISmartCardTriggerDetails<D>;
};

template <> struct traits<Windows::Devices::SmartCards::ISmartCardTriggerDetails2>
{
    using abi = ABI::Windows::Devices::SmartCards::ISmartCardTriggerDetails2;
    template <typename D> using consume = Windows::Devices::SmartCards::impl_ISmartCardTriggerDetails2<D>;
};

template <> struct traits<Windows::Devices::SmartCards::SmartCardPinResetHandler>
{
    using abi = ABI::Windows::Devices::SmartCards::SmartCardPinResetHandler;
};

template <> struct traits<Windows::Devices::SmartCards::CardAddedEventArgs>
{
    using abi = ABI::Windows::Devices::SmartCards::CardAddedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.SmartCards.CardAddedEventArgs"; }
};

template <> struct traits<Windows::Devices::SmartCards::CardRemovedEventArgs>
{
    using abi = ABI::Windows::Devices::SmartCards::CardRemovedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.SmartCards.CardRemovedEventArgs"; }
};

template <> struct traits<Windows::Devices::SmartCards::SmartCard>
{
    using abi = ABI::Windows::Devices::SmartCards::SmartCard;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.SmartCards.SmartCard"; }
};

template <> struct traits<Windows::Devices::SmartCards::SmartCardAppletIdGroup>
{
    using abi = ABI::Windows::Devices::SmartCards::SmartCardAppletIdGroup;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.SmartCards.SmartCardAppletIdGroup"; }
};

template <> struct traits<Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration>
{
    using abi = ABI::Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.SmartCards.SmartCardAppletIdGroupRegistration"; }
};

template <> struct traits<Windows::Devices::SmartCards::SmartCardAutomaticResponseApdu>
{
    using abi = ABI::Windows::Devices::SmartCards::SmartCardAutomaticResponseApdu;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.SmartCards.SmartCardAutomaticResponseApdu"; }
};

template <> struct traits<Windows::Devices::SmartCards::SmartCardChallengeContext>
{
    using abi = ABI::Windows::Devices::SmartCards::SmartCardChallengeContext;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.SmartCards.SmartCardChallengeContext"; }
};

template <> struct traits<Windows::Devices::SmartCards::SmartCardConnection>
{
    using abi = ABI::Windows::Devices::SmartCards::SmartCardConnection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.SmartCards.SmartCardConnection"; }
};

template <> struct traits<Windows::Devices::SmartCards::SmartCardCryptogramGenerator>
{
    using abi = ABI::Windows::Devices::SmartCards::SmartCardCryptogramGenerator;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.SmartCards.SmartCardCryptogramGenerator"; }
};

template <> struct traits<Windows::Devices::SmartCards::SmartCardCryptogramMaterialPossessionProof>
{
    using abi = ABI::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPossessionProof;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.SmartCards.SmartCardCryptogramMaterialPossessionProof"; }
};

template <> struct traits<Windows::Devices::SmartCards::SmartCardCryptogramPlacementStep>
{
    using abi = ABI::Windows::Devices::SmartCards::SmartCardCryptogramPlacementStep;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.SmartCards.SmartCardCryptogramPlacementStep"; }
};

template <> struct traits<Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyInfo>
{
    using abi = ABI::Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.SmartCards.SmartCardCryptogramStorageKeyInfo"; }
};

template <> struct traits<Windows::Devices::SmartCards::SmartCardEmulator>
{
    using abi = ABI::Windows::Devices::SmartCards::SmartCardEmulator;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.SmartCards.SmartCardEmulator"; }
};

template <> struct traits<Windows::Devices::SmartCards::SmartCardEmulatorApduReceivedEventArgs>
{
    using abi = ABI::Windows::Devices::SmartCards::SmartCardEmulatorApduReceivedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.SmartCards.SmartCardEmulatorApduReceivedEventArgs"; }
};

template <> struct traits<Windows::Devices::SmartCards::SmartCardEmulatorConnectionDeactivatedEventArgs>
{
    using abi = ABI::Windows::Devices::SmartCards::SmartCardEmulatorConnectionDeactivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.SmartCards.SmartCardEmulatorConnectionDeactivatedEventArgs"; }
};

template <> struct traits<Windows::Devices::SmartCards::SmartCardEmulatorConnectionProperties>
{
    using abi = ABI::Windows::Devices::SmartCards::SmartCardEmulatorConnectionProperties;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.SmartCards.SmartCardEmulatorConnectionProperties"; }
};

template <> struct traits<Windows::Devices::SmartCards::SmartCardPinPolicy>
{
    using abi = ABI::Windows::Devices::SmartCards::SmartCardPinPolicy;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.SmartCards.SmartCardPinPolicy"; }
};

template <> struct traits<Windows::Devices::SmartCards::SmartCardPinResetDeferral>
{
    using abi = ABI::Windows::Devices::SmartCards::SmartCardPinResetDeferral;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.SmartCards.SmartCardPinResetDeferral"; }
};

template <> struct traits<Windows::Devices::SmartCards::SmartCardPinResetRequest>
{
    using abi = ABI::Windows::Devices::SmartCards::SmartCardPinResetRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.SmartCards.SmartCardPinResetRequest"; }
};

template <> struct traits<Windows::Devices::SmartCards::SmartCardProvisioning>
{
    using abi = ABI::Windows::Devices::SmartCards::SmartCardProvisioning;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.SmartCards.SmartCardProvisioning"; }
};

template <> struct traits<Windows::Devices::SmartCards::SmartCardReader>
{
    using abi = ABI::Windows::Devices::SmartCards::SmartCardReader;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.SmartCards.SmartCardReader"; }
};

template <> struct traits<Windows::Devices::SmartCards::SmartCardTriggerDetails>
{
    using abi = ABI::Windows::Devices::SmartCards::SmartCardTriggerDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.SmartCards.SmartCardTriggerDetails"; }
};

}

}
