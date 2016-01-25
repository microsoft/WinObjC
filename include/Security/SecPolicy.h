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

SECURITY_EXPORT const CFTypeRef kSecPolicyOid;
SECURITY_EXPORT const CFTypeRef kSecPolicyName;
SECURITY_EXPORT const CFTypeRef kSecPolicyClient;
SECURITY_EXPORT const CFTypeRef kSecPolicyAppleX509Basic;
SECURITY_EXPORT const CFTypeRef kSecPolicyAppleSSL;
SECURITY_EXPORT const CFTypeRef kSecPolicyAppleSMIME;
SECURITY_EXPORT const CFTypeRef kSecPolicyAppleEAP;
SECURITY_EXPORT const CFTypeRef kSecPolicyAppleIPsec;
SECURITY_EXPORT const CFTypeRef kSecPolicyAppleCodeSigning;
SECURITY_EXPORT const CFTypeRef kSecPolicyMacAppStoreReceipt;
SECURITY_EXPORT const CFTypeRef kSecPolicyAppleIDValidation;
SECURITY_EXPORT const CFTypeRef kSecPolicyAppleTimeStamping;

SECURITY_EXPORT CFTypeID SecPolicyGetTypeID(void) STUB_METHOD;
SECURITY_EXPORT CFDictionaryRef SecPolicyCopyProperties(SecPolicyRef policyRef) STUB_METHOD;
SECURITY_EXPORT SecPolicyRef SecPolicyCreateBasicX509(void) STUB_METHOD;
SECURITY_EXPORT SecPolicyRef SecPolicyCreateSSL(Boolean server, CFStringRef hostname) STUB_METHOD;