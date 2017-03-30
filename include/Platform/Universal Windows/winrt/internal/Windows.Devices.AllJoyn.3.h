// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.AllJoyn.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::AllJoyn {

struct WINRT_EBO AllJoynAboutData :
    Windows::Devices::AllJoyn::IAllJoynAboutData
{
    AllJoynAboutData(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AllJoynAboutDataView :
    Windows::Devices::AllJoyn::IAllJoynAboutDataView
{
    AllJoynAboutDataView(std::nullptr_t) noexcept {}
    static Windows::Foundation::IAsyncOperation<Windows::Devices::AllJoyn::AllJoynAboutDataView> GetDataBySessionPortAsync(hstring_view uniqueName, const Windows::Devices::AllJoyn::AllJoynBusAttachment & busAttachment, uint16_t sessionPort);
    static Windows::Foundation::IAsyncOperation<Windows::Devices::AllJoyn::AllJoynAboutDataView> GetDataBySessionPortAsync(hstring_view uniqueName, const Windows::Devices::AllJoyn::AllJoynBusAttachment & busAttachment, uint16_t sessionPort, const Windows::Globalization::Language & language);
};

struct WINRT_EBO AllJoynAcceptSessionJoinerEventArgs :
    Windows::Devices::AllJoyn::IAllJoynAcceptSessionJoinerEventArgs
{
    AllJoynAcceptSessionJoinerEventArgs(std::nullptr_t) noexcept {}
    AllJoynAcceptSessionJoinerEventArgs(hstring_view uniqueName, uint16_t sessionPort, Windows::Devices::AllJoyn::AllJoynTrafficType trafficType, uint8_t proximity, const Windows::Devices::AllJoyn::IAllJoynAcceptSessionJoiner & acceptSessionJoiner);
};

struct WINRT_EBO AllJoynAuthenticationCompleteEventArgs :
    Windows::Devices::AllJoyn::IAllJoynAuthenticationCompleteEventArgs
{
    AllJoynAuthenticationCompleteEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AllJoynBusAttachment :
    Windows::Devices::AllJoyn::IAllJoynBusAttachment,
    impl::require<AllJoynBusAttachment, Windows::Devices::AllJoyn::IAllJoynBusAttachment2>
{
    AllJoynBusAttachment(std::nullptr_t) noexcept {}
    AllJoynBusAttachment();
    AllJoynBusAttachment(hstring_view connectionSpecification);
    static Windows::Devices::AllJoyn::AllJoynBusAttachment GetDefault();
    static Windows::Devices::Enumeration::DeviceWatcher GetWatcher(iterable<hstring> requiredInterfaces);
};

struct WINRT_EBO AllJoynBusAttachmentStateChangedEventArgs :
    Windows::Devices::AllJoyn::IAllJoynBusAttachmentStateChangedEventArgs
{
    AllJoynBusAttachmentStateChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AllJoynBusObject :
    Windows::Devices::AllJoyn::IAllJoynBusObject
{
    AllJoynBusObject(std::nullptr_t) noexcept {}
    AllJoynBusObject();
    AllJoynBusObject(hstring_view objectPath);
    AllJoynBusObject(hstring_view objectPath, const Windows::Devices::AllJoyn::AllJoynBusAttachment & busAttachment);
};

struct WINRT_EBO AllJoynBusObjectStoppedEventArgs :
    Windows::Devices::AllJoyn::IAllJoynBusObjectStoppedEventArgs
{
    AllJoynBusObjectStoppedEventArgs(std::nullptr_t) noexcept {}
    AllJoynBusObjectStoppedEventArgs(int32_t status);
};

struct WINRT_EBO AllJoynCredentials :
    Windows::Devices::AllJoyn::IAllJoynCredentials
{
    AllJoynCredentials(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AllJoynCredentialsRequestedEventArgs :
    Windows::Devices::AllJoyn::IAllJoynCredentialsRequestedEventArgs
{
    AllJoynCredentialsRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AllJoynCredentialsVerificationRequestedEventArgs :
    Windows::Devices::AllJoyn::IAllJoynCredentialsVerificationRequestedEventArgs
{
    AllJoynCredentialsVerificationRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AllJoynMessageInfo :
    Windows::Devices::AllJoyn::IAllJoynMessageInfo
{
    AllJoynMessageInfo(std::nullptr_t) noexcept {}
    AllJoynMessageInfo(hstring_view senderUniqueName);
};

struct WINRT_EBO AllJoynProducerStoppedEventArgs :
    Windows::Devices::AllJoyn::IAllJoynProducerStoppedEventArgs
{
    AllJoynProducerStoppedEventArgs(std::nullptr_t) noexcept {}
    AllJoynProducerStoppedEventArgs(int32_t status);
};

struct WINRT_EBO AllJoynServiceInfo :
    Windows::Devices::AllJoyn::IAllJoynServiceInfo
{
    AllJoynServiceInfo(std::nullptr_t) noexcept {}
    AllJoynServiceInfo(hstring_view uniqueName, hstring_view objectPath, uint16_t sessionPort);
    static Windows::Foundation::IAsyncOperation<Windows::Devices::AllJoyn::AllJoynServiceInfo> FromIdAsync(hstring_view deviceId);
};

struct WINRT_EBO AllJoynServiceInfoRemovedEventArgs :
    Windows::Devices::AllJoyn::IAllJoynServiceInfoRemovedEventArgs
{
    AllJoynServiceInfoRemovedEventArgs(std::nullptr_t) noexcept {}
    AllJoynServiceInfoRemovedEventArgs(hstring_view uniqueName);
};

struct WINRT_EBO AllJoynSession :
    Windows::Devices::AllJoyn::IAllJoynSession
{
    AllJoynSession(std::nullptr_t) noexcept {}
    static Windows::Foundation::IAsyncOperation<Windows::Devices::AllJoyn::AllJoynSession> GetFromServiceInfoAsync(const Windows::Devices::AllJoyn::AllJoynServiceInfo & serviceInfo);
    static Windows::Foundation::IAsyncOperation<Windows::Devices::AllJoyn::AllJoynSession> GetFromServiceInfoAsync(const Windows::Devices::AllJoyn::AllJoynServiceInfo & serviceInfo, const Windows::Devices::AllJoyn::AllJoynBusAttachment & busAttachment);
};

struct WINRT_EBO AllJoynSessionJoinedEventArgs :
    Windows::Devices::AllJoyn::IAllJoynSessionJoinedEventArgs
{
    AllJoynSessionJoinedEventArgs(std::nullptr_t) noexcept {}
    AllJoynSessionJoinedEventArgs(const Windows::Devices::AllJoyn::AllJoynSession & session);
};

struct WINRT_EBO AllJoynSessionLostEventArgs :
    Windows::Devices::AllJoyn::IAllJoynSessionLostEventArgs
{
    AllJoynSessionLostEventArgs(std::nullptr_t) noexcept {}
    AllJoynSessionLostEventArgs(Windows::Devices::AllJoyn::AllJoynSessionLostReason reason);
};

struct WINRT_EBO AllJoynSessionMemberAddedEventArgs :
    Windows::Devices::AllJoyn::IAllJoynSessionMemberAddedEventArgs
{
    AllJoynSessionMemberAddedEventArgs(std::nullptr_t) noexcept {}
    AllJoynSessionMemberAddedEventArgs(hstring_view uniqueName);
};

struct WINRT_EBO AllJoynSessionMemberRemovedEventArgs :
    Windows::Devices::AllJoyn::IAllJoynSessionMemberRemovedEventArgs
{
    AllJoynSessionMemberRemovedEventArgs(std::nullptr_t) noexcept {}
    AllJoynSessionMemberRemovedEventArgs(hstring_view uniqueName);
};

struct AllJoynStatus
{
    AllJoynStatus() = delete;
    static int32_t Ok();
    static int32_t Fail();
    static int32_t OperationTimedOut();
    static int32_t OtherEndClosed();
    static int32_t ConnectionRefused();
    static int32_t AuthenticationFailed();
    static int32_t AuthenticationRejectedByUser();
    static int32_t SslConnectFailed();
    static int32_t SslIdentityVerificationFailed();
    static int32_t InsufficientSecurity();
    static int32_t InvalidArgument1();
    static int32_t InvalidArgument2();
    static int32_t InvalidArgument3();
    static int32_t InvalidArgument4();
    static int32_t InvalidArgument5();
    static int32_t InvalidArgument6();
    static int32_t InvalidArgument7();
    static int32_t InvalidArgument8();
};

struct WINRT_EBO AllJoynWatcherStoppedEventArgs :
    Windows::Devices::AllJoyn::IAllJoynWatcherStoppedEventArgs
{
    AllJoynWatcherStoppedEventArgs(std::nullptr_t) noexcept {}
    AllJoynWatcherStoppedEventArgs(int32_t status);
};

}

}
