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

#import <CoreMedia/CMSync.h>
#import <StubReturn.h>
#import "AssertARCEnabled.h"

const CFStringRef kCMTimebaseNotification_EffectiveRateChanged = static_cast<CFStringRef>(@"CMTimebaseEffectiveRateChanged");
const CFStringRef kCMTimebaseNotification_TimeJumped = static_cast<CFStringRef>(@"CMTimebaseTimeJumped");

/**
 @Status Stub
*/
CFTypeID CMClockGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMClockRef CMClockGetHostTimeClock() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
uint64_t CMClockConvertHostTimeToSystemUnits(CMTime hostTime) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTime CMClockMakeHostTimeFromSystemUnits(uint64_t hostTime) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTime CMClockGetTime(CMClockRef clock) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMClockGetAnchorTime(CMClockRef clock, CMTime* outClockTime, CMTime* outReferenceClockTime) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
Boolean CMClockMightDrift(CMClockRef clock, CMClockRef otherClock) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
void CMClockInvalidate(CMClockRef clock) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
CFTypeID CMTimebaseGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMTimebaseCreateWithMasterClock(CFAllocatorRef allocator, CMClockRef masterClock, CMTimebaseRef _Nullable* timebaseOut) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMTimebaseCreateWithMasterTimebase(CFAllocatorRef allocator, CMTimebaseRef masterTimebase, CMTimebaseRef _Nullable* timebaseOut) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTimebaseRef CMTimebaseGetMasterTimebase(CMTimebaseRef timebase) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMClockRef CMTimebaseGetMasterClock(CMTimebaseRef timebase) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMClockOrTimebaseRef CMTimebaseGetMaster(CMTimebaseRef timebase) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMClockRef CMTimebaseGetUltimateMasterClock(CMTimebaseRef timebase) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTime CMTimebaseGetTime(CMTimebaseRef timebase) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTime CMTimebaseGetTimeWithTimeScale(CMTimebaseRef timebase, CMTimeScale timescale, CMTimeRoundingMethod method) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMTimebaseSetTime(CMTimebaseRef timebase, CMTime time) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMTimebaseSetAnchorTime(CMTimebaseRef timebase, CMTime timebaseTime, CMTime immediateMasterTime) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
Float64 CMTimebaseGetRate(CMTimebaseRef timebase) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMTimebaseGetTimeAndRate(CMTimebaseRef timebase, CMTime* outTime, Float64* outRate) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMTimebaseSetRate(CMTimebaseRef timebase, Float64 rate) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMTimebaseSetRateAndAnchorTime(CMTimebaseRef timebase, Float64 rate, CMTime timebaseTime, CMTime immediateMasterTime) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
Float64 CMTimebaseGetEffectiveRate(CMTimebaseRef timebase) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMTimebaseAddTimer(CMTimebaseRef timebase, CFRunLoopTimerRef timer, CFRunLoopRef runloop) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMTimebaseRemoveTimer(CMTimebaseRef timebase, CFRunLoopTimerRef timer) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMTimebaseSetTimerNextFireTime(CMTimebaseRef timebase, CFRunLoopTimerRef timer, CMTime fireTime, uint32_t flags) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMTimebaseSetTimerToFireImmediately(CMTimebaseRef timebase, CFRunLoopTimerRef timer) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMTimebaseAddTimerDispatchSource(CMTimebaseRef timebase, dispatch_source_t timerSource) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMTimebaseRemoveTimerDispatchSource(CMTimebaseRef timebase, dispatch_source_t timerSource) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMTimebaseSetTimerDispatchSourceNextFireTime(CMTimebaseRef timebase,
                                                      dispatch_source_t timerSource,
                                                      CMTime fireTime,
                                                      uint32_t flags) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMTimebaseSetTimerDispatchSourceToFireImmediately(CMTimebaseRef timebase, dispatch_source_t timerSource) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
Float64 CMSyncGetRelativeRate(CMClockOrTimebaseRef ofClockOrTimebase, CMClockOrTimebaseRef relativeToClockOrTimebase) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMSyncGetRelativeRateAndAnchorTime(CMClockOrTimebaseRef ofClockOrTimebase,
                                            CMClockOrTimebaseRef relativeToClockOrTimebase,
                                            Float64* outRelativeRate,
                                            CMTime* outOfClockOrTimebaseAnchorTime,
                                            CMTime* outRelativeToClockOrTimebaseAnchorTime) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTime CMSyncConvertTime(CMTime time, CMClockOrTimebaseRef fromClockOrTimebase, CMClockOrTimebaseRef toClockOrTimebase) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
Boolean CMSyncMightDrift(CMClockOrTimebaseRef clockOrTimebase1, CMClockOrTimebaseRef clockOrTimebase2) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTime CMSyncGetTime(CMClockOrTimebaseRef clockOrTimebase) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMTimebaseNotificationBarrier(CMTimebaseRef timebase) {
    UNIMPLEMENTED();
    return StubReturn();
}
