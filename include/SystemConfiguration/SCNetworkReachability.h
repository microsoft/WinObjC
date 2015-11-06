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

#ifndef __SYSTEMCONFIGURATION_SCNETWORKREACHABILITY_H
#define __SYSTEMCONFIGURATION_SCNETWORKREACHABILITY_H

#include <sys/cdefs.h>
#include <SystemConfiguration/SCExport.h>
#include <CoreFoundation/CoreFoundation.h>

typedef struct __SCNetworkReachability* SCNetworkReachabilityRef;

typedef struct {
    CFIndex version;
    void* info;
    const void* (*retain)(const void*);
    void (*release)(const void*);
    CFStringRef (*copyDescription)(const void*);
} SCNetworkReachabilityContext;

enum {
    kSCNetworkReachabilityFlagsTransientConnection = 1,
    kSCNetworkReachabilityFlagsReachable = 2,
    kSCNetworkReachabilityFlagsConnectionRequired = 4,
    kSCNetworkReachabilityFlagsConnectionOnTraffic = 1 << 3,
    kSCNetworkReachabilityFlagsInterventionRequired = 1 << 4,
    kSCNetworkReachabilityFlagsConnectionOnDemand = 1 << 5,
    kSCNetworkReachabilityFlagsIsLocalAddress = 1 << 16,
    kSCNetworkReachabilityFlagsIsDirect = 1 << 17,
    kSCNetworkReachabilityFlagsIsWWAN = 1 << 18
};
typedef uint32_t SCNetworkReachabilityFlags;

typedef void (*SCNetworkReachabilityCallBack)(SCNetworkReachabilityRef, SCNetworkReachabilityFlags, void*);

__BEGIN_DECLS

SC_EXPORT SCNetworkReachabilityRef SCNetworkReachabilityCreateWithName(CFAllocatorRef, const char*);

SC_EXPORT Boolean SCNetworkReachabilityScheduleWithRunLoop(SCNetworkReachabilityRef, CFRunLoopRef, CFStringRef);

SC_EXPORT SCNetworkReachabilityRef SCNetworkReachabilityCreateWithAddress(CFAllocatorRef, const struct sockaddr*);

SC_EXPORT Boolean SCNetworkReachabilityGetFlags(SCNetworkReachabilityRef, SCNetworkReachabilityFlags*);

SC_EXPORT Boolean SCNetworkReachabilityUnscheduleFromRunLoop(SCNetworkReachabilityRef, CFRunLoopRef, CFStringRef);

SC_EXPORT Boolean SCNetworkReachabilitySetCallback(SCNetworkReachabilityRef, SCNetworkReachabilityCallBack, SCNetworkReachabilityContext*);

SC_EXPORT Boolean SCNetworkReachabilitySetDispatchQueue(SCNetworkReachabilityRef, dispatch_queue_t);

__END_DECLS

#endif
