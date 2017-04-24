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

#import <TestFramework.h>
#import "TestUtils.h"
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

TEST(NSDictionary, ReadWriteURL) {
    NSString* filePath = @"dictionaryTestData.txt";
    SCOPE_DELETE_FILE(filePath);
    NSURL* url = [NSURL fileURLWithPath:filePath isDirectory:NO];
    NSDictionary* dict = @{ @"key1" : @1, @"k2" : @"val", @"z" : @[ @5 ] };
    EXPECT_TRUE([dict writeToURL:url atomically:NO]);
    NSDictionary* read = [NSDictionary dictionaryWithContentsOfURL:url];
    EXPECT_OBJCEQ(dict, read);
}

TEST(NSDictionary, Description) {
    NSDictionary* empty = @{};
    EXPECT_OBJCEQ(@"{\n}", [empty description]);

    NSDictionary* dict = @{ @"A" : @[ @1, @{ @"Key" : @9 } ], @"Z" : @"Value", @"G" : @"ZValue" };
    NSString* expected = @"{\n"
                          "    A =     (\n"
                          "        1,\n"
                          "                {\n"
                          "            Key = 9;\n"
                          "        }\n"
                          "    );\n"
                          "    G = ZValue;\n"
                          "    Z = Value;\n"
                          "}";
    EXPECT_OBJCEQ(expected, [dict description]);
}

@interface NSDictionaryDescriptionTest : NSObject
+ (NSDictionaryDescriptionTest*)test;
- (NSString*)descriptionWithLocale:(id)locale indent:(NSUInteger)level;
- (NSString*)fakeDescriptionWithLocale:(id)locale indent:(NSUInteger)level;
- (NSString*)descriptionWithLocale:(id)locale;
- (NSString*)fakeDescriptionWithLocale:(id)locale;
- (NSString*)description;
@end

@implementation NSDictionaryDescriptionTest
+ (NSDictionaryDescriptionTest*)test {
    return [[NSDictionaryDescriptionTest new] autorelease];
}

- (NSString*)descriptionWithLocale:(id)locale indent:(NSUInteger)level {
    if (locale) {
        if (level > 1) {
            return @"Both";
        }

        return @"JustLocale";
    } else {
        if (level > 1) {
            return @"JustLevel";
        }

        return @"Neither";
    }
}
- (NSString*)fakeDescriptionWithLocale:(id)locale indent:(NSUInteger)level {
    return nil;
}

- (NSString*)descriptionWithLocale:(id)locale {
    if (locale) {
        return @"Locale";
    }

    return @"NoLocale";
}

- (NSString*)fakeDescriptionWithLocale:(id)locale {
    return nil;
}

- (NSString*)description {
    return @"Description";
}
@end

// Unfortunately despite what documentation suggests [NSDictionary descriptionWithLocale:] and [NSDictionary descriptionWithLocale:indent:]
// do not actually call descriptionWithLocale:indent: and descriptionWithLocale: when available (and does not follow the ordering
// specified to check for availability) so we are opting to implement this correctly and not test on the reference platform
OSX_DISABLED_TEST(NSDictionary, DescriptionWithLocale) {
    NSDictionary* testDictionary = @{ @"HI" : [NSDictionaryDescriptionTest test] };

    // Should default to descriptionWithLocale:indent:
    EXPECT_OBJCEQ(@"{\n    HI = JustLocale;\n}", [testDictionary descriptionWithLocale:[NSLocale currentLocale]]);
    EXPECT_OBJCEQ(@"{\n    HI = Neither;\n}", [testDictionary descriptionWithLocale:nil]);

    Method originalDescWithLocaleIndent =
        class_getInstanceMethod([NSDictionaryDescriptionTest class], @selector(descriptionWithLocale:indent:));
    Method fakeDescWithLocaleIndent =
        class_getInstanceMethod([NSDictionaryDescriptionTest class], @selector(fakeDescriptionWithLocale:indent:));
    method_exchangeImplementations(originalDescWithLocaleIndent, fakeDescWithLocaleIndent);

    // Should that fail then to descriptionWithLocale:
    EXPECT_OBJCEQ(@"{\n    HI = Locale;\n}", [testDictionary descriptionWithLocale:[NSLocale currentLocale]]);
    EXPECT_OBJCEQ(@"{\n    HI = NoLocale;\n}", [testDictionary descriptionWithLocale:nil]);

    Method originalDescWithLocale = class_getInstanceMethod([NSDictionaryDescriptionTest class], @selector(descriptionWithLocale:));
    Method fakeDescWithLocale = class_getInstanceMethod([NSDictionaryDescriptionTest class], @selector(fakeDescriptionWithLocale:));
    method_exchangeImplementations(originalDescWithLocale, fakeDescWithLocale);

    // Should that fail then to description
    EXPECT_OBJCEQ(@"{\n    HI = Description;\n}", [testDictionary descriptionWithLocale:[NSLocale currentLocale]]);
    EXPECT_OBJCEQ(@"{\n    HI = Description;\n}", [testDictionary descriptionWithLocale:nil]);

    method_exchangeImplementations(originalDescWithLocaleIndent, fakeDescWithLocaleIndent);
    method_exchangeImplementations(originalDescWithLocale, fakeDescWithLocale);
}

OSX_DISABLED_TEST(NSDictionary, DescriptionWithLocaleIndent) {
    NSDictionary* testDictionary = @{ @"HI" : [NSDictionaryDescriptionTest test] };

    // Should default to descriptionWithLocale:indent:
    EXPECT_OBJCEQ(@"    {\n        HI = Both;\n    }", [testDictionary descriptionWithLocale:[NSLocale currentLocale] indent:1]);
    EXPECT_OBJCEQ(@"{\n    HI = JustLocale;\n}", [testDictionary descriptionWithLocale:[NSLocale currentLocale] indent:0]);
    EXPECT_OBJCEQ(@"    {\n        HI = JustLevel;\n    }", [testDictionary descriptionWithLocale:nil indent:1]);
    EXPECT_OBJCEQ(@"{\n    HI = Neither;\n}", [testDictionary descriptionWithLocale:nil indent:0]);

    Method originalDescWithLocaleIndent =
        class_getInstanceMethod([NSDictionaryDescriptionTest class], @selector(descriptionWithLocale:indent:));
    Method fakeDescWithLocaleIndent =
        class_getInstanceMethod([NSDictionaryDescriptionTest class], @selector(fakeDescriptionWithLocale:indent:));
    method_exchangeImplementations(originalDescWithLocaleIndent, fakeDescWithLocaleIndent);

    // Should that fail then to descriptionWithLocale:
    EXPECT_OBJCEQ(@"{\n    HI = Locale;\n}", [testDictionary descriptionWithLocale:[NSLocale currentLocale] indent:0]);
    EXPECT_OBJCEQ(@"    {\n        HI = Locale;\n    }", [testDictionary descriptionWithLocale:[NSLocale currentLocale] indent:1]);
    EXPECT_OBJCEQ(@"{\n    HI = NoLocale;\n}", [testDictionary descriptionWithLocale:nil indent:0]);
    EXPECT_OBJCEQ(@"    {\n        HI = NoLocale;\n    }", [testDictionary descriptionWithLocale:nil indent:1]);

    Method originalDescWithLocale = class_getInstanceMethod([NSDictionaryDescriptionTest class], @selector(descriptionWithLocale:));
    Method fakeDescWithLocale = class_getInstanceMethod([NSDictionaryDescriptionTest class], @selector(fakeDescriptionWithLocale:));
    method_exchangeImplementations(originalDescWithLocale, fakeDescWithLocale);

    // Should that fail then to description
    EXPECT_OBJCEQ(@"{\n    HI = Description;\n}", [testDictionary descriptionWithLocale:[NSLocale currentLocale] indent:0]);
    EXPECT_OBJCEQ(@"    {\n        HI = Description;\n    }", [testDictionary descriptionWithLocale:[NSLocale currentLocale] indent:1]);
    EXPECT_OBJCEQ(@"{\n    HI = Description;\n}", [testDictionary descriptionWithLocale:nil indent:0]);
    EXPECT_OBJCEQ(@"    {\n        HI = Description;\n    }", [testDictionary descriptionWithLocale:nil indent:1]);

    method_exchangeImplementations(originalDescWithLocaleIndent, fakeDescWithLocaleIndent);
    method_exchangeImplementations(originalDescWithLocale, fakeDescWithLocale);
}

TEST(NSDictionary, KeysOfEntriesPassingTest) {
    NSDictionary* dict = @{ @"one" : @1, @"two" : @2, @"three" : @3, @"four" : @4, @"five" : @5 };

    NSSet* expected = [NSSet setWithObjects:@"one", @"three", @"five", nil];
    NSSet* actual = [dict keysOfEntriesPassingTest:^BOOL(id key, id obj, BOOL* stop) {
        return ([obj integerValue] % 2) == 1 ? YES : NO;
    }];

    EXPECT_OBJCEQ(expected, actual);
}

TEST(NSDictionary, KeysOfEntriesWithOptionsPassingTest) {
    NSDictionary* dict = @{ @"one" : @1, @"two" : @2, @"three" : @3, @"four" : @4, @"five" : @5 };

    NSSet* expected = [NSSet setWithObjects:@"one", @"three", @"five", nil];
    NSSet* actual = [dict keysOfEntriesWithOptions:NSEnumerationConcurrent
                                       passingTest:^BOOL(id key, id obj, BOOL* stop) {
                                           return ([obj integerValue] % 2) == 1 ? YES : NO;
                                       }];

    EXPECT_OBJCEQ(expected, actual);
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

    // Note: filePosixPermissions returns the stored value & 01777 so values are valid permissions
    EXPECT_EQ(576, fileAttributes.filePosixPermissions);
    EXPECT_EQ(23, fileAttributes.fileSize);
    EXPECT_EQ(234, fileAttributes.fileSystemFileNumber);
    EXPECT_EQ(0, fileAttributes.fileSystemNumber);
    EXPECT_OBJCEQ(@"filetype", fileAttributes.fileType);
}
