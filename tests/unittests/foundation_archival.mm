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

#include <Windows.h>
#include <TestFramework.h>
#import <Foundation/Foundation.h>

@interface NSKeyedArchiver (Internal)
- (void)encodeCGPoint:(CGPoint)p forKey:(NSString*)k;
@end
@interface NSKeyedUnarchiver (Internal)
- (CGPoint)decodeCGPointForKey:(NSString*)k;
@end

@interface TestCreationSignallingClass : NSObject <NSSecureCoding>
+ (void)resetCreationCount;
@end

static unsigned long creationCount;
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

+ (unsigned long)creationCount {
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

TEST(Foundation, NSKeyedUnarchiver) {
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

TEST(Foundation, NSKeyedUnarchiver_Secure) {
    NSData* archive = createTestArchive();
    [TestCreationSignallingClass resetCreationCount];

    EXPECT_EQ([TestCreationSignallingClass creationCount], 0);

    { // it should be impossible to turn secure coding off once it's on.
        NSKeyedUnarchiver* secureUnarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:archive];
        secureUnarchiver.requiresSecureCoding = YES;
        EXPECT_ANY_THROW_MSG(secureUnarchiver.requiresSecureCoding = NO, "It should be impossible to turn off secure coding.");
        [secureUnarchiver finishDecoding];
        [secureUnarchiver release];
    }

    { // requesting an object with the wrong class should not result in the creation of the original object
        NSKeyedUnarchiver* secureUnarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:archive];
        secureUnarchiver.requiresSecureCoding = YES;
        EXPECT_ANY_THROW([secureUnarchiver decodeObjectOfClass:[InsecureObject class] forKey:@"creationSignalling"]);
        EXPECT_EQ(0, [TestCreationSignallingClass creationCount]);
        [secureUnarchiver finishDecoding];
        [secureUnarchiver release];
    }

    { // POD types should be passed through unharmed
        NSKeyedUnarchiver* secureUnarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:archive];
        secureUnarchiver.requiresSecureCoding = YES;
        EXPECT_EQ([secureUnarchiver decodeInt64ForKey:@"int64"], 84LL);
        [secureUnarchiver finishDecoding];
        [secureUnarchiver release];
    }

    { // NSString should be passed through without a class check
        NSKeyedUnarchiver* secureUnarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:archive];
        secureUnarchiver.requiresSecureCoding = YES;
        id stringVal = nil;
        EXPECT_NO_THROW(stringVal = [secureUnarchiver decodeObjectForKey:@"string"]);
        EXPECT_OBJCEQ(stringVal, @"Hello");
        [secureUnarchiver finishDecoding];
        [secureUnarchiver release];
    }

    { // NSNumber should be passed through without a class check
        NSKeyedUnarchiver* secureUnarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:archive];
        secureUnarchiver.requiresSecureCoding = YES;
        EXPECT_OBJCEQ([secureUnarchiver decodeObjectForKey:@"number"], @40);
        [secureUnarchiver finishDecoding];
        [secureUnarchiver release];
    }

    { // NSData requires a class check
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

    { // A dictionary should not be requestable as an array
        NSKeyedUnarchiver* secureUnarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:archive];
        secureUnarchiver.requiresSecureCoding = YES;
        EXPECT_ANY_THROW([secureUnarchiver decodeObjectOfClass:[NSArray class] forKey:@"dictionary"]);
        [secureUnarchiver finishDecoding];
        [secureUnarchiver release];
    }

    { // requesting no classes is tantamount to requesting exceptions constantly
        NSKeyedUnarchiver* secureUnarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:archive];
        secureUnarchiver.requiresSecureCoding = YES;
        EXPECT_ANY_THROW([secureUnarchiver decodeObjectForKey:@"dictionary"]);
        [secureUnarchiver finishDecoding];
        [secureUnarchiver release];
    }

    { // NSArray containing NSNumber should pass through
        NSKeyedUnarchiver* secureUnarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:archive];
        secureUnarchiver.requiresSecureCoding = YES;
        EXPECT_NO_THROW([secureUnarchiver decodeObjectOfClass:[NSArray class] forKey:@"array"]);
        [secureUnarchiver finishDecoding];
        [secureUnarchiver release];
    }

    { // TestCreationSignallingClass (NSSecureCoding) should pass through and create one instance
        NSKeyedUnarchiver* secureUnarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:archive];
        secureUnarchiver.requiresSecureCoding = YES;
        EXPECT_NO_THROW([secureUnarchiver decodeObjectOfClass:[TestCreationSignallingClass class] forKey:@"creationSignalling"]);
        EXPECT_EQ(1, [TestCreationSignallingClass creationCount]);
        [secureUnarchiver finishDecoding];
        [secureUnarchiver release];
    }

    { // An object that does not conform to NSSecureCoding cannot be decoded
        NSKeyedUnarchiver* secureUnarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:archive];
        secureUnarchiver.requiresSecureCoding = YES;
        EXPECT_ANY_THROW([secureUnarchiver decodeObjectOfClass:[InsecureObject class] forKey:@"insecureObject"]);
        [secureUnarchiver finishDecoding];
        [secureUnarchiver release];
    }

    { // Arrays must be decoded by specifying their enclosing AND enclosed types
        NSKeyedUnarchiver* secureUnarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:archive];
        secureUnarchiver.requiresSecureCoding = YES;
        EXPECT_ANY_THROW([secureUnarchiver decodeObjectOfClass:[TestCreationSignallingClass class] forKey:@"arrayOfSecureTypes"]);
        [secureUnarchiver finishDecoding];
        [secureUnarchiver release];
    }

    { // Arrays must be decoded by specifying their enclosing AND enclosed types
        NSKeyedUnarchiver* secureUnarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:archive];
        secureUnarchiver.requiresSecureCoding = YES;
        EXPECT_ANY_THROW([secureUnarchiver decodeObjectOfClass:[NSArray class] forKey:@"arrayOfSecureTypes"]);
        [secureUnarchiver finishDecoding];
        [secureUnarchiver release];
    }

    { // Arrays must be decoded by specifying their enclosing AND enclosed types
        NSKeyedUnarchiver* secureUnarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:archive];
        secureUnarchiver.requiresSecureCoding = YES;
        NSSet* allowedClasses = [NSSet setWithObjects:[TestCreationSignallingClass class], [NSArray class], nil];
        EXPECT_NO_THROW([secureUnarchiver decodeObjectOfClasses:allowedClasses forKey:@"arrayOfSecureTypes"]);
        [secureUnarchiver finishDecoding];
        [secureUnarchiver release];
    }

    { // Once a bad decode has occurred, all requests must return nil
        NSKeyedUnarchiver* secureUnarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:archive];
        secureUnarchiver.requiresSecureCoding = YES;
        EXPECT_ANY_THROW([secureUnarchiver decodeObjectOfClass:[InsecureObject class] forKey:@"insecureObject"]);
        EXPECT_OBJCEQ(nil, [secureUnarchiver decodeObjectOfClass:[NSDictionary class] forKey:@"dictionary"]);
        EXPECT_OBJCEQ(nil, [secureUnarchiver decodeObjectOfClass:[NSArray class] forKey:@"array"]);
        EXPECT_OBJCEQ(nil, [secureUnarchiver decodeObjectOfClass:[NSNumber class] forKey:@"number"]);
        [secureUnarchiver finishDecoding];
        [secureUnarchiver release];
    }
}
