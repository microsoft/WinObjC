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

#include <windows.h>
#include <TestFramework.h>
#import <Foundation/Foundation.h>

@interface TestCreationSignallingClass : NSObject <NSSecureCoding>
+ (void)resetCreationCount;
@end

static long creationCount;
@implementation TestCreationSignallingClass
+ (BOOL)supportsSecureCoding {
    return YES;
}

+ (id)allocWithZone:(NSZone*)zone {
    InterlockedIncrement(&creationCount);
    return [super allocWithZone:zone];
}

+ (void)resetCreationCount {
    InterlockedExchange(&creationCount, 0);
}

+ (long)creationCount {
    return creationCount;
}

- (void)encodeWithCoder:(NSCoder*)coder {
    // does nothing
}

- (id)initWithCoder:(NSCoder*)coder {
    // also does nothing
    return [self init];
}
@end

@interface InsecureObject : NSObject <NSCoding>
@end
@implementation InsecureObject
- (void)encodeWithCoder:(NSCoder*)coder {
    // does nothing
}
- (id)initWithCoder:(NSCoder*)coder {
    // also does nothing
    return [self init];
}
@end

static NSData* createTestArchive() {
    NSMutableData* data = [[[NSMutableData alloc] init] autorelease];
    NSKeyedArchiver* archiver = [[NSKeyedArchiver alloc] initForWritingWithMutableData:data];

    [archiver encodeInt64:84LL forKey:@"int64"];
    [archiver encodeObject:@"Hello" forKey:@"string"];
    [archiver encodeObject:@(40) forKey:@"number"];
    [archiver encodeObject:@{ @"a" : @"b" } forKey:@"dictionary"];
    [archiver encodeObject:@[ @"a" ] forKey:@"array"];
    [archiver encodeObject:[NSDate dateWithTimeIntervalSince1970:20.0] forKey:@"date"];

    [archiver encodeObject:[[TestCreationSignallingClass alloc] init] forKey:@"creationSignalling"];
    [archiver encodeObject:@[
        [[TestCreationSignallingClass alloc] init],
        [[TestCreationSignallingClass alloc] init],
        [[TestCreationSignallingClass alloc] init]
    ]
                    forKey:@"arrayOfSecureTypes"];
    [archiver encodeObject:[[InsecureObject alloc] init] forKey:@"insecureObject"];

    unsigned rawValue = 0xDEADBEEF;
    [archiver encodeObject:[NSData dataWithBytes:&rawValue length:sizeof(unsigned)] forKey:@"data"];

    [archiver finishEncoding];
    [archiver release];
    return data;
}

TEST(Archival, NSKeyedUnarchiver) {
    NSData* archive = createTestArchive();
    [TestCreationSignallingClass resetCreationCount];

    EXPECT_EQ(TestCreationSignallingClass.creationCount, 0);

    NSKeyedUnarchiver* insecureUnarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:archive];

    EXPECT_EQ([insecureUnarchiver decodeInt64ForKey:@"int64"], 84LL);
    EXPECT_OBJCEQ([insecureUnarchiver decodeObjectForKey:@"string"], @"Hello");
    EXPECT_OBJCEQ([insecureUnarchiver decodeObjectForKey:@"number"], @40);
    EXPECT_ANY_THROW([insecureUnarchiver decodeIntForKey:@"number"]);
    EXPECT_OBJCEQ([insecureUnarchiver decodeObjectForKey:@"dictionary"], @{ @"a" : @"b" });
    EXPECT_OBJCEQ([insecureUnarchiver decodeObjectForKey:@"array"], @[ @"a" ]);
    EXPECT_OBJCEQ([insecureUnarchiver decodeObjectForKey:@"date"], [NSDate dateWithTimeIntervalSince1970:20.0]);

    EXPECT_EQ_MSG([TestCreationSignallingClass class],
                  [[insecureUnarchiver decodeObjectOfClass:[NSString class] forKey:@"creationSignalling"] class],
                  "defying expectations, if you request an invalid class on a non-secure coder, it returns the actual object anyway.");
    EXPECT_EQ(TestCreationSignallingClass.creationCount, 1);

    EXPECT_OBJCNE(nil, [insecureUnarchiver decodeObjectForKey:@"creationSignalling"]);
    EXPECT_EQ_MSG(TestCreationSignallingClass.creationCount, 1, "A key should only result in the creation of a single object.");

    NSData* data = [insecureUnarchiver decodeObjectForKey:@"data"];
    EXPECT_OBJCNE(nil, data);
    EXPECT_EQ(sizeof(unsigned), [data length]);
    unsigned rawValue = 0;
    [data getBytes:&rawValue length:sizeof(unsigned)];
    EXPECT_EQ(0xDEADBEEF, rawValue);

    [insecureUnarchiver finishDecoding];
    [insecureUnarchiver release];
}

// The following test is disabled because OS X violates the contract set out in
// https://developer.apple.com/library/mac/documentation/Cocoa/Reference/Foundation/Classes/NSKeyedUnarchiver_Class/#//apple_ref/occ/instm/NSKeyedUnarchiver/setRequiresSecureCoding:
// > Once enabled, attempting to call setRequiresSecureCoding: with a value of NO will throw an exception.
//   This is to prevent classes from selectively turning secure coding off.
OSX_DISABLED_TEST(NSKeyedUnarchiverSecure,
                  SecureCodingCannotBeTurnedOff) { // it should be impossible to turn secure coding off once it's on.
    NSData* archive = createTestArchive();
    [TestCreationSignallingClass resetCreationCount];
    NSKeyedUnarchiver* secureUnarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:archive];
    secureUnarchiver.requiresSecureCoding = YES;
    EXPECT_ANY_THROW_MSG(secureUnarchiver.requiresSecureCoding = NO, "It should be impossible to turn off secure coding.");
    [secureUnarchiver finishDecoding];
    [secureUnarchiver release];
}

TEST(NSKeyedUnarchiverSecure,
     RequestIncorrectClass) { // requesting an object with the wrong class should not result in the creation of the original object
    NSData* archive = createTestArchive();
    [TestCreationSignallingClass resetCreationCount];
    NSKeyedUnarchiver* secureUnarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:archive];
    secureUnarchiver.requiresSecureCoding = YES;
    EXPECT_ANY_THROW([secureUnarchiver decodeObjectOfClass:[InsecureObject class] forKey:@"creationSignalling"]);
    EXPECT_EQ(0, [TestCreationSignallingClass creationCount]);
    [secureUnarchiver finishDecoding];
    [secureUnarchiver release];
}

TEST(NSKeyedUnarchiverSecure, PODTypesDoNotRequireCheck) { // POD types should be passed through unharmed
    NSData* archive = createTestArchive();
    [TestCreationSignallingClass resetCreationCount];
    NSKeyedUnarchiver* secureUnarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:archive];
    secureUnarchiver.requiresSecureCoding = YES;
    EXPECT_EQ([secureUnarchiver decodeInt64ForKey:@"int64"], 84LL);
    [secureUnarchiver finishDecoding];
    [secureUnarchiver release];
}

TEST(NSKeyedUnarchiverSecure, NSStringDoesNotRequireCheck) { // NSString should be passed through without a class check
    NSData* archive = createTestArchive();
    [TestCreationSignallingClass resetCreationCount];
    NSKeyedUnarchiver* secureUnarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:archive];
    secureUnarchiver.requiresSecureCoding = YES;
    id stringVal = nil;
    EXPECT_NO_THROW(stringVal = [secureUnarchiver decodeObjectForKey:@"string"]);
    EXPECT_OBJCEQ(stringVal, @"Hello");
    [secureUnarchiver finishDecoding];
    [secureUnarchiver release];
}

TEST(NSKeyedUnarchiverSecure, NSNumberDoesNotRequireCheck) { // NSNumber should be passed through without a class check
    NSData* archive = createTestArchive();
    [TestCreationSignallingClass resetCreationCount];
    NSKeyedUnarchiver* secureUnarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:archive];
    secureUnarchiver.requiresSecureCoding = YES;
    EXPECT_OBJCEQ([secureUnarchiver decodeObjectForKey:@"number"], @40);
    [secureUnarchiver finishDecoding];
    [secureUnarchiver release];
}

TEST(NSKeyedUnarchiverSecure, NSDataRequiresCheck) { // NSData requires a class check
    NSData* archive = createTestArchive();
    [TestCreationSignallingClass resetCreationCount];
    NSKeyedUnarchiver* secureUnarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:archive];
    secureUnarchiver.requiresSecureCoding = YES;
    NSData* data = nil;
    EXPECT_NO_THROW(data = [secureUnarchiver decodeObjectOfClass:[NSData class] forKey:@"data"]);
    EXPECT_OBJCNE(nil, data);
    EXPECT_EQ(sizeof(unsigned), [data length]);
    unsigned rawValue = 0;
    [data getBytes:&rawValue length:sizeof(unsigned)];
    EXPECT_EQ(0xDEADBEEF, rawValue);
    [secureUnarchiver finishDecoding];
    [secureUnarchiver release];
}

TEST(NSKeyedUnarchiverSecure, RequestDictionaryAsArray) { // A dictionary should not be requestable as an array
    NSData* archive = createTestArchive();
    [TestCreationSignallingClass resetCreationCount];
    NSKeyedUnarchiver* secureUnarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:archive];
    secureUnarchiver.requiresSecureCoding = YES;
    EXPECT_ANY_THROW([secureUnarchiver decodeObjectOfClass:[NSArray class] forKey:@"dictionary"]);
    [secureUnarchiver finishDecoding];
    [secureUnarchiver release];
}

TEST(NSKeyedUnarchiverSecure, NoClassesSpecified) { // requesting no classes is tantamount to requesting exceptions constantly
    NSData* archive = createTestArchive();
    [TestCreationSignallingClass resetCreationCount];
    NSKeyedUnarchiver* secureUnarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:archive];
    secureUnarchiver.requiresSecureCoding = YES;
    EXPECT_ANY_THROW([secureUnarchiver decodeObjectForKey:@"dictionary"]);
    [secureUnarchiver finishDecoding];
    [secureUnarchiver release];
}

TEST(NSKeyedUnarchiverSecure, NSArrayWithBasicEnclosedType) { // NSArray containing NSNumber should pass through
    NSData* archive = createTestArchive();
    [TestCreationSignallingClass resetCreationCount];
    NSKeyedUnarchiver* secureUnarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:archive];
    secureUnarchiver.requiresSecureCoding = YES;
    EXPECT_NO_THROW([secureUnarchiver decodeObjectOfClass:[NSArray class] forKey:@"array"]);
    [secureUnarchiver finishDecoding];
    [secureUnarchiver release];
}

TEST(NSKeyedUnarchiverSecure,
     CustomClass) { // TestCreationSignallingClass (NSKeyedUnarchiverSecure) should pass through and create one instance
    NSData* archive = createTestArchive();
    [TestCreationSignallingClass resetCreationCount];
    NSKeyedUnarchiver* secureUnarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:archive];
    secureUnarchiver.requiresSecureCoding = YES;
    EXPECT_NO_THROW([secureUnarchiver decodeObjectOfClass:[TestCreationSignallingClass class] forKey:@"creationSignalling"]);
    EXPECT_EQ(1, [TestCreationSignallingClass creationCount]);
    [secureUnarchiver finishDecoding];
    [secureUnarchiver release];
}

TEST(NSKeyedUnarchiverSecure, ObjectThatDoesNotConform) { // An object that does not conform to NSKeyedUnarchiverSecure cannot be decoded
    NSData* archive = createTestArchive();
    [TestCreationSignallingClass resetCreationCount];
    NSKeyedUnarchiver* secureUnarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:archive];
    secureUnarchiver.requiresSecureCoding = YES;
    EXPECT_ANY_THROW([secureUnarchiver decodeObjectOfClass:[InsecureObject class] forKey:@"insecureObject"]);
    [secureUnarchiver finishDecoding];
    [secureUnarchiver release];
}

TEST(NSKeyedUnarchiverSecure, NSArrayWithCustomEnclosedType1) { // Arrays must be decoded by specifying their enclosing AND enclosed types
    NSData* archive = createTestArchive();
    [TestCreationSignallingClass resetCreationCount];
    NSKeyedUnarchiver* secureUnarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:archive];
    secureUnarchiver.requiresSecureCoding = YES;
    EXPECT_ANY_THROW([secureUnarchiver decodeObjectOfClass:[TestCreationSignallingClass class] forKey:@"arrayOfSecureTypes"]);
    [secureUnarchiver finishDecoding];
    [secureUnarchiver release];
}

TEST(NSKeyedUnarchiverSecure,
     NSArrayWithoutEnclosedTypeSpecified) { // Arrays must be decoded by specifying their enclosing AND enclosed types
    NSData* archive = createTestArchive();
    [TestCreationSignallingClass resetCreationCount];
    NSKeyedUnarchiver* secureUnarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:archive];
    secureUnarchiver.requiresSecureCoding = YES;
    EXPECT_ANY_THROW([secureUnarchiver decodeObjectOfClass:[NSArray class] forKey:@"arrayOfSecureTypes"]);
    [secureUnarchiver finishDecoding];
    [secureUnarchiver release];
}

TEST(NSKeyedUnarchiverSecure, NSArrayWithCustomEnclosedType2) { // Arrays must be decoded by specifying their enclosing AND enclosed types
    NSData* archive = createTestArchive();
    [TestCreationSignallingClass resetCreationCount];
    NSKeyedUnarchiver* secureUnarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:archive];
    secureUnarchiver.requiresSecureCoding = YES;
    NSSet* allowedClasses = [NSSet setWithObjects:[TestCreationSignallingClass class], [NSArray class], nil];
    EXPECT_NO_THROW([secureUnarchiver decodeObjectOfClasses:allowedClasses forKey:@"arrayOfSecureTypes"]);
    [secureUnarchiver finishDecoding];
    [secureUnarchiver release];
}

// This is testing an implementation detail, but one that was true on OS X 10.10.
// It fails on 10.11.
OSX_DISABLED_TEST(NSKeyedUnarchiverSecure,
                  BadDecodeLeavesUnarchiverInBadState) { // Once a bad decode has occurred, all requests must return nil
    NSData* archive = createTestArchive();
    [TestCreationSignallingClass resetCreationCount];
    NSKeyedUnarchiver* secureUnarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:archive];
    secureUnarchiver.requiresSecureCoding = YES;
    EXPECT_ANY_THROW([secureUnarchiver decodeObjectOfClass:[InsecureObject class] forKey:@"insecureObject"]);
    EXPECT_OBJCEQ(nil, [secureUnarchiver decodeObjectOfClass:[NSDictionary class] forKey:@"dictionary"]);
    EXPECT_OBJCEQ(nil, [secureUnarchiver decodeObjectOfClass:[NSArray class] forKey:@"array"]);
    EXPECT_OBJCEQ(nil, [secureUnarchiver decodeObjectOfClass:[NSNumber class] forKey:@"number"]);
    [secureUnarchiver finishDecoding];
    [secureUnarchiver release];
}

@interface NSKAInstanceOriginalClass : NSObject <NSCoding>
@end
@implementation NSKAInstanceOriginalClass
- (id)initWithCoder:(NSCoder*)coder {
    return self;
}

- (void)encodeWithCoder:(NSCoder*)coder {
    // does nothing
}
@end

@interface NSKADifferentClass : NSObject <NSCoding>
@end
@implementation NSKADifferentClass
- (id)initWithCoder:(NSCoder*)coder {
    return self;
}

- (void)encodeWithCoder:(NSCoder*)coder {
    // does nothing
}
@end

@interface NSKAClassOriginalClass : NSObject <NSCoding>
@end
@implementation NSKAClassOriginalClass
- (id)initWithCoder:(NSCoder*)coder {
    return self;
}

- (void)encodeWithCoder:(NSCoder*)coder {
    // does nothing
}
@end

TEST(Archival, NSKeyedArchiver_Instance_ClassName) {
    // Instance-specific classname override test.
    // NSKAInstanceOriginalClass will become NSKADifferentClass on write.
    NSMutableData* data = [[[NSMutableData alloc] init] autorelease];
    NSKeyedArchiver* archiver = [[NSKeyedArchiver alloc] initForWritingWithMutableData:data];

    [archiver setClassName:@"NSKADifferentClass" forClass:[NSKAInstanceOriginalClass class]];
    EXPECT_OBJCEQ(@"NSKADifferentClass", [archiver classNameForClass:[NSKAInstanceOriginalClass class]]);
    EXPECT_OBJCEQ(nil, [NSKeyedArchiver classNameForClass:[NSKAInstanceOriginalClass class]]);

    [archiver encodeObject:[[[NSKAInstanceOriginalClass alloc] init] autorelease] forKey:@"unexpected"];

    [archiver finishEncoding];
    [archiver release];

    NSKeyedUnarchiver* unarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:data];
    id object = [unarchiver decodeObjectForKey:@"unexpected"];
    EXPECT_TRUE([object isKindOfClass:[NSKADifferentClass class]]);
    [unarchiver finishDecoding];
    [unarchiver release];
}

TEST(Archival, NSKeyedArchiver_Static_ClassName) {
    // Global classname override test.
    // NSKAClassOriginalClass will become NSKADifferentClass on write.
    [NSKeyedArchiver setClassName:@"NSKADifferentClass" forClass:[NSKAClassOriginalClass class]];
    EXPECT_OBJCEQ(@"NSKADifferentClass", [NSKeyedArchiver classNameForClass:[NSKAClassOriginalClass class]]);

    NSMutableData* data = [[[NSMutableData alloc] init] autorelease];
    NSKeyedArchiver* archiver = [[NSKeyedArchiver alloc] initForWritingWithMutableData:data];

    EXPECT_OBJCEQ_MSG(nil,
                      [archiver classNameForClass:[NSKAClassOriginalClass class]],
                      "NSKeyedArchiver instances should not inherit the global class list.");

    [archiver encodeObject:[[[NSKAClassOriginalClass alloc] init] autorelease] forKey:@"unexpected"];

    [archiver finishEncoding];
    [archiver release];

    NSKeyedUnarchiver* unarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:data];
    id object = [unarchiver decodeObjectForKey:@"unexpected"];
    EXPECT_TRUE([object isKindOfClass:[NSKADifferentClass class]]);
    [unarchiver finishDecoding];
    [unarchiver release];

    [NSKeyedArchiver setClassName:nil forClass:[NSKAClassOriginalClass class]];
}

TEST(Archival, NSKeyedArchiver_Static_ClassName_Inheritance) {
    // Instance specific classname override should override global one.
    // NSKAClassOriginalClass will become NSKADifferentClass on write.
    [NSKeyedArchiver setClassName:@"NSKADifferentClass" forClass:[NSKAClassOriginalClass class]];

    NSMutableData* data = [[[NSMutableData alloc] init] autorelease];
    NSKeyedArchiver* archiver = [[NSKeyedArchiver alloc] initForWritingWithMutableData:data];

    // [OVERRIDE] NSKAClassOriginalClass will become NSKAInstanceOriginalClass on write.
    [archiver setClassName:@"NSKAInstanceOriginalClass" forClass:[NSKAClassOriginalClass class]];

    [archiver encodeObject:[[[NSKAClassOriginalClass alloc] init] autorelease] forKey:@"unexpected"];

    [archiver finishEncoding];
    [archiver release];

    NSKeyedUnarchiver* unarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:data];
    id object = [unarchiver decodeObjectForKey:@"unexpected"];
    EXPECT_TRUE([object isKindOfClass:[NSKAInstanceOriginalClass class]]);
    [unarchiver finishDecoding];
    [unarchiver release];
}