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

const CFStringRef kCFStreamPropertyFTPUserName = static_cast<CFStringRef>(@"kCFStreamPropertyFTPUserName");
const CFStringRef kCFStreamPropertyFTPPassword = static_cast<CFStringRef>(@"kCFStreamPropertyFTPPassword");
const CFStringRef kCFStreamPropertyFTPUsePassiveMode = static_cast<CFStringRef>(@"kCFStreamPropertyFTPUsePassiveMode");
const CFStringRef kCFStreamPropertyFTPResourceSize = static_cast<CFStringRef>(@"kCFStreamPropertyFTPResourceSize");
const CFStringRef kCFStreamPropertyFTPFetchResourceInfo = static_cast<CFStringRef>(@"kCFStreamPropertyFTPFetchResourceInfo");
const CFStringRef kCFStreamPropertyFTPFileTransferOffset = static_cast<CFStringRef>(@"kCFStreamPropertyFTPFileTransferOffset");
const CFStringRef kCFStreamPropertyFTPAttemptPersistentConnection =
    static_cast<CFStringRef>(@"kCFStreamPropertyFTPAttemptPersistentConnection");
const CFStringRef kCFStreamPropertyFTPProxy = static_cast<CFStringRef>(@"kCFStreamPropertyFTPProxy");
const CFStringRef kCFStreamPropertyFTPProxyHost = static_cast<CFStringRef>(@"kCFStreamPropertyFTPProxyHost");
const CFStringRef kCFStreamPropertyFTPProxyPort = static_cast<CFStringRef>(@"kCFStreamPropertyFTPProxyPort");
const CFStringRef kCFStreamPropertyFTPProxyUser = static_cast<CFStringRef>(@"kCFStreamPropertyFTPProxyUser");
const CFStringRef kCFStreamPropertyFTPProxyPassword = static_cast<CFStringRef>(@"kCFStreamPropertyFTPProxyPassword");
const CFStringRef kCFFTPResourceMode = static_cast<CFStringRef>(@"kCFFTPResourceMode");
const CFStringRef kCFFTPResourceName = static_cast<CFStringRef>(@"kCFFTPResourceName");
const CFStringRef kCFFTPResourceOwner = static_cast<CFStringRef>(@"kCFFTPResourceOwner");
const CFStringRef kCFFTPResourceGroup = static_cast<CFStringRef>(@"kCFFTPResourceGroup");
const CFStringRef kCFFTPResourceLink = static_cast<CFStringRef>(@"kCFFTPResourceLink");
const CFStringRef kCFFTPResourceSize = static_cast<CFStringRef>(@"kCFFTPResourceSize");
const CFStringRef kCFFTPResourceType = static_cast<CFStringRef>(@"kCFFTPResourceType");
const CFStringRef kCFFTPResourceModDate = static_cast<CFStringRef>(@"kCFFTPResourceModDate");
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
