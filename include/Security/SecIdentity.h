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
#import <CoreFoundation/CFArray.h>
// This header file is not yet fully implemented

typedef struct __SecIdentity* SecIdentityRef;

SECURITY_EXPORT CFTypeID SecIdentityGetTypeID(void) STUB_METHOD;
SECURITY_EXPORT OSStatus SecIdentityCopyCertificate(SecIdentityRef identityRef, SecCertificateRef* certificateRef) STUB_METHOD;
SECURITY_EXPORT OSStatus SecIdentityCopyPrivateKey(SecIdentityRef identityRef, SecKeyRef* privateKeyRef) STUB_METHOD;
SECURITY_EXPORT OSStatus SecPKCS12Import(CFDataRef pkcs12_data, CFDictionaryRef options, CFArrayRef _Nullable* items) STUB_METHOD;