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

#include <TestFramework.h>
#include <Foundation/Foundation.h>

TEST(NSError, NSErrorSanity) {
    NSError* error1 = [NSError errorWithDomain:@"TestDomain" code:2 userInfo:@{ @1 : @"foo", @2 : @"bar" }];
    NSError* error2 = [NSError errorWithDomain:@"TestDomain" code:2 userInfo:@{ @1 : @"foo", @2 : @"bar" }];
    NSError* error3 = [NSError errorWithDomain:@"DifferentTestDomain" code:2 userInfo:@{ @1 : @"foo", @2 : @"bar" }];

    ASSERT_OBJCEQ(error1, error2);
    ASSERT_EQ([error1 hash], [error2 hash]);
    ASSERT_OBJCNE(error1, error3);
    ASSERT_NE([error1 hash], [error3 hash]);
}

@interface NSTestError : NSError
@end

@implementation NSTestError
@end

TEST(NSError, NSErrorSubclassable) {
    NSString* expectedDomain = @"testDomain";
    NSDictionary* expectedUserInfo = @{ @1 : @"foo", @2 : @"bar" };
    NSInteger expectedCode = 2;
    NSTestError* testError = [[[NSTestError alloc] initWithDomain:expectedDomain code:expectedCode userInfo:expectedUserInfo] autorelease];

    ASSERT_OBJCEQ([testError domain], expectedDomain);
    ASSERT_EQ([testError code], expectedCode);
    ASSERT_OBJCEQ([testError userInfo], expectedUserInfo);
    ASSERT_TRUE([testError isMemberOfClass:[NSTestError class]]);
    ASSERT_TRUE([testError isKindOfClass:[NSError class]]);
    ASSERT_OBJCEQ((__bridge NSString*)CFErrorGetDomain((__bridge CFErrorRef)testError), expectedDomain);
    ASSERT_EQ((long)CFErrorGetCode((__bridge CFErrorRef)testError), (long)expectedCode);
    NSDictionary* actualUserInfo = (__bridge NSDictionary*)CFErrorCopyUserInfo((__bridge CFErrorRef)testError);
    ASSERT_OBJCEQ(actualUserInfo, expectedUserInfo);
    [actualUserInfo release];
    ASSERT_NO_THROW([testError description]);
    ASSERT_NO_THROW([testError debugDescription]);
}

TEST(NSError, NSErrorBridge) {
    NSString* expectedDomain = @"testDomain";
    NSDictionary* expectedUserInfo = @{ @1 : @"foo", @2 : @"bar" };
    NSInteger expectedCode = 2;
    NSError* testError = [NSError errorWithDomain:expectedDomain code:expectedCode userInfo:expectedUserInfo];

    ASSERT_OBJCEQ((__bridge NSString*)CFErrorGetDomain((__bridge CFErrorRef)testError), expectedDomain);
    ASSERT_EQ((long)CFErrorGetCode((__bridge CFErrorRef)testError), (long)expectedCode);
    NSDictionary* actualUserInfo = (__bridge NSDictionary*)CFErrorCopyUserInfo((__bridge CFErrorRef)testError);
    ASSERT_OBJCEQ(actualUserInfo, expectedUserInfo);
    [actualUserInfo release];
    ASSERT_TRUE([testError isMemberOfClass:[NSError class]]);
    ASSERT_NO_THROW([testError description]);
    ASSERT_NO_THROW([testError debugDescription]);
}

TEST(NSError, NSCFErrorBridge) {
    NSString* expectedDomain = @"testDomain";
    NSDictionary* expectedUserInfo = @{ @1 : @"foo", @2 : @"bar" };
    NSInteger expectedCode = 2;

    NSError* testError = (__bridge NSError*)
        CFErrorCreate(kCFAllocatorDefault, (__bridge CFStringRef)expectedDomain, expectedCode, (__bridge CFDictionaryRef)expectedUserInfo);

    ASSERT_OBJCEQ([testError domain], expectedDomain);
    ASSERT_EQ((long)[testError code], (long)expectedCode);
    ASSERT_OBJCEQ([testError userInfo], expectedUserInfo);
    ASSERT_TRUE([testError isKindOfClass:[NSError class]]);
    ASSERT_NO_THROW([testError description]);
    ASSERT_NO_THROW([testError debugDescription]);
    [testError release];
}

TEST(NSError, CanBeArchived) {
    NSString* expectedDomain = @"testDomain";
    NSDictionary* expectedUserInfo = @{@1 : @"foo", @2 : @"bar"};
    NSInteger expectedCode = 2;
    NSError* expected = [NSError errorWithDomain:expectedDomain code:expectedCode userInfo:expectedUserInfo];

    id data = [NSKeyedArchiver archivedDataWithRootObject:expected];
    id actual = [NSKeyedUnarchiver unarchiveObjectWithData:data];
    ASSERT_OBJCEQ(expected, actual);
}