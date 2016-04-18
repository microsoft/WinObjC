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

typedef CF_ENUM(CFIndex, CFHostInfoType) { kCFHostAddresses = 0, kCFHostNames = 1, kCFHostReachability = 2 };

struct CFHostClientContext {
    CFIndex version;
    void* info;
    CFAllocatorRetainCallBack retain;
    CFAllocatorReleaseCallBack release;
    CFAllocatorCopyDescriptionCallBack copyDescription;
};

typedef struct __CFHost* CFHostRef;
typedef void(CFHostClientCallBack)(CFHostRef theHost, CFHostInfoType typeInfo, const CFStreamError* error, void* info);
typedef struct CFHostClientContext CFHostClientContext;

CFNETWORK_EXPORT CFHostRef CFHostCreateCopy(CFAllocatorRef alloc, CFHostRef host) STUB_METHOD;
CFNETWORK_EXPORT CFHostRef CFHostCreateWithAddress(CFAllocatorRef allocator, CFDataRef addr) STUB_METHOD;
CFNETWORK_EXPORT CFHostRef CFHostCreateWithName(CFAllocatorRef allocator, CFStringRef hostname) STUB_METHOD;
CFNETWORK_EXPORT void CFHostCancelInfoResolution(CFHostRef theHost, CFHostInfoType info) STUB_METHOD;
CFNETWORK_EXPORT CFArrayRef CFHostGetAddressing(CFHostRef theHost, Boolean* hasBeenResolved) STUB_METHOD;
CFNETWORK_EXPORT CFArrayRef CFHostGetNames(CFHostRef theHost, Boolean* hasBeenResolved) STUB_METHOD;
CFNETWORK_EXPORT CFDataRef CFHostGetReachability(CFHostRef theHost, Boolean* hasBeenResolved) STUB_METHOD;
CFNETWORK_EXPORT Boolean CFHostStartInfoResolution(CFHostRef theHost, CFHostInfoType info, CFStreamError* error) STUB_METHOD;
CFNETWORK_EXPORT Boolean CFHostSetClient(CFHostRef theHost, CFHostClientCallBack clientCB, CFHostClientContext* clientContext) STUB_METHOD;
CFNETWORK_EXPORT void CFHostScheduleWithRunLoop(CFHostRef theHost, CFRunLoopRef runLoop, CFStringRef runLoopMode) STUB_METHOD;
CFNETWORK_EXPORT void CFHostUnscheduleFromRunLoop(CFHostRef theHost, CFRunLoopRef runLoop, CFStringRef runLoopMode) STUB_METHOD;
CFNETWORK_EXPORT CFTypeID CFHostGetTypeID() STUB_METHOD;
CFNETWORK_EXPORT const SInt32 kCFStreamErrorDomainNetDB;
CFNETWORK_EXPORT const SInt32 kCFStreamErrorDomainSystemConfiguration;
