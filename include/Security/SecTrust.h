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
#pragma once

#import <Security/SecBase.h>
#import <Security/SecKey.h>
#import <Security/SecCertificate.h>
#import <stdint.h>

// This header file is not yet fully implemented

typedef struct __SecTrust* SecTrustRef;

typedef uint32_t SecTrustResultType;
enum {
    kSecTrustResultInvalid = 0,
    kSecTrustResultProceed,
    kSecTrustResultConfirm,
    kSecTrustResultDeny,
    kSecTrustResultUnspecified,
    kSecTrustResultRecoverableTrustFailure,
    kSecTrustResultFatalTrustFailure,
    kSecTrustResultOtherError
};

SECURITY_EXPORT SecKeyRef SecTrustCopyPublicKey(SecTrustRef trust);
SECURITY_EXPORT OSStatus SecTrustCreateWithCertificates(CFTypeRef certificates, CFTypeRef policies, SecTrustRef* trust);
SECURITY_EXPORT OSStatus SecTrustEvaluate(SecTrustRef trust, SecTrustResultType* result);
SECURITY_EXPORT CFIndex SecTrustGetCertificateCount(SecTrustRef trust);
SECURITY_EXPORT SecCertificateRef SecTrustGetCertificateAtIndex(SecTrustRef trust, CFIndex ix);
SECURITY_EXPORT OSStatus SecTrustSetPolicies(SecTrustRef trust, CFTypeRef policies);
SECURITY_EXPORT OSStatus SecTrustSetAnchorCertificatesOnly(SecTrustRef trust, Boolean anchorCertificatesOnly);