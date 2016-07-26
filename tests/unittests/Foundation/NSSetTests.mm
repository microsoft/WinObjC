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
#include <Foundation\Foundation.h>

TEST(NSSet, ExpandBeyondCapacity) {
    NSMutableSet* set = [NSMutableSet setWithCapacity:1];

    NSUInteger expectedCount = 10;
    for (NSUInteger i = 0; i < expectedCount; i++) {
        [set addObject:[NSNumber numberWithInt:i]];
    }

    ASSERT_EQ(expectedCount, [set count]);
}

TEST(NSSet, ContainsObject) {
    NSSet* set = [NSSet setWithObjects:@1, @2, @3, nil];
    ASSERT_NE(nil, set);
    ASSERT_FALSE([set containsObject:nil]);
}

TEST(NSSet, SetValueForKey) {
    NSMutableDictionary* dict1 = [[@{} mutableCopy] autorelease];
    NSMutableDictionary* dict2 = [[@{@"a" : @"1"} mutableCopy] autorelease];
    NSMutableDictionary* dict3 = [[@{@"b" : @"2"} mutableCopy] autorelease];
    NSSet* set = [NSSet setWithObjects:dict1, dict2, dict3, nil];
    id key = @"key";
    id expected = @"expectedValue";
    [set setValue:expected forKey:key];
    ASSERT_OBJCEQ(expected, [dict1 objectForKey:key]);
    ASSERT_OBJCEQ(expected, [dict2 objectForKey:key]);
    ASSERT_OBJCEQ(expected, [dict3 objectForKey:key]);
}

TEST(NSSet, ObjectsPassingTest) {
    NSSet* set = [NSSet setWithObjects:@1, @2, @3, @4, @5, @6, nil];
    NSSet* expectedEvensLessThanFive = [NSSet setWithObjects:@2, @4, nil];
    NSSet* actual = [set objectsPassingTest:^(id obj, BOOL* stop){
        if ([obj intValue] % 2 == 0) {
            return YES;
        }

        if([obj intValue] >= 5) {
            *stop = YES;
        }

        return NO;
    }];

    ASSERT_OBJCEQ(expectedEvensLessThanFive, actual);
}