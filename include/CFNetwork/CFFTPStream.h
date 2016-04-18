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
#import <CoreFoundation/CoreFoundation.h>

CFNETWORK_EXPORT CFReadStreamRef CFReadStreamCreateWithFTPURL(CFAllocatorRef alloc, CFURLRef ftpURL) STUB_METHOD;
CFNETWORK_EXPORT CFWriteStreamRef CFWriteStreamCreateWithFTPURL(CFAllocatorRef alloc, CFURLRef ftpURL) STUB_METHOD;
CFNETWORK_EXPORT CFIndex CFFTPCreateParsedResourceListing(CFAllocatorRef alloc,
                                                          const UInt8* buffer,
                                                          CFIndex bufferLength,
                                                          CFDictionaryRef _Nullable* parsed) STUB_METHOD;

CFNETWORK_EXPORT const CFStringRef kCFStreamPropertyFTPUserName;
CFNETWORK_EXPORT const CFStringRef kCFStreamPropertyFTPPassword;
CFNETWORK_EXPORT const CFStringRef kCFStreamPropertyFTPUsePassiveMode;
CFNETWORK_EXPORT const CFStringRef kCFStreamPropertyFTPResourceSize;
CFNETWORK_EXPORT const CFStringRef kCFStreamPropertyFTPFetchResourceInfo;
CFNETWORK_EXPORT const CFStringRef kCFStreamPropertyFTPFileTransferOffset;
CFNETWORK_EXPORT const CFStringRef kCFStreamPropertyFTPAttemptPersistentConnection;
CFNETWORK_EXPORT const CFStringRef kCFStreamPropertyFTPProxy;
CFNETWORK_EXPORT const CFStringRef kCFStreamPropertyFTPProxyHost;
CFNETWORK_EXPORT const CFStringRef kCFStreamPropertyFTPProxyPort;
CFNETWORK_EXPORT const CFStringRef kCFStreamPropertyFTPProxyUser;
CFNETWORK_EXPORT const CFStringRef kCFStreamPropertyFTPProxyPassword;
CFNETWORK_EXPORT const CFStringRef kCFFTPResourceMode;
CFNETWORK_EXPORT const CFStringRef kCFFTPResourceName;
CFNETWORK_EXPORT const CFStringRef kCFFTPResourceOwner;
CFNETWORK_EXPORT const CFStringRef kCFFTPResourceGroup;
CFNETWORK_EXPORT const CFStringRef kCFFTPResourceLink;
CFNETWORK_EXPORT const CFStringRef kCFFTPResourceSize;
CFNETWORK_EXPORT const CFStringRef kCFFTPResourceType;
CFNETWORK_EXPORT const CFStringRef kCFFTPResourceModDate;
CFNETWORK_EXPORT const SInt32 kCFStreamErrorDomainFTP;
