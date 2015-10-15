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

#pragma once

@interface NSDate : NSObject {
@public
    double _curTime;
}
+ (double)timeIntervalSinceReferenceDate;
- (double)timeIntervalSinceReferenceDate;
- (double)timeIntervalSinceNow;
- (double)timeIntervalSince1970;
- (double)timeIntervalSinceDate:(id)ref;
- (NSDate*)dateByAddingTimeInterval:(double)interval;
- (NSDate*)initWithCoder:(NSCoder*)coder;
- (NSDate*)initWithString:(NSString*)string;
- (NSDate*)initWithTimeIntervalSince1970:(double)secondsSince1970;
- (NSDate*)initWithTimeIntervalSinceNow:(double)secondsSinceNow;
- (NSDate*)initWithTimeIntervalSinceReferenceDate:(double)ref;
- (NSDate*)initWithTimeInterval:(double)seconds sinceDate:(NSDate*)date;
- (NSInteger)compare:(NSDate*)toDate;
- (NSInteger)isEqualToDate:(NSDate*)toDate;
- (BOOL)isEqual:(NSDate*)toDate;
- (NSUInteger)hash;
- (NSDate*)earlierDate:(NSDate*)toDate;
- (NSDate*)laterDate:(NSDate*)toDate;
- (NSObject*)copyWithZone:(NSZone*)zone;
- (NSDate*)addTimeInterval:(double)seconds;
- (NSObject*)init;
- (NSObject*)encodeWithCoder:(NSCoder*)coder;
- (NSString*)description;
+ (NSDate*)dateWithString:(NSString*)string;
+ (NSDate*)date;
+ (NSDate*)distantPast;
+ (NSDate*)distantFuture;
+ (NSDate*)dateWithTimeIntervalSinceNow:(double)secondsSinceNow;
+ (NSDate*)dateWithTimeIntervalSince1970:(double)secondsSince1970;
+ (NSDate*)dateWithTimeInterval:(double)interval sinceDate:(NSDate*)date;
+ (NSDate*)dateWithTimeIntervalSinceReferenceDate:(double)secondsSinceRef;
@end
