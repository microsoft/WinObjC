// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::SerialCommunication {

struct IErrorReceivedEventArgs;
struct IPinChangedEventArgs;
struct ISerialDevice;
struct ISerialDeviceStatics;
struct ErrorReceivedEventArgs;
struct PinChangedEventArgs;
struct SerialDevice;

}

namespace Windows::Devices::SerialCommunication {

struct IErrorReceivedEventArgs;
struct IPinChangedEventArgs;
struct ISerialDevice;
struct ISerialDeviceStatics;
struct ErrorReceivedEventArgs;
struct PinChangedEventArgs;
struct SerialDevice;

}

namespace Windows::Devices::SerialCommunication {

template <typename T> struct impl_IErrorReceivedEventArgs;
template <typename T> struct impl_IPinChangedEventArgs;
template <typename T> struct impl_ISerialDevice;
template <typename T> struct impl_ISerialDeviceStatics;

}

namespace Windows::Devices::SerialCommunication {

enum class SerialError
{
    Frame = 0,
    BufferOverrun = 1,
    ReceiveFull = 2,
    ReceiveParity = 3,
    TransmitFull = 4,
};

enum class SerialHandshake
{
    None = 0,
    RequestToSend = 1,
    XOnXOff = 2,
    RequestToSendXOnXOff = 3,
};

enum class SerialParity
{
    None = 0,
    Odd = 1,
    Even = 2,
    Mark = 3,
    Space = 4,
};

enum class SerialPinChange
{
    BreakSignal = 0,
    CarrierDetect = 1,
    ClearToSend = 2,
    DataSetReady = 3,
    RingIndicator = 4,
};

enum class SerialStopBitCount
{
    One = 0,
    OnePointFive = 1,
    Two = 2,
};

}

}
