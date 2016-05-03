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

#import <TestFramework.h>
#import <Foundation/Foundation.h>

TEST(NSOrderedSet, Init) {
    NSOrderedSet* orderedSet = [[NSOrderedSet alloc] init];
    ASSERT_TRUE_MSG(orderedSet != nil, "FAILED: orderedSet should be non-null!");
    [orderedSet release];
}

TEST(NSOrderedSet, orderedSet) {
    NSOrderedSet* orderedSet = [NSOrderedSet orderedSet];
    ASSERT_TRUE_MSG(orderedSet != nil, "FAILED: orderedSet should be non-null!");
    ASSERT_EQ(0, [orderedSet count]);
}

TEST(NSOrderedSet, orderedSetWithArray) {
    NSArray* array = @[ @1, @1, @1, @2, @2, @3 ];
    NSOrderedSet* orderedSet = [NSOrderedSet orderedSetWithArray:array];
    ASSERT_TRUE_MSG(orderedSet != nil, "FAILED: orderedSet should be non-null!");

    ASSERT_EQ(3, [orderedSet count]);
    ASSERT_OBJCEQ(@1, [orderedSet firstObject]);
    ASSERT_OBJCEQ(@3, [orderedSet lastObject]);
}

TEST(NSOrderedSet, orderedSetWithArrayWithOptions) {
    NSArray* array = @[ @1, @2, @3, @4, @5, @6 ];
    NSOrderedSet* orderedSet = [NSOrderedSet orderedSetWithArray:array range:NSMakeRange(2, 3) copyItems:YES];
    ASSERT_TRUE_MSG(orderedSet != nil, "FAILED: orderedSet should be non-null!");

    ASSERT_EQ(3, [orderedSet count]);
    ASSERT_OBJCEQ(@3, [orderedSet firstObject]);
    ASSERT_OBJCEQ(@5, [orderedSet lastObject]);
}

TEST(NSOrderedSet, orderedSetWithArrayWithOptions2) {
    NSArray* array = @[ @5, @5, @5, @5, @7, @6, @2, @3 ];
    NSOrderedSet* orderedSet = [NSOrderedSet orderedSetWithArray:array range:NSMakeRange(0, 8) copyItems:YES];
    ASSERT_TRUE_MSG(orderedSet != nil, "FAILED: orderedSet should be non-null!");

    ASSERT_EQ(5, [orderedSet count]);
    ASSERT_OBJCEQ(@5, [orderedSet firstObject]);
    ASSERT_OBJCEQ(@3, [orderedSet lastObject]);
}

TEST(NSOrderedSet, orderedSetWithObjects) {
    id array[3] = { @2, @1, @1 };
    NSOrderedSet* orderedSet = [NSOrderedSet orderedSetWithObjects:array count:3];
    ASSERT_EQ(2, [orderedSet count]);
    ASSERT_OBJCEQ(@2, [orderedSet firstObject]);
    ASSERT_OBJCEQ(@1, [orderedSet lastObject]);
}

TEST(NSOrderedSet, orderedSetWithOrderedSet) {
    id array[3] = { @2, @1, @1 };
    NSOrderedSet* set = [NSOrderedSet orderedSetWithObjects:array count:3];

    NSOrderedSet* orderedSet = [NSOrderedSet orderedSetWithOrderedSet:set range:NSMakeRange(0, [set count]) copyItems:NO];
    ASSERT_EQ(2, [orderedSet count]);
    ASSERT_OBJCEQ(@2, [orderedSet firstObject]);
    ASSERT_OBJCEQ(@1, [orderedSet lastObject]);
}

TEST(NSOrderedSet, orderedSetWithSet) {
    NSSet* set = [NSSet setWithObjects:@"Tesla", @"Benz", @"BMW", @"Acura", @"Audi", nil];
    NSOrderedSet* orderedSet = [NSOrderedSet orderedSetWithSet:set copyItems:YES];
    ASSERT_EQ(5, [orderedSet count]);
    ASSERT_TRUE([orderedSet containsObject:@"Tesla"]);
}