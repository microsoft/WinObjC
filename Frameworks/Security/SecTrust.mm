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
OSStatus SecTrustSetPolicies(SecTrustRef trust, CFTypeRef policies) {
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