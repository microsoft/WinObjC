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
    NSData *jsonData = [dataString dataUsingEncoding:NSUTF8StringEncoding];
    NSError *err = nil;
    id actualResult = [NSJSONSerialization JSONObjectWithData:jsonData options:opts error:&err];
    ASSERT_EQ_MSG(nil, err, "FAILED: err != nil");
    ASSERT_OBJCEQ_MSG(expectedResult, actualResult, "FAILED: expected (%@) != actual (%@)", expectedResult, actualResult);
}

void VerifyJSONObjectWithDataFails(NSString* dataString,
                                   NSJSONWritingOptions opts,
                                   NSInteger expectedErrorCode,
                                   NSString* expectedErrorDescription) {
    NSData *jsonData = [dataString dataUsingEncoding:NSUTF8StringEncoding];
    NSError *err = nil;
    id actualResult = [NSJSONSerialization JSONObjectWithData:jsonData options:opts error:&err];
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

void VerifyJSONObjectWithDataThrows(NSString* dataString, NSJSONWritingOptions opts) {
    NSError *err = nil;
    NSData *jsonData = nil;
    if (dataString != nil) {
        jsonData = [dataString dataUsingEncoding:NSUTF8StringEncoding];
    }

    ASSERT_ANY_THROW([NSJSONSerialization JSONObjectWithData:jsonData options:opts error:&err]);
}

void VerifyDataWithJSONObjectSucceeds(id testObject, NSString* expectedResult) {
    NSError *err = nil;
    NSData* result = [NSJSONSerialization dataWithJSONObject:testObject options:0 error:&err];
    NSString* actualResult = [[[NSString alloc] initWithData:result encoding:NSUTF8StringEncoding] autorelease];
    ASSERT_EQ_MSG(nil, err, "FAILED: err != nil");
    ASSERT_OBJCEQ_MSG(expectedResult, actualResult, "FAILED: expected (%@) != actual (%@)", expectedResult, actualResult);
}

void VerifyDataWithJSONObjectFails(id testObject, NSInteger expectedErrorCode, NSString* expectedErrorDescription) {
    NSError *err = nil;
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
    NSError *err = nil;
    ASSERT_ANY_THROW([NSJSONSerialization dataWithJSONObject:testObject options:0 error:&err]);
}

TEST(Foundation, JSONObjectWithDataTests) {
    NSString* testString1 = @"1";
    NSString* testString2 = @"false";
    NSString* testString3 = @"foo";
    NSString* testString4 = @"\"foo\"";
    NSString* testString5 = @"[1,2,3,4,5]";
    NSString* testString6 = @"{\"foo\":\"1\",\"bar\":\"2\"}";
    NSString* testString7 = @"{\"foo\"::::::\"1\",\"bar\":\"2\"}";
    NSString* testString8 = nil;

    // success cases
    VerifyJSONObjectWithDataSucceeds(testString1, 4, (id) [NSNumber numberWithInteger:1]);
    VerifyJSONObjectWithDataSucceeds(testString2, 4, (id) [NSNumber numberWithBool:NO]);
    VerifyJSONObjectWithDataSucceeds(testString4, 4, (id) @"foo");
    VerifyJSONObjectWithDataSucceeds(testString5, 0, (id) @[@1,@2,@3,@4,@5]);
    VerifyJSONObjectWithDataSucceeds(testString6, 0, (id) @{@"foo":@"1",@"bar":@"2"});
    VerifyJSONObjectWithDataSucceeds(testString5, 1, (id) @[@1,@2,@3,@4,@5]);
    VerifyJSONObjectWithDataSucceeds(testString6, 1, (id) @{@"foo":@"1",@"bar":@"2"});

    // error cases
    NSString* fragmentDescription = @"JSON text did not start with array or object and option to allow fragments not set.";
    VerifyJSONObjectWithDataFails(testString1, 0, 3840, fragmentDescription);
    VerifyJSONObjectWithDataFails(testString2, 0, 3840, fragmentDescription);
    VerifyJSONObjectWithDataFails(testString3, 0, 3840, @"Invalid JSON string.");
    VerifyJSONObjectWithDataFails(testString4, 0, 3840, fragmentDescription);
    VerifyJSONObjectWithDataFails(testString7, 0, 3840, @"Invalid JSON string.");
    VerifyJSONObjectWithDataThrows(testString8, 0);

    // Ensure nil error argument does not throw
    ASSERT_NO_THROW([NSJSONSerialization JSONObjectWithData:[testString1 dataUsingEncoding:NSUTF8StringEncoding] options:0 error:nil]);
}

TEST(Foundation, DataWithJSONObjectTests) {
    id testObject1 = nil;
    id testObject2 = (id) [NSNumber numberWithBool:NO];
    id testObject3 = (id) [NSNumber numberWithInteger:1];
    id testObject4 = (id) @"foo";
    id testObject5 = (id) @[@1, @2, @3, @4, @5];
    id testObject6 = (id) @{@"foo":@"1",@"bar":@"2"};
    id testObject7 = (id) @{@"foo":@{@"bar":@"1"},@"foo2":@{@"bar2":@"2"}};
    id testObject8 = (id) [NSUUID UUID];
    
    // success cases
    VerifyDataWithJSONObjectSucceeds(testObject5, @"[1,2,3,4,5]");
    VerifyDataWithJSONObjectSucceeds(testObject6, @"{\"foo\":\"1\",\"bar\":\"2\"}");
    VerifyDataWithJSONObjectSucceeds(testObject7, @"{\"foo\":{\"bar\":\"1\"},\"foo2\":{\"bar2\":\"2\"}}");

    // error case
    VerifyDataWithJSONObjectThrows(testObject2);
    VerifyDataWithJSONObjectThrows(testObject3);
    VerifyDataWithJSONObjectThrows(testObject4);
    VerifyDataWithJSONObjectThrows(testObject8);
    VerifyDataWithJSONObjectThrows(testObject1);

    // Ensure nil error argument does not throw
    ASSERT_NO_THROW([NSJSONSerialization dataWithJSONObject:testObject5 options:0 error:nil]);
}