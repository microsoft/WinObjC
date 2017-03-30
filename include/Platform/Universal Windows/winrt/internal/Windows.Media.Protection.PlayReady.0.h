// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::Protection::PlayReady {

struct INDClient;
struct INDClientFactory;
struct INDClosedCaptionDataReceivedEventArgs;
struct INDCustomData;
struct INDCustomDataFactory;
struct INDDownloadEngine;
struct INDDownloadEngineNotifier;
struct INDLicenseFetchCompletedEventArgs;
struct INDLicenseFetchDescriptor;
struct INDLicenseFetchDescriptorFactory;
struct INDLicenseFetchResult;
struct INDMessenger;
struct INDProximityDetectionCompletedEventArgs;
struct INDRegistrationCompletedEventArgs;
struct INDSendResult;
struct INDStartResult;
struct INDStorageFileHelper;
struct INDStreamParser;
struct INDStreamParserNotifier;
struct INDTCPMessengerFactory;
struct INDTransmitterProperties;
struct IPlayReadyContentHeader;
struct IPlayReadyContentHeader2;
struct IPlayReadyContentHeaderFactory;
struct IPlayReadyContentHeaderFactory2;
struct IPlayReadyContentResolver;
struct IPlayReadyDomain;
struct IPlayReadyDomainIterableFactory;
struct IPlayReadyDomainJoinServiceRequest;
struct IPlayReadyDomainLeaveServiceRequest;
struct IPlayReadyITADataGenerator;
struct IPlayReadyIndividualizationServiceRequest;
struct IPlayReadyLicense;
struct IPlayReadyLicenseAcquisitionServiceRequest;
struct IPlayReadyLicenseAcquisitionServiceRequest2;
struct IPlayReadyLicenseIterableFactory;
struct IPlayReadyLicenseManagement;
struct IPlayReadyLicenseSession;
struct IPlayReadyLicenseSessionFactory;
struct IPlayReadyMeteringReportServiceRequest;
struct IPlayReadyRevocationServiceRequest;
struct IPlayReadySecureStopIterableFactory;
struct IPlayReadySecureStopServiceRequest;
struct IPlayReadySecureStopServiceRequestFactory;
struct IPlayReadyServiceRequest;
struct IPlayReadySoapMessage;
struct IPlayReadyStatics;
struct IPlayReadyStatics2;
struct IPlayReadyStatics3;
struct IPlayReadyStatics4;
struct NDClient;
struct NDCustomData;
struct NDDownloadEngineNotifier;
struct NDLicenseFetchDescriptor;
struct NDStorageFileHelper;
struct NDStreamParserNotifier;
struct NDTCPMessenger;
struct PlayReadyContentHeader;
struct PlayReadyDomain;
struct PlayReadyDomainIterable;
struct PlayReadyDomainIterator;
struct PlayReadyDomainJoinServiceRequest;
struct PlayReadyDomainLeaveServiceRequest;
struct PlayReadyITADataGenerator;
struct PlayReadyIndividualizationServiceRequest;
struct PlayReadyLicense;
struct PlayReadyLicenseAcquisitionServiceRequest;
struct PlayReadyLicenseIterable;
struct PlayReadyLicenseIterator;
struct PlayReadyLicenseSession;
struct PlayReadyMeteringReportServiceRequest;
struct PlayReadyRevocationServiceRequest;
struct PlayReadySecureStopIterable;
struct PlayReadySecureStopIterator;
struct PlayReadySecureStopServiceRequest;
struct PlayReadySoapMessage;

}

namespace Windows::Media::Protection::PlayReady {

struct INDClient;
struct INDClientFactory;
struct INDClosedCaptionDataReceivedEventArgs;
struct INDCustomData;
struct INDCustomDataFactory;
struct INDDownloadEngine;
struct INDDownloadEngineNotifier;
struct INDLicenseFetchCompletedEventArgs;
struct INDLicenseFetchDescriptor;
struct INDLicenseFetchDescriptorFactory;
struct INDLicenseFetchResult;
struct INDMessenger;
struct INDProximityDetectionCompletedEventArgs;
struct INDRegistrationCompletedEventArgs;
struct INDSendResult;
struct INDStartResult;
struct INDStorageFileHelper;
struct INDStreamParser;
struct INDStreamParserNotifier;
struct INDTCPMessengerFactory;
struct INDTransmitterProperties;
struct IPlayReadyContentHeader;
struct IPlayReadyContentHeader2;
struct IPlayReadyContentHeaderFactory;
struct IPlayReadyContentHeaderFactory2;
struct IPlayReadyContentResolver;
struct IPlayReadyDomain;
struct IPlayReadyDomainIterableFactory;
struct IPlayReadyDomainJoinServiceRequest;
struct IPlayReadyDomainLeaveServiceRequest;
struct IPlayReadyITADataGenerator;
struct IPlayReadyIndividualizationServiceRequest;
struct IPlayReadyLicense;
struct IPlayReadyLicenseAcquisitionServiceRequest;
struct IPlayReadyLicenseAcquisitionServiceRequest2;
struct IPlayReadyLicenseIterableFactory;
struct IPlayReadyLicenseManagement;
struct IPlayReadyLicenseSession;
struct IPlayReadyLicenseSessionFactory;
struct IPlayReadyMeteringReportServiceRequest;
struct IPlayReadyRevocationServiceRequest;
struct IPlayReadySecureStopIterableFactory;
struct IPlayReadySecureStopServiceRequest;
struct IPlayReadySecureStopServiceRequestFactory;
struct IPlayReadyServiceRequest;
struct IPlayReadySoapMessage;
struct IPlayReadyStatics;
struct IPlayReadyStatics2;
struct IPlayReadyStatics3;
struct IPlayReadyStatics4;
struct NDClient;
struct NDCustomData;
struct NDDownloadEngineNotifier;
struct NDLicenseFetchDescriptor;
struct NDStorageFileHelper;
struct NDStreamParserNotifier;
struct NDTCPMessenger;
struct PlayReadyContentHeader;
struct PlayReadyContentResolver;
struct PlayReadyDomain;
struct PlayReadyDomainIterable;
struct PlayReadyDomainIterator;
struct PlayReadyDomainJoinServiceRequest;
struct PlayReadyDomainLeaveServiceRequest;
struct PlayReadyITADataGenerator;
struct PlayReadyIndividualizationServiceRequest;
struct PlayReadyLicense;
struct PlayReadyLicenseAcquisitionServiceRequest;
struct PlayReadyLicenseIterable;
struct PlayReadyLicenseIterator;
struct PlayReadyLicenseManagement;
struct PlayReadyLicenseSession;
struct PlayReadyMeteringReportServiceRequest;
struct PlayReadyRevocationServiceRequest;
struct PlayReadySecureStopIterable;
struct PlayReadySecureStopIterator;
struct PlayReadySecureStopServiceRequest;
struct PlayReadySoapMessage;
struct PlayReadyStatics;

}

namespace Windows::Media::Protection::PlayReady {

template <typename T> struct impl_INDClient;
template <typename T> struct impl_INDClientFactory;
template <typename T> struct impl_INDClosedCaptionDataReceivedEventArgs;
template <typename T> struct impl_INDCustomData;
template <typename T> struct impl_INDCustomDataFactory;
template <typename T> struct impl_INDDownloadEngine;
template <typename T> struct impl_INDDownloadEngineNotifier;
template <typename T> struct impl_INDLicenseFetchCompletedEventArgs;
template <typename T> struct impl_INDLicenseFetchDescriptor;
template <typename T> struct impl_INDLicenseFetchDescriptorFactory;
template <typename T> struct impl_INDLicenseFetchResult;
template <typename T> struct impl_INDMessenger;
template <typename T> struct impl_INDProximityDetectionCompletedEventArgs;
template <typename T> struct impl_INDRegistrationCompletedEventArgs;
template <typename T> struct impl_INDSendResult;
template <typename T> struct impl_INDStartResult;
template <typename T> struct impl_INDStorageFileHelper;
template <typename T> struct impl_INDStreamParser;
template <typename T> struct impl_INDStreamParserNotifier;
template <typename T> struct impl_INDTCPMessengerFactory;
template <typename T> struct impl_INDTransmitterProperties;
template <typename T> struct impl_IPlayReadyContentHeader;
template <typename T> struct impl_IPlayReadyContentHeader2;
template <typename T> struct impl_IPlayReadyContentHeaderFactory;
template <typename T> struct impl_IPlayReadyContentHeaderFactory2;
template <typename T> struct impl_IPlayReadyContentResolver;
template <typename T> struct impl_IPlayReadyDomain;
template <typename T> struct impl_IPlayReadyDomainIterableFactory;
template <typename T> struct impl_IPlayReadyDomainJoinServiceRequest;
template <typename T> struct impl_IPlayReadyDomainLeaveServiceRequest;
template <typename T> struct impl_IPlayReadyITADataGenerator;
template <typename T> struct impl_IPlayReadyIndividualizationServiceRequest;
template <typename T> struct impl_IPlayReadyLicense;
template <typename T> struct impl_IPlayReadyLicenseAcquisitionServiceRequest;
template <typename T> struct impl_IPlayReadyLicenseAcquisitionServiceRequest2;
template <typename T> struct impl_IPlayReadyLicenseIterableFactory;
template <typename T> struct impl_IPlayReadyLicenseManagement;
template <typename T> struct impl_IPlayReadyLicenseSession;
template <typename T> struct impl_IPlayReadyLicenseSessionFactory;
template <typename T> struct impl_IPlayReadyMeteringReportServiceRequest;
template <typename T> struct impl_IPlayReadyRevocationServiceRequest;
template <typename T> struct impl_IPlayReadySecureStopIterableFactory;
template <typename T> struct impl_IPlayReadySecureStopServiceRequest;
template <typename T> struct impl_IPlayReadySecureStopServiceRequestFactory;
template <typename T> struct impl_IPlayReadyServiceRequest;
template <typename T> struct impl_IPlayReadySoapMessage;
template <typename T> struct impl_IPlayReadyStatics;
template <typename T> struct impl_IPlayReadyStatics2;
template <typename T> struct impl_IPlayReadyStatics3;
template <typename T> struct impl_IPlayReadyStatics4;

}

namespace Windows::Media::Protection::PlayReady {

enum class NDCertificateFeature
{
    Transmitter = 1,
    Receiver = 2,
    SharedCertificate = 3,
    SecureClock = 4,
    AntiRollBackClock = 5,
    CRLS = 9,
    PlayReady3Features = 13,
};

enum class NDCertificatePlatformID
{
    Windows = 0,
    OSX = 1,
    WindowsOnARM = 2,
    WindowsMobile7 = 5,
    iOSOnARM = 6,
    XBoxOnPPC = 7,
    WindowsPhone8OnARM = 8,
    WindowsPhone8OnX86 = 9,
    XboxOne = 10,
    AndroidOnARM = 11,
    WindowsPhone81OnARM = 12,
    WindowsPhone81OnX86 = 13,
};

enum class NDCertificateType
{
    Unknown = 0,
    PC = 1,
    Device = 2,
    Domain = 3,
    Issuer = 4,
    CrlSigner = 5,
    Service = 6,
    Silverlight = 7,
    Application = 8,
    Metering = 9,
    KeyFileSigner = 10,
    Server = 11,
    LicenseSigner = 12,
};

enum class NDClosedCaptionFormat
{
    ATSC = 0,
    SCTE20 = 1,
    Unknown = 2,
};

enum class NDContentIDType
{
    KeyID = 1,
    PlayReadyObject = 2,
    Custom = 3,
};

enum class NDMediaStreamType
{
    Audio = 1,
    Video = 2,
};

enum class NDProximityDetectionType
{
    UDP = 1,
    TCP = 2,
    TransportAgnostic = 4,
};

enum class NDStartAsyncOptions
{
    MutualAuthentication = 1,
    WaitForLicenseDescriptor = 2,
};

enum class PlayReadyDecryptorSetup
{
    Uninitialized = 0,
    OnDemand = 1,
};

enum class PlayReadyEncryptionAlgorithm
{
    Unprotected = 0,
    Aes128Ctr = 1,
    Cocktail = 4,
    Uninitialized = 2147483647,
};

enum class PlayReadyHardwareDRMFeatures
{
    HardwareDRM = 1,
    HEVC = 2,
};

enum class PlayReadyITADataFormat
{
    SerializedProperties = 0,
    SerializedProperties_WithContentProtectionWrapper = 1,
};

}

}
