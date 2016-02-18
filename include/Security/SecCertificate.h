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
#import <CoreFoundation/CFData.h>
#import <Security/SecBase.h>

// This header file is not yet fully implemented

typedef struct __SecCertificate* SecCertificateRef;

SECURITY_EXPORT CFTypeID SecCertificateGetTypeID(void) STUB_METHOD;
SECURITY_EXPORT SecCertificateRef SecCertificateCreateWithData(CFAllocatorRef allocator, CFDataRef data) STUB_METHOD;
SECURITY_EXPORT CFDataRef SecCertificateCopyData(SecCertificateRef certificate) STUB_METHOD;
SECURITY_EXPORT CFStringRef SecCertificateCopySubjectSummary(SecCertificateRef certificate) STUB_METHOD;