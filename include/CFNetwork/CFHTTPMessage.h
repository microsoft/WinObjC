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
#import <CFNetwork/CFHTTPAuthentication.h>
#import <CoreFoundation/CoreFoundation.h>

CFNETWORK_EXPORT CFHTTPMessageRef CFHTTPMessageCreateCopy(CFAllocatorRef alloc, CFHTTPMessageRef message) STUB_METHOD;
CFNETWORK_EXPORT CFHTTPMessageRef CFHTTPMessageCreateEmpty(CFAllocatorRef alloc, Boolean isRequest) STUB_METHOD;
CFNETWORK_EXPORT CFHTTPMessageRef CFHTTPMessageCreateRequest(CFAllocatorRef alloc,
                                                             CFStringRef requestMethod,
                                                             CFURLRef url,
                                                             CFStringRef httpVersion) STUB_METHOD;

CFNETWORK_EXPORT CFHTTPMessageRef CFHTTPMessageCreateResponse(CFAllocatorRef alloc,
                                                              CFIndex statusCode,
                                                              CFStringRef statusDescription,
                                                              CFStringRef httpVersion) STUB_METHOD;

CFNETWORK_EXPORT Boolean CFHTTPMessageAppendBytes(CFHTTPMessageRef message, const UInt8* newBytes, CFIndex numBytes) STUB_METHOD;
CFNETWORK_EXPORT void CFHTTPMessageSetBody(CFHTTPMessageRef message, CFDataRef bodyData) STUB_METHOD;
CFNETWORK_EXPORT void CFHTTPMessageSetHeaderFieldValue(CFHTTPMessageRef message, CFStringRef headerField, CFStringRef value) STUB_METHOD;
CFNETWORK_EXPORT CFDataRef CFHTTPMessageCopyBody(CFHTTPMessageRef message) STUB_METHOD;
CFNETWORK_EXPORT CFDictionaryRef CFHTTPMessageCopyAllHeaderFields(CFHTTPMessageRef message) STUB_METHOD;
CFNETWORK_EXPORT CFStringRef CFHTTPMessageCopyHeaderFieldValue(CFHTTPMessageRef message, CFStringRef headerField) STUB_METHOD;
CFNETWORK_EXPORT CFStringRef CFHTTPMessageCopyRequestMethod(CFHTTPMessageRef request) STUB_METHOD;
CFNETWORK_EXPORT CFURLRef CFHTTPMessageCopyRequestURL(CFHTTPMessageRef request) STUB_METHOD;
CFNETWORK_EXPORT CFDataRef CFHTTPMessageCopySerializedMessage(CFHTTPMessageRef message) STUB_METHOD;
CFNETWORK_EXPORT CFStringRef CFHTTPMessageCopyVersion(CFHTTPMessageRef message) STUB_METHOD;
CFNETWORK_EXPORT Boolean CFHTTPMessageIsRequest(CFHTTPMessageRef message) STUB_METHOD;
CFNETWORK_EXPORT Boolean CFHTTPMessageIsHeaderComplete(CFHTTPMessageRef message) STUB_METHOD;
CFNETWORK_EXPORT CFIndex CFHTTPMessageGetResponseStatusCode(CFHTTPMessageRef response) STUB_METHOD;
CFNETWORK_EXPORT CFStringRef CFHTTPMessageCopyResponseStatusLine(CFHTTPMessageRef response) STUB_METHOD;
CFNETWORK_EXPORT Boolean CFHTTPMessageApplyCredentials(
    CFHTTPMessageRef request, CFHTTPAuthenticationRef auth, CFStringRef username, CFStringRef password, CFStreamError* error) STUB_METHOD;

CFNETWORK_EXPORT Boolean CFHTTPMessageApplyCredentialDictionary(CFHTTPMessageRef request,
                                                                CFHTTPAuthenticationRef auth,
                                                                CFDictionaryRef dict,
                                                                CFStreamError* error) STUB_METHOD;

CFNETWORK_EXPORT Boolean CFHTTPMessageAddAuthentication(CFHTTPMessageRef request,
                                                        CFHTTPMessageRef authenticationFailureResponse,
                                                        CFStringRef username,
                                                        CFStringRef password,
                                                        CFStringRef authenticationScheme,
                                                        Boolean forProxy) STUB_METHOD;

CFNETWORK_EXPORT CFTypeID CFHTTPMessageGetTypeID() STUB_METHOD;

CFNETWORK_EXPORT const CFStringRef kCFHTTPVersion1_0;
CFNETWORK_EXPORT const CFStringRef kCFHTTPVersion1_1;
CFNETWORK_EXPORT const CFStringRef kCFHTTPAuthenticationSchemeBasic;
CFNETWORK_EXPORT const CFStringRef kCFHTTPAuthenticationSchemeDigest;
CFNETWORK_EXPORT const CFStringRef kCFHTTPAuthenticationSchemeNTLM;
CFNETWORK_EXPORT const CFStringRef kCFHTTPAuthenticationSchemeNegotiate;
CFNETWORK_EXPORT const CFStringRef kCFHTTPAuthenticationSchemeKerberos;
CFNETWORK_EXPORT const CFStringRef kCFHTTPAuthenticationSchemeNegotiate2;
CFNETWORK_EXPORT const CFStringRef kCFHTTPAuthenticationSchemeOAuth1;
CFNETWORK_EXPORT const CFStringRef kCFHTTPAuthenticationSchemeXMobileMeAuthToken;
