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

#import <CoreMedia/CoreMediaExport.h>
#import <CoreMedia/CMTime.h>
#import <CoreFoundation/CFRunLoop.h>
#import <CoreFoundation/CFString.h>
#include <dispatch/dispatch.h>

typedef struct OpaqueCMClock* CMClockRef;
typedef struct OpaqueCMTimebase* CMTimebaseRef;
typedef CFTypeRef CMClockOrTimebaseRef;

COREMEDIA_EXPORT CFTypeID CMClockGetTypeID() STUB_METHOD;
COREMEDIA_EXPORT CMClockRef CMClockGetHostTimeClock() STUB_METHOD;
COREMEDIA_EXPORT uint64_t CMClockConvertHostTimeToSystemUnits(CMTime hostTime) STUB_METHOD;
COREMEDIA_EXPORT CMTime CMClockMakeHostTimeFromSystemUnits(uint64_t hostTime) STUB_METHOD;
COREMEDIA_EXPORT CMTime CMClockGetTime(CMClockRef clock) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMClockGetAnchorTime(CMClockRef clock, CMTime* outClockTime, CMTime* outReferenceClockTime) STUB_METHOD;
COREMEDIA_EXPORT Boolean CMClockMightDrift(CMClockRef clock, CMClockRef otherClock) STUB_METHOD;
COREMEDIA_EXPORT void CMClockInvalidate(CMClockRef clock) STUB_METHOD;
COREMEDIA_EXPORT CFTypeID CMTimebaseGetTypeID() STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMTimebaseCreateWithMasterClock(CFAllocatorRef allocator,
                                                          CMClockRef masterClock,
                                                          CMTimebaseRef _Nullable* timebaseOut) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMTimebaseCreateWithMasterTimebase(CFAllocatorRef allocator,
                                                             CMTimebaseRef masterTimebase,
                                                             CMTimebaseRef _Nullable* timebaseOut) STUB_METHOD;
COREMEDIA_EXPORT CMTimebaseRef CMTimebaseGetMasterTimebase(CMTimebaseRef timebase) STUB_METHOD;
COREMEDIA_EXPORT CMClockRef CMTimebaseGetMasterClock(CMTimebaseRef timebase) STUB_METHOD;
COREMEDIA_EXPORT CMClockOrTimebaseRef CMTimebaseGetMaster(CMTimebaseRef timebase) STUB_METHOD;
COREMEDIA_EXPORT CMClockRef CMTimebaseGetUltimateMasterClock(CMTimebaseRef timebase) STUB_METHOD;
COREMEDIA_EXPORT CMTime CMTimebaseGetTime(CMTimebaseRef timebase) STUB_METHOD;
COREMEDIA_EXPORT CMTime CMTimebaseGetTimeWithTimeScale(CMTimebaseRef timebase,
                                                       CMTimeScale timescale,
                                                       CMTimeRoundingMethod method) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMTimebaseSetTime(CMTimebaseRef timebase, CMTime time) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMTimebaseSetAnchorTime(CMTimebaseRef timebase, CMTime timebaseTime, CMTime immediateMasterTime) STUB_METHOD;
COREMEDIA_EXPORT Float64 CMTimebaseGetRate(CMTimebaseRef timebase) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMTimebaseGetTimeAndRate(CMTimebaseRef timebase, CMTime* outTime, Float64* outRate) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMTimebaseSetRate(CMTimebaseRef timebase, Float64 rate) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMTimebaseSetRateAndAnchorTime(CMTimebaseRef timebase,
                                                         Float64 rate,
                                                         CMTime timebaseTime,
                                                         CMTime immediateMasterTime) STUB_METHOD;
COREMEDIA_EXPORT Float64 CMTimebaseGetEffectiveRate(CMTimebaseRef timebase) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMTimebaseAddTimer(CMTimebaseRef timebase, CFRunLoopTimerRef timer, CFRunLoopRef runloop) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMTimebaseRemoveTimer(CMTimebaseRef timebase, CFRunLoopTimerRef timer) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMTimebaseSetTimerNextFireTime(CMTimebaseRef timebase, CFRunLoopTimerRef timer, CMTime fireTime, uint32_t flags)
    STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMTimebaseSetTimerToFireImmediately(CMTimebaseRef timebase, CFRunLoopTimerRef timer) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMTimebaseAddTimerDispatchSource(CMTimebaseRef timebase, dispatch_source_t timerSource) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMTimebaseRemoveTimerDispatchSource(CMTimebaseRef timebase, dispatch_source_t timerSource) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMTimebaseSetTimerDispatchSourceNextFireTime(CMTimebaseRef timebase,
                                                                       dispatch_source_t timerSource,
                                                                       CMTime fireTime,
                                                                       uint32_t flags) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMTimebaseSetTimerDispatchSourceToFireImmediately(CMTimebaseRef timebase,
                                                                            dispatch_source_t timerSource) STUB_METHOD;
COREMEDIA_EXPORT Float64 CMSyncGetRelativeRate(CMClockOrTimebaseRef ofClockOrTimebase,
                                               CMClockOrTimebaseRef relativeToClockOrTimebase) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMSyncGetRelativeRateAndAnchorTime(CMClockOrTimebaseRef ofClockOrTimebase,
                                                             CMClockOrTimebaseRef relativeToClockOrTimebase,
                                                             Float64* outRelativeRate,
                                                             CMTime* outOfClockOrTimebaseAnchorTime,
                                                             CMTime* outRelativeToClockOrTimebaseAnchorTime) STUB_METHOD;
COREMEDIA_EXPORT CMTime CMSyncConvertTime(CMTime time,
                                          CMClockOrTimebaseRef fromClockOrTimebase,
                                          CMClockOrTimebaseRef toClockOrTimebase) STUB_METHOD;
COREMEDIA_EXPORT Boolean CMSyncMightDrift(CMClockOrTimebaseRef clockOrTimebase1, CMClockOrTimebaseRef clockOrTimebase2) STUB_METHOD;
COREMEDIA_EXPORT CMTime CMSyncGetTime(CMClockOrTimebaseRef clockOrTimebase) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMTimebaseNotificationBarrier(CMTimebaseRef timebase) STUB_METHOD;

#define kCMTimebaseVeryLongCFTimeInterval (CFTimeInterval)(256.0 * 365.0 * 24.0 * 60.0 * 60.0);
#define kCMTimebaseFarFutureCFAbsoluteTime ((CFAbsoluteTime)kCMTimebaseVeryLongCFTimeInterval);

enum {
    kCMClockError_MissingRequiredParameter = -12745,
    kCMClockError_InvalidParameter = -12746,
    kCMClockError_AllocationFailed = -12747,
    kCMClockError_UnsupportedOperation = -12756,
};

enum {
    kCMTimebaseError_MissingRequiredParameter = -12748,
    kCMTimebaseError_InvalidParameter = -12749,
    kCMTimebaseError_AllocationFailed = -12750,
    kCMTimebaseError_TimerIntervalTooShort = -12751,
    kCMTimebaseError_ReadOnly = -12757,
};

enum {
    kCMSyncError_MissingRequiredParameter = -12752,
    kCMSyncError_InvalidParameter = -12753,
    kCMSyncError_AllocationFailed = -12754,
    kCMSyncError_RateMustBeNonZero = -12755,
};

COREMEDIA_EXPORT const CFStringRef kCMTimebaseNotification_EffectiveRateChanged;
COREMEDIA_EXPORT const CFStringRef kCMTimebaseNotification_TimeJumped;