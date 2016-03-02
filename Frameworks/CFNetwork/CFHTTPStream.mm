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
#import <CFNetwork/CFHTTPStream.h>

const CFStringRef kCFStreamPropertyHTTPAttemptPersistentConnection =
    static_cast<CFStringRef>(@"kCFStreamPropertyHTTPAttemptPersistentConnection");
const CFStringRef kCFStreamPropertyHTTPFinalURL = static_cast<CFStringRef>(@"kCFStreamPropertyHTTPFinalURL");
const CFStringRef kCFStreamPropertyHTTPFinalRequest = static_cast<CFStringRef>(@"kCFStreamPropertyHTTPFinalRequest");
const CFStringRef kCFStreamPropertyHTTPProxy = static_cast<CFStringRef>(@"kCFStreamPropertyHTTPProxy");
const CFStringRef kCFStreamPropertyHTTPRequestBytesWrittenCount =
    static_cast<CFStringRef>(@"kCFStreamPropertyHTTPRequestBytesWrittenCount");
const CFStringRef kCFStreamPropertyHTTPResponseHeader = static_cast<CFStringRef>(@"kCFStreamPropertyHTTPResponseHeader");
const CFStringRef kCFStreamPropertyHTTPShouldAutoredirect = static_cast<CFStringRef>(@"kCFStreamPropertyHTTPShouldAutoredirect");
const SInt32 kCFStreamErrorDomainHTTP = StubConstant();

/**
 @Status Stub
 @Notes
*/
CFReadStreamRef CFReadStreamCreateForHTTPRequest(CFAllocatorRef alloc, CFHTTPMessageRef request) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFReadStreamRef CFReadStreamCreateForStreamedHTTPRequest(CFAllocatorRef alloc,
                                                         CFHTTPMessageRef requestHeaders,
                                                         CFReadStreamRef requestBody) {
    UNIMPLEMENTED();
    return StubReturn();
}
