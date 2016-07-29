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

// Windows-only:
//      NSEnumerator enumeratorWithArray, enumeratorWithArrayReverse, objectEnumerator

#import "Foundation/Foundation.h"
#import "NSEnumeratorInternal.h"
#import "Starboard/SmartTypes.h"
#import "TestFramework.h"

TEST(NSEnumerator, EnumeratorWithArray) {
    // Important: this must be >16 elements to properly test NSFastEnumeration,
    // which re-calls countByEnumeratingWithState again after 16 elements
    StrongId<NSArray> testArray =
        @[ @7, @4234, @5435, @23, @-23, @7, @25, @-25, @234, @3424, @2452, @2, @1414, @-134, @4235, @13, @34242, @2234, @232, @432, @362 ];

    // allObjects forwards
    {
        StrongId<NSEnumerator> enumerator = [NSEnumerator enumeratorWithArray:testArray];
        StrongId<NSArray> resultArray = [enumerator allObjects];

        ASSERT_OBJCEQ(testArray, resultArray);
        ASSERT_OBJCEQ(nil, [enumerator nextObject]);
    }

    // nextObject forwards
    {
        StrongId<NSEnumerator> enumerator = [NSEnumerator enumeratorWithArray:testArray];
        for (size_t i = 0; i < [testArray count]; i++) {
            ASSERT_OBJCEQ([testArray objectAtIndex:i], [enumerator nextObject]);
        }
        ASSERT_OBJCEQ(nil, [enumerator nextObject]);
    }

    // countByEnumeratingWithState forwards
    {
        NSEnumerator* enumerator = [NSEnumerator enumeratorWithArray:testArray];
        size_t i = 0;
        for (id obj in enumerator) { // compiles to countByEnumeratingWithState
            ASSERT_OBJCEQ([testArray objectAtIndex:i++], obj);
        }
        ASSERT_EQ([testArray count], i);
    }

    // allObjects backwards
    {
        StrongId<NSEnumerator> enumerator = [NSEnumerator enumeratorWithArrayReverse:testArray];
        StrongId<NSArray> resultArray = [enumerator allObjects];
        StrongId<NSMutableArray> expectedResults = [NSMutableArray arrayWithCapacity:[testArray count]];
        for (size_t i = [testArray count]; i > 0; i--) {
            [expectedResults addObject:[testArray objectAtIndex:i - 1]];
        }

        ASSERT_OBJCEQ(expectedResults, resultArray);
        ASSERT_OBJCEQ(nil, [enumerator nextObject]);
    }

    // nextObject backwards
    {
        StrongId<NSEnumerator> enumerator = [NSEnumerator enumeratorWithArrayReverse:testArray];
        for (size_t i = [testArray count]; i > 0; i--) {
            ASSERT_OBJCEQ([testArray objectAtIndex:i - 1], [enumerator nextObject]);
        }
        ASSERT_OBJCEQ(nil, [enumerator nextObject]);
    }

    // countByEnumeratingWithState backwards
    {
        NSEnumerator* enumerator = [NSEnumerator enumeratorWithArrayReverse:testArray];
        size_t i = [testArray count];
        for (id obj in enumerator) { // compiles to countByEnumeratingWithState
            ASSERT_OBJCEQ([testArray objectAtIndex:--i], obj);
        }
        ASSERT_EQ(0, i);
    }
}

TEST(NSEnumerator, EnumeratorWithIterator) {
    // Using NSArray here as it leverages the enumeratorWithIterator functions in its forward enumerator
    // Important: this must be >16 elements to properly test NSFastEnumeration,
    // which re-calls countByEnumeratingWithState again after 16 elements
    StrongId<NSArray> testArray = @[ @305, @57, @4357, @2, @4, @57430, @57, @-4324, @-3985, @432, @4, @-4, @432, @42, @432, @3, @43, @-32 ];

    // allObjects
    {
        StrongId<NSEnumerator> enumerator = [testArray objectEnumerator];
        StrongId<NSArray> resultArray = [enumerator allObjects];

        ASSERT_OBJCEQ(testArray, resultArray);
        ASSERT_OBJCEQ(nil, [enumerator nextObject]);
    }

    // nextObject
    {
        StrongId<NSEnumerator> enumerator = [testArray objectEnumerator];
        for (size_t i = 0; i < [testArray count]; i++) {
            ASSERT_OBJCEQ([testArray objectAtIndex:i], [enumerator nextObject]);
        }
        ASSERT_OBJCEQ(nil, [enumerator nextObject]);
    }

    // countByEnumeratingWithState
    {
        size_t i = 0;
        NSArray* pTestArray = &*testArray;
        for (id obj in pTestArray) { // compiles to countByEnumeratingWithState
            ASSERT_OBJCEQ([testArray objectAtIndex:i++], obj);
        }
        ASSERT_EQ([testArray count], i);

        NSEnumerator* enumerator = [testArray objectEnumerator];
        i = 0;
        for (id obj in enumerator) { // compiles to countByEnumeratingWithState
            ASSERT_OBJCEQ([testArray objectAtIndex:i++], obj);
        }
        ASSERT_EQ([testArray count], i);
    }
}