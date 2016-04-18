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
#import <CFNetwork/CFNetworkErrors.h>
#import <CoreFoundation/CoreFoundation.h>

struct CFNetServiceClientContext {
    CFIndex version;
    void* info;
    CFAllocatorRetainCallBack retain;
    CFAllocatorReleaseCallBack release;
    CFAllocatorCopyDescriptionCallBack copyDescription;
};

typedef struct __CFNetServiceBrowser* CFNetServiceBrowserRef;
typedef struct __CFNetServiceMonitor* CFNetServiceMonitorRef;
typedef struct __CFNetService* CFNetServiceRef;
typedef enum CFNetServiceMonitorType CFNetServiceMonitorType;
typedef void (*CFNetServiceBrowserClientCallBack)(
    CFNetServiceBrowserRef browser, CFOptionFlags flags, CFTypeRef domainOrService, CFStreamError* error, void* info);
typedef void (*CFNetServiceClientCallBack)(CFNetServiceRef theService, CFStreamError* error, void* info);
typedef void (*CFNetServiceMonitorClientCallBack)(CFNetServiceMonitorRef theMonitor,
                                                  CFNetServiceRef theService,
                                                  CFNetServiceMonitorType typeInfo,
                                                  CFDataRef rdata,
                                                  CFStreamError* error,
                                                  void* info);

typedef struct CFNetServiceClientContext CFNetServiceClientContext;

CFNETWORK_EXPORT CFNetServiceRef
CFNetServiceCreate(CFAllocatorRef alloc, CFStringRef domain, CFStringRef serviceType, CFStringRef name, SInt32 port) STUB_METHOD;

CFNETWORK_EXPORT CFNetServiceRef CFNetServiceCreateCopy(CFAllocatorRef alloc, CFNetServiceRef service) STUB_METHOD;

CFNETWORK_EXPORT CFNetServiceMonitorRef CFNetServiceMonitorCreate(CFAllocatorRef alloc,
                                                                  CFNetServiceRef theService,
                                                                  CFNetServiceMonitorClientCallBack clientCB,
                                                                  CFNetServiceClientContext* clientContext) STUB_METHOD;

CFNETWORK_EXPORT CFNetServiceBrowserRef CFNetServiceBrowserCreate(CFAllocatorRef alloc,
                                                                  CFNetServiceBrowserClientCallBack clientCB,
                                                                  CFNetServiceClientContext* clientContext) STUB_METHOD;

CFNETWORK_EXPORT void CFNetServiceBrowserInvalidate(CFNetServiceBrowserRef browser) STUB_METHOD;

CFNETWORK_EXPORT void CFNetServiceBrowserScheduleWithRunLoop(CFNetServiceBrowserRef browser,
                                                             CFRunLoopRef runLoop,
                                                             CFStringRef runLoopMode) STUB_METHOD;

CFNETWORK_EXPORT Boolean CFNetServiceBrowserSearchForDomains(CFNetServiceBrowserRef browser,
                                                             Boolean registrationDomains,
                                                             CFStreamError* error) STUB_METHOD;

CFNETWORK_EXPORT Boolean CFNetServiceBrowserSearchForServices(CFNetServiceBrowserRef browser,
                                                              CFStringRef domain,
                                                              CFStringRef serviceType,
                                                              CFStreamError* error) STUB_METHOD;
CFNETWORK_EXPORT void CFNetServiceBrowserStopSearch(CFNetServiceBrowserRef browser, CFStreamError* error) STUB_METHOD;

CFNETWORK_EXPORT void CFNetServiceBrowserUnscheduleFromRunLoop(CFNetServiceBrowserRef browser,
                                                               CFRunLoopRef runLoop,
                                                               CFStringRef runLoopMode) STUB_METHOD;

CFNETWORK_EXPORT void CFNetServiceCancel(CFNetServiceRef theService) STUB_METHOD;

CFNETWORK_EXPORT CFDictionaryRef CFNetServiceCreateDictionaryWithTXTData(CFAllocatorRef alloc, CFDataRef txtRecord) STUB_METHOD;
CFNETWORK_EXPORT CFDataRef CFNetServiceCreateTXTDataWithDictionary(CFAllocatorRef alloc, CFDictionaryRef keyValuePairs) STUB_METHOD;
CFNETWORK_EXPORT CFArrayRef CFNetServiceGetAddressing(CFNetServiceRef theService) STUB_METHOD;
CFNETWORK_EXPORT CFStringRef CFNetServiceGetTargetHost(CFNetServiceRef theService) STUB_METHOD;
CFNETWORK_EXPORT CFStringRef CFNetServiceGetDomain(CFNetServiceRef theService) STUB_METHOD;
CFNETWORK_EXPORT CFStringRef CFNetServiceGetName(CFNetServiceRef theService) STUB_METHOD;
CFNETWORK_EXPORT SInt32 CFNetServiceGetPortNumber(CFNetServiceRef theService) STUB_METHOD;
CFNETWORK_EXPORT CFDataRef CFNetServiceGetTXTData(CFNetServiceRef theService) STUB_METHOD;
CFNETWORK_EXPORT CFStringRef CFNetServiceGetType(CFNetServiceRef theService) STUB_METHOD;
CFNETWORK_EXPORT void CFNetServiceMonitorInvalidate(CFNetServiceMonitorRef monitor) STUB_METHOD;
CFNETWORK_EXPORT void CFNetServiceMonitorScheduleWithRunLoop(CFNetServiceMonitorRef monitor,
                                                             CFRunLoopRef runLoop,
                                                             CFStringRef runLoopMode) STUB_METHOD;

CFNETWORK_EXPORT Boolean CFNetServiceMonitorStart(CFNetServiceMonitorRef monitor,
                                                  CFNetServiceMonitorType recordType,
                                                  CFStreamError* error) STUB_METHOD;
CFNETWORK_EXPORT void CFNetServiceMonitorStop(CFNetServiceMonitorRef monitor, CFStreamError* error) STUB_METHOD;

CFNETWORK_EXPORT void CFNetServiceMonitorUnscheduleFromRunLoop(CFNetServiceMonitorRef monitor,
                                                               CFRunLoopRef runLoop,
                                                               CFStringRef runLoopMode) STUB_METHOD;

CFNETWORK_EXPORT Boolean CFNetServiceRegisterWithOptions(CFNetServiceRef theService,
                                                         CFOptionFlags options,
                                                         CFStreamError* error) STUB_METHOD;

CFNETWORK_EXPORT Boolean CFNetServiceResolveWithTimeout(CFNetServiceRef theService,
                                                        CFTimeInterval timeout,
                                                        CFStreamError* error) STUB_METHOD;

CFNETWORK_EXPORT void CFNetServiceScheduleWithRunLoop(CFNetServiceRef theService,
                                                      CFRunLoopRef runLoop,
                                                      CFStringRef runLoopMode) STUB_METHOD;

CFNETWORK_EXPORT Boolean CFNetServiceSetClient(CFNetServiceRef theService,
                                               CFNetServiceClientCallBack clientCB,
                                               CFNetServiceClientContext* clientContext) STUB_METHOD;

CFNETWORK_EXPORT Boolean CFNetServiceSetTXTData(CFNetServiceRef theService, CFDataRef txtRecord) STUB_METHOD;

CFNETWORK_EXPORT void CFNetServiceUnscheduleFromRunLoop(CFNetServiceRef theService,
                                                        CFRunLoopRef runLoop,
                                                        CFStringRef runLoopMode) STUB_METHOD;

CFNETWORK_EXPORT CFTypeID CFNetServiceGetTypeID() STUB_METHOD;
CFNETWORK_EXPORT CFTypeID CFNetServiceMonitorGetTypeID() STUB_METHOD;
CFNETWORK_EXPORT CFTypeID CFNetServiceBrowserGetTypeID() STUB_METHOD;

enum { kCFNetServiceFlagNoAutoRename = 1 };

enum {
    kCFNetServiceFlagMoreComing = 1,
    kCFNetServiceFlagIsDomain = 2,
    kCFNetServiceFlagIsDefault = 4,
    kCFNetServiceFlagIsRegistrationDomain = 4, /* For compatibility  */
    kCFNetServiceFlagRemove = 8
};

enum { kCFNetServiceMonitorTXT = 1 };

CFNETWORK_EXPORT const SInt32 kCFStreamErrorDomainMach;
CFNETWORK_EXPORT const SInt32 kCFStreamErrorDomainNetServices;
