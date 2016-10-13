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
#import <CFNetwork/CFHTTPMessage.h>
#import <CFNetwork/CFHTTPAuthentication.h>

const CFStringRef kCFHTTPVersion1_0 = CFSTR("kCFHTTPVersion1_0");
const CFStringRef kCFHTTPVersion1_1 = CFSTR("kCFHTTPVersion1_1");

/**
 @Status Stub
 @Notes
*/
CFHTTPMessageRef CFHTTPMessageCreateCopy(CFAllocatorRef alloc, CFHTTPMessageRef message) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFHTTPMessageRef CFHTTPMessageCreateEmpty(CFAllocatorRef alloc, Boolean isRequest) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFHTTPMessageRef CFHTTPMessageCreateRequest(CFAllocatorRef alloc, CFStringRef requestMethod, CFURLRef url, CFStringRef httpVersion) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFHTTPMessageRef CFHTTPMessageCreateResponse(CFAllocatorRef alloc,
                                             CFIndex statusCode,
                                             CFStringRef statusDescription,
                                             CFStringRef httpVersion) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
Boolean CFHTTPMessageAppendBytes(CFHTTPMessageRef message, const UInt8* newBytes, CFIndex numBytes) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CFHTTPMessageSetBody(CFHTTPMessageRef message, CFDataRef bodyData) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CFHTTPMessageSetHeaderFieldValue(CFHTTPMessageRef message, CFStringRef headerField, CFStringRef value) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
CFDataRef CFHTTPMessageCopyBody(CFHTTPMessageRef message) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFDictionaryRef CFHTTPMessageCopyAllHeaderFields(CFHTTPMessageRef message) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFStringRef CFHTTPMessageCopyHeaderFieldValue(CFHTTPMessageRef message, CFStringRef headerField) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFStringRef CFHTTPMessageCopyRequestMethod(CFHTTPMessageRef request) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFURLRef CFHTTPMessageCopyRequestURL(CFHTTPMessageRef request) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFDataRef CFHTTPMessageCopySerializedMessage(CFHTTPMessageRef message) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFStringRef CFHTTPMessageCopyVersion(CFHTTPMessageRef message) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
Boolean CFHTTPMessageIsRequest(CFHTTPMessageRef message) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
Boolean CFHTTPMessageIsHeaderComplete(CFHTTPMessageRef message) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFIndex CFHTTPMessageGetResponseStatusCode(CFHTTPMessageRef response) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFStringRef CFHTTPMessageCopyResponseStatusLine(CFHTTPMessageRef response) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
Boolean CFHTTPMessageApplyCredentials(
    CFHTTPMessageRef request, CFHTTPAuthenticationRef auth, CFStringRef username, CFStringRef password, CFStreamError* error) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
Boolean CFHTTPMessageApplyCredentialDictionary(CFHTTPMessageRef request,
                                               CFHTTPAuthenticationRef auth,
                                               CFDictionaryRef dict,
                                               CFStreamError* error) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
Boolean CFHTTPMessageAddAuthentication(CFHTTPMessageRef request,
                                       CFHTTPMessageRef authenticationFailureResponse,
                                       CFStringRef username,
                                       CFStringRef password,
                                       CFStringRef authenticationScheme,
                                       Boolean forProxy) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFTypeID CFHTTPMessageGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}
