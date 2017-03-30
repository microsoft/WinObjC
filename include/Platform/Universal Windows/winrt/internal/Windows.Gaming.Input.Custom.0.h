// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Gaming::Input::Custom {

struct GameControllerVersionInfo;
struct GipFirmwareUpdateProgress;

}

namespace Windows::Gaming::Input::Custom {

using GameControllerVersionInfo = ABI::Windows::Gaming::Input::Custom::GameControllerVersionInfo;
using GipFirmwareUpdateProgress = ABI::Windows::Gaming::Input::Custom::GipFirmwareUpdateProgress;

}

namespace ABI::Windows::Gaming::Input::Custom {

struct ICustomGameControllerFactory;
struct IGameControllerFactoryManagerStatics;
struct IGameControllerInputSink;
struct IGameControllerProvider;
struct IGipFirmwareUpdateResult;
struct IGipGameControllerInputSink;
struct IGipGameControllerProvider;
struct IXusbGameControllerInputSink;
struct IXusbGameControllerProvider;
struct GipFirmwareUpdateResult;
struct GipGameControllerProvider;
struct XusbGameControllerProvider;

}

namespace Windows::Gaming::Input::Custom {

struct ICustomGameControllerFactory;
struct IGameControllerFactoryManagerStatics;
struct IGameControllerInputSink;
struct IGameControllerProvider;
struct IGipFirmwareUpdateResult;
struct IGipGameControllerInputSink;
struct IGipGameControllerProvider;
struct IXusbGameControllerInputSink;
struct IXusbGameControllerProvider;
struct GameControllerFactoryManager;
struct GipFirmwareUpdateResult;
struct GipGameControllerProvider;
struct XusbGameControllerProvider;

}

namespace Windows::Gaming::Input::Custom {

template <typename T> struct impl_ICustomGameControllerFactory;
template <typename T> struct impl_IGameControllerFactoryManagerStatics;
template <typename T> struct impl_IGameControllerInputSink;
template <typename T> struct impl_IGameControllerProvider;
template <typename T> struct impl_IGipFirmwareUpdateResult;
template <typename T> struct impl_IGipGameControllerInputSink;
template <typename T> struct impl_IGipGameControllerProvider;
template <typename T> struct impl_IXusbGameControllerInputSink;
template <typename T> struct impl_IXusbGameControllerProvider;

}

namespace Windows::Gaming::Input::Custom {

enum class GipFirmwareUpdateStatus
{
    Completed = 0,
    UpToDate = 1,
    Failed = 2,
};

enum class GipMessageClass
{
    Command = 0,
    LowLatency = 1,
    StandardLatency = 2,
};

enum class XusbDeviceSubtype
{
    Unknown = 0,
    Gamepad = 1,
    ArcadePad = 2,
    ArcadeStick = 3,
    FlightStick = 4,
    Wheel = 5,
    Guitar = 6,
    GuitarAlternate = 7,
    GuitarBass = 8,
    DrumKit = 9,
    DancePad = 10,
};

enum class XusbDeviceType
{
    Unknown = 0,
    Gamepad = 1,
};

}

}
