//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

// WindowsMediaProtectionPlayReady.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WMPPPlayReadyContentHeader, WMPPPlayReadySoapMessage, WMPPPlayReadyContentResolver, WMPPPlayReadyIndividualizationServiceRequest,
    WMPPPlayReadyDomainJoinServiceRequest, WMPPPlayReadyDomainLeaveServiceRequest, WMPPPlayReadyLicenseAcquisitionServiceRequest,
    WMPPPlayReadyMeteringReportServiceRequest, WMPPPlayReadyRevocationServiceRequest, WMPPPlayReadyLicenseManagement, WMPPPlayReadyLicense,
    WMPPPlayReadyLicenseIterable, WMPPPlayReadyLicenseIterator, WMPPPlayReadyDomain, WMPPPlayReadyDomainIterable,
    WMPPPlayReadyDomainIterator, WMPPPlayReadyStatics, WMPPPlayReadySecureStopServiceRequest, WMPPPlayReadySecureStopIterable,
    WMPPPlayReadySecureStopIterator, WMPPPlayReadyITADataGenerator, WMPPPlayReadyLicenseSession, WMPPNDDownloadEngineNotifier,
    WMPPNDStreamParserNotifier, WMPPNDTCPMessenger, WMPPNDLicenseFetchDescriptor, WMPPNDCustomData, WMPPNDClient, WMPPNDStorageFileHelper;
@protocol WMPPIPlayReadyContentHeader
, WMPPIPlayReadyContentHeaderFactory, WMPPIPlayReadyContentHeader2, WMPPIPlayReadyContentHeaderFactory2, WMPPIPlayReadyContentResolver,
    WMPPIPlayReadyLicenseManagement, WMPPIPlayReadyLicense, WMPPIPlayReadyLicenseIterableFactory, WMPPIPlayReadyDomain,
    WMPPIPlayReadyDomainIterableFactory, WMPPIPlayReadyStatics, WMPPIPlayReadyStatics2, WMPPIPlayReadyStatics3,
    WMPPIPlayReadySecureStopServiceRequestFactory, WMPPIPlayReadySecureStopIterableFactory, WMPPIPlayReadySoapMessage,
    WMPPIPlayReadyITADataGenerator, WMPPIPlayReadyLicenseSession, WMPPIPlayReadyLicenseSessionFactory, WMPPINDDownloadEngine,
    WMPPINDDownloadEngineNotifier, WMPPINDLicenseFetchDescriptor, WMPPINDCustomData, WMPPINDStreamParser, WMPPINDStreamParserNotifier,
    WMPPINDSendResult, WMPPINDMessenger, WMPPINDTCPMessengerFactory, WMPPINDTransmitterProperties, WMPPINDStartResult,
    WMPPINDLicenseFetchResult, WMPPINDLicenseFetchDescriptorFactory, WMPPINDRegistrationCompletedEventArgs, WMPPINDCustomDataFactory,
    WMPPINDProximityDetectionCompletedEventArgs, WMPPINDLicenseFetchCompletedEventArgs, WMPPINDClient,
    WMPPINDClosedCaptionDataReceivedEventArgs, WMPPINDClientFactory, WMPPINDStorageFileHelper, WMPPIPlayReadyServiceRequest,
    WMPPIPlayReadyIndividualizationServiceRequest, WMPPIPlayReadyDomainJoinServiceRequest, WMPPIPlayReadyDomainLeaveServiceRequest,
    WMPPIPlayReadyLicenseAcquisitionServiceRequest, WMPPIPlayReadyMeteringReportServiceRequest, WMPPIPlayReadyRevocationServiceRequest,
    WMPPIPlayReadySecureStopServiceRequest;

// Windows.Media.Protection.PlayReady.PlayReadyDecryptorSetup
enum _WMPPPlayReadyDecryptorSetup {
    WMPPPlayReadyDecryptorSetupUninitialized = 0,
    WMPPPlayReadyDecryptorSetupOnDemand = 1,
};
typedef unsigned WMPPPlayReadyDecryptorSetup;

// Windows.Media.Protection.PlayReady.PlayReadyEncryptionAlgorithm
enum _WMPPPlayReadyEncryptionAlgorithm {
    WMPPPlayReadyEncryptionAlgorithmUnprotected = 0,
    WMPPPlayReadyEncryptionAlgorithmAes128Ctr = 1,
    WMPPPlayReadyEncryptionAlgorithmCocktail = 4,
    WMPPPlayReadyEncryptionAlgorithmUninitialized = 2147483647,
};
typedef unsigned WMPPPlayReadyEncryptionAlgorithm;

// Windows.Media.Protection.PlayReady.PlayReadyHardwareDRMFeatures
enum _WMPPPlayReadyHardwareDRMFeatures {
    WMPPPlayReadyHardwareDRMFeaturesHardwareDRM = 1,
    WMPPPlayReadyHardwareDRMFeaturesHEVC = 2,
};
typedef unsigned WMPPPlayReadyHardwareDRMFeatures;

// Windows.Media.Protection.PlayReady.PlayReadyITADataFormat
enum _WMPPPlayReadyITADataFormat {
    WMPPPlayReadyITADataFormatSerializedProperties = 0,
    WMPPPlayReadyITADataFormatSerializedProperties_WithContentProtectionWrapper = 1,
};
typedef unsigned WMPPPlayReadyITADataFormat;

// Windows.Media.Protection.PlayReady.NDCertificateType
enum _WMPPNDCertificateType {
    WMPPNDCertificateTypeUnknown = 0,
    WMPPNDCertificateTypePC = 1,
    WMPPNDCertificateTypeDevice = 2,
    WMPPNDCertificateTypeDomain = 3,
    WMPPNDCertificateTypeIssuer = 4,
    WMPPNDCertificateTypeCrlSigner = 5,
    WMPPNDCertificateTypeService = 6,
    WMPPNDCertificateTypeSilverlight = 7,
    WMPPNDCertificateTypeApplication = 8,
    WMPPNDCertificateTypeMetering = 9,
    WMPPNDCertificateTypeKeyFileSigner = 10,
    WMPPNDCertificateTypeServer = 11,
    WMPPNDCertificateTypeLicenseSigner = 12,
};
typedef unsigned WMPPNDCertificateType;

// Windows.Media.Protection.PlayReady.NDCertificatePlatformID
enum _WMPPNDCertificatePlatformID {
    WMPPNDCertificatePlatformIDWindows = 0,
    WMPPNDCertificatePlatformIDOSX = 1,
    WMPPNDCertificatePlatformIDWindowsOnARM = 2,
    WMPPNDCertificatePlatformIDWindowsMobile7 = 5,
    WMPPNDCertificatePlatformIDiOSOnARM = 6,
    WMPPNDCertificatePlatformIDXBoxOnPPC = 7,
    WMPPNDCertificatePlatformIDWindowsPhone8OnARM = 8,
    WMPPNDCertificatePlatformIDWindowsPhone8OnX86 = 9,
    WMPPNDCertificatePlatformIDXboxOne = 10,
    WMPPNDCertificatePlatformIDAndroidOnARM = 11,
    WMPPNDCertificatePlatformIDWindowsPhone81OnARM = 12,
    WMPPNDCertificatePlatformIDWindowsPhone81OnX86 = 13,
};
typedef unsigned WMPPNDCertificatePlatformID;

// Windows.Media.Protection.PlayReady.NDCertificateFeature
enum _WMPPNDCertificateFeature {
    WMPPNDCertificateFeatureTransmitter = 1,
    WMPPNDCertificateFeatureReceiver = 2,
    WMPPNDCertificateFeatureSharedCertificate = 3,
    WMPPNDCertificateFeatureSecureClock = 4,
    WMPPNDCertificateFeatureAntiRollBackClock = 5,
    WMPPNDCertificateFeatureCRLS = 9,
    WMPPNDCertificateFeaturePlayReady3Features = 13,
};
typedef unsigned WMPPNDCertificateFeature;

// Windows.Media.Protection.PlayReady.NDProximityDetectionType
enum _WMPPNDProximityDetectionType {
    WMPPNDProximityDetectionTypeUDP = 1,
    WMPPNDProximityDetectionTypeTCP = 2,
    WMPPNDProximityDetectionTypeTransportAgnostic = 4,
};
typedef unsigned WMPPNDProximityDetectionType;

// Windows.Media.Protection.PlayReady.NDMediaStreamType
enum _WMPPNDMediaStreamType {
    WMPPNDMediaStreamTypeAudio = 1,
    WMPPNDMediaStreamTypeVideo = 2,
};
typedef unsigned WMPPNDMediaStreamType;

// Windows.Media.Protection.PlayReady.NDContentIDType
enum _WMPPNDContentIDType {
    WMPPNDContentIDTypeKeyID = 1,
    WMPPNDContentIDTypePlayReadyObject = 2,
    WMPPNDContentIDTypeCustom = 3,
};
typedef unsigned WMPPNDContentIDType;

// Windows.Media.Protection.PlayReady.NDClosedCaptionFormat
enum _WMPPNDClosedCaptionFormat {
    WMPPNDClosedCaptionFormatATSC = 0,
    WMPPNDClosedCaptionFormatSCTE20 = 1,
    WMPPNDClosedCaptionFormatUnknown = 2,
};
typedef unsigned WMPPNDClosedCaptionFormat;

// Windows.Media.Protection.PlayReady.NDStartAsyncOptions
enum _WMPPNDStartAsyncOptions {
    WMPPNDStartAsyncOptionsMutualAuthentication = 1,
    WMPPNDStartAsyncOptionsWaitForLicenseDescriptor = 2,
};
typedef unsigned WMPPNDStartAsyncOptions;

#include "WindowsFoundationCollections.h"
#include "WindowsFoundation.h"
#include "WindowsStorage.h"
#include "WindowsMediaCore.h"
#include "WindowsMediaProtection.h"

#import <Foundation/Foundation.h>

// Windows.Media.Protection.PlayReady.IPlayReadyLicense
#ifndef __WMPPIPlayReadyLicense_DEFINED__
#define __WMPPIPlayReadyLicense_DEFINED__

@protocol WMPPIPlayReadyLicense
@property (readonly) unsigned int chainDepth;
@property (readonly) WFGUID* domainAccountID;
@property (readonly) id expirationDate;
@property (readonly) unsigned int expireAfterFirstPlay;
@property (readonly) BOOL fullyEvaluated;
@property (readonly) BOOL usableForPlay;
- (WFGUID*)getKIDAtChainDepth:(unsigned int)chainDepth;
@end

#endif // __WMPPIPlayReadyLicense_DEFINED__

// Windows.Media.Protection.PlayReady.IPlayReadyDomain
#ifndef __WMPPIPlayReadyDomain_DEFINED__
#define __WMPPIPlayReadyDomain_DEFINED__

@protocol WMPPIPlayReadyDomain
@property (readonly) WFGUID* accountId;
@property (readonly) WFUri* domainJoinUrl;
@property (readonly) NSString* friendlyName;
@property (readonly) unsigned int revision;
@property (readonly) WFGUID* serviceId;
@end

#endif // __WMPPIPlayReadyDomain_DEFINED__

// Windows.Media.Protection.PlayReady.IPlayReadyLicenseSession
#ifndef __WMPPIPlayReadyLicenseSession_DEFINED__
#define __WMPPIPlayReadyLicenseSession_DEFINED__

@protocol WMPPIPlayReadyLicenseSession
- (RTObject<WMPPIPlayReadyLicenseAcquisitionServiceRequest>*)createLAServiceRequest;
- (void)configureMediaProtectionManager:(WMPMediaProtectionManager*)mpm;
@end

#endif // __WMPPIPlayReadyLicenseSession_DEFINED__

// Windows.Media.Protection.PlayReady.INDDownloadEngine
#ifndef __WMPPINDDownloadEngine_DEFINED__
#define __WMPPINDDownloadEngine_DEFINED__

@protocol WMPPINDDownloadEngine
@property (readonly) unsigned int bufferFullMaxThresholdInSamples;
@property (readonly) unsigned int bufferFullMinThresholdInSamples;
@property (readonly) BOOL canSeek;
@property (readonly) WMPPNDDownloadEngineNotifier* notifier;
- (void)open:(WFUri*)uri sessionIDBytes:(id<NSFastEnumeration> /* uint8_t */)sessionIDBytes;
- (void)pause;
- (void)resume;
- (void)close;
- (void)seek:(WFTimeSpan*)startPosition;
@end

#endif // __WMPPINDDownloadEngine_DEFINED__

// Windows.Media.Protection.PlayReady.INDDownloadEngineNotifier
#ifndef __WMPPINDDownloadEngineNotifier_DEFINED__
#define __WMPPINDDownloadEngineNotifier_DEFINED__

@protocol WMPPINDDownloadEngineNotifier
- (void)onStreamOpened;
- (void)onPlayReadyObjectReceived:(id<NSFastEnumeration> /* uint8_t */)dataBytes;
- (void)onContentIDReceived:(RTObject<WMPPINDLicenseFetchDescriptor>*)licenseFetchDescriptor;
- (void)onDataReceived:(id<NSFastEnumeration> /* uint8_t */)dataBytes bytesReceived:(unsigned int)bytesReceived;
- (void)onEndOfStream;
- (void)onNetworkError;
@end

#endif // __WMPPINDDownloadEngineNotifier_DEFINED__

// Windows.Media.Protection.PlayReady.INDLicenseFetchDescriptor
#ifndef __WMPPINDLicenseFetchDescriptor_DEFINED__
#define __WMPPINDLicenseFetchDescriptor_DEFINED__

@protocol WMPPINDLicenseFetchDescriptor
@property (readonly) NSArray* contentID;
@property (readonly) WMPPNDContentIDType contentIDType;
@property (copy) RTObject<WMPPINDCustomData>* licenseFetchChallengeCustomData;
@end

#endif // __WMPPINDLicenseFetchDescriptor_DEFINED__

// Windows.Media.Protection.PlayReady.INDCustomData
#ifndef __WMPPINDCustomData_DEFINED__
#define __WMPPINDCustomData_DEFINED__

@protocol WMPPINDCustomData
@property (readonly) NSArray* customData;
@property (readonly) NSArray* customDataTypeID;
@end

#endif // __WMPPINDCustomData_DEFINED__

// Windows.Media.Protection.PlayReady.INDStreamParser
#ifndef __WMPPINDStreamParser_DEFINED__
#define __WMPPINDStreamParser_DEFINED__

@protocol WMPPINDStreamParser
@property (readonly) WMPPNDStreamParserNotifier* notifier;
- (void)parseData:(id<NSFastEnumeration> /* uint8_t */)dataBytes;
- (unsigned int)getStreamInformation:(RTObject<WMCIMediaStreamDescriptor>*)descriptor streamType:(WMPPNDMediaStreamType*)streamType;
- (void)beginOfStream;
- (void)endOfStream;
@end

#endif // __WMPPINDStreamParser_DEFINED__

// Windows.Media.Protection.PlayReady.INDStreamParserNotifier
#ifndef __WMPPINDStreamParserNotifier_DEFINED__
#define __WMPPINDStreamParserNotifier_DEFINED__

@protocol WMPPINDStreamParserNotifier
- (void)onContentIDReceived:(RTObject<WMPPINDLicenseFetchDescriptor>*)licenseFetchDescriptor;
- (void)onMediaStreamDescriptorCreated:(id<NSFastEnumeration> /* WMCAudioStreamDescriptor* */)audioStreamDescriptors
                videoStreamDescriptors:(id<NSFastEnumeration> /* WMCVideoStreamDescriptor* */)videoStreamDescriptors;
- (void)onSampleParsed:(unsigned int)streamID
            streamType:(WMPPNDMediaStreamType)streamType
          streamSample:(WMCMediaStreamSample*)streamSample
                   pts:(int64_t)pts
              ccFormat:(WMPPNDClosedCaptionFormat)ccFormat
           ccDataBytes:(id<NSFastEnumeration> /* uint8_t */)ccDataBytes;
- (void)onBeginSetupDecryptor:(RTObject<WMCIMediaStreamDescriptor>*)descriptor
                        keyID:(WFGUID*)keyID
                     proBytes:(id<NSFastEnumeration> /* uint8_t */)proBytes;
@end

#endif // __WMPPINDStreamParserNotifier_DEFINED__

// Windows.Media.Protection.PlayReady.INDSendResult
#ifndef __WMPPINDSendResult_DEFINED__
#define __WMPPINDSendResult_DEFINED__

@protocol WMPPINDSendResult
@property (readonly) NSArray* response;
@end

#endif // __WMPPINDSendResult_DEFINED__

// Windows.Media.Protection.PlayReady.INDMessenger
#ifndef __WMPPINDMessenger_DEFINED__
#define __WMPPINDMessenger_DEFINED__

@protocol WMPPINDMessenger
- (void)sendRegistrationRequestAsync:(id<NSFastEnumeration> /* uint8_t */)sessionIDBytes
                  challengeDataBytes:(id<NSFastEnumeration> /* uint8_t */)challengeDataBytes
                             success:(void (^)(RTObject<WMPPINDSendResult>*))success
                             failure:(void (^)(NSError*))failure;
- (void)sendProximityDetectionStartAsync:(WMPPNDProximityDetectionType)pdType
                 transmitterChannelBytes:(id<NSFastEnumeration> /* uint8_t */)transmitterChannelBytes
                          sessionIDBytes:(id<NSFastEnumeration> /* uint8_t */)sessionIDBytes
                      challengeDataBytes:(id<NSFastEnumeration> /* uint8_t */)challengeDataBytes
                                 success:(void (^)(RTObject<WMPPINDSendResult>*))success
                                 failure:(void (^)(NSError*))failure;
- (void)sendProximityDetectionResponseAsync:(WMPPNDProximityDetectionType)pdType
                    transmitterChannelBytes:(id<NSFastEnumeration> /* uint8_t */)transmitterChannelBytes
                             sessionIDBytes:(id<NSFastEnumeration> /* uint8_t */)sessionIDBytes
                          responseDataBytes:(id<NSFastEnumeration> /* uint8_t */)responseDataBytes
                                    success:(void (^)(RTObject<WMPPINDSendResult>*))success
                                    failure:(void (^)(NSError*))failure;
- (void)sendLicenseFetchRequestAsync:(id<NSFastEnumeration> /* uint8_t */)sessionIDBytes
                  challengeDataBytes:(id<NSFastEnumeration> /* uint8_t */)challengeDataBytes
                             success:(void (^)(RTObject<WMPPINDSendResult>*))success
                             failure:(void (^)(NSError*))failure;
@end

#endif // __WMPPINDMessenger_DEFINED__

// Windows.Media.Protection.PlayReady.INDTransmitterProperties
#ifndef __WMPPINDTransmitterProperties_DEFINED__
#define __WMPPINDTransmitterProperties_DEFINED__

@protocol WMPPINDTransmitterProperties
@property (readonly) WMPPNDCertificateType certificateType;
@property (readonly) NSArray* clientID;
@property (readonly) WFDateTime* expirationDate;
@property (readonly) NSArray* modelDigest;
@property (readonly) NSString* modelManufacturerName;
@property (readonly) NSString* modelName;
@property (readonly) NSString* modelNumber;
@property (readonly) WMPPNDCertificatePlatformID platformIdentifier;
@property (readonly) unsigned int securityLevel;
@property (readonly) unsigned int securityVersion;
@property (readonly) NSArray* supportedFeatures;
@end

#endif // __WMPPINDTransmitterProperties_DEFINED__

// Windows.Media.Protection.PlayReady.INDStartResult
#ifndef __WMPPINDStartResult_DEFINED__
#define __WMPPINDStartResult_DEFINED__

@protocol WMPPINDStartResult
@property (readonly) WMCMediaStreamSource* mediaStreamSource;
@end

#endif // __WMPPINDStartResult_DEFINED__

// Windows.Media.Protection.PlayReady.INDLicenseFetchResult
#ifndef __WMPPINDLicenseFetchResult_DEFINED__
#define __WMPPINDLicenseFetchResult_DEFINED__

@protocol WMPPINDLicenseFetchResult
@property (readonly) RTObject<WMPPINDCustomData>* responseCustomData;
@end

#endif // __WMPPINDLicenseFetchResult_DEFINED__

// Windows.Media.Protection.PlayReady.INDRegistrationCompletedEventArgs
#ifndef __WMPPINDRegistrationCompletedEventArgs_DEFINED__
#define __WMPPINDRegistrationCompletedEventArgs_DEFINED__

@protocol WMPPINDRegistrationCompletedEventArgs
@property (readonly) RTObject<WMPPINDCustomData>* responseCustomData;
@property BOOL transmitterCertificateAccepted;
@property (readonly) RTObject<WMPPINDTransmitterProperties>* transmitterProperties;
@end

#endif // __WMPPINDRegistrationCompletedEventArgs_DEFINED__

// Windows.Media.Protection.PlayReady.INDProximityDetectionCompletedEventArgs
#ifndef __WMPPINDProximityDetectionCompletedEventArgs_DEFINED__
#define __WMPPINDProximityDetectionCompletedEventArgs_DEFINED__

@protocol WMPPINDProximityDetectionCompletedEventArgs
@property (readonly) unsigned int proximityDetectionRetryCount;
@end

#endif // __WMPPINDProximityDetectionCompletedEventArgs_DEFINED__

// Windows.Media.Protection.PlayReady.INDLicenseFetchCompletedEventArgs
#ifndef __WMPPINDLicenseFetchCompletedEventArgs_DEFINED__
#define __WMPPINDLicenseFetchCompletedEventArgs_DEFINED__

@protocol WMPPINDLicenseFetchCompletedEventArgs
@property (readonly) RTObject<WMPPINDCustomData>* responseCustomData;
@end

#endif // __WMPPINDLicenseFetchCompletedEventArgs_DEFINED__

// Windows.Media.Protection.PlayReady.INDClosedCaptionDataReceivedEventArgs
#ifndef __WMPPINDClosedCaptionDataReceivedEventArgs_DEFINED__
#define __WMPPINDClosedCaptionDataReceivedEventArgs_DEFINED__

@protocol WMPPINDClosedCaptionDataReceivedEventArgs
@property (readonly) NSArray* closedCaptionData;
@property (readonly) WMPPNDClosedCaptionFormat closedCaptionDataFormat;
@property (readonly) int64_t presentationTimestamp;
@end

#endif // __WMPPINDClosedCaptionDataReceivedEventArgs_DEFINED__

// Windows.Media.Protection.PlayReady.INDStorageFileHelper
#ifndef __WMPPINDStorageFileHelper_DEFINED__
#define __WMPPINDStorageFileHelper_DEFINED__

@protocol WMPPINDStorageFileHelper
- (NSMutableArray*)getFileURLs:(RTObject<WSIStorageFile>*)file;
@end

#endif // __WMPPINDStorageFileHelper_DEFINED__

// Windows.Media.Protection.IMediaProtectionServiceRequest
#ifndef __WMPIMediaProtectionServiceRequest_DEFINED__
#define __WMPIMediaProtectionServiceRequest_DEFINED__

@protocol WMPIMediaProtectionServiceRequest
@property (readonly) WFGUID* protectionSystem;
@property (readonly) WFGUID* type;
@end

#endif // __WMPIMediaProtectionServiceRequest_DEFINED__

// Windows.Media.Protection.PlayReady.IPlayReadyServiceRequest
#ifndef __WMPPIPlayReadyServiceRequest_DEFINED__
#define __WMPPIPlayReadyServiceRequest_DEFINED__

@protocol WMPPIPlayReadyServiceRequest <WMPIMediaProtectionServiceRequest>
@property (copy) NSString* challengeCustomData;
@property (readonly) NSString* responseCustomData;
@property (copy) WFUri* uri;
- (RTObject<WFIAsyncAction>*)beginServiceRequest;
- (RTObject<WMPPIPlayReadyServiceRequest>*)nextServiceRequest;
- (WMPPPlayReadySoapMessage*)generateManualEnablingChallenge;
- (HRESULT)processManualEnablingResponse:(id<NSFastEnumeration> /* uint8_t */)responseBytes;
@end

#endif // __WMPPIPlayReadyServiceRequest_DEFINED__

// Windows.Media.Protection.PlayReady.IPlayReadyLicenseAcquisitionServiceRequest
#ifndef __WMPPIPlayReadyLicenseAcquisitionServiceRequest_DEFINED__
#define __WMPPIPlayReadyLicenseAcquisitionServiceRequest_DEFINED__

@protocol WMPPIPlayReadyLicenseAcquisitionServiceRequest <WMPPIPlayReadyServiceRequest, WMPIMediaProtectionServiceRequest>
@property (copy) WMPPPlayReadyContentHeader* contentHeader;
@property WFGUID* domainServiceId;
- (RTObject<WFIAsyncAction>*)beginServiceRequest;
- (RTObject<WMPPIPlayReadyServiceRequest>*)nextServiceRequest;
- (WMPPPlayReadySoapMessage*)generateManualEnablingChallenge;
- (HRESULT)processManualEnablingResponse:(id<NSFastEnumeration> /* uint8_t */)responseBytes;
@end

#endif // __WMPPIPlayReadyLicenseAcquisitionServiceRequest_DEFINED__

// Windows.Media.Protection.PlayReady.IPlayReadySecureStopServiceRequest
#ifndef __WMPPIPlayReadySecureStopServiceRequest_DEFINED__
#define __WMPPIPlayReadySecureStopServiceRequest_DEFINED__

@protocol WMPPIPlayReadySecureStopServiceRequest <WMPPIPlayReadyServiceRequest, WMPIMediaProtectionServiceRequest>
@property (readonly) NSArray* publisherCertificate;
@property (readonly) WFGUID* sessionID;
@property (readonly) WFDateTime* startTime;
@property (readonly) BOOL stopped;
@property (readonly) WFDateTime* updateTime;
- (RTObject<WFIAsyncAction>*)beginServiceRequest;
- (RTObject<WMPPIPlayReadyServiceRequest>*)nextServiceRequest;
- (WMPPPlayReadySoapMessage*)generateManualEnablingChallenge;
- (HRESULT)processManualEnablingResponse:(id<NSFastEnumeration> /* uint8_t */)responseBytes;
@end

#endif // __WMPPIPlayReadySecureStopServiceRequest_DEFINED__

// Windows.Media.Protection.PlayReady.PlayReadyContentHeader
#ifndef __WMPPPlayReadyContentHeader_DEFINED__
#define __WMPPPlayReadyContentHeader_DEFINED__

WINRT_EXPORT
@interface WMPPPlayReadyContentHeader : RTObject
+ (WMPPPlayReadyContentHeader*)createInstanceFromComponents2:(unsigned int)dwFlags
                                               contentKeyIds:(id<NSFastEnumeration> /* WFGUID* */)contentKeyIds
                                         contentKeyIdStrings:(id<NSFastEnumeration> /* NSString * */)contentKeyIdStrings
                                  contentEncryptionAlgorithm:(WMPPPlayReadyEncryptionAlgorithm)contentEncryptionAlgorithm
                                       licenseAcquisitionUrl:(WFUri*)licenseAcquisitionUrl
                          licenseAcquisitionUserInterfaceUrl:(WFUri*)licenseAcquisitionUserInterfaceUrl
                                            customAttributes:(NSString*)customAttributes
                                             domainServiceId:(WFGUID*)domainServiceId ACTIVATOR;
+ (WMPPPlayReadyContentHeader*)createInstanceFromWindowsMediaDrmHeader:(id<NSFastEnumeration> /* uint8_t */)headerBytes
                                                 licenseAcquisitionUrl:(WFUri*)licenseAcquisitionUrl
                                    licenseAcquisitionUserInterfaceUrl:(WFUri*)licenseAcquisitionUserInterfaceUrl
                                                      customAttributes:(NSString*)customAttributes
                                                       domainServiceId:(WFGUID*)domainServiceId ACTIVATOR;
+ (WMPPPlayReadyContentHeader*)createInstanceFromComponents:(WFGUID*)contentKeyId
                                         contentKeyIdString:(NSString*)contentKeyIdString
                                 contentEncryptionAlgorithm:(WMPPPlayReadyEncryptionAlgorithm)contentEncryptionAlgorithm
                                      licenseAcquisitionUrl:(WFUri*)licenseAcquisitionUrl
                         licenseAcquisitionUserInterfaceUrl:(WFUri*)licenseAcquisitionUserInterfaceUrl
                                           customAttributes:(NSString*)customAttributes
                                            domainServiceId:(WFGUID*)domainServiceId ACTIVATOR;
+ (WMPPPlayReadyContentHeader*)createInstanceFromPlayReadyHeader:(id<NSFastEnumeration> /* uint8_t */)headerBytes ACTIVATOR;
@property (readonly) NSString* customAttributes;
@property (readonly) WMPPPlayReadyDecryptorSetup decryptorSetup;
@property (readonly) WFGUID* domainServiceId;
@property (readonly) WMPPPlayReadyEncryptionAlgorithm encryptionType;
@property (readonly) WMPPPlayReadyContentHeader* headerWithEmbeddedUpdates;
@property (readonly) WFGUID* keyId;
@property (readonly) NSString* keyIdString;
@property (readonly) WFUri* licenseAcquisitionUrl;
@property (readonly) WFUri* licenseAcquisitionUserInterfaceUrl;
@property (readonly) NSArray* keyIdStrings;
@property (readonly) NSArray* keyIds;
- (NSArray*)getSerializedHeader;
@end

#endif // __WMPPPlayReadyContentHeader_DEFINED__

// Windows.Media.Protection.PlayReady.PlayReadySoapMessage
#ifndef __WMPPPlayReadySoapMessage_DEFINED__
#define __WMPPPlayReadySoapMessage_DEFINED__

WINRT_EXPORT
@interface WMPPPlayReadySoapMessage : RTObject
@property (readonly) RTObject<WFCIPropertySet>* messageHeaders;
@property (readonly) WFUri* uri;
- (NSArray*)getMessageBody;
@end

#endif // __WMPPPlayReadySoapMessage_DEFINED__

// Windows.Media.Protection.PlayReady.PlayReadyContentResolver
#ifndef __WMPPPlayReadyContentResolver_DEFINED__
#define __WMPPPlayReadyContentResolver_DEFINED__

WINRT_EXPORT
@interface WMPPPlayReadyContentResolver : RTObject
+ (RTObject<WMPPIPlayReadyServiceRequest>*)serviceRequest:(WMPPPlayReadyContentHeader*)contentHeader;
@end

#endif // __WMPPPlayReadyContentResolver_DEFINED__

// Windows.Media.Protection.PlayReady.PlayReadyIndividualizationServiceRequest
#ifndef __WMPPPlayReadyIndividualizationServiceRequest_DEFINED__
#define __WMPPPlayReadyIndividualizationServiceRequest_DEFINED__

WINRT_EXPORT
@interface WMPPPlayReadyIndividualizationServiceRequest : RTObject <WMPPIPlayReadyServiceRequest, WMPIMediaProtectionServiceRequest>
+ (instancetype)create ACTIVATOR;
@property (readonly) WFGUID* protectionSystem;
@property (readonly) WFGUID* type;
@property (copy) WFUri* uri;
@property (copy) NSString* challengeCustomData;
@property (readonly) NSString* responseCustomData;
- (RTObject<WFIAsyncAction>*)beginServiceRequest;
- (RTObject<WMPPIPlayReadyServiceRequest>*)nextServiceRequest;
- (WMPPPlayReadySoapMessage*)generateManualEnablingChallenge;
- (HRESULT)processManualEnablingResponse:(id<NSFastEnumeration> /* uint8_t */)responseBytes;
@end

#endif // __WMPPPlayReadyIndividualizationServiceRequest_DEFINED__

// Windows.Media.Protection.PlayReady.PlayReadyDomainJoinServiceRequest
#ifndef __WMPPPlayReadyDomainJoinServiceRequest_DEFINED__
#define __WMPPPlayReadyDomainJoinServiceRequest_DEFINED__

WINRT_EXPORT
@interface WMPPPlayReadyDomainJoinServiceRequest : RTObject <WMPPIPlayReadyServiceRequest, WMPIMediaProtectionServiceRequest>
+ (instancetype)create ACTIVATOR;
@property (readonly) WFGUID* protectionSystem;
@property (readonly) WFGUID* type;
@property WFGUID* domainServiceId;
@property (copy) NSString* domainFriendlyName;
@property WFGUID* domainAccountId;
@property (copy) WFUri* uri;
@property (copy) NSString* challengeCustomData;
@property (readonly) NSString* responseCustomData;
- (RTObject<WFIAsyncAction>*)beginServiceRequest;
- (RTObject<WMPPIPlayReadyServiceRequest>*)nextServiceRequest;
- (WMPPPlayReadySoapMessage*)generateManualEnablingChallenge;
- (HRESULT)processManualEnablingResponse:(id<NSFastEnumeration> /* uint8_t */)responseBytes;
@end

#endif // __WMPPPlayReadyDomainJoinServiceRequest_DEFINED__

// Windows.Media.Protection.PlayReady.PlayReadyDomainLeaveServiceRequest
#ifndef __WMPPPlayReadyDomainLeaveServiceRequest_DEFINED__
#define __WMPPPlayReadyDomainLeaveServiceRequest_DEFINED__

WINRT_EXPORT
@interface WMPPPlayReadyDomainLeaveServiceRequest : RTObject <WMPPIPlayReadyServiceRequest, WMPIMediaProtectionServiceRequest>
+ (instancetype)create ACTIVATOR;
@property (readonly) WFGUID* protectionSystem;
@property (readonly) WFGUID* type;
@property WFGUID* domainServiceId;
@property WFGUID* domainAccountId;
@property (copy) WFUri* uri;
@property (copy) NSString* challengeCustomData;
@property (readonly) NSString* responseCustomData;
- (RTObject<WFIAsyncAction>*)beginServiceRequest;
- (RTObject<WMPPIPlayReadyServiceRequest>*)nextServiceRequest;
- (WMPPPlayReadySoapMessage*)generateManualEnablingChallenge;
- (HRESULT)processManualEnablingResponse:(id<NSFastEnumeration> /* uint8_t */)responseBytes;
@end

#endif // __WMPPPlayReadyDomainLeaveServiceRequest_DEFINED__

// Windows.Media.Protection.PlayReady.PlayReadyLicenseAcquisitionServiceRequest
#ifndef __WMPPPlayReadyLicenseAcquisitionServiceRequest_DEFINED__
#define __WMPPPlayReadyLicenseAcquisitionServiceRequest_DEFINED__

WINRT_EXPORT
@interface WMPPPlayReadyLicenseAcquisitionServiceRequest
    : RTObject <WMPPIPlayReadyLicenseAcquisitionServiceRequest, WMPPIPlayReadyServiceRequest, WMPIMediaProtectionServiceRequest>
+ (instancetype)create ACTIVATOR;
@property (readonly) WFGUID* protectionSystem;
@property (readonly) WFGUID* type;
@property WFGUID* domainServiceId;
@property (copy) WMPPPlayReadyContentHeader* contentHeader;
@property (copy) WFUri* uri;
@property (copy) NSString* challengeCustomData;
@property (readonly) NSString* responseCustomData;
- (RTObject<WFIAsyncAction>*)beginServiceRequest;
- (RTObject<WMPPIPlayReadyServiceRequest>*)nextServiceRequest;
- (WMPPPlayReadySoapMessage*)generateManualEnablingChallenge;
- (HRESULT)processManualEnablingResponse:(id<NSFastEnumeration> /* uint8_t */)responseBytes;
@end

#endif // __WMPPPlayReadyLicenseAcquisitionServiceRequest_DEFINED__

// Windows.Media.Protection.PlayReady.PlayReadyMeteringReportServiceRequest
#ifndef __WMPPPlayReadyMeteringReportServiceRequest_DEFINED__
#define __WMPPPlayReadyMeteringReportServiceRequest_DEFINED__

WINRT_EXPORT
@interface WMPPPlayReadyMeteringReportServiceRequest : RTObject <WMPPIPlayReadyServiceRequest, WMPIMediaProtectionServiceRequest>
+ (instancetype)create ACTIVATOR;
@property (readonly) WFGUID* protectionSystem;
@property (readonly) WFGUID* type;
@property (copy) NSArray* meteringCertificate;
@property (copy) WFUri* uri;
@property (copy) NSString* challengeCustomData;
@property (readonly) NSString* responseCustomData;
- (RTObject<WFIAsyncAction>*)beginServiceRequest;
- (RTObject<WMPPIPlayReadyServiceRequest>*)nextServiceRequest;
- (WMPPPlayReadySoapMessage*)generateManualEnablingChallenge;
- (HRESULT)processManualEnablingResponse:(id<NSFastEnumeration> /* uint8_t */)responseBytes;
@end

#endif // __WMPPPlayReadyMeteringReportServiceRequest_DEFINED__

// Windows.Media.Protection.PlayReady.PlayReadyRevocationServiceRequest
#ifndef __WMPPPlayReadyRevocationServiceRequest_DEFINED__
#define __WMPPPlayReadyRevocationServiceRequest_DEFINED__

WINRT_EXPORT
@interface WMPPPlayReadyRevocationServiceRequest : RTObject <WMPPIPlayReadyServiceRequest, WMPIMediaProtectionServiceRequest>
+ (instancetype)create ACTIVATOR;
@property (readonly) WFGUID* protectionSystem;
@property (readonly) WFGUID* type;
@property (copy) WFUri* uri;
@property (copy) NSString* challengeCustomData;
@property (readonly) NSString* responseCustomData;
- (RTObject<WFIAsyncAction>*)beginServiceRequest;
- (RTObject<WMPPIPlayReadyServiceRequest>*)nextServiceRequest;
- (WMPPPlayReadySoapMessage*)generateManualEnablingChallenge;
- (HRESULT)processManualEnablingResponse:(id<NSFastEnumeration> /* uint8_t */)responseBytes;
@end

#endif // __WMPPPlayReadyRevocationServiceRequest_DEFINED__

// Windows.Media.Protection.PlayReady.PlayReadyLicenseManagement
#ifndef __WMPPPlayReadyLicenseManagement_DEFINED__
#define __WMPPPlayReadyLicenseManagement_DEFINED__

WINRT_EXPORT
@interface WMPPPlayReadyLicenseManagement : RTObject
+ (RTObject<WFIAsyncAction>*)deleteLicenses:(WMPPPlayReadyContentHeader*)contentHeader;
@end

#endif // __WMPPPlayReadyLicenseManagement_DEFINED__

// Windows.Media.Protection.PlayReady.PlayReadyLicense
#ifndef __WMPPPlayReadyLicense_DEFINED__
#define __WMPPPlayReadyLicense_DEFINED__

WINRT_EXPORT
@interface WMPPPlayReadyLicense : RTObject <WMPPIPlayReadyLicense>
@property (readonly) unsigned int chainDepth;
@property (readonly) WFGUID* domainAccountID;
@property (readonly) id expirationDate;
@property (readonly) unsigned int expireAfterFirstPlay;
@property (readonly) BOOL fullyEvaluated;
@property (readonly) BOOL usableForPlay;
- (WFGUID*)getKIDAtChainDepth:(unsigned int)chainDepth;
@end

#endif // __WMPPPlayReadyLicense_DEFINED__

// Windows.Media.Protection.PlayReady.PlayReadyLicenseIterable
#ifndef __WMPPPlayReadyLicenseIterable_DEFINED__
#define __WMPPPlayReadyLicenseIterable_DEFINED__

WINRT_EXPORT
@interface WMPPPlayReadyLicenseIterable : RTObject
+ (instancetype)create ACTIVATOR;
+ (WMPPPlayReadyLicenseIterable*)createInstance:(WMPPPlayReadyContentHeader*)contentHeader fullyEvaluated:(BOOL)fullyEvaluated ACTIVATOR;
@end

#endif // __WMPPPlayReadyLicenseIterable_DEFINED__

// Windows.Media.Protection.PlayReady.PlayReadyLicenseIterator
#ifndef __WMPPPlayReadyLicenseIterator_DEFINED__
#define __WMPPPlayReadyLicenseIterator_DEFINED__

WINRT_EXPORT
@interface WMPPPlayReadyLicenseIterator : RTObject
@property (readonly) RTObject<WMPPIPlayReadyLicense>* current;
@property (readonly) BOOL hasCurrent;
// Could not find base class Windows.Foundation.Collections.IIterator`1<Windows.Media.Protection.PlayReady.IPlayReadyLicense> type
// information
@end

#endif // __WMPPPlayReadyLicenseIterator_DEFINED__

// Windows.Media.Protection.PlayReady.PlayReadyDomain
#ifndef __WMPPPlayReadyDomain_DEFINED__
#define __WMPPPlayReadyDomain_DEFINED__

WINRT_EXPORT
@interface WMPPPlayReadyDomain : RTObject <WMPPIPlayReadyDomain>
@property (readonly) WFGUID* accountId;
@property (readonly) WFUri* domainJoinUrl;
@property (readonly) NSString* friendlyName;
@property (readonly) unsigned int revision;
@property (readonly) WFGUID* serviceId;
@end

#endif // __WMPPPlayReadyDomain_DEFINED__

// Windows.Media.Protection.PlayReady.PlayReadyDomainIterable
#ifndef __WMPPPlayReadyDomainIterable_DEFINED__
#define __WMPPPlayReadyDomainIterable_DEFINED__

WINRT_EXPORT
@interface WMPPPlayReadyDomainIterable : RTObject
+ (WMPPPlayReadyDomainIterable*)createInstance:(WFGUID*)domainAccountId ACTIVATOR;
@end

#endif // __WMPPPlayReadyDomainIterable_DEFINED__

// Windows.Media.Protection.PlayReady.PlayReadyDomainIterator
#ifndef __WMPPPlayReadyDomainIterator_DEFINED__
#define __WMPPPlayReadyDomainIterator_DEFINED__

WINRT_EXPORT
@interface WMPPPlayReadyDomainIterator : RTObject
@property (readonly) RTObject<WMPPIPlayReadyDomain>* current;
@property (readonly) BOOL hasCurrent;
// Could not find base class Windows.Foundation.Collections.IIterator`1<Windows.Media.Protection.PlayReady.IPlayReadyDomain> type
// information
@end

#endif // __WMPPPlayReadyDomainIterator_DEFINED__

// Windows.Media.Protection.PlayReady.PlayReadyStatics
#ifndef __WMPPPlayReadyStatics_DEFINED__
#define __WMPPPlayReadyStatics_DEFINED__

WINRT_EXPORT
@interface WMPPPlayReadyStatics : RTObject
+ (BOOL)checkSupportedHardware:(WMPPPlayReadyHardwareDRMFeatures)hwdrmFeature;
+ (WFGUID*)domainJoinServiceRequestType;
+ (WFGUID*)domainLeaveServiceRequestType;
+ (WFGUID*)individualizationServiceRequestType;
+ (WFGUID*)licenseAcquirerServiceRequestType;
+ (WFGUID*)mediaProtectionSystemId;
+ (WFGUID*)meteringReportServiceRequestType;
+ (unsigned int)playReadySecurityVersion;
+ (WFGUID*)revocationServiceRequestType;
+ (unsigned int)playReadyCertificateSecurityLevel;
+ (WFGUID*)secureStopServiceRequestType;
@end

#endif // __WMPPPlayReadyStatics_DEFINED__

// Windows.Media.Protection.PlayReady.PlayReadySecureStopServiceRequest
#ifndef __WMPPPlayReadySecureStopServiceRequest_DEFINED__
#define __WMPPPlayReadySecureStopServiceRequest_DEFINED__

WINRT_EXPORT
@interface WMPPPlayReadySecureStopServiceRequest
    : RTObject <WMPPIPlayReadySecureStopServiceRequest, WMPPIPlayReadyServiceRequest, WMPIMediaProtectionServiceRequest>
+ (WMPPPlayReadySecureStopServiceRequest*)createInstance:(id<NSFastEnumeration> /* uint8_t */)publisherCertBytes ACTIVATOR;
+ (WMPPPlayReadySecureStopServiceRequest*)createInstanceFromSessionID:(WFGUID*)sessionID
                                                   publisherCertBytes:(id<NSFastEnumeration> /* uint8_t */)publisherCertBytes ACTIVATOR;
@property (readonly) WFGUID* protectionSystem;
@property (readonly) WFGUID* type;
@property (readonly) NSArray* publisherCertificate;
@property (readonly) WFGUID* sessionID;
@property (readonly) WFDateTime* startTime;
@property (readonly) BOOL stopped;
@property (readonly) WFDateTime* updateTime;
@property (copy) WFUri* uri;
@property (copy) NSString* challengeCustomData;
@property (readonly) NSString* responseCustomData;
- (RTObject<WFIAsyncAction>*)beginServiceRequest;
- (RTObject<WMPPIPlayReadyServiceRequest>*)nextServiceRequest;
- (WMPPPlayReadySoapMessage*)generateManualEnablingChallenge;
- (HRESULT)processManualEnablingResponse:(id<NSFastEnumeration> /* uint8_t */)responseBytes;
@end

#endif // __WMPPPlayReadySecureStopServiceRequest_DEFINED__

// Windows.Media.Protection.PlayReady.PlayReadySecureStopIterable
#ifndef __WMPPPlayReadySecureStopIterable_DEFINED__
#define __WMPPPlayReadySecureStopIterable_DEFINED__

WINRT_EXPORT
@interface WMPPPlayReadySecureStopIterable : RTObject
+ (WMPPPlayReadySecureStopIterable*)createInstance:(id<NSFastEnumeration> /* uint8_t */)publisherCertBytes ACTIVATOR;
@end

#endif // __WMPPPlayReadySecureStopIterable_DEFINED__

// Windows.Media.Protection.PlayReady.PlayReadySecureStopIterator
#ifndef __WMPPPlayReadySecureStopIterator_DEFINED__
#define __WMPPPlayReadySecureStopIterator_DEFINED__

WINRT_EXPORT
@interface WMPPPlayReadySecureStopIterator : RTObject
@property (readonly) RTObject<WMPPIPlayReadySecureStopServiceRequest>* current;
@property (readonly) BOOL hasCurrent;
// Could not find base class
// Windows.Foundation.Collections.IIterator`1<Windows.Media.Protection.PlayReady.IPlayReadySecureStopServiceRequest> type information
@end

#endif // __WMPPPlayReadySecureStopIterator_DEFINED__

// Windows.Media.Protection.PlayReady.PlayReadyITADataGenerator
#ifndef __WMPPPlayReadyITADataGenerator_DEFINED__
#define __WMPPPlayReadyITADataGenerator_DEFINED__

WINRT_EXPORT
@interface WMPPPlayReadyITADataGenerator : RTObject
+ (instancetype)create ACTIVATOR;
- (NSArray*)generateData:(WFGUID*)guidCPSystemId
          countOfStreams:(unsigned int)countOfStreams
           configuration:(RTObject<WFCIPropertySet>*)configuration
                  format:(WMPPPlayReadyITADataFormat)format;
@end

#endif // __WMPPPlayReadyITADataGenerator_DEFINED__

// Windows.Media.Protection.PlayReady.PlayReadyLicenseSession
#ifndef __WMPPPlayReadyLicenseSession_DEFINED__
#define __WMPPPlayReadyLicenseSession_DEFINED__

WINRT_EXPORT
@interface WMPPPlayReadyLicenseSession : RTObject <WMPPIPlayReadyLicenseSession>
+ (WMPPPlayReadyLicenseSession*)createInstance:(RTObject<WFCIPropertySet>*)configuration ACTIVATOR;
- (RTObject<WMPPIPlayReadyLicenseAcquisitionServiceRequest>*)createLAServiceRequest;
- (void)configureMediaProtectionManager:(WMPMediaProtectionManager*)mpm;
@end

#endif // __WMPPPlayReadyLicenseSession_DEFINED__

// Windows.Media.Protection.PlayReady.NDDownloadEngineNotifier
#ifndef __WMPPNDDownloadEngineNotifier_DEFINED__
#define __WMPPNDDownloadEngineNotifier_DEFINED__

WINRT_EXPORT
@interface WMPPNDDownloadEngineNotifier : RTObject <WMPPINDDownloadEngineNotifier>
+ (instancetype)create ACTIVATOR;
- (void)onStreamOpened;
- (void)onPlayReadyObjectReceived:(id<NSFastEnumeration> /* uint8_t */)dataBytes;
- (void)onContentIDReceived:(RTObject<WMPPINDLicenseFetchDescriptor>*)licenseFetchDescriptor;
- (void)onDataReceived:(id<NSFastEnumeration> /* uint8_t */)dataBytes bytesReceived:(unsigned int)bytesReceived;
- (void)onEndOfStream;
- (void)onNetworkError;
@end

#endif // __WMPPNDDownloadEngineNotifier_DEFINED__

// Windows.Media.Protection.PlayReady.NDStreamParserNotifier
#ifndef __WMPPNDStreamParserNotifier_DEFINED__
#define __WMPPNDStreamParserNotifier_DEFINED__

WINRT_EXPORT
@interface WMPPNDStreamParserNotifier : RTObject <WMPPINDStreamParserNotifier>
+ (instancetype)create ACTIVATOR;
- (void)onContentIDReceived:(RTObject<WMPPINDLicenseFetchDescriptor>*)licenseFetchDescriptor;
- (void)onMediaStreamDescriptorCreated:(id<NSFastEnumeration> /* WMCAudioStreamDescriptor* */)audioStreamDescriptors
                videoStreamDescriptors:(id<NSFastEnumeration> /* WMCVideoStreamDescriptor* */)videoStreamDescriptors;
- (void)onSampleParsed:(unsigned int)streamID
            streamType:(WMPPNDMediaStreamType)streamType
          streamSample:(WMCMediaStreamSample*)streamSample
                   pts:(int64_t)pts
              ccFormat:(WMPPNDClosedCaptionFormat)ccFormat
           ccDataBytes:(id<NSFastEnumeration> /* uint8_t */)ccDataBytes;
- (void)onBeginSetupDecryptor:(RTObject<WMCIMediaStreamDescriptor>*)descriptor
                        keyID:(WFGUID*)keyID
                     proBytes:(id<NSFastEnumeration> /* uint8_t */)proBytes;
@end

#endif // __WMPPNDStreamParserNotifier_DEFINED__

// Windows.Media.Protection.PlayReady.NDTCPMessenger
#ifndef __WMPPNDTCPMessenger_DEFINED__
#define __WMPPNDTCPMessenger_DEFINED__

WINRT_EXPORT
@interface WMPPNDTCPMessenger : RTObject <WMPPINDMessenger>
+ (WMPPNDTCPMessenger*)createInstance:(NSString*)remoteHostName remoteHostPort:(unsigned int)remoteHostPort ACTIVATOR;
- (void)sendRegistrationRequestAsync:(id<NSFastEnumeration> /* uint8_t */)sessionIDBytes
                  challengeDataBytes:(id<NSFastEnumeration> /* uint8_t */)challengeDataBytes
                             success:(void (^)(RTObject<WMPPINDSendResult>*))success
                             failure:(void (^)(NSError*))failure;
- (void)sendProximityDetectionStartAsync:(WMPPNDProximityDetectionType)pdType
                 transmitterChannelBytes:(id<NSFastEnumeration> /* uint8_t */)transmitterChannelBytes
                          sessionIDBytes:(id<NSFastEnumeration> /* uint8_t */)sessionIDBytes
                      challengeDataBytes:(id<NSFastEnumeration> /* uint8_t */)challengeDataBytes
                                 success:(void (^)(RTObject<WMPPINDSendResult>*))success
                                 failure:(void (^)(NSError*))failure;
- (void)sendProximityDetectionResponseAsync:(WMPPNDProximityDetectionType)pdType
                    transmitterChannelBytes:(id<NSFastEnumeration> /* uint8_t */)transmitterChannelBytes
                             sessionIDBytes:(id<NSFastEnumeration> /* uint8_t */)sessionIDBytes
                          responseDataBytes:(id<NSFastEnumeration> /* uint8_t */)responseDataBytes
                                    success:(void (^)(RTObject<WMPPINDSendResult>*))success
                                    failure:(void (^)(NSError*))failure;
- (void)sendLicenseFetchRequestAsync:(id<NSFastEnumeration> /* uint8_t */)sessionIDBytes
                  challengeDataBytes:(id<NSFastEnumeration> /* uint8_t */)challengeDataBytes
                             success:(void (^)(RTObject<WMPPINDSendResult>*))success
                             failure:(void (^)(NSError*))failure;
@end

#endif // __WMPPNDTCPMessenger_DEFINED__

// Windows.Media.Protection.PlayReady.NDLicenseFetchDescriptor
#ifndef __WMPPNDLicenseFetchDescriptor_DEFINED__
#define __WMPPNDLicenseFetchDescriptor_DEFINED__

WINRT_EXPORT
@interface WMPPNDLicenseFetchDescriptor : RTObject <WMPPINDLicenseFetchDescriptor>
+ (WMPPNDLicenseFetchDescriptor*)createInstance:(WMPPNDContentIDType)contentIDType
                                 contentIDBytes:(id<NSFastEnumeration> /* uint8_t */)contentIDBytes
                licenseFetchChallengeCustomData:(RTObject<WMPPINDCustomData>*)licenseFetchChallengeCustomData ACTIVATOR;
@property (copy) RTObject<WMPPINDCustomData>* licenseFetchChallengeCustomData;
@property (readonly) NSArray* contentID;
@property (readonly) WMPPNDContentIDType contentIDType;
@end

#endif // __WMPPNDLicenseFetchDescriptor_DEFINED__

// Windows.Media.Protection.PlayReady.NDCustomData
#ifndef __WMPPNDCustomData_DEFINED__
#define __WMPPNDCustomData_DEFINED__

WINRT_EXPORT
@interface WMPPNDCustomData : RTObject <WMPPINDCustomData>
+ (WMPPNDCustomData*)createInstance:(id<NSFastEnumeration> /* uint8_t */)customDataTypeIDBytes
                    customDataBytes:(id<NSFastEnumeration> /* uint8_t */)customDataBytes ACTIVATOR;
@property (readonly) NSArray* customData;
@property (readonly) NSArray* customDataTypeID;
@end

#endif // __WMPPNDCustomData_DEFINED__

// Windows.Media.Protection.PlayReady.NDClient
#ifndef __WMPPNDClient_DEFINED__
#define __WMPPNDClient_DEFINED__

WINRT_EXPORT
@interface WMPPNDClient : RTObject
+ (WMPPNDClient*)createInstance:(RTObject<WMPPINDDownloadEngine>*)downloadEngine
                   streamParser:(RTObject<WMPPINDStreamParser>*)streamParser
                     pMessenger:(RTObject<WMPPINDMessenger>*)pMessenger ACTIVATOR;
- (EventRegistrationToken)addClosedCaptionDataReceivedEvent:(void (^)(WMPPNDClient*,
                                                                      RTObject<WMPPINDClosedCaptionDataReceivedEventArgs>*))del;
- (void)removeClosedCaptionDataReceivedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addLicenseFetchCompletedEvent:(void (^)(WMPPNDClient*, RTObject<WMPPINDLicenseFetchCompletedEventArgs>*))del;
- (void)removeLicenseFetchCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addProximityDetectionCompletedEvent:(void (^)(WMPPNDClient*,
                                                                        RTObject<WMPPINDProximityDetectionCompletedEventArgs>*))del;
- (void)removeProximityDetectionCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addReRegistrationNeededEvent:(void (^)(WMPPNDClient*, RTObject*))del;
- (void)removeReRegistrationNeededEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addRegistrationCompletedEvent:(void (^)(WMPPNDClient*, RTObject<WMPPINDRegistrationCompletedEventArgs>*))del;
- (void)removeRegistrationCompletedEvent:(EventRegistrationToken)tok;
- (void)startAsync:(WFUri*)contentUrl
         startAsyncOptions:(unsigned int)startAsyncOptions
    registrationCustomData:(RTObject<WMPPINDCustomData>*)registrationCustomData
    licenseFetchDescriptor:(RTObject<WMPPINDLicenseFetchDescriptor>*)licenseFetchDescriptor
                   success:(void (^)(RTObject<WMPPINDStartResult>*))success
                   failure:(void (^)(NSError*))failure;
- (void)licenseFetchAsync:(RTObject<WMPPINDLicenseFetchDescriptor>*)licenseFetchDescriptor
                  success:(void (^)(RTObject<WMPPINDLicenseFetchResult>*))success
                  failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)reRegistrationAsync:(RTObject<WMPPINDCustomData>*)registrationCustomData;
- (void)close;
@end

#endif // __WMPPNDClient_DEFINED__

// Windows.Media.Protection.PlayReady.NDStorageFileHelper
#ifndef __WMPPNDStorageFileHelper_DEFINED__
#define __WMPPNDStorageFileHelper_DEFINED__

WINRT_EXPORT
@interface WMPPNDStorageFileHelper : RTObject <WMPPINDStorageFileHelper>
+ (instancetype)create ACTIVATOR;
- (NSMutableArray*)getFileURLs:(RTObject<WSIStorageFile>*)file;
@end

#endif // __WMPPNDStorageFileHelper_DEFINED__
