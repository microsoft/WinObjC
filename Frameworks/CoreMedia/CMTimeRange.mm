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

#import <CoreMedia/CMTimeRange.h>
#import <StubReturn.h>
#import "AssertARCEnabled.h"

const CFStringRef kCMTimeRangeStartKey = static_cast<CFStringRef>(@"start");
const CFStringRef kCMTimeRangeDurationKey = static_cast<CFStringRef>(@"duration");
const CMTimeRange kCMTimeRangeZero = { { 0, 1, 1, 0 }, { 0, 1, 1, 0 } };
const CMTimeRange kCMTimeRangeInvalid = { { 0, 0, 0, 0 }, { 0, 0, 0, 0 } };

/**
 @Status Stub
*/
CMTime CMTimeClampToRange(CMTime time, CMTimeRange range) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTime CMTimeMapDurationFromRangeToRange(CMTime dur, CMTimeRange fromRange, CMTimeRange toRange) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTime CMTimeMapTimeFromRangeToRange(CMTime t, CMTimeRange fromRange, CMTimeRange toRange) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
Boolean CMTimeRangeContainsTime(CMTimeRange range, CMTime time) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
Boolean CMTimeRangeContainsTimeRange(CMTimeRange range1, CMTimeRange range2) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CFDictionaryRef CMTimeRangeCopyAsDictionary(CMTimeRange range, CFAllocatorRef allocator) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CFStringRef CMTimeRangeCopyDescription(CFAllocatorRef allocator, CMTimeRange range) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
Boolean CMTimeRangeEqual(CMTimeRange range1, CMTimeRange range2) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTimeRange CMTimeRangeFromTimeToTime(CMTime start, CMTime end) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTime CMTimeRangeGetEnd(CMTimeRange range) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTimeRange CMTimeRangeGetIntersection(CMTimeRange range1, CMTimeRange range2) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTimeRange CMTimeRangeGetUnion(CMTimeRange range1, CMTimeRange range2) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTimeRange CMTimeRangeMake(CMTime start, CMTime duration) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTimeRange CMTimeRangeMakeFromDictionary(CFDictionaryRef dict) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
void CMTimeRangeShow(CMTimeRange range) {
    UNIMPLEMENTED();
}
