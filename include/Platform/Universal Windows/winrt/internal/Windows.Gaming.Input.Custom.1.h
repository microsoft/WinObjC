// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Gaming.Input.Custom.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Gaming.Input.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Gaming::Input::Custom {

struct GameControllerVersionInfo
{
    uint16_t Major;
    uint16_t Minor;
    uint16_t Build;
    uint16_t Revision;
};

struct GipFirmwareUpdateProgress
{
    double PercentCompleted;
    uint32_t CurrentComponentId;
};

}

namespace Windows::Gaming::Input::Custom {

using GameControllerVersionInfo = ABI::Windows::Gaming::Input::Custom::GameControllerVersionInfo;
using GipFirmwareUpdateProgress = ABI::Windows::Gaming::Input::Custom::GipFirmwareUpdateProgress;

}

namespace ABI::Windows::Gaming::Input::Custom {

struct __declspec(uuid("69a0ae5e-758e-4cbe-ace6-62155fe9126f")) __declspec(novtable) ICustomGameControllerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateGameController(Windows::Gaming::Input::Custom::IGameControllerProvider * provider, Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall abi_OnGameControllerAdded(Windows::Gaming::Input::IGameController * value) = 0;
    virtual HRESULT __stdcall abi_OnGameControllerRemoved(Windows::Gaming::Input::IGameController * value) = 0;
};

struct __declspec(uuid("36cb66e3-d0a1-4986-a24c-40b137deba9e")) __declspec(novtable) IGameControllerFactoryManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RegisterCustomFactoryForGipInterface(Windows::Gaming::Input::Custom::ICustomGameControllerFactory * factory, GUID interfaceId) = 0;
    virtual HRESULT __stdcall abi_RegisterCustomFactoryForHardwareId(Windows::Gaming::Input::Custom::ICustomGameControllerFactory * factory, uint16_t hardwareVendorId, uint16_t hardwareProductId) = 0;
    virtual HRESULT __stdcall abi_RegisterCustomFactoryForXusbType(Windows::Gaming::Input::Custom::ICustomGameControllerFactory * factory, winrt::Windows::Gaming::Input::Custom::XusbDeviceType xusbType, winrt::Windows::Gaming::Input::Custom::XusbDeviceSubtype xusbSubtype) = 0;
};

struct __declspec(uuid("1ff6f922-c640-4c78-a820-9a715c558bcb")) __declspec(novtable) IGameControllerInputSink : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_OnInputResumed(uint64_t timestamp) = 0;
    virtual HRESULT __stdcall abi_OnInputSuspended(uint64_t timestamp) = 0;
};

struct __declspec(uuid("e6d73982-2996-4559-b16c-3e57d46e58d6")) __declspec(novtable) IGameControllerProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FirmwareVersionInfo(Windows::Gaming::Input::Custom::GameControllerVersionInfo * value) = 0;
    virtual HRESULT __stdcall get_HardwareProductId(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_HardwareVendorId(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_HardwareVersionInfo(Windows::Gaming::Input::Custom::GameControllerVersionInfo * value) = 0;
    virtual HRESULT __stdcall get_IsConnected(bool * value) = 0;
};

struct __declspec(uuid("6b794d32-8553-4292-8e03-e16651a2f8bc")) __declspec(novtable) IGipFirmwareUpdateResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ExtendedErrorCode(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_FinalComponentId(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_Status(winrt::Windows::Gaming::Input::Custom::GipFirmwareUpdateStatus * value) = 0;
};

struct __declspec(uuid("a2108abf-09f1-43bc-a140-80f899ec36fb")) __declspec(novtable) IGipGameControllerInputSink : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_OnKeyReceived(uint64_t timestamp, uint8_t keyCode, bool isPressed) = 0;
    virtual HRESULT __stdcall abi_OnMessageReceived(uint64_t timestamp, winrt::Windows::Gaming::Input::Custom::GipMessageClass messageClass, uint8_t messageId, uint8_t sequenceId, uint32_t __messageBufferSize, uint8_t * messageBuffer) = 0;
};

struct __declspec(uuid("dbcf1e19-1af5-45a8-bf02-a0ee50c823fc")) __declspec(novtable) IGipGameControllerProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SendMessage(winrt::Windows::Gaming::Input::Custom::GipMessageClass messageClass, uint8_t messageId, uint32_t __messageBufferSize, uint8_t * messageBuffer) = 0;
    virtual HRESULT __stdcall abi_SendReceiveMessage(winrt::Windows::Gaming::Input::Custom::GipMessageClass messageClass, uint8_t messageId, uint32_t __requestMessageBufferSize, uint8_t * requestMessageBuffer, uint32_t __responseMessageBufferSize, uint8_t * responseMessageBuffer) = 0;
    virtual HRESULT __stdcall abi_UpdateFirmwareAsync(Windows::Storage::Streams::IInputStream * firmwareImage, Windows::Foundation::IAsyncOperationWithProgress<Windows::Gaming::Input::Custom::GipFirmwareUpdateResult, Windows::Gaming::Input::Custom::GipFirmwareUpdateProgress> ** result) = 0;
};

struct __declspec(uuid("b2ac1d95-6ecb-42b3-8aab-025401ca4712")) __declspec(novtable) IXusbGameControllerInputSink : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_OnInputReceived(uint64_t timestamp, uint8_t reportId, uint32_t __inputBufferSize, uint8_t * inputBuffer) = 0;
};

struct __declspec(uuid("6e2971eb-0efb-48b4-808b-837643b2f216")) __declspec(novtable) IXusbGameControllerProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SetVibration(double lowFrequencyMotorSpeed, double highFrequencyMotorSpeed) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Gaming::Input::Custom::GipFirmwareUpdateResult> { using default_interface = Windows::Gaming::Input::Custom::IGipFirmwareUpdateResult; };
template <> struct traits<Windows::Gaming::Input::Custom::GipGameControllerProvider> { using default_interface = Windows::Gaming::Input::Custom::IGipGameControllerProvider; };
template <> struct traits<Windows::Gaming::Input::Custom::XusbGameControllerProvider> { using default_interface = Windows::Gaming::Input::Custom::IXusbGameControllerProvider; };

}

namespace Windows::Gaming::Input::Custom {

template <typename D>
struct WINRT_EBO impl_ICustomGameControllerFactory
{
    Windows::Foundation::IInspectable CreateGameController(const Windows::Gaming::Input::Custom::IGameControllerProvider & provider) const;
    void OnGameControllerAdded(const Windows::Gaming::Input::IGameController & value) const;
    void OnGameControllerRemoved(const Windows::Gaming::Input::IGameController & value) const;
};

template <typename D>
struct WINRT_EBO impl_IGameControllerFactoryManagerStatics
{
    void RegisterCustomFactoryForGipInterface(const Windows::Gaming::Input::Custom::ICustomGameControllerFactory & factory, GUID interfaceId) const;
    void RegisterCustomFactoryForHardwareId(const Windows::Gaming::Input::Custom::ICustomGameControllerFactory & factory, uint16_t hardwareVendorId, uint16_t hardwareProductId) const;
    void RegisterCustomFactoryForXusbType(const Windows::Gaming::Input::Custom::ICustomGameControllerFactory & factory, Windows::Gaming::Input::Custom::XusbDeviceType xusbType, Windows::Gaming::Input::Custom::XusbDeviceSubtype xusbSubtype) const;
};

template <typename D>
struct WINRT_EBO impl_IGameControllerInputSink
{
    void OnInputResumed(uint64_t timestamp) const;
    void OnInputSuspended(uint64_t timestamp) const;
};

template <typename D>
struct WINRT_EBO impl_IGameControllerProvider
{
    Windows::Gaming::Input::Custom::GameControllerVersionInfo FirmwareVersionInfo() const;
    uint16_t HardwareProductId() const;
    uint16_t HardwareVendorId() const;
    Windows::Gaming::Input::Custom::GameControllerVersionInfo HardwareVersionInfo() const;
    bool IsConnected() const;
};

template <typename D>
struct WINRT_EBO impl_IGipFirmwareUpdateResult
{
    uint32_t ExtendedErrorCode() const;
    uint32_t FinalComponentId() const;
    Windows::Gaming::Input::Custom::GipFirmwareUpdateStatus Status() const;
};

template <typename D>
struct WINRT_EBO impl_IGipGameControllerInputSink
{
    void OnKeyReceived(uint64_t timestamp, uint8_t keyCode, bool isPressed) const;
    void OnMessageReceived(uint64_t timestamp, Windows::Gaming::Input::Custom::GipMessageClass messageClass, uint8_t messageId, uint8_t sequenceId, array_view<const uint8_t> messageBuffer) const;
};

template <typename D>
struct WINRT_EBO impl_IGipGameControllerProvider
{
    void SendMessage(Windows::Gaming::Input::Custom::GipMessageClass messageClass, uint8_t messageId, array_view<const uint8_t> messageBuffer) const;
    void SendReceiveMessage(Windows::Gaming::Input::Custom::GipMessageClass messageClass, uint8_t messageId, array_view<const uint8_t> requestMessageBuffer, array_view<uint8_t> responseMessageBuffer) const;
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Gaming::Input::Custom::GipFirmwareUpdateResult, Windows::Gaming::Input::Custom::GipFirmwareUpdateProgress> UpdateFirmwareAsync(const Windows::Storage::Streams::IInputStream & firmwareImage) const;
};

template <typename D>
struct WINRT_EBO impl_IXusbGameControllerInputSink
{
    void OnInputReceived(uint64_t timestamp, uint8_t reportId, array_view<const uint8_t> inputBuffer) const;
};

template <typename D>
struct WINRT_EBO impl_IXusbGameControllerProvider
{
    void SetVibration(double lowFrequencyMotorSpeed, double highFrequencyMotorSpeed) const;
};

}

namespace impl {

template <> struct traits<Windows::Gaming::Input::Custom::ICustomGameControllerFactory>
{
    using abi = ABI::Windows::Gaming::Input::Custom::ICustomGameControllerFactory;
    template <typename D> using consume = Windows::Gaming::Input::Custom::impl_ICustomGameControllerFactory<D>;
};

template <> struct traits<Windows::Gaming::Input::Custom::IGameControllerFactoryManagerStatics>
{
    using abi = ABI::Windows::Gaming::Input::Custom::IGameControllerFactoryManagerStatics;
    template <typename D> using consume = Windows::Gaming::Input::Custom::impl_IGameControllerFactoryManagerStatics<D>;
};

template <> struct traits<Windows::Gaming::Input::Custom::IGameControllerInputSink>
{
    using abi = ABI::Windows::Gaming::Input::Custom::IGameControllerInputSink;
    template <typename D> using consume = Windows::Gaming::Input::Custom::impl_IGameControllerInputSink<D>;
};

template <> struct traits<Windows::Gaming::Input::Custom::IGameControllerProvider>
{
    using abi = ABI::Windows::Gaming::Input::Custom::IGameControllerProvider;
    template <typename D> using consume = Windows::Gaming::Input::Custom::impl_IGameControllerProvider<D>;
};

template <> struct traits<Windows::Gaming::Input::Custom::IGipFirmwareUpdateResult>
{
    using abi = ABI::Windows::Gaming::Input::Custom::IGipFirmwareUpdateResult;
    template <typename D> using consume = Windows::Gaming::Input::Custom::impl_IGipFirmwareUpdateResult<D>;
};

template <> struct traits<Windows::Gaming::Input::Custom::IGipGameControllerInputSink>
{
    using abi = ABI::Windows::Gaming::Input::Custom::IGipGameControllerInputSink;
    template <typename D> using consume = Windows::Gaming::Input::Custom::impl_IGipGameControllerInputSink<D>;
};

template <> struct traits<Windows::Gaming::Input::Custom::IGipGameControllerProvider>
{
    using abi = ABI::Windows::Gaming::Input::Custom::IGipGameControllerProvider;
    template <typename D> using consume = Windows::Gaming::Input::Custom::impl_IGipGameControllerProvider<D>;
};

template <> struct traits<Windows::Gaming::Input::Custom::IXusbGameControllerInputSink>
{
    using abi = ABI::Windows::Gaming::Input::Custom::IXusbGameControllerInputSink;
    template <typename D> using consume = Windows::Gaming::Input::Custom::impl_IXusbGameControllerInputSink<D>;
};

template <> struct traits<Windows::Gaming::Input::Custom::IXusbGameControllerProvider>
{
    using abi = ABI::Windows::Gaming::Input::Custom::IXusbGameControllerProvider;
    template <typename D> using consume = Windows::Gaming::Input::Custom::impl_IXusbGameControllerProvider<D>;
};

template <> struct traits<Windows::Gaming::Input::Custom::GameControllerFactoryManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Gaming.Input.Custom.GameControllerFactoryManager"; }
};

template <> struct traits<Windows::Gaming::Input::Custom::GipFirmwareUpdateResult>
{
    using abi = ABI::Windows::Gaming::Input::Custom::GipFirmwareUpdateResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Gaming.Input.Custom.GipFirmwareUpdateResult"; }
};

template <> struct traits<Windows::Gaming::Input::Custom::GipGameControllerProvider>
{
    using abi = ABI::Windows::Gaming::Input::Custom::GipGameControllerProvider;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Gaming.Input.Custom.GipGameControllerProvider"; }
};

template <> struct traits<Windows::Gaming::Input::Custom::XusbGameControllerProvider>
{
    using abi = ABI::Windows::Gaming::Input::Custom::XusbGameControllerProvider;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Gaming.Input.Custom.XusbGameControllerProvider"; }
};

}

}
