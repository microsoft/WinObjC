// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Gaming.Input.Custom.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Gaming::Input::Custom {

struct GameControllerFactoryManager
{
    GameControllerFactoryManager() = delete;
    static void RegisterCustomFactoryForGipInterface(const Windows::Gaming::Input::Custom::ICustomGameControllerFactory & factory, GUID interfaceId);
    static void RegisterCustomFactoryForHardwareId(const Windows::Gaming::Input::Custom::ICustomGameControllerFactory & factory, uint16_t hardwareVendorId, uint16_t hardwareProductId);
    static void RegisterCustomFactoryForXusbType(const Windows::Gaming::Input::Custom::ICustomGameControllerFactory & factory, Windows::Gaming::Input::Custom::XusbDeviceType xusbType, Windows::Gaming::Input::Custom::XusbDeviceSubtype xusbSubtype);
};

struct WINRT_EBO GipFirmwareUpdateResult :
    Windows::Gaming::Input::Custom::IGipFirmwareUpdateResult
{
    GipFirmwareUpdateResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO GipGameControllerProvider :
    Windows::Gaming::Input::Custom::IGipGameControllerProvider
{
    GipGameControllerProvider(std::nullptr_t) noexcept {}
};

struct WINRT_EBO XusbGameControllerProvider :
    Windows::Gaming::Input::Custom::IXusbGameControllerProvider
{
    XusbGameControllerProvider(std::nullptr_t) noexcept {}
};

}

}
