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

const CFStringRef kCFHTTPAuthenticationSchemeBasic = CFSTR("kCFHTTPAuthenticationSchemeBasic");
const CFStringRef kCFHTTPAuthenticationSchemeDigest = CFSTR("kCFHTTPAuthenticationSchemeDigest");
const CFStringRef kCFHTTPAuthenticationSchemeNTLM = CFSTR("kCFHTTPAuthenticationSchemeNTLM");
const CFStringRef kCFHTTPAuthenticationSchemeNegotiate = CFSTR("kCFHTTPAuthenticationSchemeNegotiate");
const CFStringRef kCFHTTPAuthenticationSchemeKerberos = CFSTR("kCFHTTPAuthenticationSchemeKerberos");
const CFStringRef kCFHTTPAuthenticationSchemeNegotiate2 = CFSTR("kCFHTTPAuthenticationSchemeNegotiate2");
const CFStringRef kCFHTTPAuthenticationSchemeOAuth1 = CFSTR("kCFHTTPAuthenticationSchemeOAuth1");
const CFStringRef kCFHTTPAuthenticationSchemeXMobileMeAuthToken = CFSTR("kCFHTTPAuthenticationSchemeXMobileMeAuthToken");
const CFStringRef kCFHTTPAuthenticationUsername = CFSTR("kCFHTTPAuthenticationUsername");
const CFStringRef kCFHTTPAuthenticationPassword = CFSTR("kCFHTTPAuthenticationPassword");
const CFStringRef kCFHTTPAuthenticationAccountDomain = CFSTR("kCFHTTPAuthenticationAccountDomain");

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
