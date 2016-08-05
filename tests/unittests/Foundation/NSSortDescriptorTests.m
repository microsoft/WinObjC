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

TEST(NSSortDescriptor, InitDescriptorWithKey) {
    NSString* key = @"FooBar";
    NSSortDescriptor* sortDesc = [NSSortDescriptor sortDescriptorWithKey:key ascending:YES];
    ASSERT_TRUE_MSG(sortDesc != nullptr, "FAILED: sortDesc should be non-null!");

    ASSERT_EQ_MSG(YES, [sortDesc ascending], "FAILED: ascending should be YES");
    ASSERT_OBJCEQ_MSG(NSStringFromSelector(@selector(compare:)),
                      NSStringFromSelector([sortDesc selector]),
                      "FAILED: selector should be default SEL");
    ASSERT_TRUE_MSG([sortDesc selector] != nullptr, "FAILED: selector should be non-null!");
    ASSERT_EQ_MSG(nullptr, (void*)[sortDesc comparator], "FAILED: comparator should be null.");
    ASSERT_OBJCEQ_MSG(key, [sortDesc key], "FAILED: key does not match the supplied key.");

    [key release];
}

TEST(NSSortDescriptor, SortDescriptorWithNilKey) {
    NSArray* data = @[ @"B", @"D", @"F", @"E", @"A", @"C" ];
    NSSortDescriptor* sortDesc = [NSSortDescriptor sortDescriptorWithKey:nil ascending:YES];
    ASSERT_TRUE_MSG(sortDesc != nullptr, "FAILED: sortDesc should be non-null!");

    ASSERT_EQ_MSG(YES, [sortDesc ascending], "FAILED: ascending should be YES");
    ASSERT_TRUE_MSG([sortDesc selector] != nullptr, "FAILED: selector should be non-null!");
    ASSERT_EQ_MSG(nullptr, (void*)[sortDesc comparator], "FAILED: comparator should be null.");
    ASSERT_OBJCEQ_MSG(nil, [sortDesc key], "FAILED: key does not match the supplied key.");
    NSArray* sortedValue = [data sortedArrayUsingDescriptors:@[ sortDesc ]];

    // verify sorted value
    ASSERT_OBJCEQ_MSG(@"A", sortedValue[0], "FAILED: Failed to sort the data in correct order.");
    ASSERT_OBJCEQ_MSG(@"D", sortedValue[3], "FAILED: Failed to sort the data in correct order.");
    ASSERT_OBJCEQ_MSG(@"F", sortedValue[5], "FAILED: Failed to sort the data in correct order.");
}

// Used for testing keys and custom comparators.
@interface TestPoint : NSObject
@property (assign) NSString* name;
@property (assign) NSInteger xCord;
@property (assign) NSInteger yCord;
@end

@implementation TestPoint
- (instancetype)initWithName:(NSString*)nme xCord:(NSInteger)x yCord:(NSInteger)y {
    if (self == [super init]) {
        _name = [nme copy];
        _xCord = x;
        _yCord = y;
    }
    return self;
}

- (void)dealloc {
    [_name release];
    [super dealloc];
}

@end

TEST(NSSortDescriptor, SortDescriptorWithCustomObjectAndKey) {
    NSMutableArray* data = [[NSMutableArray alloc] init];
    NSString* key = @"xCord";
    int size = 10;

    TestPoint* firstObj = [[[TestPoint alloc] initWithName:@"obj1" xCord:0 yCord:10] autorelease];
    TestPoint* lastObj = [[[TestPoint alloc] initWithName:@"obj3" xCord:100 yCord:30] autorelease];
    [data addObject:firstObj];
    [data addObject:lastObj];

    for (int i = 1; i < size; ++i) {
        TestPoint* obj = [[[TestPoint alloc] initWithName:@"testObj" xCord:i yCord:(i + 1)] autorelease];
        [data addObject:obj];
    }

    NSSortDescriptor* sortDesc = [NSSortDescriptor sortDescriptorWithKey:key ascending:YES];
    ASSERT_TRUE_MSG(sortDesc != nullptr, "FAILED: sortDesc should be non-null!");

    ASSERT_EQ_MSG(YES, [sortDesc ascending], "FAILED: ascending should be YES");
    ASSERT_TRUE_MSG([sortDesc selector] != nullptr, "FAILED: selector should be non-null!");
    ASSERT_EQ_MSG(nullptr, (void*)[sortDesc comparator], "FAILED: comparator should be null.");
    ASSERT_OBJCEQ_MSG(key, [sortDesc key], "FAILED: key does not match the supplied key.");
    NSArray* sortedValue = [data sortedArrayUsingDescriptors:@[ sortDesc ]];

    // verify sorted value
    ASSERT_OBJCEQ_MSG(firstObj, sortedValue[0], "FAILED: Failed to sort the data in correct order.");
    ASSERT_OBJCEQ_MSG(lastObj, sortedValue[[sortedValue count] - 1], "FAILED: Failed to sort the data in correct order.");
    ASSERT_EQ_MSG(9, [sortedValue[9] xCord], "Failed: Failed to sort the data.");
    [data release];
}

TEST(NSSortDescriptor, SortDescriptorWithCustomObjectAndSelector) {
    NSMutableArray* data = [[NSMutableArray alloc] init];
    NSString* key = @"xCord";
    int size = 20;

    TestPoint* firstObj = [[[TestPoint alloc] initWithName:@"obj1" xCord:0 yCord:10] autorelease];
    TestPoint* lastObj = [[[TestPoint alloc] initWithName:@"obj3" xCord:100 yCord:30] autorelease];
    [data addObject:firstObj];
    [data addObject:lastObj];

    for (int i = 1; i < size; ++i) {
        TestPoint* obj = [[[TestPoint alloc] initWithName:@"testObj" xCord:i yCord:(i + 1)] autorelease];
        [data addObject:obj];
    }

    NSSortDescriptor* sortDesc = [NSSortDescriptor sortDescriptorWithKey:key ascending:YES selector:@selector(compare:)];
    ASSERT_TRUE_MSG(sortDesc != nullptr, "FAILED: sortDesc should be non-null!");

    ASSERT_EQ_MSG(YES, [sortDesc ascending], "FAILED: ascending should be YES");
    ASSERT_TRUE_MSG([sortDesc selector] != nullptr, "FAILED: selector should be non-null!");
    ASSERT_EQ_MSG(nullptr, (void*)[sortDesc comparator], "FAILED: comparator should be null.");
    ASSERT_OBJCEQ_MSG(key, [sortDesc key], "FAILED: key does not match the supplied key.");
    NSArray* sortedValue = [data sortedArrayUsingDescriptors:@[ sortDesc ]];

    ASSERT_OBJCEQ_MSG(firstObj, sortedValue[0], "FAILED: Failed to sort the data in correct order.");
    ASSERT_OBJCEQ_MSG(lastObj, sortedValue[[sortedValue count] - 1], "FAILED: to sort the data in correct order.");
    ASSERT_EQ_MSG(15, [sortedValue[15] xCord], "Failed: Failed to sort the data.");
    [data release];
}

TEST(NSSortDescriptor, SortDescriptorWithCustomObjectAndComparator) {
    NSMutableArray* data = [[NSMutableArray alloc] init];
    int size = 40;
    NSString* key = @"xCord";

    TestPoint* firstObj = [[[TestPoint alloc] initWithName:@"obj1" xCord:0 yCord:10] autorelease];
    TestPoint* lastObj = [[[TestPoint alloc] initWithName:@"obj3" xCord:100 yCord:30] autorelease];
    [data addObject:firstObj];
    [data addObject:lastObj];

    for (int i = 1; i < size; ++i) {
        TestPoint* obj = [[[TestPoint alloc] initWithName:@"testObj" xCord:i yCord:(i + 1)] autorelease];
        [data addObject:obj];
    }

    id customComparator = ^(id obj1, id obj2) {

        if ([obj1 integerValue] > [obj2 integerValue]) {
            return (NSComparisonResult)NSOrderedDescending;
        }

        if ([obj1 integerValue] < [obj2 integerValue]) {
            return (NSComparisonResult)NSOrderedAscending;
        }
        return (NSComparisonResult)NSOrderedSame;
    };

    NSSortDescriptor* sortDesc = [NSSortDescriptor sortDescriptorWithKey:key ascending:YES comparator:customComparator];
    ASSERT_TRUE_MSG(sortDesc != nullptr, "FAILED: sortDesc should be non-null!");

    ASSERT_EQ_MSG(YES, [sortDesc ascending], "FAILED: ascending should be NO");
    ASSERT_TRUE_MSG([sortDesc comparator] != nullptr, "FAILED: comparator should be non-null!");
    ASSERT_OBJCEQ_MSG(key, [sortDesc key], "FAILED: key does not match the supplied key.");
    NSArray* sortedValue = [data sortedArrayUsingDescriptors:@[ sortDesc ]];

    ASSERT_OBJCEQ_MSG(firstObj, sortedValue[0], "FAILED: Failed to sort the data in correct order.");
    ASSERT_OBJCEQ_MSG(lastObj, sortedValue[[sortedValue count] - 1], "FAILED: to sort the data in correct order.");
    ASSERT_EQ_MSG(25, [sortedValue[25] xCord], "Failed: Failed to sort the data.");
    [data release];
}

TEST(NSSortDescriptor, copy) {
    NSString* key = @"FooBar";
    NSSortDescriptor* sortDesc = [NSSortDescriptor sortDescriptorWithKey:key ascending:YES];
    ASSERT_TRUE_MSG(sortDesc != nullptr, "FAILED: sortDesc should be non-null!");

    ASSERT_EQ_MSG(YES, [sortDesc ascending], "FAILED: ascending should be YES");
    ASSERT_TRUE_MSG([sortDesc selector] != nullptr, "FAILED: selector should be non-null!");
    ASSERT_EQ_MSG(nullptr, (void*)[sortDesc comparator], "FAILED: comparator should be null.");
    ASSERT_OBJCEQ_MSG(key, [sortDesc key], "FAILED: key does not match the supplied key.");

    NSSortDescriptor* sortCopy = [sortDesc copy];

    ASSERT_EQ_MSG([sortCopy comparator], [sortDesc comparator], "FAILED: comparators do not match.");
    ASSERT_OBJCEQ_MSG([sortCopy key], [sortDesc key], "FAILED: key do not match.");
    ASSERT_EQ_MSG([sortCopy ascending], [sortDesc ascending], "FAILED: ascending property do not match.");
    ASSERT_EQ_MSG([sortCopy selector], [sortDesc selector], "FAILED: selector property do not match.");

    [sortCopy release];
}

TEST(NSSortDescriptor, ReversedSortDescriptor) {
    NSString* key = @"FooBar";
    NSSortDescriptor* sortDesc = [NSSortDescriptor sortDescriptorWithKey:key ascending:YES];
    ASSERT_TRUE_MSG(sortDesc != nullptr, "FAILED: sortDesc should be non-null!");

    NSSortDescriptor* reverseSortDesc = [sortDesc reversedSortDescriptor];
    ASSERT_TRUE_MSG(reverseSortDesc != nullptr, "FAILED: reverseSortDesc should be non-null!");
    ASSERT_EQ_MSG(NO, [reverseSortDesc ascending], "FAILED: ascending should be NO");
    ASSERT_TRUE_MSG([reverseSortDesc selector] != nullptr, "FAILED: selector should be non-null!");
    ASSERT_EQ_MSG(nullptr, (void*)[reverseSortDesc comparator], "FAILED: comparator should be null.");
    ASSERT_OBJCEQ_MSG(key, [reverseSortDesc key], "FAILED: key does not match the supplied key.");
}

TEST(NSSortDescriptor, ArchiveAndUnarchiveObject) {
    NSString* key = @"FooBar";
    NSSortDescriptor* sortDesc = [NSSortDescriptor sortDescriptorWithKey:key ascending:YES];
    ASSERT_TRUE_MSG(sortDesc != nullptr, "FAILED: sortDesc should be non-null!");

    ASSERT_EQ_MSG(YES, [sortDesc ascending], "FAILED: ascending should be YES");
    ASSERT_TRUE_MSG([sortDesc selector] != nullptr, "FAILED: selector should be non-null!");
    ASSERT_EQ_MSG(nullptr, (void*)[sortDesc comparator], "FAILED: comparator should be null.");
    ASSERT_OBJCEQ_MSG(key, [sortDesc key], "FAILED: key does not match the supplied key.");

    // archive the object
    NSData* data = [NSKeyedArchiver archivedDataWithRootObject:sortDesc];
    ASSERT_TRUE_MSG(data != nullptr, "FAILED: archived data should be non-null!");

    // unarchive
    NSSortDescriptor* unArchivedSortDesc = [NSKeyedUnarchiver unarchiveObjectWithData:data];
    ASSERT_TRUE_MSG(unArchivedSortDesc != nullptr, "FAILED: unArchivedSortDesc should be non-null!");

    // validate if the unarchived content is same as orginal.
    ASSERT_EQ_MSG([unArchivedSortDesc comparator], [sortDesc comparator], "FAILED: comparators do not match.");
    ASSERT_OBJCEQ_MSG([unArchivedSortDesc key], [sortDesc key], "FAILED: key do not match.");
    ASSERT_EQ_MSG([unArchivedSortDesc ascending], [sortDesc ascending], "FAILED: ascending property do not match.");
    ASSERT_OBJCEQ_MSG(NSStringFromSelector([unArchivedSortDesc selector]),
                      NSStringFromSelector([sortDesc selector]),
                      "FAILED: selector property do not match.");
}
