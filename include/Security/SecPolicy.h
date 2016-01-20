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

#import <CoreFoundation/CFBase.h>
#import <CoreFoundation/CFDictionary.h>
#import <Security/SecBase.h>

// This header file is not yet fully implemented

typedef struct OpaqueSecPolicyRef* SecPolicyRef;

SECURITY_EXPORT CFTypeRef kSecPolicyOid;
SECURITY_EXPORT CFTypeRef kSecPolicyName;
SECURITY_EXPORT CFTypeRef kSecPolicyClient;
SECURITY_EXPORT CFTypeRef kSecPolicyAppleX509Basic;
SECURITY_EXPORT CFTypeRef kSecPolicyAppleSSL;
SECURITY_EXPORT CFTypeRef kSecPolicyAppleSMIME;
SECURITY_EXPORT CFTypeRef kSecPolicyAppleEAP;
SECURITY_EXPORT CFTypeRef kSecPolicyAppleIPsec;
SECURITY_EXPORT CFTypeRef kSecPolicyAppleCodeSigning;
SECURITY_EXPORT CFTypeRef kSecPolicyMacAppStoreReceipt;
SECURITY_EXPORT CFTypeRef kSecPolicyAppleIDValidation;
SECURITY_EXPORT CFTypeRef kSecPolicyAppleTimeStamping;

SECURITY_EXPORT CFTypeID SecPolicyGetTypeID(void);
SECURITY_EXPORT CFDictionaryRef SecPolicyCopyProperties(SecPolicyRef policyRef);
SECURITY_EXPORT SecPolicyRef SecPolicyCreateBasicX509(void);
SECURITY_EXPORT SecPolicyRef SecPolicyCreateSSL(Boolean server, CFStringRef hostname);