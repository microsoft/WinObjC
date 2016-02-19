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
#import <CoreFoundation/CFDictionary.h>
#import <CoreFoundation/CFString.h>

typedef struct {
    CMTime start;
    CMTime duration;
} CMTimeRange;

typedef struct {
    CMTimeRange source;
    CMTimeRange target;
} CMTimeMapping;

COREMEDIA_EXPORT CMTime CMTimeClampToRange(CMTime time, CMTimeRange range) STUB_METHOD;
COREMEDIA_EXPORT CMTime CMTimeMapDurationFromRangeToRange(CMTime dur, CMTimeRange fromRange, CMTimeRange toRange) STUB_METHOD;
COREMEDIA_EXPORT CMTime CMTimeMapTimeFromRangeToRange(CMTime t, CMTimeRange fromRange, CMTimeRange toRange) STUB_METHOD;
COREMEDIA_EXPORT Boolean CMTimeRangeContainsTime(CMTimeRange range, CMTime time) STUB_METHOD;
COREMEDIA_EXPORT Boolean CMTimeRangeContainsTimeRange(CMTimeRange range1, CMTimeRange range2) STUB_METHOD;
COREMEDIA_EXPORT CFDictionaryRef CMTimeRangeCopyAsDictionary(CMTimeRange range, CFAllocatorRef allocator) STUB_METHOD;
COREMEDIA_EXPORT CFStringRef CMTimeRangeCopyDescription(CFAllocatorRef allocator, CMTimeRange range) STUB_METHOD;
COREMEDIA_EXPORT Boolean CMTimeRangeEqual(CMTimeRange range1, CMTimeRange range2) STUB_METHOD;
COREMEDIA_EXPORT CMTimeRange CMTimeRangeFromTimeToTime(CMTime start, CMTime end) STUB_METHOD;
COREMEDIA_EXPORT CMTime CMTimeRangeGetEnd(CMTimeRange range) STUB_METHOD;
COREMEDIA_EXPORT CMTimeRange CMTimeRangeGetIntersection(CMTimeRange range1, CMTimeRange range2) STUB_METHOD;
COREMEDIA_EXPORT CMTimeRange CMTimeRangeGetUnion(CMTimeRange range1, CMTimeRange range2) STUB_METHOD;
COREMEDIA_EXPORT CMTimeRange CMTimeRangeMake(CMTime start, CMTime duration) STUB_METHOD;
COREMEDIA_EXPORT CMTimeRange CMTimeRangeMakeFromDictionary(CFDictionaryRef dict) STUB_METHOD;
COREMEDIA_EXPORT void CMTimeRangeShow(CMTimeRange range) STUB_METHOD;

#define CMTIMERANGE_IS_EMPTY(range) ((Boolean)(CMTIMERANGE_IS_VALID(range) && (CMTIME_COMPARE_INLINE(range.duration, ==, kCMTimeZero))))
#define CMTIMERANGE_IS_INDEFINITE(range) \
    ((Boolean)(CMTIMERANGE_IS_VALID(range) && (CMTIME_IS_INDEFINITE(range.start) || CMTIME_IS_INDEFINITE(range.duration))))
#define CMTIMERANGE_IS_INVALID(range) (!CMTIMERANGE_IS_VALID(range))
#define CMTIMERANGE_IS_VALID(range)                                                                              \
    ((Boolean)(CMTIME_IS_VALID(range.start) && CMTIME_IS_VALID(range.duration) && (range.duration.epoch == 0) && \
               (range.duration.value >= 0)))

COREMEDIA_EXPORT const CFStringRef kCMTimeRangeStartKey;
COREMEDIA_EXPORT const CFStringRef kCMTimeRangeDurationKey;
COREMEDIA_EXPORT const CMTimeRange kCMTimeRangeZero;
COREMEDIA_EXPORT const CMTimeRange kCMTimeRangeInvalid;