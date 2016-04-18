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

const CFStringRef kCFStreamPropertyShouldCloseNativeSocket = static_cast<CFStringRef>(@"kCFStreamPropertyShouldCloseNativeSocket");
const CFStringRef kCFStreamPropertySocketSecurityLevel = static_cast<CFStringRef>(@"kCFStreamPropertySocketSecurityLevel");
const CFStringRef kCFStreamPropertySOCKSProxy = static_cast<CFStringRef>(@"kCFStreamPropertySOCKSProxy");
const CFStringRef kCFStreamPropertySSLPeerCertificates = static_cast<CFStringRef>(@"kCFStreamPropertySSLPeerCertificates");
const CFStringRef kCFStreamPropertySSLPeerTrust = static_cast<CFStringRef>(@"kCFStreamPropertySSLPeerTrust");
const CFStringRef kCFStreamPropertySSLSettings = static_cast<CFStringRef>(@"kCFStreamPropertySSLSettings");
const CFStringRef kCFStreamPropertySSLContext = static_cast<CFStringRef>(@"kCFStreamPropertySSLContext");
const CFStringRef kCFStreamPropertyProxyLocalByPass = static_cast<CFStringRef>(@"kCFStreamPropertyProxyLocalByPass");
const CFStringRef kCFStreamPropertySocketRemoteHost = static_cast<CFStringRef>(@"kCFStreamPropertySocketRemoteHost");
const CFStringRef kCFStreamPropertySocketRemoteNetService = static_cast<CFStringRef>(@"kCFStreamPropertySocketRemoteNetService");
const CFStringRef kCFStreamNetworkServiceType = static_cast<CFStringRef>(@"kCFStreamNetworkServiceType");
const CFStringRef kCFStreamPropertyConnectionIsCellular = static_cast<CFStringRef>(@"kCFStreamPropertyConnectionIsCellular");
const CFStringRef kCFStreamPropertyNoCellular = static_cast<CFStringRef>(@"kCFStreamPropertyNoCellular");
const CFStringRef kCFStreamSSLLevel = static_cast<CFStringRef>(@"kCFStreamSSLLevel");
const CFStringRef kCFStreamSSLAllowsExpiredCertificates = static_cast<CFStringRef>(@"kCFStreamSSLAllowsExpiredCertificates");
const CFStringRef kCFStreamSSLAllowsExpiredRoots = static_cast<CFStringRef>(@"kCFStreamSSLAllowsExpiredRoots");
const CFStringRef kCFStreamSSLAllowsAnyRoot = static_cast<CFStringRef>(@"kCFStreamSSLAllowsAnyRoot");
const CFStringRef kCFStreamSSLValidatesCertificateChain = static_cast<CFStringRef>(@"kCFStreamSSLValidatesCertificateChain");
const CFStringRef kCFStreamSSLPeerName = static_cast<CFStringRef>(@"kCFStreamSSLPeerName");
const CFStringRef kCFStreamSSLCertificates = static_cast<CFStringRef>(@"kCFStreamSSLCertificates");
const CFStringRef kCFStreamSSLIsServer = static_cast<CFStringRef>(@"kCFStreamSSLIsServer");
const CFStringRef kCFStreamSocketSecurityLevelNone = static_cast<CFStringRef>(@"kCFStreamSocketSecurityLevelNone");
const CFStringRef kCFStreamSocketSecurityLevelSSLv2 = static_cast<CFStringRef>(@"kCFStreamSocketSecurityLevelSSLv2");
const CFStringRef kCFStreamSocketSecurityLevelSSLv3 = static_cast<CFStringRef>(@"kCFStreamSocketSecurityLevelSSLv3");
const CFStringRef kCFStreamSocketSecurityLevelTLSv1 = static_cast<CFStringRef>(@"kCFStreamSocketSecurityLevelTLSv1");
const CFStringRef kCFStreamSocketSecurityLevelNegotiatedSSL = static_cast<CFStringRef>(@"kCFStreamSocketSecurityLevelNegotiatedSSL");
const CFStringRef kCFStreamPropertySOCKSProxyHost = static_cast<CFStringRef>(@"kCFStreamPropertySOCKSProxyHost");
const CFStringRef kCFStreamPropertySOCKSProxyPort = static_cast<CFStringRef>(@"kCFStreamPropertySOCKSProxyPort");
const CFStringRef kCFStreamPropertySOCKSVersion = static_cast<CFStringRef>(@"kCFStreamPropertySOCKSVersion");
const CFStringRef kCFStreamSocketSOCKSVersion4 = static_cast<CFStringRef>(@"kCFStreamSocketSOCKSVersion4");
const CFStringRef kCFStreamSocketSOCKSVersion5 = static_cast<CFStringRef>(@"kCFStreamSocketSOCKSVersion5");
const CFStringRef kCFStreamPropertySOCKSUser = static_cast<CFStringRef>(@"kCFStreamPropertySOCKSUser");
const CFStringRef kCFStreamPropertySOCKSPassword = static_cast<CFStringRef>(@"kCFStreamPropertySOCKSPassword");
const CFStringRef kCFStreamNetworkServiceTypeVoIP = static_cast<CFStringRef>(@"kCFStreamNetworkServiceTypeVoIP");
const CFStringRef kCFStreamNetworkServiceTypeVideo = static_cast<CFStringRef>(@"kCFStreamNetworkServiceTypeVideo");
const CFStringRef kCFStreamNetworkServiceTypeBackground = static_cast<CFStringRef>(@"kCFStreamNetworkServiceTypeBackground");
const CFStringRef kCFStreamNetworkServiceTypeVoice = static_cast<CFStringRef>(@"kCFStreamNetworkServiceTypeVoice");
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
