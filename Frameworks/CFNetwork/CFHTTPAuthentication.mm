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
#import <CFNetwork/CFHTTPAuthentication.h>

const CFStringRef kCFHTTPAuthenticationSchemeBasic = static_cast<CFStringRef>(@"kCFHTTPAuthenticationSchemeBasic");
const CFStringRef kCFHTTPAuthenticationSchemeDigest = static_cast<CFStringRef>(@"kCFHTTPAuthenticationSchemeDigest");
const CFStringRef kCFHTTPAuthenticationSchemeNTLM = static_cast<CFStringRef>(@"kCFHTTPAuthenticationSchemeNTLM");
const CFStringRef kCFHTTPAuthenticationSchemeNegotiate = static_cast<CFStringRef>(@"kCFHTTPAuthenticationSchemeNegotiate");
const CFStringRef kCFHTTPAuthenticationSchemeKerberos = static_cast<CFStringRef>(@"kCFHTTPAuthenticationSchemeKerberos");
const CFStringRef kCFHTTPAuthenticationSchemeNegotiate2 = static_cast<CFStringRef>(@"kCFHTTPAuthenticationSchemeNegotiate2");
const CFStringRef kCFHTTPAuthenticationSchemeOAuth1 = static_cast<CFStringRef>(@"kCFHTTPAuthenticationSchemeOAuth1");
const CFStringRef kCFHTTPAuthenticationSchemeXMobileMeAuthToken =
    static_cast<CFStringRef>(@"kCFHTTPAuthenticationSchemeXMobileMeAuthToken");
const CFStringRef kCFHTTPAuthenticationUsername = static_cast<CFStringRef>(@"kCFHTTPAuthenticationUsername");
const CFStringRef kCFHTTPAuthenticationPassword = static_cast<CFStringRef>(@"kCFHTTPAuthenticationPassword");
const CFStringRef kCFHTTPAuthenticationAccountDomain = static_cast<CFStringRef>(@"kCFHTTPAuthenticationAccountDomain");

/**
 @Status Stub
 @Notes
*/
CFHTTPAuthenticationRef CFHTTPAuthenticationCreateFromResponse(CFAllocatorRef alloc, CFHTTPMessageRef response) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
Boolean CFHTTPAuthenticationAppliesToRequest(CFHTTPAuthenticationRef auth, CFHTTPMessageRef request) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFArrayRef CFHTTPAuthenticationCopyDomains(CFHTTPAuthenticationRef auth) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFStringRef CFHTTPAuthenticationCopyMethod(CFHTTPAuthenticationRef auth) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFStringRef CFHTTPAuthenticationCopyRealm(CFHTTPAuthenticationRef auth) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
Boolean CFHTTPAuthenticationIsValid(CFHTTPAuthenticationRef auth, CFStreamError* error) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
Boolean CFHTTPAuthenticationRequiresAccountDomain(CFHTTPAuthenticationRef auth) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
Boolean CFHTTPAuthenticationRequiresOrderedRequests(CFHTTPAuthenticationRef auth) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
Boolean CFHTTPAuthenticationRequiresUserNameAndPassword(CFHTTPAuthenticationRef auth) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFTypeID CFHTTPAuthenticationGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}
