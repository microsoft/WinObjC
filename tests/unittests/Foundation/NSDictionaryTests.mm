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

#include <TestFramework.h>
#import <Foundation/Foundation.h>

TEST(NSDictionary, Enumerate) {
    __block NSDictionary* testDictionary = @{ @"a" : @1, @"b" : @2, @"c" : @3, @"d" : @4 };

    [testDictionary enumerateKeysAndObjectsWithOptions:0
                                            usingBlock:^(id key, id object, BOOL* stop) {
                                                ASSERT_EQ((unsigned)[(NSNumber*)[testDictionary objectForKey:key] integerValue],
                                                          (unsigned)[object integerValue]);
                                            }];

    // Verify that the NSEnumerationConcurrent option executes the blocks concurrently
    __block NSCondition* condition = [NSCondition new];
    __block unsigned waitingCount = 0;
    [testDictionary enumerateKeysAndObjectsWithOptions:NSEnumerationConcurrent
                                            usingBlock:^(id key, id object, BOOL* stop) {
                                                [condition lock];
                                                waitingCount++;
                                                if (waitingCount == 4) {
                                                    waitingCount--;
                                                    [condition signal];
                                                    [condition unlock];
                                                    return;
                                                }
                                                [condition wait];
                                                waitingCount--;
                                                [condition signal];
                                                [condition unlock];
                                            }];

    ASSERT_EQ(0, waitingCount);
}

TEST(NSDictionary, keysSortedByValueUsingComparator) {
    NSDictionary* testDict = @{ @"A" : @2, @"B" : @4, @"C" : @3, @"D" : @1 };
    NSArray* actualArray = [testDict keysSortedByValueUsingComparator: ^(id obj1, id obj2) {
        return [obj1 compare:obj2];
    }];

    NSArray* expectedArray = @[@"D", @"A", @"C", @"B" ];
    ASSERT_OBJCEQ(expectedArray, actualArray);
}

TEST(NSDictionary, ExpandBeyondCapacity) {
    NSMutableDictionary* dictionary = [NSMutableDictionary dictionaryWithCapacity:1];

    NSUInteger expectedCount = 10;
    for (NSUInteger i = 0; i < expectedCount; i++) {
        [dictionary setObject:@1 forKey:[NSNumber numberWithInt:i]];
    }

    ASSERT_EQ(expectedCount, [dictionary count]);
}
