// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Phone::Media::Devices {

struct IAudioRoutingManager;
struct IAudioRoutingManagerStatics;
struct AudioRoutingManager;

}

namespace Windows::Phone::Media::Devices {

struct IAudioRoutingManager;
struct IAudioRoutingManagerStatics;
struct AudioRoutingManager;

}

namespace Windows::Phone::Media::Devices {

template <typename T> struct impl_IAudioRoutingManager;
template <typename T> struct impl_IAudioRoutingManagerStatics;

}

namespace Windows::Phone::Media::Devices {

enum class AudioRoutingEndpoint
{
    Default = 0,
    Earpiece = 1,
    Speakerphone = 2,
    Bluetooth = 3,
    WiredHeadset = 4,
    WiredHeadsetSpeakerOnly = 5,
    BluetoothWithNoiseAndEchoCancellation = 6,
    BluetoothPreferred = 7,
};

enum class AvailableAudioRoutingEndpoints : unsigned
{
    None = 0x0,
    Earpiece = 0x1,
    Speakerphone = 0x2,
    Bluetooth = 0x4,
};

DEFINE_ENUM_FLAG_OPERATORS(AvailableAudioRoutingEndpoints)

}

}
