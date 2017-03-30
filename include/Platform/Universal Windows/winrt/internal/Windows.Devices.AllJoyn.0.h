// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::AllJoyn {

struct IAllJoynAboutData;
struct IAllJoynAboutDataView;
struct IAllJoynAboutDataViewStatics;
struct IAllJoynAcceptSessionJoiner;
struct IAllJoynAcceptSessionJoinerEventArgs;
struct IAllJoynAcceptSessionJoinerEventArgsFactory;
struct IAllJoynAuthenticationCompleteEventArgs;
struct IAllJoynBusAttachment;
struct IAllJoynBusAttachment2;
struct IAllJoynBusAttachmentFactory;
struct IAllJoynBusAttachmentStateChangedEventArgs;
struct IAllJoynBusAttachmentStatics;
struct IAllJoynBusObject;
struct IAllJoynBusObjectFactory;
struct IAllJoynBusObjectStoppedEventArgs;
struct IAllJoynBusObjectStoppedEventArgsFactory;
struct IAllJoynCredentials;
struct IAllJoynCredentialsRequestedEventArgs;
struct IAllJoynCredentialsVerificationRequestedEventArgs;
struct IAllJoynMessageInfo;
struct IAllJoynMessageInfoFactory;
struct IAllJoynProducer;
struct IAllJoynProducerStoppedEventArgs;
struct IAllJoynProducerStoppedEventArgsFactory;
struct IAllJoynServiceInfo;
struct IAllJoynServiceInfoFactory;
struct IAllJoynServiceInfoRemovedEventArgs;
struct IAllJoynServiceInfoRemovedEventArgsFactory;
struct IAllJoynServiceInfoStatics;
struct IAllJoynSession;
struct IAllJoynSessionJoinedEventArgs;
struct IAllJoynSessionJoinedEventArgsFactory;
struct IAllJoynSessionLostEventArgs;
struct IAllJoynSessionLostEventArgsFactory;
struct IAllJoynSessionMemberAddedEventArgs;
struct IAllJoynSessionMemberAddedEventArgsFactory;
struct IAllJoynSessionMemberRemovedEventArgs;
struct IAllJoynSessionMemberRemovedEventArgsFactory;
struct IAllJoynSessionStatics;
struct IAllJoynStatusStatics;
struct IAllJoynWatcherStoppedEventArgs;
struct IAllJoynWatcherStoppedEventArgsFactory;
struct AllJoynAboutData;
struct AllJoynAboutDataView;
struct AllJoynAcceptSessionJoinerEventArgs;
struct AllJoynAuthenticationCompleteEventArgs;
struct AllJoynBusAttachment;
struct AllJoynBusAttachmentStateChangedEventArgs;
struct AllJoynBusObject;
struct AllJoynBusObjectStoppedEventArgs;
struct AllJoynCredentials;
struct AllJoynCredentialsRequestedEventArgs;
struct AllJoynCredentialsVerificationRequestedEventArgs;
struct AllJoynMessageInfo;
struct AllJoynProducerStoppedEventArgs;
struct AllJoynServiceInfo;
struct AllJoynServiceInfoRemovedEventArgs;
struct AllJoynSession;
struct AllJoynSessionJoinedEventArgs;
struct AllJoynSessionLostEventArgs;
struct AllJoynSessionMemberAddedEventArgs;
struct AllJoynSessionMemberRemovedEventArgs;
struct AllJoynWatcherStoppedEventArgs;

}

namespace Windows::Devices::AllJoyn {

struct IAllJoynAboutData;
struct IAllJoynAboutDataView;
struct IAllJoynAboutDataViewStatics;
struct IAllJoynAcceptSessionJoiner;
struct IAllJoynAcceptSessionJoinerEventArgs;
struct IAllJoynAcceptSessionJoinerEventArgsFactory;
struct IAllJoynAuthenticationCompleteEventArgs;
struct IAllJoynBusAttachment;
struct IAllJoynBusAttachment2;
struct IAllJoynBusAttachmentFactory;
struct IAllJoynBusAttachmentStateChangedEventArgs;
struct IAllJoynBusAttachmentStatics;
struct IAllJoynBusObject;
struct IAllJoynBusObjectFactory;
struct IAllJoynBusObjectStoppedEventArgs;
struct IAllJoynBusObjectStoppedEventArgsFactory;
struct IAllJoynCredentials;
struct IAllJoynCredentialsRequestedEventArgs;
struct IAllJoynCredentialsVerificationRequestedEventArgs;
struct IAllJoynMessageInfo;
struct IAllJoynMessageInfoFactory;
struct IAllJoynProducer;
struct IAllJoynProducerStoppedEventArgs;
struct IAllJoynProducerStoppedEventArgsFactory;
struct IAllJoynServiceInfo;
struct IAllJoynServiceInfoFactory;
struct IAllJoynServiceInfoRemovedEventArgs;
struct IAllJoynServiceInfoRemovedEventArgsFactory;
struct IAllJoynServiceInfoStatics;
struct IAllJoynSession;
struct IAllJoynSessionJoinedEventArgs;
struct IAllJoynSessionJoinedEventArgsFactory;
struct IAllJoynSessionLostEventArgs;
struct IAllJoynSessionLostEventArgsFactory;
struct IAllJoynSessionMemberAddedEventArgs;
struct IAllJoynSessionMemberAddedEventArgsFactory;
struct IAllJoynSessionMemberRemovedEventArgs;
struct IAllJoynSessionMemberRemovedEventArgsFactory;
struct IAllJoynSessionStatics;
struct IAllJoynStatusStatics;
struct IAllJoynWatcherStoppedEventArgs;
struct IAllJoynWatcherStoppedEventArgsFactory;
struct AllJoynAboutData;
struct AllJoynAboutDataView;
struct AllJoynAcceptSessionJoinerEventArgs;
struct AllJoynAuthenticationCompleteEventArgs;
struct AllJoynBusAttachment;
struct AllJoynBusAttachmentStateChangedEventArgs;
struct AllJoynBusObject;
struct AllJoynBusObjectStoppedEventArgs;
struct AllJoynCredentials;
struct AllJoynCredentialsRequestedEventArgs;
struct AllJoynCredentialsVerificationRequestedEventArgs;
struct AllJoynMessageInfo;
struct AllJoynProducerStoppedEventArgs;
struct AllJoynServiceInfo;
struct AllJoynServiceInfoRemovedEventArgs;
struct AllJoynSession;
struct AllJoynSessionJoinedEventArgs;
struct AllJoynSessionLostEventArgs;
struct AllJoynSessionMemberAddedEventArgs;
struct AllJoynSessionMemberRemovedEventArgs;
struct AllJoynStatus;
struct AllJoynWatcherStoppedEventArgs;

}

namespace Windows::Devices::AllJoyn {

template <typename T> struct impl_IAllJoynAboutData;
template <typename T> struct impl_IAllJoynAboutDataView;
template <typename T> struct impl_IAllJoynAboutDataViewStatics;
template <typename T> struct impl_IAllJoynAcceptSessionJoiner;
template <typename T> struct impl_IAllJoynAcceptSessionJoinerEventArgs;
template <typename T> struct impl_IAllJoynAcceptSessionJoinerEventArgsFactory;
template <typename T> struct impl_IAllJoynAuthenticationCompleteEventArgs;
template <typename T> struct impl_IAllJoynBusAttachment;
template <typename T> struct impl_IAllJoynBusAttachment2;
template <typename T> struct impl_IAllJoynBusAttachmentFactory;
template <typename T> struct impl_IAllJoynBusAttachmentStateChangedEventArgs;
template <typename T> struct impl_IAllJoynBusAttachmentStatics;
template <typename T> struct impl_IAllJoynBusObject;
template <typename T> struct impl_IAllJoynBusObjectFactory;
template <typename T> struct impl_IAllJoynBusObjectStoppedEventArgs;
template <typename T> struct impl_IAllJoynBusObjectStoppedEventArgsFactory;
template <typename T> struct impl_IAllJoynCredentials;
template <typename T> struct impl_IAllJoynCredentialsRequestedEventArgs;
template <typename T> struct impl_IAllJoynCredentialsVerificationRequestedEventArgs;
template <typename T> struct impl_IAllJoynMessageInfo;
template <typename T> struct impl_IAllJoynMessageInfoFactory;
template <typename T> struct impl_IAllJoynProducer;
template <typename T> struct impl_IAllJoynProducerStoppedEventArgs;
template <typename T> struct impl_IAllJoynProducerStoppedEventArgsFactory;
template <typename T> struct impl_IAllJoynServiceInfo;
template <typename T> struct impl_IAllJoynServiceInfoFactory;
template <typename T> struct impl_IAllJoynServiceInfoRemovedEventArgs;
template <typename T> struct impl_IAllJoynServiceInfoRemovedEventArgsFactory;
template <typename T> struct impl_IAllJoynServiceInfoStatics;
template <typename T> struct impl_IAllJoynSession;
template <typename T> struct impl_IAllJoynSessionJoinedEventArgs;
template <typename T> struct impl_IAllJoynSessionJoinedEventArgsFactory;
template <typename T> struct impl_IAllJoynSessionLostEventArgs;
template <typename T> struct impl_IAllJoynSessionLostEventArgsFactory;
template <typename T> struct impl_IAllJoynSessionMemberAddedEventArgs;
template <typename T> struct impl_IAllJoynSessionMemberAddedEventArgsFactory;
template <typename T> struct impl_IAllJoynSessionMemberRemovedEventArgs;
template <typename T> struct impl_IAllJoynSessionMemberRemovedEventArgsFactory;
template <typename T> struct impl_IAllJoynSessionStatics;
template <typename T> struct impl_IAllJoynStatusStatics;
template <typename T> struct impl_IAllJoynWatcherStoppedEventArgs;
template <typename T> struct impl_IAllJoynWatcherStoppedEventArgsFactory;

}

namespace Windows::Devices::AllJoyn {

enum class AllJoynAuthenticationMechanism
{
    None = 0,
    SrpAnonymous [[deprecated("SrpAnonymous is deprecated and might not work on all platforms. For more info, see MSDN.")]] = 1,
    SrpLogon [[deprecated("SrpLogon is deprecated and might not work on all platforms. For more info, see MSDN.")]] = 2,
    EcdheNull = 3,
    EcdhePsk [[deprecated("EcdhePsk is deprecated and might not work on all platforms. For more info, see MSDN.")]] = 4,
    EcdheEcdsa = 5,
    EcdheSpeke = 6,
};

enum class AllJoynBusAttachmentState
{
    Disconnected = 0,
    Connecting = 1,
    Connected = 2,
    Disconnecting = 3,
};

enum class AllJoynSessionLostReason
{
    None = 0,
    ProducerLeftSession = 1,
    ProducerClosedAbruptly = 2,
    RemovedByProducer = 3,
    LinkTimeout = 4,
    Other = 5,
};

enum class AllJoynTrafficType
{
    Unknown = 0,
    Messages = 1,
    RawUnreliable = 2,
    RawReliable = 4,
};

}

}
