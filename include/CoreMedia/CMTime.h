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
#import <CoreFoundation/CFDictionary.h>
#import <CoreFoundation/CFString.h>

typedef int64_t CMTimeValue;
typedef int32_t CMTimeScale;
typedef int64_t CMTimeEpoch;
typedef uint32_t CMTimeFlags;
typedef struct {
    CMTimeValue value;
    CMTimeScale timescale;
    CMTimeFlags flags;
    CMTimeEpoch epoch;
} CMTime;

typedef uint32_t CMTimeRoundingMethod;

COREMEDIA_EXPORT CMTime CMTimeMake(int64_t value, int32_t timescale) STUB_METHOD;
COREMEDIA_EXPORT CMTime CMTimeMakeFromDictionary(CFDictionaryRef dict) STUB_METHOD;
COREMEDIA_EXPORT CMTime CMTimeMakeWithEpoch(int64_t value, int32_t timescale, int64_t epoch) STUB_METHOD;
COREMEDIA_EXPORT CMTime CMTimeMakeWithSeconds(Float64 seconds, int32_t preferredTimeScale) STUB_METHOD;
COREMEDIA_EXPORT CMTime CMTimeAbsoluteValue(CMTime time) STUB_METHOD;
COREMEDIA_EXPORT CMTime CMTimeAdd(CMTime addend1, CMTime addend2) STUB_METHOD;
COREMEDIA_EXPORT int32_t CMTimeCompare(CMTime time1, CMTime time2) STUB_METHOD;
COREMEDIA_EXPORT CMTime CMTimeConvertScale(CMTime time, int32_t newTimescale, CMTimeRoundingMethod method) STUB_METHOD;
COREMEDIA_EXPORT CFDictionaryRef CMTimeCopyAsDictionary(CMTime time, CFAllocatorRef allocator) STUB_METHOD;
COREMEDIA_EXPORT CFStringRef CMTimeCopyDescription(CFAllocatorRef allocator, CMTime time) STUB_METHOD;
COREMEDIA_EXPORT Float64 CMTimeGetSeconds(CMTime time) STUB_METHOD;
COREMEDIA_EXPORT CMTime CMTimeMaximum(CMTime time1, CMTime time2) STUB_METHOD;
COREMEDIA_EXPORT CMTime CMTimeMinimum(CMTime time1, CMTime time2) STUB_METHOD;
COREMEDIA_EXPORT CMTime CMTimeMultiply(CMTime time, int32_t multiplier) STUB_METHOD;
COREMEDIA_EXPORT CMTime CMTimeMultiplyByFloat64(CMTime time, Float64 multiplier) STUB_METHOD;
COREMEDIA_EXPORT void CMTimeShow(CMTime time) STUB_METHOD;
COREMEDIA_EXPORT CMTime CMTimeSubtract(CMTime minuend, CMTime subtrahend) STUB_METHOD;

#define CMTIME_COMPARE_INLINE(time1, comparator, time2) ((Boolean)(CMTimeCompare(time1, time2) comparator 0))
#define CMTIME_IS_VALID(time) ((Boolean)(((time).flags & kCMTimeFlags_Valid) != 0))
#define CMTIME_IS_INVALID(time) (!CMTIME_IS_VALID(time))
#define CMTIME_IS_POSITIVE_INFINITY(time) ((Boolean)(CMTIME_IS_VALID(time) && (((time).flags & kCMTimeFlags_PositiveInfinity) != 0)))
#define CMTIME_IS_NEGATIVE_INFINITY(time) ((Boolean)(CMTIME_IS_VALID(time) && (((time).flags & kCMTimeFlags_NegativeInfinity) != 0)))
#define CMTIME_IS_INDEFINITE(time) ((Boolean)(CMTIME_IS_VALID(time) && (((time).flags & kCMTimeFlags_Indefinite) != 0)))
#define CMTIME_IS_NUMERIC(time) \
    ((Boolean)(((time).flags & (kCMTimeFlags_Valid | kCMTimeFlags_ImpliedValueFlagsMask)) == kCMTimeFlags_Valid))
#define CMTIME_HAS_BEEN_ROUNDED(time) ((Boolean)(CMTIME_IS_NUMERIC(time) && (((time).flags & kCMTimeFlags_HasBeenRounded) != 0)))

COREMEDIA_EXPORT const CMTime kCMTimeInvalid;
COREMEDIA_EXPORT const CMTime kCMTimeIndefinite;
COREMEDIA_EXPORT const CMTime kCMTimePositiveInfinity;
COREMEDIA_EXPORT const CMTime kCMTimeNegativeInfinity;
COREMEDIA_EXPORT const CMTime kCMTimeZero;

enum {
    kCMTimeFlags_Valid = 1UL << 0,
    kCMTimeFlags_HasBeenRounded = 1UL << 1,
    kCMTimeFlags_PositiveInfinity = 1UL << 2,
    kCMTimeFlags_NegativeInfinity = 1UL << 3,
    kCMTimeFlags_Indefinite = 1UL << 4,
    kCMTimeFlags_ImpliedValueFlagsMask = kCMTimeFlags_PositiveInfinity | kCMTimeFlags_NegativeInfinity | kCMTimeFlags_Indefinite
};

#define kCMTimeMaxTimescale 0x7fffffffL
enum {
    kCMTimeRoundingMethod_RoundHalfAwayFromZero = 1,
    kCMTimeRoundingMethod_RoundTowardZero = 2,
    kCMTimeRoundingMethod_RoundAwayFromZero = 3,
    kCMTimeRoundingMethod_QuickTime = 4,
    kCMTimeRoundingMethod_RoundTowardPositiveInfinity = 5,
    kCMTimeRoundingMethod_RoundTowardNegativeInfinity = 6,
    kCMTimeRoundingMethod_Default = kCMTimeRoundingMethod_RoundHalfAwayFromZero
};

COREMEDIA_EXPORT const CFStringRef kCMTimeValueKey;
COREMEDIA_EXPORT const CFStringRef kCMTimeScaleKey;
COREMEDIA_EXPORT const CFStringRef kCMTimeEpochKey;
COREMEDIA_EXPORT const CFStringRef kCMTimeFlagsKey;
