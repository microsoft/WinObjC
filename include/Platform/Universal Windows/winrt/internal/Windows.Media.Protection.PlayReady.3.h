// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Media.Protection.PlayReady.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Media::Protection::PlayReady {

struct WINRT_EBO NDClient :
    Windows::Media::Protection::PlayReady::INDClient
{
    NDClient(std::nullptr_t) noexcept {}
    NDClient(const Windows::Media::Protection::PlayReady::INDDownloadEngine & downloadEngine, const Windows::Media::Protection::PlayReady::INDStreamParser & streamParser, const Windows::Media::Protection::PlayReady::INDMessenger & pMessenger);
};

struct WINRT_EBO NDCustomData :
    Windows::Media::Protection::PlayReady::INDCustomData
{
    NDCustomData(std::nullptr_t) noexcept {}
    NDCustomData(array_view<const uint8_t> customDataTypeIDBytes, array_view<const uint8_t> customDataBytes);
};

struct WINRT_EBO NDDownloadEngineNotifier :
    Windows::Media::Protection::PlayReady::INDDownloadEngineNotifier
{
    NDDownloadEngineNotifier(std::nullptr_t) noexcept {}
    NDDownloadEngineNotifier();
};

struct WINRT_EBO NDLicenseFetchDescriptor :
    Windows::Media::Protection::PlayReady::INDLicenseFetchDescriptor
{
    NDLicenseFetchDescriptor(std::nullptr_t) noexcept {}
    NDLicenseFetchDescriptor(Windows::Media::Protection::PlayReady::NDContentIDType contentIDType, array_view<const uint8_t> contentIDBytes, const Windows::Media::Protection::PlayReady::INDCustomData & licenseFetchChallengeCustomData);
};

struct WINRT_EBO NDStorageFileHelper :
    Windows::Media::Protection::PlayReady::INDStorageFileHelper
{
    NDStorageFileHelper(std::nullptr_t) noexcept {}
    NDStorageFileHelper();
};

struct WINRT_EBO NDStreamParserNotifier :
    Windows::Media::Protection::PlayReady::INDStreamParserNotifier
{
    NDStreamParserNotifier(std::nullptr_t) noexcept {}
    NDStreamParserNotifier();
};

struct WINRT_EBO NDTCPMessenger :
    Windows::Media::Protection::PlayReady::INDMessenger
{
    NDTCPMessenger(std::nullptr_t) noexcept {}
    NDTCPMessenger(hstring_view remoteHostName, uint32_t remoteHostPort);
};

struct WINRT_EBO PlayReadyContentHeader :
    Windows::Media::Protection::PlayReady::IPlayReadyContentHeader,
    impl::require<PlayReadyContentHeader, Windows::Media::Protection::PlayReady::IPlayReadyContentHeader2>
{
    PlayReadyContentHeader(std::nullptr_t) noexcept {}
    PlayReadyContentHeader(array_view<const uint8_t> headerBytes, const Windows::Foundation::Uri & licenseAcquisitionUrl, const Windows::Foundation::Uri & licenseAcquisitionUserInterfaceUrl, hstring_view customAttributes, GUID domainServiceId);
    PlayReadyContentHeader(GUID contentKeyId, hstring_view contentKeyIdString, Windows::Media::Protection::PlayReady::PlayReadyEncryptionAlgorithm contentEncryptionAlgorithm, const Windows::Foundation::Uri & licenseAcquisitionUrl, const Windows::Foundation::Uri & licenseAcquisitionUserInterfaceUrl, hstring_view customAttributes, GUID domainServiceId);
    PlayReadyContentHeader(array_view<const uint8_t> headerBytes);
    PlayReadyContentHeader(uint32_t dwFlags, array_view<const GUID> contentKeyIds, array_view<const hstring> contentKeyIdStrings, Windows::Media::Protection::PlayReady::PlayReadyEncryptionAlgorithm contentEncryptionAlgorithm, const Windows::Foundation::Uri & licenseAcquisitionUrl, const Windows::Foundation::Uri & licenseAcquisitionUserInterfaceUrl, hstring_view customAttributes, GUID domainServiceId);
};

struct PlayReadyContentResolver
{
    PlayReadyContentResolver() = delete;
    static Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest ServiceRequest(const Windows::Media::Protection::PlayReady::PlayReadyContentHeader & contentHeader);
};

struct WINRT_EBO PlayReadyDomain :
    Windows::Media::Protection::PlayReady::IPlayReadyDomain
{
    PlayReadyDomain(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PlayReadyDomainIterable :
    Windows::Foundation::Collections::IIterable<Windows::Media::Protection::PlayReady::IPlayReadyDomain>
{
    PlayReadyDomainIterable(std::nullptr_t) noexcept {}
    PlayReadyDomainIterable(GUID domainAccountId);
};

struct WINRT_EBO PlayReadyDomainIterator :
    Windows::Foundation::Collections::IIterator<Windows::Media::Protection::PlayReady::IPlayReadyDomain>
{
    PlayReadyDomainIterator(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PlayReadyDomainJoinServiceRequest :
    Windows::Media::Protection::PlayReady::IPlayReadyDomainJoinServiceRequest
{
    PlayReadyDomainJoinServiceRequest(std::nullptr_t) noexcept {}
    PlayReadyDomainJoinServiceRequest();
};

struct WINRT_EBO PlayReadyDomainLeaveServiceRequest :
    Windows::Media::Protection::PlayReady::IPlayReadyDomainLeaveServiceRequest
{
    PlayReadyDomainLeaveServiceRequest(std::nullptr_t) noexcept {}
    PlayReadyDomainLeaveServiceRequest();
};

struct WINRT_EBO PlayReadyITADataGenerator :
    Windows::Media::Protection::PlayReady::IPlayReadyITADataGenerator
{
    PlayReadyITADataGenerator(std::nullptr_t) noexcept {}
    PlayReadyITADataGenerator();
};

struct WINRT_EBO PlayReadyIndividualizationServiceRequest :
    Windows::Media::Protection::PlayReady::IPlayReadyIndividualizationServiceRequest
{
    PlayReadyIndividualizationServiceRequest(std::nullptr_t) noexcept {}
    PlayReadyIndividualizationServiceRequest();
};

struct WINRT_EBO PlayReadyLicense :
    Windows::Media::Protection::PlayReady::IPlayReadyLicense
{
    PlayReadyLicense(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PlayReadyLicenseAcquisitionServiceRequest :
    Windows::Media::Protection::PlayReady::IPlayReadyLicenseAcquisitionServiceRequest,
    impl::require<PlayReadyLicenseAcquisitionServiceRequest, Windows::Media::Protection::PlayReady::IPlayReadyLicenseAcquisitionServiceRequest2>
{
    PlayReadyLicenseAcquisitionServiceRequest(std::nullptr_t) noexcept {}
    PlayReadyLicenseAcquisitionServiceRequest();
};

struct WINRT_EBO PlayReadyLicenseIterable :
    Windows::Foundation::Collections::IIterable<Windows::Media::Protection::PlayReady::IPlayReadyLicense>
{
    PlayReadyLicenseIterable(std::nullptr_t) noexcept {}
    PlayReadyLicenseIterable();
    PlayReadyLicenseIterable(const Windows::Media::Protection::PlayReady::PlayReadyContentHeader & contentHeader, bool fullyEvaluated);
};

struct WINRT_EBO PlayReadyLicenseIterator :
    Windows::Foundation::Collections::IIterator<Windows::Media::Protection::PlayReady::IPlayReadyLicense>
{
    PlayReadyLicenseIterator(std::nullptr_t) noexcept {}
};

struct PlayReadyLicenseManagement
{
    PlayReadyLicenseManagement() = delete;
    static Windows::Foundation::IAsyncAction DeleteLicenses(const Windows::Media::Protection::PlayReady::PlayReadyContentHeader & contentHeader);
};

struct WINRT_EBO PlayReadyLicenseSession :
    Windows::Media::Protection::PlayReady::IPlayReadyLicenseSession
{
    PlayReadyLicenseSession(std::nullptr_t) noexcept {}
    PlayReadyLicenseSession(const Windows::Foundation::Collections::IPropertySet & configuration);
};

struct WINRT_EBO PlayReadyMeteringReportServiceRequest :
    Windows::Media::Protection::PlayReady::IPlayReadyMeteringReportServiceRequest
{
    PlayReadyMeteringReportServiceRequest(std::nullptr_t) noexcept {}
    PlayReadyMeteringReportServiceRequest();
};

struct WINRT_EBO PlayReadyRevocationServiceRequest :
    Windows::Media::Protection::PlayReady::IPlayReadyRevocationServiceRequest
{
    PlayReadyRevocationServiceRequest(std::nullptr_t) noexcept {}
    PlayReadyRevocationServiceRequest();
};

struct WINRT_EBO PlayReadySecureStopIterable :
    Windows::Foundation::Collections::IIterable<Windows::Media::Protection::PlayReady::IPlayReadySecureStopServiceRequest>
{
    PlayReadySecureStopIterable(std::nullptr_t) noexcept {}
    PlayReadySecureStopIterable(array_view<const uint8_t> publisherCertBytes);
};

struct WINRT_EBO PlayReadySecureStopIterator :
    Windows::Foundation::Collections::IIterator<Windows::Media::Protection::PlayReady::IPlayReadySecureStopServiceRequest>
{
    PlayReadySecureStopIterator(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PlayReadySecureStopServiceRequest :
    Windows::Media::Protection::PlayReady::IPlayReadySecureStopServiceRequest
{
    PlayReadySecureStopServiceRequest(std::nullptr_t) noexcept {}
    PlayReadySecureStopServiceRequest(array_view<const uint8_t> publisherCertBytes);
    PlayReadySecureStopServiceRequest(GUID sessionID, array_view<const uint8_t> publisherCertBytes);
};

struct WINRT_EBO PlayReadySoapMessage :
    Windows::Media::Protection::PlayReady::IPlayReadySoapMessage
{
    PlayReadySoapMessage(std::nullptr_t) noexcept {}
};

struct PlayReadyStatics
{
    PlayReadyStatics() = delete;
    static GUID DomainJoinServiceRequestType();
    static GUID DomainLeaveServiceRequestType();
    static GUID IndividualizationServiceRequestType();
    static GUID LicenseAcquirerServiceRequestType();
    static GUID MeteringReportServiceRequestType();
    static GUID RevocationServiceRequestType();
    static GUID MediaProtectionSystemId();
    static uint32_t PlayReadySecurityVersion();
    static uint32_t PlayReadyCertificateSecurityLevel();
    static GUID SecureStopServiceRequestType();
    static bool CheckSupportedHardware(Windows::Media::Protection::PlayReady::PlayReadyHardwareDRMFeatures hwdrmFeature);
    static hstring InputTrustAuthorityToCreate();
    static GUID ProtectionSystemId();
};

}

}
