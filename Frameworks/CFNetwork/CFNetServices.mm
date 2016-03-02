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

#import <StubReturn.h>
#import <CFNetwork/CFNetServices.h>

/** @Status Stub */
const SInt32 kCFStreamErrorDomainMach = StubConstant();
/** @Status Stub */
const SInt32 kCFStreamErrorDomainNetServices = StubConstant();

/**
 @Status Stub
 @Notes
*/
CFNetServiceRef CFNetServiceCreate(CFAllocatorRef alloc, CFStringRef domain, CFStringRef serviceType, CFStringRef name, SInt32 port) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFNetServiceRef CFNetServiceCreateCopy(CFAllocatorRef alloc, CFNetServiceRef service) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFNetServiceMonitorRef CFNetServiceMonitorCreate(CFAllocatorRef alloc,
                                                 CFNetServiceRef theService,
                                                 CFNetServiceMonitorClientCallBack clientCB,
                                                 CFNetServiceClientContext* clientContext) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFNetServiceBrowserRef CFNetServiceBrowserCreate(CFAllocatorRef alloc,
                                                 CFNetServiceBrowserClientCallBack clientCB,
                                                 CFNetServiceClientContext* clientContext) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CFNetServiceBrowserInvalidate(CFNetServiceBrowserRef browser) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CFNetServiceBrowserScheduleWithRunLoop(CFNetServiceBrowserRef browser, CFRunLoopRef runLoop, CFStringRef runLoopMode) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
Boolean CFNetServiceBrowserSearchForDomains(CFNetServiceBrowserRef browser, Boolean registrationDomains, CFStreamError* error) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
Boolean CFNetServiceBrowserSearchForServices(CFNetServiceBrowserRef browser,
                                             CFStringRef domain,
                                             CFStringRef serviceType,
                                             CFStreamError* error) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CFNetServiceBrowserStopSearch(CFNetServiceBrowserRef browser, CFStreamError* error) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CFNetServiceBrowserUnscheduleFromRunLoop(CFNetServiceBrowserRef browser, CFRunLoopRef runLoop, CFStringRef runLoopMode) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CFNetServiceCancel(CFNetServiceRef theService) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
CFDictionaryRef CFNetServiceCreateDictionaryWithTXTData(CFAllocatorRef alloc, CFDataRef txtRecord) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFDataRef CFNetServiceCreateTXTDataWithDictionary(CFAllocatorRef alloc, CFDictionaryRef keyValuePairs) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFArrayRef CFNetServiceGetAddressing(CFNetServiceRef theService) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFStringRef CFNetServiceGetTargetHost(CFNetServiceRef theService) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFStringRef CFNetServiceGetDomain(CFNetServiceRef theService) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFStringRef CFNetServiceGetName(CFNetServiceRef theService) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
SInt32 CFNetServiceGetPortNumber(CFNetServiceRef theService) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFDataRef CFNetServiceGetTXTData(CFNetServiceRef theService) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFStringRef CFNetServiceGetType(CFNetServiceRef theService) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CFNetServiceMonitorInvalidate(CFNetServiceMonitorRef monitor) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CFNetServiceMonitorScheduleWithRunLoop(CFNetServiceMonitorRef monitor, CFRunLoopRef runLoop, CFStringRef runLoopMode) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
Boolean CFNetServiceMonitorStart(CFNetServiceMonitorRef monitor, CFNetServiceMonitorType recordType, CFStreamError* error) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CFNetServiceMonitorStop(CFNetServiceMonitorRef monitor, CFStreamError* error) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CFNetServiceMonitorUnscheduleFromRunLoop(CFNetServiceMonitorRef monitor, CFRunLoopRef runLoop, CFStringRef runLoopMode) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
Boolean CFNetServiceRegisterWithOptions(CFNetServiceRef theService, CFOptionFlags options, CFStreamError* error) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
Boolean CFNetServiceResolveWithTimeout(CFNetServiceRef theService, CFTimeInterval timeout, CFStreamError* error) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CFNetServiceScheduleWithRunLoop(CFNetServiceRef theService, CFRunLoopRef runLoop, CFStringRef runLoopMode) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
Boolean CFNetServiceSetClient(CFNetServiceRef theService, CFNetServiceClientCallBack clientCB, CFNetServiceClientContext* clientContext) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
Boolean CFNetServiceSetTXTData(CFNetServiceRef theService, CFDataRef txtRecord) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CFNetServiceUnscheduleFromRunLoop(CFNetServiceRef theService, CFRunLoopRef runLoop, CFStringRef runLoopMode) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
CFTypeID CFNetServiceGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFTypeID CFNetServiceMonitorGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFTypeID CFNetServiceBrowserGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}
