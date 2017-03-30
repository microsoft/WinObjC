// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::Protection {

struct ComponentLoadFailedEventHandler;
struct IComponentLoadFailedEventArgs;
struct IComponentRenewalStatics;
struct IHdcpSession;
struct IMediaProtectionManager;
struct IMediaProtectionPMPServer;
struct IMediaProtectionPMPServerFactory;
struct IMediaProtectionServiceCompletion;
struct IMediaProtectionServiceRequest;
struct IProtectionCapabilities;
struct IRevocationAndRenewalInformation;
struct IRevocationAndRenewalItem;
struct IServiceRequestedEventArgs;
struct IServiceRequestedEventArgs2;
struct RebootNeededEventHandler;
struct ServiceRequestedEventHandler;
struct ComponentLoadFailedEventArgs;
struct HdcpSession;
struct MediaProtectionManager;
struct MediaProtectionPMPServer;
struct MediaProtectionServiceCompletion;
struct ProtectionCapabilities;
struct RevocationAndRenewalInformation;
struct RevocationAndRenewalItem;
struct ServiceRequestedEventArgs;

}

namespace Windows::Media::Protection {

struct ComponentLoadFailedEventHandler;
struct RebootNeededEventHandler;
struct ServiceRequestedEventHandler;
struct IComponentLoadFailedEventArgs;
struct IComponentRenewalStatics;
struct IHdcpSession;
struct IMediaProtectionManager;
struct IMediaProtectionPMPServer;
struct IMediaProtectionPMPServerFactory;
struct IMediaProtectionServiceCompletion;
struct IMediaProtectionServiceRequest;
struct IProtectionCapabilities;
struct IRevocationAndRenewalInformation;
struct IRevocationAndRenewalItem;
struct IServiceRequestedEventArgs;
struct IServiceRequestedEventArgs2;
struct ComponentLoadFailedEventArgs;
struct ComponentRenewal;
struct HdcpSession;
struct MediaProtectionManager;
struct MediaProtectionPMPServer;
struct MediaProtectionServiceCompletion;
struct ProtectionCapabilities;
struct RevocationAndRenewalInformation;
struct RevocationAndRenewalItem;
struct ServiceRequestedEventArgs;

}

namespace Windows::Media::Protection {

template <typename T> struct impl_IComponentLoadFailedEventArgs;
template <typename T> struct impl_IComponentRenewalStatics;
template <typename T> struct impl_IHdcpSession;
template <typename T> struct impl_IMediaProtectionManager;
template <typename T> struct impl_IMediaProtectionPMPServer;
template <typename T> struct impl_IMediaProtectionPMPServerFactory;
template <typename T> struct impl_IMediaProtectionServiceCompletion;
template <typename T> struct impl_IMediaProtectionServiceRequest;
template <typename T> struct impl_IProtectionCapabilities;
template <typename T> struct impl_IRevocationAndRenewalInformation;
template <typename T> struct impl_IRevocationAndRenewalItem;
template <typename T> struct impl_IServiceRequestedEventArgs;
template <typename T> struct impl_IServiceRequestedEventArgs2;
template <typename T> struct impl_ComponentLoadFailedEventHandler;
template <typename T> struct impl_RebootNeededEventHandler;
template <typename T> struct impl_ServiceRequestedEventHandler;

}

namespace Windows::Media::Protection {

enum class GraphicsTrustStatus
{
    TrustNotRequired = 0,
    TrustEstablished = 1,
    EnvironmentNotSupported = 2,
    DriverNotSupported = 3,
    DriverSigningFailure = 4,
    UnknownFailure = 5,
};

enum class HdcpProtection
{
    Off = 0,
    On = 1,
    OnWithTypeEnforcement = 2,
};

enum class HdcpSetProtectionResult
{
    Success = 0,
    TimedOut = 1,
    NotSupported = 2,
    UnknownFailure = 3,
};

enum class ProtectionCapabilityResult
{
    NotSupported = 0,
    Maybe = 1,
    Probably = 2,
};

enum class RenewalStatus
{
    NotStarted = 0,
    UpdatesInProgress = 1,
    UserCancelled = 2,
    AppComponentsMayNeedUpdating = 3,
    NoComponentsFound = 4,
};

enum class RevocationAndRenewalReasons : unsigned
{
    UserModeComponentLoad = 0x1,
    KernelModeComponentLoad = 0x2,
    AppComponent = 0x4,
    GlobalRevocationListLoadFailed = 0x10,
    InvalidGlobalRevocationListSignature = 0x20,
    GlobalRevocationListAbsent = 0x1000,
    ComponentRevoked = 0x2000,
    InvalidComponentCertificateExtendedKeyUse = 0x4000,
    ComponentCertificateRevoked = 0x8000,
    InvalidComponentCertificateRoot = 0x10000,
    ComponentHighSecurityCertificateRevoked = 0x20000,
    ComponentLowSecurityCertificateRevoked = 0x40000,
    BootDriverVerificationFailed = 0x100000,
    ComponentSignedWithTestCertificate = 0x1000000,
    EncryptionFailure = 0x10000000,
};

DEFINE_ENUM_FLAG_OPERATORS(RevocationAndRenewalReasons)

}

}
