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

#import <CoreMedia/CMTime.h>
#import <StubReturn.h>
#import "AssertARCEnabled.h"

const CMTime kCMTimeInvalid = { 0, 0, 0, 0 };
const CMTime kCMTimeIndefinite = { 0, 0, 17, 0 };
const CMTime kCMTimePositiveInfinity = { 0, 0, 5, 0 };
const CMTime kCMTimeNegativeInfinity = { 0, 0, 9, 0 };
const CMTime kCMTimeZero = { 0, 1, 1, 0 };
const CFStringRef kCMTimeValueKey = static_cast<CFStringRef>(@"value");
const CFStringRef kCMTimeScaleKey = static_cast<CFStringRef>(@"timescale");
const CFStringRef kCMTimeEpochKey = static_cast<CFStringRef>(@"epoch");
const CFStringRef kCMTimeFlagsKey = static_cast<CFStringRef>(@"flags");

/**
 @Status Stub
*/
CMTime CMTimeMake(int64_t value, int32_t timescale) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTime CMTimeMakeFromDictionary(CFDictionaryRef dict) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTime CMTimeMakeWithEpoch(int64_t value, int32_t timescale, int64_t epoch) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTime CMTimeMakeWithSeconds(Float64 seconds, int32_t preferredTimeScale) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTime CMTimeAbsoluteValue(CMTime time) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTime CMTimeAdd(CMTime addend1, CMTime addend2) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
int32_t CMTimeCompare(CMTime time1, CMTime time2) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTime CMTimeConvertScale(CMTime time, int32_t newTimescale, CMTimeRoundingMethod method) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CFDictionaryRef CMTimeCopyAsDictionary(CMTime time, CFAllocatorRef allocator) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CFStringRef CMTimeCopyDescription(CFAllocatorRef allocator, CMTime time) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
Float64 CMTimeGetSeconds(CMTime time) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTime CMTimeMaximum(CMTime time1, CMTime time2) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTime CMTimeMinimum(CMTime time1, CMTime time2) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTime CMTimeMultiply(CMTime time, int32_t multiplier) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTime CMTimeMultiplyByFloat64(CMTime time, Float64 multiplier) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
void CMTimeShow(CMTime time) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
CMTime CMTimeSubtract(CMTime minuend, CMTime subtrahend) {
    UNIMPLEMENTED();
    return StubReturn();
}
