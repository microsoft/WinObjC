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

#ifndef _CFNETSERVICES_H_
#define _CFNETSERVICES_H_

#import <CFNetwork/CFHost.h>
#import <CFNetwork/CFNetworkExport.h>

CFNETWORK_EXPORT const SInt32 kCFStreamErrorDomainMach;
CFNETWORK_EXPORT const SInt32 kCFStreamErrorDomainNetServices;

enum {
    kCFNetServiceFlagMoreComing = 1,
    kCFNetServiceFlagIsDomain = 2,
    kCFNetServiceFlagIsDefault = 4,
    kCFNetServiceFlagIsRegistrationDomain = 4,
    kCFNetServiceFlagRemove = 8
};

typedef struct __CFNetServiceBrowser* CFNetServiceBrowserRef;
typedef struct __CFNetService* CFNetServiceRef;

struct CFNetServiceClientContext {
    CFIndex version;
    void* info;
    CFAllocatorRetainCallBack retain;
    CFAllocatorReleaseCallBack release;
    CFAllocatorCopyDescriptionCallBack copyDescription;
};
typedef struct CFNetServiceClientContext CFNetServiceClientContext;

typedef void (*CFNetServiceBrowserClientCallBack)(
    CFNetServiceBrowserRef browser, CFOptionFlags flags, CFTypeRef domainOrService, CFStreamError* error, void* info);
typedef void (*CFNetServiceClientCallBack)(CFNetServiceRef theService, CFStreamError* error, void* info);

SB_EXPORT CFNetServiceBrowserRef CFNetServiceBrowserCreate(CFAllocatorRef alloc,
                                                           CFNetServiceBrowserClientCallBack clientCB,
                                                           CFNetServiceClientContext* clientContext);
SB_EXPORT void CFNetServiceBrowserScheduleWithRunLoop(CFNetServiceBrowserRef browser, CFRunLoopRef runLoop, CFStringRef runLoopMode);
SB_EXPORT Boolean CFNetServiceBrowserSearchForDomains(CFNetServiceBrowserRef browser, Boolean registrationDomains, CFStreamError* error);
SB_EXPORT void CFNetServiceBrowserUnscheduleFromRunLoop(CFNetServiceBrowserRef browser, CFRunLoopRef runLoop, CFStringRef runLoopMode);
SB_EXPORT void CFNetServiceBrowserStopSearch(CFNetServiceBrowserRef browser, CFStreamError* error);
SB_EXPORT void CFNetServiceBrowserInvalidate(CFNetServiceBrowserRef browser);
SB_EXPORT Boolean CFNetServiceBrowserSearchForServices(CFNetServiceBrowserRef browser,
                                                       CFStringRef domain,
                                                       CFStringRef serviceType,
                                                       CFStreamError* error);
SB_EXPORT Boolean CFNetServiceSetClient(CFNetServiceRef theService,
                                        CFNetServiceClientCallBack clientCB,
                                        CFNetServiceClientContext* clientContext);
SB_EXPORT void CFNetServiceCancel(CFNetServiceRef theService);
SB_EXPORT CFStringRef CFNetServiceGetName(CFNetServiceRef theService);
SB_EXPORT void CFNetServiceUnscheduleFromRunLoop(CFNetServiceRef theService, CFRunLoopRef runLoop, CFStringRef runLoopMode);

#endif /* _CFNETSERVICES_H_ */