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

#ifndef _CFHOST_H_
#define _CFHOST_H_

#import <CoreFoundation/CoreFoundation.h>
#import <StarboardExport.h>

typedef struct __CFHost* CFHostRef;

enum CFHostInfoType {
    kCFHostAddresses = 0,
    kCFHostNames = 1,
    kCFHostReachability = 2,
};
typedef enum CFHostInfoType CFHostInfoType;

typedef void (*CFHostClientCallBack)(CFHostRef host, CFHostInfoType infoType, const CFStreamError* streamError, void* info);

typedef struct CFHostClientContext {
    CFIndex version;
    void* info;
    CFAllocatorRetainCallBack retain;
    CFAllocatorReleaseCallBack release;
    CFAllocatorCopyDescriptionCallBack copyDescription;
} CFHostClientContext;

SB_EXPORT const SInt32 kCFStreamErrorDomainNetDB;
SB_EXPORT const SInt32 kCFStreamErrorDomainSystemConfiguration;

SB_EXPORT CFTypeID CFHostGetTypeID();
SB_EXPORT CFHostRef CFHostCreateCopy(CFAllocatorRef alloc, CFHostRef self);
SB_EXPORT CFHostRef CFHostCreateWithAddress(CFAllocatorRef allocator, CFDataRef address);
SB_EXPORT CFHostRef CFHostCreateWithName(CFAllocatorRef allocator, CFStringRef name);
SB_EXPORT CFArrayRef CFHostGetAddressing(CFHostRef self, Boolean* hasBeenResolved);
SB_EXPORT CFArrayRef CFHostGetNames(CFHostRef self, Boolean* hasBeenResolved);
SB_EXPORT CFDataRef CFHostGetReachability(CFHostRef self, Boolean* hasBeenResolved);
SB_EXPORT Boolean CFHostSetClient(CFHostRef self, CFHostClientCallBack callback, CFHostClientContext* context);

SB_EXPORT Boolean CFHostStartInfoResolution(CFHostRef self, CFHostInfoType infoType, CFStreamError* streamError);
SB_EXPORT void CFHostCancelInfoResolution(CFHostRef theHost, CFHostInfoType infoType);

SB_EXPORT void CFHostScheduleWithRunLoop(CFHostRef self, CFRunLoopRef runLoop, CFStringRef mode);
SB_EXPORT void CFHostUnscheduleFromRunLoop(CFHostRef self, CFRunLoopRef runLoop, CFStringRef mode);

#endif /* _CFHOST_H_ */
