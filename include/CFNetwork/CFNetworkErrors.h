//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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
#pragma once

#import <CFNetwork/CFNetworkExport.h>
#import <CoreFoundation/CFString.h>

typedef CF_ENUM(CFIndex, CFNetworkErrors) {
    kCFHostErrorHostNotFound = 1,
    kCFHostErrorUnknown = 2,
    /* SOCKS errors */ kCFSOCKSErrorUnknownClientVersion = 100,
    kCFSOCKSErrorUnsupportedServerVersion = 101,
    /* SOCKS4-specific errors */ kCFSOCKS4ErrorRequestFailed = 110,
    kCFSOCKS4ErrorIdentdFailed = 111,
    kCFSOCKS4ErrorIdConflict = 112,
    kCFSOCKS4ErrorUnknownStatusCode = 113,
    /* SOCKS5-specific errors */ kCFSOCKS5ErrorBadState = 120,
    kCFSOCKS5ErrorBadResponseAddr = 121,
    kCFSOCKS5ErrorBadCredentials = 122,
    kCFSOCKS5ErrorUnsupportedNegotiationMethod = 123,
    kCFSOCKS5ErrorNoAcceptableMethod = 124,
    /* FTP errors */ kCFFTPErrorUnexpectedStatusCode = 200,
    /* HTTP errors */ kCFErrorHTTPAuthenticationTypeUnsupported = 300,
    kCFErrorHTTPBadCredentials = 301,
    kCFErrorHTTPConnectionLost = 302,
    kCFErrorHTTPParseFailure = 303,
    kCFErrorHTTPRedirectionLoopDetected = 304,
    kCFErrorHTTPBadURL = 305,
    kCFErrorHTTPProxyConnectionFailure = 306,
    kCFErrorHTTPBadProxyCredentials = 307,
    kCFErrorPACFileError = 308,
    kCFErrorPACFileAuth = 309,
    kCFErrorHTTPSProxyConnectionFailure = 310,
    kCFStreamErrorHTTPSProxyFailureUnexpectedResponseToCONNECTMethod = 311,
    /* CFURL and CFURLConnection Errors */ kCFURLErrorUnknown = -998,
    kCFURLErrorCancelled = -999,
    kCFURLErrorBadURL = -1000,
    kCFURLErrorTimedOut = -1001,
    kCFURLErrorUnsupportedURL = -1002,
    kCFURLErrorCannotFindHost = -1003,
    kCFURLErrorCannotConnectToHost = -1004,
    kCFURLErrorNetworkConnectionLost = -1005,
    kCFURLErrorDNSLookupFailed = -1006,
    kCFURLErrorHTTPTooManyRedirects = -1007,
    kCFURLErrorResourceUnavailable = -1008,
    kCFURLErrorNotConnectedToInternet = -1009,
    kCFURLErrorRedirectToNonExistentLocation = -1010,
    kCFURLErrorBadServerResponse = -1011,
    kCFURLErrorUserCancelledAuthentication = -1012,
    kCFURLErrorUserAuthenticationRequired = -1013,
    kCFURLErrorZeroByteResource = -1014,
    kCFURLErrorCannotDecodeRawData = -1015,
    kCFURLErrorCannotDecodeContentData = -1016,
    kCFURLErrorCannotParseResponse = -1017,
    kCFURLErrorInternationalRoamingOff = -1018,
    kCFURLErrorCallIsActive = -1019,
    kCFURLErrorDataNotAllowed = -1020,
    kCFURLErrorRequestBodyStreamExhausted = -1021,
    kCFURLErrorFileDoesNotExist = -1100,
    kCFURLErrorFileIsDirectory = -1101,
    kCFURLErrorNoPermissionsToReadFile = -1102,
    kCFURLErrorDataLengthExceedsMaximum = -1103,
    /* SSL errors */ kCFURLErrorSecureConnectionFailed = -1200,
    kCFURLErrorServerCertificateHasBadDate = -1201,
    kCFURLErrorServerCertificateUntrusted = -1202,
    kCFURLErrorServerCertificateHasUnknownRoot = -1203,
    kCFURLErrorServerCertificateNotYetValid = -1204,
    kCFURLErrorClientCertificateRejected = -1205,
    kCFURLErrorClientCertificateRequired = -1206,
    kCFURLErrorCannotLoadFromNetwork = -2000,
    /* Download and file I/O errors */ kCFURLErrorCannotCreateFile = -3000,
    kCFURLErrorCannotOpenFile = -3001,
    kCFURLErrorCannotCloseFile = -3002,
    kCFURLErrorCannotWriteToFile = -3003,
    kCFURLErrorCannotRemoveFile = -3004,
    kCFURLErrorCannotMoveFile = -3005,
    kCFURLErrorDownloadDecodingFailedMidStream = -3006,
    kCFURLErrorDownloadDecodingFailedToComplete = -3007,
    /* Cookie errors */ kCFHTTPCookieCannotParseCookieFile = -4000,
    /* Errors originating from CFNetServices */ kCFNetServiceErrorUnknown = -72000L,
    kCFNetServiceErrorCollision = -72001L,
    kCFNetServiceErrorNotFound = -72002L,
    kCFNetServiceErrorInProgress = -72003L,
    kCFNetServiceErrorBadArgument = -72004L,
    kCFNetServiceErrorCancel = -72005L,
    kCFNetServiceErrorInvalid = -72006L,
    kCFNetServiceErrorTimeout = -72007L,
    kCFNetServiceErrorDNSServiceFailure = -73000L,
};

CFNETWORK_EXPORT const CFStringRef kCFURLErrorFailingURLErrorKey;
CFNETWORK_EXPORT const CFStringRef kCFURLErrorFailingURLStringErrorKey;
CFNETWORK_EXPORT const CFStringRef kCFGetAddrInfoFailureKey;
CFNETWORK_EXPORT const CFStringRef kCFSOCKSStatusCodeKey;
CFNETWORK_EXPORT const CFStringRef kCFSOCKSVersionKey;
CFNETWORK_EXPORT const CFStringRef kCFSOCKSNegotiationMethodKey;
CFNETWORK_EXPORT const CFStringRef kCFDNSServiceFailureKey;
CFNETWORK_EXPORT const CFStringRef kCFFTPStatusCodeKey;
CFNETWORK_EXPORT const CFStringRef kCFErrorDomainCFNetwork;
CFNETWORK_EXPORT const CFStringRef kCFErrorDomainWinSock;
