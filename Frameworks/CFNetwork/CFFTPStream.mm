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
#import <CoreFoundation/CoreFoundation.h>
#import <CFNetwork/CFFTPStream.h>

const CFStringRef kCFStreamPropertyFTPUserName = CFSTR("kCFStreamPropertyFTPUserName");
const CFStringRef kCFStreamPropertyFTPPassword = CFSTR("kCFStreamPropertyFTPPassword");
const CFStringRef kCFStreamPropertyFTPUsePassiveMode = CFSTR("kCFStreamPropertyFTPUsePassiveMode");
const CFStringRef kCFStreamPropertyFTPResourceSize = CFSTR("kCFStreamPropertyFTPResourceSize");
const CFStringRef kCFStreamPropertyFTPFetchResourceInfo = CFSTR("kCFStreamPropertyFTPFetchResourceInfo");
const CFStringRef kCFStreamPropertyFTPFileTransferOffset = CFSTR("kCFStreamPropertyFTPFileTransferOffset");
const CFStringRef kCFStreamPropertyFTPAttemptPersistentConnection = CFSTR("kCFStreamPropertyFTPAttemptPersistentConnection");
const CFStringRef kCFStreamPropertyFTPProxy = CFSTR("kCFStreamPropertyFTPProxy");
const CFStringRef kCFStreamPropertyFTPProxyHost = CFSTR("kCFStreamPropertyFTPProxyHost");
const CFStringRef kCFStreamPropertyFTPProxyPort = CFSTR("kCFStreamPropertyFTPProxyPort");
const CFStringRef kCFStreamPropertyFTPProxyUser = CFSTR("kCFStreamPropertyFTPProxyUser");
const CFStringRef kCFStreamPropertyFTPProxyPassword = CFSTR("kCFStreamPropertyFTPProxyPassword");
const CFStringRef kCFFTPResourceMode = CFSTR("kCFFTPResourceMode");
const CFStringRef kCFFTPResourceName = CFSTR("kCFFTPResourceName");
const CFStringRef kCFFTPResourceOwner = CFSTR("kCFFTPResourceOwner");
const CFStringRef kCFFTPResourceGroup = CFSTR("kCFFTPResourceGroup");
const CFStringRef kCFFTPResourceLink = CFSTR("kCFFTPResourceLink");
const CFStringRef kCFFTPResourceSize = CFSTR("kCFFTPResourceSize");
const CFStringRef kCFFTPResourceType = CFSTR("kCFFTPResourceType");
const CFStringRef kCFFTPResourceModDate = CFSTR("kCFFTPResourceModDate");
const SInt32 kCFStreamErrorDomainFTP = StubConstant();

/**
 @Status Stub
 @Notes
*/
CFReadStreamRef CFReadStreamCreateWithFTPURL(CFAllocatorRef alloc, CFURLRef ftpURL) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFWriteStreamRef CFWriteStreamCreateWithFTPURL(CFAllocatorRef alloc, CFURLRef ftpURL) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFIndex CFFTPCreateParsedResourceListing(CFAllocatorRef alloc,
                                         const UInt8* buffer,
                                         CFIndex bufferLength,
                                         CFDictionaryRef _Nullable* parsed) {
    UNIMPLEMENTED();
    return StubReturn();
}
