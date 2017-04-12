//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

TEST(NSDictionary, KeysSortedByValueUsingComparator) {
    NSDictionary* testDict = @{ @"A" : @2, @"B" : @4, @"C" : @3, @"D" : @1 };
    NSArray* actualArray = [testDict keysSortedByValueUsingComparator:^(id obj1, id obj2) {
        return [obj1 compare:obj2];
    }];

    NSArray* expectedArray = @[ @"D", @"A", @"C", @"B" ];
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

TEST(NSDictionary, KeysSortedByValue) {
    NSDictionary* dictionary = @{ @"f" : @6, @"b" : @2, @"a" : @1, @"c" : @3, @"e" : @5, @"d" : @4 };
    NSArray* expected = @[ @"a", @"b", @"c", @"d", @"e", @"f" ];
    NSArray* actual = [dictionary keysSortedByValueUsingComparator:^NSComparisonResult(id obj1, id obj2) {
        int a = [obj1 intValue];
        int b = [obj2 intValue];
        if (a == b) {
            return NSOrderedSame;
        }

        return (a > b) ? NSOrderedDescending : NSOrderedAscending;
    }];

    ASSERT_OBJCEQ(expected, actual);
}

TEST(NSDictionary, KeysSortedByValueWithOptions) {
    NSDictionary* dictionary = @{ @"f" : @6, @"b" : @2, @"a" : @1, @"c" : @3, @"e" : @5, @"d" : @4 };
    NSArray* expected = @[ @"a", @"b", @"c", @"d", @"e", @"f" ];
    NSArray* actual = [dictionary keysSortedByValueWithOptions:0
                                               usingComparator:^NSComparisonResult(id obj1, id obj2) {
                                                   int a = [obj1 intValue];
                                                   int b = [obj2 intValue];
                                                   if (a == b) {
                                                       return NSOrderedSame;
                                                   }

                                                   return (a > b) ? NSOrderedDescending : NSOrderedAscending;
                                               }];

    ASSERT_OBJCEQ(expected, actual);
}

TEST(NSDictionary, KeysSortedByValueWithOptions_Stable) {
    NSDictionary* dictionary = @{ @"a" : @1, @"b" : @1, @"c" : @1, @"d" : @1, @"e" : @1, @"f" : @0 };
    NSArray* expected = @[
        @"f",
        @"d",
        @"b",
        @"e",
        @"c",
        @"a"
    ]; // Note: ordering after "f" is dependent on CFDictionary (this ordering matches the reference platform)
    NSArray* actual = [dictionary keysSortedByValueWithOptions:NSSortStable
                                               usingComparator:^NSComparisonResult(id obj1, id obj2) {
                                                   int a = [obj1 intValue];
                                                   int b = [obj2 intValue];
                                                   if (a == b) {
                                                       return NSOrderedSame;
                                                   }

                                                   return (a > b) ? NSOrderedDescending : NSOrderedAscending;
                                               }];

    ASSERT_OBJCEQ(expected, actual);
}

TEST(NSDictionary, MutableInstanceArchivesAsMutable) {
    NSMutableDictionary* input = [NSMutableDictionary dictionaryWithObject:@"world" forKey:@"hello"];

    NSData* data = [NSKeyedArchiver archivedDataWithRootObject:input];
    ASSERT_OBJCNE(nil, data);

    NSMutableDictionary* output = [NSKeyedUnarchiver unarchiveObjectWithData:data];
    ASSERT_OBJCNE(nil, output);

    EXPECT_NO_THROW([output setObject:@"morld" forKey:@"yello"]);

    EXPECT_OBJCNE(input, output);
}

TEST(NSMutableDictionary, InsertingNilForKeyedSubscriptShouldRemoveValue) {
    NSMutableDictionary* dict = [NSMutableDictionary dictionaryWithObject:@"world" forKey:@"hello"];
    [dict setObject:nil forKeyedSubscript:@"hello"];
    EXPECT_EQ(nil, dict[@"hello"]);
    EXPECT_EQ(0, [dict count]);
}

TEST(NSMutableDictionary, InsertingNilWithSubscriptingShouldRemoveValue) {
    NSMutableDictionary* dict = [NSMutableDictionary dictionaryWithObject:@"world" forKey:@"hello"];
    dict[@"hello"] = nil;
    EXPECT_EQ(nil, dict[@"hello"]);
    EXPECT_EQ(0, [dict count]);
}

TEST(NSMutableDictionary, SetObjectWithNilShouldThrow) {
    NSMutableDictionary* dict = [NSMutableDictionary dictionaryWithObject:@"world" forKey:@"hello"];
    EXPECT_ANY_THROW([dict setObject:nil forKey:@"fail"]);
    EXPECT_OBJCEQ(@"world", dict[@"hello"]);
}

TEST(NSDictionary, NSFileManagerExtensions) {
    NSDate* now = [NSDate date];
    NSDictionary* fileAttributes = @{
        NSFileAppendOnly : @YES,
        NSFileBusy : @YES,
        NSFileCreationDate : now,
        NSFileOwnerAccountName : @"Name",
        NSFileGroupOwnerAccountName : @"GroupName",
        NSFileDeviceIdentifier : @1,
        NSFileExtensionHidden : @YES,
        NSFileGroupOwnerAccountID : @12,
        NSFileHFSCreatorCode : @123,
        NSFileHFSTypeCode : @1234,
        NSFileImmutable : @YES,
        NSFileModificationDate : now,
        NSFileOwnerAccountID : @12345,
        NSFilePosixPermissions : @123456,
        NSFileReferenceCount : @2,
        NSFileSize : @23,
        NSFileSystemFileNumber : @234,
        NSFileType : @"filetype"
    };
    EXPECT_OBJCEQ(now, fileAttributes.fileCreationDate);
    EXPECT_EQ(YES, fileAttributes.fileExtensionHidden);
    EXPECT_OBJCEQ(@12, fileAttributes.fileGroupOwnerAccountID);
    EXPECT_OBJCEQ(@"GroupName", fileAttributes.fileGroupOwnerAccountName);
    EXPECT_EQ(123, fileAttributes.fileHFSCreatorCode);
    EXPECT_EQ(1234, fileAttributes.fileHFSTypeCode);
    EXPECT_EQ(YES, fileAttributes.fileIsAppendOnly);
    EXPECT_EQ(YES, fileAttributes.fileIsImmutable);
    EXPECT_OBJCEQ(now, fileAttributes.fileModificationDate);
    EXPECT_OBJCEQ(@12345, fileAttributes.fileOwnerAccountID);
    EXPECT_OBJCEQ(@"Name", fileAttributes.fileOwnerAccountName);
    EXPECT_EQ(123456, fileAttributes.filePosixPermissions);
    EXPECT_EQ(23, fileAttributes.fileSize);
    EXPECT_EQ(234, fileAttributes.fileSystemFileNumber);
    EXPECT_EQ(0, fileAttributes.fileSystemNumber);
    EXPECT_OBJCEQ(@"filetype", fileAttributes.fileType);
}
