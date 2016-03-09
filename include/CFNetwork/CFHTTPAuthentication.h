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
#import <CFNetwork/CFNetworkBase.h>
#import <CFNetwork/CFHTTPMessage.h>
#import <CoreFoundation/CoreFoundation.h>

typedef CF_ENUM(CFIndex, CFStreamErrorHTTPAuthentication) {
    kCFStreamErrorHTTPAuthenticationTypeUnsupported = -1000,
    kCFStreamErrorHTTPAuthenticationBadUserName = -1001,
    kCFStreamErrorHTTPAuthenticationBadPassword = -1002
};

CFNETWORK_EXPORT CFHTTPAuthenticationRef CFHTTPAuthenticationCreateFromResponse(CFAllocatorRef alloc,
                                                                                CFHTTPMessageRef response) STUB_METHOD;
CFNETWORK_EXPORT Boolean CFHTTPAuthenticationAppliesToRequest(CFHTTPAuthenticationRef auth, CFHTTPMessageRef request) STUB_METHOD;
CFNETWORK_EXPORT CFArrayRef CFHTTPAuthenticationCopyDomains(CFHTTPAuthenticationRef auth) STUB_METHOD;
CFNETWORK_EXPORT CFStringRef CFHTTPAuthenticationCopyMethod(CFHTTPAuthenticationRef auth) STUB_METHOD;
CFNETWORK_EXPORT CFStringRef CFHTTPAuthenticationCopyRealm(CFHTTPAuthenticationRef auth) STUB_METHOD;
CFNETWORK_EXPORT Boolean CFHTTPAuthenticationIsValid(CFHTTPAuthenticationRef auth, CFStreamError* error) STUB_METHOD;
CFNETWORK_EXPORT Boolean CFHTTPAuthenticationRequiresAccountDomain(CFHTTPAuthenticationRef auth) STUB_METHOD;
CFNETWORK_EXPORT Boolean CFHTTPAuthenticationRequiresOrderedRequests(CFHTTPAuthenticationRef auth) STUB_METHOD;
CFNETWORK_EXPORT Boolean CFHTTPAuthenticationRequiresUserNameAndPassword(CFHTTPAuthenticationRef auth) STUB_METHOD;

CFNETWORK_EXPORT CFTypeID CFHTTPAuthenticationGetTypeID() STUB_METHOD;
CFNETWORK_EXPORT const CFStringRef kCFHTTPAuthenticationSchemeBasic;
CFNETWORK_EXPORT const CFStringRef kCFHTTPAuthenticationSchemeDigest;
CFNETWORK_EXPORT const CFStringRef kCFHTTPAuthenticationSchemeNegotiate;
CFNETWORK_EXPORT const CFStringRef kCFHTTPAuthenticationSchemeNTLM;
CFNETWORK_EXPORT const CFStringRef kCFHTTPAuthenticationUsername;
CFNETWORK_EXPORT const CFStringRef kCFHTTPAuthenticationPassword;
CFNETWORK_EXPORT const CFStringRef kCFHTTPAuthenticationAccountDomain;
