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
// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//

#import <Foundation/Foundation.h>
#import <TestFramework.h>

TEST(NSDate, BasicConstruction) {
    NSDate* d = [NSDate date];
    ASSERT_OBJCNE(nil, d);
}

TEST(NSDate, DescriptionWithLocale) {
    NSDate* d = [NSDate dateWithTimeIntervalSince1970:0];
    ASSERT_OBJCEQ([d descriptionWithLocale:nil], @"1970-01-01 00:00:00 +0000");
    ASSERT_OBJCNE(nil, [d descriptionWithLocale:[NSLocale localeWithLocaleIdentifier:@"ja_JP"]]);
}

TEST(NSDate, InitTimeIntervalSince1970) {
    NSTimeInterval ti = 1;
    NSDate* d = [NSDate dateWithTimeIntervalSince1970:ti];
    ASSERT_OBJCNE(nil, d);
}

TEST(NSDate, InitTimeIntervalSinceSinceDate) {
    NSTimeInterval ti = 1;
    NSDate* d1 = [[NSDate new] autorelease];
    NSDate* d2 = [NSDate dateWithTimeInterval:ti sinceDate:d1];
    ASSERT_OBJCNE(nil, d2);
}

TEST(NSDate, TimeIntervalSinceSinceDate) {
    NSTimeInterval ti = 1;
    NSDate* d1 = [[NSDate new] autorelease];
    NSDate* d2 = [NSDate dateWithTimeInterval:ti sinceDate:d1];
    ASSERT_EQ([d2 timeIntervalSinceDate:d1], ti);
}

TEST(NSDate, DistantFuture) {
    auto d = [NSDate distantFuture];
    ASSERT_OBJCNE(nil, d);
}

TEST(NSDate, DistantPast) {
    auto d = [NSDate distantPast];
    ASSERT_OBJCNE(nil, d);
}

TEST(NSDate, DateByAddingTimeInterval) {
    NSTimeInterval ti = 1;
    NSDate* d1 = [[NSDate new] autorelease];
    auto d2 = [d1 dateByAddingTimeInterval:ti];
    ASSERT_OBJCNE(nil, d2);
}

TEST(NSDate, EarlierDate) {
    NSTimeInterval ti = 1;
    NSDate* d1 = [[NSDate new] autorelease];
    auto d2 = [d1 dateByAddingTimeInterval:ti];
    ASSERT_OBJCEQ([d1 earlierDate:d2], d1);
}

TEST(NSDate, LaterDate) {
    NSTimeInterval ti = 1;
    NSDate* d1 = [[NSDate new] autorelease];
    auto d2 = [d1 dateByAddingTimeInterval:ti];
    ASSERT_OBJCEQ([d1 laterDate:d2], d2);
}

TEST(NSDate, Compare) {
    NSTimeInterval ti = 1;
    NSDate* d1 = [[NSDate new] autorelease];
    auto d2 = [d1 dateByAddingTimeInterval:ti];
    ASSERT_EQ([d1 compare:d2], NSOrderedAscending);
}

TEST(NSDate, IsEqualToDate) {
    NSTimeInterval ti = 1;
    NSDate* d1 = [NSDate date];
    auto d2 = [d1 dateByAddingTimeInterval:ti];
    auto d3 = [d1 dateByAddingTimeInterval:ti];
    ASSERT_TRUE([d2 isEqualToDate:d3]);
}
