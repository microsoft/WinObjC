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

// WindowsMediaProtection.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WMPMediaProtectionManager, WMPServiceRequestedEventArgs, WMPComponentLoadFailedEventArgs, WMPMediaProtectionServiceCompletion,
    WMPRevocationAndRenewalInformation, WMPRevocationAndRenewalItem, WMPMediaProtectionPMPServer;
@protocol WMPIMediaProtectionManager
, WMPIMediaProtectionServiceCompletion, WMPIServiceRequestedEventArgs, WMPIMediaProtectionServiceRequest, WMPIServiceRequestedEventArgs2,
    WMPIComponentLoadFailedEventArgs, WMPIRevocationAndRenewalInformation, WMPIRevocationAndRenewalItem,
    WMPIMediaProtectionPMPServerFactory, WMPIMediaProtectionPMPServer;

// Windows.Media.Protection.RevocationAndRenewalReasons
enum _WMPRevocationAndRenewalReasons {
    WMPRevocationAndRenewalReasonsUserModeComponentLoad = 1,
    WMPRevocationAndRenewalReasonsKernelModeComponentLoad = 2,
    WMPRevocationAndRenewalReasonsAppComponent = 4,
    WMPRevocationAndRenewalReasonsGlobalRevocationListLoadFailed = 16,
    WMPRevocationAndRenewalReasonsInvalidGlobalRevocationListSignature = 32,
    WMPRevocationAndRenewalReasonsGlobalRevocationListAbsent = 4096,
    WMPRevocationAndRenewalReasonsComponentRevoked = 8192,
    WMPRevocationAndRenewalReasonsInvalidComponentCertificateExtendedKeyUse = 16384,
    WMPRevocationAndRenewalReasonsComponentCertificateRevoked = 32768,
    WMPRevocationAndRenewalReasonsInvalidComponentCertificateRoot = 65536,
    WMPRevocationAndRenewalReasonsComponentHighSecurityCertificateRevoked = 131072,
    WMPRevocationAndRenewalReasonsComponentLowSecurityCertificateRevoked = 262144,
    WMPRevocationAndRenewalReasonsBootDriverVerificationFailed = 1048576,
    WMPRevocationAndRenewalReasonsComponentSignedWithTestCertificate = 16777216,
    WMPRevocationAndRenewalReasonsEncryptionFailure = 268435456,
};
typedef unsigned WMPRevocationAndRenewalReasons;

// Windows.Media.Protection.GraphicsTrustStatus
enum _WMPGraphicsTrustStatus {
    WMPGraphicsTrustStatusTrustNotRequired = 0,
    WMPGraphicsTrustStatusTrustEstablished = 1,
    WMPGraphicsTrustStatusEnvironmentNotSupported = 2,
    WMPGraphicsTrustStatusDriverNotSupported = 3,
    WMPGraphicsTrustStatusDriverSigningFailure = 4,
    WMPGraphicsTrustStatusUnknownFailure = 5,
};
typedef unsigned WMPGraphicsTrustStatus;

#include "WindowsFoundation.h"
#include "WindowsFoundationCollections.h"
#include "WindowsMediaPlayback.h"
// Windows.Media.Protection.ComponentLoadFailedEventHandler
#ifndef __WMPComponentLoadFailedEventHandler__DEFINED
#define __WMPComponentLoadFailedEventHandler__DEFINED
typedef void (^WMPComponentLoadFailedEventHandler)(WMPMediaProtectionManager* sender, WMPComponentLoadFailedEventArgs* e);
#endif // __WMPComponentLoadFailedEventHandler__DEFINED

// Windows.Media.Protection.RebootNeededEventHandler
#ifndef __WMPRebootNeededEventHandler__DEFINED
#define __WMPRebootNeededEventHandler__DEFINED
typedef void (^WMPRebootNeededEventHandler)(WMPMediaProtectionManager* sender);
#endif // __WMPRebootNeededEventHandler__DEFINED

// Windows.Media.Protection.ServiceRequestedEventHandler
#ifndef __WMPServiceRequestedEventHandler__DEFINED
#define __WMPServiceRequestedEventHandler__DEFINED
typedef void (^WMPServiceRequestedEventHandler)(WMPMediaProtectionManager* sender, WMPServiceRequestedEventArgs* e);
#endif // __WMPServiceRequestedEventHandler__DEFINED

#import <Foundation/Foundation.h>

// Windows.Media.Protection.ServiceRequestedEventHandler
#ifndef __WMPServiceRequestedEventHandler__DEFINED
#define __WMPServiceRequestedEventHandler__DEFINED
typedef void (^WMPServiceRequestedEventHandler)(WMPMediaProtectionManager* sender, WMPServiceRequestedEventArgs* e);
#endif // __WMPServiceRequestedEventHandler__DEFINED

// Windows.Media.Protection.RebootNeededEventHandler
#ifndef __WMPRebootNeededEventHandler__DEFINED
#define __WMPRebootNeededEventHandler__DEFINED
typedef void (^WMPRebootNeededEventHandler)(WMPMediaProtectionManager* sender);
#endif // __WMPRebootNeededEventHandler__DEFINED

// Windows.Media.Protection.ComponentLoadFailedEventHandler
#ifndef __WMPComponentLoadFailedEventHandler__DEFINED
#define __WMPComponentLoadFailedEventHandler__DEFINED
typedef void (^WMPComponentLoadFailedEventHandler)(WMPMediaProtectionManager* sender, WMPComponentLoadFailedEventArgs* e);
#endif // __WMPComponentLoadFailedEventHandler__DEFINED

// Windows.Media.Protection.IMediaProtectionServiceRequest
#ifndef __WMPIMediaProtectionServiceRequest_DEFINED__
#define __WMPIMediaProtectionServiceRequest_DEFINED__

@protocol WMPIMediaProtectionServiceRequest
@property (readonly) WFGUID* protectionSystem;
@property (readonly) WFGUID* type;
@end

#endif // __WMPIMediaProtectionServiceRequest_DEFINED__

// Windows.Media.Protection.MediaProtectionManager
#ifndef __WMPMediaProtectionManager_DEFINED__
#define __WMPMediaProtectionManager_DEFINED__

WINRT_EXPORT
@interface WMPMediaProtectionManager : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) RTObject<WFCIPropertySet>* properties;
- (EventRegistrationToken)addComponentLoadFailedEvent:(WMPComponentLoadFailedEventHandler)del;
- (void)removeComponentLoadFailedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addRebootNeededEvent:(WMPRebootNeededEventHandler)del;
- (void)removeRebootNeededEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addServiceRequestedEvent:(WMPServiceRequestedEventHandler)del;
- (void)removeServiceRequestedEvent:(EventRegistrationToken)tok;
@end

#endif // __WMPMediaProtectionManager_DEFINED__

// Windows.Media.Protection.ServiceRequestedEventArgs
#ifndef __WMPServiceRequestedEventArgs_DEFINED__
#define __WMPServiceRequestedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMPServiceRequestedEventArgs : RTObject
@property (readonly) WMPMediaProtectionServiceCompletion* completion;
@property (readonly) RTObject<WMPIMediaProtectionServiceRequest>* request;
@property (readonly) WMPMediaPlaybackItem* mediaPlaybackItem;
@end

#endif // __WMPServiceRequestedEventArgs_DEFINED__

// Windows.Media.Protection.ComponentLoadFailedEventArgs
#ifndef __WMPComponentLoadFailedEventArgs_DEFINED__
#define __WMPComponentLoadFailedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMPComponentLoadFailedEventArgs : RTObject
@property (readonly) WMPMediaProtectionServiceCompletion* completion;
@property (readonly) WMPRevocationAndRenewalInformation* information;
@end

#endif // __WMPComponentLoadFailedEventArgs_DEFINED__

// Windows.Media.Protection.MediaProtectionServiceCompletion
#ifndef __WMPMediaProtectionServiceCompletion_DEFINED__
#define __WMPMediaProtectionServiceCompletion_DEFINED__

WINRT_EXPORT
@interface WMPMediaProtectionServiceCompletion : RTObject
- (void)complete:(BOOL)success;
@end

#endif // __WMPMediaProtectionServiceCompletion_DEFINED__

// Windows.Media.Protection.RevocationAndRenewalInformation
#ifndef __WMPRevocationAndRenewalInformation_DEFINED__
#define __WMPRevocationAndRenewalInformation_DEFINED__

WINRT_EXPORT
@interface WMPRevocationAndRenewalInformation : RTObject
@property (readonly) NSMutableArray* items;
@end

#endif // __WMPRevocationAndRenewalInformation_DEFINED__

// Windows.Media.Protection.RevocationAndRenewalItem
#ifndef __WMPRevocationAndRenewalItem_DEFINED__
#define __WMPRevocationAndRenewalItem_DEFINED__

WINRT_EXPORT
@interface WMPRevocationAndRenewalItem : RTObject
@property (readonly) NSString* headerHash;
@property (readonly) NSString* name;
@property (readonly) NSString* publicKeyHash;
@property (readonly) WMPRevocationAndRenewalReasons reasons;
@property (readonly) NSString* renewalId;
@end

#endif // __WMPRevocationAndRenewalItem_DEFINED__

// Windows.Media.Protection.MediaProtectionPMPServer
#ifndef __WMPMediaProtectionPMPServer_DEFINED__
#define __WMPMediaProtectionPMPServer_DEFINED__

WINRT_EXPORT
@interface WMPMediaProtectionPMPServer : RTObject
+ (WMPMediaProtectionPMPServer*)createPMPServer:(RTObject<WFCIPropertySet>*)pProperties ACTIVATOR;
@property (readonly) RTObject<WFCIPropertySet>* properties;
@end

#endif // __WMPMediaProtectionPMPServer_DEFINED__
