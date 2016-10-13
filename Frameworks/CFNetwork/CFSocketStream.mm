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

#import <StubReturn.h>
#import <CFNetwork/CFSocketStream.h>

const CFStringRef kCFStreamPropertyShouldCloseNativeSocket = CFSTR("kCFStreamPropertyShouldCloseNativeSocket");
const CFStringRef kCFStreamPropertySocketSecurityLevel = CFSTR("kCFStreamPropertySocketSecurityLevel");
const CFStringRef kCFStreamPropertySOCKSProxy = CFSTR("kCFStreamPropertySOCKSProxy");
const CFStringRef kCFStreamPropertySSLPeerCertificates = CFSTR("kCFStreamPropertySSLPeerCertificates");
const CFStringRef kCFStreamPropertySSLPeerTrust = CFSTR("kCFStreamPropertySSLPeerTrust");
const CFStringRef kCFStreamPropertySSLSettings = CFSTR("kCFStreamPropertySSLSettings");
const CFStringRef kCFStreamPropertySSLContext = CFSTR("kCFStreamPropertySSLContext");
const CFStringRef kCFStreamPropertyProxyLocalByPass = CFSTR("kCFStreamPropertyProxyLocalByPass");
const CFStringRef kCFStreamPropertySocketRemoteHost = CFSTR("kCFStreamPropertySocketRemoteHost");
const CFStringRef kCFStreamPropertySocketRemoteNetService = CFSTR("kCFStreamPropertySocketRemoteNetService");
const CFStringRef kCFStreamNetworkServiceType = CFSTR("kCFStreamNetworkServiceType");
const CFStringRef kCFStreamPropertyConnectionIsCellular = CFSTR("kCFStreamPropertyConnectionIsCellular");
const CFStringRef kCFStreamPropertyNoCellular = CFSTR("kCFStreamPropertyNoCellular");
const CFStringRef kCFStreamSSLLevel = CFSTR("kCFStreamSSLLevel");
const CFStringRef kCFStreamSSLAllowsExpiredCertificates = CFSTR("kCFStreamSSLAllowsExpiredCertificates");
const CFStringRef kCFStreamSSLAllowsExpiredRoots = CFSTR("kCFStreamSSLAllowsExpiredRoots");
const CFStringRef kCFStreamSSLAllowsAnyRoot = CFSTR("kCFStreamSSLAllowsAnyRoot");
const CFStringRef kCFStreamSSLValidatesCertificateChain = CFSTR("kCFStreamSSLValidatesCertificateChain");
const CFStringRef kCFStreamSSLPeerName = CFSTR("kCFStreamSSLPeerName");
const CFStringRef kCFStreamSSLCertificates = CFSTR("kCFStreamSSLCertificates");
const CFStringRef kCFStreamSSLIsServer = CFSTR("kCFStreamSSLIsServer");
const CFStringRef kCFStreamSocketSecurityLevelNone = CFSTR("kCFStreamSocketSecurityLevelNone");
const CFStringRef kCFStreamSocketSecurityLevelSSLv2 = CFSTR("kCFStreamSocketSecurityLevelSSLv2");
const CFStringRef kCFStreamSocketSecurityLevelSSLv3 = CFSTR("kCFStreamSocketSecurityLevelSSLv3");
const CFStringRef kCFStreamSocketSecurityLevelTLSv1 = CFSTR("kCFStreamSocketSecurityLevelTLSv1");
const CFStringRef kCFStreamSocketSecurityLevelNegotiatedSSL = CFSTR("kCFStreamSocketSecurityLevelNegotiatedSSL");
const CFStringRef kCFStreamPropertySOCKSProxyHost = CFSTR("kCFStreamPropertySOCKSProxyHost");
const CFStringRef kCFStreamPropertySOCKSProxyPort = CFSTR("kCFStreamPropertySOCKSProxyPort");
const CFStringRef kCFStreamPropertySOCKSVersion = CFSTR("kCFStreamPropertySOCKSVersion");
const CFStringRef kCFStreamSocketSOCKSVersion4 = CFSTR("kCFStreamSocketSOCKSVersion4");
const CFStringRef kCFStreamSocketSOCKSVersion5 = CFSTR("kCFStreamSocketSOCKSVersion5");
const CFStringRef kCFStreamPropertySOCKSUser = CFSTR("kCFStreamPropertySOCKSUser");
const CFStringRef kCFStreamPropertySOCKSPassword = CFSTR("kCFStreamPropertySOCKSPassword");
const CFStringRef kCFStreamNetworkServiceTypeVoIP = CFSTR("kCFStreamNetworkServiceTypeVoIP");
const CFStringRef kCFStreamNetworkServiceTypeVideo = CFSTR("kCFStreamNetworkServiceTypeVideo");
const CFStringRef kCFStreamNetworkServiceTypeBackground = CFSTR("kCFStreamNetworkServiceTypeBackground");
const CFStringRef kCFStreamNetworkServiceTypeVoice = CFSTR("kCFStreamNetworkServiceTypeVoice");
const int kCFStreamErrorDomainSOCKS = StubConstant();
const int kCFStreamErrorDomainSSL = StubConstant();
const CFIndex kCFStreamErrorDomainWinSock = StubConstant();

/**
 @Status Stub
 @Notes
*/
void CFStreamCreatePairWithSocketToCFHost(
    CFAllocatorRef alloc, CFHostRef host, SInt32 port, CFReadStreamRef _Nullable* readStream, CFWriteStreamRef _Nullable* writeStream) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CFStreamCreatePairWithSocketToNetService(CFAllocatorRef alloc,
                                              CFNetServiceRef service,
                                              CFReadStreamRef _Nullable* readStream,
                                              CFWriteStreamRef _Nullable* writeStream) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
SInt32 CFSocketStreamSOCKSGetError(const CFStreamError* error) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
SInt32 CFSocketStreamSOCKSGetErrorSubdomain(const CFStreamError* error) {
    UNIMPLEMENTED();
    return StubReturn();
}
