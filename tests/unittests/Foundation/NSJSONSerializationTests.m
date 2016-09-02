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

#include "gtest-api.h"
#import <Foundation/Foundation.h>

void VerifyJSONObjectWithDataSucceeds(NSString* dataString, NSJSONWritingOptions opts, id expectedResult) {
    NSData* jsonData = [dataString dataUsingEncoding:NSUTF8StringEncoding];
    NSError* err = nil;
    id actualResult = [NSJSONSerialization JSONObjectWithData:jsonData options:opts error:&err];

    ASSERT_EQ_MSG(nil, err, "FAILED: err != nil");
    ASSERT_OBJCEQ_MSG(expectedResult, actualResult, "FAILED: expected (%@) != actual (%@)", expectedResult, actualResult);
}

void VerifyJSONObjectWithDataFails(NSString* dataString, NSJSONWritingOptions opts, NSInteger expectedErrorCode) {
    NSData* jsonData = [dataString dataUsingEncoding:NSUTF8StringEncoding];
    NSError* err = nil;
    id actualResult = [NSJSONSerialization JSONObjectWithData:jsonData options:opts error:&err];

    ASSERT_EQ_MSG(nil, actualResult, "FAILED: actualResult != nil");
    ASSERT_OBJCNE_MSG(nil, err, "FAILED: err == nil");
    ASSERT_OBJCEQ_MSG(@"NSCocoaErrorDomain", [err domain], "FAILED: expected error with domain NSCocoaErrorDomain");
    ASSERT_EQ_MSG(expectedErrorCode, [err code], "FAILED: unexpected error code %d", [err code]);
}

void VerifyJSONObjectWithDataThrows(NSString* dataString, NSJSONWritingOptions opts) {
    NSError* err = nil;
    NSData* jsonData = nil;
    if (dataString != nil) {
        jsonData = [dataString dataUsingEncoding:NSUTF8StringEncoding];
    }

    ASSERT_ANY_THROW([NSJSONSerialization JSONObjectWithData:jsonData options:opts error:&err]);
}

void VerifyDataWithJSONObjectSucceeds(id testObject, NSString* expectedResult) {
    NSError* err = nil;
    NSData* result = [NSJSONSerialization dataWithJSONObject:testObject options:0 error:&err];
    NSString* actualResult = [[[NSString alloc] initWithData:result encoding:NSUTF8StringEncoding] autorelease];

    ASSERT_EQ_MSG(nil, err, "FAILED: err != nil");
    ASSERT_OBJCEQ_MSG(expectedResult, actualResult, "FAILED: expected (%@) != actual (%@)", expectedResult, actualResult);
}

void VerifyDataWithJSONObjectFails(id testObject, NSInteger expectedErrorCode, NSString* expectedErrorDescription) {
    NSError* err = nil;
    NSData* result = [NSJSONSerialization dataWithJSONObject:testObject options:0 error:&err];
    NSString* actualResult = [[[NSString alloc] initWithData:result encoding:NSUTF8StringEncoding] autorelease];
    ASSERT_EQ_MSG(nil, actualResult, "FAILED: actualResult != nil");
    ASSERT_OBJCNE_MSG(nil, err, "FAILED: err == nil");
    ASSERT_OBJCEQ_MSG(@"NSCocoaErrorDomain", [err domain], "FAILED: expected error with domain NSCocoaErrorDomain");
    ASSERT_EQ_MSG(expectedErrorCode, [err code], "FAILED: unexpected error code %d", [err code]);
    NSString* actualErrorDescription = [[err userInfo] objectForKey:@"NSDebugDescription"];
    ASSERT_OBJCEQ_MSG(expectedErrorDescription,
                      actualErrorDescription,
                      "FAILED: expected error description (%s) did not match actual (%s).",
                      expectedErrorDescription,
                      actualErrorDescription);
}

void VerifyDataWithJSONObjectThrows(id testObject) {
    NSError* err = nil;
    ASSERT_ANY_THROW([NSJSONSerialization dataWithJSONObject:testObject options:0 error:&err]);
}

TEST(NSJSON, JSONObjectWithDataTests) {
    NSString* testString1 = @"1";
    NSString* testString2 = @"false";
    NSString* testString3 = @"foo";
    NSString* testString4 = @"\"foo\"";
    NSString* testString5 = @"[1,2,3,4,5]";
    NSString* testString6 = @"{\"foo\":\"1\",\"bar\":\"2\"}";
    NSString* testString7 = @"{\"foo\"::::::\"1\",\"bar\":\"2\"}";
    NSString* testString8 = nil;
    NSString* testString9 = @"{\"key\":\"value\",\"nullkey\":null,\"array\":[{\"subnullkey\":null}]}";

    // success cases
    VerifyJSONObjectWithDataSucceeds(testString1, 4, [NSNumber numberWithInteger:1]);
    VerifyJSONObjectWithDataSucceeds(testString2, 4, [NSNumber numberWithBool:NO]);
    VerifyJSONObjectWithDataSucceeds(testString4, 4, @"foo");
    VerifyJSONObjectWithDataSucceeds(testString5, 0, @[ @1, @2, @3, @4, @5 ]);
    VerifyJSONObjectWithDataSucceeds(testString6, 0, @{ @"foo" : @"1", @"bar" : @"2" });
    VerifyJSONObjectWithDataSucceeds(testString5, 1, @[ @1, @2, @3, @4, @5 ]);
    VerifyJSONObjectWithDataSucceeds(testString6, 1, @{ @"foo" : @"1", @"bar" : @"2" });
    VerifyJSONObjectWithDataSucceeds(
        testString9,
        0,
        @{ @"key" : @"value",
           @"nullkey" : [NSNull null],
           @"array" : @[ @{ @"subnullkey" : [NSNull null] } ] });

    // error cases
    VerifyJSONObjectWithDataFails(testString1, 0, 3840);
    VerifyJSONObjectWithDataFails(testString2, 0, 3840);
    VerifyJSONObjectWithDataFails(testString3, 0, 3840);
    VerifyJSONObjectWithDataFails(testString4, 0, 3840);
    VerifyJSONObjectWithDataFails(testString7, 0, 3840);
    VerifyJSONObjectWithDataThrows(testString8, 0);

    // Ensure nil error argument does not throw
    ASSERT_NO_THROW([NSJSONSerialization JSONObjectWithData:[testString1 dataUsingEncoding:NSUTF8StringEncoding] options:0 error:nullptr]);
}

TEST(NSJSON, DataWithJSONObjectTests) {
    id testObject1 = nil;
    id testObject2 = [NSNumber numberWithBool:NO];
    id testObject3 = [NSNumber numberWithInteger:1];
    id testObject4 = @"foo";
    id testObject5 = @[ @1, @2, @3, @4, @5 ];
    id testObject6 = @{ @"foo" : @"1", @"bar" : @"2" };
    id testObject7 = @{ @"foo" : @{ @"bar" : @"1" }, @"foo2" : @{ @"bar2" : @"2" } };
    id testObject8 = [NSUUID UUID];
    id testObject9 = @{ @"key" : @"value", @"nullkey" : [NSNull null], @"array" : @[ @{ @"subnullkey" : [NSNull null] } ] };

    // success cases
    VerifyDataWithJSONObjectSucceeds(testObject5, @"[1,2,3,4,5]");
    VerifyDataWithJSONObjectSucceeds(testObject6, @"{\"foo\":\"1\",\"bar\":\"2\"}");
    VerifyDataWithJSONObjectSucceeds(testObject7, @"{\"foo\":{\"bar\":\"1\"},\"foo2\":{\"bar2\":\"2\"}}");
    VerifyDataWithJSONObjectSucceeds(testObject9, @"{\"key\":\"value\",\"array\":[{\"subnullkey\":null}],\"nullkey\":null}");

    // error case
    VerifyDataWithJSONObjectThrows(testObject2);
    VerifyDataWithJSONObjectThrows(testObject3);
    VerifyDataWithJSONObjectThrows(testObject4);
    VerifyDataWithJSONObjectThrows(testObject8);
    VerifyDataWithJSONObjectThrows(testObject1);

    // Ensure nil error argument does not throw
    ASSERT_NO_THROW([NSJSONSerialization dataWithJSONObject:testObject5 options:0 error:nullptr]);
}

TEST(NSJSON, ValidJSONObjectTests) {
    id testObject1 = nil;
    id testObject2 = [NSNumber numberWithBool:NO];
    id testObject3 = @[ @1, @2, @3, @4, (NSNumber*)kCFNumberNaN ];
    id testObject4 = @"foo";
    id testObject5 = @[ @1, @2, @3, @4, @5 ];
    id testObject6 = @{ @"foo" : @"1", @"bar" : [NSNull null] };
    id testObject7 =
        @{ @"foo" : @{ @"bar" : @{ @"foo" : @"1", @"bar" : [NSNull null] } },
           @"foo2" : @{ @"bar2" : @[ @1, @2, @3, @4, @5 ] } };
    id testObject8 = [NSUUID UUID];

    ASSERT_EQ(NO, [NSJSONSerialization isValidJSONObject:testObject1]);
    ASSERT_EQ(NO, [NSJSONSerialization isValidJSONObject:testObject2]);
    ASSERT_EQ(NO, [NSJSONSerialization isValidJSONObject:testObject3]);
    ASSERT_EQ(NO, [NSJSONSerialization isValidJSONObject:testObject4]);
    ASSERT_EQ(YES, [NSJSONSerialization isValidJSONObject:testObject5]);
    ASSERT_EQ(YES, [NSJSONSerialization isValidJSONObject:testObject6]);
    ASSERT_EQ(YES, [NSJSONSerialization isValidJSONObject:testObject7]);
    ASSERT_EQ(NO, [NSJSONSerialization isValidJSONObject:testObject8]);
}
