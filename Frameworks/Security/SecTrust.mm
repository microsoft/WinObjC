//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#import <Starboard.h>
#import <Security/SecTrust.h>

/**
 @Status Stub
*/
CFTypeID SecTrustGetTypeID() {
    UNIMPLEMENTED();
    return 0;
}

/**
 @Status Stub
*/
OSStatus SecTrustCopyCustomAnchorCertificates(SecTrustRef trust, CFArrayRef _Nullable* anchors) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
CFDataRef SecTrustCopyExceptions(SecTrustRef trust) {
    UNIMPLEMENTED();
    return nullptr;
}

/**
 @Status Stub
*/
CFArrayRef SecTrustCopyProperties(SecTrustRef trust) {
    UNIMPLEMENTED();
    return nullptr;
}

/**
 @Status Stub
*/
OSStatus SecTrustCopyPolicies(SecTrustRef trust, CFArrayRef _Nullable* policies) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
@Status Stub
*/
SecKeyRef SecTrustCopyPublicKey(SecTrustRef trust) {
    UNIMPLEMENTED();
    return nullptr;
}

/**
@Status Stub
*/
OSStatus SecTrustCreateWithCertificates(CFTypeRef certificates, CFTypeRef policies, SecTrustRef* trust) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
@Status Stub
*/
OSStatus SecTrustEvaluate(SecTrustRef trust, SecTrustResultType* result) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SecTrustEvaluateAsync(SecTrustRef trust, dispatch_queue_t queue, SecTrustCallback result) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
@Status Stub
*/
CFIndex SecTrustGetCertificateCount(SecTrustRef trust) {
    UNIMPLEMENTED();
    return -1;
}

/**
@Status Stub
*/
SecCertificateRef SecTrustGetCertificateAtIndex(SecTrustRef trust, CFIndex ix) {
    UNIMPLEMENTED();
    return nullptr;
}

/**
 @Status Stub
*/
OSStatus SecTrustGetTrustResult(SecTrustRef trust, SecTrustResultType* result) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
CFAbsoluteTime SecTrustGetVerifyTime(SecTrustRef trust) {
    UNIMPLEMENTED();
    return 0;
}

/**
 @Status Stub
*/
OSStatus SecTrustSetAnchorCertificates(SecTrustRef trust, CFArrayRef anchorCertificates) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SecTrustSetAnchorCertificatesOnly(SecTrustRef trust, Boolean anchorCertificatesOnly) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
bool SecTrustSetExceptions(SecTrustRef trust, CFDataRef exceptions) {
    UNIMPLEMENTED();
    return false;
}

/**
@Status Stub
*/
OSStatus SecTrustSetPolicies(SecTrustRef trust, CFTypeRef policies) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SecTrustSetVerifyDate(SecTrustRef trust, CFDateRef verifyDate) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}