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

#ifndef _CFHTTPAUTHENTICATION_H_
#define _CFHTTPAUTHENTICATION_H_

#import <CoreFoundation/CFStream.h>
#import <CFNetwork/CFNetworkExport.h>
#import <CFNetwork/CFHTTPMessage.h>
#import <stdint.h>

typedef struct __CFHTTPAuthentication *CFHTTPAuthenticationRef;

enum {
    kCFStreamErrorHTTPAuthenticationTypeUnsupported = -1000,
    kCFStreamErrorHTTPAuthenticationBadUserName = -1001,
    kCFStreamErrorHTTPAuthenticationBadPassword = -1002
};
typedef uint32_t CFStreamErrorHTTPAuthentication;

CFNETWORK_EXPORT const CFStringRef kCFHTTPAuthenticationSchemeBasic;
CFNETWORK_EXPORT const CFStringRef kCFHTTPAuthenticationSchemeDigest;
CFNETWORK_EXPORT const CFStringRef kCFHTTPAuthenticationSchemeNTLM;
CFNETWORK_EXPORT const CFStringRef kCFHTTPAuthenticationSchemeNegotiate;

CFNETWORK_EXPORT const CFStringRef kCFHTTPAuthenticationUsername;
CFNETWORK_EXPORT const CFStringRef kCFHTTPAuthenticationPassword;
CFNETWORK_EXPORT const CFStringRef kCFHTTPAuthenticationAccountDomain;

CFNETWORK_EXPORT Boolean CFHTTPMessageApplyCredentialDictionary(CFHTTPMessageRef request, CFHTTPAuthenticationRef auth, CFDictionaryRef dict, CFStreamError *err);
CFNETWORK_EXPORT Boolean CFHTTPAuthenticationRequiresAccountDomain(CFHTTPAuthenticationRef auth);
CFNETWORK_EXPORT CFHTTPAuthenticationRef CFHTTPAuthenticationCreateFromResponse(CFAllocatorRef alloc, CFHTTPMessageRef reply);
CFNETWORK_EXPORT CFStringRef CFHTTPAuthenticationCopyMethod(CFHTTPAuthenticationRef auth);
CFNETWORK_EXPORT CFStringRef CFHTTPAuthenticationCopyRealm(CFHTTPAuthenticationRef auth);
CFNETWORK_EXPORT Boolean CFHTTPAuthenticationIsValid(CFHTTPAuthenticationRef auth, CFStreamError *err);
CFNETWORK_EXPORT Boolean CFHTTPAuthenticationRequiresUserNameAndPassword(CFHTTPAuthenticationRef auth);

#endif // _CFHTTPAUTHENTICATION_H_