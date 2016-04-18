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
#pragma once

#import <CFNetwork/CFNetworkExport.h>
#import <CoreFoundation/CoreFoundation.h>

typedef CF_ENUM(CFIndex, CFNetDiagnosticStatusValues) {
    kCFNetDiagnosticNoErr = 0,
    kCFNetDiagnosticErr = -66560L,
    kCFNetDiagnosticConnectionUp = -66559L,
    kCFNetDiagnosticConnectionIndeterminate = -66558L,
    kCFNetDiagnosticConnectionDown = -66557L
};

typedef struct __CFNetDiagnostic* CFNetDiagnosticRef;
typedef CFIndex CFNetDiagnosticStatus;
CFNETWORK_EXPORT CFNetDiagnosticRef CFNetDiagnosticCreateWithStreams(CFAllocatorRef alloc,
                                                                     CFReadStreamRef readStream,
                                                                     CFWriteStreamRef writeStream) STUB_METHOD;
CFNETWORK_EXPORT CFNetDiagnosticRef CFNetDiagnosticCreateWithURL(CFAllocatorRef alloc, CFURLRef url) STUB_METHOD;
CFNETWORK_EXPORT void CFNetDiagnosticSetName(CFNetDiagnosticRef details, CFStringRef name) STUB_METHOD;
CFNETWORK_EXPORT CFNetDiagnosticStatus CFNetDiagnosticDiagnoseProblemInteractively(CFNetDiagnosticRef details) STUB_METHOD;
CFNETWORK_EXPORT CFNetDiagnosticStatus CFNetDiagnosticCopyNetworkStatusPassively(CFNetDiagnosticRef details,
                                                                                 CFStringRef _Nullable* description) STUB_METHOD;
