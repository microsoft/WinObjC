// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Gaming.Input.Custom.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_bfaa48bd_155f_5112_bd86_e01d6f7cd405
#define WINRT_GENERIC_bfaa48bd_155f_5112_bd86_e01d6f7cd405
template <> struct __declspec(uuid("bfaa48bd-155f-5112-bd86-e01d6f7cd405")) __declspec(novtable) IAsyncOperationWithProgress<Windows::Gaming::Input::Custom::GipFirmwareUpdateResult, Windows::Gaming::Input::Custom::GipFirmwareUpdateProgress> : impl_IAsyncOperationWithProgress<Windows::Gaming::Input::Custom::GipFirmwareUpdateResult, Windows::Gaming::Input::Custom::GipFirmwareUpdateProgress> {};
#endif

#ifndef WINRT_GENERIC_065c16af_49dc_5c94_afe2_9385937facc9
#define WINRT_GENERIC_065c16af_49dc_5c94_afe2_9385937facc9
template <> struct __declspec(uuid("065c16af-49dc-5c94-afe2-9385937facc9")) __declspec(novtable) AsyncOperationProgressHandler<Windows::Gaming::Input::Custom::GipFirmwareUpdateResult, Windows::Gaming::Input::Custom::GipFirmwareUpdateProgress> : impl_AsyncOperationProgressHandler<Windows::Gaming::Input::Custom::GipFirmwareUpdateResult, Windows::Gaming::Input::Custom::GipFirmwareUpdateProgress> {};
#endif

#ifndef WINRT_GENERIC_61b95949_a027_51d8_9f33_37927451502b
#define WINRT_GENERIC_61b95949_a027_51d8_9f33_37927451502b
template <> struct __declspec(uuid("61b95949-a027-51d8-9f33-37927451502b")) __declspec(novtable) AsyncOperationWithProgressCompletedHandler<Windows::Gaming::Input::Custom::GipFirmwareUpdateResult, Windows::Gaming::Input::Custom::GipFirmwareUpdateProgress> : impl_AsyncOperationWithProgressCompletedHandler<Windows::Gaming::Input::Custom::GipFirmwareUpdateResult, Windows::Gaming::Input::Custom::GipFirmwareUpdateProgress> {};
#endif


}

namespace Windows::Gaming::Input::Custom {

struct ICustomGameControllerFactory :
    Windows::Foundation::IInspectable,
    impl::consume<ICustomGameControllerFactory>
{
    ICustomGameControllerFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IGameControllerFactoryManagerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IGameControllerFactoryManagerStatics>
{
    IGameControllerFactoryManagerStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IGameControllerInputSink :
    Windows::Foundation::IInspectable,
    impl::consume<IGameControllerInputSink>
{
    IGameControllerInputSink(std::nullptr_t = nullptr) noexcept {}
};

struct IGameControllerProvider :
    Windows::Foundation::IInspectable,
    impl::consume<IGameControllerProvider>
{
    IGameControllerProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IGipFirmwareUpdateResult :
    Windows::Foundation::IInspectable,
    impl::consume<IGipFirmwareUpdateResult>
{
    IGipFirmwareUpdateResult(std::nullptr_t = nullptr) noexcept {}
};

struct IGipGameControllerInputSink :
    Windows::Foundation::IInspectable,
    impl::consume<IGipGameControllerInputSink>,
    impl::require<IGipGameControllerInputSink, Windows::Gaming::Input::Custom::IGameControllerInputSink>
{
    IGipGameControllerInputSink(std::nullptr_t = nullptr) noexcept {}
};

struct IGipGameControllerProvider :
    Windows::Foundation::IInspectable,
    impl::consume<IGipGameControllerProvider>,
    impl::require<IGipGameControllerProvider, Windows::Gaming::Input::Custom::IGameControllerProvider>
{
    IGipGameControllerProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IXusbGameControllerInputSink :
    Windows::Foundation::IInspectable,
    impl::consume<IXusbGameControllerInputSink>,
    impl::require<IXusbGameControllerInputSink, Windows::Gaming::Input::Custom::IGameControllerInputSink>
{
    IXusbGameControllerInputSink(std::nullptr_t = nullptr) noexcept {}
};

struct IXusbGameControllerProvider :
    Windows::Foundation::IInspectable,
    impl::consume<IXusbGameControllerProvider>,
    impl::require<IXusbGameControllerProvider, Windows::Gaming::Input::Custom::IGameControllerProvider>
{
    IXusbGameControllerProvider(std::nullptr_t = nullptr) noexcept {}
};

}

}
