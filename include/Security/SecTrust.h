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

#include <dispatch/dispatch.h>
#import <Security/SecBase.h>
#import <Security/SecKey.h>
#import <Security/SecCertificate.h>
#import <stdint.h>

// This header file is not yet fully implemented

typedef struct __SecTrust* SecTrustRef;

typedef enum SecTrustResultType : uint32_t SecTrustResultType;
enum SecTrustResultType : uint32_t {
    kSecTrustResultInvalid = 0,
    kSecTrustResultProceed,
    kSecTrustResultConfirm,
    kSecTrustResultDeny,
    kSecTrustResultUnspecified,
    kSecTrustResultRecoverableTrustFailure,
    kSecTrustResultFatalTrustFailure,
    kSecTrustResultOtherError
};

typedef void (^SecTrustCallback)(SecTrustRef trustRef, SecTrustResultType trustResult);

SECURITY_EXPORT CFTypeID SecTrustGetTypeID(void);
SECURITY_EXPORT OSStatus SecTrustCopyCustomAnchorCertificates(SecTrustRef trust, CFArrayRef _Nullable* anchors);
SECURITY_EXPORT CFDataRef SecTrustCopyExceptions(SecTrustRef trust);
SECURITY_EXPORT CFArrayRef SecTrustCopyProperties(SecTrustRef trust);
SECURITY_EXPORT OSStatus SecTrustCopyPolicies(SecTrustRef trust, CFArrayRef _Nullable* policies);
SECURITY_EXPORT SecKeyRef SecTrustCopyPublicKey(SecTrustRef trust);
SECURITY_EXPORT OSStatus SecTrustCreateWithCertificates(CFTypeRef certificates, CFTypeRef policies, SecTrustRef* trust);
SECURITY_EXPORT OSStatus SecTrustEvaluate(SecTrustRef trust, SecTrustResultType* result);
SECURITY_EXPORT OSStatus SecTrustEvaluateAsync(SecTrustRef trust, dispatch_queue_t queue, SecTrustCallback result);
SECURITY_EXPORT CFIndex SecTrustGetCertificateCount(SecTrustRef trust);
SECURITY_EXPORT SecCertificateRef SecTrustGetCertificateAtIndex(SecTrustRef trust, CFIndex ix);
SECURITY_EXPORT OSStatus SecTrustGetTrustResult(SecTrustRef trust, SecTrustResultType* result);
SECURITY_EXPORT CFAbsoluteTime SecTrustGetVerifyTime(SecTrustRef trust);
SECURITY_EXPORT OSStatus SecTrustSetAnchorCertificates(SecTrustRef trust, CFArrayRef anchorCertificates);
SECURITY_EXPORT OSStatus SecTrustSetAnchorCertificatesOnly(SecTrustRef trust, Boolean anchorCertificatesOnly);
SECURITY_EXPORT bool SecTrustSetExceptions(SecTrustRef trust, CFDataRef exceptions);
SECURITY_EXPORT OSStatus SecTrustSetPolicies(SecTrustRef trust, CFTypeRef policies);
SECURITY_EXPORT OSStatus SecTrustSetVerifyDate(SecTrustRef trust, CFDateRef verifyDate);