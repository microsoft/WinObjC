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
#import <CFNetwork/CFHTTPMessage.h>
#import <CoreFoundation/CoreFoundation.h>

typedef CF_ENUM(CFIndex, CFStreamErrorHTTP) {
    kCFStreamErrorHTTPParseFailure = -1,
    kCFStreamErrorHTTPRedirectionLoop = -2,
    kCFStreamErrorHTTPBadURL = -3
};

CFNETWORK_EXPORT CFReadStreamRef CFReadStreamCreateForHTTPRequest(CFAllocatorRef alloc, CFHTTPMessageRef request) STUB_METHOD;
CFNETWORK_EXPORT CFReadStreamRef CFReadStreamCreateForStreamedHTTPRequest(CFAllocatorRef alloc,
                                                                          CFHTTPMessageRef requestHeaders,
                                                                          CFReadStreamRef requestBody) STUB_METHOD;

CFNETWORK_EXPORT const CFStringRef kCFStreamPropertyHTTPAttemptPersistentConnection;
CFNETWORK_EXPORT const CFStringRef kCFStreamPropertyHTTPFinalURL;
CFNETWORK_EXPORT const CFStringRef kCFStreamPropertyHTTPFinalRequest;
CFNETWORK_EXPORT const CFStringRef kCFStreamPropertyHTTPProxy;
CFNETWORK_EXPORT const CFStringRef kCFStreamPropertyHTTPRequestBytesWrittenCount;
CFNETWORK_EXPORT const CFStringRef kCFStreamPropertyHTTPResponseHeader;
CFNETWORK_EXPORT const CFStringRef kCFStreamPropertyHTTPShouldAutoredirect;

CFNETWORK_EXPORT const SInt32 kCFStreamErrorDomainHTTP;
